/*
 * Copyright (c) 2000-2016 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/* gnsdk_lookupdatabase.cpp
 *
 * Implementation of C++ wrapper for GNSDK
 *
 */
#include "gnsdk_manager.hpp"

#include "gnsdk_lookupdatabase.hpp"
#include "metadata_music.hpp"


using namespace gracenote;
using namespace gracenote::metadata;
using namespace gracenote::lookupdatabase;


GnLookupDatabase::GnLookupDatabase(gnsdk_cstr_t db_identifier, const GnConfig& config) throw (GnError)
{
	gnsdk_error_t error;

	identifier = db_identifier;

	error = gnsdk_lookupdatabase_open(identifier, config.native());
	if (error) { throw GnError(); }
}


GnLookupDatabase::~GnLookupDatabase()
{
}


void
GnLookupDatabase::AddRecord(const metadata::GnAlbum& album) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_lookupdatabase_record_add(identifier, album.native());
	if (error) { throw GnError(); }	
}


void
GnLookupDatabase::AddRecord(const metadata::GnContributor& contributor) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_lookupdatabase_record_add(identifier, contributor.native());
	if (error) { throw GnError(); }	
}

void
GnLookupDatabase::AddImage(gnsdk_byte_t* image_buffer, gnsdk_size_t image_buffer_size, const metadata::GnAsset& asset)
{
	gnsdk_error_t error;

	error = gnsdk_lookupdatabase_image_add(identifier, image_buffer, image_buffer_size, asset.native());
	if (error) { throw GnError(); }	

}

gnsdk_uint64_t
GnLookupDatabase::Size() throw (GnError)
{
	gnsdk_error_t error;
	gnsdk_uint64_t lookup_db_size;

	error = gnsdk_lookupdatabase_size_get(identifier, &lookup_db_size);
	if (error) { throw GnError(); }	
				
	return lookup_db_size;
}

GnLookupDatabaseInfo
GnLookupDatabase::Info() throw (GnError)
{
	gnsdk_error_t error;
	gnsdk_gdo_handle_t info_gdo;

	error = gnsdk_lookupdatabase_info_get(identifier, &info_gdo);
	if (error) { throw GnError(); }	

	return GnLookupDatabaseInfo(info_gdo);
}

void
GnLookupDatabase::Close() throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_lookupdatabase_close(identifier);
	if (error) { throw GnError(); }	
}


