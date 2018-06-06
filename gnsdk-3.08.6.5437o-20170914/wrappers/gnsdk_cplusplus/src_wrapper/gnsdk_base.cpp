/*
 * Copyright (c) 2000-2016 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/* gnsdk.cpp
 *
 * Implementation of C++ wrapper for GNSDK
 *
 */

#include "gnsdk_base.hpp"
#include "gnsdk_list.hpp"
#include "gnsdk_locale.hpp"
#include "gnsdk_manager.hpp"
#include "gnsdk_convert.hpp"

using namespace gracenote;

static void GNSDK_CALLBACK_API
_user_store_callback(gnsdk_void_t* callback_data, gnsdk_cstr_t client_id, gnsdk_cstr_t serialized_user);


/******************************************************************************
** GnUser
*/
GnUser::GnUser(gnsdk_cstr_t serializedUser, gnsdk_cstr_t clientIdTest) throw (GnError)
{
	gnsdk_user_handle_t user = GNSDK_NULL;
	gnsdk_error_t       error;

	error = gnsdk_manager_user_create(serializedUser, clientIdTest, &user);
	if (error) { throw GnError(); }

	options_.weakhandle_ = user;

	assign(user);
}

/* deprecated, remove in future release*/
GnUser::GnUser(IGnUserStore& userStore, gnsdk_cstr_t clientId, gnsdk_cstr_t clientTag, gnsdk_cstr_t appVersion) throw (GnError)
{
	userStore_ = GnManagedPtr<IGnUserStore*>(&userStore, GnManagedPtr<IGnUserStore*>::ptr_nomanage);

	create(clientId, clientTag, appVersion);
}

GnUser::GnUser(gnsdk_cstr_t clientId, gnsdk_cstr_t clientTag, gnsdk_cstr_t appVersion, IGnUserStore* userStore) throw (GnError)
{
	userStore_ = GnManagedPtr<IGnUserStore*>(userStore, GnManagedPtr<IGnUserStore*>::ptr_nomanage);

	create(clientId, clientTag, appVersion);
}
#ifndef SWIG
GnUser::GnUser(gnsdk_cstr_t clientId, gnsdk_cstr_t clientTag, gnsdk_cstr_t appVersion, GnManagedPtr<IGnUserStore*> userStore) throw (GnError)
{
	userStore_ = userStore;

	create(clientId, clientTag, appVersion);
}
#endif

GnUser::~GnUser()
{
}


/*-----------------------------------------------------------------------------
 *  create
 */
void
GnUser::create(gnsdk_cstr_t clientId, gnsdk_cstr_t clientTag, gnsdk_cstr_t appVersion) throw (GnError)
{
	gnsdk_user_handle_t user           = GNSDK_NULL;
	gnsdk_str_t         serializedUser = GNSDK_NULL;
	gnsdk_error_t       error          = SDKMGRWARN_NotFound;
	GnError             e;

	if ( GNSDK_NULL == clientId )
	{
		throw GnError(GNSDKERR_InvalidArg,"Invalid Client ID provided: null");
	}
	if ( userStore_.IsNull() )
	{
		throw GnError(GNSDKERR_InvalidArg, "Invalid IGnUserStore provided: null");
	}

	/* try to create from stored user */
	GnString storedUserData = userStore_->LoadSerializedUser(clientId);
	if (!storedUserData.IsEmpty())
	{
		error = gnsdk_manager_user_create(storedUserData, clientId, &user);
	}

	/* if did not deserialize user, or existing user is not for current clientId */
	if (error)
	{
		/* create local-only user for now, but set auto-register */
		error = gnsdk_manager_user_register(GNSDK_USER_REGISTER_MODE_LOCALONLY, clientId, clientTag, appVersion, &serializedUser);
		if (!error)
		{
			error = gnsdk_manager_user_create(serializedUser, clientId, &user);
			if (error)
			{
				e = GnError();
			}

			gnsdk_manager_string_free(serializedUser);
		}
		else
		{
			e = GnError();
		}
	}

	/* always set autoreg callback on created user */
	if (!error)
	{
		error = gnsdk_manager_user_set_autoregister(user, _user_store_callback, userStore_.native());
		if (error)
		{
			e = GnError();
		}
	}

	if (error)
	{
		gnsdk_manager_user_release(user);
		throw e;
	}

	options_.weakhandle_ = user;

	assign(user);
}


/*-----------------------------------------------------------------------------
 *  _user_store_callback
 */
static void GNSDK_CALLBACK_API
_user_store_callback(gnsdk_void_t* callback_data, gnsdk_cstr_t client_id, gnsdk_cstr_t serialized_user)
{
	IGnUserStore* userStore = (IGnUserStore*)callback_data;

	userStore->StoreSerializedUser(client_id, serialized_user);
}


/*-----------------------------------------------------------------------------
 *  IsLocalOnly
 */
bool
GnUser::IsLocalOnly() const throw (GnError)
{
	gnsdk_bool_t	b_local_only = GNSDK_FALSE;
	gnsdk_error_t	error;

	error = gnsdk_manager_user_is_localonly(native(), &b_local_only);
	if (error) { throw GnError(); }

	if (b_local_only)
		return true;

	return false;
}


/******************************************************************************
** GnUserOptions

GnUserOptions::GnUserOptions(const GnUserOptions& options)
{
	this->weakhandle_ = options.weakhandle_;
}

GnUserOptions&
GnUserOptions::operator=(const GnUserOptions& options)
{
	this->weakhandle_ = options.weakhandle_;
	return *this;
}
*/
/*-----------------------------------------------------------------------------
 *  LookupMode
 */
GnLookupMode
GnUserOptions::LookupMode() throw (GnError)
{
	gnsdk_cstr_t  option_value = GNSDK_NULL;
	gnsdk_error_t	error;

	error = gnsdk_manager_user_option_get(weakhandle_, GNSDK_USER_OPTION_LOOKUP_MODE, &option_value);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

	return gnconvert::gn_lookup_mode_to_enum(option_value);
}


/*-----------------------------------------------------------------------------
 *  LookupMode
 */
void
GnUserOptions::LookupMode(GnLookupMode lookupMode) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_LOOKUP_MODE, gnconvert::gn_lookup_mode_to_string(lookupMode));
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }
	}


/*-----------------------------------------------------------------------------
 *  NetworkProxy
 */
gnsdk_cstr_t
GnUserOptions::NetworkProxy() throw (GnError)
{
	gnsdk_cstr_t	value;
	gnsdk_error_t	error;

	error = gnsdk_manager_user_option_get(weakhandle_, GNSDK_USER_OPTION_PROXY_HOST, &value);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

	return value;
}


/*-----------------------------------------------------------------------------
 *  NetworkProxy
 */
void
GnUserOptions::NetworkProxy(gnsdk_cstr_t hostName, gnsdk_cstr_t userName, gnsdk_cstr_t password) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_PROXY_HOST, hostName);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_PROXY_PASS, password);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_PROXY_USER, userName);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  NetworkTimeout
 */
gnsdk_uint32_t
GnUserOptions::NetworkTimeout() throw (GnError)
{
	gnsdk_cstr_t	value;
	gnsdk_error_t	error;
	
	error = gnsdk_manager_user_option_get(weakhandle_, GNSDK_USER_OPTION_NETWORK_TIMEOUT, &value);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

	return gnstd::gn_atoi(value);
}


/*-----------------------------------------------------------------------------
 *  NetworkTimeout
 */
void
GnUserOptions::NetworkTimeout(gnsdk_uint32_t timeoutMs) throw (GnError)
{
	gnsdk_char_t	buf[32];
	gnsdk_error_t	error;
	
	gnstd::gn_itoa(buf, sizeof(buf), timeoutMs);
	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_NETWORK_TIMEOUT, buf);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  NetworkLoadBalance
 */
bool
GnUserOptions::NetworkLoadBalance() throw (GnError)
{
	gnsdk_cstr_t	value;
	gnsdk_error_t	error;
	
	error = gnsdk_manager_user_option_get(weakhandle_, GNSDK_USER_OPTION_NETWORK_LOADBALANCE, &value);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

	return gnstd::gn_strtobool(value);
}


/*-----------------------------------------------------------------------------
 *  NetworkLoadBalance
 */
void
GnUserOptions::NetworkLoadBalance(bool bEnable) throw (GnError)
{
	gnsdk_error_t error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_NETWORK_LOADBALANCE, bEnable ? "Y" : "N");
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  UserInfo
 */
gnsdk_cstr_t
GnUserOptions::NetworkInterface() throw (GnError)
{
	gnsdk_cstr_t	intfName = gnstd::kEmptyString;
	gnsdk_error_t	error;

	error = gnsdk_manager_user_option_get(weakhandle_, GNSDK_USER_OPTION_NETWORK_INTERFACE, &intfName);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

	return intfName;
}


/*-----------------------------------------------------------------------------
 *  NetworkInterface
 */
void
GnUserOptions::NetworkInterface(gnsdk_cstr_t intfName) throw (GnError)
{
	gnsdk_error_t	error;

	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_NETWORK_INTERFACE, intfName);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  UserInfo
 */
void
GnUserOptions::UserInfo(gnsdk_cstr_t locationId, gnsdk_cstr_t mfg, gnsdk_cstr_t os, gnsdk_cstr_t uId) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_LOCATION_ID, locationId);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_INFO_MFG, mfg);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_INFO_OS, os);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }
	
	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_INFO_RAWUID, uId);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  DeveloperUserID
 */
void
GnUserOptions::DeveloperUserID(gnsdk_cstr_t devUserId) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_INFO_DEVELOPER_USER_ID, devUserId);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  DeveloperUserID
 */
void
GnUserOptions::AdID(gnsdk_cstr_t adId, bool optOut) throw (GnError)
{
	gnsdk_error_t error;

	if(true == optOut)
	{
		error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_INFO_AD_ID_OPT_OUT, adId);
	}
	else
	{
		error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_INFO_AD_ID_OPT_IN, adId);
	}

	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 * DeviceModel 
 */
void
GnUserOptions::DeviceModel(gnsdk_cstr_t model) throw (GnError)
{
	gnsdk_error_t	error;

	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_INFO_MODEL, model);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  DeviceModel
 */
gnsdk_cstr_t
GnUserOptions::DeviceModel() throw (GnError)
{
	gnsdk_cstr_t	&model = gnstd::kEmptyString;
	gnsdk_error_t	error;


	error = gnsdk_manager_user_option_get(weakhandle_, GNSDK_USER_OPTION_INFO_MODEL, &model);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

	return model;
}


/*-----------------------------------------------------------------------------
 *  CacheExpiration
 */
gnsdk_uint32_t
GnUserOptions::CacheExpiration() throw (GnError)
{
	gnsdk_cstr_t	value;
	gnsdk_error_t	error;
	
	error = gnsdk_manager_user_option_get(weakhandle_, GNSDK_USER_OPTION_CACHE_EXPIRATION, &value);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

	return gnstd::gn_atoi(value);
}


/*-----------------------------------------------------------------------------
 *  CacheExpiration
 */
void
GnUserOptions::CacheExpiration(gnsdk_uint32_t durationSec) throw (GnError)
{
	gnsdk_char_t	buf[32];
	gnsdk_error_t	error;
	
	gnstd::gn_itoa(buf, sizeof(buf), durationSec);
	error = gnsdk_manager_user_option_set(weakhandle_, GNSDK_USER_OPTION_CACHE_EXPIRATION, buf);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  Custom
 */
gnsdk_cstr_t
GnUserOptions::Custom(gnsdk_cstr_t key) throw (GnError)
{
	gnsdk_cstr_t	value;
	gnsdk_error_t	error;
	
	error = gnsdk_manager_user_option_get(weakhandle_, key, &value);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

	return value;
}


/*-----------------------------------------------------------------------------
 *  Custom
 */
void
GnUserOptions::Custom(gnsdk_cstr_t key, gnsdk_cstr_t value) throw (GnError)
{
	gnsdk_error_t error;
	
	error = gnsdk_manager_user_option_set(weakhandle_, key, value);
	if (GNSDKERR_SEVERE(error) ) { throw GnError(); }
}
