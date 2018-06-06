/*
 * Copyright (c) 2000-2014 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/*
 *  Name: musicid_persist_and_manage
 *  Description:
 *  Stores query results in a results database to be available in future offline queries or after
 *  the local database is updated.
 *  Demonstrates management of result database size.
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
#include <sys/stat.h>

#ifdef _WIN32
    #include <windows.h>
#endif 

/**********************************************
 *    Local Function Declarations
 **********************************************/
static int
_init_gnsdk(
    const char*             client_id,
    const char*             client_id_tag,
    const char*             client_app_version,
    const char*             license_path,
    int                     use_local,
    gnsdk_user_handle_t*    p_user_handle
    );

static void
_shutdown_gnsdk(
    gnsdk_user_handle_t     user_handle
    );

static void
_do_sample_queries_and_persist_results(
    gnsdk_user_handle_t     user_handle,
	int						local_only
    );

#define GRACENOTE_PRODUCTION_DATABASE               "production_database"
#define GRACENOTE_PRODUCTION_DATABASE_LOCATION      "../../sample_data/gdb"

#define RESULT_DATABASE_A                           "result_database_a"
#define RESULT_DATABASE_A_LOCATION                  "result_database_a"

#define RESULT_DATABASE_B                           "result_database_b"
#define RESULT_DATABASE_B_LOCATION                  "result_database_b"

#define RESULT_STORE_ALLOCATION_SIZE_BYTES          36864

typedef struct g_lookup_database_s
{
    gnsdk_cstr_t            id;
    gnsdk_cstr_t            location;
    gnsdk_config_handle_t   config_handle;
    gnsdk_uint64_t          size;
} g_lookup_database_t;

/* Files used by this sample app */
typedef struct g_sample_input_s
{
    gnsdk_cstr_t artist_name;
    gnsdk_cstr_t album_title;
    gnsdk_cstr_t track_title;
} g_sample_input_t;

g_sample_input_t g_sample_input[] = {
    {"Coldplay",    "Viva La Vida",             "Death And All His Friends"},
    {"Adele",       "21",                       "Rumour Has It"},
    {"Santana",     "Supernatural",             "Africa Bamba"},
    {"Daft Punk",   "Random Access Memories",   "Get Lucky"},
    {"Adele",       "21",                       "Rolling in the Deep"},
    {"Sam Smith",   "In the Lonely Hour",       "Stay With Me"},
    {"Coldplay",    "Viva La Vida",             "Lost!"}
    };


/******************************************************************
 *
 *    MAIN
 *
 ******************************************************************/
int
main( int argc, char* argv[] )
{
    gnsdk_user_handle_t     user_handle         = GNSDK_NULL;
    const char*             client_id           = NULL;
    const char*             client_id_tag       = NULL;
    const char*             client_app_version  = "1.0.0.0"; /* Version of your application */
    const char*             license_path        = NULL;
    int                     local_only          = -1;
    int                     rc                  = 0;
    
    if (argc == 5)
    {
        client_id     = argv[1];
        client_id_tag = argv[2];
        license_path  = argv[3];
        
        if ( !strcmp(argv[4], "online") )
        {
            local_only = 0; /* ok to go online */
        }
        else if ( !strcmp(argv[4], "local") )
        {
            local_only = 1; /* do not go online */
        }
	}
    if ( argc != 5 || local_only == -1 )
    {
        printf( "\nUsage:\n%s clientid clientidtag license [local|online]\n", argv[0] );
        rc = -1;
    }

	if (rc == 0)
	{
        /* Create folders to hold result databases */
#ifdef _WIN32
        CreateDirectoryA(RESULT_DATABASE_A_LOCATION, NULL);
        CreateDirectoryA(RESULT_DATABASE_B_LOCATION, NULL);
#else
        mkdir(RESULT_DATABASE_A_LOCATION, 0777);
        mkdir(RESULT_DATABASE_B_LOCATION, 0777);
#endif
        
        /* GNSDK initialization */
        rc = _init_gnsdk(
                client_id,
                client_id_tag,
                client_app_version,
                license_path,
                local_only,
                &user_handle
                );
        if ( 0 == rc )
        {
            /* Process the text inputs simulating mp3s. */
            _do_sample_queries_and_persist_results( user_handle, local_only );
            
            /* Clean up and shutdown */
            _shutdown_gnsdk( user_handle );
        }
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
    const char*             client_id,
    const char*             client_id_tag,
    const char*             client_app_version,
    int                     use_local,
    gnsdk_user_handle_t*    p_user_handle
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
_display_local_db_info(
    gnsdk_cstr_t    db_identifier
    )
{
    gnsdk_error_t		error			= GNSDK_SUCCESS;
    gnsdk_gdo_handle_t	db_info_gdo		= GNSDK_NULL;
    gnsdk_str_t			db_info_xml		= GNSDK_NULL;
    
    error = gnsdk_lookupdatabase_info_get( db_identifier, &db_info_gdo );
    if (GNSDK_SUCCESS == error)
    {
        error = gnsdk_manager_gdo_render( db_info_gdo, GNSDK_GDO_RENDER_XML, &db_info_xml );
        if (GNSDK_SUCCESS == error)
        {
            /* To see detailed information about the Lookup Database, enable this:
             printf("Gracenote DB Info:\n%s\n", db_info_xml);
             */
            gnsdk_manager_string_free( db_info_xml );
        }
        gnsdk_manager_gdo_release( db_info_gdo );
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
static gnsdk_error_t
_open_local_db(
    gnsdk_cstr_t            db_identfier_id,
    gnsdk_cstr_t            gracenote_db_path,
    gnsdk_cstr_t            access_mode,
    gnsdk_config_handle_t*  p_db_config_handle
    )
{
    gnsdk_error_t			error			= GNSDK_SUCCESS;
    gnsdk_config_handle_t	config_handle	= GNSDK_NULL;
    
	error = gnsdk_config_create( &config_handle );
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
	}
	else
	{
		error = gnsdk_config_value_set(config_handle, GNSDK_CONFIG_LOOKUPDATABASE_ALL_LOCATION, gracenote_db_path);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
		}
		else
		{
			error = gnsdk_config_value_set(config_handle, GNSDK_CONFIG_LOOKUPDATABASE_ENABLE_MUSICID_TEXT, GNSDK_VALUE_TRUE);
			if (GNSDK_SUCCESS != error)
			{
				_display_last_error(__LINE__);
			}
			else
			{
				error = gnsdk_config_value_set(config_handle, GNSDK_CONFIG_LOOKUPDATABASE_ACCESS, access_mode);
				if (GNSDK_SUCCESS != error)
				{
					_display_last_error(__LINE__);
				}
				else
				{
					/* Open the database and assign it an ID for use by your application */
					error = gnsdk_lookupdatabase_open( db_identfier_id, config_handle );
					if (GNSDK_SUCCESS != error)
					{
						_display_last_error(__LINE__);
					}
					else
					{
						/* Display information about our lookup DB */
						_display_local_db_info( db_identfier_id );
					}              
				}                   
			}
		}
	}
    
    /* Return persistent lookup DB config handle */
    if (GNSDK_SUCCESS == error)
    {
        *p_db_config_handle = config_handle;
    }

    return error;
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
 *  Enable logging for the SDK.
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
_set_locale(
    gnsdk_user_handle_t user_handle
    )
{
    gnsdk_locale_handle_t locale_handle = GNSDK_NULL;
    gnsdk_error_t         error         = GNSDK_SUCCESS;
    int                   rc            = 0;
    
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
    const char*             client_id,
    const char*             client_id_tag,
    const char*             client_app_version,
    const char*             license_path,
    int                     use_local,
    gnsdk_user_handle_t*    p_user_handle
    )
{
    gnsdk_manager_handle_t  sdkmgr_handle      = GNSDK_NULL;
    gnsdk_error_t           error              = GNSDK_SUCCESS;
    gnsdk_user_handle_t     user_handle        = GNSDK_NULL;
    gnsdk_config_handle_t   db_config_handle   = GNSDK_NULL;
    int                     rc                 = 0;
    
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
        if (1 == use_local)
        {
            error = _open_local_db(
                    GRACENOTE_PRODUCTION_DATABASE,
                    GRACENOTE_PRODUCTION_DATABASE_LOCATION,
                    GNSDK_LOOKUPDATABASE_ACCESS_READ_ONLY,
                    &db_config_handle
                    );

            if (GNSDK_SUCCESS != error)
            {
                _display_last_error(__LINE__);
                rc = -1;
            }
            else
            {
                gnsdk_config_release(db_config_handle);
            }
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
    gnsdk_error_t error = GNSDK_SUCCESS;
    
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
    gnsdk_gdo_handle_t album_gdo
    )
{
    gnsdk_error_t      error     = GNSDK_SUCCESS;
    gnsdk_gdo_handle_t title_gdo = GNSDK_NULL;
    gnsdk_cstr_t       value     = GNSDK_NULL;
    
    /* Album Title */
    error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_TITLE_OFFICIAL, 1, &title_gdo );
    if (GNSDK_SUCCESS != error)
	{
		 _display_last_error(__LINE__);
	}
	else
    {
        error = gnsdk_manager_gdo_value_get( title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value );
        if (GNSDK_SUCCESS != error)
        {
			 _display_last_error(__LINE__);
        }
        else
		{
			printf( "%16s %s\n", "Title:", value );
		}
        gnsdk_manager_gdo_release( title_gdo );
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
    gnsdk_gdo_handle_t contrib_gdo
    )
{
    gnsdk_error_t      error    = GNSDK_SUCCESS;
    gnsdk_gdo_handle_t name_gdo = GNSDK_NULL;
    gnsdk_cstr_t       value    = GNSDK_NULL;
    
    
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
    gnsdk_error_t error    = GNSDK_SUCCESS;
    gnsdk_cstr_t  gdo_type = GNSDK_NULL;
    
    
    error = gnsdk_manager_gdo_get_type( match_gdo, &gdo_type );
    if (GNSDK_SUCCESS != error)
    {
        _display_last_error(__LINE__);
    }
    else
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
    
}  /* _display_match_gdo() */


/***************************************************************************
 *
 *    _DISPLAY_FOR_RESOLVE
 *
 *      Display information, to help select from match(es).
 *
 ***************************************************************************/
static void
_display_for_resolve(
    gnsdk_gdo_handle_t response_gdo
    )
{
    gnsdk_error_t      error     = GNSDK_SUCCESS;
    gnsdk_gdo_handle_t match_gdo = GNSDK_NULL;
    gnsdk_uint32_t     count     = 0;
    gnsdk_uint32_t     ordinal   = 0;
    
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
    
}  /* _display_for_resolve() */


/***************************************************************************
 *
 *    _DO_MATCH_SELECTION
 *
 *      Help select from match(es)
 *
 ***************************************************************************/
static gnsdk_uint32_t
_do_match_selection(gnsdk_gdo_handle_t response_gdo)
{
    /*
     This is where any matches that need resolution/disambiguation are iterated
     and a single selection of the best match is made.
     
     For this simplified sample, we'll just echo the matches and select the first match.
     */
    _display_for_resolve( response_gdo );
    
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
        
        *p_response_match_gdo = match_gdo;
    }
    else
    {
        gnsdk_manager_gdo_release( match_gdo );
    }
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
_query_text_input_fields_add(
    gnsdk_musicid_query_handle_t    query_handle,
    gnsdk_cstr_t                    album_title,
    gnsdk_cstr_t                    track_title,
    gnsdk_cstr_t                    artist_name
    )
{
    gnsdk_error_t   error   = GNSDK_SUCCESS;
    
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

/******************************************************************
 *
 *    _DO_SAMPLE_TEXT_QUERY
 *
 *    Perform sample text query.
 *
 *****************************************************************/
static gnsdk_error_t
_do_sample_text_query(
    gnsdk_musicid_query_handle_t    query_handle,
	int								local_only,
    g_sample_input_t*               sample_input,
    gnsdk_gdo_handle_t*             p_match_gdo
    )
{
    gnsdk_error_t       error               = GNSDK_SUCCESS;
    gnsdk_gdo_handle_t  response_gdo        = GNSDK_NULL;
    gnsdk_gdo_handle_t  choosen_match_gdo   = GNSDK_NULL;
    gnsdk_uint32_t      response_count      = 0;
    
    printf("\n*****MusicID Text Match Query*****\n");

    /* Set the input text */
    error = _query_text_input_fields_add(
                query_handle,
                sample_input->album_title,
                sample_input->track_title,
                sample_input->artist_name
                );
    if (GNSDK_SUCCESS == error)
    {
        /* Set lookup mode to local to see if we have a local match. */
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
    
    /* Perform the query */
    if (GNSDK_SUCCESS == error)
    {
        error = gnsdk_musicid_query_find_matches( query_handle, &response_gdo );
        if (GNSDK_SUCCESS != error)
        {
            _display_last_error(__LINE__);
        }
    }
    
    /* Check if we have a match */
    if (GNSDK_SUCCESS == error)
    {
        error = gnsdk_manager_gdo_child_count(
                    response_gdo,
                    GNSDK_GDO_CHILD_MATCH,
                    &response_count
                    );
        if (GNSDK_SUCCESS == error)
        {
            if (0 == response_count)
            {
                gnsdk_manager_gdo_release( response_gdo );
                response_gdo = GNSDK_NULL;
             
                /* No results locally, if allowed, let's try an online query */
				if (!local_only)
				{
					error = gnsdk_musicid_query_option_set(
								query_handle,
								GNSDK_MUSICID_OPTION_LOOKUP_MODE,
								GNSDK_LOOKUP_MODE_ONLINE_NOCACHE
								);
					if (GNSDK_SUCCESS == error)
					{
						/* Perform the query */
						error = gnsdk_musicid_query_find_matches( query_handle, &response_gdo );
						if (GNSDK_SUCCESS == error)
						{
							error = gnsdk_manager_gdo_child_count(
										response_gdo,
										GNSDK_GDO_CHILD_MATCH,
										&response_count
										);
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
        if (0 != response_count)
        {
            printf("Match candidate(s) found for the input.\n");
            
            /* See if we need any follow-up queries or disambiguation */
            error = _do_match_selection_and_get_full_response_match(
                        query_handle,
                        response_gdo,
                        &choosen_match_gdo
                        );
        }
        else
        {
            printf("No matches found for the input. \n");
        }
    }
    
    gnsdk_manager_gdo_release( response_gdo );
    
    *p_match_gdo = choosen_match_gdo;
    
    return error;
    
}  /* _do_sample_text_query() */


/******************************************************************
 *
 *    _MANAGE_RESULT_STORE_SIZE
 *
 *    Checks size of the result store with the most recent results.
 *    If it has hit the size limit, deletes the store with older results,
 *    makes the recent result store the "new" older results store,
 *    creates a new result store for more recent results.
 *
 *****************************************************************/
static int
_manage_result_store_size(
    g_lookup_database_t *result_stores,
    int                 *recent_db_index
    )
{
    gnsdk_error_t  error  = GNSDK_SUCCESS;

    if (result_stores[*recent_db_index].size > (RESULT_STORE_ALLOCATION_SIZE_BYTES/2))
    {
        printf("Size limit hit. Remove old results and start new recent results store.\n");
        error = gnsdk_lookupdatabase_close( result_stores[1^(*recent_db_index)].id );
        if (GNSDK_SUCCESS == error)
        {
            error = gnsdk_lookupdatabase_delete( result_stores[1^(*recent_db_index)].config_handle );
            if (GNSDK_SUCCESS == error)
            {
                gnsdk_config_release( result_stores[1^(*recent_db_index)].config_handle );

                *recent_db_index = 1^(*recent_db_index);

                error = _open_local_db(
                    result_stores[*recent_db_index].id,
                    result_stores[*recent_db_index].location,
                    GNSDK_LOOKUPDATABASE_ACCESS_READ_WRITE,
                    &result_stores[*recent_db_index].config_handle
                );
                if ( GNSDK_SUCCESS == error )
                {
                    error = gnsdk_lookupdatabase_size_get(result_stores[*recent_db_index].id, &result_stores[*recent_db_index].size);
                    if (GNSDK_SUCCESS != error)
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
_do_sample_queries_and_persist_results(
    gnsdk_user_handle_t		user_handle,
	int						local_only
    )
{
    gnsdk_error_t                   error             = GNSDK_SUCCESS;
    gnsdk_musicid_query_handle_t    query_handle      = GNSDK_NULL;
    gnsdk_gdo_handle_t              match_gdo         = GNSDK_NULL;
    int                             track_count       = sizeof(g_sample_input)/sizeof(g_sample_input_t);
    int                             track_iter        = 0;
    int                             recent_db_index   = 0;
    g_lookup_database_t             result_stores[2];

    result_stores[0].id             =  RESULT_DATABASE_A;
    result_stores[0].location       =  RESULT_DATABASE_A_LOCATION;
    result_stores[0].config_handle  =  GNSDK_NULL;
    result_stores[0].size           =  0;

    result_stores[1].id             =  RESULT_DATABASE_B;
    result_stores[1].location       =  RESULT_DATABASE_B_LOCATION;
    result_stores[1].config_handle  =  GNSDK_NULL;
    result_stores[1].size           =  0;

    error = _open_local_db(
        result_stores[0].id,
        result_stores[0].location,
        GNSDK_LOOKUPDATABASE_ACCESS_READ_WRITE,
        &result_stores[0].config_handle
    );
    if (GNSDK_SUCCESS == error)
    {
        error = _open_local_db(
            result_stores[1].id,
            result_stores[1].location,
            GNSDK_LOOKUPDATABASE_ACCESS_READ_WRITE,
            &result_stores[1].config_handle
        );
    }
    
    if (GNSDK_SUCCESS == error)
    {
        /* Get size of Lookup Database stores A & B */
        error = gnsdk_lookupdatabase_size_get( result_stores[0].id, &result_stores[0].size );
        if (GNSDK_SUCCESS == error)
        {
            error = gnsdk_lookupdatabase_size_get( result_stores[1].id, &result_stores[1].size );
        }
        
        /* For simplicity we are assigning current to store index 0 */
        /* You will need to keep track of which database has recent results between sessions. */
        recent_db_index = 0;
    }
    
    if (GNSDK_SUCCESS == error)
    {
        /* Create the query handle */
        error = gnsdk_musicid_query_create(
                    user_handle,
                    GNSDK_NULL,          /* User callback function */
                    GNSDK_NULL,          /* Optional data to be passed to the callback */
                    &query_handle
                    );
        
        for(track_iter = 0; track_iter < track_count && GNSDK_SUCCESS == error; track_iter++)
        {
            printf("Lookup: %d of %d\n", (track_iter+1), track_count);

            error = _do_sample_text_query( query_handle, local_only, &g_sample_input[track_iter], &match_gdo );
            if (GNSDK_SUCCESS == error &&
                GNSDK_NULL != match_gdo)
            {
                error = gnsdk_lookupdatabase_record_add( result_stores[recent_db_index].id, match_gdo );
                if (GNSDK_SUCCESS == error)
                {
                    printf("Query Result:%d added to %s\n", (track_iter+1), result_stores[recent_db_index].id);

                    /* Update size of recent results DB */
                    error = gnsdk_lookupdatabase_size_get( result_stores[recent_db_index].id, &result_stores[recent_db_index].size );
                    if (GNSDK_SUCCESS == error)
                    {
                        _manage_result_store_size(result_stores, &recent_db_index);
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

                gnsdk_manager_gdo_release( match_gdo );
            }
        }
        if (GNSDK_NULL != query_handle)
        {
            gnsdk_musicid_query_release( query_handle );
        }
    }
    
    /* Clean up Lookup DB Config handle */
    gnsdk_config_release( result_stores[0].config_handle );
    gnsdk_config_release( result_stores[1].config_handle );
}
