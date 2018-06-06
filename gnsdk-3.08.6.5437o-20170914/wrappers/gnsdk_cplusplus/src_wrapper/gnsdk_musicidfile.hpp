/** Public header file for Gracenote SDK C++ Wrapper
 * Author:
 *   Copyright (c) 2000-2015 Gracenote, Inc.
 *
 *   This software may not be used in any way or distributed without
 *   permission. All rights reserved.
 *
 *   Some code herein may be covered by US and international patents.
 */

#ifndef _GNSDK_MUSICIDFILE_HPP_
#define _GNSDK_MUSICIDFILE_HPP_

#ifndef __cplusplus
#error "C++ compiler required"
#endif

#include "gnsdk_base.hpp"
#include "metadata_music.hpp"
#include "gn_audiosource.hpp"

#if GNSDK_MUSICID_FILE

namespace gracenote
{
	namespace musicid_file
	{
		class GnMusicIdFile;
		class GnMusicIdFileInfo;
		class IGnMusicIdFileEvents;
		class IGnMusicIdFileInfoEvents;

		/**
		 *  @enum GnMusicIdFileInfoStatus
		 *  Current query status.
		 *  @ingroup Music_MusicIDFile_TypesEnums
		 */
		enum GnMusicIdFileInfoStatus
		{
			/**
			 * FileInfo has not been processed.
			 * @ingroup Music_MusicIDFile_TypesEnums
			 */
			kMusicIdFileInfoStatusUnprocessed  = 0,


			/**
			 * FileInfo is currently being processed.
			 * @ingroup Music_MusicIDFile_TypesEnums
			 */
			kMusicIdFileInfoStatusProcessing   = 1,


			/**
			 * An error occurred while processing the FileInfo.
			 * @ingroup Music_MusicIDFile_TypesEnums
			 */
			kMusicIdFileInfoStatusError      = 2,


			/**
			 * No results were found for FileInfo.
			 * @ingroup Music_MusicIDFile_TypesEnums
			 */
			kMusicIdFileInfoStatusResultNone   = 3,


			/**
			 * Single preferred response available for FileInfo.
			 * @ingroup Music_MusicIDFile_TypesEnums
			 */
			kMusicIdFileInfoStatusResultSingle = 4,


			/**
			 * All retrieved results available for FileInfo.
			 * @ingroup Music_MusicIDFile_TypesEnums
			 */
			kMusicIdFileInfoStatusResultAll  = 5

		};

		/**
		 *  @enum GnMusicIdFileCallbackStatus
		 *  Status codes passed to the gnsdk_musicidfile_callback_status_fn() callback.
		 *  @ingroup Music_MusicIDFile_TypesEnums
		 */
		enum GnMusicIdFileCallbackStatus
		{
			/**
			 *
			 *   MusicID-File processing is beginning for a given FileInfo.
			 * @ingroup Music_MusicIDFile_TypesEnums
			 */
			kMusicIdFileCallbackStatusProcessingBegin    = 0x100,


			/**
			 *
			 *   Performing a Gracenote query for given FileInfo.
			 * @ingroup Music_MusicIDFile_TypesEnums
			 */
			kMusicIdFileCallbackStatusFileInfoQuery      = 0x150,


			/**
			 *
			 *   MusicID-File processing is complete for a given FileInfo.
			 * @ingroup Music_MusicIDFile_TypesEnums
			 */
			kMusicIdFileCallbackStatusProcessingComplete = 0x199,

			/**
			 *
			 *   MusicID-File processing for a given FileInfo has encountered an
			 *   error.
			 * @ingroup Music_MusicIDFile_TypesEnums
			 */
			kMusicIdFileCallbackStatusProcessingError    = 0x299,


			/**
			 *
			 *   An error in MusicID-File querying or processing has occurred.
			 * @ingroup Music_MusicIDFile_TypesEnums
			 */
			kMusicIdFileCallbackStatusError              = 0x999

		};

		/**
		 *  Container class for providing media file information to MusicID-File.
		 */
		class GnMusicIdFileInfo 
		{
		public:
			GNWRAPPER_ANNOTATE

			GnMusicIdFileInfo() : 
				query_handle_(GNSDK_NULL), fileinfo_handle_(GNSDK_NULL) {};

			/**
			 *@internal
			 *  Helper to allow GnMusicIdFileInfoManager to construct a new GnMusicIdFileInfo object
			 *  @param query_handle		[in] A C-GNSDK gnsdk_musicidfile_query_handle_t
			 *  @param handle			[in] A C-GNSDK gnsdk_musicidfile_fileinfo_handle_t
			 *@endinternal
			 */
			GnMusicIdFileInfo( gnsdk_musicidfile_query_handle_t query_handle, gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle) throw (GnError) :
				query_handle_(query_handle), fileinfo_handle_(fileinfo_handle) 
			{ 
				// Need to add a reference since the query_handle_ doesn't belong to us
				gnsdk_error_t error = gnsdk_handle_addref((gnsdk_handle_t)query_handle_);
				if (error) { throw GnError(); }
			};

			GnMusicIdFileInfo(GnMusicIdFileInfo const& rhs) throw (GnError) :
				query_handle_(rhs.query_handle_), fileinfo_handle_(rhs.fileinfo_handle_) 
			{ 
				gnsdk_error_t error = gnsdk_handle_addref((gnsdk_handle_t)query_handle_);
				if (error) { throw GnError(); }
			};

			GnMusicIdFileInfo& operator=(GnMusicIdFileInfo const& rhs) throw (GnError)
			{
				if (this != &rhs)
				{
					gnsdk_handle_release((gnsdk_handle_t)query_handle_);

					query_handle_		= rhs.query_handle_;
					fileinfo_handle_	= rhs.fileinfo_handle_;

					gnsdk_error_t error = gnsdk_handle_addref((gnsdk_handle_t)query_handle_);
					if (error) { throw GnError(); }
				}

				return *this;
			}

			~GnMusicIdFileInfo()
			{
				gnsdk_handle_release((gnsdk_handle_t)query_handle_);
			}

			/**
			 *  Retrieves the identifier string from a FileInfo object.
			 *  @return gnsdk_cstr_t Pointer to receive the data value defined for the identifier
			 */
			gnsdk_cstr_t
			Identifier() throw (GnError);

			/**
			 *  Get the file name
			 *  @return File name
			 */
			gnsdk_cstr_t
			FileName() throw (GnError);

			/**
			 *  Set the file name
			 *  @param value			[in] The file name to set
			 */
			void
			FileName(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Gets the Gracenote CDDB ID value from a FileInfo object.
			 *  @return Identifier
			 */
			gnsdk_cstr_t
			CddbId() throw (GnError);

			/**
			 *  Sets the Gracenote CDDB ID.
			 *  @param value			[in] The Gracenote CDDB ID to set
			 */
			void
			CddbId(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Gets the album artist
			 *  @return Artist name
			 */
			gnsdk_cstr_t
			AlbumArtist() throw (GnError);

			/**
			 *  Sets the album artist
			 *  @param value			[in] The album artist to set
			 */
			void
			AlbumArtist(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Gets the album title
			 *  @return Album title
			 */
			gnsdk_cstr_t
			AlbumTitle() throw (GnError);

			/**
			 *  Sets the album title
			 *  @param value			[in] The album title to set
			 */
			void
			AlbumTitle(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Gets the track artist
			 *  @return Track artist
			 */
			gnsdk_cstr_t
			TrackArtist() throw (GnError);

			/**
			 *  Sets the track artist
			 *  @param value			[in] The track artist to use
			 */
			void
			TrackArtist(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Gets the track title
			 *  @return Track title
			 */
			gnsdk_cstr_t
			TrackTitle() throw (GnError);

			/**
			 *  Sets the track title
			 *  @param value			[in] The track title to set
			 */
			void
			TrackTitle(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Gets the track number
			 *  @return Track number
			 */
			gnsdk_uint32_t
			TrackNumber() throw (GnError);

			/**
			 *  Sets the track number
			 *  @param value			[in] The track number to set
			 */
			void
			TrackNumber(gnsdk_uint32_t value) throw (GnError);

			/**
			 *  Gets the disc number
			 *  @return Disc number
			 */
			gnsdk_uint32_t
			DiscNumber() throw (GnError);

			/**
			 *  Sets the disc number
			 *  @param value			[in] The disc number to set
			 */
			void
			DiscNumber(gnsdk_uint32_t value) throw (GnError);

			/**
			 *  Gets the tag ID
			 *  @return Tag identifier
			 */
			gnsdk_cstr_t
			TagId() throw (GnError);

			/**
			 *  Sets the tag ID
			 *  @param value			[in] The tag ID to set
			 */
			void
			TagId(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Gets the fingerprint data
			 *  @return Fingerprint data
			 */
			gnsdk_cstr_t
			Fingerprint() throw (GnError);

			/**
			 *  Sets the fingerprint
			 *  @param value			[in] The fingerprint to set
			 */
			void
			Fingerprint(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Gets the media ID
			 *  @return Media identifier
			 */
			gnsdk_cstr_t
			MediaId() throw (GnError);

			/**
			 *  Sets the media ID
			 *  @param value			[in] The media ID to set
			 */
			void
			MediaId(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Gets the Media Unique ID (MUI)
			 *  @return Media unique identifier
			 */
			gnsdk_cstr_t
			Mui() throw (GnError);

			/**
			 *  Sets the Media Unique ID (MUI)
			 *  @param value			[in] The Media Unique ID (MUI) to set
			 */
			void
			Mui(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Gets the CDTOC value
			 *  @return CDTOC value
			 */
			gnsdk_cstr_t
			CdToc() throw (GnError);

			/**
			 *  Sets the CDTOC value
			 *  @param value			[in] The CDTOC to set
			 */
			void
			CdToc(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Gets the Title Unique Identifier (Tui)
			 *  @return Title unique identifier
			 */
			gnsdk_cstr_t
			Tui() throw (GnError);

			/**
			 *  Sets the Title Unique Identifier (Tui)
			 *  @param value			[in] The Title Unique Identifier (Tui) to set
			 */
			void
			Tui(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Gets the Tui tag
			 *  @return Tui tag
			 */
			gnsdk_cstr_t
			TuiTag() throw (GnError);

			/**
			 *  Sets the Tui tag
			 *  @param value			[in] The Tui tag to set
			 */
			void
			TuiTag(gnsdk_cstr_t value) throw (GnError);

			/**
			 *  Initializes fingerprint generation.
			 *  @param audioSampleRate	[in] Set sample frequency of audio to be provided: 11 kHz, 22 kHz, or 44 kHz
			 *  @param audioSampleSize	[in] Set sample rate of audio to be provided (in 8-bit, 16-bit, or 32-bit bytes per sample)
			 *  @param audioChannels	[in] Set number of channels for audio to be provided (1 or 2)
			 *  <p><b>Remarks:</b></p>
			 *  The MusicID-File fingerprinting APIs allow your application to provide audio data, as opposed to
			 *  using only associated metadata, for identification.
			 *  Use these APIs either before processing has begun or during a
			 *  IGnMusicIdFileEvents or IGnMusicIdFileInfoEvents delegate method call.
			 */
			void
			FingerprintBegin(gnsdk_uint32_t audioSampleRate, gnsdk_uint32_t audioSampleSize, gnsdk_uint32_t audioChannels) throw (GnError);

			/**
			 *  Provides uncompressed audio data for fingerprint generation.
			 *  @param audioData 		[in] Pointer to audio data buffer that matches the audio format described in FingerprintBegin().
			 *  @param audioDataSize 	[in] Size of audio data buffer (in bytes)
			 *  @return bool Checks whether the fingerprint generation has received enough audio data
			 *  <p><b>Remarks:</b></p>
			 *  The provided audio data must be uncompressed PCM data and must match the format given to fingerprintBegin().
			 *  Returns true when the fingerprinter has received enough audio data for
			 *  processing. Any further provided audio data is ignored.
			 *  Your application must provide audio data until true is returned
			 *  to successfully generate an audio fingerprint.
			 *  Your application must complete the fingerprinting process by calling
			 *  FingerprintEnd() when either the audio data terminates, or after true is returned.
			 *  Use the MusicID-File fingerprinting APIs either before processing has begun, or during a
			 *  IGnMusicIdFileEvents or IGnMusicIdFileInfoEvents delegate method call.
			 */
			bool
			FingerprintWrite(const gnsdk_byte_t* audioData, gnsdk_size_t audioDataSize) throw (GnError);

			/**
			 *  Finalizes fingerprint generation.
			 *  <p><b>Remarks:</b></p>
			 *  The application must complete the fingerprinting process by calling
			 *  fingerprint_end when either the audio data terminates, or after receiving
			 *  a GNSDK_TRUE value.
			 *  Use the MusicID-File fingerprinting APIs either before processing has begun, or during a
			 *  IGnMusicIdFileEvents or IGnMusicIdFileInfoEvents delegate method call.
			 */
			void
			FingerprintEnd() throw (GnError);

			/**
			 *  Generate a fingerprint from audio pulled from the provided audio source
			 *  @param audioSource		[in] audio source representing the file being identified
			 */
			void
			FingerprintFromSource(IGnAudioSource& audioSource) throw (GnError);

			/**
			 *  Retrieves the current status for a specific FileInfo object.
			 *  <p><b>Remarks:</b></p>
			 *  The File Info object's state value indicates what kind of response is available for a FileInfo object after
			 *  MusicID-File. In the case of an error, error info can be retrieved from the FileInfo object.
			 */
			GnMusicIdFileInfoStatus
			Status() throw (GnError);

			/**
			 *  Retrieves the error information for a FileInfo object. This is related to the status returned.
			 *  If the status is error, this call returns the extended error information.
			 *  <p><b>Remarks:</b></p>
			 *  An error object is returned representing the FileInfo error condition. An error object exception
			 *  may be thrown if an error occurred retrieving the FileInfo object's error object.
			 */
			GnError
			ErrorInformation() throw (GnError);

			/**
			 *  Retrieves the album response if available
			 *  @return Album response
			 *  <p><b>Remarks:</b></p>
			 *  This function retrieves the album response object of the match for this file information object if available.
			 *  Use Status() to determine if a response is available for this file information object.
			 */
			metadata::GnResponseAlbums
			AlbumResponse() throw (GnError);

			/**
			 *  Retrieves the data match response if available
			 *  @return Data match response
			 *  <p><b>Remarks:</b></p>
			 *  This function retrieves the data match response object of the match for this file information object if available.
			 *  Data match responses mean the match could be an album or contributor or a mix thereof depending on the query options.
			 *  Use Status() to determine if a response is available for this file information object.
			 */
			metadata::GnResponseDataMatches
			DataMatchResponse () throw (GnError);

			/**
			 *  Compare GnMusicIdFileInfo object for equality
			 *  @param rhs				[in] GnMusicIdFileInfo object to compare
			 */
			bool operator == (const GnMusicIdFileInfo& rhs ) const
			{
				return ((this->fileinfo_handle_ == rhs.fileinfo_handle_) && (this->query_handle_ == rhs.query_handle_));
			}
			/**
			 *  Compare GnMusicIdFileInfo object for inequality
			 *  @param rhs				[in] GnMusicIdFileInfo object to compare
			 */
			bool operator !=(const GnMusicIdFileInfo& rhs ) const
			{
				return !operator==(rhs);
			}

		private:
			gnsdk_musicidfile_query_handle_t	query_handle_;
			gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle_;

			friend class GnMusicIdFileInfoManager;
		};


		class musicid_file_info_provider
		{
		public:
			/**
			 *@internal
			 *  Helper to allow iteration of GnMusicIdFileInfo objects
			 *  @param query_handle		[in] A C-GNSDK gnsdk_musicidfile_query_handle_t
			 *@endinternal
			 */
			musicid_file_info_provider(gnsdk_musicidfile_query_handle_t query_handle) : weakhandle_(query_handle){ }
			~musicid_file_info_provider(){ }

			/**
			 *@internal
			 *  Gets the GnMusicIdFileInfo object at the requested position
			 *  @param pos				[in] the index of obect to retrieve
			 *@endinternal
			 */
			GnMusicIdFileInfo
			get_data(gnsdk_uint32_t pos) const
			{
				gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle = GNSDK_NULL;
				if ( pos < GN_UINT32_MAX)
				{
					gnsdk_error_t  error = gnsdk_musicidfile_query_fileinfo_get_by_index(weakhandle_, pos-1, &fileinfo_handle);
					if (GNSDKERR_SEVERE(error)) { throw GnError();}
					if (!error)
						return GnMusicIdFileInfo(weakhandle_, fileinfo_handle);
				}

				return GnMusicIdFileInfo();
			}

			/**
			 *@internal
			 *  Gets the number of GnMusicIdFileInfo objects available
			 *@endinternal
			 */
			gnsdk_uint32_t
			count () const
			{
				gnsdk_uint32_t count = 0;
				gnsdk_musicidfile_query_fileinfo_count(weakhandle_, &count);
				return count;
			}

		private:
			gnsdk_musicidfile_query_handle_t weakhandle_;
		};


		typedef gn_facade_range_iterator<GnMusicIdFileInfo, musicid_file_info_provider>      musicid_file_info_iterator;

		/**
		 *  @enum GnMusicIdFileProcessType
		 *  Response and processing controls for DoTrackId, DoAlbumId and DoLibraryId
		 */
		enum GnMusicIdFileProcessType
		{
			kQueryReturnSingle = 1,
			kQueryReturnAll

		};

		/**
		 * @enum GnMusicIdFileResponseType
		 * Type of response requested from DoTrackId, DoAlbumId and DoLibraryId
		 */
		enum GnMusicIdFileResponseType
		{
			kResponseAlbums = 1,
			kResponseMatches

		};


		/**
		 * Configures options for GnMusicIdFile
		 */
		class GnMusicIdFileOptions
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 *  Indicates whether the MusicID-File query should be performed against local embedded databases or online.
			 *  @param lookupMode		[in] One of the GnLookupMode values
			 *  @ingroup MusicIdFile_Options
			 */
			void
			LookupMode(GnLookupMode lookupMode) throw (GnError);

			/**
			 *  Sets the lookup data value for the MusicID-File query.
			 *  @param val 				[in] Set One of the GnLookupData values
			 *  @param enable 			[in] True or false to enable or disable
			 *  @ingroup MusicIdFile_Options
			 */
			void
			LookupData(GnLookupData val, bool enable) throw (GnError);

			/**
			 *  Sets the batch size for the MusicID-File query.
			 *  @param size				[in] set String value or one of MusicID-File Option Values that corresponds to BATCH_SIZE
			 *  <p><b>Remarks:</b></p>
			 *  The option value provided for batch size must be greater than zero (0).
			 *  @ingroup MusicIdFile_Options
			 */
			void
			BatchSize( gnsdk_uint32_t size) throw (GnError);

			/**
			 *  Indicates whether MusicID-File should process the responses online, thus reducing client-used resources.
			 *  Your license must allow online processing.
			 *  @param enable			[in] True or false to enable or disable
			 *  @ingroup MusicIdFile_Options
			 */
			void
			OnlineProcessing(bool enable) throw (GnError);

			/**
			 *  Sets the preferred language for the MusicID-File query.
			 *  @param preferredLangauge	[in] One of the GNSDK language values
			 *  @ingroup MusicIdFile_Options
			 */
			void
			PreferResultLanguage(GnLanguage preferredLangauge) throw (GnError);

			/**
			 * Use this option to specify an external identifier which MusicID-File should try to include in any responses that are returned.
			 *  <p><b>Remarks:</b></p>
			 * This option is currently only supported when online processing is enabled.
			 *  @param preferredExternalId	[in] The name of an external identifier that should be preferred when selecting matches
			 *  @ingroup MusicIdFile_Options
			 */
			void
			PreferResultExternalId(gnsdk_cstr_t preferredExternalId) throw (GnError);


			/**
			 *  Sets the thread priority for a given MusicID-File query.
			 *  @param threadPriority 	[in] Set one of GnThreadPriority values that corresponds to thread priority
			 *  <p><b>Remarks:</b></p>
			 *  The option value provided for thread priority must be one of the defined
			 *  #GnThreadPriority values.
			 *  @ingroup MusicIdFile_Options
			 */
			void
			ThreadPriority(GnThreadPriority threadPriority) throw (GnError);

			/**
			 * Set a specific network interface to use with this object's connections. This can be useful for
			 * systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
			 *  @param intfName [in] Local IP address or system name for the desired network interface
			 *  @ingroup MusicIdFile_Options
			 */
			void
			NetworkInterface(gnsdk_cstr_t intfName) throw (GnError);

			/**
			 * Return network interface being used with this object's connections if one has been set.
			 * If no specific network interface has been set, an empty string is returned.
			 *  @ingroup MusicIdFile_Options
			 */
			gnsdk_cstr_t
			NetworkInterface() throw (GnError);

			/**
			 *  General option setting for custom options
			 *  @param optionKey		[in] Set one of the MusicID-File option keys
			 *  @param enable			[in] Set to true (enable) or false (disable)
			 *  @ingroup MusicIdFile_Options
			 */
			void
			Custom(gnsdk_cstr_t optionKey, bool enable) throw (GnError);

			/**
			 *  Set option using option name
			 *  @param option			[in] Option name
			 *  @param value			[in] Option value
			 *  @ingroup MusicIdFile_Options
			 */
			void
			Custom(gnsdk_cstr_t option, gnsdk_cstr_t value) throw (GnError);


		protected:
			GnMusicIdFileOptions() : weakhandle_(GNSDK_NULL) {}

		private:
			friend class GnMusicIdFile;
			DISALLOW_COPY_AND_ASSIGN(GnMusicIdFileOptions);

			gnsdk_musicidfile_query_handle_t weakhandle_;
		};


		/**
		 * Provides services for adding audio tracks to GnMusicIdFile for identification.
		 */
		class GnMusicIdFileInfoManager
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 * Add an audio file to GnMusicIdFile for identification
			 * @param uniqueIdentifier	[in] Audio track unique identifier such as a filename or library reference
			 * @param pEventHandler		[in-opt] Event delegate for processing events specifically for this audio file. Use
			 * 							where the generic event handler provided on GnMusicIdFile construction isn't
			 * 							suitable
			 * @return Object representing the audio file
			 */
			GnMusicIdFileInfo
			Add(gnsdk_cstr_t uniqueIdentifier, IGnMusicIdFileInfoEvents* pEventHandler = GNSDK_NULL) throw (GnError);

			/**
			 * Add audio file(s) represented by an XML string to GnMusicIdFile for identification
			 * @param xmlStr			[in] Audio file(s) XML string, such as one created using RenderToXml()
			 * @return Number of audio files added
			 */
			gnsdk_uint32_t
			AddFromXml( gnsdk_cstr_t xmlStr) throw (GnError);

			/**
			 * Render all added audio files to an XML string
			 * @return XML string
			 */
			GnString
			RenderToXml() throw (GnError);

			/**
			 * Remove and audio file from GnMusicIdFile
			 * @param fileInfo			[in] Object representing audio file to remove
			 */
			void
			Remove(const GnMusicIdFileInfo& fileInfo) throw (GnError);

			/**
			 * Get an audio file iterator set at the first audio file.
			 * @return audio file iterator
			 */
			musicid_file_info_iterator
			begin() const {
				musicid_file_info_provider provider(weakhandle_);
				return musicid_file_info_iterator(provider, 1);
			}

			/**
			 * Get an audio file iterator set at the last audio file.
			 * @return audio file iterator
			 */
			musicid_file_info_iterator
			end() const {
				musicid_file_info_provider provider(weakhandle_);
				return musicid_file_info_iterator(provider, GN_UINT32_MAX);
			}

			/**
			 * Get number of audio files added
			 * @return Number of audio files
			 */
			gnsdk_uint32_t
			count() const {
				musicid_file_info_provider provider(weakhandle_);
				return provider.count();
			}

			/**
			 * Get audio file at specified index
			 * @param index				[in] Audio file index
			 * @return file iterator
			 */
			GnMusicIdFileInfo
			at(gnsdk_uint32_t index) const {
				musicid_file_info_provider provider(weakhandle_ );
				return provider.get_data(index);
			}

			/**
			 * Get audio file at specified index
			 * @param index				[in] Audio file index
			 * @return Object representing audio file
			 */
			GnMusicIdFileInfo
			operator [](gnsdk_uint32_t index) const {
				musicid_file_info_provider provider(weakhandle_);
				return provider.get_data(index);
			}

			/**
			 * Retrieves the GnMusicIdFileInfo object that matches the given identifier string and is associated with the
			 * given MusicID-File handle.
			 * @param ident 			[in] String identifier of FileInfo to retrieve
			 * <p><b>Remarks:</b></p>
			 * The string identifier of each GnMusicIdFileInfo is set when Add is called.
			 * GnMusicIdFile enforces GnMusicIdFileInfo identifiers to be unique.
			 */
			GnMusicIdFileInfo
			GetByIdentifier(gnsdk_cstr_t ident) throw (GnError);

			/**
			* Retrieves the GnMusicIdFileInfo object that matches the given file name.
			* @param filename 			[in] File name or other string identifier of FileInfo to retrieve
			* <p><b>Remarks:</b></p>
			* Only GnMusicIdFileInfo objects that have file name information set through
			* GnMusicIdFile::FileName can be retrieved with this function.
			* <p><b>Note:</b></p>
			* GnMusicIdFile does not enforce unique GnMusucIdFileInfo file names. Consequently, to use this function
			* well, it is important to give unique file names to each GnMusicIdFileInfo added (such as the full path and
			* file name).
			* GnMusicIdFile does not check if the given file name given is a valid path or file name, nor is it
			* required to be one. GnMusicIdFile only performs a match against the existing GnMusicIdFileInfo path and file
			* names.
			*/
			GnMusicIdFileInfo
			GetByFilename(gnsdk_cstr_t filename) throw (GnError);

			/**
			 * Retrieves the index'th GnMusicIdFileInfo object matching the given folder.
			 * @param folder 			[in] Folder name of GnMusicIdFileInfo object to retrieve
			 * @param index 			[in] Index of GnMusicIdFileInfo object in folder name to retrieve
			 * <p><b>Remarks:</b></p>
			 * Only a GnMusicIdFileInfo that has path information set through GnMusicIdFile::FileName
			 * can be retrieved with this function. GnMusicId does not check if the given folder name is a valid path,
			 * nor is it required to be one. GnMusicIdFile only performs a match against existing GnMusiucIdFileInfo
			 * folder names.
			 */
			GnMusicIdFileInfo
			GetByFolder(gnsdk_cstr_t folder, gnsdk_uint32_t index) throw (GnError);


		protected:
			GnMusicIdFileInfoManager() : weakhandle_(GNSDK_NULL) {}

		private:
			DISALLOW_COPY_AND_ASSIGN(GnMusicIdFileInfoManager);
			friend class GnMusicIdFile;
			gnsdk_musicidfile_query_handle_t weakhandle_;

		};


		/**
		 *  Performs bulk audio track recognition
		 *
		 *  MusicID-File is intended to be used with collections of file-based media.
		 *  When an application provides decoded audio and text data for each file to the
		 *  library, the MusicID-File functionality both identifies each file and groups
		 *  the files into albums.
		 *
		 * <p><b>SDK Documentation</b></p>
		 * <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Audio Files
		 *
		 * For more information on using MusicID-File, see the above topic which covers:
		 * <ul>
		 *     <li>MusicID file identification mechanisms (TrackID, AlbumID, and LibraryID)</li>
		 *     <li>How to identify audio from a file</li>
		 *     <li>Implementing an events delegate<ul>
		 *     <li>Events delegate code samples</li></ul></li>
		 *     <li>Adding audio files for identification<ul>
		 *     <li>Adding audio files code samples</li></ul></li>
		 *     <li>Setting audio file identification<ul>
		 *     <li>Audio file identification code samples</li></ul></li>
		 *     <li>MusicID-File fingerprinting<ul>
		 *     <li>Fingerprinting code samples</li></ul></li>
		 *     <li>Setting options for MusicID-File queries</li>
		 *     <li>Making a MusicID-File query<ul>
		 *     <li>MusicID-file query options</li>
		 *     <li>Setting options code samples</li></ul></li>
		 * </ul>
		 *
		 * <p><b>Sample Apps</b></p>
		 * <ul>
		 *    <li>.../samples/musicid_file_trackid</li>
		 *    <li>.../samples/musicid_file_albumid</li>
		 *    <li>.../samples/musicid_file_libraryid</li>
		 * </ul>
		 *
		 * <p><b>Overiew</b></p>
		 * <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID-File Overview
		 */
		class GnMusicIdFile : public GnObject<gnsdk_musicidfile_query_handle_t>
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 *  Constructs an audio track identification object
			 *  @param user 			[in] Gracenote user object representing the user making the GnMusicIdFile request
			 *  @param pEventHandler	[in] Delegate object for receiving processing events
			 */
			GnMusicIdFile(const GnUser& user, IGnMusicIdFileEvents* pEventHandler = GNSDK_NULL) throw (GnError);
			GnMusicIdFile(const GnUser& user, GnManagedPtr<IGnMusicIdFileEvents*> eventHandler) throw (GnError);

			virtual
			~GnMusicIdFile();

			/**
			 *  Retrieves the MusicID-File library's version string.
			 *  <p><b>Remarks:</b></p>
			 *  You can call this API at any time after successfully instantiating a GnManager instance.
			 *  The returned string is a constant. Do not attempt to modify or delete.
			 *
			 *  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
			 *
			 *  Major: New functionality
			 *  Minor: New or changed features
			 *  Improvement: Improvements and fixes
			 *  Build: Internal build number
			 */
			static gnsdk_cstr_t
			Version();

			/**
			 *  Retrieves the MusicID-File library's build date string.
			 *  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
			 *  <p><b>Remarks:</b></p>
			 *  You can call this API at any time after successfully instantiating a GnManager instance.
			 *  The returned string is a constant. Do not attempt to modify or delete.
			 *
			 *  Example build date string: 2008-02-12 00:41 UTC
			 */
			static gnsdk_cstr_t
			BuildDate();

			/**
			 *  Retrieves the GnMusicIdFileOptions object.
			 */
			GnMusicIdFileOptions&
			Options() { return options_; }

			/**
			 *  Retrieves the GnMusicIdFileInfoManager object.
			 */
			GnMusicIdFileInfoManager&
			FileInfos() { return fileinfomanager_; }

			/**
			 *  Initiates TrackId processing.
			 *
			 *  @param processType		[in] Specifies what you get back
			 *  @param responseType		[in] Match response or album response
			 *
			 *  <p><b>Remarks:</b></p>
			 *  TrackId processing performs MusicID-File recognition on each given FileInfo independently
			 *  and is intended to be used with a small number of tracks that do not relate to other tracks in
			 *  the user's collection.
			 */
			void
			DoTrackId(GnMusicIdFileProcessType processType, GnMusicIdFileResponseType responseType) throw (GnError);

			/**
			 *  Initiates TrackId processing asynchronously.
			 *
			 *  @param processType		[in] specifies what you get back
			 *  @param responseType		[in] match response or album response
			 *
			 *  <p><b>Remarks:</b></p>
			 *  TrackId processing performs MusicID-File recognition on each given FileInfo independently
			 *  and is intended to be used with small number of tracks that do not relate to other tracks in
			 *  the user's collection.
			 */
			void
			DoTrackIdAsync(GnMusicIdFileProcessType processType, GnMusicIdFileResponseType responseType) throw (GnError);

			/**
			 *  Initiates AlbumId processing.
			 *
			 *  @param processType		[in] Process type specifies what you get back
			 *  @param responseType		[in] match response or album response
			 *
			 *  <p><b>Remarks:</b></p>
			 *  AlbumId processing performs MusicID-File recognition on all of the given FileInfos as a group.
			 *  This type of processing can be more accurate than TrackId processing, as AlbumId processing matches
			 *  the files to albums. Intended to be used with a small number of related tracks.
			 */
			void
			DoAlbumId(GnMusicIdFileProcessType processType, GnMusicIdFileResponseType responseType) throw (GnError);

			/**
			 *  Initiates AlbumId processing asynchronously .
			 *
			 *  @param processType		[in] Process type specifies what you get back
			 *  @param responseType		[in] match response or album response
			 *
			 *  <p><b>Remarks:</b></p>
			 *  AlbumId processing performs MusicID-File recognition on all of the given FileInfos as a group.
			 *  This type of processing can be more accurate than TrackId processing, as AlbumId processing matches
			 *  the files to albums. Intended to be used with a small number of related tracks.
			 */
			void
			DoAlbumIdAsync(GnMusicIdFileProcessType processType, GnMusicIdFileResponseType responseType) throw (GnError);

			/**
			 *  Initiates LibraryId processing.
			 *
			 *  @param responseType		[in] match response or album response
			 *
			 *  <p><b>Remarks:</b></p>
			 *  LibraryId processing performs MusicID-File recognition on a large number of given FileInfos. This
			 *  processing divides the given group of FileInfos into workable batches, and then processes each batch
			 *  using AlbumId functionality.
			 */
			void
			DoLibraryId(GnMusicIdFileResponseType responseType) throw (GnError);

			/**
			 *  Initiates LibraryId processing asyncronously
			 *
			 *  @param responseType		[in] match response or album response
			 *
			 *  <p><b>Remarks:</b></p>
			 *  LibraryId processing performs MusicID-File recognition on a large number of given FileInfos. This
			 *  processing divides the given group of FileInfos into workable batches, and then processes each batch
			 *  using AlbumId functionality.
			 */
			void
			DoLibraryIdAsync(GnMusicIdFileResponseType responseType) throw (GnError);


			/**
			 *  Value for infinite wait in a call to GnMusicIdFile.WaitForComplete().
			 *  Otherwise enter the timeout duration in milliseconds.
			 */
			static gnsdk_uint32_t kTimeValueInfinite;

			/**
			 *  Wait for a MusicID-File operation to complete, wait for the specified number of milliseconds.
			 *  @param timeoutValue		[in] Length of time to wait in milliseconds
			 *  <p><b>Remarks:</b></p>
			 *  Use this function to set a wait for TrackId, AlbumId, or LibraryId processing to complete for
			 *  a given GnMusicIdFile instance.
			 */
			void
			WaitForComplete(gnsdk_uint32_t timeoutValue) throw (GnError);

			/**
			 *  Wait for a MusicID-File operation to complete with infinite wait time.
			 *  <p><b>Remarks:</b></p>
			 *  Use this function to set a wait for TrackId, AlbumId, or LibraryId processing to complete for
			 *  a given GnMusicIdFile instance.
			 */
			void
			WaitForComplete() throw (GnError);

			/**
			 * Get the event handler provided on construction
			 * @return Event handler
			 */
			IGnMusicIdFileEvents*
			EventHandler() const { return eventHandler_.native(); }

			/**
			 * Set cancel state
			*/
			void
			Cancel();

		private:
			void
			create(const GnUser& user) throw (GnError);

			GnManagedPtr<IGnMusicIdFileEvents*>	eventHandler_;
			GnMusicIdFileOptions				options_;
			GnMusicIdFileInfoManager			fileinfomanager_;

			friend class GnMusicIdFileInfo;
			DISALLOW_COPY_AND_ASSIGN(GnMusicIdFile);
		};


		/**
		 *  Delegate interface for receiving data retrieval and status updates as various
		 *  MusicID-File operations are performed
		 */
		class IGnMusicIdFileEvents : public IGnStatusEvents
		{
		public:
			GNWRAPPER_ANNOTATE

			virtual
			~IGnMusicIdFileEvents() { };

			/**
			 *  Retrieves the current status.
			 *  @param fileInfo 		[in] FileInfo object that the callback operates on
			 *  @param status 			[in] FileInfo status
			 *  @param currentFile 		[in] Current number of the file being processed
			 *  @param totalFiles 		[in] Total number of files to be processed by the callback
			 *  @param canceller		[in] Object that can be used to cancel processing if desired
			 */
			virtual void
			MusicIdFileStatusEvent(GnMusicIdFileInfo& fileInfo, GnMusicIdFileCallbackStatus status, gnsdk_uint32_t currentFile, gnsdk_uint32_t totalFiles, IGnCancellable& canceller) = 0;

			/**
			 *  Callback function declaration for a fingerprint generation request.
			 *  @param fileInfo 		[in] FileInfo object that the callback operates on
			 *  @param currentFile  	[in] Current number of the file being processed
			 *  @param totalFiles 		[in] Total number of files to be processed
			 *  @param canceller		[in] Object that can be used to cancel processing if desired
			 *  <p><b>Remarks:</b></p>
			 *  The application can implement this callback to use the fingerprint_begin(), fingerprint_write() and fingerprint_end() APIs with the given FileInfo object to
			   generate a fingerprint from raw audio. If your application already has created the fingerprint for the respective file,
			   the application should implement this callback to use the GnMusicIdFileInfo.set*() API to set any metadata values in the FileInfo object.
			   This callback is called only if no fingerprint has already been set for the passed FileInfo object.
			 */
			virtual void
			GatherFingerprint(GnMusicIdFileInfo& fileInfo, gnsdk_uint32_t currentFile, gnsdk_uint32_t totalFiles, IGnCancellable& canceller) = 0;

			/**
			 *  Callback function declaration for a metadata gathering request.
			 *  @param fileInfo 		[in] FileInfo object that the callback operates on
			 *  @param currentFile 		[in] Current number of the file being processed
			 *  @param totalFiles 		[in] Total number of files to be processed
			 *  @param canceller		[in] Object that can be used to cancel processing if desired
			 *  <p><b>Remarks:</b></p>
			 *   The application should implement this callback to use the GnMusicIdFileInfo.set*() API to set any metadata values in the FileInfo object.
			   This callback is called only if no metadata has already been set for the passed FileInfo.
			 */
			virtual void
			GatherMetadata(GnMusicIdFileInfo& fileInfo, gnsdk_uint32_t currentFile, gnsdk_uint32_t totalFiles, IGnCancellable& canceller) = 0;

			/**
			 *  Callback function declaration for a result available notification.
			 *  @param albumResult  	[in] Album response
			 *  @param currentAlbum 	[in] Current number of the album in this response
			 *  @param totalAlbums 		[in] Total number of albums in this response
			 *  @param canceller		[in] Object that can be used to cancel processing if desired
			 *  <p><b>Remarks:</b></p>
			 *  The provided response will include results for one or more files.
			 */
			virtual void
			MusicIdFileAlbumResult(metadata::GnResponseAlbums& albumResult, gnsdk_uint32_t currentAlbum, gnsdk_uint32_t totalAlbums, IGnCancellable& canceller) = 0;

			/**
			 *  Callback function declaration for a result available notification.
			 *  @param matchesResult	[in] Match response
			 *  @param currentAlbum 	[in] Current number of the album in this response
			 *  @param totalAlbums 		[in] Total number of albums in this response
			 *  @param canceller		[in] Object that can be used to cancel processing if desired
			 *  <p><b>Remarks:</b></p>
			 *  The provided response will include results for one or more files.
			 */
			virtual void
			MusicIdFileMatchResult(metadata::GnResponseDataMatches& matchesResult, gnsdk_uint32_t currentAlbum, gnsdk_uint32_t totalAlbums, IGnCancellable& canceller) = 0;

			/**
			 *  Callback function declaration for a no results notification.
			 *  @param fileInfo 		[in] Set FileInfo object that the callback operates on
			 *  @param currentFile 		[in] Current number of the file that is not found
			 *  @param totalFiles 		[in] Total number of files to be processed
			 *  @param canceller		[in] Object that can be used to cancel processing if desired
			 */
			virtual void
			MusicIdFileResultNotFound(GnMusicIdFileInfo& fileInfo, gnsdk_uint32_t currentFile, gnsdk_uint32_t totalFiles, IGnCancellable& canceller) = 0;

			/**
			 *  Callback function declaration for MusicID-File processing completion.
			 *  @param completeError 	[in] Final error value of MusicID-File operation
			 */
			virtual void
			MusicIdFileComplete(GnError& completeError) = 0;
		};


		/**
		 *  Defines the structure of callback functions for data retrieval for
		 *  specific GnMusicIdFileInfo's
		 */
		class IGnMusicIdFileInfoEvents
		{
		public:
			GNWRAPPER_ANNOTATE

			virtual
			~IGnMusicIdFileInfoEvents() { };

			/**
			 *  Callback function declaration for a fingerprint generation request.
			 *  @param fileinfo 		[in] FileInfo object that the callback operates on
			 *  @param currentFile 		[in] Current number of the file being processed
			 *  @param totalFiles 		[in] Total number of files to be processed
			 *  @param canceller		[in] Object that can be used to cancel processing if desired
			 *  <p><b>Remarks:</b></p>
			 *  The application can implement this callback to use the fingerprint_begin(), fingerprint_write() and fingerprint_end() APIs with the given FileInfo object to
			   generate a fingerprint from raw audio. If your application already has created the fingerprint for the respective file,
			   the application should implement this callback to use the GnMusicIdFileInfo.set*() API to set any metadata values in the FileInfo object.
			   This callback is called only if no fingerprint has already been set for the passed FileInfo object.
			 */
			virtual void
			GatherFingerprint(GnMusicIdFileInfo& fileinfo, gnsdk_uint32_t currentFile, gnsdk_uint32_t totalFiles, IGnCancellable& canceller) = 0;

			/**
			 *  Callback function declaration for a metadata gathering request.
			 *  @param fileinfo 		[in] FileInfo object that the callback operates on
			 *  @param currentFile 		[in] Current number of the file being processed
			 *  @param totalFiles 		[in] Total number of files to be processed
			 *  @param canceller		[in] Object that can be used to cancel processing if desired
			 *  <p><b>Remarks:</b></p>
			 *   The application should implement this callback to use the GnMusicIdFileInfo.set*() API to set any metadata values in the FileInfo object.
			   This callback is called only if no metadata has already been set for the passed FileInfo.
			 */
			virtual void
			GatherMetadata(GnMusicIdFileInfo& fileinfo, gnsdk_uint32_t currentFile, gnsdk_uint32_t totalFiles, IGnCancellable& canceller) = 0;
		};
	} /* namespace musicid_file */

}     /* namespace gracenote */

#endif /* GNSDK_MUSICID_FILE */

#endif /* _GNSDK_MUSICIDFILE_HPP_ */
