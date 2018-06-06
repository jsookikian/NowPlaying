/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
 *
 */

/*
 * MusicIDImageFetch.cs
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.IO;
using System.Runtime.InteropServices;
using GracenoteSDK;

namespace Sample
{


	public class MusicIDAssetFetch
	{
        static int SUCCESS = 0;
        static int ERROR = 1;
	     private static string dbPath = @"../../../../sample_data/gdb";
		/* GnStatusEventsDelegate : overrider methods of this class to get delegate callbacks */
        public class LookupStatusEvents : GnStatusEventsDelegate
		{
			/*-----------------------------------------------------------------------------
			 *  StatusEvent
			 */
			public override void
			StatusEvent(GnStatus status, uint percentComplete, uint bytesTotalSent, uint bytesTotalReceived, IGnCancellable canceller)
			{
				Console.Write("\nPerforming MusicID Query ...\t");
				switch (status)
				{
				case GnStatus.kStatusUnknown:
					Console.Write("Status unknown ");
					break;

				case GnStatus.kStatusBegin:
					Console.Write("Status query begin ");
					break;

				case GnStatus.kStatusConnecting:
					Console.Write("Status  connecting ");
					break;

				case GnStatus.kStatusSending:
					Console.Write("Status sending ");
					break;

				case GnStatus.kStatusReceiving:
					Console.Write("Status receiving ");
					break;

				case GnStatus.kStatusComplete:
					Console.Write("Status complete ");
					break;

				default:
					break;
				}

				Console.WriteLine("\n\t% Complete (" + percentComplete + "),\tTotal Bytes Sent (" + bytesTotalSent + "),\tTotal Bytes Received (" + bytesTotalReceived + ")");
			}

		}



        /// <summary>
        /// EnableStorage:
        /// Enabling a storage module for GNSDK enables the SDK to use it 
        /// for caching of online queries, storing Playlist Collections, and
        /// to access to Local Databases for offline queries.
        /// Using a storage module is optional and the SDK is capable of operating
        /// without those features if you so chose.
        /// </summary>
        private static void EnableStorage()
        {
            // Instantiate SQLite module to use as our database 
            GnStorageSqlite storageSqlite = GnStorageSqlite.Enable();

            // Set folder location for sqlite storage 
            storageSqlite.StorageLocation = ".";
        }

        /// <summary>
        /// EnableLocalLookups:
        /// Enabling a Local Lookup module gives the SDK the ability to perform
        /// certain queries without going online. This can enable an completely
        /// off-line mode for your application, or can act as a performance boost
        /// over going online for some queries.
        /// </summary>
        private static void EnableLocalLookups()
        {


            // Instantiate Local Lookup module to enable local queries
            GnLookupLocal gnLookupLocal = GnLookupLocal.Enable();
            gnLookupLocal.StorageLocation(GnLocalStorageName.kLocalStorageAll, dbPath);
            // Display Local Database version 
            uint ordinal = gnLookupLocal.StorageInfoCount(GnLocalStorageName.kLocalStorageMetadata, GnLocalStorageInfo.kLocalStorageInfoVersion);
            string gdb_version = gnLookupLocal.StorageInfo(GnLocalStorageName.kLocalStorageMetadata, GnLocalStorageInfo.kLocalStorageInfoVersion, ordinal);
            Console.Write("Gracenote Local Database Version : %s\n", gdb_version);
        }


        /// <summary>
        /// GetUser:
        /// Return a stored user if exists, or create new user and store it for use next time.
        /// </summary>
        /// <param name="manager"></param>
        /// <param name="clientId"></param>
        /// <param name="clientIdTag"></param>
        /// <param name="applicationVersion"></param>
        /// <param name="lookupMode"></param>
        /// <returns></returns>
        private static GnUser
        GetUser(GnManager manager, string clientId, string clientIdTag, string applicationVersion, GnLookupMode lookupMode)
        {
            string serializedUser = String.Empty;

            GnUserRegisterMode userRegMode = GnUserRegisterMode.kUserRegisterModeOnline;
            if (lookupMode == GnLookupMode.kLookupModeLocal)
                userRegMode = GnUserRegisterMode.kUserRegisterModeLocalOnly;

            // read stored user data from file 
            if (File.Exists("user.txt"))
            {
                using (StreamReader sr = new StreamReader("user.txt"))
                {
                    serializedUser = sr.ReadToEnd();
                }
            }

            if (serializedUser.Length > 0)
            {
                // pass in clientID (optional) to ensure this serialized user is for this clientID 
                GnUser user = new GnUser(serializedUser, clientId);

                if ((userRegMode == GnUserRegisterMode.kUserRegisterModeLocalOnly) || !user.IsLocalOnly())
                    return user;
                // else desired regmode is online, but user is localonly - discard and register new online user
            }

            // Register new user
            serializedUser = manager.UserRegister(userRegMode, clientId, clientIdTag, applicationVersion).c_str();

            // store user data to file 
            using (StreamWriter outfile = new StreamWriter("user.txt"))
            {
                outfile.Write(serializedUser);
                outfile.Close();
            }

            return new GnUser(serializedUser);
        }


        /// <summary>
        ///  LoadLocale:
        /// 
        /// </summary>
        /// <param name="user"></param>
        static void
        LoadLocale(GnUser user)
        {
            using (LookupStatusEvents localeEvents = new LookupStatusEvents())
            {
                GnLocale locale = new GnLocale(
                    GnLocaleGroup.kLocaleGroupMusic,     // Locale group
                    GnLanguage.kLanguageEnglish,         // Language 
                    GnRegion.kRegionDefault,             // Region 
                    GnDescriptor.kDescriptorSimplified,  // Descriptor 
                    user,                                // User 
                    null                                 // locale Events object 
                    );

                locale.SetGroupDefault();
            }
        }

       

	

		/***************************************************************************
		*
		*    DoSampleTextQuery
		*
		* This function performs a text lookup using musicid. If there is a match,
		* the associated image is fetched.
		*
		***************************************************************************/
		private static void
		DoSampleAlbumQuery( GnUser user, GnLookupMode lookupMode)
		{
	
			GnMusicId musicID = new GnMusicId(user);

			/* set the lookup data to Content */
			musicID.Options().LookupData(GnLookupData.kLookupDataContent, true);
			
			/* Set the input text as album title, artist name, track title and perform the query */
			GnResponseAlbums responseAlbums = musicID.FindAlbums(String.Empty, String.Empty, "Kelly Clarkson", string.Empty, string.Empty);

			uint count = responseAlbums.Albums.count();

			Console.WriteLine("Number of Albums found = " + count);

            /* for each and every album matched */
            Console.WriteLine("Displaying all assets for albums found" );
			foreach ( GnAlbum album in responseAlbums.Albums ) 
			{

				 Console.WriteLine("Album:" + album.Title.Display + "\tGNUID:" + album.GnUId); 
                /* Lets print all possible Content Assets */
                foreach (GnContent content in album.Contents)  
                {
                    foreach (GnAsset asset in content.Assets)
                    {
                        Console.WriteLine( "Content Type: " + content.ContentType.ToString() + " Asset Dimension: " +  asset.Dimension
                                      + " Asset Size: " + asset.Size.ToString()  + "\tURL: " + asset.Url);
                    }
                }
			}

            if (count > 0 )
            {
                /* Lets download the cover art for the first album*/
                Console.WriteLine("Copy the Cover Art URL for 450x450 for the first album");
                GnAlbum album = responseAlbums.Albums.at(0).Current; 

                /* Use the size you want for you asset , this is demonstrating 450x450 */
                GnAsset asset = album.Content(GnContentType.kContentTypeImageCover).Asset(GnImageSize.kImageSize450);
                if (asset.IsNull()) {
                    /* The followup can be for a smaller size , this is demonstrating 170x170*/
                    Console.WriteLine("Cover Art does not exist for 450x450 , dropping down to 170x170");
                    asset = album.Content(GnContentType.kContentTypeImageCover).Asset(GnImageSize.kImageSize170); 

                }

                string url = null;

                if (GnLookupMode.kLookupModeLocal == lookupMode)
                    url = asset.UrlGnsdk();
                else
                    url = asset.UrlHttp();

                /* lets dump the image to a file. */
                GnAssetFetch assetFetch = new GnAssetFetch(user, url, lookupMode);
              Console.WriteLine("\nRETRIEVED COVER ART: " + asset.Size.ToString()
				                  + ": "
				                  + assetFetch.DataBuffer.Length
				                  + " byte JPEG");
            }
		}

		
		/*
		 * Sample app start (main)
		 */
		static int Main(string[] args)
		{
            string licenseFile;
            string gnsdkLibraryPath;
            string clientId;
            string clientIdTag;
            string applicationVersion = "1.0.0.0";  /* Increment with each version of your app */
            GnLookupMode lookupMode;
            int result = ERROR;

            Console.OutputEncoding = Encoding.UTF8;
            if (args.Length == 5)
            {
                clientId = args[0];
                clientIdTag = args[1];
                licenseFile = args[2];
                gnsdkLibraryPath = args[3];

                if (args[4] == "online")
                {
                    lookupMode = GnLookupMode.kLookupModeOnline;
                }
                else if (args[4] == "local")
                {
                    lookupMode = GnLookupMode.kLookupModeLocal;
                }
                else
                {
                    Console.Write("Incorrect lookupMode specified.\n");
                    Console.Write("Please choose either \"local\" or \"online\"\n");
                    return ERROR;
                }
            }
            else
            {
                Console.Write("\nUsage:  clientId clientIdTag license gnsdkLibraryPath lookupMode\n");
                return ERROR;
            }

            /* GNSDK initialization */
            try
			{
				// Initialize SDK 
				GnManager manager = new GnManager(gnsdkLibraryPath, licenseFile, GnLicenseInputMode.kLicenseInputModeFilename);

                /* Display SDK version */
                Console.WriteLine("\nGNSDK Product Version : " + manager.ProductVersion + " \t(built " + manager.BuildDate + ")");

                // Enable GNSDK logging 
                GnLog sampleLog = new GnLog("sample.log", null);
                GnLogFilters filters = new GnLogFilters();
                sampleLog.Filters(filters.Error().Warning());               // Include only error and warning entries 
                GnLogColumns columns = new GnLogColumns();
                sampleLog.Columns(columns.All());			                // Add all columns to log: timestamps, thread IDs, etc 
                GnLogOptions options = new GnLogOptions();
                sampleLog.Options(options.MaxSize(0).Archive(false));       // Max size of log: 0 means a new log file will be created each run. Archive option will save old log else it will regenerate the log each time 
                sampleLog.Enable(GnLogPackageType.kLogPackageAllGNSDK);     // Include entries for all packages and subsystems 

                EnableStorage();

                if (lookupMode == GnLookupMode.kLookupModeLocal)
                {
                    // Enable local database lookups 
                    EnableLocalLookups();
                }

                // Get GnUser instance to allow us to perform queries
                GnUser user = GetUser(manager, clientId, clientIdTag, applicationVersion, lookupMode);

                // set user to match our desired lookup mode (all queries done with this user will inherit the lookup mode) 
                user.Options().LookupMode(lookupMode);

                LoadLocale(user);

				/* Perform a sample album text query */
				DoSampleAlbumQuery( user, lookupMode );

                // Success 
                result = SUCCESS;
			}
			catch (GnException e)
			{
				Console.WriteLine("GnException :" + e.ErrorDescription + " Code " + e.ErrorCode.ToString("X")  + "API:" + e.ErrorAPI );
			}
            return result;
		}

	}


}

