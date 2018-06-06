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
 *  This example fetches Cover Art for a sample album
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

package musicid_asset_fetch;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

import com.gracenote.gnsdk.*;

public class MusicIDAssetFetch {

    final String CLIENT_APP_VERSION = "1.0.0.0";    // Version of your application

    static final String GRACENOTE_PRODUCTION_DATABASE              = "gracenote_production_database";
    static final String GRACENOTE_PRODUCTION_DATABASE_LOCATION     = "../../../../sample_data/gdb";


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
            System.out.println("Usage : clientId clientIdTag license gnsdkLibraryPath lookupMode");
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

        try {
            
            new MusicIDAssetFetch().doSample(
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

        // Enable storage module
        GnStorageSqlite.enable();

        if (lookupMode == GnLookupMode.kLookupModeLocal)
        {
            // Enable local database lookups
            EnableLocalLookups();
        }

        // Get User handle to allow us to perform queries
        GnUser gnUser = new GnUser( new UserStore(), clientId, clientIdTag, CLIENT_APP_VERSION );

        // set user to match our desired lookup mode (all queries done with this user will inherit the lookup mode)
        gnUser.options().lookupMode(lookupMode);

        // Load a 'locale' to return locale-specifc results values. This examples loads an English locale.
        loadLocale( gnManager, gnUser );

        // Perform a sample album text query
        doSampleAlbumSearch(gnUser, lookupMode);
    }

    //=============================================================================================
    //  doSampleAlbumSearch
    //
    void 
    doSampleAlbumSearch(GnUser gnUser, GnLookupMode lookupMode) throws GnException {
        
        System.out.printf("\n*****Sample Album Search*****\n");

        GnMusicId mid = new GnMusicId( gnUser ); // provide status events delegate instead of null to view progress

        mid.options().lookupData( GnLookupData.kLookupDataContent, true );
        
        // Perform the query with input text as album title, artist name, track title
        GnResponseAlbums albumResponse = mid.findAlbums( "Supernatural", "Africa Bamba", "Santana", null, null );

        System.out.println("album title    : Supernatural");
        System.out.println("track title    : Africa Bamba");
        System.out.println("artist title   : Santana");
        
        if ( albumResponse.albums().count() == 0 )          
            System.out.println("\nNo albums found for the input.\n");
        else {
            long albumCount = albumResponse.albums().count();
            for (int albumIndex = 0; albumIndex < albumCount; albumIndex++) {
                GnAlbum album = albumResponse.albums().at(albumIndex).next();
                doAssetFetch(gnUser, lookupMode, album);                    
            }
        }
    }
    
    //=============================================================================================
    //  doAssetFetch
    //
    void
    doAssetFetch(GnUser gnUser, GnLookupMode lookupMode, GnAlbum album) throws GnException {
        
        GnContentIterator itr = album.contents().getIterator();
        
        while ( itr.hasNext() ){
            GnContent content = itr.next();

            if (content.contentType() == GnContentType.kContentTypeImageCover) {
                GnAssetIterator aItr = content.assets().getIterator();
                while (aItr.hasNext()) {
                    
                    GnAsset asset = aItr.next();

                    String url = null;
                    
                    url = asset.urlGnsdk();
                    
                    if (!url.isEmpty())
                    {
                        GnAssetFetch assetFetch = new GnAssetFetch(gnUser, url, lookupMode);
                    
                        System.out.println("\nSuccessfully Fetched CoverArt:");
                        System.out.println("\tAsset Url: " + asset.url());
                        System.out.println("\tAsset Size: " + assetFetch.size());
                    }
                }
            }
        }
    }

    
    //=============================================================================================
    // returnTextOrNone
    //
    static String
    returnTextOrNone(String str)
    {
        return str!=null? str : "[none]";
    }

    //=============================================================================================
    // EnableLocalLookups
    //
    void
    EnableLocalLookups() throws GnException
    {
        /* Initialize Local Lookup module to enable local queries */
        GnLookupLocal gnLookupLocal = GnLookupLocal.enable();

        GnConfig config = new GnConfig();
        config.set(GnConfigOptionLocation.kConfigOptionLocationLookupDatabaseAll, GRACENOTE_PRODUCTION_DATABASE_LOCATION);
        config.set(GnConfigOptionEnable.kConfigOptionEnableLookupDatabaseMusicIDText, true);
        config.set(GnConfigOptionEnable.kConfigOptionEnableLookupDatabaseMusicIDImages, true);
        GnLookupDatabase gnLookupDB = new GnLookupDatabase(GRACENOTE_PRODUCTION_DATABASE, config);

        /* To see detailed information about the Lookup Database, enable this: */
        // GnDataObject dbInfo = gnLookupDB.info();
        // GnRenderOptions renderOpts = new GnRenderOptions().json();
        //System.out.println("Gracenote Local Database Info : \n" + dbInfo.render(renderOpts));
    }


    //=============================================================================================
    // loadLocale
    //  Load a 'locale' to return locale-specific values in the Metadata.
    //  This examples loads an English locale.
    //
    void
    loadLocale( GnManager gnManager, GnUser gnUser ) throws GnException {

        /* Set the location of Gracenote Lists DB */
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
