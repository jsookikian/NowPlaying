/** Public header file for Gracenote SDK C++ Wrapper
 * Author:
 *   Copyright (c) 2015 Gracenote, Inc.
 *
 *   This software may not be used in any way or distributed without
 *   permission. All rights reserved.
 *
 *   Some code herein may be covered by US and international patents.
 */

#ifndef _GNSDK_LOOKUPDATABASE_HPP_
#define _GNSDK_LOOKUPDATABASE_HPP_

#ifndef __cplusplus
#error "C++ compiler required"
#endif

#include "gnsdk_base.hpp"
#include "gnsdk_manager.hpp"
#include "gnsdk_config.hpp"
#include "metadata_music.hpp"

namespace gracenote
{
	namespace lookupdatabase
	{
		class GnLookupDatabaseInfo : public metadata::GnDataObject
		{
		public:
            GnLookupDatabaseInfo() {}
            
			explicit GnLookupDatabaseInfo(gnsdk_gdo_handle_t gdoHandle):GnDataObject(gdoHandle){};
        };

		class GnLookupDatabase
		{
		public:
			GNWRAPPER_ANNOTATE

			/** 
			 * Open Local Database - database is a set of related gracenote storages. This call will create new or open
			 * existing database based on configuration given.
			 * @param identifier [in] Local Database identifier 
			 * @param config [in] GnConfig object
			 */
 			GnLookupDatabase(gnsdk_cstr_t identifier, const GnConfig& config) throw (GnError);

			~GnLookupDatabase();

			/** 
			 * Add record to database. 
			 * @param db_identifier [in] database identifer 
			 * @param album			[in] GnAlbum object
			 */
			void
			AddRecord(const metadata::GnAlbum& album) throw (GnError);

			/** 
			 * Add record to database. 
			 * @param db_identifier [in] database identifer 
			 * @param contributor	[in] GnContributor object
			 */
			void
			AddRecord(const metadata::GnContributor& contributor) throw (GnError);

			/**
			 * Add image to database. 
			 * @param db_identifier [in] database identifer 
			 * @param buffer		 [in] image buffer
			 * @param buffer_size	 [in] image buffer size in bytes
			 * @param asset_gdo	 [in] asset gracenote data object to add
			 */
			void
			AddImage(gnsdk_byte_t* image_buffer, gnsdk_size_t image_buffer_size, const metadata::GnAsset& asset);

		   /** 
			* Get databse size.
			* @return - database size in bytes
  			*/
			gnsdk_uint64_t
			Size() throw (GnError);

			/** 
			* Get databse info.
			* @return - GnDataObject with DB information
  			*/
			GnLookupDatabaseInfo
			Info() throw (GnError);

			/** 
			 * Close lookup local database - will wait if any threads have outstanding queries with this database.  
			 * If this API is not called, all open databases will be closed on when GnManager object goes out of scope.
			 * @param db_identifier [in] database identifer 
			 */
			void
			Close() throw (GnError);

			/**
			 * Deletes the local database files.  Database must be closed before calling this method.
			 * Note that only lookup related GDB files are deleted.
			 * @param config [in] GnConfig object - database configuration. 
 			 */
			static void
			Delete(const GnConfig& config) throw (GnError)
			{ 
				gnsdk_error_t error;

				error = gnsdk_lookupdatabase_delete(config.native());
				if (error) { throw GnError(); }
			};			

		private:
			GnString		identifier;
		};
	} // namespace lookupdatabase

}     // namespace gracenote

#endif // _GNSDK_LOOKUPDATABASE_HPP_
