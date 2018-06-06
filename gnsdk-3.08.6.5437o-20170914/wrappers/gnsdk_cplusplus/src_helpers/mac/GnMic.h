#pragma once
#include "../../src_wrapper/gn_audiosource.hpp"

#include <CoreAudio/CoreAudio.h>
#include <AudioToolbox/AudioToolbox.h>
#include <pthread.h>

/**
*  This class represents Microphone as IGnAudioSource. Use this class when working with microphone
*/
class GnMic : public gracenote::IGnAudioSource
{
public:
	GnMic(gnsdk_uint32_t samplerate, gnsdk_uint16_t bitdepth, gnsdk_uint16_t channels);
	virtual ~GnMic(void);

	/*
	** GnAudioSource Implementation
	*/

	/**
	* Initialize Microphone as IGnAudioSource
	* @return errorCode 0 = sucess, non 0 = failure
	*/
	virtual gnsdk_error_t	SourceInit();

	/*
	* Audio Samples Per Scecond 
	* @return samplePerSecond 
	*/
	virtual gnsdk_void_t	SourceClose();

	/**
	* Close Microphone 
	*/
	virtual gnsdk_uint32_t	SamplesPerSecond();

	/**
	* Audio Sample Size in Bits
	* @return SampleSizeInBits
	*/
	virtual gnsdk_uint32_t	SampleSizeInBits();

	/**
	* Audio Number of Channels
	* @return Number of channels
	*/
	virtual gnsdk_uint32_t	NumberOfChannels();

	/**
	* Get audio data from microphone
	* @param audio_buffer Adudio Buffer
	* @param buffer_size  Audio Buffer Size
	* @return populated_buffer_size populated buffer size
	*/		
	virtual gnsdk_size_t	GetData(gnsdk_byte_t* audio_buffer, gnsdk_size_t buffer_size);
	
private:
	typedef struct s_buffer_list
	{
		AudioQueueBufferRef		queueBuf;
		gnsdk_size_t			bytes_used;
		struct s_buffer_list*	next;

	} buffer_list_t;

	static void _staticAudioInput(void* inUserData, AudioQueueRef inAQ, AudioQueueBufferRef inBuffer, const AudioTimeStamp* inStartTime, UInt32 inNumberPacketDescriptions, const AudioStreamPacketDescription *inPacketDescs);
	void 		_audioInput      (void* inUserData, AudioQueueRef inAQ, AudioQueueBufferRef inBuffer, const AudioTimeStamp* inStartTime, UInt32 inNumberPacketDescriptions, const AudioStreamPacketDescription *inPacketDescs);

	void					_add_to_full_list   (buffer_list_t* buffer);
	void					_add_to_empty_list  (buffer_list_t* buffer);
	buffer_list_t*			_get_from_empty_list();
	
	gnsdk_uint32_t			m_samplerate;
	gnsdk_uint16_t			m_bitdepth;
	gnsdk_uint16_t			m_channels;

    AudioQueueRef			m_micHandle;

	buffer_list_t*			m_full_buffers;
	buffer_list_t*			m_empty_buffers;
	gnsdk_uint32_t			m_full_count;
	gnsdk_uint32_t			m_empty_count;

	bool					m_bRunning;
	
	pthread_mutex_t			m_mutex;
	pthread_cond_t			m_cond;
};

