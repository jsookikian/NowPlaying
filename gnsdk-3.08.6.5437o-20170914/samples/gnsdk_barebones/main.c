 #define GNSDK_MUSICID               1

  #include "gnsdk.h"  // Includes all GN SDK headers

  /* Standard C headers - used by the sample app, but not required for GNSDK */
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>

  /* Local function declarations */
  static int _init_gnsdk(const char* client_id, const char* client_id_tag, const char* client_app_version,
                         const char* license_path, gnsdk_user_handle_t* p_user_handle);
  static void _display_error(int line_num, const char* info, gnsdk_error_t error_code);
  static void _shutdown_gnsdk(gnsdk_user_handle_t user_handle);
  static void _query_album_lookup(gnsdk_user_handle_t user_handle);
  static void _display_album_gdo(gnsdk_gdo_handle_t album_gdo);

  int main(int argc, char* argv[])
  {
      gnsdk_user_handle_t user_handle         = GNSDK_NULL;
      const char*         client_id           = NULL;
      const char*         client_id_tag       = NULL;
      const char*         client_app_version  = "1";   // client app version - usually "1"
      const char*         license_path        = NULL;

      if (argc != 4)
      {
          printf("\nUsage:\n%s clientid clientidtag license\n", argv[0]);
          return -1;
      }

      client_id     = argv[1];
      client_id_tag = argv[2];
      license_path  = argv[3];

      /* GNSDK initialization */
      if ((_init_gnsdk(client_id, client_id_tag,client_app_version,license_path,&user_handle)) == 0)
      {
          _query_album_lookup(user_handle);  /* Perform a sample album text search query - calls display function */
          _shutdown_gnsdk(user_handle);      /* Clean up and shutdown */
      }

      return 0;
  }

  static void _display_error(int line_num, const char* info, gnsdk_error_t error_code)
{
    const gnsdk_error_info_t* error_info = gnsdk_manager_error_info();
    printf("\nerror 0x%08x - %s\n\tline %d, info %s\n", error_code, error_info->error_description, line_num, info);
}

static int _init_gnsdk(const char* client_id, const char* client_id_tag, const char* client_app_version, const char* license_path,
                       gnsdk_user_handle_t* p_user_handle)
{
    gnsdk_manager_handle_t sdkmgr_handle  = GNSDK_NULL;
    gnsdk_error_t          error          = GNSDK_SUCCESS;
    gnsdk_user_handle_t    user_handle    = GNSDK_NULL;
    gnsdk_str_t            serialized_user     = GNSDK_NULL;

    /* Initialize the GNSDK Manager */
    if ((error = gnsdk_manager_initialize(&sdkmgr_handle, license_path, GNSDK_MANAGER_LICENSEDATA_FILENAME)) != GNSDK_SUCCESS)
    {
        _display_error(__LINE__, "gnsdk_manager_initialize()", error);
    }

    /* Initialize the MusicID Library */
    else if ((error = gnsdk_musicid_initialize(sdkmgr_handle)) != GNSDK_SUCCESS)
    {
        _display_error(__LINE__, "gnsdk_musicid_initialize()", error);
    }
    else if (( error = gnsdk_manager_user_register(GNSDK_USER_REGISTER_MODE_ONLINE, client_id, client_id_tag, client_app_version, &serialized_user)) != GNSDK_SUCCESS)
    {
        _display_error(__LINE__, "gnsdk_manager_user_register()", error);
    }
    else if (( error = gnsdk_manager_user_create(serialized_user, client_id, &user_handle)) != GNSDK_SUCCESS)
    {
        _display_error(__LINE__, "gnsdk_manager_user_create()", error);
    }

    if (error != GNSDK_SUCCESS)
        _shutdown_gnsdk(user_handle);
    else  *p_user_handle = user_handle;

    return error;
}

static void _query_album_lookup( gnsdk_user_handle_t user_handle)
{
    gnsdk_error_t                 error          = GNSDK_SUCCESS;
    gnsdk_musicid_query_handle_t  query_handle   = GNSDK_NULL;
    gnsdk_gdo_handle_t            response_gdo   = GNSDK_NULL;
    gnsdk_gdo_handle_t            album_gdo      = GNSDK_NULL;
    gnsdk_uint32_t                count          = 0;

    printf("\nMusicID Text Search Query\n");

    /* Create the query handle */
    if ((error = gnsdk_musicid_query_create(user_handle, GNSDK_NULL, GNSDK_NULL, &query_handle)) == GNSDK_SUCCESS)
    {
        if ((error = gnsdk_musicid_query_set_text( query_handle, GNSDK_MUSICID_FIELD_TITLE, "I Wonder")) != GNSDK_SUCCESS)
        {
            _display_error(__LINE__, "gnsdk_musicid_query_set_text()", error);
        }
        else if ((error = gnsdk_musicid_query_find_matches(query_handle, &response_gdo)) != GNSDK_SUCCESS)
        {
            _display_error(__LINE__, "gnsdk_musicid_query_find_matches()", error);
	}
	/* Find number of matches */
	else if ((error = gnsdk_manager_gdo_child_count(response_gdo, GNSDK_GDO_CHILD_MATCH, &count)) != GNSDK_SUCCESS)
	{
	    _display_error(__LINE__, "gnsdk_manager_gdo_child_count(GNSDK_GDO_CHILD_MATCH)", error);
	}
	else if (count == 0)
	{
	     printf("\nNo albums found for the input.\n");
	}

	/* Get first child Album GDO */
	else if ((error = gnsdk_manager_gdo_child_get(response_gdo, GNSDK_GDO_CHILD_MATCH, 1, &album_gdo)) != GNSDK_SUCCESS)
	{
	     _display_error(__LINE__, "gnsdk_manager_gdo_child_get(GNSDK_GDO_CHILD_MATCH)", error);
	}
	else
	{
	      _display_album_gdo(album_gdo);
	      gnsdk_manager_gdo_release(album_gdo);
	      album_gdo = GNSDK_NULL;
	}
    }

    /* Clean up - release the query handle and results */
    if (GNSDK_NULL != query_handle) gnsdk_musicid_query_release(query_handle);
    if (GNSDK_NULL != response_gdo) gnsdk_manager_gdo_release(response_gdo);

}

static void _display_album_gdo(gnsdk_gdo_handle_t album_gdo)
{
    gnsdk_error_t      error        = GNSDK_SUCCESS;
    gnsdk_gdo_handle_t title_gdo    = GNSDK_NULL;
    gnsdk_cstr_t       value        = GNSDK_NULL;

    /* Album Title */
    if ((error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_TITLE_OFFICIAL, 1, &title_gdo )) == GNSDK_SUCCESS)
    {
        if ((error = gnsdk_manager_gdo_value_get( title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value )) == GNSDK_SUCCESS)
        {
            printf( "%8s %s\n", "Album Title:", value );
        }
        else _display_error(__LINE__, "gnsdk_manager_gdo_value_get()", error);

        gnsdk_manager_gdo_release(title_gdo);
    }
    else _display_error(__LINE__, "gnsdk_manager_gdo_child_get()", error);
}

static void _shutdown_gnsdk(gnsdk_user_handle_t user_handle)
{
    gnsdk_error_t error                           = GNSDK_SUCCESS;

    /* Release our user handle - note that if updated_serialized_user_string is not null, meaning */
    /* the handle had changed during program execution, then you should save it out to disk again */
    if ((error = gnsdk_manager_user_release(user_handle)) != GNSDK_SUCCESS)
    {
        _display_error(__LINE__, "gnsdk_manager_user_release()", error);
    }

    /* Shutdown the libraries */
    gnsdk_musicid_shutdown();
    gnsdk_manager_shutdown();
}