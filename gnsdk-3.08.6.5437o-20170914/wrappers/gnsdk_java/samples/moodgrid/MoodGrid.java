/*
 * Copyright (c) 2000-2016 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/*
 * Name: moodgrid.MoodGrid
 * Description:
 * Moodgrid enables querying offline and online providers for mood based playlists.
 * Moodgrid is a curated flow of adjacent moods that is available in ( multiple) 2 Dimension data grids.
 * The sample shows using a playlist collection as an offline provider of music for a 5x5 Moodgrid and 10x10 Moodgrid.
 *
 *  Please see docs/README_Samples.txt for more information.
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
package moodgrid;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

import com.gracenote.gnsdk.*;

/******************************************************************************
 * class UserStore
 * <p>
 * Example implementation of interface: IGnUserStore
 * Loads and stores User data for the GnUser object. This sample stores the
 * user data to a local file named 'user.txt'.
 * Your application should store the user data to an appropriate location.
 ******************************************************************************/
class UserStore implements IGnUserStore {
    @Override
    public GnString loadSerializedUser(String clientId) {
        try {
            InputStream userFileInputStream = new FileInputStream("user.txt");
            Scanner scanner = new java.util.Scanner(userFileInputStream).useDelimiter("\\A");
            GnString serializeUser = new GnString(scanner.hasNext() ? scanner.next() : "");
            userFileInputStream.close();
            return serializeUser;
        } catch (IOException e) {
            return null;
        }
    }

    @Override
    public boolean storeSerializedUser(String clientId, String serializedUser) {
        try {
            File userFile = new File("user.txt");
            if (!userFile.exists())
                userFile.createNewFile();
            PrintWriter out = new PrintWriter(userFile);
            out.print(serializedUser);
            out.close();
        } catch (IOException e) {
            return false;
        }
        return true;
    }
}

public class MoodGrid {
    final String CLIENT_APP_VERSION = "1.0.0.0";    /* Version of your application, free format */
    static final String GRACENOTE_PRODUCTION_DATABASE_LOCATION = "../../../../sample_data/gdb";

    /* Load GNSDK native libraries*/
    static {
        try {
            System.loadLibrary("gnsdk_java_marshal");
        } catch (UnsatisfiedLinkError unsatisfiedLinkError) {
            System.err.println("Native code library failed to load\n" + unsatisfiedLinkError.getMessage());
            System.exit(1);
        }
    }

    /**************************************************************************
     * MAIN
     * /
     **************************************************************************/
    public static void main(String[] args) {
        if (args.length != 5) {
            System.out.println("Usage : clientId clientIdTag license gnsdkLibraryPath online|local");
            System.exit(-1);
            return;
        }

        GnLookupMode lookupMode;

        if (args[4].trim().equals("online")) {
            lookupMode = GnLookupMode.kLookupModeOnline;
        } else if (args[4].trim().equals("local")) {
            lookupMode = GnLookupMode.kLookupModeLocal;
        } else {
            System.out.println("Incorrect lookup mode specified.\n");
            System.out.println("Please choose either \"local\" or \"online\"\n");
            System.exit(-1);
            return;
        }

        try {
            new MoodGrid().doSample(
                    args[0].trim(),     /* Client ID */
                    args[1].trim(),     /* Client ID Tag */
                    args[2].trim(),     /* License */
                    args[3].trim(),     /* GNSDK Library Path */
                    lookupMode);
        } catch (GnException gnException) {
            System.out.println("GnException \t" + gnException.getMessage());
            System.exit(-1);
        } finally {
            System.runFinalization();
            System.gc();
        }
    }

    /**************************************************************************
     * doSample
     ***************************************************************************/
    void
    doSample(String clientId, String clientIdTag, String licensePath, String libPath, GnLookupMode lookupMode) throws GnException {
       /*  Initialize GNSDK*/
        /* Note: For Android GnManager constructors are different. Consult documentation for more information.*/
        GnManager gnManager = new GnManager(libPath, licensePath, GnLicenseInputMode.kLicenseInputModeFilename);
        
       /*  Display GNSDK Version information*/
        System.out.println("\nGNSDK Product Version : " + GnManager.productVersion() + "\t(built " + GnManager.buildDate() + ")");

        /* Enable GNSDK logging*/
        GnLog sampleLog = new GnLog("sample.log", null);
        sampleLog.filters(new GnLogFilters().error().warning());                /* Include only error and warning entries */
        sampleLog.columns(new GnLogColumns().all());                            /* Add all columns to log: timestamps, thread IDs, etc */
        sampleLog.options(new GnLogOptions().maxSize(new BigInteger("0")));     /* Max size of log: 0 means a new log file will be created each run */
        sampleLog.options(new GnLogOptions().archive(false));                   /* True = old logs will be renamed and saved. False = new log each time */

        /* To enable logging package call enable with the package. Enable can be called multiple times to turn on multiple packages*/
        sampleLog.enable(GnLogPackageType.kLogPackageAll);

        if (lookupMode == GnLookupMode.kLookupModeLocal) {
            /* Enable Local lookup*/
            GnStorageSqlite.enable();
            GnLookupLocal.enable();
        }

        /* Get User handle to allow us to perform queries*/
        GnUser gnUser = new GnUser(new UserStore(), clientId, clientIdTag, CLIENT_APP_VERSION);

        /* Set user to match our desired lookup mode (all queries done with this user will inherit the lookup mode)*/
        gnUser.options().lookupMode(lookupMode);

        /* Load a 'locale' to return locale-specifc results values. This examples loads an English locale.*/
        loadLocale(gnManager, gnUser);

        /* Initialize Storage for storing Playlist Collections*/
        GnStorageSqlite.enable();
        GnPlaylistStorage plStorage = new GnPlaylistStorage();

        /* How many collections are stored?*/
        long storedCollCount = plStorage.names().count();
        System.out.println("\nStored Collections Count: " + storedCollCount);

        GnPlaylistCollection myCollection;
        if (storedCollCount == 0) {
            // Create new collection onlne if not stored any
            myCollection = new GnPlaylistCollection("sample_collection");
            doMusicRecognition(gnUser, myCollection, lookupMode);
            plStorage.store(myCollection);
        } else {
            // Load first existing collection from local store 
            myCollection = plStorage.load(plStorage.names().getIterator().next());
        }

        /* Create, query and print a  5 x  5  moodgrid*/
        doMoodgridRecommendations(gnUser, myCollection, GnMoodgridPresentationType.kMoodgridPresentationType5x5);

       /* Create, query and print a 10 x 10 moodgrid*/
        doMoodgridRecommendations(gnUser, myCollection, GnMoodgridPresentationType.kMoodgridPresentationType10x10);
    }

    /**************************************************************************
     * doMusicRecognition
     ***************************************************************************/
    void
    doMusicRecognition(GnUser gnUser, GnPlaylistCollection collection, GnLookupMode lookupMode) throws GnException {
        String[] inputQueryTOCs = {
                "150 13224 54343 71791 91348 103567 116709 132142 141174 157219 175674 197098 238987 257905",
                "182 23637 47507 63692 79615 98742 117937 133712 151660 170112 189281",
                "182 14035 25710 40955 55975 71650 85445 99680 115902 129747 144332 156122 170507",
                "150 10705 19417 30005 40877 50745 62252 72627 84955 99245 109657 119062 131692 141827 152207 164085 173597 187090 204152 219687 229957 261790 276195 289657 303247 322635 339947 356272",
                "150 14112 25007 41402 54705 69572 87335 98945 112902 131902 144055 157985 176900 189260 203342",
                "150 1307 15551 31744 45022 57486 72947 85253 100214 115073 128384 141948 152951 167014",
                "183 69633 96258 149208 174783 213408 317508",
                "150 19831 36808 56383 70533 87138 105157 121415 135112 151619 169903 189073",
                "182 10970 29265 38470 59517 74487 83422 100987 113777 137640 150052 162445 173390 196295 221582",
                "150 52977 87922 128260 167245 187902 215777 248265",
                "183 40758 66708 69893 75408 78598 82983 87633 91608 98690 103233 108950 111640 117633 124343 126883 132298 138783 144708 152358 175233 189408 201408 214758 239808",
                "150 92100 135622 183410 251160 293700 334140",
                "150 17710 33797 65680 86977 116362 150932 166355 183640 193035",
                "150 26235 51960 73111 93906 115911 142086 161361 185586 205986 227820 249300 277275 333000",
                "150 1032 27551 53742 75281 96399 118691 145295 165029 189661 210477 232501 254342 282525",
                "150 26650 52737 74200 95325 117675 144287 163975 188650 209350 231300 253137 281525 337875",
                "150 19335 35855 59943 78183 96553 111115 125647 145635 163062 188810 214233 223010 241800 271197",
                "150 17942 32115 47037 63500 79055 96837 117772 131940 148382 163417 181167 201745",
                "150 17820 29895 41775 52915 69407 93767 105292 137857 161617 171547 182482 204637 239630 250692 282942 299695 311092 319080",
                "182 21995 45882 53607 71945 80495 94445 119270 141845 166445 174432 187295 210395 230270 240057 255770 277745 305382 318020 335795 356120",
                "187 34360 64007 81050 122800 157925 195707 230030 255537 279212 291562 301852 310601",
                "150 72403 124298 165585 226668 260273 291185"
        };

        System.out.printf("Populating Collection Summary from sample TOCs...\n");

        /* Create musicid query object*/
        GnMusicId musicId = new GnMusicId(gnUser);

        /* Set query options */
        musicId.options().lookupData(GnLookupData.kLookupDataSonicData, true);
        musicId.options().lookupData(GnLookupData.kLookupDataPlaylist, true);

        /* Set the lookup mode on the query object to 'Online No Cache.'
         * Query caching is not used for automotive as it expires entries too quickly.
         * Automotive use cases instead use the result DB to persist results in an
         * embedded database.
         */
        if (lookupMode == GnLookupMode.kLookupModeLocal) {
            musicId.options().lookupMode(GnLookupMode.kLookupModeLocal);
        } else {
            musicId.options().lookupMode(GnLookupMode.kLookupModeOnlineNoCache);
        }

        int tocCount = 0;
        for (String toc : inputQueryTOCs) {
            tocCount++;
            GnResponseAlbums albumResponse = musicId.findAlbums(toc);
            GnAlbum album = albumResponse.albums().getIterator().next();
            GnTrackIterator iter = album.tracks().getIterator();

            int trackCount = 0;
            while (iter.hasNext()) {
                trackCount++;

                GnTrack track = iter.next();

                /* create a unique ident for every track that is added to the playlist.
                * Ideally the ident allows for the identification of which track it is.
                * e.g. path/filename.ext , or an id that can be externally looked up. */
                String uniqueId = String.format("%d_%d", tocCount, trackCount);

                /* Add the the Album and Track GDO for the same ident so that we can
                * query the Playlist Collection with both track and album level attributes. */
                collection.add(uniqueId, album);     // Add the album
                collection.add(uniqueId, track);     // Add the track
            }
            System.out.printf("\tAlbum %d added\n", tocCount);
        }

        System.out.printf("\n Finished Recognition \n");
    }

    /**************************************************************************
     * doMoodgridRecommendations
     **************************************************************************/
    void
    doMoodgridRecommendations(GnUser user, GnPlaylistCollection collection, GnMoodgridPresentationType type) throws GnException {
        GnMoodgrid myMoodgrid = new GnMoodgrid();
        GnMoodgridProvider myProvider = myMoodgrid.providers().at(0).next();

        /* get the details for the provider*/
        String mProviderName = myProvider.name();
        System.out.printf("\n GNSDK_MOODGRID_PROVIDER_NAME :%s \n", mProviderName);

        String mProviderType = myProvider.type();
        System.out.printf("\n GNSDK_MOODGRID_PROVIDER_TYPE :%s \n", mProviderType);

        /* create a moodgrid presentation for the specified type*/
        GnMoodgridPresentation myPresentation = myMoodgrid.createPresentation(user, type, GnMoodgridCoordinateType.kMoodgridCoordinateTopLeft);

        GnMoodgridPresentationDataIterator itr = myPresentation.moods().getIterator();

        while (itr.hasNext()) {
            GnMoodgridDataPoint dataPoint = itr.next();

            /* find the recommendation for the mood*/
            GnMoodgridResult result = myPresentation.findRecommendations(myProvider, dataPoint);

            System.out.printf("\n\n\tX:%d  Y:%d\tMood Name: %s\tMood ID: %s\tCount: %d\n", dataPoint.getX(), dataPoint.getY(), myPresentation.moodName(dataPoint), myPresentation.moodId(dataPoint), result.count());

            /* iterate the results for the idents*/
            GnMoodgridResultIterator resultItr = result.identifiers().getIterator();
            while (resultItr.hasNext()) {
                GnMoodgridIdentifier ident = resultItr.next();

                System.out.printf("\nident:\t%s\n", ident.mediaIdentifier());
                System.out.printf("group:\t%s\n", ident.group());

                GnPlaylistAttributes data = collection.attributes(user, ident.mediaIdentifier(), ident.group());

                System.out.printf("Album:\t%s\n", data.albumName());
                System.out.printf("Mood :\t%s\n", data.mood());

            }
        }
    }

    /**************************************************************************
     * loadLocale
     * Load a 'locale' to return locale-specific values in the Metadata.
     * This examples loads an English locale.
     ***************************************************************************/
    void
    loadLocale(GnManager gnMgr, GnUser gnUser) throws GnException {
        gnMgr.localesStore().location(GRACENOTE_PRODUCTION_DATABASE_LOCATION);

        GnLocale locale = new GnLocale(
                GnLocaleGroup.kLocaleGroupPlaylist,
                GnLanguage.kLanguageEnglish,
                GnRegion.kRegionDefault,
                GnDescriptor.kDescriptorDefault,
                gnUser);

        /* Setting the 'locale' as default
        * If default not set, no locale-specific results would be available */
        locale.setGroupDefault();

        /* GnSDK will hold onto the locale when set as default
         so it's ok to allow our reference to go out of scope */
    }

    /**************************************************************************
     * doMatchSelection
     ***************************************************************************/
    int
    doMatchSelection(GnResponseAlbums albumResponse) throws GnException {

        /* This is where any matches that need resolution/disambiguation are iterated
        * and a single selection of the best match is made.
        *
        * For this simplified sample, we'll just echo the matches and select the first match. */
        System.out.printf("%16s %d\n", "Match count:", albumResponse.albums().count());

        GnAlbumIterator iter = albumResponse.albums().getIterator();
        while (iter.hasNext()) {
            displayAlbum(iter.next());
        }
        return 0;
    }

    /**************************************************************************
     * displayAlbum
     ***************************************************************************/
    void
    displayAlbum(GnAlbum album) throws GnException {
        System.out.printf("%16s %s\n", "Title:", album.title().display());
    }

    /**************************************************************************
     * UserStore
     * Persistent store and recall of serialized user
     ***************************************************************************/
    class UserStore implements IGnUserStore {
        @Override
        public GnString loadSerializedUser(String clientId) {
            try {
                InputStream userFileInputStream = new FileInputStream("user.txt");
                Scanner scanner = new java.util.Scanner(userFileInputStream).useDelimiter("\\A");
                GnString serializeUser = new GnString(scanner.hasNext() ? scanner.next() : "");
                userFileInputStream.close();
                return serializeUser;
            } catch (IOException e) {
                return null;
            }
        }

        @Override
        public boolean storeSerializedUser(String clientId, String serializedUser) {
            try {
                File userFile = new File("user.txt");
                if (!userFile.exists())
                    userFile.createNewFile();
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