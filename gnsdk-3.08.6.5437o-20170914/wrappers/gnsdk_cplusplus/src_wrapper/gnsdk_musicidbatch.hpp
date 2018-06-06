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

#ifndef _GNSDK_MUSICID_BATCH_HPP_
#define _GNSDK_MUSICID_BATCH_HPP_

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
	namespace musicid_batch
	{
		/**
		 * \class GnMusicIdBatchOptions
		 * Configures options for GnMusicIdBatch
		 */
		class GnMusicIdBatchOptions
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
			 *  Indicates whether the query should attempt to lookup & include the requested image size in the response.
			 *  @param GnImageSize  [in] One of the #GnImageSize values
			 *  @ingroup MusicId_Options
			 */
			void
			InlineImage(GnImageSize imageSize) throw (GnError);

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
			 * Set a specific network interface to use with this object's connections. This can be useful for
			 * systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
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

		private:
			friend class GnMusicIdBatch;

			GnMusicIdBatchOptions() : weakhandle_(GNSDK_NULL) {}
			gnsdk_musicid_batch_handle_t weakhandle_;

			DISALLOW_COPY_AND_ASSIGN(GnMusicIdBatchOptions);
		};

		/**
		 *  \class GnMusicIdBatch
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
		class GnMusicIdBatch : public GnObject<gnsdk_musicid_batch_handle_t>
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 *  Defualt constructs a batch music identification query object
			 */
			GnMusicIdBatch() throw (GnError);
			
			/**
			 *  Constructs a batch music identification query object with a Gracenote user and event delegate
			 *  @param user          [in] Set GnUser object representing the user making the GnMusicId request
			 *  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed.
			 */
			GnMusicIdBatch(const GnUser& user, IGnStatusEvents* pEventHandler = GNSDK_NULL) throw (GnError);
			GnMusicIdBatch(const GnUser& user, GnManagedPtr<IGnStatusEvents*> eventHandler) throw (GnError);

			/**
			 *  Constructs a batch music identification query object with a Gracenote user, locale and event delegate
			 *  @param user          [in] Set GnUser object representing the user making the GnMusicIdBatch request
			 *  @param locale		 [in] GnLocale object representing region and language preferred for MusicID-Stream responses
			 *  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed.
			 */
			GnMusicIdBatch(const GnUser& user, const GnLocale& locale, IGnStatusEvents* pEventHandler = GNSDK_NULL) throw (GnError);
			GnMusicIdBatch(const GnUser& user, const GnLocale& locale, GnManagedPtr<IGnStatusEvents*> eventHandler) throw (GnError);

			virtual
			~GnMusicIdBatch();
			
			/**
			 *  Clear all queries from batch music identification
			 */
			void
			Clear() throw (GnError);
			
			/**
			 *  Perform album find for all individual queries in the batch
			 */
			void
			FindAlbums() throw (GnError);

			/**
			 *  Perform match find for all individual queries in the batch
			 */
			void
			FindMatches() throw (GnError);

			/**
			 *  Retrieve album query from batch music identification
			 */
			metadata::GnResponseAlbums
			GetAlbums(const gnsdk_cstr_t unique_id) throw (GnError);

			/**
			 *  Retrieve match query from batch music identification
			 */
			metadata::GnResponseDataMatches
			GetMatches(gnsdk_cstr_t unique_id) throw (GnError);

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
			 * Get the event handler provided on construction
			 * @return Event handler
			 */
			IGnStatusEvents*
			EventHandler() { return eventHandler_.native();}

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
			 * Get GnMusicIdBatchOption options object. Use to configure your GnMusicIdBatch instance.
			 * @return Options objects
			 */
			GnMusicIdBatchOptions& Options() { return options_;}

		private:
		
			void
			create(const GnUser& user, const GnLocale& locale) throw (GnError);

			GnManagedPtr<IGnStatusEvents*>	eventHandler_;
			GnMusicIdBatchOptions			options_;
			bool							cancelled_;

			/* disallow assignment operator */
			DISALLOW_COPY_AND_ASSIGN(GnMusicIdBatch);
		};

		/**
		 * \class GnMusicIdBatchQuery
		 * Configures query for GnMusicIdBatch
		 */
		class GnMusicIdBatchQuery
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 *  Constructs a batch music identification query object with a unique identifier
			 *  @param batch		[in] GnMusicIdBatch object to use with query
			 *  @param unique_id	[in] Unique identifier for batch query
			 */
			GnMusicIdBatchQuery(GnMusicIdBatch& batch, gnsdk_cstr_t uniqueId) throw (GnError);

			virtual
			~GnMusicIdBatchQuery();
			
			/**
			 *  Sets externally- and internally-generated Gracenote fingerprint
			 *  fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint data.
			 *	Use with GnMusicIdBatch::GetAlbums
			 *  @param strFingerprintData	[in] Audio source to fingerprint
			 *  @param fpType				[in] One of the GnFingerprintType fingerprint data types,
			 */
			void
			SetFingerprint(gnsdk_cstr_t strFingerprintData, GnFingerprintType fpType) throw (GnError);
			
			/**
			 *  Sets metadata::GnDataObject, use with GnMusicIdBatch::GetAlbums
			 *  @param gnObj				[in] An metadata::GnDataObject object
			 */
			void
			SetGDO(const metadata::GnDataObject& gnObj) throw (GnError);

			/**
			 *  Sets text string, use with GnMusicIdBatch::GetAlbums and GnMusicIdBatch::GetMatches
			 *  @param albumTitle			[in] Album title string
			 *  @param trackTitle			[in] Track title string
			 *  @param albumArtistName		[in] Album artist string
			 *  @param trackArtistName		[in] Track artist string
			 *  @param composerName			[in] Composer string
			 */
			void
			SetText(gnsdk_cstr_t albumTitle, gnsdk_cstr_t trackTitle, gnsdk_cstr_t albumArtistName, gnsdk_cstr_t trackArtistName, gnsdk_cstr_t composerName) throw (GnError);
			
			/**
			 *  Sets TOC Offset
			 *  @param strCDTOC				[in] CD TOC string
			 */
			void
			SetTOCOffset(gnsdk_uint32_t tocOffset) throw (GnError);

			/**
			 *  Sets CDTOC string, use with GnMusicIdBatch::GetAlbums
			 *  @param strCDTOC				[in] CD TOC string
			 */
			void
			SetTOC(gnsdk_cstr_t strTOC) throw (GnError);

		private:

			gnsdk_musicid_batch_handle_t	weakhandle_;
			GnString						uniqueId_;

			DISALLOW_COPY_AND_ASSIGN(GnMusicIdBatchQuery);
		};
		
	} /* namespace musicid */

}     /* namespace gracenote */

#endif /* GNSDK_MUSICID */

#endif /* _GNSDK_MUSICID_BATCH_HPP_ */

