/** Public header file for Gracenote SDK C++ Wrapper
 * Author:
 *   Copyright (c) 2000-2015 Gracenote, Inc.
 *
 *   This software may not be used in any way or distributed without
 *   permission. All rights reserved.
 *
 *   Some code herein may be covered by US and international patents.
 */

/**
*  @file gnsdk_musicid.hpp
*/

#ifndef _GNSDK_MUSICID_HPP_
#define _GNSDK_MUSICID_HPP_

#ifndef __cplusplus
#error "C++ compiler required"
#endif

#include "gnsdk_base.hpp"
#include "metadata_music.hpp"
#include "gn_audiosource.hpp"

#if GNSDK_MUSICID

/**
* \namespace gracenote
*/
namespace gracenote
{
	/**
	* \namespace musicid
	*/
	namespace musicid
	{
		/**
		 * @enum GnMusicIdInfo
		 * Represents the different information types that can be retrieved from
		 * a GnMusicId object.
		 * @ingroup Music_MusicID_TypesEnums
		 */
		enum GnMusicIdInfo
		{
			kInfoInvalid = 0,

			/** If Audio Suitability Processing enabled this information type
			 * indicates if the received audio is suitable for music identification
			 * query. If not the query is less likely to return a match.
			 * This info type is experimental and subject to change.
			 */
			kInfoSuitableForQuery
		};

		/**
		 * \class GnMusicIdOptions
		 * Configures options for GnMusicId
		 */
		class GnMusicIdOptions
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 *  Indicate whether the MusicID query should be performed against local embedded databases or online.
			 *  @param lookupMode  [in] One of the #GnLookupMode values
			 *  @ingroup MusicId_Options
			 */
			void
			LookupMode(GnLookupMode lookupMode) throw (GnError);

			/**
			 *  Return current lookup mode for MusicID query
			 *  @ingroup MusicId_Options
			 */
			GnLookupMode
			LookupMode() throw (GnError);

			/**
			 *  Set the lookup data value for the MusicID query.
			 *  @param lookupData [in] One of the #GnLookupData values
			 *  @param bEnable    [in] Set lookup data
			 *  @ingroup MusicId_Options
			 */
			void
			LookupData(GnLookupData lookupData, bool bEnable) throw (GnError);

			/**
			 *  Set the preferred language for the returned results.
			 *  @param preferredLanguage [in] One of the GNSDK language values
			 *  @ingroup MusicId_Options
			 */
			void
			PreferResultLanguage(GnLanguage preferredLanguage) throw (GnError);

			/**
			 *  Set the preferred external ID of the returned results.
			 *  Only available where single result is also requested.
			 *  @param strExternalId [in] Gracenote external ID source name
			 *  @ingroup MusicId_Options
			 */
			void
			PreferResultExternalId(gnsdk_cstr_t strExternalId) throw (GnError);

			/**
			 *  Set that you would like cover art (if availble) in the returned results.
			 *  @param bEnable [in] Set prefer cover art
			 *  @ingroup MusicId_Options
			 */
			void
			PreferResultCoverart(bool bEnable) throw (GnError);

			/**
			 *  Set that the response must return only a single best result.
			 *  When enabled, a single full result is returned; when disabled, multiple partial results may be returned.
			 *  @param bEnable [in] Set single result
			 *  <p><b>Remarks:</b></p>
			 *  If enabled, the MusicID library selects the single best result based on the query type and input.
			 *  @ingroup MusicId_Options
			 */
			void
			ResultSingle(bool bEnable) throw (GnError);

			/**
			 *  Enable or disable revision check option.
			 *  @param bEnable [in] Set revision check
			 *
			 * Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
			 *  @ingroup MusicId_Options
			 */
			void
			RevisionCheck(bool bEnable) throw (GnError);

			/**
			 *  Specfies whether a response must return a range of results beginning at a specified value.
			 *  @param resultStart  [in] Result range start value
			 *  <p><b>Remarks:</b></p>
			 *  This option is useful for paging through results.
			 *  <p><b>Note:</b></p>
			 *  Gracenote Service enforces that the range start value must be less than or equal to the total
			 *  number of results. If you specify a range start value that is greater than the total number of
			 *  results, no results are returned.
			 *  @ingroup MusicId_Options
			 */
			void
			ResultRangeStart(gnsdk_uint32_t resultStart) throw (GnError);

			/**
			 *  Set the maximum number of results to return.
			 *  @param resultCount  [in] Maximum results
			 *  <p><b>Note:</b></p>
			 *  Gracenote Service enforces its own maximum number of results that can vary over time and query types.
			 *  This setting sets a maximum that can be as high as the Service maximum  but not higher.
			 *  @ingroup MusicId_Options
			 */
			void
			ResultCount(gnsdk_uint32_t resultCount) throw (GnError);

			/**
			 * Set a specific network interface to use with this object's connections. This can be useful for
			 * systems with multiple network interfaces. Otherwise, the operating system determines the interface to use.
			 *  @param intfName [in] Local IP address or system name for the desired network interface
			 *  @ingroup MusicId_Options
			 */
			void
			NetworkInterface(gnsdk_cstr_t intfName) throw (GnError);

			/**
			 * Return the network interface being used with this object's connections if one has been set.
			 * If no specific network interface has been set, this option returns an empty string.
			 *  @ingroup MusicId_Options
			 */
			gnsdk_cstr_t
			NetworkInterface() throw (GnError);

			/**
			 * Specifies whether GnMuisicId processes received audio for music identification
			 * suitability.
			 * This option is experimental and subject to change
			 * @ingroup MusicId_Options
			 */
			void
			AudioSuitabilityProcessing(bool bEnable) throw (GnError);			

			/**
			 *  Set option using option name
			 *  @param option   [in] Option name
			 *  @param value	[in] Option value
			 *  @ingroup MusicId_Options
			 */
			void
			Custom(gnsdk_cstr_t option, gnsdk_cstr_t value) throw (GnError);


			/**
			 *  Set option using option name
			 *  @param option   [in] Option name
			 *  @param bEnable	[in] Option enable true/false
			 *  @ingroup MusicId_Options
			 */
			void
			Custom(gnsdk_cstr_t option, bool bEnable) throw (GnError);

		protected:
			GnMusicIdOptions() : weakhandle_(GNSDK_NULL) {}

		private:
			friend class GnMusicId;
			gnsdk_musicid_query_handle_t weakhandle_;
			DISALLOW_COPY_AND_ASSIGN(GnMusicIdOptions);
		};

		/**
		 *  \class GnMusicId
		 *  Provides services for audio recognition using CD TOC-based search,
		 *  text-based search, fingerprint, and identifier lookup functionality.
		 *
		 *  <p><b>SDK Documentation</b></p>
		 *  <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Music Using a CD-TOC, Text, or Fingerprints (MusicID)
		 *
		 *  For more information on using MusicID, see the above topic which covers:
		 *    <ul>
		 *   <li>MusicID queries</li>
		 *   <li>Options for MusicID queries</li>
		 *   <li>Identifying music using a CD TOC<ul>
		 *   <li>Code samples for identifying music using a CD TOC</li></ul></li>
		 *   <li>Identifying music using text<ul>
		 *   <li>Code samples for identifying music using text</li></ul></li>
		 *   <li>Identifying music using fingerprints</li>
		 *   <li>MusicID fingerprinting<ul>
		 *   <li>Code samples for identifying music using MusicID fingerprinting</li></ul></li>
		 *   </ul>
		 *
		 *  <p><b>Overiew</b></p>
		 *  <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID Overview
		 *
		 *  <p><b>Sample Apps</b></p>
		 *  <ul>
		 *     <li>.../samples/musicid_gdo_navigation</li>
		 *     <li>.../samples/musicid_lookup_album_id</li>
		 *     <li>.../samples/musicid_lookup_album_local_online</li>
		 *     <li>.../samples/musicid_lookup_album_toc</li>
		 *     <li>.../samples/musicid_lookup_matches_text</li>
		 *     <li>.../samples/musicid_persist_and_manage</li>
		 *     <li>.../samples/musicid_persist_results</li>
		 *   </ul>
		 *
		 */
		class GnMusicId : public GnObject<gnsdk_musicid_query_handle_t>
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 *  Constructs a music identification query object with a Gracenote user and event delegate
			 *  @param user          [in] Set GnUser object representing the user making the GnMusicId request
			 *  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed.
			 */
			GnMusicId(const GnUser& user, IGnStatusEvents* pEventHandler = GNSDK_NULL) throw (GnError);
			GnMusicId(const GnUser& user, GnManagedPtr<IGnStatusEvents*> eventHandler) throw (GnError);

			/**
			 *  Constructs a music identification query object with a Gracenote user, locale and event delegate
			 *  @param user          [in] Set GnUser object representing the user making the GnMusicId request
			 *  @param locale		 [in] GnLocale object representing region and language preferred for MusicID-Stream responses
			 *  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed.
			 */
			GnMusicId(const GnUser& user, const GnLocale& locale, IGnStatusEvents* pEventHandler = GNSDK_NULL) throw (GnError);
			GnMusicId(const GnUser& user, const GnLocale& locale, GnManagedPtr<IGnStatusEvents*> eventHandler) throw (GnError);

			virtual
			~GnMusicId( );


			/**
			 *  Retrieves the MusicID library version string.
			 *  @return gnsdk_cstr_t Version string, if successful
			 *  <p><b>Remarks:</b></p>
			 *  You can call this API after successfully instantiating a GnManager instance.
			 *  The returned string is a constant. Do not attempt to modify or delete.
			 *
			 *  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
			 *
			 *  Major: New functionality
			 *
			 *  Minor: New or changed features
			 *
			 *  Improvement: Improvements and fixes
			 *
			 *  Build: Internal build number
			 */
			static gnsdk_cstr_t
			Version();


			/**
			 *  Retrieves the MusicID SDK's build date string.
			 *  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
			 *  <p><b>Remarks:</b></p>
			 *  You can call this API after successfully instantiating a GnManager instance.
			 *  The returned string is a constant. Do not attempt to modify or delete.
			 *
			 *  Example build date string: 2008-02-12 00:41 UTC
			 */
			static gnsdk_cstr_t
			BuildDate();



			/**
			 *  Retrieves externally- and internally-generated Gracenote
			 *  fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint data.
			 *  @return String fingerprint data
			 */
			gnsdk_cstr_t
			FingerprintDataGet() throw (GnError);


			/**
			 *  Initializes native fingerprint generation for a MusicID query.
			 *  @param fpType 			[in] One of the GnFingerprintType fingerprint data types,
			 *  						either Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX)
			 *  @param audioSampleRate 	[in] Sample rate of audio to be provided in Hz (for example,44100)
			 *  @param audioSampleSize 	[in] Size of a single sample of audio to be provided: 8 for 8-bit audio
			 *  						(0-255 integers), 16 for 16-bit audio , and 32 for 32-bit audio (floating point)
			 *  @param audioChannels 	[in] Number of channels for audio to be provided (1 or 2)
			 */
			void
			FingerprintBegin(GnFingerprintType fpType, gnsdk_uint32_t audioSampleRate, gnsdk_uint32_t audioSampleSize, gnsdk_uint32_t audioChannels) throw (GnError);


			/**
			 *  Provides uncompressed audio data to a query for native fingerprint generation and returns
			 *  a boolean value indicating when enough data has been received.
			 *  @param audioData 		[in] Pointer to audio data buffer that matches audio format described in
			 *  						FingerprintBegin().
			 *  @param audioDataSize 	[in] Size of audio data buffer in bytes
			 *  @return True fingerprint generation process gathered enough audio data, false otherwise.
			 *  <p><b>Remarks:</b></p>
			 *  Call this API after FingerprintBegin() to:
			 *  <ul>
			 *  <li>Generate a native Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint.
			 *  <li>Receive a boolean value indicating whether MusicID has
			 *  received sufficient audio data to generate the fingerprint.
			 *  </ul>
			 *  Additionally, if fingerprints have been generated (as shown by the returned
			 *  value):
			 *  <ul>
			 *  <li>Optimally, stop calling FingerprintWrite after it returns true
			 *  to conserve application resources.
			 *  <li>Call FingerprintDataGet() for cases where the application needs to retrieve the
			 *  raw fingerprint value from storage.
			 *  </ul>
			 */
			bool
			FingerprintWrite(const gnsdk_byte_t* audioData, gnsdk_size_t audioDataSize) throw (GnError);


			/**
			 *  Finalizes native fingerprint generation for a MusicID query handle.
			 *  <p><b>Remarks:</b></p>
			 *  Call this API when the audio stream ends - this alerts the system that it has received all the
			 *  available audio for a particular stream.
			 *  If FingerprintWrite() returns True before the stream ends, we recommend that you:
			 *  <ul>
			 *  <li>Stop providing audio at that time, since enough has been received.
			 *  <li>Do not FingerprintEnd(), as this is unnecessary.
			 *  </ul>
			 *  Fingerprints may be generated based on the call to this API; however, this is not guaranteed.
			 */
			void
			FingerprintEnd( ) throw (GnError);

			/**
			 *  Creates a fingerprint from the given audio stream represented by an implementation
			 *  of IGnAudioSource. Once completed, call FingerprintDataGet() for cases where the application needs
			 *  to retrieve the raw fingerprint value from storage.
			 *  This is an alternate and often simpler method for generating a
			 *  fingerprint instead of calling FingerprintBegin, FingerprintWrite and FingerprintEnd.
			 *  To use this method, the audio source to be fingerprinted must be accessible via an IGnAudioSource
			 *  implementation. Custom implementations of IGnAudioSource are encouraged.
			 *  @param audioSource		[in] Audio source to fingerprint
			 *  @param fpType			[in] One of the GnFingerprintType fingerprint data types,
			 *  						either Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX)
			 */
			void
			FingerprintFromSource(IGnAudioSource& audioSource, GnFingerprintType fpType) throw (GnError);

			/**
			 *  Performs a MusicID query for album results based on text input.
			 *  @param albumTitle           [in] Album title
			 *  @param trackTitle           [in] Track title
			 *  @param albumArtistName      [in] Album Artist name
			 *  @param trackArtistName      [in] Track Artist name
			 *  @param composerName         [in] Album Composer ( e.g. Classical, Instrumental, Movie Score)
			 *  @return An instance of GnResponseAlbums that contain Album metadata.
			 *
			 * Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
			 */
			metadata::GnResponseAlbums
			FindAlbums(gnsdk_cstr_t albumTitle, gnsdk_cstr_t trackTitle, gnsdk_cstr_t albumArtistName, gnsdk_cstr_t trackArtistName, gnsdk_cstr_t composerName) throw (GnError);


			/**
			 *  Performs a MusicID query for album results using a CD TOC
			 *  @param CDTOC             [in] Compact Disc Table Of Contents
			 *  @return An instance of GnResponseAlbums that contain Album metadata.
			 *
			 *  Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
			 */
			metadata::GnResponseAlbums
			FindAlbums(gnsdk_cstr_t CDTOC) throw (GnError);

			/**
			 *  Performs a MusicID query for album results using CD TOC togther with fingerprint data
			 *  @param CDTOC             	[in] Compact Disc Table Of Contents
			 *  @param strFingerprintData	[in] Fingerprint data
			 *  @param fpType            	[in] One of the #GnFingerprintType fingerprint types
			 *  @return An instance of GnResponseAlbums that contain Album metadata.
			 *
			 *  Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
			 */
			metadata::GnResponseAlbums
			FindAlbums(gnsdk_cstr_t CDTOC, gnsdk_cstr_t strFingerprintData, GnFingerprintType fpType) throw (GnError);


			/**
			 *  Performs a MusicID query for album results using fingerprint data and finger print type.
			 *  @param fingerprintData 	[in] Fingerprint data
			 *  @param fpType 			[in] One of the #GnFingerprintType fingerprint types
			 *  @return An instance of GnResponseAlbums that contain Album metadata.
			 *
			 * Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
			 */
			metadata::GnResponseAlbums
			FindAlbums(gnsdk_cstr_t fingerprintData, GnFingerprintType fpType) throw (GnError);


			/**
			 *  Performs a MusicID query for album results.
			 *  @param gnDataObject      [in] Gracenote data object
			 *  @return An instance of GnResponseAlbums that contain Album metadata.
			 *
			 * Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
			 */
			metadata::GnResponseAlbums
			FindAlbums(const metadata::GnDataObject& gnDataObject) throw (GnError);


			/**
			 *  Performs a MusicID query for album results.
			 *  @param audioSource     	[in] A valid IGnAudioSource object.
			 *  @param fpType 			[in] One of the #GnFingerprintType fingerprint types
			 *  @return An instance of GnResponseAlbums that contain Album metadata.
			 *
			 * Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
			 */
			metadata::GnResponseAlbums
			FindAlbums(IGnAudioSource& audioSource, GnFingerprintType fpType) throw (GnError);


			/**
			 *  Performs a MusicID query for best Matches results, being GnAlbum and/or GnContributor matches ordered in priority.
			 *  @param albumTitle             [in] Album title
			 *  @param trackTitle             [in] Track title
			 *  @param albumArtistName        [in] Album Artist name
			 *  @param trackArtistName        [in] Track Artist name
			 *  @param composerName           [in] Album Composer ( e.g. Classical, Instrumental, Movie Score)
			 *  @return Response containing Album, Track and Artist metadata.
			 *
			 * Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
			 */
			metadata::GnResponseDataMatches
			FindMatches(gnsdk_cstr_t albumTitle, gnsdk_cstr_t trackTitle, gnsdk_cstr_t albumArtistName, gnsdk_cstr_t trackArtistName, gnsdk_cstr_t composerName) throw (GnError);

			/**
			 * Get the event handler provided on construction
			 * @return Event handler
			 */
			IGnStatusEvents*
			EventHandler() { return eventHandler_.native();}

			/**
			 * Get GnMusicId options object. Use to configure your GnMusicId instance.
			 * @return Options objects
			 */
			GnMusicIdOptions& Options() { return options_;}

			/**
			 * Set cancel state
			 * @param bCancel 	[in] Cancel state
			 */
			virtual void
			SetCancel(bool bCancel)
			{
				cancelled_ = bCancel;
			}

			/**
			 * Get cancel state.
			 * @return Cancel state
			 */
			virtual bool
			IsCancelled()
			{
				return cancelled_;
			}

			/**
			 *  Returns information about the GnMusicId instance
			 *  @param infoType		[in] Information type
			 *  @return GnString containing the requested information
			 */
			GnString
			InfoGet(GnMusicIdInfo infoType) throw (GnError);

			/**
			 *  Returns information about the GnMusicId instance
			 *  @param key		[in] Information key
			 *  @return GnString containing the requested information
			 */
			GnString
			InfoGet(gnsdk_cstr_t key) throw (GnError);

		private:
			void
			create(const GnUser& user, const GnLocale& locale) throw (GnError);

			GnManagedPtr<IGnStatusEvents*>	eventHandler_;
			GnMusicIdOptions				options_;
			bool							cancelled_;

			/* disallow assignment operator */
			DISALLOW_COPY_AND_ASSIGN(GnMusicId);
		};
	} /* namespace musicid */

}     /* namespace gracenote */

#endif /* GNSDK_MUSICID */

#endif /* _GNSDK_MUSICID_HPP_ */

