/** Public header file for Gracenote SDK C++ Wrapper
 * Author:
 *   Copyright (c) 2000-2015 Gracenote, Inc.
 *
 *   This software may not be used in any way or distributed without
 *   permission. All rights reserved.
 *
 *   Some code herein may be covered by US and international patents.
 */

#ifndef _GNSDK_MUSICID_STREAM_HPP_
#define _GNSDK_MUSICID_STREAM_HPP_

#ifndef __cplusplus
#error "C++ compiler required"
#endif

#include "gnsdk_base.hpp"
#include "metadata_music.hpp"
#include "gn_audiosource.hpp"

#if GNSDK_MUSICID_STREAM

namespace gracenote
{
	namespace musicid_stream
	{
		class GnMusicIdStream;
		class IGnMusicIdStreamEvents;


		/**
		 * @enum GnMusicIdStreamProcessingStatus
		 * GnMusicIdStreamProcessingStatus is currently considered to be experimental.
		 * An application should only use this option if your Gracenote representative advises you to do so.
		 * Contact your Gracenote representative with any questions about this enhanced functionality.
		 * @ingroup Music_MusicIDStream_TypesEnums
		 */
		enum GnMusicIdStreamProcessingStatus
		{
			kStatusProcessingInvalid = 0,

			kStatusProcessingAudioNone,
			kStatusProcessingAudioSilence,
			kStatusProcessingAudioNoise,
			kStatusProcessingAudioSpeech,
			kStatusProcessingAudioMusic,

			kStatusProcessingTransitionNone,
			kStatusProcessingTransitionChannelChange,
			kStatusProcessingTransitionContentToContent,

			kStatusProcessingErrorNoClassifier,

			kStatusProcessingAudioStarted,
			kStatusProcessingAudioEnded,

			kStatusProcessingEqProfileChanged
		};

		/**
		 *  @enum GnMusicIdStreamIdentifyingStatus
		 *  The status of the channel or current identification query.
		 *  As a channel processes audio, or as an identification query progresses,
		 *  status notifications are provided via the events delegate.
		 * @ingroup Music_MusicIDStream_TypesEnums
		 */
		enum GnMusicIdStreamIdentifyingStatus
		{
			/** Invalid status
			 * @ingroup Music_MusicIDStream_TypesEnums
			 */
			kStatusIdentifyingInvalid = 0,


			/** Identification query started
			 * @ingroup Music_MusicIDStream_TypesEnums
			 */
			kStatusIdentifyingStarted,

			/** Fingerprint generated for sample audio
			 * @ingroup Music_MusicIDStream_TypesEnums
			 */
			kStatusIdentifyingFpGenerated,

			/** Local query started for identification
			 * @ingroup Music_MusicIDStream_TypesEnums
			 */
			kStatusIdentifyingLocalQueryStarted,

			/** Local query ended for identification
			 * @ingroup Music_MusicIDStream_TypesEnums
			 */
			kStatusIdentifyingLocalQueryEnded,

			/** Online query started for identification
			 * @ingroup Music_MusicIDStream_TypesEnums
			 */
			kStatusIdentifyingOnlineQueryStarted,

			/** Online query ended for identification
			 * @ingroup Music_MusicIDStream_TypesEnums
			 */
			kStatusIdentifyingOnlineQueryEnded,

			/** Identification query ended
			 * @ingroup Music_MusicIDStream_TypesEnums
			 */
			kStatusIdentifyingEnded,

			/** Identification query completed with existing match
			 * @deprecated NB: Automatic mode for radio stream identification will be removed in future release. Do not use.
			 * @ingroup Music_MusicIDStream_TypesEnums
			 */
			kStatusIdentifyingNoNewResult

		};
		/**
		* @enum GnMusicIdStreamPreset
		* @ingroup Music_MusicIDStream_TypesEnums
		*/
		enum GnMusicIdStreamPreset
		{
			kPresetInvalid = 0,

			/** Application type mobile, i.e. audio is captured by microphone
			 * @ingroup Music_MusicIDStream_TypesEnums
			 */
			kPresetMicrophone,

			/** Application type radio, i.e. audio is captured at source (e.g. direct from tuner)
			 * @ingroup Music_MusicIDStream_TypesEnums
			 */
			kPresetRadio,

			/** Custom type for a special case
			 * @ingroup Music_MusicIDStream_TypesEnums
			 */
			kPresetCustom
		};

		/**
		* @enum GnMusicIdStreamText
		* @deprecated NB: Automatic mode will be removed in future release. Do not use.
		* @ingroup Music_MusicIDStream_TypesEnums
		*/
        enum GnMusicIdStreamText
        {
            /** No text
             * @deprecated NB: Automatic mode will be removed in future release. Do not use.
             * @ingroup Music_MusicIDStream_TypesEnums
             */
            kTextNone = 0,

            /** Accompanying text from shoutcast stream
             * @deprecated NB: Automatic mode will be removed in future release. Do not use.
             * @ingroup Music_MusicIDStream_TypesEnums
             */
            kTextShoutcast,

            /** Accompanying RDS RT Text
             * @deprecated NB: Automatic mode will be removed in future release. Do not use.
             * @ingroup Music_MusicIDStream_TypesEnums
             */
            kTextRdsRt,

            /** Accompanying RDS PTY Text
             * @deprecated NB: Automatic mode will be removed in future release. Do not use.
             * @ingroup Music_MusicIDStream_TypesEnums
             */
            kTextRdsPty,

            /** Accompanying RDS PI Text
             * @deprecated NB: Automatic mode will be removed in future release. Do not use.
             * @ingroup Music_MusicIDStream_TypesEnums
             */
            kTextRdsPi,

            /** Accompanying Artist Text
             * @deprecated NB: Automatic mode will be removed in future release. Do not use.
             * @ingroup Music_MusicIDStream_TypesEnums
             */
            kTextArtist,

            /** Accompanying Track Title Text
             * @deprecated NB: Automatic mode will be removed in future release. Do not use.
             * @ingroup Music_MusicIDStream_TypesEnums
             */
            kTextTrackTitle,

            /** Accompanying Album Title Text
             * @deprecated NB: Automatic mode will be removed in future release. Do not use.
             * @ingroup Music_MusicIDStream_TypesEnums
             */
            kTextAlbumTitle

        };

		/**
		 * Configures options for GnMusicIdStream
		 */
		class GnMusicIdStreamOptions
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 *  Specifies whether identification should be performed against local embedded databases or online.
			 *  @param lookupMode  [in] One of the GnLookupMode values
			 *  @ingroup MusicIdStream_Options
			 */
			void
			LookupMode(GnLookupMode lookupMode) throw (GnError);

			/**
			 *  Specifies which data should be included in the response
			 *  @param val 		[in] Set One of the #GnLookupData values
			 *  @param enable 	[in] True (enable) or false (disable)
			 *  @ingroup MusicIdStream_Options
			 */
			void
			LookupData(GnLookupData val, bool enable) throw (GnError);

			/**
			*   @deprecated To set language provide appropriate GnLocale object with GnMusicIdStream constructor
			*   @param preferredLanguage		[in] Preferred language for result
			 *  @ingroup MusicIdStream_Options
			*/
			void
			PreferResultLanguage(GnLanguage preferredLanguage) throw (GnError);


			/**
			 * Specifies preference for results that contain the provided external identifier
			 * <p><b>Remarks:</b></p>
			 * This option is currently only supported when online processing is enabled and single
			 * result is specified.
			 *  @param preferredExternalId 	[in] The name of an external identifier that should be preferred when selecting matches
			 *  @ingroup MusicIdStream_Options
			 */
			void
			PreferResultExternalId(gnsdk_cstr_t preferredExternalId) throw (GnError);


			/**
			 *  Specifies preference for results that have cover art associated
			 *  @param bEnable 	[in] Set prefer cover art.
			 *  @ingroup MusicIdStream_Options
			 */
			void
			PreferResultCoverart(bool bEnable) throw (GnError);


			/**
			 *  Specifies whether a response must return only the single best result.
			 *  When enabled, a single full result is returned; when disabled, multiple partial results could be returned.
			 *  @param bEnable 	[in] Option, default is true. True to enable, false to disable.
			 *  @ingroup MusicIdStream_Options
			 */
			void
			ResultSingle(bool bEnable) throw (GnError);


			/**
			 *  Specifies whether a response must return a range of results that begin at a specified value
			 *  @param resultStart  [in] Result range start value
			 *  <p><b>Remarks:</b></p>
			 *  This Option is useful for paging through results.
			 *  <p><b>Note:</b></p>
			 *  Gracenote Service enforces that the range start value must be less than or equal to the total
			 *  number of results. If you specify a range start value that is greater than the total number of
			 *  results, no results are returned.
			 *  @ingroup MusicIdStream_Options
			 */
			void
			ResultRangeStart(gnsdk_uint32_t resultStart) throw (GnError);

			/**
			 * Specifies the number of results to return in the response
			 *  @param resultCount 	[in] Number of results
			 *  @ingroup MusicIdStream_Options
			 */
			void
			ResultCount(gnsdk_uint32_t resultCount) throw (GnError);

			/**
			 * Set a specific network interface to use with this object's connections. This can be useful for
			 * systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
			 *  @param intfName [in] Local IP address or system name for the desired network interface
			 *  @ingroup MusicIdStream_Options
			 */
			void
			NetworkInterface(gnsdk_cstr_t intfName) throw (GnError);

			/**
			 * Returns the network interface being used with this object's connections if one has been set.
			 * If no specific network interface has been set, this option will return an empty string.
			 *  @ingroup MusicIdStream_Options
			 */
			gnsdk_cstr_t
			NetworkInterface() throw (GnError);

			/**
			 * Specifies whether GnMuisicIdStream processes received audio and prevents performing
			 * identification queries if the audio is deemed unsuitable for music identification.
			 * If audio is deemed unsuitable a request to identify terminates in
			 * IGnMusicIdStreamEvents::MusicIdStreamIdentifyCompletedWithError being invoked with
			 * MIDSWARN_UnsuitableAudio.
			 * This option is experimental and subject to change
			 * @ingroup MusicIdStream_Options
			 */
			void
			AudioSuitabilityProcessing(bool bEnable) throw (GnError);

			/**
			 *  General option setting for custom string options
			 *  @param optionKey   [in] Option name
			 *  @param value	   [in] Option value
			 *  @ingroup MusicIdStream_Options
			 */
			void
			Custom(gnsdk_cstr_t optionKey, gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Return set value for custom options.
			 *  @param optionKey   [in] Option name
			 *  @ingroup MusicIdStream_Options
			 */
			gnsdk_cstr_t
			Custom(gnsdk_cstr_t optionKey) throw (GnError);

		protected:
			GnMusicIdStreamOptions() : weakhandle_(GNSDK_NULL) { }

		private:
			DISALLOW_COPY_AND_ASSIGN(GnMusicIdStreamOptions);
			friend class GnMusicIdStream;
			gnsdk_musicidstream_channel_handle_t weakhandle_;

		};

		/**
		 *
		 * GnMusicIdStream provides services for identifying music within a continuous audio stream.
		 * As data is received from the audio stream, it is provided to GnMusicIdStream, when the application
		 * wishes to identify the audio it initializes an identification. The results of the identification
		 * are delivered asynchronously to a delegate object.
		 *
		 * <p><b>SDK Documentation</b></p>
		 *
		 * <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Streaming Music
		 *
		 * For more information on using MusicID-Stream/Radio, see the above topic which covers:
		 * <ul>
		 *     <li>General information about identifying streaming music</li>
		 *     <li>How to identify streaming audio from an audio source (IGnAudioSource implementation)</li>
		 *     <li>Setting options for streaming audio queries</li>
		 *     <li>Music-ID Stream/Radio code samples</li>
		 * </ul>
		 *
		 * <b>Sample App</b>
		 *
		 *     - .../samples/musicid_stream_manual
		 *
		 * <p><b>Overview</b></p>
		 *
		 * <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID Radio
		 *
		 * Note: Customers must be licensed to implement use of a MusicID product in an application.
		 * Contact your Gracenote support representative with questions about product licensing and
		 * entitlement.
		 */
		class GnMusicIdStream : public GnObject<gnsdk_musicidstream_channel_handle_t>
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 *  Establishes an audio stream identification object with locale. The locale is used to determine
			 *  the preferred language and script of stream identification results.
			 *  Note: Results are only returned in preferred language and script where available.
			 *  @param user 			[in] Gracenote user
			 *  @param preset 			[in] Gracenote musicID stream preset
			 *  @param locale 			[in] Gracenote locale
			 *  @param pEventDelegate 	[in] Audio processing and identification query events handler
			 */
			GnMusicIdStream(const GnUser& user, GnMusicIdStreamPreset preset, const GnLocale& locale, IGnMusicIdStreamEvents* pEventHandler) throw (GnError);
			GnMusicIdStream(const GnUser& user, GnMusicIdStreamPreset preset, const GnLocale& locale, GnManagedPtr<IGnMusicIdStreamEvents*> eventHandler) throw (GnError);

			/**
			 *  Establishes an audio stream identification object with locale. The locale is used determine
			 *  the preferred language and script of stream identification results.
			 *  Note: Results are only returned in preferred language and script where available.
			 *  @param user 			[in] Gracenote user
			 *  @param preset			[in] Gracenote musicID stream preset
			 *  @param pEventDelegate 	[in] Audio processing and identification query events handler
			 */
			GnMusicIdStream(const GnUser& user, GnMusicIdStreamPreset preset, IGnMusicIdStreamEvents* pEventHandler) throw (GnError);
			GnMusicIdStream(const GnUser& user, GnMusicIdStreamPreset preset, GnManagedPtr<IGnMusicIdStreamEvents*> eventHandler) throw (GnError);

			virtual
			~GnMusicIdStream( );


			/**
			 *  Retrieves the MusicID-Stream SDK's version string.
			 *  @return Version string if successful
			 *  <p><b>Remarks:</b></p>
			 *  You can call this API at any time after successfully establishing a MusicID-Stream audio channel.
			 *  The returned string is a constant. Do not attempt to modify or delete.
			 *  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
			 *  Major: New functionality
			 *  Minor: New or changed features
			 *  Improvement: Improvements and fixes
			 *  Build: Internal build number
			 */
			static gnsdk_cstr_t Version();


			/**
			 *  Retrieves the MusicID-Stream SDK's build date string.
			 *  @return Build date string of the format: YYYY-MM-DD hh:mm UTC
			 *  <p><b>Remarks:</b></p>
			 *  You can call this API at any time after successfully establishing a MusicID-Stream audio channel.
			 *  The returned string is a constant. Do not attempt to modify or delete.
			 *  Example build date string: 2008-02-12 00:41 UTC
			 */
			static gnsdk_cstr_t BuildDate();


			/**
			 * Get GnMusicIdStream options object. Use to configure your GnMusicIdStream instance.
			 * @return Options objects
			 */
			GnMusicIdStreamOptions&
			Options() { return options_; }

			/**
			 * Commence retrieving and processing audio from an object implementing the audio source interface.
			 * This is an alternate and often simpler method for providing audio to GnMusicIdStream
			 * instead of calling AudioProcessStart (audio format overload) and AudioProcess.
			 * To use this method the audio source to be identified must be accessible via an IGnAudioSource
			 * implementation. Custom implementations of IGnAudioSource are encouraged.
			 * Note: audio is retrieved from the audio source in a loop so some applications may wish to start
			 * automatic audio processing in a background thread to avoid stalling the main thread.
			 * @param audioSource	[in] Audio source to be identified
			 */
			void
			AudioProcessStart(IGnAudioSource& audioSource) throw (GnError);


			/**
			 * Initialize manual delivery of audio stream audio to GnMusicIdStream. GnMusicIdStream
			 * establishes buffers and audio processing modules, readying itself to receive audio.
			 * @param samplesPerSecond	[in] Number of samples per second
			 * @param bitsPerSample		[in] Number of bits per sample
			 * @param numberOfChannels	[in] Number of channels
			 */
			void
			AudioProcessStart(gnsdk_uint32_t samplesPerSecond, gnsdk_uint32_t bitsPerSample, gnsdk_uint32_t numberOfChannels ) throw (GnError);


			/**
			 * Stops audio processing. If audio processing was started with an object implementing IGnAudioSource
			 * the audio source is closed and data is no longer retrieved from that source. If manual audio processing
			 * was used future attempts to write audio data for processing will fail.
			 */
			void
			AudioProcessStop() throw (GnError);

			/**
			 * Provides audio manually for processing by GnMusicIdStream. This should not be called if
			 * audio processing was started with an object implementing the audio source interface.
			 * @param audioData			[in] Buffer containing sample audio
			 * @param audioDataLength	[in] Number of bytes of audio in pAudioBuffer
			 */
			void
			AudioProcess(const gnsdk_byte_t* audioData, gnsdk_size_t audioDataLength) throw (GnError);

			/**
			 * @deprecated Will be removed next release, use IdentifyAlbumAsync and WaitForIdentify instead.
			 * Identifying the audio in the audio stream and blocks until identification is
			 * complete. Results are delivered asynchronously via IGnMusicIdStreamEvents delegate.
			 */
			void
			IdentifyAlbum() throw (GnError);

			/**
			 * Identifying the audio in the audio stream. Results are delivered
			 * asynchronously via IGnMusicIdStreamEvents delegate.
			 */
			void
			IdentifyAlbumAsync() throw (GnError);

			/**
			 * Wait for currently running identify call to complete (up to timeout_ms milliseconds).
			 * Returns true if identification completed in the timeout period, false if not
			 * @param timeout_ms	[in] Timeout in milliseconds
			 * @return true			True if completed, false if timed out
			 */
			bool
			WaitForIdentify(gnsdk_uint32_t timeout_ms) throw (GnError);

			/**
			 * Cancel the current identify operation blocking until the identification has stopped.
			 * Cannot be called from within a GnMusicIdStream delegate callback, use the canceller provided
			 * in the callback instead. 
			 */
			void
			IdentifyCancel() throw (GnError);

			/**
			 * @deprecated NB: Automatic mode will be removed in future release. Do not use.
			 * Specifies automatic recognition should be enabled or disabled
			 * @param bEnable 	[in] Option, default is false. True to enable, false to disable
			 *
			 */
			void
			AutomaticIdentification(bool bEnable) throw (GnError);

			/**
			 * @deprecated NB: Automatic mode will be removed in future release. Do not use.
			 * Specifies automatic recognition is enabled or disabled
			 * @return true			True if automatic recognition is enabled
			 *
			 */
			bool
			AutomaticIdentification() throw (GnError);

			/**
			 * @deprecated NB: Automatic mode for radio stream identification will be removed in future release. Do not use.
			 * Provide text accompanying the channel stream to a query handle for improved match resolution
			 * @param textKey 		[in] A input type from the available MusicIDStream Text Keys
			 * @param textValue 	[in] A string value that corresponds to the defined text key
			 *
			 */
			void
			Text(GnMusicIdStreamText textKey, gnsdk_cstr_t textValue) throw (GnError);

			/**
			 * @deprecated NB: Automatic mode for radio stream identification will be removed in future release. Do not use.
			 * Returns real clock time duration remaining before next query takes place when automatic recognition mode is turned on.
			 * @param queryTimeLeft	[out[ Duration in ms left before next query.
			 *
			 */
			GnString
			NextQueryTime() throw (GnError);

			/**
			 * Get the event handler provided on construction
			 * @return Event handler
			 */
			IGnMusicIdStreamEvents*
			EventHandler() { return eventHandler_.native(); }

			/**
			 *  Returns information about the GnMusicIdStream instance
			 *  @param key		[in] Information key
			 *  @return GnString containing the requested information
			 */
			GnString
			InfoGet(gnsdk_cstr_t key) throw (GnError);

		private:
			void
			create(const GnUser& user, GnMusicIdStreamPreset preset, const GnLocale& locale) throw (GnError);

			GnManagedPtr<IGnMusicIdStreamEvents*>	eventHandler_;
			GnMusicIdStreamOptions					options_;
			IGnAudioSource*							p_audioSource;

			/* dissallow assignment operator */
			DISALLOW_COPY_AND_ASSIGN(GnMusicIdStream);
		};

		/**
		 * Delegate interface for receiving GnMusicIdStream events
		 */
		class IGnMusicIdStreamEvents : public IGnStatusEvents
		{
		public:
			GNWRAPPER_ANNOTATE

			virtual
			~IGnMusicIdStreamEvents() { };



			/**
			 * MusicIdStreamProcessingStatusEvent is currently considered to be experimental.
			 * An application should only use this option if it is advised by Gracenote representative.
			 * Contact your Gracenote representative with any questions about this enhanced functionality.
			 * @param status		Status
			 * @param canceller		Cancellable that can be used to cancel this processing operation
			 */
			virtual void
			MusicIdStreamProcessingStatusEvent(GnMusicIdStreamProcessingStatus status, IGnCancellable& canceller) = 0;

			/**
			 * Provides GnMusicIdStream identifying status notification
			 * @param status		Status
			 * @param canceller		Cancellable that can be used to cancel this identification operation
			 */
			virtual void
			MusicIdStreamIdentifyingStatusEvent(GnMusicIdStreamIdentifyingStatus status, IGnCancellable& canceller) = 0;

			/**
			 * A result is available for a GnMusicIdStream identification request
			 * @param result		Result
			 * @param canceller		Cancellable that can be used to cancel this identification operation
			 */
			virtual void
			MusicIdStreamAlbumResult(metadata::GnResponseAlbums& result, IGnCancellable& canceller) = 0;

			/**
			 * Identifying request could not be completed due to the reported error condition
			 * @param completeError	Error condition information
			 */
			virtual void
			MusicIdStreamIdentifyCompletedWithError(GnError& completeError) = 0;
		};
	} // namespace musicid_stream

}     // namespace gracenote

#endif /* GNSDK_MUSICID_STREAM */


#endif // _GNSDK_MUSICID_STREAM_HPP_

