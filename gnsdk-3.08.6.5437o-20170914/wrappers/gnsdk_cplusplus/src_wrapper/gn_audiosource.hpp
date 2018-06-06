/** Public header file for Gracenote SDK C++ Wrapper
 * Author:
 *   Copyright (c) 2000-2015 Gracenote, Inc.
 *
 *   This software may not be used in any way or distributed without
 *   permission. All rights reserved.
 *
 *   Some code herein may be covered by US and international patents.
 */

/* IGnAudioSource.hpp: Gracenote audio helper class */

#ifndef _GNAUDIOSOURCE_HPP_
#define _GNAUDIOSOURCE_HPP_

#ifndef __cplusplus
#error "C++ compiler required"
#endif

#include "gnsdk.h"

namespace gracenote
{
	/**
	 * Delegate interface for retrieving audio data from a raw audio source such as a microphone, audio file,
	 * or Internet stream.
	 *
	 * A number of Gracenote methods consume audio data from audio sources without requiring your application to
	 * manually pass the data. Using these can simplify your application's implementation. They also allow for
	 * hot fixes that don't require an entire release cycle.
	 *
	 * These methods/consumers currently include:
	 *
	 *  <p>// Generate a fingerprint using the audio from a raw audio source</p>
	 *  void GnMusicId::FingerprintFromSource(IGnAudioSource& audioSource, GnFingerprintType fpType) throw (GnError);
	 *
	 *  <p>// Find albums using the audio from a raw audio source</p>
	 *  metadata::GnResponseAlbums GnMusicId::FindAlbums(IGnAudioSource& audioSource, GnFingerprintType fpType) throw (GnError);
	 *
	 * <p>// Add a fingerprint to the file information used to identify a track, album, or library</p>
	 *  void GnMusicIdFileInfo::FingerprintFromSource(IGnAudioSource& audioSource) throw (GnError);
	 *
	 *  <p>// Process the audio stream provided by the raw audio source for identification</p>
	 *  void GnMusicIdStream::AudioProcessStart(IGnAudioSource& audioSource) throw (GnError);
	 *
	 * You are encouraged to implement your own audio source object if, for example, your application
	 * requires a custom audio file format.
	 *
	 * Note that for some platforms (e.g., iOS and Android), Gracenote provides the GnMic helper class
	 * that implements the IGnAudioSource interface to retrive audio. If available, your application can use this class to process
	 * streaming audio from a device microphone. Gracenote for Mobile also provides a GnAudioFile delegate for reading raw
	 * audio from encoded audio files.
	 *
     * <b>SDK Documentation</b>
     *
     * Topic: .../docs/html-oo > start_here.html > "Implementing Applications..." > Identifying Music > Identifying Streaming Music (MusicID-Stream )
	 *
	 * See this topic for more information on implementing an IGnAudioSource interface.
	 */
	class IGnAudioSource
	{
	public:
		virtual ~IGnAudioSource() {};

		/**
		 * Initialize the audio source. This is invoked prior to any other methods. If initialization
		 * fails a non-zero value is returned. In this case the consumer will not call any other methods
		 * including that to close the audio source.
		 * @return 0 indicates initialization was successful, non-zero otherwise.
		 */
		virtual gnsdk_uint32_t
		SourceInit()  = 0;

		/**
		 * Close the audio source. The consumer will not call any other methods after the source has
		 * been closed
		 */
		virtual void
		SourceClose() = 0;


		/**
		 * Return the source audio format's samples per second. Return zero if called
		 * prior to SourceInit.
		 * @return Samples per second
		 */
		virtual gnsdk_uint32_t
		SamplesPerSecond() = 0;

		/**
		 * Return the source audio format's number of bits in a sample. Return zero if called
		 * prior to SourceInit.
		 * @return Sample size in bits
		 */
		virtual gnsdk_uint32_t
		SampleSizeInBits() = 0;

		/**
		 * Return the source audio format's number of channels. Return zero if called
		 * prior to SourceInit.
		 * @return Number of channels
		 */
		virtual gnsdk_uint32_t
		NumberOfChannels() = 0;


		/**
		 * Get audio data from the audio source. This is a blocking call that does
		 * not return until data is available.
		 * When data is available, this method must
		 * copy data to the provided buffer ensuring not to overflow it. The number of bytes
		 * copied to the buffer is returned.
		 * To signal the audio source is unable to deliver any more data return zero. The
		 * consumer will then stop requesting data and close the audio source.
		 * @param dataBuffer 	[out] Buffer to receive audio data
		 * @param dataSize 		[in]  Size in bytes of buffer
		 * @return Number of bytes copied to the buffer. Return zero to indicate
		 * 		   no more data can be delivered via the audio source.
		 */
		virtual gnsdk_size_t
		GetData(gnsdk_byte_t* dataBuffer, gnsdk_size_t dataSize) = 0;
	};

}  // namespace gracenote

#endif // _GNAUDIOSOURCE_HPP_
