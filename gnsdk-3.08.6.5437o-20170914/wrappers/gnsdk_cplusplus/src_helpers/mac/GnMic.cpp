/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
 *
 */

/*
 * GnMic.cpp
 */

#include "GnMic.h"

GnMic::GnMic(gnsdk_uint32_t samplerate, gnsdk_uint16_t bitdepth, gnsdk_uint16_t channels)
{
	m_samplerate = samplerate;
	m_bitdepth   = bitdepth;
	m_channels   = channels;

	m_micHandle = NULL;

	m_bRunning      = false;
	m_full_buffers  = NULL;
	m_empty_buffers = NULL;
	m_full_count    = 0;
	m_empty_count   = 0;

	pthread_mutex_init(&m_mutex, 0);
	pthread_cond_init(&m_cond, 0);
}


GnMic::~GnMic(void)
{
	if (m_micHandle)
    {
        while (m_empty_buffers)
        {
            buffer_list_t* next = m_empty_buffers->next;
            AudioQueueFreeBuffer(m_micHandle, m_empty_buffers->queueBuf);
            free(m_empty_buffers);
            m_empty_buffers = next;
        }
        while (m_full_buffers)
        {
            buffer_list_t* next = m_full_buffers->next;
            AudioQueueFreeBuffer(m_micHandle, m_full_buffers->queueBuf);
            free(m_full_buffers);
            m_full_buffers = next;
        }
        
		AudioQueueDispose(m_micHandle, true);
    }

	pthread_mutex_destroy(&m_mutex);
	pthread_cond_destroy(&m_cond);
}


/*-----------------------------------------------------------------------------
 *  SourceInit
 */
gnsdk_error_t
GnMic::SourceInit()
{
	OSStatus result;


	AudioStreamBasicDescription format;
	format.mFormatID = kAudioFormatLinearPCM;
    format.mFormatFlags = kLinearPCMFormatFlagIsSignedInteger | kLinearPCMFormatFlagIsPacked;
	format.mSampleRate = m_samplerate;
	format.mChannelsPerFrame = m_channels;
	format.mBitsPerChannel = 8 * sizeof(SInt16);
	format.mBytesPerPacket =
		format.mBytesPerFrame =
			 format.mChannelsPerFrame * sizeof(SInt16);
	format.mFramesPerPacket = 1;
    format.mReserved = 0;
 
	result = AudioQueueNewInput(&format, _staticAudioInput, this, NULL, kCFRunLoopCommonModes, 0, &m_micHandle);
	if (result)
	{
		GNSDK_ASSERT(!result);
		return GNSDKERR_InitFailed;
	}

	/* Set up and prepare 2 buffers for mic at first*/
	for (int i = 0; i < 2; i += 1)
	{
		buffer_list_t* buffer = _get_from_empty_list();
		if (buffer)
		{
			result = AudioQueueEnqueueBuffer(m_micHandle, buffer->queueBuf, 0, NULL);
			GNSDK_ASSERT(!result);
		}
	}

	m_bRunning = true;
	
	result = AudioQueueStart(m_micHandle, NULL);
	if (result)
	{
		m_bRunning = false;
		GNSDK_ASSERT(!result);
		return GNSDKERR_InitFailed;
	}

	return GNSDKERR_NoError;
}


/*-----------------------------------------------------------------------------
 *  SourceClose
 */
gnsdk_void_t
GnMic::SourceClose()
{
	OSStatus result;


	pthread_mutex_lock(&m_mutex);
	{
		m_bRunning = false;
	}
	pthread_mutex_unlock(&m_mutex);

	result = AudioQueueStop(m_micHandle, true);
	GNSDK_ASSERT(!result);
}


/*-----------------------------------------------------------------------------
 *  SamplesPerSecond
 */
gnsdk_uint32_t
GnMic::SamplesPerSecond()
{
	return m_samplerate;
}


/*-----------------------------------------------------------------------------
 *  SampleSizeInBits
 */
gnsdk_uint32_t
GnMic::SampleSizeInBits()
{
	return m_bitdepth;
}


/*-----------------------------------------------------------------------------
 *  NumberOfChannels
 */
gnsdk_uint32_t
GnMic::NumberOfChannels()
{
	return m_channels;
}


/*-----------------------------------------------------------------------------
 *  GetData
 */
gnsdk_size_t
GnMic::GetData(gnsdk_byte_t* audio_buffer, gnsdk_size_t buffer_size)
{
	gnsdk_size_t read_size = 0;
	gnsdk_byte_t* p_data;

	if (m_bRunning)
	{
		/* wait for buffer to appear on full queue */
		if (m_full_buffers == NULL)
		{
			pthread_mutex_lock(&m_mutex);
			{
				pthread_cond_wait(&m_cond, &m_mutex);
			}
			pthread_mutex_unlock(&m_mutex);
		}

		if (m_full_buffers != NULL)
		{
			/* take from head of full buffers */
			buffer_list_t* buffer = m_full_buffers;

			read_size = buffer->queueBuf->mAudioDataByteSize - buffer->bytes_used;
			if (read_size > buffer_size)
				read_size = buffer_size;

			p_data = (gnsdk_byte_t*)buffer->queueBuf->mAudioData;
			memcpy(audio_buffer, &p_data[buffer->bytes_used], read_size);
			buffer->bytes_used += read_size;

			if (buffer->bytes_used == buffer->queueBuf->mAudioDataByteSize)
			{
				/* all used up, move to next full and
				** add empty buffer to empty list */
				pthread_mutex_lock(&m_mutex);
				{
					m_full_buffers = m_full_buffers->next;
					m_full_count -= 1;

					_add_to_empty_list(buffer);
				}
				pthread_mutex_unlock(&m_mutex);
			}
		}
	}

	return read_size;
}


/*-----------------------------------------------------------------------------
 *  _audioInput
 */
void 
GnMic::_audioInput (
   void                                *inUserData,
   AudioQueueRef                       inAQ,
   AudioQueueBufferRef                 inBuffer,
   const AudioTimeStamp                *inStartTime,
   UInt32                              inNumberPacketDescriptions,
   const AudioStreamPacketDescription  *inPacketDescs
   )
{
	OSStatus result;

	GNSDK_UNUSED(inUserData);
	GNSDK_UNUSED(inAQ);
	GNSDK_UNUSED(inStartTime);
	GNSDK_UNUSED(inNumberPacketDescriptions);
	GNSDK_UNUSED(inPacketDescs);
	
	pthread_mutex_lock(&m_mutex);
	{
		buffer_list_t* buffer = (buffer_list_t*)inBuffer->mUserData;

		/* add this buffer to full queue */
		_add_to_full_list(buffer);

		/* if still running, prepare another buffer for mic */
		if (m_bRunning)
		{
			/* get new buffer from empty queue */
			buffer = _get_from_empty_list();
			if (buffer)
			{
				result = AudioQueueEnqueueBuffer(m_micHandle, buffer->queueBuf, 0, NULL);
				GNSDK_ASSERT(!result);
			}
			else
			{
				/* out of mem, bail */
				m_bRunning = false;
			}
		}

		/* signal that a buffer is available */
		pthread_cond_broadcast(&m_cond);
	}
	pthread_mutex_unlock(&m_mutex);
}


/*-----------------------------------------------------------------------------
 *  _staticAudioInput
 */
void 
GnMic::_staticAudioInput (
   void                                *inUserData,
   AudioQueueRef                       inAQ,
   AudioQueueBufferRef                 inBuffer,
   const AudioTimeStamp                *inStartTime,
   UInt32                              inNumberPacketDescriptions,
   const AudioStreamPacketDescription  *inPacketDescs
)
{
	GnMic* me = (GnMic*)inUserData;
	me->_audioInput(inUserData, inAQ, inBuffer, inStartTime, inNumberPacketDescriptions, inPacketDescs);
}


/*-----------------------------------------------------------------------------
 *  _add_to_full_list
 */
void
GnMic::_add_to_full_list(buffer_list_t* buffer)
{
	buffer_list_t* list_end = m_full_buffers;


	if (list_end == NULL)
	{
		m_full_buffers = buffer;
	}
	else
	{
		while (list_end && list_end->next)
			list_end = list_end->next;

		list_end->next = buffer;
	}

	buffer->next  = NULL;
	m_full_count += 1;
}


/*-----------------------------------------------------------------------------
 *  _add_to_empty_list
 */
void
GnMic::_add_to_empty_list(buffer_list_t* buffer)
{
	buffer->next    = m_empty_buffers;
	m_empty_buffers = buffer;

	m_empty_count     += 1;
	buffer->bytes_used = 0;
}


/*-----------------------------------------------------------------------------
 *  _get_from_empty_list
 */
GnMic::buffer_list_t*
GnMic::_get_from_empty_list()
{
	buffer_list_t*  buffer = m_empty_buffers;
	OSStatus		result;

	if (buffer != NULL)
	{
		m_empty_buffers = m_empty_buffers->next;
		m_empty_count  -= 1;
	}
	else
	{
		/* create extra buffer */
		buffer = (buffer_list_t*)malloc(sizeof(*buffer));
		if (buffer)
		{
			memset(buffer, 0, sizeof(*buffer));

			result = AudioQueueAllocateBuffer(m_micHandle, 2048, &buffer->queueBuf);
			if (!result)
			{
				buffer->queueBuf->mUserData = buffer;
			}
		}
	}

	return buffer;
}

