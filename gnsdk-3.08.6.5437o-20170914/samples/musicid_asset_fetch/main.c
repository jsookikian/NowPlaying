/*
 * Copyright (c) 2000-2016 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/*
 *  Name: musicid_asset_fetch
 *  Description:
 *  Download content via Gracenote asset fetch interface.
 *
 *  Command-line Syntax:
 *  sample <client_id> <client_id_tag> <license> [local|online]
 */

/* GNSDK headers
 *
 * Define the modules your application needs.
 * These constants enable inclusion of headers and symbols in gnsdk.h.
 * Define GNSDK_LOOKUP_LOCAL because this program has the potential to do local queries.
 * For local queries, a Gracenote local database must be present.
 */
#define GNSDK_MUSICID               1
#define GNSDK_STORAGE_SQLITE        1
#define GNSDK_LOOKUP_LOCAL          1

#include "gnsdk.h"

/* Standard C headers - used by the sample app, but not required for GNSDK */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LOOKUP_DATABASE_SAMPLE_ID			"lookup_database_sample_id"

#define LOOKUP_DATABASE_SAMPLE_LOCATION		"../../sample_data/gdb"

/**********************************************
 *    Local Function Declarations
 **********************************************/
static int
_init_gnsdk(
	const char*          client_id,
	const char*          client_id_tag,
	const char*          client_app_version,
	const char*          license_path,
	int                  use_local,
	gnsdk_user_handle_t* p_user_handle
	);

static void
_shutdown_gnsdk(
	gnsdk_user_handle_t user_handle
	);

static void
_do_sample_album_search(
	gnsdk_user_handle_t user_handle,
	int					use_local,
	gnsdk_cstr_t        album_title,
	gnsdk_cstr_t        track_title,
	gnsdk_cstr_t        track_artist
	);

/******************************************************************
 *
 *    MAIN
 *
 ******************************************************************/
int
main( int argc, char* argv[] )
{
	gnsdk_user_handle_t user_handle        = GNSDK_NULL;
	const char*         client_id          = NULL;
	const char*         client_id_tag      = NULL;
	const char*         client_app_version = "1.0.0.0"; /* Version of your application */
	const char*         license_path       = NULL;
	int                 use_local          = -1;
	int                 rc                 = 0;
	
	if (argc == 5)
	{
		client_id     = argv[1];
		client_id_tag = argv[2];
		license_path  = argv[3];
		if (!strcmp(argv[4], "online"))
		{
			use_local = 0;
		}
		else if (!strcmp(argv[4], "local"))
		{
			use_local = 1;
		}
		
		/* GNSDK initialization */
		if (use_local != -1)
		{
			rc = _init_gnsdk(
				client_id,
				client_id_tag,
				client_app_version,
				license_path,
				use_local,
				&user_handle
			);
			if (0 == rc)
			{
				/*	Find Albums: Album Title, Track Title, Track Artist	*/
				_do_sample_album_search( user_handle, use_local, "Supernatural", "Africa Bamba", "Santana" );
				
				/* Clean up and shutdown */
				_shutdown_gnsdk( user_handle );
			}
		}
	}
	if (argc != 5 || use_local == -1)
	{
		printf( "\nUsage:\n%s clientid clientidtag license [local|online]\n", argv[0] );
		rc = -1;
	}
	
	return rc;
	
}  /* main() */

/******************************************************************
 *
 *    _DISPLAY_LAST_ERROR
 *
 *    Echo the error and information.
 *
 *****************************************************************/
static void
_display_last_error(
	int line_num
	)
{
	/* Get the last error information from the SDK */
	const gnsdk_error_info_t* error_info = gnsdk_manager_error_info();
	
	/* Error_info will never be GNSDK_NULL.
	 * The SDK will always return a pointer to a populated error info structure.
	 */
	printf(
		"\nerror from: %s()  [on line %d]\n\t0x%08x %s\n",
		error_info->error_api,
		line_num,
		error_info->error_code,
		error_info->error_description
	);
	
} /* _display_last_error() */

/******************************************************************
 *
 *    _GET_USER_HANDLE
 *
 *    Load existing user handle, or register new one.
 *
 *    GNSDK requires a user handle instance to perform queries.
 *    User handles encapsulate your Gracenote provided Client ID
 *    which is unique for your application. User handles are
 *    registered once with Gracenote then must be saved by
 *    your application and reused on future invocations.
 *
 *****************************************************************/
static int
_get_user_handle(
	const char*          client_id,
	const char*          client_id_tag,
	const char*          client_app_version,
	int                  use_local,
	gnsdk_user_handle_t* p_user_handle
	)
{
	gnsdk_user_handle_t user_handle               = GNSDK_NULL;
	gnsdk_cstr_t		user_reg_mode             = GNSDK_NULL;
	gnsdk_str_t         serialized_user           = GNSDK_NULL;
	gnsdk_char_t		serialized_user_buf[1024] = {0};
	gnsdk_bool_t        b_localonly               = GNSDK_FALSE;
	gnsdk_error_t       error                     = GNSDK_SUCCESS;
	FILE*               file                      = NULL;
	int                 rc                        = 0;
	
	/* Creating a GnUser is required before performing any queries to Gracenote services,
	 * and such APIs in the SDK require a GnUser to be provided. GnUsers can be created
	 * 'Online' which means they are created by the Gracenote backend and fully vetted.
	 * Or they can be create 'Local Only' which means they are created locally by the
	 * SDK but then can only be used locally by the SDK.
	 */
	
	/* If the application cannot go online at time of user-regstration it should
	 * create a 'local only' user. If connectivity is available, an Online user should
	 * be created. An Online user can do both Local and Online queries.
	 */
	if (use_local)
	{
		user_reg_mode = GNSDK_USER_REGISTER_MODE_LOCALONLY;
	}
	else
	{
		user_reg_mode = GNSDK_USER_REGISTER_MODE_ONLINE;
	}
	
	/* Do we have a user saved locally? */
	file = fopen("user.txt", "r");
	if (file)
	{
		fgets(serialized_user_buf, sizeof(serialized_user_buf), file);
		fclose(file);
		
		/* Create the user handle from the saved user */
		error = gnsdk_manager_user_create(serialized_user_buf, client_id, &user_handle);
		if (GNSDK_SUCCESS == error)
		{
			error = gnsdk_manager_user_is_localonly(user_handle, &b_localonly);
			if (!b_localonly || (strcmp(user_reg_mode, GNSDK_USER_REGISTER_MODE_LOCALONLY) == 0))
			{
				*p_user_handle = user_handle;
				return 0;
			}
			
			/* else desired regmode is online, but user is localonly - discard and register new online user */
			gnsdk_manager_user_release(user_handle);
		}
		
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
		}
	}
	else
	{
		printf("\nInfo: No stored user - this must be the app's first run.\n");
	}
	
	/*
	 * Register new user
	 */
	error = gnsdk_manager_user_register(
		user_reg_mode,
		client_id,
		client_id_tag,
		client_app_version,
		&serialized_user
	);
	if (GNSDK_SUCCESS == error)
	{
		/* Create the user handle from the newly registered user */
		error = gnsdk_manager_user_create(serialized_user, client_id, &user_handle);
		if (GNSDK_SUCCESS == error)
		{
			/* save newly registered user for use next time */
			file = fopen("user.txt", "w");
			if (file)
			{
				fputs(serialized_user, file);
				fclose(file);
			}
		}
		
		gnsdk_manager_string_free(serialized_user);
	}
	
	if (GNSDK_SUCCESS == error)
	{
		*p_user_handle = user_handle;
		rc = 0;
	}
	else
	{
		_display_last_error(__LINE__);
		rc = -1;
	}
	
	return rc;
	
} /* _get_user_handle() */

/******************************************************************
 *
 *    _DISPLAY_LOCAL_DB_INFO
 *
 *    Display local Gracenote DB information.
 *
 ******************************************************************/
static void
_display_local_db_info(gnsdk_cstr_t db_identifier)
{
	gnsdk_error_t		error = GNSDK_SUCCESS;
    gnsdk_gdo_handle_t  db_info_gdo		= GNSDK_NULL;
	gnsdk_str_t			db_info_xml		= GNSDK_NULL;

    error = gnsdk_lookupdatabase_info_get( db_identifier, &db_info_gdo );
    if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_manager_gdo_render(db_info_gdo, GNSDK_GDO_RENDER_XML, &db_info_xml);
		if (GNSDK_SUCCESS == error)
		{
			/* To see detailed information about the Lookup Database, enable this:
			printf("Gracenote DB Info:\n%s\n", db_info_xml);
			*/
			gnsdk_manager_string_free(db_info_xml);
		}
		gnsdk_manager_gdo_release(db_info_gdo);
	}
	else
	{
		_display_last_error(__LINE__);
	}
}  /* _display_local_db_info() */

/******************************************************************
 *
 *    _OPEN_LOCAL_DB
 *
 *    Open/Create Gracenote Lookup DB.
 *
 ******************************************************************/
static int
_open_local_db(void)
{
	gnsdk_error_t			error = GNSDK_SUCCESS;
	gnsdk_config_handle_t	config_handle = GNSDK_NULL;
	int						rc = 0;

	error = gnsdk_config_create(&config_handle);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		rc = -1;
	}
	else
	{
		error = gnsdk_config_value_set(config_handle, GNSDK_CONFIG_LOOKUPDATABASE_ALL_LOCATION, LOOKUP_DATABASE_SAMPLE_LOCATION);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
			rc = -1;
		}
		else
		{
			error = gnsdk_config_value_set(config_handle, GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID_TEXT, GNSDK_VALUE_TRUE);
			if (GNSDK_SUCCESS != error)
			{
				_display_last_error(__LINE__);
				rc = -1;
			}
			else				
			{
				error = gnsdk_config_value_set(config_handle, GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID_IMAGES, GNSDK_VALUE_TRUE);
				if (GNSDK_SUCCESS != error)
				{
					_display_last_error(__LINE__);
					rc = -1;
				}
				else				
				{
					/* Open the database and assign it an ID for use by your application */
					error = gnsdk_lookupdatabase_open(LOOKUP_DATABASE_SAMPLE_ID, config_handle);
					if (GNSDK_SUCCESS != error)
					{
						_display_last_error(__LINE__);
						rc = -1;
					}
					else
					{
						/* Display information about our local EDB */
						_display_local_db_info( LOOKUP_DATABASE_SAMPLE_ID );
					}
				}
			}
		}
		gnsdk_config_release(config_handle);
	}

	/* The database will be closed automatically at shutdown, but if your app
	wants to close it sooner, there is a gnsdk_lookupdatabase_close() API. */

	return rc;
}  /* _open_local_db() */

/******************************************************************
 *
 *    _DISPLAY_GNSDK_PRODUCT_INFO
 *
 *    Display product version information
 *
 ******************************************************************/
static void
_display_gnsdk_product_info(void)
{
	/* Display GNSDK Version infomation */
	printf(
		"\nGNSDK Product Version    : %s \t(built %s)\n",
		gnsdk_manager_get_product_version(),
		gnsdk_manager_get_build_date()
	);
}  /* _display_gnsdk_product_info() */

/******************************************************************
 *
 *    _ENABLE_LOGGING
 *
 *  Enable logging for the SDK. Not used by Sample App. This helps
 *  Gracenote debug your app, if necessary.
 *
 ******************************************************************/
static int
_enable_logging(void)
{
	gnsdk_error_t error = GNSDK_SUCCESS;
	int           rc    = 0;
	
	error = gnsdk_manager_logging_enable(
		"sample.log",                                           /* Log file path */
		GNSDK_LOG_PKG_ALL,                                      /* Include entries for all packages and subsystems */
		GNSDK_LOG_LEVEL_ERROR|GNSDK_LOG_LEVEL_WARNING,          /* Include only error and warning entries */
		GNSDK_LOG_OPTION_ALL,                                   /* All logging options: timestamps, thread IDs, etc */
		0,                                                      /* Max size of log: 0 means a new log file will be created each run */
		GNSDK_FALSE                                             /* GNSDK_TRUE = old logs will be renamed and saved */
	);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		rc = -1;
	}
	
	return rc;
	
}  /* _enable_logging() */

/*****************************************************************************
 *
 *    _SET_LOCALE
 *
 *  Set application locale. Note that this is only necessary if you are using
 *  locale-dependant fields such as genre, mood, origin, era, etc. Your app
 *  may or may not be accessing locale_dependent fields, but it does not hurt
 *  to do this initialization as a matter of course .
 *
 ****************************************************************************/
static int
_set_locale( gnsdk_user_handle_t user_handle )
{
	gnsdk_locale_handle_t locale_handle = GNSDK_NULL;
	gnsdk_error_t         error         = GNSDK_SUCCESS;
	int                   rc            = 0;

    /* Set the location of Gracenote Lists DB */
	error = gnsdk_manager_storage_location_set( GNSDK_MANAGER_STORAGE_LISTS, LOOKUP_DATABASE_SAMPLE_LOCATION );
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_manager_locale_load(
					GNSDK_LOCALE_GROUP_MUSIC,			/* Locale group */
					GNSDK_LANG_ENGLISH,					/* Language */
					GNSDK_REGION_DEFAULT,				/* Region */
					GNSDK_DESCRIPTOR_SIMPLIFIED,		/* Descriptor */
					user_handle,						/* User handle */
					GNSDK_NULL,							/* User callback function */
					0,									/* Optional data for user callback function */
					&locale_handle );					/* Return handle */

		if (GNSDK_SUCCESS == error)
		{
			/* Setting the 'locale' as default
			 * If default not set, no locale-specific results would be available
			 */
			error = gnsdk_manager_locale_set_group_default( locale_handle );
			if (GNSDK_SUCCESS != error)
			{
				_display_last_error(__LINE__);
				rc = -1;
			}

			/* The manager will hold onto the locale when set as default
			 * so it's ok to release our reference to it here
			 */
			gnsdk_manager_locale_release( locale_handle );
		}
		else
		{
			_display_last_error(__LINE__);
			rc = -1;
		}
	}
	else
	{
		_display_last_error(__LINE__);
		rc = -1;
	}

	return rc;
}  /* _set_locale() */

/****************************************************************************************
 *
 *    _INIT_GNSDK
 *
 *     Initializing the GNSDK is required before any other APIs can be called.
 *     First step is to always initialize the Manager module, then use the returned
 *     handle to initialize any modules to be used by the application.
 *
 *     For this sample, we also load a locale which is used by GNSDK to provide
 *     appropriate locale-sensitive metadata for certain metadata values. Loading of the
 *     locale is done here for sample convenience but can be done at anytime in your
 *     application.
 *
 ****************************************************************************************/
static int
_init_gnsdk(
	const char*          client_id,
	const char*          client_id_tag,
	const char*          client_app_version,
	const char*          license_path,
	int                  use_local,
	gnsdk_user_handle_t* p_user_handle
	)
{
	gnsdk_manager_handle_t sdkmgr_handle = GNSDK_NULL;
	gnsdk_error_t          error         = GNSDK_SUCCESS;
	gnsdk_user_handle_t    user_handle   = GNSDK_NULL;
	int                    rc            = 0;
	
	/* Display GNSDK Product Version Info */
	_display_gnsdk_product_info();
	
	/* Initialize the GNSDK Manager */
	error = gnsdk_manager_initialize(
		&sdkmgr_handle,
		license_path,
		GNSDK_MANAGER_LICENSEDATA_FILENAME
	);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		return -1;
	}
	
	/* Enable logging */
	if (0 == rc)
	{
		rc = _enable_logging();
	}
	
	/* Initialize the Storage SQLite Library */
	if (0 == rc)
	{
		error = gnsdk_storage_sqlite_initialize(sdkmgr_handle);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
			rc = -1;
		}
	}
	
	if (use_local)
	{
		/* Initialize the Lookup Local Library */
		if (0 == rc)
		{
			error = gnsdk_lookup_local_initialize(sdkmgr_handle);
			if (GNSDK_SUCCESS != error)
			{
				_display_last_error(__LINE__);
				rc = -1;
			}
			else
			{
				/* Open the local database for querying. */
				rc = _open_local_db();
			}
		}
	}
	
	/* Initialize the MusicID Library */
	if (0 == rc)
	{
		error = gnsdk_musicid_initialize(sdkmgr_handle);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
			rc = -1;
		}
	}
	
	/* Get a user handle for our client ID.  This will be passed in for all queries */
	if (0 == rc)
	{
		rc = _get_user_handle(
			client_id,
			client_id_tag,
			client_app_version,
			use_local,
			&user_handle
		);
	}
	
	/* Set the user option to use our local Gracenote DB unless overridden. */
	if (use_local)
	{
		if (0 == rc)
		{
			error = gnsdk_manager_user_option_set(
				user_handle,
				GNSDK_USER_OPTION_LOOKUP_MODE,
				GNSDK_LOOKUP_MODE_LOCAL
			);
			if (GNSDK_SUCCESS != error)
			{
				_display_last_error(__LINE__);
				rc = -1;
			}
		}
	}
	
	/* Set the 'locale' to return locale-specifc results values. This examples loads an English locale. */
	if (0 == rc)
	{
		rc = _set_locale(user_handle);
	}
	
	if (0 != rc)
	{
		/* Clean up on failure. */
		_shutdown_gnsdk(user_handle);
	}
	else
	{
		/* return the User handle for use at query time */
		*p_user_handle = user_handle;
	}
	
	return rc;
	
}  /* _init_gnsdk() */

/***************************************************************************
 *
 *    _SHUTDOWN_GNSDK
 *
 *     When your program is terminating, or you no longer need GNSDK, you should
 *     call gnsdk_manager_shutdown(). No other shutdown operations are required.
 *     gnsdk_manager_shutdown() also shuts down all other modules, regardless
 *     of the number of times they have been initialized.
 *     You can shut down individual modules while your program is running with
 *     their dedicated shutdown functions in order to free up resources.
 *
 ***************************************************************************/
static void
_shutdown_gnsdk(
	gnsdk_user_handle_t user_handle
	)
{
	gnsdk_error_t error = GNSDK_SUCCESS;
	
	error = gnsdk_manager_user_release(user_handle);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
	}
	
	/* Shutdown the Manager to shutdown all libraries */
	gnsdk_manager_shutdown();
	
}  /* _shutdown_gnsdk() */

/****************************************************************************
 *
 *    _DO_ASSET_FETCH_
 *
 *	Description: This function demonstrates	fetch asset from given query response
 *
 ****************************************************************************/
static void
_do_asset_fetch(
    gnsdk_user_handle_t	user_handle,
	int					use_local,
	gnsdk_gdo_handle_t	response_gdo
	)
{
	gnsdk_error_t       error         = GNSDK_SUCCESS;
	gnsdk_uint32_t      child_count   = 0;
	gnsdk_gdo_handle_t  content_gdo   = GNSDK_NULL;
	gnsdk_gdo_handle_t  asset_gdo     = GNSDK_NULL;
	gnsdk_cstr_t        url           = GNSDK_NULL;
	gnsdk_uint32_t      i             = 0;

	error = gnsdk_manager_gdo_child_get(response_gdo, GNSDK_GDO_CHILD_CONTENT_IMAGECOVER, 1, &content_gdo);
    if (GNSDK_SUCCESS != error)
    {
	    /*Some Albums may not have an associated cover art. Hence this is not an error*/
		return;
	}

    error = gnsdk_manager_gdo_child_count(content_gdo, GNSDK_GDO_CHILD_ASSET_SIZE_SMALL, &child_count);
    if (GNSDK_SUCCESS != error)
    {
        _display_last_error(__LINE__);
        return;
    }

    if (child_count > 0)
    {
        for ( i = 1; i <= child_count; i++) 
		{
			error = gnsdk_manager_gdo_child_get(content_gdo, GNSDK_GDO_CHILD_ASSET_SIZE_SMALL, i, &asset_gdo);
			if (GNSDK_SUCCESS != error)
			{
			  _display_last_error(__LINE__);
			  break;
			}

			error = gnsdk_manager_gdo_value_get(asset_gdo, GNSDK_GDO_VALUE_ASSET_URL_GNSDK, 1, &url);
			if ( GNSDK_SUCCESS == error)
			{
				gnsdk_byte_t* p_asset_data		= GNSDK_NULL;
				gnsdk_size_t  p_asset_data_size = 0;
				gnsdk_cstr_t  asset_data_type		= GNSDK_NULL;							 

				error = gnsdk_manager_asset_fetch2(url,
													use_local ? GNSDK_LOOKUP_MODE_LOCAL : GNSDK_LOOKUP_MODE_ONLINE_NOCACHE,
													user_handle,
													GNSDK_NULL,
													GNSDK_NULL,
													&p_asset_data,
													&p_asset_data_size,
													&asset_data_type);

				if (GNSDK_SUCCESS == error)
				{
						printf("\nSuccessfully Fetched CoverArt :\n\tAsset Data Type\t: %s\n\tAsset Url\t: %s\n\tAsset Size\t: %lu \n",
							asset_data_type, url, p_asset_data_size);

						gnsdk_manager_buffer_free(p_asset_data);
				} 
			}
			else
			{
				_display_last_error(__LINE__);
			}

			gnsdk_manager_gdo_release(asset_gdo);
        }
    }

    gnsdk_manager_gdo_release(content_gdo);

}

static void
_do_sample_album_search(
	gnsdk_user_handle_t user_handle,
	int					use_local,
	gnsdk_cstr_t        album_title,
	gnsdk_cstr_t        track_title,
	gnsdk_cstr_t        track_artist
	)
{
	gnsdk_error_t                error                 = GNSDK_SUCCESS;
	gnsdk_musicid_query_handle_t query_handle          = GNSDK_NULL;
	gnsdk_gdo_handle_t           response_gdo          = GNSDK_NULL;
	gnsdk_uint32_t               count                 = 0;
	gnsdk_uint32_t               i                     = 0;
	gnsdk_cstr_t                 content_enable        = "1";

	printf("\n*****Sample Album Search*****\n");

	/* Create the query handle */
	error = gnsdk_musicid_query_create(
				user_handle,
				GNSDK_NULL,          /* User callback function */
				GNSDK_NULL,          /* Optional data to be passed to the callback */
				&query_handle
				);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
	}

	error = gnsdk_musicid_query_option_set(query_handle, GNSDK_MUSICID_OPTION_ENABLE_CONTENT_DATA, content_enable);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
	}

	/*** Set the input text ****/
	if (GNSDK_SUCCESS == error)
	{
		if ((GNSDK_SUCCESS == error) && (album_title != GNSDK_NULL))
		{
			error = gnsdk_musicid_query_set_text( query_handle, GNSDK_MUSICID_FIELD_ALBUM, album_title );
			if (GNSDK_SUCCESS != error)
			{
				_display_last_error(__LINE__);
			}

			printf( "%-15s: %s\n", "album title", album_title );    /*	show the fields that we have set	*/
		}

		if ((GNSDK_SUCCESS == error) && (track_title != GNSDK_NULL))
		{
			error = gnsdk_musicid_query_set_text( query_handle, GNSDK_MUSICID_FIELD_TITLE, track_title );
			if (GNSDK_SUCCESS != error)
			{
				_display_last_error(__LINE__);
			}

			printf( "%-15s: %s\n", "track title", track_title );
		}

		if ((GNSDK_SUCCESS == error) && (track_artist != GNSDK_NULL))\
		{
			error = gnsdk_musicid_query_set_text( query_handle, GNSDK_MUSICID_FIELD_TRACK_ARTIST, track_artist );
			if (GNSDK_SUCCESS != error)
			{
				_display_last_error(__LINE__);
			}

			printf( "%-15s: %s\n", "artist name", track_artist );
		}
	}

	/* Perform the query */
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_musicid_query_find_albums(
			query_handle,
			&response_gdo
			);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
		}
	}

	/* See how many albums were found. */
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_manager_gdo_child_count(
			response_gdo,
			GNSDK_GDO_CHILD_ALBUM,
			&count
			);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
		}
	}

	/* See if we need any follow-up queries or disambiguation */
	if (GNSDK_SUCCESS == error)
	{
		if (count == 0)
		{
			printf("\nNo albums found for the input.\n");
		}
		else
		{
			for (i = 1 ; i <= count; i++)
			{
				 gnsdk_gdo_handle_t album_gdo = GNSDK_NULL;
				 error = gnsdk_manager_gdo_child_get(response_gdo,
													 GNSDK_GDO_CHILD_ALBUM,
													 i,
													 &album_gdo);
					 if (GNSDK_SUCCESS != error)
					 {
						 _display_last_error(__LINE__);
					 }
					 else
					 {
						 _do_asset_fetch(user_handle, use_local, album_gdo);
                   		 gnsdk_manager_gdo_release(album_gdo);
                   	 }

            }
		}
	}

	/* Clean up */
	gnsdk_musicid_query_release(query_handle);
	gnsdk_manager_gdo_release(response_gdo);
}
