/*
 * Copyright (c) 2000-2016 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/*
 *	Name: musicid_file_trackid
 *	Description:
 *	TrackID processing provides the simplest processing of media files. With this method, MusicID-File processes
 *	each media file independently, without regard for any other provided media files.
 *	This method is best used for small sets of media recognition, where getting an answer is more important then
 *	getting the best answer. It is also appropriate to use for retrieving all possible results for a single media
 *	file. The gnsdk_musicidfile_query_do_trackid API provides TrackID processing.
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

#define LOOKUP_SAMPLE_DATA_LOCATION			"../../sample_data/"
#define LOOKUP_DATABASE_SAMPLE_LOCATION		"../../sample_data/gdb"

/* Files used by this sample app */
typedef struct sample_file_s
{
    gnsdk_cstr_t file_path;
    gnsdk_cstr_t artist;
    gnsdk_cstr_t album;
    gnsdk_cstr_t track;
} sample_file_t;

/* Music ID File - track ID notes:
 * Tracks are treated independently.
 *   The result returned from RETURN_SINGLE will typically be the result that is at the top of the list for RETURN_ALL.
 * In online mode, the fingerprint is the primary lookup key.
 *   Many tracks appear on multiple albums, e.g. an original release and a greatest hits.
 *   Tag data can help find the correct album.
 * In local mode, the fingerprint is not used.
 */

sample_file_t sample_files[] =
{

    {"RECORDING.wav",GNSDK_NULL, GNSDK_NULL,      GNSDK_NULL}
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
_do_sample_trackid(
	gnsdk_user_handle_t user_handle,
	int                 use_local,
	gnsdk_uint32_t      midf_options
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

				/* Perform two MusicID-File TrackID lookups,
				 * first with RETURN_SINGLE,
				 * second with RETURN_ALL.
				 */
				printf("-------TrackID with 'RETURN_SINGLE' option:-------\n");
				rc = _do_sample_trackid(
					user_handle,
					use_local,
					GNSDK_MUSICIDFILE_QUERY_FLAG_RETURN_SINGLE | midf_query_flag | GNSDK_MUSICIDFILE_QUERY_FLAG_NO_THREADS
				);

				if (0 == rc)
				{
					printf("-------TrackID with 'RETURN_ALL' option:-------\n");
					rc = _do_sample_trackid(
						user_handle,
						use_local,
						GNSDK_MUSICIDFILE_QUERY_FLAG_RETURN_ALL | midf_query_flag | GNSDK_MUSICIDFILE_QUERY_FLAG_NO_THREADS
					);
				}

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
*    _SET_FINGERPRINT
*
***************************************************************************/
static int
_set_fingerprint(
    gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
    sample_file_t*                      sample_file
	)
{
	gnsdk_error_t error           = GNSDK_SUCCESS;
	gnsdk_bool_t  complete        = GNSDK_FALSE;
	size_t        read            = 0;
	FILE*         p_file          = NULL;
	char          pcm_audio[2048] = {0};

	/* check file for existence */
	p_file = fopen(sample_file->file_path, "rb");
	if (p_file == NULL)
	{
		printf("\n\nError: Failed to open input file: %s\n\n", sample_file->file_path);
		return -1;
	}
	else
	{
		/* skip the wave header (first 44 bytes). we know the format of our sample files, but please
		   be aware that many wav file headers are larger then 44 bytes! */
		if (0 != fseek(p_file, 44, SEEK_SET))
		{
			printf("\n\nError: Failed to seek past header: %s\n\n", sample_file->file_path);
		}
		else
		{
			/* initialize the fingerprinter
			   Note: Our sample files are non-standard 11025 Hz 16-bit mono to save on file size */
			error = gnsdk_musicidfile_fileinfo_fingerprint_begin(fileinfo_handle, 11025, 16, 1);
			if (GNSDK_SUCCESS != error)
			{
				_display_last_error(__LINE__);
			}
			else
			{
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
			}
		}
		fclose(p_file);
	}

	/* signal that we are done */
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_musicidfile_fileinfo_fingerprint_end(fileinfo_handle);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
		}
	}

	if (GNSDK_TRUE != complete)
	{
		/* Fingerprinter doesn't have enough data to generate a fingerprint.
			Note that the sample data does include one track that is too short to fingerprint. */
		printf("Warning: input file does not contain enough data to generate a fingerprint:\n%s\n", sample_file->file_path);
	}

	return 0;

}  /* _set_fingerprint() */


/***************************************************************************
*
*    _SET_METADATA
*
***************************************************************************/
static int
_set_metadata(
    gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
    sample_file_t*                      sample_file
	)
{
	gnsdk_error_t error = GNSDK_SUCCESS;

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

	return 0;

}   /* _set_metadata() */


/***************************************************************************
*
*    _ADD_FILE
*
***************************************************************************/
static int
_add_file(
	gnsdk_musicidfile_query_handle_t query_handle,
	sample_file_t*                   sample_file,
    int                              use_local
	)
{
	gnsdk_error_t                       error           = GNSDK_SUCCESS;
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle = GNSDK_NULL;
	int                                 rc              = 0;

	error = gnsdk_musicidfile_query_fileinfo_create(
		query_handle,
		sample_file->file_path,         /* identifier string - we'll use the file path, which is unique */
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
		if (GNSDK_SUCCESS == error)
		{
            rc = _set_metadata(fileinfo_handle, sample_file);

            /* Note: MusicID-File fingerprints are not supported locally. Adding the fingerprint will have no harmful effect. */
            if (!use_local && GNSDK_NULL != sample_files->file_path)
            {
                rc = _set_fingerprint(fileinfo_handle, sample_file);
            }
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
	gnsdk_musicidfile_query_handle_t query_handle,
    int                              use_local
	)
{
	int rc = 0;
    unsigned index = 0;

    for (index = 0; index < sizeof(sample_files)/sizeof(sample_file_t) && rc == 0; index++)
    {
        rc = _add_file(query_handle, &sample_files[index], use_local);
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
	}
	else
	{
		/* Quiet the compiler warning about this unused param */
		(void)query_handle;
	}

	return rc;

} /* _set_query_options() */

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
 *    _DISPLAY_ALBUM_GDO
 *
 ***************************************************************************/
static int
_display_album_gdo(
    gnsdk_gdo_handle_t album_gdo
    )
{
    gnsdk_error_t      error = GNSDK_SUCCESS;
    gnsdk_cstr_t       value = GNSDK_NULL;
    int                rc    = 0;
    gnsdk_gdo_handle_t title_gdo = GNSDK_NULL;
    gnsdk_gdo_handle_t track_gdo = GNSDK_NULL;

    error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_TITLE_OFFICIAL, 1, &title_gdo );
    if (GNSDK_SUCCESS == error)
    {
        error = gnsdk_manager_gdo_value_get( title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value );
        if (GNSDK_SUCCESS == error)
        {
            printf( "%10s %-35s", "Album:", value );

            error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_TRACK_MATCHED, 1, &track_gdo );
            if (GNSDK_SUCCESS == error)
            {
                gnsdk_gdo_handle_t track_title_gdo = GNSDK_NULL;

                error = gnsdk_manager_gdo_child_get( track_gdo, GNSDK_GDO_CHILD_TITLE_OFFICIAL, 1, &track_title_gdo );
                if (GNSDK_SUCCESS == error)
                {
                    error = gnsdk_manager_gdo_value_get( track_title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value );
                    if (GNSDK_SUCCESS == error)
                    {
                        printf( "%s %s", "Track:", value );
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
                track_gdo = GNSDK_NULL;
            }
            else
            {
                /* We may not have matched a track, so ignore errors here.
                 * You will probably want to only ignore not found errors.
                 */
                error = GNSDK_SUCCESS;
            }
            printf("\n");
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
            if (GNSDK_SUCCESS == error)
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
*    _DISPLAY_FILE_RESULTS
*
***************************************************************************/
static int
_display_file_results(
	gnsdk_musicidfile_fileinfo_handle_t midf_fileinfo
	)
{
	gnsdk_error_t                       error           = GNSDK_SUCCESS;
	gnsdk_gdo_handle_t                  results_gdo     = GNSDK_NULL;
	gnsdk_musicidfile_fileinfo_status_t fileinfo_status = gnsdk_musicidfile_fileinfo_unprocessed;
	const gnsdk_error_info_t*           p_error_info    = GNSDK_NULL;
	int                                 rc              = 0;

	if (midf_fileinfo == GNSDK_NULL)
	{
		return -1;
	}

	/* Display the fileinfo's status */
	error = gnsdk_musicidfile_fileinfo_status(midf_fileinfo, &fileinfo_status, &p_error_info);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		return -1;
	}

	if (gnsdk_musicidfile_fileinfo_unprocessed == fileinfo_status)
	{
		printf("\tFile unprocessed. Please retry.\n");
	}
	else if (gnsdk_musicidfile_fileinfo_error == fileinfo_status)
	{
		printf("\tProcessing error (0x%08x %s). Please retry.\n", p_error_info->error_code, p_error_info->error_description);
	}
	else if (gnsdk_musicidfile_fileinfo_result_none == fileinfo_status)
	{
		printf("\tNo results.\n");
	}
	else if ((gnsdk_musicidfile_fileinfo_result_single == fileinfo_status) ||
             (gnsdk_musicidfile_fileinfo_result_all == fileinfo_status))
	{
		error = gnsdk_musicidfile_fileinfo_get_response_gdo(midf_fileinfo, &results_gdo);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
			return -1;
		}

		rc = _display_gdo_results(results_gdo);

		error = gnsdk_manager_gdo_release(results_gdo);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
			return -1;
		}
	}

	return rc;

}  /* _display_file_results() */


/***************************************************************************
*
*    _DO_SAMPLE_TRACKID
*
***************************************************************************/
static int
_do_sample_trackid(
	gnsdk_user_handle_t user_handle,
	int                 use_local,
	gnsdk_uint32_t      midf_options
	)
{
	int                                 rc              = 0;
	gnsdk_error_t                       error           = GNSDK_SUCCESS;
	gnsdk_uint32_t                      count           = 0;
	gnsdk_uint32_t                      i               = 0;
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle = GNSDK_NULL;
	gnsdk_musicidfile_query_handle_t    query_handle    = GNSDK_NULL;

	/* create the MusicID-File handle */
	error = gnsdk_musicidfile_query_create(
		user_handle,
		GNSDK_NULL,
		GNSDK_NULL,         /* not using callbacks in this sample */
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
		rc = _set_query_data(query_handle, use_local);
	}

	/* Set any options */
	if (0 == rc)
	{
		rc = _set_query_options(query_handle, use_local);
	}

	/* Perform the Query */
	if (0 == rc)
	{
		error = gnsdk_musicidfile_query_do_trackid(query_handle, midf_options);
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

	/* display the results for each file */
	if (0 == rc)
	{
		error = gnsdk_musicidfile_query_fileinfo_count(query_handle, &count);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
			rc = -1;
		}
		else
		{
			printf("\nPrinting results for %u files:\n", count);

			/* for each file in the query... */
			for (i = 0; i < count; i++)
			{
				error = gnsdk_musicidfile_query_fileinfo_get_by_ident(
                    query_handle,
                    sample_files[i].file_path,
                    &fileinfo_handle
                );
				if (GNSDK_SUCCESS != error)
				{
					_display_last_error(__LINE__);
					rc = -1;
					break;
				}

				printf("*File %2d of %d*", i + 1, count);
                if (midf_options & GNSDK_MUSICIDFILE_QUERY_FLAG_RETURN_ALL) printf("\n");
				rc = _display_file_results(fileinfo_handle);
				if (0 != rc)
				{
					break;
				}
			}
			printf("\n\n");
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

} /* _do_sample_trackid() */
