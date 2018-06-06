/*
 * Copyright (c) 2000-2016 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/*
 *  Name: musicid_persist_results
 *  Description:
 *  This example demonstrates persisting MusicID query results for future (re)lookups.
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

/**********************************************
 *    Local Function Declarations
 **********************************************/
static int
_init_gnsdk(
	const char*				client_id,
	const char*				client_id_tag,
	const char*				client_app_version,
	const char*				license_path,
	int						use_local,
	gnsdk_user_handle_t*	p_user_handle
	);

static void
_shutdown_gnsdk(
	gnsdk_user_handle_t		user_handle
	);

static void
_do_sample_query_and_persist_result(
	gnsdk_user_handle_t		user_handle,
	int						use_local
	);

#define GRACENOTE_PRODUCTION_DATABASE                     "production_database"
#define GRACENOTE_PRODUCTION_DATABASE_LOCATION            "../../sample_data/gdb"

#define RESULT_DATABASE                                   "result_database"
#define RESULT_DATABASE_LOCATION                          "."

/* If Image (Asset) retrieval is available (check Gracenote License),
 * uncomment the #define below or set CFLAGS=-GRACENOTE_ASSET_FETCH_ENABLED
 */
/*   #define GRACENOTE_ASSET_FETCH_ENABLED   1 */

typedef struct query_result_s
{
    gnsdk_gdo_handle_t  match_gdo;
    gnsdk_gdo_handle_t  asset_gdo;
    gnsdk_byte_t*       asset_image_buf;
    gnsdk_size_t        asset_image_size;
} query_result_t;

/******************************************************************
 *
 *    MAIN
 *
 ******************************************************************/
int
main( int argc, char* argv[] )
{
	gnsdk_user_handle_t     user_handle			= GNSDK_NULL;
	const char*             client_id			= NULL;
	const char*             client_id_tag		= NULL;
	const char*             client_app_version	= "1.0.0.0"; /* Version of your application */
	const char*             license_path		= NULL;
	int                     use_local			= -1;
	int                     rc					= 0;

	if (argc == 5)
	{
		client_id     = argv[1];
		client_id_tag = argv[2];
		license_path  = argv[3];
		
        if ( !strcmp(argv[4], "online") )
		{
			use_local = 0;
		}
		else if ( !strcmp(argv[4], "local") )
		{
			use_local = 1;
		}

		/* GNSDK initialization */
		if ( use_local != -1 )
		{
			rc = _init_gnsdk(
                    client_id,
                    client_id_tag,
                    client_app_version,
                    license_path,
                    use_local,
                    &user_handle
                    );
			if ( 0 == rc )
			{
				/* Look up the provided text inputs simulating mp3s and persist the results */
				_do_sample_query_and_persist_result(
                    user_handle,
                    use_local
                    );

			   /* Clean up and shutdown */
				_shutdown_gnsdk( user_handle );
			}
		}
	}
	if ( argc != 5 || use_local == -1 )
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
	const char*				client_id,
	const char*				client_id_tag,
	const char*				client_app_version,
	int						use_local,
	gnsdk_user_handle_t*	p_user_handle
	)
{
	gnsdk_user_handle_t	user_handle					= GNSDK_NULL;
	gnsdk_cstr_t		user_reg_mode				= GNSDK_NULL;
	gnsdk_str_t			serialized_user				= GNSDK_NULL;
	gnsdk_char_t		serialized_user_buf[1024]	= {0};
	gnsdk_bool_t		b_localonly					= GNSDK_FALSE;
	gnsdk_error_t		error						= GNSDK_SUCCESS;
	FILE*				file						= NULL;
	int					rc							= 0;
	
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
		error = gnsdk_manager_user_create( serialized_user_buf, client_id, &user_handle );
		if (GNSDK_SUCCESS == error)
		{
			error = gnsdk_manager_user_is_localonly( user_handle, &b_localonly );
			if (!b_localonly || (strcmp(user_reg_mode, GNSDK_USER_REGISTER_MODE_LOCALONLY) == 0))
			{
				*p_user_handle = user_handle;
				return 0;
			}
			
			/* else desired regmode is online, but user is localonly - discard and register new online user */
			gnsdk_manager_user_release( user_handle );
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
		error = gnsdk_manager_user_create( serialized_user, client_id, &user_handle );
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
		
		gnsdk_manager_string_free( serialized_user );
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
	gnsdk_error_t		error			= GNSDK_SUCCESS;
	gnsdk_gdo_handle_t	db_info_gdo		= GNSDK_NULL;
	gnsdk_str_t			db_info_xml		= GNSDK_NULL;
	
	error = gnsdk_lookupdatabase_info_get( db_identifier, &db_info_gdo );
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_manager_gdo_render(db_info_gdo, GNSDK_GDO_RENDER_XML, &db_info_xml);
		if (GNSDK_SUCCESS == error)
		{
			/* To see detailed information about the Lookup Database, enable this:
			printf("\nGracenote DB Info:\n%s\n", db_info_xml);
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
_open_local_db(
	gnsdk_cstr_t            db_identfier_id,
	gnsdk_cstr_t            gracenote_db_path,
	gnsdk_cstr_t            access_mode
	)
{
	gnsdk_error_t			error			= GNSDK_SUCCESS;
	gnsdk_config_handle_t	config_handle	= GNSDK_NULL;
	int						rc				= 0;

	error = gnsdk_config_create( &config_handle );
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		rc = -1;
	}
	else
	{
		error = gnsdk_config_value_set(config_handle, GNSDK_CONFIG_LOOKUPDATABASE_ALL_LOCATION, gracenote_db_path);
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
					error = gnsdk_config_value_set(config_handle, GNSDK_CONFIG_LOOKUPDATABASE_ACCESS, access_mode);
					if (GNSDK_SUCCESS != error)
					{
						_display_last_error(__LINE__);
						rc = -1;
					}
					else
					{
						/* Open the database and assign it an ID for use by your application */
						error = gnsdk_lookupdatabase_open( db_identfier_id, config_handle );
						if (GNSDK_SUCCESS != error)
						{
							_display_last_error(__LINE__);
							rc = -1;
						}
						else
						{
							/* Display information about our local EDB */
							_display_local_db_info( db_identfier_id );
						}
					}
				}
			}
		}

		gnsdk_config_release( config_handle );
	}
	
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
	gnsdk_error_t	error	= GNSDK_SUCCESS;
	int				rc		= 0;

	error = gnsdk_manager_logging_enable(
                "sample.log",									/* Log file path */
                GNSDK_LOG_PKG_ALL,								/* Include entries for all packages and subsystems */
                GNSDK_LOG_LEVEL_ERROR|GNSDK_LOG_LEVEL_WARNING,	/* Include only error and warning entries */
                GNSDK_LOG_OPTION_ALL,							/* All logging options: timestamps, thread IDs, etc */
                0,												/* Max size of log: 0 means a new log file will be created each run */
                GNSDK_FALSE										/* GNSDK_TRUE = old logs will be renamed and saved */
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
	gnsdk_locale_handle_t	locale_handle	= GNSDK_NULL;
	gnsdk_error_t			error			= GNSDK_SUCCESS;
	int						rc				= 0;

    /* Set the location of Gracenote Lists DB */
	error = gnsdk_manager_storage_location_set( GNSDK_MANAGER_STORAGE_LISTS, GRACENOTE_PRODUCTION_DATABASE_LOCATION );
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_manager_locale_load(
                    GNSDK_LOCALE_GROUP_MUSIC,		/* Locale group */
                    GNSDK_LANG_ENGLISH,				/* Language */
                    GNSDK_REGION_DEFAULT,			/* Region */
                    GNSDK_DESCRIPTOR_SIMPLIFIED,	/* Descriptor */
                    user_handle,					/* User handle */
                    GNSDK_NULL,						/* User callback function */
                    0,								/* Optional data for user callback function */
                    &locale_handle );				/* Return handle */

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
	const char*				client_id,
	const char*				client_id_tag,
	const char*				client_app_version,
	const char*				license_path,
	int						use_local,
	gnsdk_user_handle_t*	p_user_handle
	)
{
	gnsdk_manager_handle_t	sdkmgr_handle       = GNSDK_NULL;
	gnsdk_error_t			error               = GNSDK_SUCCESS;
	gnsdk_user_handle_t		user_handle         = GNSDK_NULL;
	int						rc                  = 0;

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
		error = gnsdk_storage_sqlite_initialize( sdkmgr_handle );
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
			rc = -1;
		}
	}

	/* Initialize the Lookup Local Library */
	if (0 == rc)
	{
		error = gnsdk_lookup_local_initialize( sdkmgr_handle );
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
			rc = -1;
		}
	}

	/* Open storage database for reading and writing (online and/or local) query responses */
	if (0 == rc)
	{
		rc = _open_local_db(
                RESULT_DATABASE,
                RESULT_DATABASE_LOCATION,
                GNSDK_LOOKUPDATABASE_ACCESS_READ_WRITE
                );
	}

	if (1 == use_local)
	{
		/* Open the base local database for querying. */
		if (0 == rc)
		{
			rc = _open_local_db(
                    GRACENOTE_PRODUCTION_DATABASE,
                    GRACENOTE_PRODUCTION_DATABASE_LOCATION,
                    GNSDK_LOOKUPDATABASE_ACCESS_READ_ONLY
                    );
		}
	}

	/* Initialize the MusicID Library */
	if (0 == rc)
	{
		error = gnsdk_musicid_initialize( sdkmgr_handle );
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
		rc = _set_locale( user_handle );
	}

	if (0 != rc)
	{
		/* Clean up on failure. */
		_shutdown_gnsdk( user_handle );
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
	gnsdk_user_handle_t     user_handle
	)
{
	gnsdk_error_t	error	= GNSDK_SUCCESS;

	error = gnsdk_manager_user_release( user_handle );
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
	}

	/* Shutdown the Manager to shutdown all libraries */
	gnsdk_manager_shutdown();

}  /* _shutdown_gnsdk() */


/***************************************************************************
 *
 *    _DISPLAY_ALBUM_GDO
 *
 *      Display attributes contained in an Album object.
 *
 ***************************************************************************/
static void
_display_album_gdo(
	gnsdk_gdo_handle_t	album_gdo
	)
{
	gnsdk_error_t		error		= GNSDK_SUCCESS;
	gnsdk_gdo_handle_t	title_gdo	= GNSDK_NULL;
	gnsdk_cstr_t		value		= GNSDK_NULL;

	/* Album Title */
	error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_TITLE_OFFICIAL, 1, &title_gdo );
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_manager_gdo_value_get( title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value );
		if (GNSDK_SUCCESS == error)
		{
			printf( "%16s %s\n", "Title:", value );
		}
		else
		{
			_display_last_error(__LINE__);
		}
		gnsdk_manager_gdo_release( title_gdo );
	}
	else
	{
		_display_last_error(__LINE__);
	}

	printf( "\n" );
}  /* _display_album_gdo() */


/***************************************************************************
 *
 *    _DISPLAY_CONTRIB_GDO
 *      
 *      Display attributes contained in a Contributer object.
 *
 ***************************************************************************/
static void
_display_contrib_gdo(
	gnsdk_gdo_handle_t	contrib_gdo
	)
{
	gnsdk_error_t		error		= GNSDK_SUCCESS;
	gnsdk_gdo_handle_t	name_gdo	= GNSDK_NULL;
	gnsdk_cstr_t		value		= GNSDK_NULL;

	/* Contributor Name */
	error = gnsdk_manager_gdo_child_get( contrib_gdo, GNSDK_GDO_CHILD_NAME_OFFICIAL, 1, &name_gdo );
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_manager_gdo_value_get( name_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value );
		if (GNSDK_SUCCESS == error)
		{
			printf( "%16s %s\n", "Name:", value );
		}
		else
		{
			_display_last_error(__LINE__);
		}
		gnsdk_manager_gdo_release( name_gdo );
	}
	else
	{
		_display_last_error(__LINE__);
	}

}  /* _display_contrib_gdo() */


/***************************************************************************
 *
 *    _DISPLAY_MATCH_GDO
 *
 *      Check if returned match object is an Album or Contributor object
 *
 ***************************************************************************/
static void
_display_match_gdo(
	gnsdk_gdo_handle_t match_gdo
	)
{
	gnsdk_error_t	error		= GNSDK_SUCCESS;
	gnsdk_cstr_t	gdo_type	= GNSDK_NULL;

	error = gnsdk_manager_gdo_get_type( match_gdo, &gdo_type );
	if (GNSDK_SUCCESS == error)
	{
        if (0 == strcmp(gdo_type, GNSDK_GDO_TYPE_ALBUM))
        {
            _display_album_gdo(match_gdo);
        }
        else if (0 == strcmp(gdo_type, GNSDK_GDO_TYPE_CONTRIBUTOR))
        {
            _display_contrib_gdo(match_gdo);
        }
        else
        {
            printf("\nUnsupported match GDO type: %s\n", gdo_type);
        }
	}
	else
	{
        _display_last_error(__LINE__);
	}

}  /* _display_match_gdo() */


/***************************************************************************
 *
 *    _DO_MATCH_SELECTION
 *
 *      Help select from match(es)
 *
 ***************************************************************************/
static gnsdk_uint32_t
_do_match_selection(gnsdk_gdo_handle_t	response_gdo)
{
	/*
	   This is where any matches that need resolution/disambiguation are iterated
	   and a single selection of the best match is made.

	   For this simplified sample, we'll just echo the matches and select the first match.
	 */

    gnsdk_error_t		error		= GNSDK_SUCCESS;
    gnsdk_gdo_handle_t	match_gdo	= GNSDK_NULL;
    gnsdk_uint32_t		count		= 0;
    gnsdk_uint32_t		ordinal		= 0;
    
    error = gnsdk_manager_gdo_child_count( response_gdo, GNSDK_GDO_CHILD_MATCH, &count );
    if (GNSDK_SUCCESS == error)
    {
        printf( "%16s %d\n", "Match count:", count);
        /*	Note that the GDO accessors below are *ordinal* based, not index based.  so the 'first' of
         *	anything has a one-based ordinal of '1' - *not* an index of '0'
         */
        for (ordinal = 1; ordinal <= count; ordinal++)
        {
            /* Get the match GDO */
            error = gnsdk_manager_gdo_child_get( response_gdo, GNSDK_GDO_CHILD_MATCH, ordinal, &match_gdo );
            if (GNSDK_SUCCESS == error)
            {
                _display_match_gdo(match_gdo);
                
                /* Release the current match */
                gnsdk_manager_gdo_release(match_gdo);
                match_gdo = GNSDK_NULL;
            }
            else
            {
                _display_last_error(__LINE__);
            }
        }
    }
    else
    {
        _display_last_error(__LINE__);
    }

	return 1;

}  /* _do_match_selection() */

/***************************************************************************
 *
 *    _DO_MATCH_SELECTION_AND_GET_FULL_RESPONSE_MATCH
 *
 *      Inspects a response object and returns a single, full match object.
 *
 ***************************************************************************/
/* Response management */
static gnsdk_error_t
_do_match_selection_and_get_full_response_match(
	gnsdk_musicid_query_handle_t	query_handle,
	gnsdk_gdo_handle_t				response_gdo,
	gnsdk_gdo_handle_t*				p_response_match_gdo
	)
{
	gnsdk_error_t		error					= GNSDK_SUCCESS;
	gnsdk_uint32_t		choice_ordinal			= 0;
	gnsdk_cstr_t		needs_decision			= GNSDK_NULL;
	gnsdk_cstr_t		is_full					= GNSDK_NULL;
	gnsdk_gdo_handle_t	match_gdo				= GNSDK_NULL;
	gnsdk_gdo_handle_t	followup_response_gdo	= GNSDK_NULL;

	/* we have at least one match, see if disambiguation (match resolution) is necessary. */
	error = gnsdk_manager_gdo_value_get(
                response_gdo,
                GNSDK_GDO_VALUE_RESPONSE_NEEDS_DECISION,
                1,
                &needs_decision
                );
	if (GNSDK_SUCCESS == error)
	{
		/* See if selection of one of the matches needs to happen */
		if (0 == strcmp(needs_decision, GNSDK_VALUE_TRUE))
		{
			choice_ordinal = _do_match_selection( response_gdo );
		}
		else
		{
			/* no need for disambiguation, we'll take the first match */
			choice_ordinal = 1;
		}
		error = gnsdk_manager_gdo_child_get(
                    response_gdo,
                    GNSDK_GDO_CHILD_MATCH,
                    choice_ordinal,
                    &match_gdo
                    );
		if (GNSDK_SUCCESS == error)
		{
            /* See if the match has full data or only partial data. */
            error = gnsdk_manager_gdo_value_get(
                        match_gdo,
						GNSDK_GDO_VALUE_FULL_RESULT,
						1,
						&is_full
						);
            if (GNSDK_SUCCESS == error)
            {
                /* if we only have a partial result, we do a follow-up query to retrieve the full match */
                if (0 == strcmp(is_full, GNSDK_VALUE_FALSE))
                {
                    /* do followup query to get full object. Setting the partial object as the query input. */
                    error = gnsdk_musicid_query_set_gdo( query_handle, match_gdo );
                    if (GNSDK_SUCCESS == error)
                    {
                        /* we can now release the partial object */
                        gnsdk_manager_gdo_release( match_gdo );
                        match_gdo = GNSDK_NULL;
                        
                        /* Non-full results only supported for albums, so we can use find_albums. */
                        error = gnsdk_musicid_query_find_albums( query_handle, &followup_response_gdo );
                        if (GNSDK_SUCCESS == error)
                        {
                            /* now our first album is the desired result with full data */
                            error = gnsdk_manager_gdo_child_get(
                                        followup_response_gdo,
										GNSDK_GDO_CHILD_ALBUM,
										1,
										&match_gdo
										);
                            if (GNSDK_SUCCESS != error)
                            {
                                _display_last_error(__LINE__);
                            }
                            /* Release the followup query's response object */
                            gnsdk_manager_gdo_release( followup_response_gdo );
                        }
                        else
                        {
                            _display_last_error(__LINE__);
                        }
					}
					else
					{
						_display_last_error(__LINE__);
					}
				}
			}
			else
			{
				_display_last_error(__LINE__);
			}
		}
        else
        {
            _display_last_error(__LINE__);
        }
	}
	else
	{
		_display_last_error(__LINE__);
	}

	if (GNSDK_SUCCESS == error)
	{
		/* We should now have our final, full match result. */
		printf( "%16s\n", "Final match:");
		_display_match_gdo( match_gdo );
	}
    else
    {
        gnsdk_manager_gdo_release( match_gdo );
    }
    
    *p_response_match_gdo = match_gdo;
    
	return error;
}

/***************************************************************************
 *
 *    _QUERY_TEXT_INPUT_FIELDS_ADD
 *
 *      Adds input text fields in to a MusicID query handle.
 *
 ***************************************************************************/
static gnsdk_error_t
_query_add_input_text_fields(
	gnsdk_musicid_query_handle_t	query_handle
	)
{
	gnsdk_error_t	error		= GNSDK_SUCCESS;
    gnsdk_cstr_t	album_title	= "Nevermind"; /* Sample test inputs */
    gnsdk_cstr_t	track_title	= "Smells Like Teen Spirit";
    gnsdk_cstr_t	artist_name	= "Nirvana";

	if (album_title != GNSDK_NULL)
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

	if ((GNSDK_SUCCESS == error) && (artist_name != GNSDK_NULL))
	{
		error = gnsdk_musicid_query_set_text( query_handle, GNSDK_MUSICID_FIELD_TRACK_ARTIST, artist_name );
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
		}
		printf( "%-15s: %s\n", "artist name", artist_name );
	}

	return error;
}

#if GRACENOTE_ASSET_FETCH_ENABLED
/***************************************************************************
 *
 *    _DO_CONTENT_LOOKUP
 *
 *      Help select from match(es)
 *
 ***************************************************************************/
static gnsdk_error_t
_do_content_lookup(
    gnsdk_gdo_handle_t	match_gdo,
    gnsdk_gdo_handle_t* p_asset_gdo,
    gnsdk_cstr_t*       p_asset_url
    )
{
    gnsdk_error_t		error               = GNSDK_SUCCESS;
    gnsdk_gdo_handle_t  content_gdo         = GNSDK_NULL;
    gnsdk_gdo_handle_t  asset_gdo           = GNSDK_NULL;
    gnsdk_uint32_t		content_ordinal		= 0;
    gnsdk_uint32_t      asset_ordinal       = 0;
    gnsdk_cstr_t        content_type        = GNSDK_NULL;
    gnsdk_cstr_t        asset_url           = GNSDK_NULL;
    
    /* For simplicity let's select first content object returned */
    content_ordinal = 1;
    
	error = gnsdk_manager_gdo_child_get(match_gdo, GNSDK_GDO_CHILD_CONTENT, content_ordinal, &content_gdo);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
	}
	else
	{
		error = gnsdk_manager_gdo_value_get(content_gdo, GNSDK_GDO_VALUE_CONTENT_TYPE, 1, &content_type);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
		}
		else
		{
			printf("Content Type: %s\t", content_type);

			/* For simplicity let's take the first asset */
			asset_ordinal = 1;

			error = gnsdk_manager_gdo_child_get(content_gdo, GNSDK_GDO_CHILD_ASSET, asset_ordinal, &asset_gdo);
			if (GNSDK_SUCCESS != error)
			{
				_display_last_error(__LINE__);
			}
			else
			{
				error = gnsdk_manager_gdo_value_get(asset_gdo, GNSDK_GDO_VALUE_ASSET_URL_GNSDK, 1, &asset_url);			
				if (GNSDK_SUCCESS != error)
				{ 
					_display_last_error(__LINE__);
				}
			}
		}

		/* Release the current match */
		gnsdk_manager_gdo_release( content_gdo );
		content_gdo = GNSDK_NULL;
	} 
    
    if (GNSDK_SUCCESS != error)
    {
        /* Release the asset gdo */
        gnsdk_manager_gdo_release( asset_gdo );
        content_gdo = GNSDK_NULL;
    }
    
    *p_asset_gdo = asset_gdo;
    *p_asset_url = asset_url;
    
    return error;
    
}  /* _do_content_lookup() */
#endif

/***************************************************************************
 *
 *    _DO_MUSICID_LOOKUP
 *
 *      MusicID Text Query
 *
 ***************************************************************************/
static gnsdk_error_t
_do_musicid_lookup(
    gnsdk_musicid_query_handle_t    query_handle,
    gnsdk_user_handle_t             user_handle,
    int                             use_local,
    query_result_t*                 p_query_result
    )
{
    gnsdk_error_t		error                   = GNSDK_SUCCESS;
    gnsdk_gdo_handle_t	response_gdo            = GNSDK_NULL;
    gnsdk_gdo_handle_t  match_candidate_gdo     = GNSDK_NULL;
    gnsdk_gdo_handle_t  asset_gdo               = GNSDK_NULL;
    gnsdk_uint32_t		match_candidate_count   = 0;
    
    /* Set the input text */
    error = _query_add_input_text_fields( query_handle );
    if (GNSDK_SUCCESS != error)
    {
        _display_last_error(__LINE__);
    }
    
#if GRACENOTE_ASSET_FETCH_ENABLED
    if (GNSDK_SUCCESS == error)
    {
        error = gnsdk_musicid_query_option_set(
                    query_handle,
                    GNSDK_MUSICID_OPTION_ENABLE_CONTENT_DATA,
                    GNSDK_VALUE_TRUE
                    );
        if (GNSDK_SUCCESS != error)
        {
            _display_last_error(__LINE__);
        }
    }
    
    if (GNSDK_SUCCESS == error)
    {
        error = gnsdk_musicid_query_option_set(
                    query_handle,
                    GNSDK_MUSICID_OPTION_RESULT_PREFER_COVERART,
                    GNSDK_VALUE_TRUE
                    );
        if (GNSDK_SUCCESS != error)
        {
            _display_last_error(__LINE__);
        }
    }
#endif
    
    if (GNSDK_SUCCESS == error)
    {
        /* Set lookup mode */
        /* Let's try a local lookup first */
        
        error = gnsdk_musicid_query_option_set(
                    query_handle,
                    GNSDK_MUSICID_OPTION_LOOKUP_MODE,
                    GNSDK_LOOKUP_MODE_LOCAL
                    );
        if (GNSDK_SUCCESS != error)
        {
            _display_last_error(__LINE__);
        }
    }

    if (GNSDK_SUCCESS == error)
    {
        /* Perform query */
        error = gnsdk_musicid_query_find_matches( query_handle, &match_candidate_gdo );
        if (GNSDK_SUCCESS != error)
        {
            _display_last_error(__LINE__);
        }
    }
    
    if (GNSDK_SUCCESS == error)
    {
        /* Check if we have a match */
        error = gnsdk_manager_gdo_child_count(
                    match_candidate_gdo,
                    GNSDK_GDO_CHILD_MATCH,
                    &match_candidate_count
                    );
        if (GNSDK_SUCCESS == error)
        {
            if (0 == match_candidate_count)
            {
                gnsdk_manager_gdo_release(match_candidate_gdo);
                match_candidate_gdo = GNSDK_NULL;
                
                if (0 == use_local)
                {
                    /* No results found locally, let's try an online query */
                    error = gnsdk_musicid_query_option_set(
                                query_handle,
                                GNSDK_MUSICID_OPTION_LOOKUP_MODE,
                                GNSDK_LOOKUP_MODE_ONLINE_NOCACHE
                                );
                    if (GNSDK_SUCCESS == error)
                    {
                        /* Perform query */
                        error = gnsdk_musicid_query_find_matches( query_handle, &match_candidate_gdo );
                        if (GNSDK_SUCCESS == error)
                        {
                            /* Check if we have a match */
                            error = gnsdk_manager_gdo_child_count(
                                        match_candidate_gdo,
                                        GNSDK_GDO_CHILD_MATCH,
                                        &match_candidate_count
                                        );
                            if (GNSDK_SUCCESS != error)
                            {
                                _display_last_error(__LINE__);
                            }
                        }
                        else
                        {
                            _display_last_error(__LINE__);
                        }
                    }
                    else
                    {
                        _display_last_error(__LINE__);
                    }
                }
            }
        }
        else
        {
            _display_last_error(__LINE__);
        }
    }
    
    if (GNSDK_SUCCESS == error)
    {
        if (0 != match_candidate_count)
        {
            printf("\nMatch candidate(s) found for the input.\n");
            
            /* We found a match(es), see if we need any follow-up queries or */
            /* disambiguation needed before we can persist a chosen match */
            error = _do_match_selection_and_get_full_response_match(
                            query_handle,
                            match_candidate_gdo,
                            &response_gdo
                            );
#if GRACENOTE_ASSET_FETCH_ENABLED            
            if (GNSDK_SUCCESS == error)
            {
				gnsdk_cstr_t    asset_url = GNSDK_NULL;

                error = _do_content_lookup(
                            response_gdo,
                            &asset_gdo,
                            &asset_url
                            );
                
                if (GNSDK_SUCCESS == error)
                {
                    /* Let's fetch art work */
                    error = gnsdk_manager_asset_fetch2(
                                asset_url,
								use_local ? GNSDK_LOOKUP_MODE_LOCAL : GNSDK_LOOKUP_MODE_ONLINE_NOCACHE,
                                user_handle,
                                GNSDK_NULL,
                                GNSDK_NULL,
                                &p_query_result->asset_image_buf,
                                &p_query_result->asset_image_size,
                                GNSDK_NULL
                                );
                    if (GNSDK_SUCCESS != error)
                    {
                        _display_last_error(__LINE__);
                    }
                }
                else
                {
                    printf("\nNo assets found for the input.\n");
                }
            }
#else
			/* quiet unused param warning */
			GNSDK_UNUSED(user_handle);
#endif
        }
        else
        {
            printf("\nNo matches found for the input.\n");
        }
    }

    /* Clean up */
    gnsdk_manager_gdo_release( match_candidate_gdo );
    
	if(GNSDK_SUCCESS == error)
	{
		p_query_result->match_gdo = response_gdo;
		p_query_result->asset_gdo = asset_gdo;
	}
	else
	{
		gnsdk_manager_gdo_release( response_gdo );
		gnsdk_manager_gdo_release( asset_gdo );
	}
    
    return error;
}

/***************************************************************************
 *
 *    _DO_SAMPLE_QUERY_AND_PERSIST_RESULT
 *
 *      Performs a local/online lookup and persists result in Gracenote R/W Lookup DataBase.
 *
 ***************************************************************************/
static void
_do_sample_query_and_persist_result(
	gnsdk_user_handle_t     user_handle,
	int                     local_only
)
{
	gnsdk_error_t					error           = GNSDK_SUCCESS;
	gnsdk_musicid_query_handle_t	query_handle    = GNSDK_NULL;
    query_result_t                  query_result	= {0};
    
    printf("\n*****MusicID Query*****\n");
    
	/* Create the query handle */
	error = gnsdk_musicid_query_create(
		user_handle,
		GNSDK_NULL,		/* User callback function */
		GNSDK_NULL,		/* Optional data to be passed to the callback */
		&query_handle
		);
    if (GNSDK_SUCCESS != error)
    {
        _display_last_error(__LINE__);
    }
    
	if (GNSDK_SUCCESS == error)
	{
        error = _do_musicid_lookup(
                    query_handle,
                    user_handle,
                    local_only,
                    &query_result
                    );
    }
    
    if (GNSDK_SUCCESS == error)
    {
        if (GNSDK_NULL != query_result.match_gdo)
        {
           /* -- Persist the match's metadata --
            *  Note: You can omit adding the match's record (metadata) to the local database if you only want to
            *  persist its image assets to be retrieved later for the same associated match from online.
            */
            error = gnsdk_lookupdatabase_record_add( RESULT_DATABASE, query_result.match_gdo );
            if (GNSDK_SUCCESS == error)
            {
				printf("\nMatch successfully added to the persistent lookup database.\n");
            }
            else
            {
                _display_last_error(__LINE__);
            }
        }
        
#if GRACENOTE_ASSET_FETCH_ENABLED
        if (GNSDK_NULL != query_result.asset_gdo &&
            0 != query_result.asset_image_size)
        {
            /* -- Persist image asset --
             * Note: if the album is an online match whose image assets might have been added to
			 * the local database previously (without the corresponding record),
			 * the local image url can still be retrieved via gnsdk_manager_gdo_value_get(asset_gdo, GNSDK_GDO_VALUE_ASSET_URL_GNSDK,...)
			 * Caveat: where no local image exists, this call returns a non-empty url
			 * that results in an error (GNSDKERR_Unsupported) when fetched.
			 */
            error = gnsdk_lookupdatabase_image_add(
                        RESULT_DATABASE,
                        query_result.asset_image_buf,
                        query_result.asset_image_size,
                        query_result.asset_gdo
                        );
            if (GNSDK_SUCCESS == error)
            {
                printf("\nAsset successfully added to the persistent lookup database.\n");
            }
            else
            {
                _display_last_error(__LINE__);
            }
        }
        
        /* Clean up */
        gnsdk_manager_buffer_free( query_result.asset_image_buf );
#endif
    }

    /* Clean up */
	gnsdk_manager_gdo_release( query_result.asset_gdo );
    gnsdk_manager_gdo_release( query_result.match_gdo );
    gnsdk_musicid_query_release( query_handle );

}
