/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
  *
 */

/* gnsdk_lookup_local.h: Primary interface for the Lookup Local module.
 */
#ifndef _GNSDK_LOOKUP_LOCAL_H_
#define _GNSDK_LOOKUP_LOCAL_H_

#include "gnsdk_manager.h"

#ifdef __cplusplus
extern "C"{
#endif


/******************************************************************************
 * Initialization APIs
 ******************************************************************************/

/** @internal gnsdk_lookup_local_initialize @endinternal
  * Initializes the Lookup Local module.
  * This function must be successfully called before any calls to other Lookup Local APIs will succeed.
  * @param sdkmgr_handle [in] Handle from a successful gnsdk_manager_initialize() call.
  * @hideinitializer
  * @ingroup Setup_LookupLocal_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_lookup_local_initialize(
	gnsdk_manager_handle_t sdkmgr_handle
	);

/** @internal gnsdk_lookup_local_shutdown @endinternal
  * Shuts down and release resources for the Lookup Local module.
  * gnsdk_lookup_local_shutdown must be called to shutdown this module;
  * all Lookup Local APIs cease to function until the module is again initialized.
  * @hideinitializer
  * @ingroup Setup_LookupLocal_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_lookup_local_shutdown(void);

/** @internal gnsdk_lookup_local_get_version @endinternal
  * Retrieves the Lookup Local module version string.
  * This API can be called at any time, even before initialization and after shutdown.
  * @hideinitializer
  * @ingroup Setup_LookupLocal_Functions
*/
GNSDK_EXPORTED gnsdk_cstr_t GNSDK_API
gnsdk_lookup_local_get_version(void);

/** @internal gnsdk_lookup_local_get_build_date @endinternal
  * Retrieves the Lookup Local module's build date string.
  * This API can be called at any time, even before initialization and after shutdown.
  * @hideinitializer
  * @ingroup Setup_LookupLocal_Functions
*/
GNSDK_EXPORTED gnsdk_cstr_t GNSDK_API
gnsdk_lookup_local_get_build_date(void);

/******************************************************************************
 * Lookup local storage management APIs
 ******************************************************************************/
/** 
 * Please specify the storage locations in config_handle passed in to a call to 
 * the SDK Manager's gnsdk_lookupdatabase_open() API.
*/
GNSDK_DEPRECATED gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_location_set(
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t	storage_location
	);

/** 
 * Use the SDK Manager's gnsdk_lookupdatabase_validate() instead.
*/
GNSDK_DEPRECATED gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_validate(
	gnsdk_cstr_t			storage_name,
	gnsdk_error_info_t*		p_valid
	);

/** 
 * Use the SDK Manager's gnsdk_lookupdatabase_info_get() and INFO GDO keys.
*/
GNSDK_DEPRECATED gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_version_get(
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t*	p_gdb_version
	);
	
/** 
 * Use the SDK Manager's gnsdk_lookupdatabase_info_get() and INFO GDO keys.
*/
GNSDK_DEPRECATED gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_info_count(
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t	storage_info_key,
	gnsdk_uint32_t*	p_info_count
	);

/** 
 * Use the SDK Manager's gnsdk_lookupdatabase_info_get() and INFO GDO keys.
*/
GNSDK_DEPRECATED gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_info_get(
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t	storage_info_key,
	gnsdk_uint32_t	ordinal,
	gnsdk_cstr_t*	p_storage_info
	);


/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_CONTENT @endinternal
  * Name of the local storage the SDK uses to query Gracenote Content (gn_cds.gdb).
  * @hideinitializer
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_CONTENT			"CONTENT"

/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_METADATA @endinternal
  * Name of the local storage the SDK uses to query Gracenote Metadata (gn_mdata.gdb).
  * @hideinitializer
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_METADATA			"METADATA"

/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_TOCINDEX @endinternal
  * Name of the local storage the SDK uses for CD TOC searching (gn_itoc.gdb).
  * @hideinitializer
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_TOCINDEX			"TOCINDEX"

/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_TEXTINDEX @endinternal
  * Name of the local storage the SDK uses for text searching (gn_itxt.gdb).
  * @hideinitializer
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_TEXTINDEX		"TEXTINDEX"
	
/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_EPG @endinternal
  * Name of the local storage the SDK uses for local programming guide data (gn_epg.gdb).
  * @hideinitializer
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_EPG				"EPG"
	
/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_ALL @endinternal
  * For referencing all the above storages that make up the local storage.
  * @hideinitializer  
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_ALL				"gnsdk_lookup_local_gdball"


/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_GDB_VERSION @endinternal
  * Key the local storage the SDK uses for version searching.
  * @hideinitializer
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_GDB_VERSION		"gnsdk_lookup_local_gdb_version"

/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_IMAGE_SIZE @endinternal
  * Key the local storage the SDK uses for content image size searching.
  * @hideinitializer
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_IMAGE_SIZE		"gnsdk_lookup_local_image_size"

#ifdef __cplusplus
}
#endif

#endif /* _GNSDK_LOOKUP_LOCAL_H_ */

