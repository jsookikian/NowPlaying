/** Public header file for Gracenote SDK C++ Wrapper
 * Author:
 *   Copyright (c) 2000-2015 Gracenote, Inc.
 *
 *   This software may not be used in any way or distributed without
 *   permission. All rights reserved.
 *
 *   Some code herein may be covered by US and international patents.
 */

#ifndef _GNSDK_LOOKUP_LOCAL_HPP_
#define _GNSDK_LOOKUP_LOCAL_HPP_

#ifndef __cplusplus
#error "C++ compiler required"
#endif

#include "gnsdk_base.hpp"

#if GNSDK_LOOKUP_LOCAL

namespace gracenote
{
	namespace lookup_local
	{
		/**
		 * Gracenote local database names
		 * Gracenote supports local lookup for various types of identification
		 * and content, each is provided in its own Gracenote database. Each name
		 * represents a specific local Gracenote database.
		 * @ingroup Setup_StorageIDs
		 */
		enum GnLocalStorageName
		{
			kLocalStorageInvalid = 0,

			/**
			 * Local storage used for querying Gracenote content.
			 * @ingroup Setup_StorageIDs
			 */
			kLocalStorageContent,

			/**
			 * Local storage used for querying Gracenote metadata.
			 * @ingroup Setup_StorageIDs
			 */
			kLocalStorageMetadata,

			/**
			 * Local storage used for CD TOC searching.
			 * @ingroup Setup_StorageIDs
			 */
			kLocalStorageTOCIndex,

			/**
			 * Local storage used for text searching.
			 * @ingroup Setup_StorageIDs
			 */
			kLocalStorageTextIndex,

			/**
			 * For referencing all the above storages that make up the local storage.
			 * @ingroup Setup_StorageIDs
			 */
			kLocalStorageAll
		};

		enum GnLocalStorageInfo
		{
			kLocalStorageInfoInvalid	= 0,

			kLocalStorageInfoVersion,
			kLocalStorageInfoImageSize
		};

		/**
		 *
         * GnLookupLocal
         *
		 * Provides services for local lookup of various identification queries such as
		 * text and CD TOC search and provides services for local retreival of content
		 * such as cover art.
		 *
		 * <b>SDK Documentation</b>
		 *
		 * Topic: .../docs/html-oo > index.html > Implementing Applications (All Platforms) > Enabling and Using GNSDK Storage
		 *
		 * For more information on GNSDK storage, see the above topic which covers:
		 * <ul>
		 *     <li>How to enable and manage GNSDK storage</li>
		 *     <li>Enabling a provider for GNSDK storage</li>
		 *     <li>Enabling storage code samples</li>
		 *     <li>GNSDK stores</li>
		 *     <li>GNSDK databases</li>
		 *     <li>Setting GNSDK storage folder locations</li>
		 *     <li>Setting a storage folder location code samples</li>
		 *     <li>Storing query results in local storage</li>
		 *     <li>Storing query results in local storage code samples</li>
		 *     <li>Getting local lookup database information</li>
		 *     <li>Setting online cache expiration</li>
		 *     <li>Managing online cache size and memory</li>
		 * </ul>
		 *
		 * <b>Sample App</b>
		 *
		 *     - .../samples/musicid_lookup_album_local_online
		 */
		class GnLookupLocal
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 * Enable local lookup for various identification queries such as
			 * text and CD TOC search; plus enable services for local retreival of
			 * content such as cover art.
			 * @ingroup Music_LookupLocal_InitializationFunctions
			 */
			static GnLookupLocal&
			Enable() throw (GnError);

			virtual ~GnLookupLocal() { }

			/**
			 *  Version
			 *  Retrieves the Lookup Local SDK version string.
			 *  @return version string if successful
			 *  @return GNSDK_NULL if not successful
			 *  <p><b>Remarks:</b></p>
			 *  You can call this API at any time after you have instantiated a GnManager instance. The returned
			 *  string is a constant. Do not attempt to modify or delete.
			 *  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
			 *  Major: New functionality
			 *  Minor: New or changed features
			 *  Improvement: Improvements and fixes
			 *  Build: Internal build number
			 */
			static gnsdk_cstr_t Version();

			/**
			 *  BuildDate
			 *  Retrieves the Lookup Local SDK's build date string.
			 *  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC
			 *  <p><b>Remarks:</b></p>
			 *  You can call this API at any time after you have instantiated a GnManager instance. The returned
			 *   string is a constant. Do not attempt to modify or delete.
			 *  Example build date string: 2008-02-12 00:41 UTC
			 */
			static gnsdk_cstr_t BuildDate();

			/**
			 *  Sets location where GNSDK can find a specific local lookup database
			 *	@param storageName 		[in] local storage name
			 *	@param storageLocation 	[in] local storage location
			 */
			void StorageLocation(GnLocalStorageName storageName, gnsdk_cstr_t storageLocation) throw (GnError);

			/**
			 *  Validate named local storage.
			 *	@param storageName [in] local storage name
			 */
			void StorageValidate(GnLocalStorageName storageName) throw (GnError);

			/**
			 *  Retrieves the Local Storage information for named storage
			 *  @param storageName 		[in] local storage name
			 *  @param storageInfo 		[in] local storage info type
			 *  @param ordinal 			[in] ordinal
			 *  @return info string if successful, GNSDK_NULL if not successful
			 */
			gnsdk_cstr_t StorageInfo(GnLocalStorageName storageName, GnLocalStorageInfo storageInfo, gnsdk_uint32_t ordinal) throw (GnError);

			/**
			 *  Retrieves the Local Storage information count for named storage
			 *  @param storageName 		[in] local storage name
			 *  @param storageInfo 		[in] local storage info type
			 *  @return count if successful, 0 if not successful
			 */
			gnsdk_uint32_t StorageInfoCount(GnLocalStorageName storageName, GnLocalStorageInfo storageInfo) throw (GnError);

		private:
			GnLookupLocal() throw (GnError) {};

			DISALLOW_COPY_AND_ASSIGN(GnLookupLocal);
		};
	} // namespace lookup_local

}     // namespace gracenote

#endif /* GNSDK_LOOKUP_LOCAL */

#endif // _GNSDK_LOOKUP_LOCAL_HPP_
