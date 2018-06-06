/*
 * Copyright (c) 2000-2015 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */
/*
 * Name: MusicIDPersistResults
 * Description:
 *  Stores query results in a results database to be available in future offline queries or after
 *  the local database is updated.
 *
 * Command line arguments:
 * clientId clientIdTag license gnsdkLibraryPath lookupMode
 *
 * To build and run using GNSDK makefiles:
 * 1. Customize .../wrappers/gnsdk_java/samples/sample_vars.mk and set:
 *   a. CID=<your Client ID>
 *   b. CTAG=<your Client Tag>
 *   c. LIC=<path to your GNSDK license file>
 *   d. LOCAL=<online or local>
 * 2. Navigate to the sample directory
 * 3. Build "make"
 * 4. Run "make run"
 */

package musicid_persist_results;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import com.gracenote.gnsdk.*;
public class MusicIDPersistResults {

	final String CLIENT_APP_VERSION                         = "1.0.0.0";    // Version of application

	final String GRACENOTE_PRODUCTION_DATABASE              = "gracenote_production_database";
	final String GRACENOTE_PRODUCTION_DATABASE_LOCATION     = "../../../../sample_data/gdb";

	final String RESULT_DATABASE                            = "result_database";
	final String RESULT_DATABASE_LOCATION                   = ".";


	// Load GNSDK native libraries
	static {
		try {
			System.loadLibrary("gnsdk_java_marshal");
		} catch (UnsatisfiedLinkError unsatisfiedLinkError) {
			System.err.println("Native code library failed to load\n" + unsatisfiedLinkError.getMessage());
		}
	}

	//=============================================================================================
	//
	// main
	//
	//=============================================================================================
	public static void main(String[] args) {

		if (args.length != 5) {
			System.out.println("Usage : clientId clientIdTag license gnsdkLibraryPath lookupMode");
			System.exit(-1);
			return;
		}

		GnLookupMode lookupMode;

		if (args[4].trim().equals("online")) {
			lookupMode = GnLookupMode.kLookupModeOnline;
		}
		else if (args[4].trim().equals("local")) {
			lookupMode = GnLookupMode.kLookupModeLocal;
		}
		else
		{
			System.out.println("Incorrect lookup mode specified.");
			System.out.println("Please choose either \"local\" or \"online\".");
			System.exit(-1);
			return;
		}

		try {
			
			new MusicIDPersistResults().doSample(
					args[0].trim(),     // Client ID
					args[1].trim(),     // Client ID Tag
					args[2].trim(),     // License
					args[3].trim(),     // GNSDK Library Path
					lookupMode
			);

		} catch (GnException gnException) {
			System.out.println("GnException \t" + gnException.getMessage());
			System.exit(-1);
		} finally {
			System.runFinalization();
			System.gc();
		} 
	}

	//=============================================================================================
	// doSample
	//
	void
	doSample(String clientId, String clientIdTag, String license, String gnLibPath, GnLookupMode lookupMode) throws GnException{

		// Initialize GNSDK
		// Note: For Android GnManager constructors are different. Consult documentation for more information.
		GnManager gnManager = new GnManager(gnLibPath, license, GnLicenseInputMode.kLicenseInputModeFilename);

		// Display GNSDK Version information
		System.out.println("\nGNSDK Product Version : " + GnManager.productVersion() + "\t(built " + GnManager.buildDate() + ")");

		// Enable GNSDK logging
		GnLog sampleLog = new GnLog("sample.log", null );
		sampleLog.filters(new GnLogFilters().error().warning());                // Include only error and warning entries
		sampleLog.columns(new GnLogColumns().all());                            // Add all columns to log: timestamps, thread IDs, etc
		sampleLog.options(new GnLogOptions().maxSize (new BigInteger("0") ));   // Max size of log: 0 means a new log file will be created each run
		sampleLog.options(new GnLogOptions().archive( false ));                 // True = old logs will be renamed and saved. False = new log each time
		// To enable logging package call enable with the package. Enable can be called multiple times to turn on multiple packages
		sampleLog.enable(GnLogPackageType.kLogPackageAll);

		// Initialize SQLite module
		GnStorageSqlite.enable();

		// Initialize Local lookup module
		GnLookupLocal.enable();

		// Get User handle to allow us to perform queries
		GnUser gnUser = new GnUser(new UserStore(), clientId, clientIdTag, CLIENT_APP_VERSION);

		// set user to match our desired lookup mode (all queries done with this user will inherit the lookup mode)
		gnUser.options().lookupMode( lookupMode );

		// Load a 'locale' to return locale-specifc results values. This examples loads an English locale.
		loadLocale( gnManager, gnUser );

		// Do sample text search and store result in lookup database
		doSampleQueryAndPersistResult(gnUser, lookupMode);
	}

	//=============================================================================================
	// openLocalDB
	//
	GnLookupDatabase openLocalDB(String dbId, String dbLocation, GnConfigOptionAccess accessMode) throws GnException
	{
		GnConfig config = new GnConfig();

		config.set(GnConfigOptionLocation.kConfigOptionLocationLookupDatabaseAll, dbLocation);
		config.set(GnConfigOptionEnable.kConfigOptionEnableLookupDatabaseMusicIDText, true);
		config.set(GnConfigOptionEnable.kConfigOptionEnableLookupDatabaseMusicIDImages, true);

		config.set(accessMode);

		return new GnLookupDatabase(dbId, config);
	}

	//=============================================================================================
	// displayDbInfo
	//
	void displayDbInfo(GnLookupDatabase gnLookupDB) throws GnException
	{
		// To see detailed information about the lookup database, enable this:
		/*    GnDataObject dbInfo = gnLookupDB.info();
			GnString dbInfoXml = null;

			dbInfoXml = dbInfo.render((new GnRenderOptions()).xml());
			System.out.println("Gracenote Local Database Info : \n" + dbInfoXml); */
	}


	//=============================================================================================
	// doSampleQueryAndPersistResult
	//
	void doSampleQueryAndPersistResult(GnUser gnUser, GnLookupMode lookupMode) throws GnException
	{
		// Open database for persisting results (and querying)
		GnLookupDatabase persistDB = openLocalDB(RESULT_DATABASE, RESULT_DATABASE_LOCATION, GnConfigOptionAccess.kConfigOptionAccessLookupDatabaseReadWrite);
		displayDbInfo(persistDB);

		if ( GnLookupMode.kLookupModeLocal == lookupMode )
		{
			// Open base database for querying
			GnLookupDatabase baseDB = openLocalDB(GRACENOTE_PRODUCTION_DATABASE, GRACENOTE_PRODUCTION_DATABASE_LOCATION, GnConfigOptionAccess.kConfigOptionAccessLookupDatabaseReadOnly);
			displayDbInfo(baseDB);
		}

		// do local lookup
		GnDataObject matchResult = doSampleMusicIDQuery(gnUser, GnLookupMode.kLookupModeLocal);

		// do online lookup if no match was found and lookupMode allows
		if (matchResult == null && lookupMode == GnLookupMode.kLookupModeOnline)
		{
			matchResult = doSampleMusicIDQuery(gnUser, GnLookupMode.kLookupModeOnlineNoCache);
		}

		// store match and image asset in lookup database
		if (matchResult != null) {

			GnAsset asset = null;

			/* -- Persist the match's metadata --
			*  Note: You can omit adding the match's record (metadata) to the local database if you only want to
			*  persist its image assets to be retrieved later for the same associated match from online.
			*/

			if(matchResult.isType(GnAlbum.gnType())) {
				GnAlbum album = GnAlbum.from(matchResult);
				persistDB.addRecord(album);
				asset = album.coverArt().assets().at(0).next(); //asset(GnImageSize.kImageSize170);

			}
			else if(matchResult.isType(GnContributor.gnType()))
			{
				GnContributor contrib = GnContributor.from(matchResult);
				persistDB.addRecord(contrib);
				asset = contrib.image().asset(GnImageSize.kImageSize170);
			}

			System.out.println("Match successfully added to the result database.");

			/* --Persist image asset--
			 * Note: if the album is an online match whose image assets might have been added to
			 * the local database previously (without the corresponding record),
			 * the local image url can still be retrieved via asset.urlGnsdk().
			 * Caveat: where no local image exists, this call returns a non-empty url
			 * that results in an "item not found" exception when fetched.
			 */
			if(asset != null) {

				String url = null;
				url = asset.urlGnsdk();

				if (!url.isEmpty()) {
					GnAssetFetch assetFetch = new GnAssetFetch(gnUser, url, lookupMode);
					persistDB.addImage(assetFetch.data(), assetFetch.size(), asset);
					System.out.println("Asset successfully added to the result database.");
				}
			}
		}
		else{
			System.out.println("No match found\n");
		}
	}


	//=============================================================================================
	// doSampleMusicIDQuery
	//
	GnDataObject
	doSampleMusicIDQuery( GnUser gnUser, GnLookupMode lookupMode ) throws GnException {

		System.out.printf("\n-----------MusicID Query--------\n");

		GnMusicId mid = new GnMusicId(gnUser); // provide status events delegate instead of null to view progress
		mid.options().lookupMode(lookupMode);
		mid.options().lookupData(GnLookupData.kLookupDataContent, true);
		mid.options().preferResultCoverart(true);

		// Perform the query with input text as album title, artist name, track title
		GnResponseDataMatches matchResponse = mid.findMatches("Supernatural", "Africa Bamba", "Santana", null, null);
		GnDataObject finalMatch = null;

		// See if we need any follow-up queries or disambiguation
		if ( matchResponse.dataMatches().count() > 0 ){

			int choiceIndex;

			// we have at least one album, see if disambiguation (match resolution) is necessary.
			if ( matchResponse.needsDecision() ){

				choiceIndex = doMatchSelection( matchResponse );

			} else {

				// no need for disambiguation, we'll take the first album
				choiceIndex = 0;
			}

			GnDataMatch match = matchResponse.dataMatches().at(choiceIndex).next();
			if (match.isAlbum()) {
				GnAlbum album = match.getAsAlbum();

				// See if the album has full data or only partial data.
				// If we only have a partial result, we do a follow-up query to retrieve the full album
				if (!album.isFullResult()) {

					// do followup query to get full object. Setting the partial album as the query input.
					GnResponseAlbums albumResponse = mid.findAlbums(album);
					album = albumResponse.albums().at(0).next();
				}

				// We should now have our final, full album result.
				System.out.printf("%16s\n", "Final album:");
				displayAlbum(album);
				finalMatch = album;
			}
			else {
				GnContributor contrib = match.getAsContributor();

				System.out.printf("%16s\n", "Final match:");
				displayMatch(match);

				// contributor match is always a full result
				finalMatch = contrib;
			}
		}

		return finalMatch;
	}


	//=============================================================================================
	// loadLocale
	//  Load a 'locale' to return locale-specific values in the Metadata.
	//  This examples loads an English locale.
	//
	void
	loadLocale( GnManager gnManager, GnUser gnUser ) throws GnException {

		// Set the location of Gracenote Lists DB
		gnManager.localesStore().location(GRACENOTE_PRODUCTION_DATABASE_LOCATION);

		GnLocale locale = new GnLocale(
				GnLocaleGroup.kLocaleGroupMusic,
				GnLanguage.kLanguageEnglish,
				GnRegion.kRegionDefault,
				GnDescriptor.kDescriptorDefault,
				gnUser);

		// Setting the 'locale' as default
		// If default not set, no locale-specific results would be available
		locale.setGroupDefault();

		// GnSDK will hold onto the locale when set as default
		// so it's ok to allow our reference to go out of scope
	}

	//=============================================================================================
	// doMatchSelection
	//
	int
	doMatchSelection( GnResponseDataMatches matchResponse ) throws GnException {

		// This is where any matches that need resolution/disambiguation are iterated
		// and a single selection of the best match is made.
		//
		// For this simplified sample, we'll just echo the matches and select the first match.
		System.out.printf( "%16s %d\n", "Match count:", matchResponse.dataMatches().count() );

		GnDataMatchIterator iter = matchResponse.dataMatches().getIterator();
		while ( iter.hasNext() ){
			displayMatch( iter.next() );
		}

		return 0;
	}


	//=============================================================================================
	// displayMatch
	//
	void
	displayMatch( GnDataMatch dataMatch ) throws GnException {
		if (dataMatch.isAlbum()) {
			// Display Album match
			GnAlbum album = dataMatch.getAsAlbum();
			System.out.printf("%16s %s\n", "Title:", album.title().display());

		} else if (dataMatch.isContributor()) {
			// Display Contributor match
			GnContributor contrib = dataMatch.getAsContributor();
			GnName name = contrib.namesOfficial().at(0).next();
			System.out.printf("%16s %s\n", "Name:", name.display());
		} else {
			System.out.printf("\nUnsupported match data type: %s\n", dataMatch.getType());
		}
	}

	//=============================================================================================
	// displayAlbum
	//
	void
	displayAlbum(GnAlbum album) throws GnException {
		System.out.printf( "%16s %s\n", "Title:", album.title().display() );
	}


	//=============================================================================================
	// UserStore
	// Persistent store and recall of serialized user
	//
	class UserStore implements IGnUserStore {

		@Override
		public GnString loadSerializedUser(String clientId) {

			try {
				InputStream userFileInputStream = new FileInputStream("user.txt");

				Scanner scanner = new java.util.Scanner(userFileInputStream).useDelimiter("\\A");
				GnString serializeUser = new GnString(scanner.hasNext() ? scanner.next() : "");

				userFileInputStream.close();
				return serializeUser;
			}catch (IOException e) {
				//ignore
			}

			return null;
		}

		@Override
		public boolean storeSerializedUser(String clientId, String serializedUser)
		{
			try{
				File userFile = new File("user.txt");
				if(!userFile.exists())
				{
					userFile.createNewFile();
				}
				PrintWriter out = new PrintWriter(userFile);
				out.print(serializedUser);
				out.close();
			} catch (IOException e) {
				return false;
			}
			return true;
		}
	}

}
