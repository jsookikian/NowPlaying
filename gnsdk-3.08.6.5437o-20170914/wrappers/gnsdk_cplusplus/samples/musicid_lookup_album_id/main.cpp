/*
 * Copyright (c) 2000-2015 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/*
 * Name: MusicID album identifier lookup sample application
 * Description:
 * This example looks up an Album using a TUI.
 *
 * Command-line Syntax:
 * sample client_id client_id_tag license [local|online]
 */

/* Online vs Local queries
 *  For local queries, a Gracenote local database must be present.
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

/* Callback delegate called when performing queries */
class LookupStatusEvents : public IGnStatusEvents
{
	/*-----------------------------------------------------------------------------
	 *  StatusEvent
	 */
	void
	StatusEvent(GnStatus status, gnsdk_uint32_t percentComplete, gnsdk_size_t bytesTotalSent, gnsdk_size_t bytesTotalReceived, IGnCancellable& canceller)
	{
		std::cout << "status (";

		switch (status)
		{
		case gnsdk_status_unknown:
			std::cout << "Unknown ";
			break;

		case gnsdk_status_begin:
			std::cout << "Begin ";
			break;

		case gnsdk_status_connecting:
			std::cout << "Connecting ";
			break;

		case gnsdk_status_sending:
			std::cout << "Sending ";
			break;

		case gnsdk_status_receiving:
			std::cout << "Receiving ";
			break;

		case gnsdk_status_disconnected:
			std::cout << "Disconnected ";
			break;

		case gnsdk_status_complete:
			std::cout << "Complete ";
			break;

		default:
			break;
		}

		std::cout << "), % complete (" << percentComplete << "), sent (" << bytesTotalSent << "), received (" << bytesTotalReceived << ")" << std::endl;

		GNSDK_UNUSED(canceller);
	}

};


/*-----------------------------------------------------------------------------
 *  doMatchSelection
 */
static int
doMatchSelection(GnResponseAlbums& response)
{
	/*
	   This is where any matches that need resolution/disambiguation are iterated
	   and a single selection of the best match is made.

	   For this simplified sample, we'll just echo the matches and select the first match.
	 */
	printf("%16s %d\n", "Match count:", response.Albums().count());

	metadata::album_iterator it_album = response.Albums().begin();
	for (; it_album != response.Albums().end(); ++it_album )
	{
		printf("%16s %s\n", "Title:", it_album->Title().Display() );

	}

	return 0;
}


/*-----------------------------------------------------------------------------
 *  queryAlbumLookup
 */
static void
queryAlbumLookup(GnUser& user, gnsdk_cstr_t id, gnsdk_cstr_t tag)
{
	bool           needs_decision = false;
	gnsdk_uint32_t choice_ordinal = 0;

	printf("\n*****MusicID ID Query*****\n");

	/* Create GDO from given ID
	** (using GnAlbum constructor because we know beforehand that this ID came
	** from an Album response) */
	GnAlbum albObject(id, tag);

	/* Perform the query */
	GnMusicId music_id(user);
	GnResponseAlbums response = music_id.FindAlbums(albObject);

	int count = response.Albums().count();
	if (count == 0)
	{
		printf("\nNo albums found for the input.\n");
	}
	else
	{
		needs_decision = response.NeedsDecision();

		/* See if selection of one of the albums needs to happen */
		if (needs_decision)
		{
			choice_ordinal = doMatchSelection(response);

		}
		else
		{
			/* no need for disambiguation, we'll take the first album */
			choice_ordinal = 0; /* Since iterator starts reading from 0th position in the list*/
		}

		GnAlbum album = *(response.Albums().at(choice_ordinal));

		bool fullResult = album.IsFullResult();

		/* if we only have a partial result, we do a follow-up query to retrieve the full album */
		if (!fullResult)
		{
			/* do followup query to get full object. Setting the partial album as the query input. */
			GnResponseAlbums followup_response = music_id.FindAlbums(album);

			/* now our first album is the desired result with full data */
			album = *(followup_response.Albums().begin());

		}
		printf("%16s\n", "Final album:");
		printf("%16s %s\n", "Title:", album.Title().Display() );
		printf("%16s %s\n", "Artist:", album.Artist().Name().Display() );
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
	GnLookupLocal& gnLookupLocal = GnLookupLocal::Enable();

	GnConfig config;
	config.Set(kConfigOptionLocationLookupDatabaseAll, GRACENOTE_PRODUCTION_DATABASE_LOCATION);	
	config.Set(kConfigOptionEnableLookupDatabaseMusicID, GNSDK_VALUE_TRUE);

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
	/*-----------------------------------------------------------------------------
	 *  LoadSerializedUser
	 */
	GnString
	LoadSerializedUser(gnsdk_cstr_t clientId)
	{
		std::fstream userRegFile;
		std::string  fileName;
		std::string  serialized;
		GnString     userData;

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

	/*-----------------------------------------------------------------------------
	 *  StoreSerializedUser
	 */
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
	LookupStatusEvents localeEvents;

	gnMgr.LocalesStore().Location(GRACENOTE_PRODUCTION_DATABASE_LOCATION);

	/* Set locale with desired Group, Language, Region and Descriptor */
	GnLocale locale(kLocaleGroupMusic, kLanguageEnglish, kRegionDefault, kDescriptorSimplified, user, &localeEvents);

	/* set this locale as default for the duration of gnsdk */
	locale.SetGroupDefault();
}

/******************************************************************
*
*    MAIN
*
******************************************************************/
int
main(int argc, char* argv[])
{
	gnsdk_cstr_t licenseFile        = GNSDK_NULL;
	gnsdk_cstr_t clientId           = GNSDK_NULL;
	gnsdk_cstr_t clientIdTag        = GNSDK_NULL;
	GnLookupMode lookupMode         = kLookupModeInvalid;
	gnsdk_cstr_t applicationVersion = "1.0.0.0";   /* Increment with each version of your app */


	if (argc == 5)
	{
		clientId    = argv[1];
		clientIdTag = argv[2];
		licenseFile = argv[3];

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

		/* Display GNSDK Version infomation */
		std::cout << std::endl << "GNSDK Product Version : " << gnMgr.ProductVersion() << " \t(built " << gnMgr.BuildDate() << ")" << std::endl;

		/* Enable GNSDK logging */
		GnLog sampleLog(
			"sample.log",                               /* File to write log to (optional if using delegate) */
			GnLogFilters().Error().Warning(),           /* Include only error and warning entries */
			GnLogColumns().All(),                       /* Add all columns to log: timestamps, thread IDs, etc */
			GnLogOptions().MaxSize(0).Archive(false),   /* Max size of log: 0 means a new log file will be created each run. Archiving of logs disabled. */
			GNSDK_NULL                                  /* Optional callback delegate for logging messages */
			);
		sampleLog.Enable(kLogPackageAllGNSDK);          /* Enable for all GNSDK packages */

		/* Enable StorageSQLite module to use as our database engine */
		GnStorageSqlite::Enable();

		if (lookupMode == kLookupModeLocal)
		{
			/* Enable local database lookups */
			EnableLocalLookups();
		}

		/* Get GnUser instance to allow us to perform queries */
		GnUser user = GnUser(clientId, clientIdTag, applicationVersion, GnManagedPtr<IGnUserStore*>(new UserStore()));

		/* set user to match our desired lookup mode (all queries done with this user will inherit the lookup mode) */
		user.Options().LookupMode(lookupMode);

		LoadLocale(gnMgr, user);

		queryAlbumLookup(user, "5154004", "0168B3134B141081DE907A15E792D4E0");
	}
	catch (GnError& e)
	{
		std::cout << "ERROR: " << e.ErrorAPI() << "\t" << std::hex << e.ErrorCode() << "\t" <<  e.ErrorDescription() << std::endl;
		return 1;
	}

	return 0;
}

