/*
 * Copyright (c) 2000-2015 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */
/*
 * Name: musicid_persist_and_manage.MusicIDPersistAndManage
 * Description:
 *  Stores query results in a results database to be available in future offline queries or after
 *  the local database is updated.
 *  Demonstrates management of result database size.
 *
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


package musicid_persist_and_manage;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import java.io.File;

import com.gracenote.gnsdk.*;

public class MusicIDPersistAndManage {

    static final String CLIENT_APP_VERSION                         = "1.0.0.0";    // Version of your application

    static final String GRACENOTE_PRODUCTION_DATABASE              = "gracenote_production_database";
    static final String GRACENOTE_PRODUCTION_DATABASE_LOCATION     = "../../../../sample_data/gdb";

    static final String RESULT_DATABASE_A                          = "result_database_a";
    static final String RESULT_DATABASE_A_LOCATION                 = "result_database_a";

    static final String RESULT_DATABASE_B                          = "result_database_b";
    static final String RESULT_DATABASE_B_LOCATION                 = "result_database_b";

    final long RESULT_STORE_ALOCATION_SIZE_BYTES                   = 36864;



    SampleInput sampleInput[] =
            {
                    new SampleInput("Coldplay", "Viva La Vida", "Death And All His Friends"),
                    new SampleInput("Adele", "21", "Rumour Has It"),
                    new SampleInput("Santana", "Supernatural", "Africa Bamba"),
                    new SampleInput("Daft Punk", "Random Access Memories", "Get Lucky"),
                    new SampleInput("Adele", "21", "Rolling in the Deep"),
                    new SampleInput("Sam Smith", "In the Lonely Hour", "Stay With Me"),
                    new SampleInput("Coldplay", "Viva La Vida", "Lost!")
            };


    // Load GNSDK native libraries
    static {
        try {
            System.loadLibrary("gnsdk_java_marshal");
        } catch (UnsatisfiedLinkError unsatisfiedLinkError) {
            System.err.println("Native code library failed to load\n" + unsatisfiedLinkError.getMessage());
            System.exit(1);
        }
    }


    //=============================================================================================
    //
    // main
    //
    //=============================================================================================
    public static void main(String[] args) {

        if (args.length != 5) {
            System.out.println("Usage : clientId clientIdTag license gnsdkLibraryPath [local|online]");
            System.exit(-1);
            return;
        }

        GnLookupMode lookupMode;

        if ( args[4].trim().equals( "online" ) ){
            lookupMode = GnLookupMode.kLookupModeOnline;
        }else if ( args[4].trim().equals( "local" ) ){
            lookupMode = GnLookupMode.kLookupModeLocal;
        }else{
            System.out.println("Incorrect lookup mode specified.\n");
            System.out.println("Please choose either \"local\" or \"online\"\n");
            System.exit(-1);
            return;
        }

        // Create folders to hold persistent lookup databases
        (new File(RESULT_DATABASE_A_LOCATION)).mkdir();
        (new File(RESULT_DATABASE_B_LOCATION)).mkdir();


        try {

            new MusicIDPersistAndManage().doSample(
                    args[0].trim(),     // Client ID
                    args[1].trim(),     // Client ID Tag
                    args[2].trim(),     // License
                    args[3].trim(),     // GNSDK Library Path
                    lookupMode );

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
    doSample( String clientId, String clientIdTag, String licensePath, String libPath, GnLookupMode lookupMode ) throws GnException{

        // Initialize GNSDK
        // Note: For Android GnManager constructors are different. Consult documentation for more information.
        GnManager gnManager = new GnManager(libPath, licensePath, GnLicenseInputMode.kLicenseInputModeFilename);

        // Display GNSDK Version infomation
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
        GnStorageSqlite gnStorage = GnStorageSqlite.enable();

        // Initialize Local lookup module
        GnLookupLocal gnLookupLocal = GnLookupLocal.enable();

        // Get User handle to allow us to perform queries
        GnUser gnUser = new GnUser( new UserStore(), clientId, clientIdTag, CLIENT_APP_VERSION );

        // set user to match our desired lookup mode (all queries done with this user will inherit the lookup mode)
        gnUser.options().lookupMode( lookupMode );

        // Load a 'locale' to return locale-specifc results values. This examples loads an English locale.
        loadLocale( gnManager, gnUser );


        // Perform sample text search and store result in database
        doSampleQueriesAndPersistResults(gnUser, lookupMode);
    }

    //=============================================================================================
    // doSampleQueriesAndPersistResults
    //
    void doSampleQueriesAndPersistResults(GnUser gnUser, GnLookupMode lookupMode) throws GnException
    {
        // Open base database for querying
        if (lookupMode == GnLookupMode.kLookupModeLocal)
        {
            LookupDB base_db = new LookupDB(GRACENOTE_PRODUCTION_DATABASE, GRACENOTE_PRODUCTION_DATABASE_LOCATION, GnConfigOptionAccess.kConfigOptionAccessLookupDatabaseReadOnly);
            base_db.displayDbInfo();
        }

        // Open databases for storing and querying
        LookupDB result_dbs[] = {
                new LookupDB(RESULT_DATABASE_A, RESULT_DATABASE_A_LOCATION, GnConfigOptionAccess.kConfigOptionAccessLookupDatabaseReadWrite),
                new LookupDB(RESULT_DATABASE_B, RESULT_DATABASE_B_LOCATION, GnConfigOptionAccess.kConfigOptionAccessLookupDatabaseReadWrite)};


        /* For simplicity we are assigning current to DB index 0
         * You will need to keep track of which database has recent results between sessions.
         */
        int current_db_index = 0;


        for (int i=0; i < sampleInput.length; i++)
        {
            // do local lookup
            GnDataObject matchResult = doSampleMusicIDQuery(gnUser, GnLookupMode.kLookupModeLocal, sampleInput[i]);

            // do online lookup if no match was found and lookupMode allows
            if (matchResult == null && lookupMode == GnLookupMode.kLookupModeOnline)
            {
                matchResult = doSampleMusicIDQuery(gnUser, GnLookupMode.kLookupModeOnlineNoCache, sampleInput[i]);
            }

            if (matchResult != null)
            {
                if(matchResult.isType(GnAlbum.gnType())) {
                    result_dbs[current_db_index].gnLookupDB.addRecord(GnAlbum.from(matchResult));
                }
                else if(matchResult.isType(GnContributor.gnType()))
                {
                    result_dbs[current_db_index].gnLookupDB.addRecord(GnContributor.from(matchResult));
                }

                System.out.printf( "%16s\n", "Match successfully added to the result database " + (current_db_index==0? "A":"B"));

                // check database size and reset current index if needed
                current_db_index = manageResultDBSize(result_dbs, current_db_index);
            }
            else
            {
                System.out.printf("\n No match found for input: %s \n", sampleInput[i].albumTitle);
            }
        }
    }

    //=============================================================================================
    // doSampleMusicIDQuery
    //
    GnDataObject
    doSampleMusicIDQuery( GnUser gnUser, GnLookupMode lookupMode, SampleInput input_text ) throws GnException {

        System.out.printf("\n-----------MusicID Query--------\n");

        GnMusicId mid = new GnMusicId( gnUser ); // provide status events delegate instead of null to view progress
        mid.options().lookupMode(lookupMode);

        // Perform the query with input text as album title, artist name, track title
        GnResponseDataMatches matchResponse = mid.findMatches( input_text.albumTitle, input_text.trackTitle, input_text.artistName, null, null );
        GnDataObject finalMatch = null;

        // See if we need any follow-up queries or disambiguation
        if ( matchResponse.dataMatches().count() > 0 ){

            int choiceIndex;

            // we have at least one match, see if disambiguation (match resolution) is necessary.
            if ( matchResponse.needsDecision() ){

                choiceIndex = doMatchSelection( matchResponse );

            } else {

                // no need for disambiguation, we'll take the first match
                choiceIndex = 0;
            }

            GnDataMatch match = matchResponse.dataMatches().at(choiceIndex).next();

            if (match.isAlbum()){
                GnAlbum album = match.getAsAlbum();

                // See if the match has full data or only partial data.
                // If we only have a partial result, we do a follow-up query to retrieve the full album
                if (!album.isFullResult()) {

                    // do followup query to get full object. Setting the partial album as the query input.
                    GnResponseAlbums albumResponse = mid.findAlbums(album);
                    album = albumResponse.albums().at(0).next();
                }

                // We should now have our final, full album result.
                System.out.printf("%16s\n", "Final match:");
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
    // displayAlbum
    //
    void
    displayAlbum( GnAlbum album ) throws GnException{
        System.out.printf( "%16s %s\n", "Title:", album.title().display() );
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
    //  _MANAGE_RESULT_DB_SIZE
    //
    //  Checks size of the result store with the most recent results.
    //  If it has hit the size limit, deletes the store with older results,
    //  makes the recent result store the "new" older results store,
    //  creates a new result store for more recent results.

    int manageResultDBSize(LookupDB DBs[], int current_db_index) throws GnException
    {
        int old_db_index = (current_db_index + 1) % 2;
        if (DBs[current_db_index].gnLookupDB.size().compareTo(BigInteger.valueOf(RESULT_STORE_ALOCATION_SIZE_BYTES/2)) > 0 )        {
            System.out.println("Size limit hit. Remove old results and start new recent-results database.");
            DBs[old_db_index].reCreate();
            current_db_index = old_db_index;
        }

        return current_db_index;
    }


    //=============================================================================================
    // SampleInput
    //
    class SampleInput
    {
        SampleInput(String artist, String album, String track)
        {
            artistName = artist;
            albumTitle = album;
            trackTitle = track;
        }
        final String artistName;
        final String albumTitle;
        final String trackTitle;
    }


    //=============================================================================================
    // LookupDB
    //
    class LookupDB
    {
        LookupDB(String _id, String _location, GnConfigOptionAccess _access_mode) throws GnException
        {
            id = _id;

            config = new GnConfig();
            config.set(GnConfigOptionLocation.kConfigOptionLocationLookupDatabaseAll , _location);
            config.set(GnConfigOptionEnable.kConfigOptionEnableLookupDatabaseMusicIDText, true);
            config.set(_access_mode);

            gnLookupDB = new GnLookupDatabase(id, config);
        };


        void reCreate() throws GnException
        {
            gnLookupDB.close();
            GnLookupDatabase.delete(config);
            gnLookupDB = new GnLookupDatabase(id, config);
        }

        void displayDbInfo() throws GnException
        {
            // To see detailed information about the Lookup Database, enable this:
           /* GnDataObject dbInfo = gnLookupDB.info();
            GnString dbInfoXml = null;

            dbInfoXml = dbInfo.render((new GnRenderOptions()).xml());
            System.out.println("Gracenote Local Database Info : \n" + dbInfoXml);*/
        }

        GnLookupDatabase gnLookupDB;
        String id;
        GnConfig config;
    };


    //=============================================================================================
    // UserStore
    // Persistent store and recall of serialized user
    //
    class UserStore implements IGnUserStore {

        @Override
        public GnString loadSerializedUser( String clientId ) {

            try {
                InputStream userFileInputStream = new FileInputStream( "user.txt" );

                Scanner scanner = new java.util.Scanner( userFileInputStream ).useDelimiter("\\A");
                GnString serializeUser = new GnString( scanner.hasNext() ? scanner.next() : "" );

                userFileInputStream.close();

                return serializeUser;

            } catch (IOException e) {
                // ignore
            }

            return null;
        }

        @Override
        public boolean storeSerializedUser( String clientId, String serializedUser ) {

            try{
                File userFile = new File( "user.txt" );
                if ( !userFile.exists() )
                    userFile.createNewFile();
                PrintWriter out = new PrintWriter( userFile );
                out.print( serializedUser );
                out.close();
            } catch (IOException e) {
                return false;
            }

            return true;
        }
    }
}
