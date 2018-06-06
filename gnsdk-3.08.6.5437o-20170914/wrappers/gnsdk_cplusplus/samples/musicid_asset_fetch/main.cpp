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
 *  sample client_id client_id_tag license [local|online]
 */

/* Online vs Local queries
 * For local queries, a Gracenote local database must be present.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#include "gnsdk.hpp"
#include "gnsdk_musicid.hpp"
#include "gnsdk_storage_sqlite.hpp"
#include "gnsdk_lookup_local.hpp"
#include "gnsdk_lookupdatabase.hpp"

#define GRACENOTE_PRODUCTION_DATABASE_SAMPLE_ID		"lookup_database_sample_id"
#define GRACENOTE_PRODUCTION_DATABASE_LOCATION		"../../../../sample_data/gdb"

using namespace gracenote;
using namespace gracenote::musicid;
using namespace gracenote::metadata;
using namespace gracenote::lookup_local;
using namespace gracenote::storage_sqlite;
using namespace gracenote::lookupdatabase;

static void
doAssetFetch(GnUser& user, GnLookupMode lookupMode, GnAlbum& album)
{
	content_iterator Iter = album.Contents().begin();

	for (; Iter != album.Contents().end(); ++Iter)
	{
		 GnContent content = *Iter;
		 asset_iterator aIter = content.Assets().begin();

		 for (; aIter != content.Assets().end(); ++aIter)
		 {
			  GnAsset asset = *aIter;
			  gnsdk_cstr_t url = GNSDK_NULL;

			  url = asset.UrlGnsdk();

			  if (!url || (0 == strcmp("" , url)))
				  continue;

			  if (kContentTypeImageCover == content.ContentType())
			  {
				    GnAssetFetch          gnAssetFetch(user, url, lookupMode);
				  	const gnsdk_byte_t*   img  = gnAssetFetch.Data();
					gnsdk_size_t          size = gnAssetFetch.Size();

					if (img && size)
					{
						std::cout 
							<< std::endl 
							<< "Successfully Fetched CoverArt:" << std::endl
							<<	"\tAsset Url: " << url << std::endl
							<<  "\tAsset Size: " << size << std::endl;
					}
			  }
		 }
	}
}

static void
doSampleAlbumSearch( GnUser& user, GnLookupMode lookupMode )
{
	std::cout << "\n*****Sample Album Search*****\n" ;

	GnMusicId music_id(user, GNSDK_NULL);

	/* enable content to retrieved during lookup */
	music_id.Options().LookupData(kLookupDataContent, true);

	std::cout << "album title    : Supernatural \n";
	std::cout << "track title    : Africa Bamba \n";
	std::cout << "artist title   : Santana \n";

	/*** Set the input text as album title, artist name, track title and perform the query****/
	GnResponseAlbums response = music_id.FindAlbums("Supernatural", "Africa Bamba", GNSDK_NULL, "Santana", GNSDK_NULL);

	/* See how many albums were found. */
	gnsdk_uint32_t count = response.Albums().count();

	if(count == 0)
	{ 
		printf("\nNo albums found for the input.\n");
	}
	else
	{
		album_iterator aIter = response.Albums().begin();
		for (; aIter != response.Albums().end(); ++aIter)
		{
			GnAlbum album = *aIter;
            doAssetFetch(user, lookupMode, album);
		}
	}
}

/*-----------------------------------------------------------------------------
 *  EnableLocalLookups
 *		Enabling a Local Lookup module gives the SDK the ability to perform
 *		certain queries without going online. This can enable an completely
 *		off-line mode for your application, or can act as a performance boost
 *		over going online for some queries.
 */
static void
EnableLocalLookups()
{
	/* Enable Local Lookup module to use for local queries */
	GnLookupLocal::Enable();
	
	GnConfig config;
	config.Set(kConfigOptionLocationLookupDatabaseAll, GRACENOTE_PRODUCTION_DATABASE_LOCATION);
	config.Set(kConfigOptionEnableLookupDatabaseMusicIDText, GNSDK_VALUE_TRUE);
	config.Set(kConfigOptionEnableLookupDatabaseMusicIDImages, GNSDK_VALUE_TRUE);

	GnLookupDatabase gnLookupDB(GRACENOTE_PRODUCTION_DATABASE_SAMPLE_ID, config);

	//To see detailed information about the Lookup Database, enable this:
	//const GnDataObject& infoGdo = gnLookupDB.Info();
	//const GnRenderOptions& opts = GnRenderOptions().Full().Xml();
	//std::cout << infoGdo.Render(opts) << std::endl;
}

/*-----------------------------------------------------------------------------
 *  class UserStore
 *    Example implementation of interface: IGnUserStore
 *		Loads and stores User data for the GnUser object. This sample stores the
 *		user data to a local file named 'user.txt'.
 *		Your application should store the user data to an appropriate location.
 */
class UserStore : public IGnUserStore
{
public:
	GnString
	LoadSerializedUser(gnsdk_cstr_t clientId)
	{
		std::fstream	userRegFile;
		std::string		fileName;
		std::string		serialized;
		GnString		userData;

		fileName  = "user_";
		fileName += clientId;
		fileName += ".txt";

		userRegFile.open(fileName.c_str(), std::ios_base::in);
		if (!userRegFile.fail())
		{
			userRegFile >> serialized;
			userData = serialized.c_str();
		}
		return userData;
	}

	bool
	StoreSerializedUser(gnsdk_cstr_t clientId, gnsdk_cstr_t userData)
	{
		std::fstream userRegFile;
		std::string  fileName;

		fileName  = "user_";
		fileName += clientId;
		fileName += ".txt";

		/* store user data to file */
		userRegFile.open(fileName.c_str(), std::ios_base::out);
		if (!userRegFile.fail())
		{
			userRegFile << userData;
			return true;
		}
		return false;
	}
};

/*-----------------------------------------------------------------------------
 *  LoadLocale
 *    Load a 'locale' to return locale-specific values in the Metadata.
 *    This examples loads an English locale.
 */
void
LoadLocale(GnManager& gnMgr, GnUser& user)
{
	/* Set the location of Gracenote Lists DB */
	gnMgr.LocalesStore().Location(GRACENOTE_PRODUCTION_DATABASE_LOCATION);

	/* Set locale with desired Group, Language, Region and Descriptor */
	GnLocale locale( kLocaleGroupMusic, kLanguageEnglish, kRegionDefault, kDescriptorSimplified, user, GNSDK_NULL );

	/* set this locale as default for the duration of gnsdk */
	locale.SetGroupDefault();
}

/******************************************************************
*
*    MAIN
*
******************************************************************/
int
main( int argc, char* argv[] )
{
	gnsdk_cstr_t  licenseFile        = GNSDK_NULL;
	gnsdk_cstr_t  clientId           = GNSDK_NULL;
	gnsdk_cstr_t  clientIdTag        = GNSDK_NULL;
	GnLookupMode  lookupMode         = kLookupModeInvalid;
	gnsdk_cstr_t  applicationVersion = "1.0.0.0";  /* Increment with each version of your app */


	if (argc == 5)
	{
		clientId         = argv[1];
		clientIdTag      = argv[2];
		licenseFile      = argv[3];

		if (strcmp(argv[4], "online") == 0)
		{
			lookupMode = kLookupModeOnline;
		}
		else if (strcmp(argv[4], "local") == 0)
		{
			lookupMode = kLookupModeLocal;
		}
		else
		{
			printf("Incorrect lookupMode specified.\n");
			printf("Please choose either \"local\" or \"online\"\n");
			return -1;
		}
	}
	else
	{
		std::cout << "\nUsage:  clientId clientIdTag license lookupMode\n"<< std::endl;
		return -1;
	}

	/* GNSDK initialization */
	try
	{
		GnManager gnMgr(licenseFile, kLicenseInputModeFilename);

		/* Display GNSDK Version information */
		std::cout << std::endl << "GNSDK Product Version : " << gnMgr.ProductVersion() << " \t(built " << gnMgr.BuildDate() << ")" << std::endl;

		/* Enable GNSDK logging */
		GnLog sampleLog(
			"sample.log",								/* File to write log to (optional if using delegate) */
			GnLogFilters().Error().Warning(),			/* Include only error and warning entries */
			GnLogColumns().All(),						/* Add all columns to log: timestamps, thread IDs, etc */
			GnLogOptions().MaxSize(0).Archive(false),	/* Max size of log: 0 means a new log file will be created each run. Archiving of logs disabled. */
			GNSDK_NULL									/* Optional callback delegate for logging messages */
			);
		sampleLog.Enable(kLogPackageAllGNSDK);			/* Enable for all GNSDK packages */

		/* Enable StorageSQLite module to use as our database engine */
		GnStorageSqlite::Enable();

		if (lookupMode == kLookupModeLocal)
		{
			/* Enable local database lookups */
			EnableLocalLookups();
		}

		/* Get GnUser instance to allow us to perform queries */
		GnUser    user = GnUser(clientId, clientIdTag, applicationVersion, GnManagedPtr<IGnUserStore*>(new UserStore()));

		/* set user to match our desired lookup mode (all queries done with this user will inherit the lookup mode) */
		user.Options().LookupMode(lookupMode);

		LoadLocale(gnMgr, user);

		/* Perform a sample album text query */
		doSampleAlbumSearch( user, lookupMode );
	}
	catch (GnError& e)
	{
		std::cout << "ERROR: " << e.ErrorAPI() << "\t" << std::hex << e.ErrorCode() << "\t" <<  e.ErrorDescription() << std::endl;
        return 1;
	}

	return 0;
}