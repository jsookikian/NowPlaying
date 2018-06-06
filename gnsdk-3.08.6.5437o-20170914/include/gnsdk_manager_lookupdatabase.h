/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */

/* gnsdk_manager_lookupdatabase.h: Primary interface for enabling local lookup databases.
 */

#ifndef _GNSDK_LOOKUPDATABASE_H_
#define _GNSDK_LOOKUPDATABASE_H_

 
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * Lookup Database management APIs
 ******************************************************************************/

/** @internal gnsdk_lookupdatabase_open @endinternal
  * Open Local Database set - database set is set of related gracenote databases. This call will create new or open
    existnig database set based on configuration given.
  * @param db_identifier [in] Local Database Set identifier 
  * @param config_handle [in]
** @hideinitializer
  * @ingroup Setup_LookupLocalStorage_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 
gnsdk_lookupdatabase_open(
	gnsdk_cstr_t db_identifier,
	gnsdk_config_handle_t h_config
); 

/** @internal gnsdk_lookupdatabase_close @endinternal
  * Close the specified lookup database - will wait if any threads have outstanding queries with this database.  
  * Once a lookup database is closed, any outstanding result GDOs from this database will be invalid.
  * If this API is not called, all open databases will be closed on gnsdk_manager_shutdown()
  * @param db_identifier [in] database identifer 
** @hideinitializer
  * @ingroup Setup_LookupLocalStorage_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 
gnsdk_lookupdatabase_close(
	gnsdk_cstr_t db_identifier
); 

/** @internal gnsdk_lookupdatabase_record_add @endinternal
  * Add record to database. The SDK will attempt to ensure the newest version 
  * of the record is in the database - overwriting as necessary.
  * @param db_identifier [in] database identifer 
  * @param gdo			 [in] gracenote data object to add
** @hideinitializer
  * @ingroup Setup_LookupLocalStorage_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 
gnsdk_lookupdatabase_record_add(
	gnsdk_cstr_t dbidentifier, 
	gnsdk_gdo_handle_t gdo
);

 /** @internal gnsdk_lookupdatabase_image_add @endinternal
  * Add image to database. The SDK will overwrite if this image is already in the DB.
  * @param db_identifier [in] database identifer 
  * @param buffer		 [in] image buffer
  * @param buffer_size	 [in] image buffer size in bytes
  * @param asset_gdo	 [in] asset gracenote data Object to add
** @hideinitializer
  * @ingroup Setup_LookupLocalStorage_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 
gnsdk_lookupdatabase_image_add(
	gnsdk_cstr_t		db_identifier, 
	gnsdk_byte_t*		buffer, 
	gnsdk_size_t		buffer_size, 
	gnsdk_gdo_handle_t  asset_gdo
);

 /** @internal gnsdk_lookupdatabase_size_get @endinternal
  * Get databse size.
  * @param db_identifier [in] database identifer 
  * @param p_size		 [out] database size in bytes
** @hideinitializer
  * @ingroup Setup_LookupLocalStorage_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 
gnsdk_lookupdatabase_size_get(
	gnsdk_cstr_t  db_identifier, 
	gnsdk_uint64_t* p_size
); 


 /** @internal gnsdk_lookupdatabase_delete @endinternal
  * Deletes the local database files. 
  * Note that only lookup related GDB files are deleted.
  * @param config_handle [in] database configuration. 
** @hideinitializer
  * @ingroup Setup_LookupLocalStorage_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 
gnsdk_lookupdatabase_delete(
	gnsdk_config_handle_t config_handle
);


 /** @internal gnsdk_lookupdatabase_validate @endinternal
  * Validate database
  * @param db_identifier [in] database identifer 
** @hideinitializer
  * @ingroup Setup_LookupLocalStorage_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 
gnsdk_lookupdatabase_validate(
	gnsdk_cstr_t db_identifier
);

/** @internal gnsdk_lookupdatabase_info_get @endinternal
  * Validate database
  * @param db_identifier [in] database identifer 
  * @param p_info_gdo [out] GDO containing database information ( version, location, etc)
** @hideinitializer
  * @ingroup Setup_LookupLocalStorage_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 
gnsdk_lookupdatabase_info_get(
	gnsdk_cstr_t			db_identifier, 
	gnsdk_gdo_handle_t*		p_info_gdo
);
	
#ifdef __cplusplus
}
#endif

#endif /** @internal _GNSDK_LOOKUPDATABASE_H_ @endinternal
		*  Primary interface for the local lookup databases.
		*/

