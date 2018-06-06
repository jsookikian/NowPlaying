/*
 * Copyright (c) 2000-2016 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/* gnsdk_musicid.cpp
 *
 * Implementation of C++ wrapper for GNSDK
 *
 */
#include "gnsdk_manager.hpp"
#include "gnsdk_convert.hpp"

#if GNSDK_MUSICID

#include "gnsdk_musicidbatch.hpp"
#include "metadata_music.hpp"

using namespace gracenote;
using namespace gracenote::musicid_batch;
using namespace gracenote::metadata;

static gnsdk_cstr_t
_MapfPTypeCStr(GnFingerprintType fpType);

static void GNSDK_CALLBACK_API
_callback_status(void* callback_data, gnsdk_status_t status, gnsdk_uint32_t percent_complete, gnsdk_size_t bytes_total_sent, gnsdk_size_t bytes_total_received, gnsdk_bool_t* p_abort);

/******************************************************************************
** GnMusicIdBatchOptions
*/

/*-----------------------------------------------------------------------------
 *  LookupMode
 */
void
GnMusicIdBatchOptions::LookupMode(GnLookupMode lookupMode) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_LOOKUP_MODE, gnconvert::gn_lookup_mode_to_string(lookupMode));
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  LookupMode
 */
GnLookupMode
GnMusicIdBatchOptions::LookupMode() throw (GnError)
{
	gnsdk_cstr_t  option_value = GNSDK_NULL;
	gnsdk_error_t error;

	error = gnsdk_musicid_batch_option_get(weakhandle_, GNSDK_MUSICID_OPTION_LOOKUP_MODE, &option_value);
	if (error) { throw GnError(); }

	return gnconvert::gn_lookup_mode_to_enum(option_value);
}


/*-----------------------------------------------------------------------------
 *  OptionLookupData
 */
void
GnMusicIdBatchOptions::LookupData(GnLookupData lookupData, bool bEnable) throw (GnError)
{
	gnsdk_error_t error;
	gnsdk_cstr_t  sz_enable;

	if (bEnable)
	{
		sz_enable = GNSDK_VALUE_TRUE;
	}
	else
	{
		sz_enable = GNSDK_VALUE_FALSE;
	}

	switch (lookupData)
	{
	case kLookupDataContent:
		error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_CONTENT_DATA, sz_enable);
		break;

	case kLookupDataClassical:
		error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_CLASSICAL_DATA, sz_enable);
		break;

	case kLookupDataSonicData:
		error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_SONIC_DATA, sz_enable);
		break;

	case kLookupDataPlaylist:
		error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_PLAYLIST, sz_enable);
		break;

	case kLookupDataExternalIds:
		error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_EXTERNAL_IDS, sz_enable);
		break;

	case kLookupDataGlobalIds:
		error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_GLOBALIDS, sz_enable);
		break;

	case kLookupDataAdditionalCredits:
		error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ADDITIONAL_CREDITS, sz_enable);
		break;

	case kLookupDataSortable:
		error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_SORTABLE, sz_enable);
		break;

	default:
		return;
	}

	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  NetworkInterface
 */
void
GnMusicIdBatchOptions::NetworkInterface(gnsdk_cstr_t intfName) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_QUERY_OPTION_NETWORK_INTERFACE, intfName);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  NetworkInterface
 */
gnsdk_cstr_t
GnMusicIdBatchOptions::NetworkInterface() throw (GnError)
{
	gnsdk_cstr_t  intfName = gnstd::kEmptyString;
	gnsdk_error_t error;

	error = gnsdk_musicid_batch_option_get(weakhandle_, GNSDK_QUERY_OPTION_NETWORK_INTERFACE, &intfName);
	if (error) { throw GnError(); }

	return intfName;
}


/*-----------------------------------------------------------------------------
 *  OptionCustom
 */
void
GnMusicIdBatchOptions::Custom(gnsdk_cstr_t option, gnsdk_cstr_t value) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_musicid_batch_option_set(weakhandle_, option, value);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  OptionCustom
 */
void
GnMusicIdBatchOptions::Custom(gnsdk_cstr_t option, bool bEnable) throw (GnError)
{
	gnsdk_error_t error;

	if (bEnable)
	{
		error = gnsdk_musicid_batch_option_set(weakhandle_, option, GNSDK_VALUE_TRUE);
	}
	else
	{
		error = gnsdk_musicid_batch_option_set(weakhandle_, option, GNSDK_VALUE_FALSE);
	}

	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  OptionResultPreferLanguage
 */
void
GnMusicIdBatchOptions::PreferResultLanguage(GnLanguage preferredLanguage) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_PREFERRED_LANG, gnconvert::gn_language_to_string(preferredLanguage) );
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  OptionPreferredExternalId
 */
void
GnMusicIdBatchOptions::PreferResultExternalId(gnsdk_cstr_t strExternalId) throw (GnError)
{
	gnsdk_error_t error;


	error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_RESULT_PREFER_XID, strExternalId);
	if ( error ) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *	OptionPreferCoverart
 */
void
GnMusicIdBatchOptions::PreferResultCoverart(bool bEnable) throw (GnError)
{
	gnsdk_error_t error;

	if (bEnable)
	{
		error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_RESULT_PREFER_COVERART, GNSDK_VALUE_TRUE);
	}
	else
	{
		error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_RESULT_PREFER_COVERART, GNSDK_VALUE_FALSE);
	}
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  InlineImage
 */
void
GnMusicIdBatchOptions::InlineImage(GnImageSize imageSize) throw (GnError)
{
	gnsdk_error_t error;
	
	error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_INLINE_IMAGE_SIZE, gnconvert::gn_image_size_to_string(imageSize));
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  RevisionCheck
 */
void
GnMusicIdBatchOptions::RevisionCheck(bool bEnable) throw (GnError)
{
	gnsdk_error_t error;

	if (bEnable)
	{
		error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_REVISION_CHECK, GNSDK_VALUE_TRUE);
	}
	else
	{
		error = gnsdk_musicid_batch_option_set(weakhandle_, GNSDK_MUSICID_OPTION_REVISION_CHECK, GNSDK_VALUE_FALSE);
	}

	if (error) { throw GnError(); }
}


/******************************************************************************
** GnMusicIdBatch
*/

/*-----------------------------------------------------------------------------
 *  GnMusicIdBatch
 */
GnMusicIdBatch::GnMusicIdBatch()  throw (GnError)
	: GnObject<gnsdk_musicid_batch_handle_t>(), cancelled_(GNSDK_FALSE)
{
}

/*-----------------------------------------------------------------------------
 *  GnMusicIdBatch
 */
GnMusicIdBatch::GnMusicIdBatch(const GnUser& user, IGnStatusEvents* pEventHandler)  throw (GnError)
	: GnObject<gnsdk_musicid_batch_handle_t>(), cancelled_(GNSDK_FALSE)
{
	eventHandler_ = GnManagedPtr<IGnStatusEvents*>(pEventHandler, GnManagedPtr<IGnStatusEvents*>::ptr_nomanage);
	create(user, GnLocale());
}


/*-----------------------------------------------------------------------------
 *  GnMusicIdBatch
 */
GnMusicIdBatch::GnMusicIdBatch(const GnUser& user, GnManagedPtr<IGnStatusEvents*> eventHandler) throw (GnError)
	: GnObject<gnsdk_musicid_batch_handle_t>(), cancelled_(GNSDK_FALSE)
{
	eventHandler_ = eventHandler;
	create(user, GnLocale());
}


/*-----------------------------------------------------------------------------
 *  GnMusicIdBatch
 */
GnMusicIdBatch::GnMusicIdBatch(const GnUser& user, const GnLocale& locale, IGnStatusEvents* pEventHandler)  throw (GnError)
	: GnObject<gnsdk_musicid_batch_handle_t>(), cancelled_(GNSDK_FALSE)
{
	eventHandler_ = GnManagedPtr<IGnStatusEvents*>(pEventHandler, GnManagedPtr<IGnStatusEvents*>::ptr_nomanage);
	create(user, locale);
}


/*-----------------------------------------------------------------------------
 *  GnMusicIdBatch
 */
GnMusicIdBatch::GnMusicIdBatch(const GnUser& user, const GnLocale& locale, GnManagedPtr<IGnStatusEvents*> eventHandler) throw (GnError)
	: GnObject<gnsdk_musicid_batch_handle_t>(), cancelled_(GNSDK_FALSE)
{
	eventHandler_ = eventHandler;
	create(user, locale);
}


/*-----------------------------------------------------------------------------
 *  ~GnMusicIdBatch
 */
GnMusicIdBatch::~GnMusicIdBatch()
{
}

/*-----------------------------------------------------------------------------
 *  Clear
 */
void
GnMusicIdBatch::Clear() throw (GnError)
{
	gnsdk_error_t error = gnsdk_musicid_batch_clear(native());
	if (error) { throw GnError(); }
}

/*-----------------------------------------------------------------------------
 *  FindAlbums
 */
void
GnMusicIdBatch::FindAlbums() throw (GnError)
{
	gnsdk_error_t error = gnsdk_musicid_batch_find_albums(native());
	if (error) { throw GnError(); }
}

/*-----------------------------------------------------------------------------
 *  FindMatches
 */
void
GnMusicIdBatch::FindMatches() throw (GnError)
{
	gnsdk_error_t error = gnsdk_musicid_batch_find_matches(native());
	if (error) { throw GnError(); }
}

/*-----------------------------------------------------------------------------
 *  GetResponseAlbum
 */
GnResponseAlbums
GnMusicIdBatch::GetAlbums(gnsdk_cstr_t unique_id) throw (GnError)
{
	gnsdk_gdo_handle_t response_gdo;

	gnsdk_error_t error = gnsdk_musicid_batch_response_get(native(), unique_id, &response_gdo);
	if (error) { throw GnError(); }
	
//	GNSDK_CHECKED_CAST()
	return GnResponseAlbums::From(GnResponseAlbums(response_gdo));
//	return GnResponseAlbums(response_gdo);

//	GnResponseData response(response_gdo);
//	if (0 == gnstd::gn_strcmp(GNSDK_GDO_TYPE_RESPONSE_ALBUM, response.GetType())
//	{
//		return GnResponseAlbums(response_gdo);
//	}
}

/*-----------------------------------------------------------------------------
 *  GetResponseMatches
 */
GnResponseDataMatches
GnMusicIdBatch::GetMatches(gnsdk_cstr_t unique_id) throw (GnError)
{
	gnsdk_gdo_handle_t response_gdo;

	gnsdk_error_t error = gnsdk_musicid_batch_response_get(native(), unique_id, &response_gdo);
	if (error) { throw GnError(); }
	
//	GNSDK_CHECKED_CAST()
	return GnResponseDataMatches::From(GnResponseDataMatches(response_gdo));
//	return GnResponseDataMatches(response_gdo);

//	GnResponseData response(response_gdo);
//	if (0 == gnstd::gn_strcmp(GNSDK_GDO_TYPE_RESPONSE_MATCH, response.GetType())
//	{
//		return GnResponseDataMatches(response_gdo);
//	}
}

/*-----------------------------------------------------------------------------
 *  Version
 */
gnsdk_cstr_t
GnMusicIdBatch::Version()
{
	return gnsdk_musicid_get_version();
}


/*-----------------------------------------------------------------------------
 *  BuildDate
 */
gnsdk_cstr_t
GnMusicIdBatch::BuildDate()
{
	return gnsdk_musicid_get_build_date();
}

/*-----------------------------------------------------------------------------
 *  create
 */
void
GnMusicIdBatch::create(const GnUser& user, const GnLocale& locale) throw (GnError)
{
	gnsdk_musicid_batch_handle_t	query_handle = GNSDK_NULL;
	gnsdk_error_t					error;

	_gnsdk_internal::module_initialize(GNSDK_MODULE_MUSICID);

	error = gnsdk_musicid_batch_create(user.native(), _callback_status, this, &query_handle);
	if (error) { throw GnError(); }

	assign(query_handle);

	if (locale.native())
	{
		error = gnsdk_musicid_batch_set_locale(query_handle, locale.native());
		if (error) { throw GnError(); }
	}

	options_.weakhandle_ = query_handle;
}

/******************************************************************************
** GnMusicIdBatchQuery
*/

/*-----------------------------------------------------------------------------
 *  GnMusicIdBatchQuery
 */
GnMusicIdBatchQuery::GnMusicIdBatchQuery(GnMusicIdBatch& batch, gnsdk_cstr_t uniqueId) throw (GnError)
	: weakhandle_(batch.native()), uniqueId_(uniqueId)
{
	gnsdk_error_t error = gnsdk_musicid_batch_query_create(weakhandle_, uniqueId_);
	if (error) { throw GnError(); }
}

/*-----------------------------------------------------------------------------
 *  ~GnMusicIdBatchQuery
 */
GnMusicIdBatchQuery::~GnMusicIdBatchQuery()
{
}

/*-----------------------------------------------------------------------------
 *  SetFP
 */
void
GnMusicIdBatchQuery::SetFingerprint(gnsdk_cstr_t strFingerprintData, GnFingerprintType fpType) throw (GnError)
{
	gnsdk_error_t error = gnsdk_musicid_batch_query_set_fp_data(weakhandle_, uniqueId_, strFingerprintData, _MapfPTypeCStr(fpType) );
	if (error) { throw GnError(); }
}

/*-----------------------------------------------------------------------------
 *  SetGDO
 */
void
GnMusicIdBatchQuery::SetGDO(const GnDataObject& gnObj) throw (GnError)
{
	gnsdk_error_t error = gnsdk_musicid_batch_query_set_gdo(weakhandle_, uniqueId_, gnObj.native());
	if (error) { throw GnError(); }
}

/*-----------------------------------------------------------------------------
 *  SetText
 */
void
GnMusicIdBatchQuery::SetText(gnsdk_cstr_t albumTitle, gnsdk_cstr_t trackTitle, gnsdk_cstr_t albumArtistName, gnsdk_cstr_t trackArtistName, gnsdk_cstr_t composerName) throw (GnError)
{
	gnsdk_error_t error = MIDERR_NoError;

	if (albumTitle && (0 != gnstd::gn_strlen(albumTitle)) )
	{
		error = gnsdk_musicid_batch_query_set_text(weakhandle_, uniqueId_, GNSDK_MUSICID_FIELD_ALBUM, albumTitle);
		if (error) { throw GnError(); }
	}

	if (trackTitle && (0 != gnstd::gn_strlen(trackTitle)) )
	{
		error = gnsdk_musicid_batch_query_set_text(weakhandle_, uniqueId_, GNSDK_MUSICID_FIELD_TITLE, trackTitle);
		if (error) { throw GnError(); }
	}

	if (albumArtistName && (0 != gnstd::gn_strlen(albumArtistName)) )
	{
		error = gnsdk_musicid_batch_query_set_text(weakhandle_, uniqueId_, GNSDK_MUSICID_FIELD_ALBUM_ARTIST, albumArtistName);
		if (error) { throw GnError(); }
	}

	if (trackArtistName && (0 != gnstd::gn_strlen(trackArtistName)) )
	{
		error = gnsdk_musicid_batch_query_set_text(weakhandle_, uniqueId_, GNSDK_MUSICID_FIELD_TRACK_ARTIST, trackArtistName);
		if (error) { throw GnError(); }
	}

	if (composerName && (0 != gnstd::gn_strlen(composerName)) )
	{
		error = gnsdk_musicid_batch_query_set_text(weakhandle_, uniqueId_, GNSDK_MUSICID_FIELD_COMPOSER, composerName);
		if (error) { throw GnError(); }
	}
}

/*-----------------------------------------------------------------------------
 *  SetTOC
 */
void
GnMusicIdBatchQuery::SetTOCOffset(gnsdk_uint32_t tocOffset) throw (GnError)
{
	gnsdk_error_t error = gnsdk_musicid_batch_query_add_toc_offset(weakhandle_, uniqueId_, tocOffset);
	if (error) { throw GnError(); }
}

/*-----------------------------------------------------------------------------
 *  SetTOC
 */
void
GnMusicIdBatchQuery::SetTOC(gnsdk_cstr_t strTOC) throw (GnError)
{
	gnsdk_error_t error = gnsdk_musicid_batch_query_set_toc_string(weakhandle_, uniqueId_, strTOC);
	if (error) { throw GnError(); }
}


/******************************************************************************
** Static Functions
*/

/*-----------------------------------------------------------------------------
 *  _MapfPTypeCStr
 */
static gnsdk_cstr_t
_MapfPTypeCStr(GnFingerprintType fpType)
{
	gnsdk_cstr_t str = GNSDK_NULL;

	switch (fpType)
	{
	case kFingerprintTypeCMX:
		str = GNSDK_MUSICID_FP_DATA_TYPE_CMX;
		break;

	case kFingerprintTypeFile:
		str = GNSDK_MUSICID_FP_DATA_TYPE_FILE;
		break;

	case kFingerprintTypeGNFPX:
		str = GNSDK_MUSICID_FP_DATA_TYPE_GNFPX;
		break;

	case kFingerprintTypeStream3:
		str = GNSDK_MUSICID_FP_DATA_TYPE_STREAM3;
		break;

	case kFingerprintTypeStream6:
		str = GNSDK_MUSICID_FP_DATA_TYPE_STREAM6;
		break;

	case kFingerprintTypeStreamFP:
		str = GNSDK_MUSICID_FP_DATA_TYPE_STREAMFP;
		break;

	default:
		break;
	}

	return str;
}

/*-----------------------------------------------------------------------------
 *  _callback_status
 */
static void GNSDK_CALLBACK_API
_callback_status(void* callback_data, gnsdk_status_t mid_status, gnsdk_uint32_t percent_complete, gnsdk_size_t bytes_total_sent, gnsdk_size_t bytes_total_received, gnsdk_bool_t* p_abort)
{
	GnMusicIdBatch* p_musicIdBatch = (GnMusicIdBatch*)callback_data;

	if (p_musicIdBatch->EventHandler())
	{
		gn_canceller canceller;

		if (!p_musicIdBatch->IsCancelled())
		{
			p_musicIdBatch->EventHandler()->StatusEvent((GnStatus)mid_status, percent_complete, bytes_total_sent, bytes_total_received, canceller);
		}

		if (canceller.IsCancelled() || p_musicIdBatch->IsCancelled())
		{
			*p_abort = GNSDK_TRUE;
		}
	}
}

#endif /* GNSDK_MUSICID */

