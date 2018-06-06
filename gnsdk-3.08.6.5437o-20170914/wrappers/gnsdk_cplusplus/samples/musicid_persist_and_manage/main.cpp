/*
 * Copyright (c) 2000-2016 Gracenote.
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
#include <stdlib.h>
#include <sys/stat.h>

#include "gnsdk.hpp"
#include "gnsdk_musicid.hpp"
#include "gnsdk_storage_sqlite.hpp"
#include "gnsdk_lookup_local.hpp"
#include "gnsdk_lookupdatabase.hpp"

#ifdef _WIN32
	#include <windows.h>
#endif

#define GRACENOTE_PRODUCTION_DATABASE				"gracenote_production_database"
#define GRACENOTE_PRODUCTION_DATABASE_LOCATION		"../../../../sample_data/gdb"

#define RESULT_DATABASE_A                           "result_database_a"
#define RESULT_DATABASE_A_LOCATION                  "result_database_a"

#define RESULT_DATABASE_B                           "result_database_b"
#define RESULT_DATABASE_B_LOCATION                  "result_database_b"

#define RESULT_STORE_ALOCATION_SIZE_BYTES            36864


using namespace gracenote;
using namespace gracenote::musicid;
using namespace gracenote::metadata;
using namespace gracenote::lookup_local;
using namespace gracenote::storage_sqlite;
using namespace gracenote::lookupdatabase;
using namespace std;


/*-----------------------------------------------------------------------------
 * Text inputs used by this sample app
 */
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
		fstream userRegFile;
		string  fileName;
		string  serialized;
		GnString     userData;

		fileName  = "user_";
		fileName += clientId;
		fileName += ".txt";

		userRegFile.open(fileName.c_str(), ios_base::in);
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
		fstream userRegFile;
		string  fileName;

		fileName  = "user_";
		fileName += clientId;
		fileName += ".txt";

		/* store user data to file */
		userRegFile.open(fileName.c_str(), ios_base::out);
		if (!userRegFile.fail())
		{
			userRegFile << userData;
			return true;
		}
		return false;
	}

};


class LookupDB
{
	public:
		LookupDB(gnsdk_cstr_t _id, gnsdk_cstr_t _location, GnConfigOptionAccess _access_mode) throw (GnError)
		{
			id = _id;

			config = new GnConfig();
			config->Set(kConfigOptionLocationLookupDatabaseAll, _location);
			config->Set(kConfigOptionEnableLookupDatabaseMusicIDText, GNSDK_VALUE_TRUE);
			config->Set(_access_mode);

			p_GnLookupDB = new GnLookupDatabase(id, *config);
		}

		~LookupDB()
		{	
			delete config;
			delete p_GnLookupDB;			
		}

		void ReCreate()
		{
			p_GnLookupDB->Close();
			GnLookupDatabase::Delete(*config);
			p_GnLookupDB = new GnLookupDatabase(id, *config);
		}

		void DisplayDbInfo()
		{
			//To see detailed information about the Lookup Database, enable this:
			/*
			GnDataObject info = p_GnLookupDB->Info();
			GnRenderOptions render;
			GnString infoStr = info.Render(render.Xml());	
			cout << endl << "Gracenote DB Info:" << endl << infoStr;
			*/
		}

		GnLookupDatabase *p_GnLookupDB;
		gnsdk_cstr_t id;
		GnConfig* config;
};


/*-----------------------------------------------------------------------------
 *  DoMatchSelection
 */
static int
DoMatchSelection(GnResponseDataMatches& response)
{
	/*
		This is where any matches that need resolution/disambiguation are iterated
		and a single selection of the best match is made.

		For this simplified sample, we'll just echo the matches and select the first match.
	*/
	cout << "Match count:" << response.DataMatches().count() << endl;

	metadata::datamatch_iterator it_match = response.DataMatches().begin();
	for (; it_match != response.DataMatches().end(); ++it_match)
	{
		if (it_match->IsAlbum())
		{
			cout << "\t Title:" << it_match->GetAsAlbum().Title().Display() << endl;
		}
		else if (it_match->IsContributor())
		{
			cout << "\t Name:" << it_match->GetAsContributor().NamesOfficial().at(0)->Display() << endl;
		}

	}

	return 0;
}


/*-----------------------------------------------------------------------------
 *  LoadLocale
 *    Load a 'locale' to return locale-specific values in the Metadata.
 *    This examples loads an English locale.
 */
void
LoadLocale(GnManager& gnMgr, const GnUser& gnUser)
{
	/* Set the location of Gracenote Lists DB */
	gnMgr.LocalesStore().Location(GRACENOTE_PRODUCTION_DATABASE_LOCATION);

	/* Set locale with desired Group, Language, Region and Descriptor */
	GnLocale locale(kLocaleGroupMusic, kLanguageEnglish, kRegionDefault, kDescriptorSimplified, gnUser, GNSDK_NULL);

	/* set this locale as default for the duration of gnsdk */
	locale.SetGroupDefault();
}


/*-----------------------------------------------------------------------------
 *  DoTextLookup
 */
static GnDataObject
DoTextLookup(GnUser& user, GnLookupMode lookupMode, g_sample_input_t text_input)
{
	GnDataObject finalMatch = GnDataObject();

	cout << endl  << "*****MusicID Query*****\n" << endl;

	GnMusicId          music_id(user, GNSDK_NULL);
	music_id.Options().LookupMode(lookupMode);

	/*** Set the input text as album title, artist name, track title and perform the query****/
	GnResponseDataMatches response = music_id.FindMatches(
		text_input.album_title, 
		text_input.track_title, 
		text_input.artist_name, 
		GNSDK_NULL, 
		GNSDK_NULL
	);

	/* See how many matches were found. */
	gnsdk_uint32_t count = response.DataMatches().count();

	if (count != 0)
	{
		bool needs_decision = response.NeedsDecision();
		gnsdk_uint32_t choice_ordinal = 0;

		/* See if selection of one of the albums needs to happen */
		if (needs_decision)
		{
			choice_ordinal = DoMatchSelection(response);

		}
		else
		{
			/* no need for disambiguation, we'll take the first album */
			choice_ordinal = 0; /* Since iterator starts reading from 0th position in the list*/
		}

		GnDataMatch match = *(response.DataMatches().at(choice_ordinal));

		if (match.IsAlbum())
		{
			GnAlbum album = match.GetAsAlbum();
			bool fullResult = album.IsFullResult();

			/* if we only have a partial result, we do a follow-up query to retrieve the full album */
			if (!fullResult)
			{
				/* do followup query to get full object. Setting the partial album as the query input. */
				GnResponseAlbums followup_response = music_id.FindAlbums(album);

				/* now our first album is the desired result with full data */
				album = *(followup_response.Albums().begin());
			}

			cout << endl << "Final match:" << endl;
			cout << "\t Title:" << album.Title().Display() << endl;
			finalMatch = album;
		}
		else
		{
			GnContributor contrib = match.GetAsContributor();

			/* contributor match is always a full result */
			cout << endl << "Final match:" << endl;
			cout << "\t Name: " << contrib.NamesOfficial().at(0)->Display() << endl;
			finalMatch = contrib;
		}
	}

	return finalMatch;
}

/*-----------------------------------------------------------------------------
 *    ManageResultDBSize
 *
 *    Checks size of the result store with the most recent results.
 *    If it has hit the size limit, deletes the store with older results,
 *    makes the recent result store the "new" older results store,
 *    creates a new result store for more recent results.
 *
 */
void ManageResultDBSize(LookupDB DBs[], gnsdk_uint16_t &current_db_index)
{
	int old_db_index = (current_db_index + 1) % 2;
	if (DBs[current_db_index].p_GnLookupDB->Size() > RESULT_STORE_ALOCATION_SIZE_BYTES/2)
	{
		printf("Size limit hit. Remove old results and start new recent-results database.\n");
		DBs[old_db_index].ReCreate();
		current_db_index = old_db_index;
	}

}


/*-----------------------------------------------------------------------------
 *
 *    DoQueriesAndPersistResults
 *
 *      Performs a local/online lookup and persists result in Gracenote R/W Lookup DataBase.
 */
void
DoQueriesAndPersistResults(GnUser& user, GnLookupMode lookupMode)
{
	/* Open base database for querying */
	if (lookupMode == kLookupModeLocal)
	{
		LookupDB base_db = LookupDB(GRACENOTE_PRODUCTION_DATABASE, GRACENOTE_PRODUCTION_DATABASE_LOCATION, kConfigOptionAccessLookupDatabaseReadOnly);
		base_db.DisplayDbInfo();
	}

	/* Open databases for storing and querying */
	LookupDB result_dbs[2] = { 
		LookupDB(RESULT_DATABASE_A, RESULT_DATABASE_A_LOCATION, kConfigOptionAccessLookupDatabaseReadWrite),
		LookupDB(RESULT_DATABASE_B, RESULT_DATABASE_B_LOCATION, kConfigOptionAccessLookupDatabaseReadWrite)
	};

	/* For simplicity we are assigning current to DB index 0 
     * You will need to keep track of which database has recent results between sessions. 
	 */
	gnsdk_uint16_t current_db_index = 0;

	for (unsigned int i=0; i < sizeof(g_sample_input)/sizeof(g_sample_input[0]); i++)
	{
		/* do local lookup */
		GnDataObject match = DoTextLookup(user, kLookupModeLocal, g_sample_input[i]);

		/* do online lookup if no match was found and lookupMode allows */
		if (match.IsNull() && (lookupMode == kLookupModeOnline))
		{
			match = DoTextLookup(user, kLookupModeOnlineNoCache, g_sample_input[i]);
		}

		if (!match.IsNull())
		{
			if (match.IsType(GnAlbum().GnType()))
			{
				result_dbs[current_db_index].p_GnLookupDB->AddRecord(GnAlbum().From(match));
			}
			else if (match.IsType(GnContributor().GnType()))
			{
				result_dbs[current_db_index].p_GnLookupDB->AddRecord(GnContributor().From(match));
			}
			cout << endl << "Match successfully added to the result database " << (current_db_index==0? "A":"B") << endl << endl;

			/* manage database size */
			ManageResultDBSize(result_dbs, current_db_index);
		}
		else
		{
			cout << "No match found for input: "<<g_sample_input[i].album_title<<endl; 		
		}
	}
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
	
	if (argc != 5 || lookupMode == kLookupModeInvalid)
	{
		cout << "\nUsage:  clientId clientIdTag license [local|online]\n"<< endl;
		return -1;
	}

	try
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
		GnManager gnMgr(licenseFile, kLicenseInputModeFilename);

		/* Display GNSDK Version infomation */
		cout << endl << "GNSDK Product Version : " << gnMgr.ProductVersion() << " \t(built " << gnMgr.BuildDate() << ")" << endl;

		/* Enable GNSDK logging */
		GnLog sampleLog(
		    "sample.log",                               /* File to write log to (optional if using delegate) */
		    GnLogFilters().Error().Warning(),           /* Include only error and warning entries */
		    GnLogColumns().All(),                       /* Add all columns to log: timestamps, thread IDs, etc */
		    GnLogOptions().MaxSize(0).Archive(false),   /* Max size of log: 0 means a new log file will be created each run. Archiving of logs disabled. */
		    GNSDK_NULL                                  /* Optional callback delegate for logging messages */
		    );
		sampleLog.Enable(kLogPackageAllGNSDK);          /* Enable for all GNSDK packages */

		/* Enable storage module */
		GnStorageSqlite::Enable();

		/* Enable local database lookups */
		GnLookupLocal::Enable();

		/* Get GnUser instance to allow us to perform queries */
		GnUser user = GnUser(clientId, clientIdTag, applicationVersion, GnManagedPtr<IGnUserStore*>(new UserStore()));

		/* set user to match our desired lookup mode (all queries done with this user will inherit the lookup mode) */
		user.Options().LookupMode(lookupMode);

		/* Set the 'locale' to return locale-specific results values. This example loads an English locale. */
		LoadLocale(gnMgr, user);

	
		/**********   Perform a MusicID query and persist result   **********/
		DoQueriesAndPersistResults(user, lookupMode);

	}
	catch (GnError& e)
	{
		cout << "ERROR: " << e.ErrorAPI() << "\t" << hex << e.ErrorCode() << "\t" <<  e.ErrorDescription() << endl;
		return 1;
	}

	return 0;
}
