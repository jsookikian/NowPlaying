/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */

/* gnsdk_manager_config.h: APIs for creation of Config objects
 */

#ifndef _GNSDK_MANAGER_CONFIG_H_
#define _GNSDK_MANAGER_CONFIG_H_

#include "gnsdk_defines.h"
#include "gnsdk_manager.h"

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
 * Typedefs
 ******************************************************************************/
GNSDK_DECLARE_HANDLE(gnsdk_config_handle_t);

/******************************************************************************
 * SDK Manager Event Data Types
 ******************************************************************************/

 /** @internal gnsdk_config_format_t @endinternal
	*  Event data types.
        * @hideinitializer
	* @ingroup Config_Enums
*/
typedef enum
{
	/** @internal gnsdk_config_format_invalid @endinternal
	*  This format is used to initialize configuration format locals.
	*/
	gnsdk_config_format_invalid = 0,

	/** @internal gnsdk_config_format_json @endinternal
	*  This format is used to specify that the SDK should render the 
	*  configuration to JSON.
	*/
	gnsdk_config_format_json,

	/** @internal gnsdk_config_format_xml @endinternal
	*  This format is used to specify that the SDK should render the 
	*  configuration to XML.
	*/
	gnsdk_config_format_xml

} gnsdk_config_format_t;

/******************************************************************************
 * SDK Manager Config Group
 ******************************************************************************/

/*
 * Lookup Database Config Keys
 */
/** @internal GNSDK_CONFIG_LOOKUPDATABASE_ACCESS @endinternal
*  Allows for specifying whether the database should be open in read-only mode
*  or read-write mode (which allows for the persistent storing of results).
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_ACCESS 						"gnsdk_config_lookupdatabase_access"

/** @internal GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID @endinternal
*  Allows for specifying that the database will be used for MusicID GDO queries.
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID				"gnsdk_config_lookupdatabase_enable_musicid"

/** @internal GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID_TEXT @endinternal
*  Allows for specifying that the database will be used for MusicID and/or
*  MusicID-File text queries.
*  Performing text queries without enabling musicid_text will not result in an error,
*  but text queries will return no results.
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID_TEXT			"gnsdk_config_lookupdatabase_enable_musicid_text"   	

/** @internal GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID_CD @endinternal
*  Allows for specifying that the database will be used for MusicID CD TOC
*  Performing CD TOC queries without enabling musicid_cd will not result in an error,
*  but TOC queries will return no results.
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID_CD         	"gnsdk_config_lookupdatabase_enable_musicid_cd"

/** @internal GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID_IMAGES @endinternal
*  Allows for specifying that the database will be used to fetch MusicID
*  imagery (cover art, artist images, and so on).
*  Performing image queries without enabling musicid_images will not result in an error,
*  but image queries will return no results.
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID_IMAGES    	"gnsdk_config_lookupdatabase_enable_musicid_images"

/** @internal GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_EPG_RADIO @endinternal
*  Allows for specifying that the database will be used for Radio Station
*  queries and imagery.
*  Performing Radio Station queries without enabling epg_radio will not result in an
*  error, but Radio queries will return no results.
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_EPG_RADIO     		"gnsdk_config_lookupdatabase_enable_epg_radio"

/** @internal GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_EPG_TV @endinternal
*  Allows for specifying that the database will be used for TV Channel
*  queries and imagery.
*  Performing TV Channel queries without enabling epg_tv will not result in an
*  error, but TV queries will return no results.
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_EPG_TV          		"gnsdk_config_lookupdatabase_enable_epg_tv"   	

/** @internal GNSDK_CONFIG_LOOKUPDATABASE_ALL_LOCATION @endinternal
*  Allows for specifying the directory for storing all of the database file(s)
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_ALL_LOCATION				"gnsdk_config_lookupdatabase_all_location"

/** @internal GNSDK_CONFIG_LOOKUPDATABASE_CONTENT_LOCATION @endinternal
*  Allows for specifying the directory for storing the content database file(s)  
*  which contain images (cover art, artist images, and so on).
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_CONTENT_LOCATION			"gnsdk_config_lookupdatabase_content_location"

/** @internal GNSDK_CONFIG_LOOKUPDATABASE_METADATA_LOCATION @endinternal
*  Allows for specifying the directory for storing the metadata database file(s)
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_METADATA_LOCATION			"gnsdk_config_lookupdatabase_metadata_location"

/** @internal GNSDK_CONFIG_LOOKUPDATABASE_TOCINDEX_LOCATION @endinternal
*  Allows for specifying the directory for storing the CD TOC index database file(s)
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_TOCINDEX_LOCATION			"gnsdk_config_lookupdatabase_tocindex_location"

/** @internal GNSDK_CONFIG_LOOKUPDATABASE_TEXTINDEX_LOCATION @endinternal
*  Allows for specifying the directory for storing the text index database file(s)
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_TEXTINDEX_LOCATION			"gnsdk_config_lookupdatabase_textindex_location"

/** @internal GNSDK_CONFIG_LOOKUPDATABASE_EPG_LOCATION @endinternal
*  Allows for specifying the directory for storing the electronic program guide 
*  database file(s) which contain metadata, indexes, and content related to
*  radio stations and TV channels.
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_CONFIG_LOOKUPDATABASE_EPG_LOCATION				"gnsdk_config_lookupdatabase_epg_location"

/*
 * Lookup Database Config Values
 */
/** @internal GNSDK_LOOKUPDATABASE_ACCESS_READ_ONLY @endinternal
*  Specifies that the database should be opened in read-only mode.
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_LOOKUPDATABASE_ACCESS_READ_ONLY					"r"
/** @internal GNSDK_LOOKUPDATABASE_ACCESS_READ_WRITE @endinternal
*  Specifies that the database should be opened in read-write mode,
*  allowing for records and images to be persistently stored in this
*  result database.
* @hideinitializer
* @ingroup Config_Groups
*/
#define GNSDK_LOOKUPDATABASE_ACCESS_READ_WRITE					"rw" 


/** @internal gnsdk_config_create @endinternal
* Creates an empty configuration handle.
*  @param p_config_handle [out] pointer to the created handle
* @hideinitializer
* @ingroup Config_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 
gnsdk_config_create(
	gnsdk_config_handle_t*		p_config_handle
	); 

/** @internal gnsdk_config_release @endinternal
* Releases the configuration handle.
*  @param config_handle [in] the handle to release.
* @hideinitializer
* @ingroup Config_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 
gnsdk_config_release(
	gnsdk_config_handle_t		config_handle
	); 

/** @internal gnsdk_config_value_set @endinternal
* Sets the value specified by the key into the configuration object.
*  @param config_handle [in] the configuration handle to act on.
*  @param key [in] one of the supported configuration keys.
*  @param value [in] the value to set for the specified key.
* @hideinitializer
* @ingroup Config_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 
gnsdk_config_value_set(
	gnsdk_config_handle_t		config_handle,
	gnsdk_cstr_t				key,
	gnsdk_cstr_t				value
	); 

/** @internal gnsdk_config_value_get @endinternal
* Gets the value specified by the key from the configuration object.
*  @param config_handle [in] the configuration handle to act on.
*  @param key [in] one of the supported configuration keys.
*  @param p_value [out] pointer to hold the returned value.
* @hideinitializer
* @ingroup Config_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API 
gnsdk_config_value_get(
	gnsdk_config_handle_t		config_handle,
	gnsdk_cstr_t				key,
	gnsdk_cstr_t*				p_value
	); 

/** @internal gnsdk_config_load @endinternal
* Allows for creating a configuration object populated with the values from the 
* rendered configuration string.
*  @param rendered_string [in] the rendered configuration string.
*  @param p_config [out] pointer to hold the returned configuration handle.
* @hideinitializer
* @ingroup Config_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_config_load(
	gnsdk_cstr_t				rendered_string,
	gnsdk_config_handle_t*		p_config_handle
	); 

/** @internal gnsdk_config_render @endinternal
* Allows for rendering the configuration object to a string with the specified
* format.
*  @param config_handle [in] the configuration object to render.
*  @param format [in] the desired rendered format.
*  @param p_rendered_string [out] pointer to hold the returned string.
* @hideinitializer
* @ingroup Config_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_config_render(
	gnsdk_config_handle_t		config_handle,
	gnsdk_config_format_t		format,
	gnsdk_cstr_t*				p_rendered_string
	); 
 

#ifdef __cplusplus
}
#endif

#endif /* _GNSDK_MANAGER_CONFIG_H_ */
