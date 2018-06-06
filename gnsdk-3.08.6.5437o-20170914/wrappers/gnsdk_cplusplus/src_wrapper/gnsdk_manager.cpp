/*
 * Copyright (c) 2000-2016 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/* gnsdk_manager.cpp
 *
 * Implementation of C++ wrapper for GNSDK Manager
 *
 */

#include "gnsdk_manager.hpp"
#include "gnsdk_list.hpp"
#include "gnsdk_convert.hpp"

using namespace gracenote;


static void GNSDK_CALLBACK_API
_locale_update_callback(void* callback_data, gnsdk_locale_handle_t locale_handle);

static gnsdk_void_t GNSDK_CALLBACK_API
_list_update_callback(void* callback_data, gnsdk_list_handle_t list_handle);

static void
_memory_warn_fn(gnsdk_void_t* p_arg, gnsdk_size_t cur_mem_size, gnsdk_size_t memory_warn_size);

GNSDK_EXTERN_C gnsdk_error_t GNSDK_API
manager_init_inc(void);

GNSDK_EXTERN_C gnsdk_uint32_t GNSDK_API
manager_init_dec(void);

/* static private vars */
static gnsdk_manager_handle_t sManagerHandle = GNSDK_NULL;
static gnsdk_uint32_t         sModulesInit   = 0;
static bool sInitialized = false;


/******************************************************************************
** GnManager
*/

GnManager::GnManager(gnsdk_cstr_t license, GnLicenseInputMode licenseInputMode) throw (GnError)
	: localestore_(GNSDK_MANAGER_STORAGE_LISTS)
	, querycachestore_(GNSDK_MANAGER_STORAGE_QUERYCACHE)
	, contentcachestore_(GNSDK_MANAGER_STORAGE_CONTENTCACHE)
	, tempcachestore_(GNSDK_MANAGER_STORAGE_TEMP)
{
	gnsdk_error_t error;

	Initialize();

	switch (licenseInputMode)
	{
	case kLicenseInputModeString:
	case kLicenseInputModeFilename:
	case kLicenseInputModeStandardIn:
		ApplyLicense(license, licenseInputMode);
		break;

	default:
		break;
	}

	error = gnsdk_manager_locale_update_notify(_locale_update_callback, this);
	if (error) { throw GnError(); }
	error = gnsdk_manager_list_update_notify(_list_update_callback, this);
	if (error) { throw GnError(); }
}


GnManager::~GnManager() throw (GnError)
{
	gnsdk_manager_locale_update_denotify(_locale_update_callback, this);
	gnsdk_manager_list_update_denotify(_list_update_callback, this);
	gnsdk_manager_memory_warn(GNSDK_NULL, GNSDK_NULL, 0);

	_gnsdk_internal::manager_release();
}


/*-----------------------------------------------------------------------------
 *  Version
 */
gnsdk_cstr_t
GnManager::Version()
{
	return gnsdk_manager_get_version();
}


/*-----------------------------------------------------------------------------
 *  ProductVersion
 */
gnsdk_cstr_t
GnManager::ProductVersion()
{
	return gnsdk_manager_get_product_version();
}


/*-----------------------------------------------------------------------------
 *  BuildDate
 */
gnsdk_cstr_t
GnManager::BuildDate()
{
	return gnsdk_manager_get_build_date();
}


/*-----------------------------------------------------------------------------
 *  Initialize
 */
void
GnManager::Initialize() throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_initialize(&sManagerHandle, 0, 0);
	if (error) { throw  GnError(); }

	sInitialized = true;
}


/*-----------------------------------------------------------------------------
 *  Shutdown
 */
void
GnManager::Shutdown() throw (GnError)
{
	if (sInitialized)
	{
		_gnsdk_internal::manager_release();
	}
}


/*-----------------------------------------------------------------------------
 *  ApplyLicense
 */
void
GnManager::ApplyLicense(gnsdk_cstr_t license, GnLicenseInputMode licenseInputMode) throw (GnError)
{
	gnsdk_size_t  licenseMode = 0;
	gnsdk_error_t error;

	switch (licenseInputMode)
	{
	case kLicenseInputModeString:
		licenseMode = GNSDK_MANAGER_LICENSEDATA_NULLTERMSTRING;
		break;

	case kLicenseInputModeFilename:
		licenseMode = GNSDK_MANAGER_LICENSEDATA_FILENAME;
		break;

	case kLicenseInputModeStandardIn:
		licenseMode = GNSDK_MANAGER_LICENSEDATA_STDIN;
		break;

	case kLicenseInputModeInvalid:
		throw GnError(GNSDKERR_InvalidArg, "Invalid license input mode");
		break;

	default:
		licenseMode = 0;
		break;
	}

	error = gnsdk_manager_initialize(&sManagerHandle, license, licenseMode);
	if (!error) 
		_gnsdk_internal::manager_release();

	if (error) { throw  GnError(); }
}


/*-----------------------------------------------------------------------------
 *  GlobalIdMagic
 */
gnsdk_cstr_t
GnManager::GlobalIdMagic()
{
	return gnsdk_manager_get_globalid_magic();
}


/*-----------------------------------------------------------------------------
 *  UserRegister
 */
GnString
GnManager::UserRegister(GnUserRegisterMode registerMode, gnsdk_cstr_t clientId, gnsdk_cstr_t clientTag, gnsdk_cstr_t applicationVersion) throw (GnError)
{
	gnsdk_str_t   serializedUser = GNSDK_NULL;
	gnsdk_error_t error          = SDKMGRERR_InvalidArg;

	switch (registerMode)
	{
	case kUserRegisterModeOnline:
		error = gnsdk_manager_user_register(GNSDK_USER_REGISTER_MODE_ONLINE, clientId, clientTag, applicationVersion, &serializedUser);
		break;

	case kUserRegisterModeLocalOnly:
		error = gnsdk_manager_user_register(GNSDK_USER_REGISTER_MODE_LOCALONLY, clientId, clientTag, applicationVersion, &serializedUser);
		break;

	default:
		break;
	}
	if (error) { throw GnError(); }

	return GnString::manage(serializedUser);
}


/*----------------------------------------------------------------------------r
 *  QueryCacheStore
 */
GnStoreOps&
GnManager::QueryCacheStore()
{
	return querycachestore_;
}


/*-----------------------------------------------------------------------------
 *  LocalesStore
 */
GnStoreOps&
GnManager::LocalesStore()
{
	return localestore_;
}


/*-----------------------------------------------------------------------------
 *  ContentCacheStore
 */
GnStoreOps&
GnManager::ContentCacheStore()
{
	return contentcachestore_;
}


GnStoreOps&
GnManager::TempCacheStore()
{
	return tempcachestore_;
}


/*-----------------------------------------------------------------------------
 *  SystemEventHandler
 */
void
GnManager::SystemEventHandler(IGnSystemEvents* pEventHandler)
{
	eventHandler_ = GnManagedPtr<IGnSystemEvents*>(pEventHandler, GnManagedPtr<IGnSystemEvents*>::ptr_nomanage);
}


/*-----------------------------------------------------------------------------
 *  SystemEventHandler
 */
void
GnManager::SystemEventHandler(GnManagedPtr<IGnSystemEvents*> eventHandler)
{
	eventHandler_ = eventHandler;
}


/*-----------------------------------------------------------------------------
 *  _memory_warn_fn
 */
static void
_memory_warn_fn(gnsdk_void_t* p_arg, gnsdk_size_t cur_mem_size, gnsdk_size_t memory_warn_size)
{
	GnManager* me = (GnManager*)p_arg;

	if (me->EventHandler())
	{
		me->EventHandler()->SystemMemoryWarning(cur_mem_size, memory_warn_size);
	}
}


/*-----------------------------------------------------------------------------
 *  SystemMemoryEvent
 */
void
GnManager::SystemMemoryEvent(gnsdk_size_t memoryWarnSize)
{
	gnsdk_manager_memory_warn(_memory_warn_fn, this, memoryWarnSize);
}


/*-----------------------------------------------------------------------------
 *  SystemMemoryCurrent
 */
gnsdk_size_t
GnManager::SystemMemoryCurrent()
{
	gnsdk_size_t current = 0;

	gnsdk_manager_internals(GNSDK_INTERNALS_OP_MEMORY_HEAP, &current, GNSDK_NULL, GNSDK_FALSE);

	return current;
}


/*-----------------------------------------------------------------------------
 *  SystemMemoryHighWater
 */
gnsdk_size_t
GnManager::SystemMemoryHighWater(gnsdk_bool_t bResetHighWater)
{
	gnsdk_size_t highwater = 0;

	gnsdk_manager_internals(GNSDK_INTERNALS_OP_MEMORY_HEAP, GNSDK_NULL, &highwater, bResetHighWater);

	return highwater;
}


/*-----------------------------------------------------------------------------
 *  TestGracenoteConnection
 */
void
GnManager::TestGracenoteConnection(const GnUser& user) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_test_gracenote_connection(user.native());
	if (error) { throw GnError(); }
}


/******************************************************************************
 *  GnStoreOps
 */

/*-----------------------------------------------------------------------------
 *  Location
 */
void
GnStoreOps::Location(gnsdk_cstr_t location) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_storage_location_set(cachetype_, location);
	if (error) { throw GnError(); }
}

/*-----------------------------------------------------------------------------
 *  Location
 */
void
GnStoreOps::FileSize(gnsdk_uint32_t size_in_kb) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_storage_filesize_set(cachetype_, size_in_kb);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  Cleanup
 */
void
GnStoreOps::Cleanup(bool bAsync) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_storage_cleanup(cachetype_, bAsync ? GNSDK_TRUE : GNSDK_FALSE);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  Compact
 */
void
GnStoreOps::Compact(bool bAsync) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_storage_compact(cachetype_, bAsync ? GNSDK_TRUE : GNSDK_FALSE);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  Flush
 */
void
GnStoreOps::Flush(bool bAsync) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_storage_flush(cachetype_, bAsync ? GNSDK_TRUE : GNSDK_FALSE);
	if (error) { throw GnError(); }
}


/******************************************************************************
** GnAssetFetch
*/

static void GNSDK_CALLBACK_API
asset_fetch_callback_status(
	void*          callback_data,
	gnsdk_status_t status,
	gnsdk_uint32_t percent_complete,
	gnsdk_size_t   bytes_total_sent,
	gnsdk_size_t   bytes_total_received,
	gnsdk_bool_t*  p_abort
	);

GnAssetFetch::GnAssetFetch(const GnUser& user, gnsdk_cstr_t url, IGnStatusEvents* pEventHandler) throw (GnError) :
	p_data_(GNSDK_NULL), size_(0)
{
	eventHandler_ = GnManagedPtr<IGnStatusEvents*>(pEventHandler, GnManagedPtr<IGnStatusEvents*>::ptr_nomanage);
	create(user, url);
}


GnAssetFetch::GnAssetFetch(const GnUser& user, gnsdk_cstr_t url, GnManagedPtr<IGnStatusEvents*> eventHandler) throw (GnError) :
	p_data_(GNSDK_NULL), size_(0)
{
	eventHandler_ = eventHandler;
	create(user, url);
}


GnAssetFetch::GnAssetFetch(const GnUser& user, gnsdk_cstr_t url, GnLookupMode lookupMode, IGnStatusEvents* pEventHandler) throw (GnError) :
	p_data_(GNSDK_NULL), size_(0)
{
	eventHandler_ = GnManagedPtr<IGnStatusEvents*>(pEventHandler, GnManagedPtr<IGnStatusEvents*>::ptr_nomanage);
	create2(user, url, lookupMode);
}


GnAssetFetch::GnAssetFetch(const GnUser& user, gnsdk_cstr_t url, GnLookupMode lookupMode, GnManagedPtr<IGnStatusEvents*> eventHandler) throw (GnError) :
	p_data_(GNSDK_NULL), size_(0)
{
	eventHandler_ = eventHandler;
	create2(user, url, lookupMode);
}


GnAssetFetch::~GnAssetFetch()
{
	gnsdk_manager_buffer_free(p_data_);
}


/*-----------------------------------------------------------------------------
 *  create
 */
void
GnAssetFetch::create(const GnUser& user, gnsdk_cstr_t url) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_asset_fetch(url, user.native(), asset_fetch_callback_status, this, &p_data_, &size_, &type_);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  create2
 */
void
GnAssetFetch::create2(const GnUser& user, gnsdk_cstr_t url, GnLookupMode lookupMode) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_asset_fetch2(url, gnconvert::gn_lookup_mode_to_string(lookupMode), user.native(), asset_fetch_callback_status, this, &p_data_, &size_, &type_);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  asset_fetch_callback_status
 */
void GNSDK_CALLBACK_API
asset_fetch_callback_status(void* callback_data, gnsdk_status_t fetch_status, gnsdk_uint32_t percent_complete, gnsdk_size_t bytes_total_sent, gnsdk_size_t bytes_total_received, gnsdk_bool_t* p_abort)
{
	GnAssetFetch* p_asset_fetch = (GnAssetFetch*)callback_data;

	if (p_asset_fetch->EventHandler())
	{
		gn_canceller canceller;

		p_asset_fetch->EventHandler()->StatusEvent((GnStatus)fetch_status, percent_complete, bytes_total_sent, bytes_total_received, canceller);
		if (canceller.IsCancelled())
		{
			*p_abort = GNSDK_TRUE;
		}
	}
}


/*-----------------------------------------------------------------------------
 *  _list_update_callback
 */
static gnsdk_void_t GNSDK_CALLBACK_API
_list_update_callback(void* callback_data, gnsdk_list_handle_t list_handle)
{
	GnManager* me = (GnManager*)callback_data;

	if (me->EventHandler())
	{
		GnList gnList(list_handle);
		me->EventHandler()->ListUpdateNeeded(gnList);
	}
}


/*-----------------------------------------------------------------------------
 *  _locale_update_callback
 */
void GNSDK_CALLBACK_API
_locale_update_callback(void* callback_data, gnsdk_locale_handle_t locale_handle)
{
	GnManager* me = (GnManager*)callback_data;

	if (me->EventHandler())
	{
		GnLocale gnLocale(locale_handle);
		me->EventHandler()->LocaleUpdateNeeded(gnLocale);
	}
}


/*-----------------------------------------------------------------------------
 *  module_initialize
 */
void
_gnsdk_internal::module_initialize(gnsdk_uint32_t moduleId) throw (GnError)
{
	gnsdk_error_t error;

	switch (moduleId)
	{
#if GNSDK_MUSICID
	case GNSDK_MODULE_MUSICID:
		if (!( sModulesInit & GNSDK_MODULE_MUSICID ) )
		{
			error = gnsdk_musicid_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_MUSICID;
		}
		break;
#endif

#if GNSDK_DSP
	case GNSDK_MODULE_DSP:
		if (!( sModulesInit & GNSDK_MODULE_DSP ) )
		{
			error = gnsdk_dsp_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_DSP;
		}
		break;
#endif

#if GNSDK_MUSICID_FILE
	case GNSDK_MODULE_MUSICIDFILE:
		if (!( sModulesInit & GNSDK_MODULE_MUSICIDFILE ) )
		{
			error = gnsdk_musicidfile_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_MUSICIDFILE;
		}
		break;
#endif

#if GNSDK_MUSICID_STREAM
	case GNSDK_MODULE_MUSICIDSTREAM:
		if (!( sModulesInit & GNSDK_MODULE_MUSICIDSTREAM ) )
		{
			error = gnsdk_musicidstream_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_MUSICIDSTREAM;
		}
		break;
#endif

#if GNSDK_RADIOID
	case GNSDK_MODULE_RADIOID:
		if (!( sModulesInit & GNSDK_MODULE_RADIOID ) )
		{
			error = gnsdk_radioid_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_RADIOID;
		}
		break;
#endif		

#if GNSDK_LINK
	case GNSDK_MODULE_LINK:
		if (!( sModulesInit & GNSDK_MODULE_LINK ) )
		{
			error = gnsdk_link_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_LINK;
		}
		break;
#endif

#if GNSDK_MUSICID_MATCH
	case GNSDK_MODULE_MUSICIDMATCH:
		if (!( sModulesInit & GNSDK_MODULE_MUSICIDMATCH ) )
		{
			error = gnsdk_musicidmatch_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_MUSICIDMATCH;
		}
		break;
#endif

#if GNSDK_STORAGE_SQLITE
	case GNSDK_MODULE_STORAGE_SQLITE:
		if (!( sModulesInit & GNSDK_MODULE_STORAGE_SQLITE ) )
		{
			error = gnsdk_storage_sqlite_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_STORAGE_SQLITE;
		}
		break;
#endif

#if GNSDK_STORAGE_QNX
	case GNSDK_MODULE_STORAGE_QNX:
		if (!( sModulesInit & GNSDK_MODULE_STORAGE_QNX) )
		{
			error = gnsdk_storage_qnx_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_STORAGE_QNX;
		}
		break;
#endif

#if GNSDK_LOOKUP_LOCAL
	case GNSDK_MODULE_LOOKUP_LOCAL:
		if (!( sModulesInit & GNSDK_MODULE_LOOKUP_LOCAL ) )
		{
			error = gnsdk_lookup_local_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_LOOKUP_LOCAL;
		}
		break;
#endif

#if GNSDK_LOOKUP_MANAGED
	case GNSDK_MODULE_LOOKUP_MANAGED:
		if (!( sModulesInit & GNSDK_MODULE_LOOKUP_MANAGED ) )
		{
			error = gnsdk_lookup_managed_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_LOOKUP_MANAGED;
		}
		break;
#endif

#if GNSDK_LOOKUP_FPLOCAL
	case GNSDK_MODULE_LOOKUP_FPLOCAL:
		if (!( sModulesInit & GNSDK_MODULE_LOOKUP_FPLOCAL ) )
		{
			error = gnsdk_lookup_fplocal_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_LOOKUP_FPLOCAL;
		}
		break;
#endif

#if GNSDK_LOOKUP_LOCALSTREAM
	case GNSDK_MODULE_LOOKUP_LOCALSTREAM:
		if (!( sModulesInit & GNSDK_MODULE_LOOKUP_LOCALSTREAM ) )
		{
			error = gnsdk_lookup_localstream_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_LOOKUP_LOCALSTREAM;
		}
		break;
#endif

#if GNSDK_SUBMIT
	case GNSDK_MODULE_SUBMIT:
		if (!( sModulesInit & GNSDK_MODULE_SUBMIT ) )
		{
			error = gnsdk_submit_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_SUBMIT;
		}
		break;
#endif

#if GNSDK_VIDEO
	case GNSDK_MODULE_VIDEO:
		if (!( sModulesInit & GNSDK_MODULE_VIDEO ) )
		{
			error = gnsdk_video_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_VIDEO;
		}
		break;
#endif

#if GNSDK_PLAYLIST
	case GNSDK_MODULE_PLAYLIST:
		if (!( sModulesInit & GNSDK_MODULE_PLAYLIST ) )
		{
			error = gnsdk_playlist_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_PLAYLIST;
		}
		break;
#endif

#if GNSDK_MOODGRID
	case GNSDK_MODULE_MOODGRID:
		if (!( sModulesInit & GNSDK_MODULE_MOODGRID ) )
		{
			error = gnsdk_moodgrid_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_MOODGRID;
		}
		break;
#endif

#if GNSDK_ACR
	case GNSDK_MODULE_ACR:
		if (!( sModulesInit & GNSDK_MODULE_ACR ) )
		{
			error = gnsdk_acr_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_ACR;
		}
		break;
#endif

#if GNSDK_CORRELATES
	case GNSDK_MODULE_CORRELATES:
		if (!( sModulesInit & GNSDK_MODULE_CORRELATES ) )
		{
			error = gnsdk_correlates_initialize(sManagerHandle);
			if (error) { throw GnError(); }

			sModulesInit |= GNSDK_MODULE_CORRELATES;
		}
		break;

#endif

#if GNSDK_EPG
	case GNSDK_MODULE_EPG:
		if (!( sModulesInit & GNSDK_MODULE_EPG ) )
		{
			error = gnsdk_epg_initialize(sManagerHandle);
			if (error) { throw GnError(); }
			sModulesInit |= GNSDK_MODULE_EPG;
		}
		break;

#endif

#if GNSDK_TASTEPROFILE
	case GNSDK_MODULE_TASTEPROFILE:
		if (!( sModulesInit & GNSDK_MODULE_TASTEPROFILE ) )
		{
			error = gnsdk_tasteprofile_initialize(sManagerHandle);
			if (error) { throw GnError(); }
			sModulesInit |= GNSDK_MODULE_TASTEPROFILE;
		}
		break;

#endif

#if GNSDK_TASTE
	case GNSDK_MODULE_TASTE:
		if (!( sModulesInit & GNSDK_MODULE_TASTE ) )
		{
			error = gnsdk_taste_initialize(sManagerHandle);
			if (error) { throw GnError(); }
			sModulesInit |= GNSDK_MODULE_TASTE;
		}
		break;

#endif

#if GNSDK_RHYTHM
	case GNSDK_MODULE_RHYTHM:
		if (!( sModulesInit & GNSDK_MODULE_RHYTHM ) )
		{
			error = gnsdk_rhythm_initialize(sManagerHandle);
			if (error) { throw GnError(); }
			sModulesInit |= GNSDK_MODULE_RHYTHM;
		}
		break;

#endif

	default:
		break;
	}
}


/*-----------------------------------------------------------------------------
 *  manager_initialized
 */
bool
_gnsdk_internal::manager_initialized()
{
	return sInitialized;
}


/*-----------------------------------------------------------------------------
 *  manager_addref
 */
void
_gnsdk_internal::manager_addref()
{
	manager_init_inc();
}


/*-----------------------------------------------------------------------------
 *  manager_release
 */
void
_gnsdk_internal::manager_release()
{
	gnsdk_uint32_t init_count;

	init_count = manager_init_dec();
	if (init_count == 0)
	{
		/* manager is shutdown */
		sModulesInit = 0;
		sInitialized = false;
	}
}

