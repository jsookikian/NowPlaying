/*
 * Copyright (c) 2000-2016 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/* gnsdk_config.cpp
 *
 * Implementation of C++ wrapper for GNSDK Config
 *
 */

#include "gnsdk_config.hpp"

using namespace gracenote;

/******************************************************************************
** GnConfig
*/

GnConfig::GnConfig() throw (GnError)
{
	gnsdk_error_t         error;
	gnsdk_config_handle_t config_handle = GNSDK_NULL;

	error = gnsdk_config_create(&config_handle);
	if (error) { throw GnError(); }

	assign(config_handle);
}


/*-----------------------------------------------------------------------------
 *  GnConfig
 */
GnConfig::GnConfig(gnsdk_cstr_t config) throw (GnError)
{
	gnsdk_error_t         error;
	gnsdk_config_handle_t config_handle = GNSDK_NULL;

	error = gnsdk_config_load(config, &config_handle);
	if (error) { throw GnError(); }

	assign(config_handle);
}


/*-----------------------------------------------------------------------------
 *  Set
 */
void
GnConfig::Set(gnsdk_cstr_t custom, gnsdk_cstr_t value) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_config_value_set(native(), custom, value);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  Set
 */
void
GnConfig::Set(GnConfigOptionAccess access) throw (GnError)
{
	gnsdk_cstr_t  value = GNSDK_NULL;
	gnsdk_error_t error;

	switch (access)
	{
	case kConfigOptionAccessLookupDatabaseReadOnly:
		value = GNSDK_LOOKUPDATABASE_ACCESS_READ_ONLY;
		break;

	case kConfigOptionAccessLookupDatabaseReadWrite:
		value = GNSDK_LOOKUPDATABASE_ACCESS_READ_WRITE;
		break;

	case kConfigOptionAccessInvalid:
		value = GNSDK_NULL;
		break;
	}

	error = gnsdk_config_value_set(native(), GNSDK_CONFIG_LOOKUPDATABASE_ACCESS, value);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  Set
 */
void
GnConfig::Set(GnConfigOptionEnable enable, bool value) throw (GnError)
{
	gnsdk_cstr_t  option_cstr = GNSDK_NULL;
	gnsdk_error_t error;

	switch (enable)
	{
	case kConfigOptionEnableLookupDatabaseMusicID:
		option_cstr = GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID;
		break;

	case kConfigOptionEnableLookupDatabaseMusicIDText:
		option_cstr = GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID_TEXT;
		break;

	case kConfigOptionEnableLookupDatabaseMusicIDCD:
		option_cstr = GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID_CD;
		break;

	case kConfigOptionEnableLookupDatabaseMusicIDImages:
		option_cstr = GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID_IMAGES;
		break;

	case kConfigOptionEnableLookupDatabaseEpgRadio:
		option_cstr = GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_EPG_RADIO;
		break;

	case kConfigOptionEnableLookupDatabaseEpgTV:
		option_cstr = GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_EPG_TV;
		break;

	case kConfigOptionEnableInvalid:
		option_cstr = GNSDK_NULL;
		break;
	}

	error = gnsdk_config_value_set(native(), option_cstr, (value ? GNSDK_VALUE_TRUE : GNSDK_VALUE_FALSE));
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  Set 
 */
void
GnConfig::Set(GnConfigOptionLocation location, gnsdk_cstr_t value) throw (GnError)
{
	gnsdk_cstr_t  option_cstr = GNSDK_NULL;
	gnsdk_error_t error;

	switch (location)
	{
	case kConfigOptionLocationLookupDatabaseAll:
		option_cstr = GNSDK_CONFIG_LOOKUPDATABASE_ALL_LOCATION;
		break;

	case kConfigOptionLocationLookupDatabaseContent:
		option_cstr = GNSDK_CONFIG_LOOKUPDATABASE_CONTENT_LOCATION;
		break;

	case kConfigOptionLocationLookupDatabaseMetadata:
		option_cstr = GNSDK_CONFIG_LOOKUPDATABASE_METADATA_LOCATION;
		break;

	case kConfigOptionLocationLookupDatabaseTocIndex:
		option_cstr = GNSDK_CONFIG_LOOKUPDATABASE_TOCINDEX_LOCATION;
		break;

	case kConfigOptionLocationLookupDatabaseTextIndex:
		option_cstr = GNSDK_CONFIG_LOOKUPDATABASE_TEXTINDEX_LOCATION;
		break;

	case kConfigOptionLocationLookupDatabaseEpg:
		option_cstr = GNSDK_CONFIG_LOOKUPDATABASE_EPG_LOCATION;
		break;

	case kConfigOptionLocationInvalid:
		option_cstr = GNSDK_NULL;
		break;
	}

	error = gnsdk_config_value_set(native(), option_cstr, value);
	if (error) { throw GnError(); }
}

