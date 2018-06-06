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

#include "gnsdk_musicid.hpp"
#include "metadata_music.hpp"

using namespace gracenote;
using namespace gracenote::musicid;
using namespace gracenote::metadata;


static metadata::GnResponseAlbums
_intFindAlbums(gnsdk_musicid_query_handle_t handle) throw (GnError);

static void
_intSetText(gnsdk_musicid_query_handle_t handle, gnsdk_cstr_t albumTitle, gnsdk_cstr_t trackTitle, gnsdk_cstr_t albumArtistName, gnsdk_cstr_t trackArtistName, gnsdk_cstr_t composerName) throw (GnError);

static gnsdk_cstr_t
_MapfPTypeCStr(GnFingerprintType fpType);

static void GNSDK_CALLBACK_API
_callback_status(void* callback_data, gnsdk_status_t status, gnsdk_uint32_t percent_complete, gnsdk_size_t bytes_total_sent, gnsdk_size_t bytes_total_received, gnsdk_bool_t* p_abort);


/******************************************************************************
** GnMusicIdOptions
*/

/*-----------------------------------------------------------------------------
 *  LookupMode
 */
void
GnMusicIdOptions::LookupMode(GnLookupMode lookupMode) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_LOOKUP_MODE, gnconvert::gn_lookup_mode_to_string(lookupMode));
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  LookupMode
 */
GnLookupMode
GnMusicIdOptions::LookupMode() throw (GnError)
{
	gnsdk_cstr_t  option_value = GNSDK_NULL;
	gnsdk_error_t error;

	error = gnsdk_musicid_query_option_get(weakhandle_, GNSDK_MUSICID_OPTION_LOOKUP_MODE, &option_value);
	if (error) { throw GnError(); }

	return gnconvert::gn_lookup_mode_to_enum(option_value);
}


/*-----------------------------------------------------------------------------
 *  OptionLookupData
 */
void
GnMusicIdOptions::LookupData(GnLookupData lookupData, bool bEnable) throw (GnError)
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
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_CONTENT_DATA, sz_enable);
		break;

	case kLookupDataClassical:
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_CLASSICAL_DATA, sz_enable);
		break;

	case kLookupDataSonicData:
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_SONIC_DATA, sz_enable);
		break;

	case kLookupDataPlaylist:
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_PLAYLIST, sz_enable);
		break;

	case kLookupDataExternalIds:
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_EXTERNAL_IDS, sz_enable);
		break;

	case kLookupDataGlobalIds:
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_GLOBALIDS, sz_enable);
		break;

	case kLookupDataAdditionalCredits:
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ADDITIONAL_CREDITS, sz_enable);
		break;

	case kLookupDataSortable:
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_SORTABLE, sz_enable);
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
GnMusicIdOptions::NetworkInterface(gnsdk_cstr_t intfName) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_QUERY_OPTION_NETWORK_INTERFACE, intfName);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  NetworkInterface
 */
gnsdk_cstr_t
GnMusicIdOptions::NetworkInterface() throw (GnError)
{
	gnsdk_cstr_t  intfName = gnstd::kEmptyString;
	gnsdk_error_t error;

	error = gnsdk_musicid_query_option_get(weakhandle_, GNSDK_QUERY_OPTION_NETWORK_INTERFACE, &intfName);
	if (error) { throw GnError(); }

	return intfName;
}

/*-----------------------------------------------------------------------------
 *  AudioSuitabilityProcessing
 */
void
GnMusicIdOptions::AudioSuitabilityProcessing(bool bEnable) throw (GnError)
{
	gnsdk_error_t error;

	if ( bEnable )
	{
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_AUDIO_SUITABILITY_PROCESSING, GNSDK_VALUE_TRUE);
	}
	else
	{
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_ENABLE_AUDIO_SUITABILITY_PROCESSING, GNSDK_VALUE_FALSE);	
	}
	if (error) { throw GnError(); }	
}


/*-----------------------------------------------------------------------------
 *  OptionCustom
 */
void
GnMusicIdOptions::Custom(gnsdk_cstr_t option, gnsdk_cstr_t value) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_musicid_query_option_set(weakhandle_, option, value);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  OptionCustom
 */
void
GnMusicIdOptions::Custom(gnsdk_cstr_t option, bool bEnable) throw (GnError)
{
	gnsdk_error_t error;

	if (bEnable)
	{
		error = gnsdk_musicid_query_option_set(weakhandle_, option, GNSDK_VALUE_TRUE);
	}
	else
	{
		error = gnsdk_musicid_query_option_set(weakhandle_, option, GNSDK_VALUE_FALSE);
	}

	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  OptionResultPreferLanguage
 */
void
GnMusicIdOptions::PreferResultLanguage(GnLanguage preferredLanguage) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_PREFERRED_LANG, gnconvert::gn_language_to_string(preferredLanguage) );
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  OptionPreferredExternalId
 */
void
GnMusicIdOptions::PreferResultExternalId(gnsdk_cstr_t strExternalId) throw (GnError)
{
	gnsdk_error_t error;


	error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_RESULT_PREFER_XID, strExternalId);
	if ( error ) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *	OptionPreferCoverart
 */
void
GnMusicIdOptions::PreferResultCoverart(bool bEnable) throw (GnError)
{
	gnsdk_error_t error;

	if (bEnable)
	{
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_RESULT_PREFER_COVERART, GNSDK_VALUE_TRUE);
	}
	else
	{
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_RESULT_PREFER_COVERART, GNSDK_VALUE_FALSE);
	}
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  OptionResultSingle
 */
void
GnMusicIdOptions::ResultSingle(bool bEnable) throw (GnError)
{
	gnsdk_error_t error;

	if (bEnable)
	{
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_RESULT_SINGLE, GNSDK_VALUE_TRUE);
	}
	else
	{
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_RESULT_SINGLE, GNSDK_VALUE_FALSE);
	}

	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  RevisionCheck
 */
void
GnMusicIdOptions::RevisionCheck(bool bEnable) throw (GnError)
{
	gnsdk_error_t error;

	if (bEnable)
	{
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_REVISION_CHECK, GNSDK_VALUE_TRUE);
	}
	else
	{
		error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_REVISION_CHECK, GNSDK_VALUE_FALSE);
	}

	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  ResultRangeStart
 */
void
GnMusicIdOptions::ResultRangeStart(gnsdk_uint32_t resultStart) throw (GnError)
{
	char          buffer[16];
	gnsdk_error_t error;

	gnstd::gn_itoa(buffer, sizeof(buffer), resultStart);
	error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_RESULT_RANGE_START, buffer);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  ResultCount
 */
void
GnMusicIdOptions::ResultCount(gnsdk_uint32_t resultCount) throw (GnError)
{
	char          buffer[16];
	gnsdk_error_t error;

	gnstd::gn_itoa(buffer, sizeof(buffer), resultCount);
	error = gnsdk_musicid_query_option_set(weakhandle_, GNSDK_MUSICID_OPTION_RESULT_RANGE_SIZE, buffer);
	if (error) { throw GnError(); }
}


/******************************************************************************
** GnMusicId
*/
GnMusicId::GnMusicId(const GnUser& user, IGnStatusEvents* pEventHandler)  throw (GnError) :
	cancelled_(false)
{
	eventHandler_ = GnManagedPtr<IGnStatusEvents*>(pEventHandler, GnManagedPtr<IGnStatusEvents*>::ptr_nomanage);
	create(user, GnLocale());
}


GnMusicId::GnMusicId(const GnUser& user, GnManagedPtr<IGnStatusEvents*> eventHandler) throw (GnError) :
	cancelled_(false)
{
	eventHandler_ = eventHandler;
	create(user, GnLocale());
}


GnMusicId::GnMusicId(const GnUser& user, const GnLocale& locale, IGnStatusEvents* pEventHandler)  throw (GnError) :
	cancelled_(false)
{
	eventHandler_ = GnManagedPtr<IGnStatusEvents*>(pEventHandler, GnManagedPtr<IGnStatusEvents*>::ptr_nomanage);
	create(user, locale);
}


GnMusicId::GnMusicId(const GnUser& user, const GnLocale& locale, GnManagedPtr<IGnStatusEvents*> eventHandler) throw (GnError) :
	cancelled_(false)
{
	eventHandler_ = eventHandler;
	create(user, locale);
}


GnMusicId::~GnMusicId()
{ }


/*-----------------------------------------------------------------------------
 *  create
 */
void
GnMusicId::create(const GnUser& user, const GnLocale& locale) throw (GnError)
{
	gnsdk_musicid_query_handle_t query_handle = GNSDK_NULL;
	gnsdk_error_t                error;

	_gnsdk_internal::module_initialize(GNSDK_MODULE_MUSICID);

	error = gnsdk_musicid_query_create(user.native(), _callback_status, this, &query_handle);
	if (error) { throw GnError(); }

	assign(query_handle);

	if (locale.native())
	{
		error = gnsdk_musicid_query_set_locale(query_handle, locale.native());
		if (error) { throw GnError(); }
	}

	options_.weakhandle_ = query_handle;
}


/*-----------------------------------------------------------------------------
 *  Version
 */
gnsdk_cstr_t
GnMusicId::Version()
{
	return gnsdk_musicid_get_version();
}


/*-----------------------------------------------------------------------------
 *  BuildDate
 */
gnsdk_cstr_t
GnMusicId::BuildDate()
{
	return gnsdk_musicid_get_build_date();
}


/*-----------------------------------------------------------------------------
 *  FingerprintDataGet
 */
gnsdk_cstr_t
GnMusicId::FingerprintDataGet() throw (GnError)
{
	gnsdk_error_t error;
	gnsdk_cstr_t  str = GNSDK_NULL;

	error = gnsdk_musicid_query_get_fp_data(native(), &str);
	if (error) { throw GnError(); }

	return str;
}


/*-----------------------------------------------------------------------------
 *  FingerprintBegin
 */
void
GnMusicId::FingerprintBegin(GnFingerprintType fpType, gnsdk_uint32_t audio_sample_rate, gnsdk_uint32_t audio_sample_size, gnsdk_uint32_t audio_channels)
throw (GnError)
{
	gnsdk_error_t error;

	_gnsdk_internal::module_initialize(GNSDK_MODULE_DSP);

	error = gnsdk_musicid_query_fingerprint_begin(native(), _MapfPTypeCStr(fpType), audio_sample_rate, audio_sample_size, audio_channels);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  FingerprintWrite
 */
bool
GnMusicId::FingerprintWrite(const gnsdk_byte_t* audioData, gnsdk_size_t audioData_size) throw (GnError)
{
	gnsdk_bool_t  b_complete = GNSDK_FALSE;
	gnsdk_error_t error;

	error = gnsdk_musicid_query_fingerprint_write(native(), audioData, audioData_size, &b_complete);
	if (error) { throw GnError(); }

	if (b_complete)
	{
		return true;
	}
	return false;
}


/*-----------------------------------------------------------------------------
 *  FingerprintEnd
 */
void
GnMusicId::FingerprintEnd() throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_musicid_query_fingerprint_end(native());
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  FingerprintFromSource
 */
void
GnMusicId::FingerprintFromSource(IGnAudioSource& audioSource, GnFingerprintType fpType) throw (GnError)
{
	gnsdk_byte_t  audio_buffer[1024];
	gnsdk_size_t  audioData_size;
	gnsdk_bool_t  b_complete;
	gnsdk_error_t error;

	_gnsdk_internal::module_initialize(GNSDK_MODULE_DSP);

	error = audioSource.SourceInit();
	if (error)
	{
		gnsdk_error_info_t error_info;
		error_info.error_api           = "GnMusicId::FingerprintFromSource";
		error_info.error_code          = error;
		error_info.error_description   = "Failed to initialize audio source";
		error_info.error_module        = "GnMusicId";
		error_info.source_error_code   = error_info.error_code;
		error_info.source_error_module = error_info.error_module;
		throw GnError(&error_info);
	}

	error = gnsdk_musicid_query_fingerprint_begin(native(), _MapfPTypeCStr(fpType), audioSource.SamplesPerSecond(), audioSource.SampleSizeInBits(), audioSource.NumberOfChannels() );
	if (!error)
	{
		b_complete = GNSDK_FALSE;

		while (0 < ( audioData_size = audioSource.GetData(audio_buffer, sizeof( audio_buffer ) ) ) )
		{
			error = gnsdk_musicid_query_fingerprint_write(native(), audio_buffer, audioData_size, &b_complete);
			if (error)
			{
				break;
			}

			if (b_complete)
			{
				break;
			}
		}

		if (!b_complete)
		{
			error = gnsdk_musicid_query_fingerprint_end(native());
		}
	}

	audioSource.SourceClose();

	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  FindAlbums
 */
GnResponseAlbums
GnMusicId::FindAlbums(gnsdk_cstr_t albumTitle, gnsdk_cstr_t trackTitle, gnsdk_cstr_t albumArtistName, gnsdk_cstr_t trackArtistName, gnsdk_cstr_t composerName) throw (GnError)
{
	cancelled_ = false;

	_intSetText(native(), albumTitle, trackTitle, albumArtistName, trackArtistName, composerName);

	return _intFindAlbums(native());
}


/*-----------------------------------------------------------------------------
 *  FindAlbums
 */
GnResponseAlbums
GnMusicId::FindAlbums(gnsdk_cstr_t strCDTOC)
throw (GnError)
{
	gnsdk_error_t error;

	cancelled_ = false;

	error = gnsdk_musicid_query_set_toc_string(native(), strCDTOC);
	if (error) { throw GnError(); }

	return _intFindAlbums(native());
}


/*-----------------------------------------------------------------------------
 *  FindAlbums
 */
GnResponseAlbums
GnMusicId::FindAlbums(gnsdk_cstr_t strCDTOC, gnsdk_cstr_t strFingerprintData, GnFingerprintType fpType) throw (GnError)
{
	gnsdk_error_t error;

	cancelled_ = false;

	error = gnsdk_musicid_query_set_toc_string(native(), strCDTOC);
	if (error) { throw GnError(); }

	error = gnsdk_musicid_query_set_fp_data(native(), strFingerprintData, _MapfPTypeCStr(fpType) );
	if (error) { throw GnError(); }

	return _intFindAlbums(native());
}


/*-----------------------------------------------------------------------------
 *  FindAlbums
 */
GnResponseAlbums
GnMusicId::FindAlbums(gnsdk_cstr_t strFingerprintData, GnFingerprintType fpType) throw (GnError)
{
	gnsdk_error_t error;

	cancelled_ = false;

	error = gnsdk_musicid_query_set_fp_data(native(), strFingerprintData, _MapfPTypeCStr(fpType) );
	if (error) { throw GnError(); }

	return _intFindAlbums(native());
}


/*-----------------------------------------------------------------------------
 *  FindAlbums
 */
GnResponseAlbums
GnMusicId::FindAlbums(const GnDataObject& gnObj) throw (GnError)
{
	gnsdk_error_t error;

	cancelled_ = false;

	error = gnsdk_musicid_query_set_gdo(native(), gnObj.native() );
	if (error) { throw GnError(); }

	return _intFindAlbums(native());
}


/*-----------------------------------------------------------------------------
 *  FindAlbums
 */
GnResponseAlbums
GnMusicId::FindAlbums(IGnAudioSource& audioSource, GnFingerprintType fpType) throw (GnError)
{
	cancelled_ = false;

	FingerprintFromSource(audioSource, fpType);

	return _intFindAlbums(native());
}


/*-----------------------------------------------------------------------------
 *  FindMatches
 */
GnResponseDataMatches
GnMusicId::FindMatches(gnsdk_cstr_t albumTitle, gnsdk_cstr_t trackTitle, gnsdk_cstr_t albumArtistName, gnsdk_cstr_t trackArtistName, gnsdk_cstr_t composerName) throw (GnError)
{
	gnsdk_gdo_handle_t response_gdo;

	cancelled_ = false;

	_intSetText(native(), albumTitle, trackTitle, albumArtistName, trackArtistName, composerName);

	gnsdk_error_t error = gnsdk_musicid_query_find_matches(native(), &response_gdo);
	if (error) { throw GnError(); }

	return GnResponseDataMatches(response_gdo);
}


/*-----------------------------------------------------------------------------
 *  InfoGet
 */
GnString
GnMusicId::InfoGet(GnMusicIdInfo infoType) throw (GnError)
{
	gnsdk_cstr_t value = GNSDK_NULL;
	gnsdk_cstr_t key = GNSDK_NULL;
	switch(infoType)
	{
		case kInfoSuitableForQuery:
			key = GNSDK_MUSICID_AUDIO_INFO_SUITABLE_FOR_QUERY;
			break;
		default:
			{
				throw GnError(MIDSERR_InvalidArg, "Unhandled GnMusicIdInfo provided");
			}
			break;
	}

	gnsdk_error_t error = gnsdk_musicid_query_fingerprint_info_get(native(),key,&value);	
	if (GNSDKERR_SEVERE(error)) { throw GnError();}

	return GnString(value);
}


/*-----------------------------------------------------------------------------
 *  InfoGet
 */
GnString
GnMusicId::InfoGet(gnsdk_cstr_t key) throw (GnError)
{
	gnsdk_cstr_t value = GNSDK_NULL;
	gnsdk_error_t error = gnsdk_musicid_query_fingerprint_info_get(native(),key,&value);	
	if (GNSDKERR_SEVERE(error)) { throw GnError();}

	return GnString(value);
}


/*-----------------------------------------------------------------------------
 *  _intFindAlbums
 */
GnResponseAlbums
_intFindAlbums(gnsdk_musicid_query_handle_t handle) throw (GnError)
{
	gnsdk_gdo_handle_t response_gdo;
	gnsdk_error_t      error;

	error = gnsdk_musicid_query_find_albums(handle, &response_gdo);
	if (error) { throw GnError(); }

	return GnResponseAlbums(response_gdo);
}


/*-----------------------------------------------------------------------------
 *  _intSetText
 */
void
_intSetText(gnsdk_musicid_query_handle_t handle, gnsdk_cstr_t albumTitle, gnsdk_cstr_t trackTitle, gnsdk_cstr_t albumArtistName, gnsdk_cstr_t trackArtistName, gnsdk_cstr_t composerName) throw (GnError)
{
	gnsdk_error_t error = MIDERR_NoError;

	if (albumTitle && (0 != gnstd::gn_strlen(albumTitle)) )
	{
		error = gnsdk_musicid_query_set_text(handle, GNSDK_MUSICID_FIELD_ALBUM, albumTitle);
		if (error) { throw GnError(); }
	}

	if (trackTitle && (0 != gnstd::gn_strlen(trackTitle)) )
	{
		error = gnsdk_musicid_query_set_text(handle, GNSDK_MUSICID_FIELD_TITLE, trackTitle);
		if (error) { throw GnError(); }
	}

	if (albumArtistName && (0 != gnstd::gn_strlen(albumArtistName)) )
	{
		error = gnsdk_musicid_query_set_text(handle, GNSDK_MUSICID_FIELD_ALBUM_ARTIST, albumArtistName);
		if (error) { throw GnError(); }
	}

	if (trackArtistName && (0 != gnstd::gn_strlen(trackArtistName)) )
	{
		error = gnsdk_musicid_query_set_text(handle, GNSDK_MUSICID_FIELD_TRACK_ARTIST, trackArtistName);
		if (error) { throw GnError(); }
	}

	if (composerName && (0 != gnstd::gn_strlen(composerName)) )
	{
		error = gnsdk_musicid_query_set_text(handle, GNSDK_MUSICID_FIELD_COMPOSER, composerName);
		if (error) { throw GnError(); }
	}

}


/*-----------------------------------------------------------------------------
 *  _MapfPTypeCStr
 */
gnsdk_cstr_t
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
void GNSDK_CALLBACK_API
_callback_status(void* callback_data, gnsdk_status_t mid_status, gnsdk_uint32_t percent_complete, gnsdk_size_t bytes_total_sent, gnsdk_size_t bytes_total_received, gnsdk_bool_t* p_abort)
{
	GnMusicId* p_musicid = (GnMusicId*)callback_data;

	if (p_musicid->EventHandler())
	{
		gn_canceller canceller;

		if (!p_musicid->IsCancelled())
		{
			p_musicid->EventHandler()->StatusEvent((GnStatus)mid_status, percent_complete, bytes_total_sent, bytes_total_received, canceller);
		}

		if (canceller.IsCancelled() || p_musicid->IsCancelled())
		{
			*p_abort = GNSDK_TRUE;
		}
	}
}


#endif /* GNSDK_MUSICID */

