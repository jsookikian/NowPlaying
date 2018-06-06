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
 *	Stores query results in a results database to be available in future offline queries or after
 *  the local database is updated.
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

#include "gnsdk.hpp"
#include "gnsdk_musicid.hpp"
#include "gnsdk_storage_sqlite.hpp"
#include "gnsdk_lookup_local.hpp"
#include "gnsdk_lookupdatabase.hpp"

#define GRACENOTE_PRODUCTION_DATABASE				"gracenote_production_database"
#define GRACENOTE_PRODUCTION_DATABASE_LOCATION		"../../../../sample_data/gdb"

#define RESULT_DATABASE								"result_database"
#define RESULT_DATABASE_LOCATION					"."


using namespace gracenote;
using namespace gracenote::musicid;
using namespace gracenote::metadata;
using namespace gracenote::lookup_local;
using namespace gracenote::storage_sqlite;
using namespace gracenote::lookupdatabase;
using namespace std;



/* If Image (Asset) retrieval is available (check Gracenote License)
 * uncomment the #def below or set CFLAGS=-GRACENOTE_ASSET_FETCH_ENABLED
 */
   //#define GRACENOTE_ASSET_FETCH_ENABLED   1 



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
 *  OpenLocalDB
 */
GnLookupDatabase
OpenLocalDB(gnsdk_cstr_t dbId, gnsdk_cstr_t dbLocation, GnConfigOptionAccess accessMode)
{
	GnConfig config;

	config.Set(kConfigOptionLocationLookupDatabaseAll, dbLocation);
	config.Set(kConfigOptionEnableLookupDatabaseMusicIDText, GNSDK_VALUE_TRUE);
	config.Set(kConfigOptionEnableLookupDatabaseMusicIDImages, GNSDK_VALUE_TRUE);
	config.Set(accessMode);

	return GnLookupDatabase(dbId, config);
}


/*-----------------------------------------------------------------------------
 *  DisplayLocalDBInfo
 */
static void
DisplayDbInfo(GnLookupDatabase db)
{
	//To see detailed information about the Lookup Database, enable this:
	/*
	GnDataObject info = db.Info();
	GnRenderOptions render;
	GnString infoStr = info.Render(render.Xml());
	cout << endl << "Gracenote DB Info:" << endl << infoStr;
	*/
}


/*-----------------------------------------------------------------------------
 *  DoTextLookup
 */
static GnDataObject
DoTextLookup(GnUser& user, GnLookupMode lookupMode)
{
	GnDataObject finalMatch = GnDataObject();

	cout << endl  << "*****Sample Album Search*****\n" << endl;

	GnMusicId music_id(user, GNSDK_NULL);
	music_id.Options().LookupMode(lookupMode);

#if GRACENOTE_ASSET_FETCH_ENABLED
	music_id.Options().LookupData(kLookupDataContent, true);
	music_id.Options().PreferResultCoverart(true);
#endif

	/*** Set the input text as album title, artist name, track title and perfor the query****/
	GnResponseDataMatches response = music_id.FindMatches(
		"Supernatural", 
		"Africa Bamba", 
		"Santana", 
		GNSDK_NULL, 
		GNSDK_NULL
	);

	/* See how many albums were found. */
	gnsdk_uint32_t count = response.DataMatches().count();

	if (count != 0)
	{
		gnsdk_uint32_t	choice_ordinal = 0;
		bool			needs_decision = response.NeedsDecision();

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
 *  doAssetFetchAndPersistResult for album match
 */
static void
doAssetFetchAndPersistResult(GnUser& user, GnLookupMode lookupMode, GnAlbum& album, GnLookupDatabase& persistDB)
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

			if (!url || std::string(url).empty())
				continue;

			if (kContentTypeImageCover == content.ContentType())
			{
				GnAssetFetch          gnAssetFetch(user, url, lookupMode);
				const gnsdk_byte_t*   img  = gnAssetFetch.Data();
				gnsdk_size_t          size = gnAssetFetch.Size();

				if (img && size)
				{
					persistDB.AddImage((gnsdk_byte_t*)img, size, asset/*for metadata*/);
					cout << "Asset successfully added to the result database." << std::endl
							<<	"\tAsset Url: " << url << std::endl
							<< "\tAsset Size: " << size << std::endl;
				}
			}
		}
	}
}

/*-----------------------------------------------------------------------------
 *  doAssetFetchAndPersistResult for contributor match
 */
static void
doAssetFetchAndPersistResult(GnUser& user, GnLookupMode lookupMode, GnContributor& contrib, GnLookupDatabase& persistDB)
{
	content_iterator Iter = contrib.Contents().begin();

	for (; Iter != contrib.Contents().end(); ++Iter)
	{
		 GnContent content = *Iter;
		 asset_iterator aIter = content.Assets().begin();

		 for (; aIter != content.Assets().end(); ++aIter)
		 {
			GnAsset asset = *aIter;
			gnsdk_cstr_t url = GNSDK_NULL;

			if (kLookupModeLocal == lookupMode)
				url = asset.UrlGnsdk();
			else
				url = asset.UrlHttp();

			if (!url || std::string(url).empty())
				continue;

			if (kContentTypeImageArtist == content.ContentType())
			{
				GnAssetFetch          gnAssetFetch(user, url, lookupMode);
				const gnsdk_byte_t*   img  = gnAssetFetch.Data();
				gnsdk_size_t          size = gnAssetFetch.Size();

				if (img && size)
				{
					persistDB.AddImage((gnsdk_byte_t*)img, size, asset/*for metadata*/);
					cout << "Asset successfully added to the result database." << std::endl
							<<	"\tAsset Url: " << url << std::endl
							<< "\tAsset Size: " << size << std::endl;
				}
			}
		}
	}
}


/***************************************************************************
 *
 *    _DO_SAMPLE_QUERY_AND_PERSIST_RESULT
 *
 *      Performs a local/online lookup and persists result in Gracenote R/W Lookup DataBase.
 *
 ***************************************************************************/
void
DoQueryAndPersistResult(GnUser& user, GnLookupMode lookupMode)
{
	/* Open database for persisting results (and querying) */
	GnLookupDatabase persistDB = OpenLocalDB(RESULT_DATABASE, RESULT_DATABASE_LOCATION, kConfigOptionAccessLookupDatabaseReadWrite);
	DisplayDbInfo(persistDB);

	if ( kLookupModeLocal == lookupMode )
	{
		/* Open base database for querying */
		GnLookupDatabase baseDB = OpenLocalDB(GRACENOTE_PRODUCTION_DATABASE, GRACENOTE_PRODUCTION_DATABASE_LOCATION, kConfigOptionAccessLookupDatabaseReadOnly);
		DisplayDbInfo(baseDB);
	}

	GnDataObject match = DoTextLookup(user, lookupMode);

	/* if no match found and lookupMode is not local-only */
	if (match.IsNull() && (lookupMode == kLookupModeOnline))
	{
		match = DoTextLookup(user, kLookupModeOnlineNoCache);
	}

	if (!match.IsNull())
	{
		GnAlbum album = GnAlbum();
		GnContributor contrib = GnContributor();

		/*	-- Persist the match's metadata and images --
		*  Note: You can omit adding the match's record (metadata) to the local database if you only want to
		*  persist its image assets to be retrieved later for the same associated match from online.
		*  From the online match, the local image url can be retrieved via asset.GetUrlGnsdk().
		*  Caveat: where no local image exists, this call returns a non-empty url
		*  that results in an "item not found" exception when fetched.
		*/
		if (match.IsType(GnAlbum().GnType()))
		{
			album = GnAlbum().From(match);
			persistDB.AddRecord(album);
#if GRACENOTE_ASSET_FETCH_ENABLED
			doAssetFetchAndPersistResult(user, lookupMode, album, persistDB);
#endif
		}
		else if (match.IsType(GnContributor().GnType()))
		{
			contrib = GnContributor().From(match);
			persistDB.AddRecord(contrib);
#if GRACENOTE_ASSET_FETCH_ENABLED
			doAssetFetchAndPersistResult(user, lookupMode, contrib, persistDB);
#endif
		}
		cout << endl << "Match successfully added to the result database." << endl << endl;	
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

	}
	
	if (argc != 5 || lookupMode == kLookupModeInvalid)
	{
		cout << "\nUsage:  clientId clientIdTag license [local|online]\n"<< endl;
		return -1;
	}

	try
	{
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


		/**********   Perform text query and persist result   **********/
		DoQueryAndPersistResult(user, lookupMode);

	}
	catch (GnError& e)
	{
		cout << "ERROR: " << e.ErrorAPI() << "\t" << hex << e.ErrorCode() << "\t" <<  e.ErrorDescription() << endl;
		return 1;
	}

	return 0;
}
