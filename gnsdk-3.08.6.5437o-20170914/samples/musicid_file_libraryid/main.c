/*
 * Copyright (c) 2000-2016 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/*
 *	Name: musicid_file_libraryid
 *	Description:
 *	LibraryID processing adds another level of processing above AlbumID for very large collections of media files.
 *	LibraryID extends AlbumID functionality by performing additional scanning and processing of all the files in
 *	an entire collection. This enables LibraryID to find groupings that are not captured by AlbumID processing.
 *	This method is highly recommended for use when there are a large number (hundreds to thousands) of files to
 *	identify, though it is also equally effective when processing only a few files. This method takes most of
 *	the guesswork out of MusicID-File and lets the library do all the work for the application.
 *	The gnsdk_musicidfile_query_do_libraryid API provides LibraryID processing.
 *
 *	Command-line Syntax:
 *  sample <client_id> <client_id_tag> <license> [local|online]
 */

/* GNSDK headers
 *
 * Define the modules your application needs.
 * These constants enable inclusion of headers and symbols in gnsdk.h.
 * Define GNSDK_LOOKUP_LOCAL because this program has the potential to do local queries.
 * For local queries, a Gracenote local database must be present.
 */
#define GNSDK_MUSICID_FILE          1
#define GNSDK_DSP                   1
#define GNSDK_STORAGE_SQLITE        1
#define GNSDK_LOOKUP_LOCAL          1
#include "gnsdk.h"

/* Standard C headers - used by the sample app, but not required for GNSDK */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LOOKUP_DATABASE_SAMPLE_ID			"lookup_database_sample_id"

#define LOOKUP_DATABASE_SAMPLE_LOCATION		"../../sample_data/gdb"

/* Files used by this sample app */
typedef struct sample_file_s
{
    gnsdk_cstr_t ident;
    gnsdk_cstr_t file_path;
    gnsdk_cstr_t artist;
    gnsdk_cstr_t album;
    gnsdk_cstr_t track;
} sample_file_t;

/* Music ID File - library ID notes:
 * If you have many albums where multiple tracks are included, you will be better of using Album ID or Library ID.
 * If you cannot determine reliably which tracks come from the same album, then feeding all tracks to Library ID may be best.
 * In that case, a general heuristic will be used to try to group tracks to albums to improve results.
 * Libary ID does not support RETURN_ALL, it only supports RETURN_SINGLE.
 */
sample_file_t sample_files[] = {
    {"01", "../../sample_data/Coldplay - Death And All His Friends.wav", "Coldplay", "Viva La Vida", "Death And All His Friends"},
    {"02", "../../sample_data/Coldplay - Life In Technicolor.wav",       "Coldplay", "Viva La Vida", "Life In Technicolor"},
    {"03", "../../sample_data/Coldplay - Lost!.wav",                     "Coldplay", "Viva La Vida", "Lost!"},
    {"04", "../../sample_data/Coldplay - Yes.wav",                       "Coldplay", "Viva La Vida", "Yes"},
    
    {"05", "../../sample_data/Santana - Everybody's Everything.wav",      "Santana", "Greatest Hits", "Everybody's Everything"},
    {"06", "../../sample_data/Santana - Se A Cabo.wav",                   "Santana", "Greatest Hits", "Se A Cabo"},
    {"07", "../../sample_data/Santana - Everything's Coming Our Way.wav", "Santana", "Greatest Hits", "Everything's Coming Our Way"},
    {"08", "../../sample_data/Santana - Oye Como Va.wav",                 "Santana", "Greatest Hits", "Oye Como Va"},
    {"09", "../../sample_data/Santana - Black Magic Woman.wav",           "Santana", "Greatest Hits", "Black Magic Woman"},
    {"10", "../../sample_data/Santana - Persuasion.wav",                  "Santana", "Greatest Hits", "Persuasion"},
    {"11", "../../sample_data/Santana - Samba Pa Ti.wav",                 "Santana", "Greatest Hits", "Samba Pa Ti"},
    {"12", "../../sample_data/Santana - Hope You're Feeling Better.wav",  "Santana", "Greatest Hits", "Hope You're Feeling Better"},
    {"13", "../../sample_data/Santana - Jingo.wav",                       "Santana", "Greatest Hits", "Jingo"},
    {"14", "../../sample_data/Santana - Evil Ways.wav",                   "Santana", GNSDK_NULL,      GNSDK_NULL}
};

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

static int
_do_sample_libraryid(
	gnsdk_user_handle_t user_handle,
	int                 use_local,
	gnsdk_uint32_t      midf_options
	);

/* MusicID-File query status callback */
static gnsdk_void_t GNSDK_CALLBACK_API
_musicidfile_status_callback(
	gnsdk_void_t*                       user_data,
	gnsdk_musicidfile_query_handle_t    query_handle,
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
	gnsdk_musicidfile_callback_status_t status,
	gnsdk_uint32_t                      current_file,
	gnsdk_uint32_t                      total_files,
	gnsdk_bool_t*                       p_abort
	);

/* Fingerprint request for the specified file */
static gnsdk_void_t GNSDK_CALLBACK_API
_get_fingerprint_callback(
	gnsdk_void_t*                       user_data,
	gnsdk_musicidfile_query_handle_t    query_handle,
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
	gnsdk_uint32_t                      current_file,
	gnsdk_uint32_t                      total_files,
	gnsdk_bool_t*                       p_abort
	);

/* Metadata request for the specified file */
static gnsdk_void_t GNSDK_CALLBACK_API
_get_metadata_callback(
	gnsdk_void_t*                       user_data,
	gnsdk_musicidfile_query_handle_t    query_handle,
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
	gnsdk_uint32_t                      current_file,
	gnsdk_uint32_t                      total_files,
	gnsdk_bool_t*                       p_abort
	);

/* MusicID-File query status callback */
static gnsdk_void_t GNSDK_CALLBACK_API
_result_available_callback(
	gnsdk_void_t*                    user_data,
	gnsdk_musicidfile_query_handle_t query_handle,
	gnsdk_gdo_handle_t               results_gdo,
	gnsdk_uint32_t                   current_album,
	gnsdk_uint32_t                   total_albums,
	gnsdk_bool_t*                    p_abort
	);

/******************************************************************
 *
 *    MAIN
 *
 ******************************************************************/
int
main(int argc, char* argv[])
{
	gnsdk_user_handle_t user_handle        = GNSDK_NULL;
	const char*         client_id          = NULL;
	const char*         client_id_tag      = NULL;
	const char*         client_app_version = "1";
	const char*         license_path       = NULL;
	int                 use_local          = -1;
	unsigned            midf_query_flag    = 0;
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
				if (use_local)
				{
					midf_query_flag = GNSDK_MUSICIDFILE_QUERY_FLAG_RESPONSE_MATCHES;
				}
				else
				{
					midf_query_flag = GNSDK_MUSICIDFILE_QUERY_FLAG_RESPONSE_ALBUMS;
				}
				
				/* Perform a MusicID-File LibraryID lookup */
				rc = _do_sample_libraryid(
					user_handle,
					use_local,
					GNSDK_MUSICIDFILE_QUERY_FLAG_RETURN_SINGLE | midf_query_flag
				);

				/* Clean up and shutdown */
				_shutdown_gnsdk(user_handle);
			}
		}
	}
	if (argc != 5 || use_local == -1)
	{
		printf( "\nUsage:\n%s clientid clientidtag license [local|online]\n", argv[0] );
		rc = -1;
	}
	
	return rc;
	
} /* main() */


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
				/* Display information about our local EDB */
				rc = _open_local_db();
			}
		}
	}
	
	/* Initialize the DSP library - used for fingerprint generation. */
	if (0 == rc)
	{
		error = gnsdk_dsp_initialize(sdkmgr_handle);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
			rc = -1;
		}
	}
	
	/* Initialize the MusicID-File library */
	if (0 == rc)
	{
		error = gnsdk_musicidfile_initialize(sdkmgr_handle);
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


/***************************************************************************
*
*    _ADD_FILE
*
***************************************************************************/
static int
_add_file(
	gnsdk_musicidfile_query_handle_t query_handle,
    sample_file_t*                   sample_file
	)
{
	gnsdk_error_t                       error           = GNSDK_SUCCESS;
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle = GNSDK_NULL;
	int                                 rc              = 0;

	error = gnsdk_musicidfile_query_fileinfo_create(
		query_handle,
        sample_file->ident,
		GNSDK_NULL,
		GNSDK_NULL,
		&fileinfo_handle
    );
	if (GNSDK_SUCCESS == error)
	{
		/* Set the file path in the fileinfo */
		error = gnsdk_musicidfile_fileinfo_metadata_set(
            fileinfo_handle,
            GNSDK_MUSICIDFILE_FILEINFO_VALUE_FILENAME,
            sample_file->file_path
        );

		/* The created fileinfo are managed by the query handle and won't need to be explicitly released */
            if (GNSDK_SUCCESS != error)
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

	if (0 != rc)
	{
		printf("\nError: Failed to add file %s to the query", sample_file->file_path);
	}
	return rc;

}  /* _add_file() */


/***************************************************************************
*
*    _SET_QUERY_DATA
*
***************************************************************************/
static int
_set_query_data(
	gnsdk_musicidfile_query_handle_t query_handle
	)
{
	int rc = 0;
    unsigned index = 0;
    
    for (index = 0; index < sizeof(sample_files)/sizeof(sample_file_t) && rc == 0; index++)
    {
        rc = _add_file(query_handle, &sample_files[index]);
    }

	return rc;

}  /* _set_query_data() */


/***************************************************************************
*
*    _SET_QUERY_OPTIONS
*
***************************************************************************/
static int
_set_query_options(
	gnsdk_musicidfile_query_handle_t query_handle,
	int                              use_local
	)
{
	int rc = 0;

	/* To use the local data stores for this query, set the 'use local lookup'
	 * query option to true.
	 * By default, the lookup will be handled online but many applications
	 * will want to start with a local query and then fall back to an online
	 * query for anything not matched. See the "musicid_lookup_album_local_online"
	 * sample for an example of this 'hybrid' approach.
	 */
	if (use_local)
	{
		gnsdk_error_t error = GNSDK_SUCCESS;

		error = gnsdk_musicidfile_query_option_set(
			query_handle,
			GNSDK_MUSICIDFILE_OPTION_LOOKUP_MODE,
			GNSDK_LOOKUP_MODE_LOCAL
		);
		if (GNSDK_SUCCESS != error)
		{
			rc = -1;
			_display_last_error(__LINE__);
		}
		else
		{
			/* Quiet the compiler warning about this unused param */
			(void)query_handle;
		}
	}

	return rc;

}  /* _set_query_options() */

/***************************************************************************
 *
 *    _DISPLAY_CONTRIB_GDO
 *
 ***************************************************************************/
static int
_display_contrib_gdo(
    gnsdk_gdo_handle_t contrib_gdo
    )
{
    gnsdk_error_t      error    = GNSDK_SUCCESS;
    gnsdk_gdo_handle_t name_gdo = GNSDK_NULL;
    gnsdk_cstr_t       name     = GNSDK_NULL;
    int                rc       = 0;
    
    error = gnsdk_manager_gdo_child_get( contrib_gdo, GNSDK_GDO_CHILD_NAME_OFFICIAL, 1, &name_gdo );
    if (GNSDK_SUCCESS == error)
    {
        error = gnsdk_manager_gdo_value_get( name_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &name );
        if (GNSDK_SUCCESS == error)
        {
            printf( "%10s %s\n", "Name: ", name );
        }
        else
        {
            _display_last_error(__LINE__);
            rc = -1;
        }
        gnsdk_manager_gdo_release( name_gdo );
    }
    else
    {
        _display_last_error(__LINE__);
        rc = -1;
    }
    
    return rc;
    
}  /* _display_contrib_gdo() */

/***************************************************************************
 *
 *    _DISPLAY_TRACK_GDO
 *
 ***************************************************************************/
static int
_display_track_gdo(
    gnsdk_gdo_handle_t album_gdo,
    gnsdk_uint32_t     track_index
    )
{
    gnsdk_error_t      error       = GNSDK_SUCCESS;
    gnsdk_gdo_handle_t track_gdo   = GNSDK_NULL;
    gnsdk_cstr_t       track_title = GNSDK_NULL;
    gnsdk_cstr_t       track_num   = GNSDK_NULL;
    int                rc          = 0;
    
    error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_TRACK_MATCHED, track_index, &track_gdo );
    if (GNSDK_SUCCESS == error)
    {
        gnsdk_gdo_handle_t track_title_gdo = GNSDK_NULL;
        
        error = gnsdk_manager_gdo_child_get( track_gdo, GNSDK_GDO_CHILD_TITLE_OFFICIAL, 1, &track_title_gdo );
        if (GNSDK_SUCCESS == error)
        {
            error = gnsdk_manager_gdo_value_get( track_title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &track_title );
            if (GNSDK_SUCCESS == error)
            {
                error = gnsdk_manager_gdo_value_get( track_gdo, GNSDK_GDO_VALUE_TRACK_NUMBER, 1, &track_num);
                if (GNSDK_SUCCESS == error)
                {
                    printf( "%10s (ord = %2s) %s\n", "Track:", track_num, track_title );
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
            gnsdk_manager_gdo_release( track_title_gdo );
        }
        else
        {
            _display_last_error(__LINE__);
            rc = -1;
        }
        gnsdk_manager_gdo_release( track_gdo );
    }
    
    return rc;
}  /* _display_track_gdo() */

/***************************************************************************
 *
 *    _DISPLAY_ALBUM_GDO
 *
 ***************************************************************************/
static int
_display_album_gdo(
    gnsdk_gdo_handle_t album_gdo
    )
{
    gnsdk_error_t      error               = GNSDK_SUCCESS;
    gnsdk_cstr_t       value               = GNSDK_NULL;
    int                rc                  = 0;
    gnsdk_gdo_handle_t title_gdo           = GNSDK_NULL;
    gnsdk_uint32_t     matched_track_count = 0;
    gnsdk_uint32_t     matched_track_index = 0;

    error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_TITLE_OFFICIAL, 1, &title_gdo );
    if (GNSDK_SUCCESS == error)
    {
        error = gnsdk_manager_gdo_value_get( title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value );
        if (GNSDK_SUCCESS == error)
        {
            printf( "%10s %s", "Album:", value );

            error = gnsdk_manager_gdo_child_count(
                album_gdo,
                GNSDK_GDO_CHILD_TRACK_MATCHED,
                &matched_track_count
            );
            if (GNSDK_SUCCESS == error)
            {
                printf("   -   (matched %d tracks)\n", matched_track_count);
                for (matched_track_index = 1; matched_track_index <= matched_track_count; matched_track_index++)
                {
                    rc = _display_track_gdo(album_gdo, matched_track_index);
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
            rc = -1;
        }
        gnsdk_manager_gdo_release( title_gdo );
    }
    else
    {
        _display_last_error(__LINE__);
        rc = -1;
    }
    
    return rc;
}  /* _display_album_gdo() */

/***************************************************************************
 *
 *    _DISPLAY_ALBUM_RESULTS
 *
 ***************************************************************************/
static int
_display_album_results(
    gnsdk_gdo_handle_t results_gdo,
    gnsdk_uint32_t     album_count
    )
{
    gnsdk_error_t  error = GNSDK_SUCCESS;
    gnsdk_uint32_t album_index   = 0;
    int            rc    = 0;
    
    if (album_count > 1)
    {
        printf("\tAlbum count: %d\n", album_count);
    }
    
    /* GDO accessors are ordinal based, i.e. the first element is accessed with 1, not 0. */
    for (album_index = 1; album_index <= album_count && 0 == rc; album_index++)
    {
        gnsdk_gdo_handle_t album_gdo = GNSDK_NULL;
        
        error = gnsdk_manager_gdo_child_get(results_gdo, GNSDK_GDO_CHILD_ALBUM, album_index, &album_gdo);
        if (GNSDK_SUCCESS == error)
        {
            rc = _display_album_gdo(album_gdo);
            gnsdk_manager_gdo_release(album_gdo);
        }
        else
        {
            _display_last_error(__LINE__);
            rc = -1;
        }
    }
    
    return rc;
    
}  /* _display_album_results() */

/***************************************************************************
 *
 *    _DISPLAY_MATCH_RESULTS
 *
 ***************************************************************************/
static int
_display_match_results(
    gnsdk_gdo_handle_t results_gdo,
    gnsdk_uint32_t     match_count
    )
{
    gnsdk_error_t  error       = GNSDK_SUCCESS;
    gnsdk_uint32_t match_index = 0;
    gnsdk_cstr_t   gdo_type    = GNSDK_NULL;
    int            rc          = 0;
    
    if (match_count > 1)
    {
        printf("\tMatch count: %d\n", match_count);
    }
    
    /* GDO accessors are ordinal based, i.e. the first element is accessed with 1, not 0. */
    for (match_index = 1; match_index <= match_count && 0 == rc; match_index++)
    {
        gnsdk_gdo_handle_t match_gdo = GNSDK_NULL;
        
        error = gnsdk_manager_gdo_child_get(results_gdo, GNSDK_GDO_CHILD_MATCH, match_index, &match_gdo);
        if (GNSDK_SUCCESS == error)
        {
            error = gnsdk_manager_gdo_get_type(match_gdo, &gdo_type);
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
                rc = -1;
            }
            gnsdk_manager_gdo_release(match_gdo);
        }
        else
        {
            _display_last_error(__LINE__);
            rc = -1;
        }
    }
    
    return rc;
    
}  /* _display_match_results() */

/***************************************************************************
 *
 *    _DISPLAY_GDO_RESULTS
 *
 ***************************************************************************/
static int
_display_gdo_results(
    gnsdk_gdo_handle_t results_gdo
    )
{
    gnsdk_error_t  error       = GNSDK_SUCCESS;
    gnsdk_uint32_t album_count = 0;
    gnsdk_uint32_t match_count = 0;
    int            rc          = 0;
    
    /* We either asked for albums (online) or matches (local). Matches can be either
     * albums or artists if finding a specific album was not possible.
     */
    error = gnsdk_manager_gdo_child_count(results_gdo, GNSDK_GDO_CHILD_ALBUM, &album_count);
    if (GNSDK_SUCCESS == error)
    {
        if (album_count != 0)
        {
            rc = _display_album_results(results_gdo, album_count);
        }
        else
        {
            error = gnsdk_manager_gdo_child_count(results_gdo, GNSDK_GDO_CHILD_MATCH, &match_count);
            if (GNSDK_SUCCESS == 0)
            {
                rc = _display_match_results(results_gdo, match_count);
            }
            else
            {
                _display_last_error(__LINE__);
                rc = -1;
            }
        }
    }
    else
    {
        _display_last_error(__LINE__);
        rc = -1;
    }
    
    return rc;
}  /* _display_gdo_results() */

/***************************************************************************
*
*    _DO_SAMPLE_LIBRARYID
*
***************************************************************************/
static int
_do_sample_libraryid(
	gnsdk_user_handle_t user_handle,
	int                 use_local,
	gnsdk_uint32_t      midf_options
	)
{
	int                              rc           = 0;
	gnsdk_error_t                    error        = GNSDK_SUCCESS;
	gnsdk_musicidfile_query_handle_t query_handle = GNSDK_NULL;

	/* This sample does not use some of the available MIDF callbacks - the 'result available,'
	 * 'result not found' and 'identification complete' callbacks aren't used because we block on
	 * the call to do the identification and then display all of the results only when the
	 * identification process is complete.
     */
    /* Note: File based fingerprints not supported locally. You could add the fingerprint with no ill-effect. */
	gnsdk_musicidfile_callbacks_t midf_callbacks = {
		_musicidfile_status_callback,
        use_local ? GNSDK_NULL : _get_fingerprint_callback,
		_get_metadata_callback,
		_result_available_callback,
		GNSDK_NULL,                                                         /* result_not_found_callback */
		GNSDK_NULL                                                          /* musicid_complete_callback */
	};

	/* create the MusicID-File handle */
	error = gnsdk_musicidfile_query_create(
		user_handle,
		&midf_callbacks,
		GNSDK_NULL,         /* the optional 'user data' param is passed to our callbacks */
		&query_handle
		);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		rc = -1;
	}

	/* Add our sample files to the query. Metadata and fingerprints will be set in the callbacks. */
	if (0 == rc)
	{
		rc = _set_query_data(query_handle);
	}

	/* Set any options */
	if (0 == rc)
	{
		rc = _set_query_options(query_handle, use_local);
	}

	/* Perform the Query */
	if (0 == rc)
	{
		error = gnsdk_musicidfile_query_do_libraryid(query_handle, midf_options);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
			rc = -1;
		}
	}

	/* Ensure everything is finished. */
	if (0 == rc)
	{
		error = gnsdk_musicidfile_query_wait_for_complete(query_handle, GNSDK_MUSICIDFILE_TIMEOUT_INFINITE, GNSDK_NULL);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
			rc = -1;
		}
	}

	/* release the query handle */
	error = gnsdk_musicidfile_query_release(query_handle);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		rc = -1;
	}

	return rc;

}  /* _do_sample_libraryid() */


/***************************************************************************
*
*    _GET_FINGERPRINT_CALLBACK
*
***************************************************************************/
static gnsdk_void_t GNSDK_CALLBACK_API
_get_fingerprint_callback(
	gnsdk_void_t*                       user_data,
	gnsdk_musicidfile_query_handle_t    query_handle,
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
	gnsdk_uint32_t                      current_file,
	gnsdk_uint32_t                      total_files,
	gnsdk_bool_t*                       p_abort
	)
{
	gnsdk_error_t error           = GNSDK_SUCCESS;
	gnsdk_bool_t  complete        = GNSDK_FALSE;
	gnsdk_cstr_t  file            = GNSDK_NULL;
	size_t        read            = 0;
	FILE*         p_file          = NULL;
	char          pcm_audio[2048] = {0};


	/* get the file */
	error = gnsdk_musicidfile_fileinfo_metadata_get(fileinfo_handle, GNSDK_MUSICIDFILE_FILEINFO_VALUE_FILENAME, &file, GNSDK_NULL);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		return;
	}

	/* check file for existence */
	p_file = fopen(file, "rb");
	if (p_file == NULL)
	{
		printf("\n\n!!!!Failed to open input file: %s!!!\n\n", file);
		return;
	}

	/* skip the wave header (first 44 bytes). we know the format of our sample files */
	if (0 != fseek(p_file, 44, SEEK_SET))
	{
		GNSDK_ASSERT(0);
		fclose(p_file);
		return;
	}

	/* initialize the fingerprinter
	   Note: Our sample files are non-standard 11025 Hz 16-bit mono to save on file size */
	error = gnsdk_musicidfile_fileinfo_fingerprint_begin(fileinfo_handle, 11025, 16, 1);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		fclose(p_file);
		return;
	}

	read = fread(pcm_audio, sizeof(char), 2048, p_file);
	while (read > 0)
	{
		/* write audio to the fingerprinter */
		error = gnsdk_musicidfile_fileinfo_fingerprint_write(
			fileinfo_handle,
			pcm_audio,
			read,
			&complete
			);
		if (GNSDK_SUCCESS != error)
		{
			if (GNSDKERR_SEVERE(error)) /* 'aborted' warnings could come back from write which should be expected */
				_display_last_error(__LINE__);
			break;
		}

		/* does the fingerprinter have enough audio? */
		if (GNSDK_TRUE == complete)
		{
			break;
		}

		read = fread(pcm_audio, sizeof(char), 2048, p_file);
	}

	fclose(p_file);

	/* signal that we are done */
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_musicidfile_fileinfo_fingerprint_end(
			fileinfo_handle
			);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
		}
	}

	if (GNSDK_TRUE != complete)
	{
		/* fingerprinter doesn't have enough data! */
		printf("Warning: input file does not contain enough data to generate a fingerprint:\n%s\n", file);
	}

	/* this app doesn't allow a user to cancel but you could use this parameter
	   to allow cancellation of the query */
	*p_abort = GNSDK_FALSE;

	/* This is to quiet compiler warnings about un-used parameters in this simplified sample callback. */
	user_data    = 0;
	current_file = 0;
	total_files  = 0;
	(void)query_handle;

}  /* _get_fingerprint_callback() */


/***************************************************************************
*
*    _GET_METADATA_CALLBACK
*
***************************************************************************/
static gnsdk_void_t GNSDK_CALLBACK_API
_get_metadata_callback(
	gnsdk_void_t*                       user_data,
	gnsdk_musicidfile_query_handle_t    query_handle,
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
	gnsdk_uint32_t                      current_file,
	gnsdk_uint32_t                      total_files,
	gnsdk_bool_t*                       p_abort
	)
{
	gnsdk_error_t  error = GNSDK_SUCCESS;
	gnsdk_cstr_t   ident  = GNSDK_NULL;
    unsigned       index = 0;
    sample_file_t* sample_file = GNSDK_NULL;

	/* get the fileinfo */
	error = gnsdk_musicidfile_fileinfo_metadata_get(fileinfo_handle, GNSDK_MUSICIDFILE_FILEINFO_VALUE_IDENT, &ident, GNSDK_NULL);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		return;
	}
    for (index = 0; index < sizeof(sample_files)/sizeof(sample_file_t); index++)
    {
        if (0 == strcmp(ident, sample_files[index].ident))
        {
            sample_file = &sample_files[index];
            break;
        }
    }

    /* Typically, you would read file tags, e.g. ID3, and add that text to the fileinfo to help with
     * the search. To keep the sample code simple, we use .wav files and hardcode mock tag data.
     */
    if (GNSDK_NULL != sample_file->artist)
    {
        error = gnsdk_musicidfile_fileinfo_metadata_set(
            fileinfo_handle,
            GNSDK_MUSICIDFILE_FILEINFO_VALUE_ALBUMARTIST,
            sample_file->artist
        );
        if (GNSDK_SUCCESS != error)
        {
            _display_last_error(__LINE__);
        }
    }
    if (GNSDK_SUCCESS == error)
    {
        if (GNSDK_NULL != sample_file->album)
        {
            error = gnsdk_musicidfile_fileinfo_metadata_set(
                fileinfo_handle,
                GNSDK_MUSICIDFILE_FILEINFO_VALUE_ALBUMTITLE,
                sample_file->album
            );
            if (GNSDK_SUCCESS != error)
            {
                _display_last_error(__LINE__);
            }
        }
    }
    if (GNSDK_SUCCESS == error)
    {
        if (GNSDK_NULL != sample_file->track)
        {
            error = gnsdk_musicidfile_fileinfo_metadata_set(
                fileinfo_handle,
                GNSDK_MUSICIDFILE_FILEINFO_VALUE_TRACKTITLE,
                sample_file->track
            );
            if (GNSDK_SUCCESS != error)
            {
                _display_last_error(__LINE__);
            }
        }
    }

	/* This app doesn't allow a user to cancel but you could use this parameter
	   to allow cancellation of the query */
	*p_abort = GNSDK_FALSE;

	/* This is to quiet compiler warnings about un-used parameters in this simplified sample callback. */
	user_data    = 0;
	current_file = 0;
	total_files  = 0;
	(void)query_handle;

}  /* _get_metadata_callback() */


/***************************************************************************
*
*    _MUSICIDFILE_STATUS_CALLBACK
*
***************************************************************************/
/* This is the status callback function - useful for displaying progress of
   network actions and for allowing cancellation of large transactions */
static gnsdk_void_t GNSDK_CALLBACK_API
_musicidfile_status_callback(
	gnsdk_void_t*                       user_data,
	gnsdk_musicidfile_query_handle_t    query_handle,
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
	gnsdk_musicidfile_callback_status_t status,
	gnsdk_uint32_t                      current_file,
	gnsdk_uint32_t                      total_files,
	gnsdk_bool_t*                       p_abort
	)
{
	gnsdk_error_t error = GNSDK_SUCCESS;
	gnsdk_cstr_t  file  = GNSDK_NULL;
	gnsdk_cstr_t  tmp   = GNSDK_NULL;


	/* get the file */
	error = gnsdk_musicidfile_fileinfo_metadata_get(fileinfo_handle, GNSDK_MUSICIDFILE_FILEINFO_VALUE_FILENAME, &file, GNSDK_NULL);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
	}

	printf("\nMID-File Status: ");

	switch (status)
	{
	case gnsdk_musicidfile_status_error:
		tmp = "error";
		break;

	case gnsdk_musicidfile_status_fileinfo_processing_begin:
		tmp = "fileinfo_processing_begin";
		break;

	case gnsdk_musicidfile_status_fileinfo_query:
		tmp = "fileinfo_query";
		break;

	case gnsdk_musicidfile_status_fileinfo_processing_error:
		tmp = "fileinfo_processing_error";
		break;

	case gnsdk_musicidfile_status_fileinfo_processing_complete:
		tmp = "fileinfo_processing_complete";
		break;
	}

	printf("%d of %d - %s - %s\n", current_file, total_files, tmp, file);

	/* this app doesn't allow a user to cancel but you could use this parameter
	   to allow cancellation of the query */
	*p_abort = GNSDK_FALSE;

	/* This is to quiet compiler warnings about un-used parameters in this simplified sample callback. */
	user_data = 0;
	(void)query_handle;

}  /* _musicidfile_status_callback() */


/***************************************************************************
*
*    _RESULT_AVAILABLE_CALLBACK
*
***************************************************************************/
static gnsdk_void_t GNSDK_CALLBACK_API
_result_available_callback(
	gnsdk_void_t*                    user_data,
	gnsdk_musicidfile_query_handle_t query_handle,
	gnsdk_gdo_handle_t               results_gdo,
	gnsdk_uint32_t                   current_album,
	gnsdk_uint32_t                   total_albums,
	gnsdk_bool_t*                    p_abort
	)
{
	printf("\nMID-File Result:");

	_display_gdo_results(results_gdo);

	/* this app doesn't allow a user to cancel but you could use this parameter
	   to allow cancellation of the query */
	*p_abort = GNSDK_FALSE;

	/* This is to quiet compiler warnings about un-used parameters in this simplified sample callback. */
	user_data     = 0;
	query_handle  = 0;
	total_albums  = 0;
	current_album = 0;

}  /* _result_available_callback() */

