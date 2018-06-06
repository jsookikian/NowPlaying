/*
 * Copyright (c) 2000-2016 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/* gnsdk_playlist.cpp
 *
 * Implementation of C++ wrapper for GNSDK
 *
 */
#include "gnsdk_manager.hpp"

#if GNSDK_PLAYLIST

#include "gnsdk_playlist.hpp"
#include "gnsdk_list.hpp"

using namespace gracenote;
using namespace gracenote::playlist;

static void _add(gnsdk_playlist_collection_handle_t handle, gnsdk_cstr_t mediaIdentifier, gnsdk_gdo_handle_t gdo) throw (GnError);


/******************************************************************************
 *  GnPlaylist
 */
GnPlaylist::GnPlaylist() throw (GnError)
{
	_gnsdk_internal::module_initialize(GNSDK_MODULE_PLAYLIST);
}


/*-----------------------------------------------------------------------------
 *  Version
 */
gnsdk_cstr_t
GnPlaylist::Version()
{
	return gnsdk_playlist_get_version();
}


/*-----------------------------------------------------------------------------
 *  BuildDate
 */
gnsdk_cstr_t
GnPlaylist::BuildDate()
{
	return gnsdk_playlist_get_build_date();
}


/* ***************************************************************************************************************************** */
/* GnPlaylistResults result_provider */
/* ***************************************************************************************************************************** */

GnPlaylistIdentifier
result_provider::get_data(gnsdk_uint32_t pos) const
{
	gnsdk_cstr_t  media_ident = GNSDK_NULL;
	gnsdk_cstr_t  coll_name   = GNSDK_NULL;
	gnsdk_error_t error;

	if ( pos < GN_UINT32_MAX )
	{
		error = gnsdk_playlist_results_enum(weak_handle_, pos, &media_ident, &coll_name);
		if (GNSDKERR_IndexOutOfRange == GNSDKERR_ERROR_CODE(error)) error = GNSDK_SUCCESS; // out of range just allow "end" returned
		if (GNSDKERR_SEVERE(error)) {throw GnError();}
	}
 
	return GnPlaylistIdentifier(media_ident, coll_name);
}


/*-----------------------------------------------------------------------------
 *  count
 */
gnsdk_uint32_t
result_provider::count() const
{
	gnsdk_uint32_t count = 0;
	gnsdk_error_t  error = PLERR_NoError;

	error = gnsdk_playlist_results_count(weak_handle_, &count);
	if (GNSDKERR_SEVERE(error)) { throw GnError(); }

	return count;
}


/* ***************************************************************************************************************************** */
/* GnPlaylistCollection  collection_ident_provider */
/* ***************************************************************************************************************************** */

GnPlaylistIdentifier
collection_ident_provider::get_data(gnsdk_uint32_t pos) const
{
	gnsdk_cstr_t  media_ident = GNSDK_NULL;
	gnsdk_cstr_t  coll_name   = GNSDK_NULL;
	gnsdk_error_t error;

	if ( pos < GN_UINT32_MAX )
	{
		error = gnsdk_playlist_collection_ident_enum(weak_handle_, pos, &media_ident, &coll_name);
		if (GNSDKERR_IndexOutOfRange == GNSDKERR_ERROR_CODE(error)) error = GNSDK_SUCCESS; // out of range just allow "end" returned
		if (GNSDKERR_SEVERE(error)) { throw GnError(); }
	}

	return GnPlaylistIdentifier(media_ident, coll_name);
}


/*-----------------------------------------------------------------------------
 *  count
 */
gnsdk_uint32_t
collection_ident_provider::count() const
{
	gnsdk_uint32_t count = 0;
	gnsdk_error_t  error = PLERR_NoError;

	error = gnsdk_playlist_collection_ident_count(weak_handle_, &count);
	if (GNSDKERR_SEVERE(error)) { throw GnError(); }

	return count;

}


/* ***************************************************************************************************************************** */
/* GnPlaylistCollection  collection_join_provider */
/* ***************************************************************************************************************************** */

GnPlaylistCollection
collection_join_provider::get_data(gnsdk_uint32_t pos) const
{
	gnsdk_playlist_collection_handle_t coll  = GNSDK_NULL;
	gnsdk_error_t                      error = PLERR_NoError;

	if ( pos < GN_UINT32_MAX )
	{
		error = gnsdk_playlist_collection_join_enum(weak_handle_, pos, &coll);
		if (GNSDKERR_IndexOutOfRange == GNSDKERR_ERROR_CODE(error)) error = GNSDK_SUCCESS; // out of range just allow "end" returned
		if (GNSDKERR_SEVERE(error)) { throw GnError(); }
	}

	return GnPlaylistCollection(coll);
}


/*-----------------------------------------------------------------------------
 *  count
 */
gnsdk_uint32_t
collection_join_provider::count() const
{
	gnsdk_uint32_t count = 0;
	gnsdk_error_t  error = PLERR_NoError;

	error = gnsdk_playlist_collection_join_count(weak_handle_, &count);
	if (GNSDKERR_SEVERE(error)) { throw GnError(); }

	return count;

}


/* ***************************************************************************************************************************** */
/* GnPlaylistCollection */
/* ***************************************************************************************************************************** */

GnPlaylistCollection::GnPlaylistCollection(gnsdk_playlist_collection_handle_t handle) : GnObject<gnsdk_playlist_collection_handle_t>(handle)
{
	_gnsdk_internal::module_initialize(GNSDK_MODULE_PLAYLIST);
	options_.weakhandle_ = handle;
}


GnPlaylistCollection::GnPlaylistCollection(gnsdk_byte_t* buffer, gnsdk_size_t size)
{
	gnsdk_playlist_collection_handle_t h_collection;
	gnsdk_error_t                      error;

	_gnsdk_internal::module_initialize(GNSDK_MODULE_PLAYLIST);

	error = gnsdk_playlist_collection_deserialize(buffer, size, &h_collection);
	if (error) { throw GnError(); }

	assign(h_collection);
	options_.weakhandle_ = h_collection;
}


GnPlaylistCollection::GnPlaylistCollection(gnsdk_cstr_t collectionName)
{
	gnsdk_playlist_collection_handle_t h_collection;
	gnsdk_error_t                      error;

	_gnsdk_internal::module_initialize(GNSDK_MODULE_PLAYLIST);

	error = gnsdk_playlist_collection_create(collectionName, &h_collection);
	if (error) { throw GnError(); }

	assign(h_collection);
	options_.weakhandle_ = h_collection;
}


GnPlaylistCollection::GnPlaylistCollection(const GnPlaylistCollection& other) : GnObject<gnsdk_playlist_collection_handle_t>(other)
{
	options_.weakhandle_ = native();
}


/*-----------------------------------------------------------------------------
 *  operator =
 */
GnPlaylistCollection&
GnPlaylistCollection::operator =(const GnPlaylistCollection& other)
{
	if ( this != &other)
	{
		GnObject<gnsdk_playlist_collection_handle_t>::operator=(other);
		options_.weakhandle_ = native();
	}
	return *this;
}


/*-----------------------------------------------------------------------------
 *  Name
 */
gnsdk_cstr_t
GnPlaylistCollection::Name() const throw (GnError)
{
	gnsdk_cstr_t  name = GNSDK_NULL;
	gnsdk_error_t error;

	error = gnsdk_playlist_collection_get_name(native(), &name);
	if (error) { throw GnError(); }

	return name;
}


/*-----------------------------------------------------------------------------
 *  Name
 */
void
GnPlaylistCollection::Name(gnsdk_cstr_t updatedName) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_collection_update_name(native(), updatedName);
	if (error) { throw GnError(); }
}


/* Add an Ident to the collection. */
void
GnPlaylistCollection::Add(gnsdk_cstr_t mediaIdentifier) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_collection_add_ident(native(), mediaIdentifier);
	if (error) { throw GnError(); }
}


/* Add a GnAlbum to the collection. */
void
GnPlaylistCollection::Add(gnsdk_cstr_t mediaIdentifier, const metadata::GnAlbum& album) throw (GnError)
{
	_add(native(), mediaIdentifier, album.native() );
}


/* Add a GnTrack to the collection. */
void
GnPlaylistCollection::Add(gnsdk_cstr_t mediaIdentifier, const metadata::GnTrack& track) throw (GnError)
{
	_add(native(), mediaIdentifier, track.native() );
}


/* Add a GnContributor to the Collection. */
void
GnPlaylistCollection::Add(gnsdk_cstr_t mediaIdentifier, const metadata::GnContributor& contributor) throw (GnError)
{
	_add(native(), mediaIdentifier, contributor.native() );
}


/* Add a GnPlaylistAttributes to the Collection. */
void
GnPlaylistCollection::Add(gnsdk_cstr_t mediaIdentifier, const GnPlaylistAttributes& playlistMetadata) throw (GnError)
{
	_add(native(), mediaIdentifier, playlistMetadata.native() );
}


/*-----------------------------------------------------------------------------
 *  Add
 */
void
GnPlaylistCollection::Add(gnsdk_cstr_t mediaIdentifier, const GnListElement& listElement) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_collection_add_list_element(native(), mediaIdentifier, listElement.native());
	if (error) { throw GnError(); }
}


/* Remove and media identifier from the collection. */
void
GnPlaylistCollection::Remove(gnsdk_cstr_t mediaIdentifier) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_collection_ident_remove(native(), mediaIdentifier);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  Contains
 */
bool
GnPlaylistCollection::Contains(gnsdk_cstr_t mediaIdentifier) const throw (GnError)
{
	gnsdk_cstr_t   coll_name = GNSDK_NULL;
	gnsdk_uint32_t found     = 0;
	gnsdk_error_t  error;

	error = gnsdk_playlist_collection_ident_find(native(), mediaIdentifier, 0, &found, &coll_name);
	if (error && ( PLERR_NotFound != error) ) { throw GnError(); }

	return (found != 0);
}


/*-----------------------------------------------------------------------------
 *  Find
 */
ident_iterator
GnPlaylistCollection::Find(gnsdk_cstr_t mediaIdentifier, gnsdk_uint32_t start) const throw (GnError)
{
	gnsdk_cstr_t   coll_name = GNSDK_NULL;
	gnsdk_uint32_t found     = 0;
	gnsdk_error_t  error;

	error = gnsdk_playlist_collection_ident_find(native(), mediaIdentifier, start, &found, &coll_name);
	collection_ident_provider provider(native() );
	if (GNSDKERR_SEVERE(error))
	{
		throw GnError();
	}
	else if (error)
	{
		return ident_iterator(collection_ident_provider(native()), GN_UINT32_MAX);
	}

	return ident_iterator(provider, found);
}


/*-----------------------------------------------------------------------------
 *  Attributes
 */
GnPlaylistAttributes
GnPlaylistCollection::Attributes(const GnUser& user, const GnPlaylistIdentifier& mediaIdentifier) const throw (GnError)
{
	gnsdk_error_t                      error  = PLERR_NoError;
	gnsdk_playlist_collection_handle_t h_coll = GNSDK_NULL;
	gnsdk_gdo_handle_t                 h_gdo  = GNSDK_NULL;

	error = gnsdk_playlist_collection_join_get(native(), mediaIdentifier.CollectionName(), &h_coll);
	if (error) { throw GnError(); }

	error = gnsdk_playlist_collection_get_gdo(h_coll, user.native(), mediaIdentifier.MediaIdentifier(), &h_gdo);
	gnsdk_playlist_collection_release(h_coll);

	return GnPlaylistAttributes(h_gdo);
}


/*-----------------------------------------------------------------------------
 *  Attributes
 */
GnPlaylistAttributes
GnPlaylistCollection::Attributes(const GnUser& user, gnsdk_cstr_t mediaIdentifier, gnsdk_cstr_t joinedCollectionName) const throw (GnError)
{
	gnsdk_playlist_collection_handle_t h_coll = GNSDK_NULL;
	gnsdk_gdo_handle_t                 h_gdo  = GNSDK_NULL;
	gnsdk_error_t                      error;

	if (joinedCollectionName)
	{
		error = gnsdk_playlist_collection_join_get(native(), joinedCollectionName, &h_coll);
		if (error) { throw GnError(); }

		error = gnsdk_playlist_collection_get_gdo(h_coll, user.native(), mediaIdentifier, &h_gdo);
		gnsdk_playlist_collection_release(h_coll);
	}
	else
	{
		error = gnsdk_playlist_collection_get_gdo(native(), user.native(), mediaIdentifier, &h_gdo);
	}

	return GnPlaylistAttributes(h_gdo);
}


/*-----------------------------------------------------------------------------
 *  StatementValidate
 */
GnError
GnPlaylistCollection::StatementValidate(gnsdk_cstr_t pdlStatement)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_statement_validate(pdlStatement, native(), GNSDK_NULL);
	return GnError();
}


/*-----------------------------------------------------------------------------
 *  StatementAnalyzeIdent
 */
GnString
GnPlaylistCollection::StatementAnalyzeIdent(gnsdk_cstr_t pdlStatement, gnsdk_cstr_t mediaIdentifier) const throw (GnError)
{
	gnsdk_str_t   pdl_outcome = GNSDK_NULL;
	gnsdk_error_t error;

	error = gnsdk_playlist_statement_analyze_ident(pdlStatement, native(), mediaIdentifier, &pdl_outcome);
	if (error) { throw GnError(); }

	return GnString::manage(pdl_outcome);
}


/*-----------------------------------------------------------------------------
 *  StatementRequiresSeed
 */
bool
GnPlaylistCollection::StatementRequiresSeed(gnsdk_cstr_t pdlStatement) const throw (GnError)
{
	gnsdk_bool_t  b_seed_needed = GNSDK_FALSE;
	gnsdk_error_t error;

	error = gnsdk_playlist_statement_validate(pdlStatement, native(), &b_seed_needed);
	if (error) { throw GnError(); }

	if (b_seed_needed)
		return true;

	return false;
}


/*-----------------------------------------------------------------------------
 *  GeneratePlaylist
 */
GnPlaylistResults
GnPlaylistCollection::GeneratePlaylist(const GnUser& user, gnsdk_cstr_t pdlStatement, const metadata::GnDataObject& playlistSeed) throw (GnError)
{
	gnsdk_playlist_results_handle_t h_results = GNSDK_NULL;
	gnsdk_error_t                   error;

	error = gnsdk_playlist_generate_playlist(user.native(), pdlStatement, native(), playlistSeed.native(), &h_results);
	if (error) { throw GnError(); }

	return GnPlaylistResults(h_results);
}


/*-----------------------------------------------------------------------------
 *  GeneratePlaylist
 */
GnPlaylistResults
GnPlaylistCollection::GeneratePlaylist(const GnUser& user, gnsdk_cstr_t pdlStatement) throw (GnError)
{
	gnsdk_playlist_results_handle_t h_results = GNSDK_NULL;
	gnsdk_error_t                   error;

	error = gnsdk_playlist_generate_playlist(user.native(), pdlStatement, native(), GNSDK_NULL, &h_results);
	if (error) { throw GnError(); }

	return GnPlaylistResults(h_results);
}


/*-----------------------------------------------------------------------------
 *  GenerateMoreLikeThis
 */
GnPlaylistResults
GnPlaylistCollection::GenerateMoreLikeThis(const GnUser& user, const metadata::GnDataObject& playlistSeed) throw (GnError)
{
	gnsdk_playlist_results_handle_t h_results = GNSDK_NULL;
	gnsdk_error_t                   error;

	error = gnsdk_playlist_generate_morelikethis(user.native(), native(), playlistSeed.native(), &h_results);
	if (error) { throw GnError(); }

	return GnPlaylistResults(h_results);
}


/*-----------------------------------------------------------------------------
 *  JoinSearchByName
 */
GnPlaylistCollection
GnPlaylistCollection::JoinFindByName(gnsdk_cstr_t collectionName) const throw (GnError)
{
	gnsdk_playlist_collection_handle_t coll = GNSDK_NULL;
	gnsdk_error_t                      error;

	error = gnsdk_playlist_collection_join_get_by_name(native(), collectionName, &coll);
	if (error) { throw GnError(); }

	return GnPlaylistCollection(coll);
}


/*-----------------------------------------------------------------------------
 *  Join
 */
void
GnPlaylistCollection::Join(const GnPlaylistCollection& toJoin) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_collection_join(native(), toJoin.native() );
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  JoinRemove
 */
void
GnPlaylistCollection::JoinRemove(const GnPlaylistCollection& toRemove) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_collection_join_remove(native(), toRemove.Name() );
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  GnPlaylistMoreLikeThisOptions
 */

static gnsdk_uint32_t
_get_mltoption(gnsdk_playlist_collection_handle_t handle, gnsdk_cstr_t key)
{
	gnsdk_cstr_t  value = GNSDK_NULL;
	gnsdk_error_t error;

	error = gnsdk_playlist_morelikethis_option_get(handle, key, &value);
	if (error) { throw GnError(); }

	return gnstd::gn_atoi(value);
}


/*-----------------------------------------------------------------------------
 *  _set_mltoption
 */
static void
_set_mltoption(gnsdk_playlist_collection_handle_t handle, gnsdk_cstr_t key, gnsdk_uint32_t value)
{
	char          buffer[16];
	gnsdk_error_t error;

	gracenote::gnstd::gn_itoa(buffer, 16, value);

	error = gnsdk_playlist_morelikethis_option_set(handle, key, buffer);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  MaxTracks
 */
gnsdk_uint32_t
GnPlaylistMoreLikeThisOptions::MaxTracks() const throw (GnError)
{
	return _get_mltoption(weakhandle_, GNSDK_PLAYLIST_MORELIKETHIS_OPTION_MAX_TRACKS);
}


/*-----------------------------------------------------------------------------
 *  MaxTracks
 */
void
GnPlaylistMoreLikeThisOptions::MaxTracks(gnsdk_uint32_t value) throw (GnError)
{
	return _set_mltoption(weakhandle_, GNSDK_PLAYLIST_MORELIKETHIS_OPTION_MAX_TRACKS, value);
}


/*-----------------------------------------------------------------------------
 *  MaxPerArtist
 */
gnsdk_uint32_t
GnPlaylistMoreLikeThisOptions::MaxPerArtist() const throw (GnError)
{
	return _get_mltoption(weakhandle_, GNSDK_PLAYLIST_MORELIKETHIS_OPTION_MAX_PER_ARTIST);
}


/*-----------------------------------------------------------------------------
 *  MaxPerArtist
 */
void
GnPlaylistMoreLikeThisOptions::MaxPerArtist(gnsdk_uint32_t value) throw (GnError)
{
	return _set_mltoption(weakhandle_, GNSDK_PLAYLIST_MORELIKETHIS_OPTION_MAX_PER_ARTIST, value);
}


/*-----------------------------------------------------------------------------
 *  MaxPerAlbum
 */
gnsdk_uint32_t
GnPlaylistMoreLikeThisOptions::MaxPerAlbum() const throw (GnError)
{
	return _get_mltoption(weakhandle_, GNSDK_PLAYLIST_MORELIKETHIS_OPTION_MAX_PER_ALBUM);
}


/*-----------------------------------------------------------------------------
 *  MaxPerAlbum
 */
void
GnPlaylistMoreLikeThisOptions::MaxPerAlbum(gnsdk_uint32_t value) throw (GnError)
{
	return _set_mltoption(weakhandle_, GNSDK_PLAYLIST_MORELIKETHIS_OPTION_MAX_PER_ALBUM, value);
}


/*-----------------------------------------------------------------------------
 *  RandomSeed
 */
gnsdk_uint32_t
GnPlaylistMoreLikeThisOptions::RandomSeed() const throw (GnError)
{
	return _get_mltoption(weakhandle_, GNSDK_PLAYLIST_MORELIKETHIS_OPTION_RANDOMSEED);
}


/*-----------------------------------------------------------------------------
 *  RandomSeed
 */
void
GnPlaylistMoreLikeThisOptions::RandomSeed(gnsdk_uint32_t value) throw (GnError)
{
	return _set_mltoption(weakhandle_, GNSDK_PLAYLIST_MORELIKETHIS_OPTION_RANDOMSEED, value);
}


/*-----------------------------------------------------------------------------
 *  Serialize
 */
gnsdk_size_t
GnPlaylistCollection::Serialize(gnsdk_byte_t* buffer, gnsdk_size_t buffer_sz) const throw (GnError)
{
	gnsdk_size_t  sz = buffer_sz;
	gnsdk_error_t error;

	error = gnsdk_playlist_collection_serialize(native(), buffer, &sz);
	if (error) { throw GnError(); }

	return sz;
}


/*-----------------------------------------------------------------------------
 *  CollectionSerializeSize
 */
gnsdk_size_t
GnPlaylistCollection::SerializeSize() const throw (GnError)
{
	gnsdk_size_t  sz = 0;
	gnsdk_error_t error;

	error = gnsdk_playlist_collection_serialize_size(native(), &sz);
	if (error) { throw GnError(); }

	return sz;
}


/*-----------------------------------------------------------------------------
 *  PeformSyncProcess
 */
void
GnPlaylistCollection::SyncProcessExecute(IGnPlaylistCollectionSyncEvents& syncEvents) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_collection_sync_process(native(), IGnPlaylistCollectionSyncEvents::_collection_sync, &syncEvents);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  AddForSyncProcess
 */
void
GnPlaylistCollection::SyncProcessAdd(gnsdk_cstr_t mediaIdentifier) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_collection_sync_ident_add(native(), mediaIdentifier);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  _add
 */
void
_add(gnsdk_playlist_collection_handle_t handle, gnsdk_cstr_t mediaIdentifier, gnsdk_gdo_handle_t gdo) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_collection_add_gdo(handle, mediaIdentifier, gdo);
	if (error) { throw GnError(); }
}


/* ***************************************************************************************************************************** */
/* GnPlaylist Collection Storage Provider */
/* ***************************************************************************************************************************** */

collection_storage_provider::collection_storage_provider()
{ }


/*-----------------------------------------------------------------------------
 *  get_data
 */
gnsdk_cstr_t
collection_storage_provider::get_data(gnsdk_uint32_t pos)
{
	gnsdk_cstr_t  collection_name = gnstd::kEmptyString;
	gnsdk_error_t error;

	if (pos < GN_UINT32_MAX)
	{
		error = gnsdk_playlist_storage_enum_collections(pos, &collection_name);
		if (GNSDKERR_IndexOutOfRange == GNSDKERR_ERROR_CODE(error)) error = GNSDKERR_MAKE_WARNING(GNSDKPKG_Playlist, GNSDKERR_IndexOutOfRange); // out of range just allow "end" returned
		if (GNSDKERR_SEVERE(error)) { throw GnError(); }
	}

	return collection_name;
}


/*-----------------------------------------------------------------------------
 *  count
 */
gnsdk_uint32_t
collection_storage_provider::count() const
{
	gnsdk_uint32_t count = 0;
	gnsdk_error_t  error;

	error = gnsdk_playlist_storage_count_collections(&count);
	if (GNSDKERR_SEVERE(error)) { throw GnError(); }
	return count;
}


/* ***************************************************************************************************************************** */
/* GnPlaylist Attribute Provider */
/* ***************************************************************************************************************************** */
gnsdk_cstr_t
attribute_provider::get_data(gnsdk_uint32_t pos) const
{
	gnsdk_cstr_t  attr_name = gnstd::kEmptyString;
	gnsdk_error_t error;

	if ( pos == GN_UINT32_MAX )
		return gnstd::kEmptyString;

	if (weak_handle_)
		error = gnsdk_playlist_collection_attributes_enum(weak_handle_, pos, &attr_name);
	else
		error = gnsdk_playlist_attributes_enum(pos, &attr_name);
	if (GNSDKERR_IndexOutOfRange == GNSDKERR_ERROR_CODE(error)) error = GNSDK_SUCCESS; // out of range just allow "end" returned
	if (GNSDKERR_SEVERE(error)) { throw GnError(); }

	return attr_name;
}


/*-----------------------------------------------------------------------------
 *  count
 */
gnsdk_uint32_t
attribute_provider::count() const
{
	gnsdk_uint32_t count = 0;
	gnsdk_error_t  error;

	if (weak_handle_)
		error = gnsdk_playlist_collection_attributes_count(weak_handle_, &count);
	else
		error = gnsdk_playlist_attributes_count(&count);
	if (GNSDKERR_SEVERE(error)) { throw GnError(); }

	return count;
}


/* ***************************************************************************************************************************** */
/* IGnPlaylistCollectionSyncEvents */
/* ***************************************************************************************************************************** */

void
IGnPlaylistCollectionSyncEvents::_collection_sync(gnsdk_void_t*                      callback_data,
												  gnsdk_playlist_collection_handle_t handle,
												  gnsdk_cstr_t                       ident,
												  gnsdk_playlist_status_t            status,
												  gnsdk_bool_t*                      p_cancel
												  )
{
	IGnPlaylistCollectionSyncEvents* events = reinterpret_cast<IGnPlaylistCollectionSyncEvents*>( callback_data );
	GnPlaylistCollection             coll(handle);
	GnPlaylistEventsIdentiferStatus  cppStatus = kIdentifierStatusUnknown;
	gn_canceller                     canceller;

	switch ( status )
	{
	case gnsdk_playlist_status_unknown:
		cppStatus = kIdentifierStatusUnknown;
		break;

	case gnsdk_playlist_status_new_ident:
		cppStatus = kIdentifierStatusNew;
		break;

	case gnsdk_playlist_status_old_ident:
		cppStatus = kIdentifierStatusOld;
		break;
	}

	events->OnUpdate(coll, GnPlaylistIdentifier(ident, coll.Name() ), cppStatus, canceller);

	if (canceller.IsCancelled())
	{
		*p_cancel = GNSDK_TRUE;
	}
}


/* ***************************************************************************************************************************** */
/* GnPlaylistStorage */
/* ***************************************************************************************************************************** */


/*-----------------------------------------------------------------------------
 *  CollectionStore
 */
GnPlaylistStorage::GnPlaylistStorage ()
{
	_gnsdk_internal::module_initialize(GNSDK_MODULE_PLAYLIST);
}


/*-----------------------------------------------------------------------------
 *  Store
 */
void
GnPlaylistStorage::Store(const GnPlaylistCollection& collection) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_storage_store_collection(collection.native() );
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  CollectionLoad
 */
GnPlaylistCollection
GnPlaylistStorage::Load(storage_iterator itr) throw (GnError)
{
	gnsdk_playlist_collection_handle_t coll_handle = GNSDK_NULL;
	gnsdk_error_t                      error;

	error = gnsdk_playlist_storage_load_collection(*itr, &coll_handle);
	if (error) { throw GnError(); }

	return GnPlaylistCollection(coll_handle);
}


/*-----------------------------------------------------------------------------
 *  CollectionLoad
 */
GnPlaylistCollection
GnPlaylistStorage::Load(gnsdk_cstr_t collectionName) throw (GnError)
{
	gnsdk_playlist_collection_handle_t coll_handle = GNSDK_NULL;
	gnsdk_error_t                      error;

	error = gnsdk_playlist_storage_load_collection(collectionName, &coll_handle);
	if (error) { throw GnError(); }

	return GnPlaylistCollection(coll_handle);
}


/*-----------------------------------------------------------------------------
 *  StorageRemove
 */
void
GnPlaylistStorage::Remove(const GnPlaylistCollection& collection) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_storage_remove_collection(collection.Name() );
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  StorageRemove
 */
void
GnPlaylistStorage::Remove(gnsdk_cstr_t collectionName) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_storage_remove_collection(collectionName);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  StorageLocation
 */
void
GnPlaylistStorage::Location(gnsdk_cstr_t location) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_storage_location_set(location);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  StorageCompact
 */
void
GnPlaylistStorage::Compact() throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_playlist_storage_compact();
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  StorageIsValid
 */
GnError
GnPlaylistStorage::IsValid() const
{
	gnsdk_error_info_t error_info;
	gnsdk_error_t      error;

	error = gnsdk_playlist_storage_validate(&error_info);
	if (error)
		return GnError();

	return GnError(&error_info);
}


#endif

