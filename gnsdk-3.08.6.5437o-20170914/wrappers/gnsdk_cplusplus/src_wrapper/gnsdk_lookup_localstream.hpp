/** Public header file for Gracenote SDK C++ Wrapper
 *	gnsdk_lookup_localstream.hpp
 *
 *	Author:
 *	Copyright (c) 2000-2015 Gracenote, Inc.
 *
 *	This software may not be used in any way or distributed without
 *	permission. All rights reserved.
 *
 *	Some code herein may be covered by US and international patents.
 */

#ifndef _GNSDK_LOOKUP_LOCALSTREAM_HPP_
#define _GNSDK_LOOKUP_LOCALSTREAM_HPP_

#ifndef __cplusplus
#error "C++ compiler required"
#endif

#include "gnsdk_base.hpp"

#if GNSDK_LOOKUP_LOCALSTREAM

namespace gracenote
{
	namespace lookup_localstream
	{
		/**
		 * Possible values for <code>EngineType</code>
		 */
		enum GnLocalStreamEngineType
		{
			kLocalStreamEngineInvalid = 0,

			/**
			 * Sets lookup local stream library to operate in memory-mapped mode.
			 * Memory-mapped mode uses a memory-mapped file - the OS loads a portion of this file
			 * into memory as it is accessed by an  application, which leads to overall lower peak memory
			 * usage than in-memory mode.
			 */
			kLocalStreamEngineMMap,

			/**
			 * Sets lookup local stream library to operate in in-memory mode. This is faster, but
			 * for mobile devices the amount of memory needed may be prohibitive.
			 */
			kLocalStreamEngineInMemory
		};

		enum GnLocalStreamFingerprintProcessingMethod
		{
			kLocalStreamFingeprintProcessingInvalid = 0,

			/**
			 * Only use the CPU for local fingerprint comparison.
			 */
			kLocalStreamFingeprintProcessingUseCPU,

			/**
			 * Use the GPU (if available) for local fingerprint comparison. The GPU is likely
			 * faster than using the CPU, but if your app is doing lots of intense graphics it
			 * may cause a "stutter" in displayed graphics.
			 */
			kLocalStreamFingeprintProcessingUseGPU,

			/**
			 * Use CUDA on the GPU (if available) for local fingerprint comparison. The GPU is likely
			 * faster than using the CPU, but if your app is doing lots of intense graphics it
			 * may cause a "stutter" in displayed graphics.
			 */
			kLocalStreamFingeprintProcessingUseGPU_CUDA
		};

		/**
		 *
		 * GnLookupLocalStream is a MusicID-Stream local lookup provider, providing a local
		 * database of MusicID-Stream tracks suitable for lookup via GnMusicIdStream or GnMusicId.
		 * A MusicID-Stream local database can be constructed from "bundles" (raw fingerprints and metadata) that
		 * Gracenote provides.
		 *
		 * <b>SDK Documentation</b>
		 *
		 * Topic: "Implementing Applications..." > "Using a Local Fingerprint Database"
		 *
		 * For more information on using the GnLookupLocalStream class see the above topic which covers
		 * the following:
		 * <ul>
		 *     <li>Using a local fingerprint database</li>
		 *     <li>Downloading and ingesting bundles</li>
		 *     <li>Ingesting bundles code samples</li>
		 *     <li>Designating a storage provider</li>
		 *     <li>Local fingerprinting options</li>
		 * </ul>
		 *
		 */
		class GnLookupLocalStream
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 * Enable a lookup local Stream provider.
			 * @return Storage provider instance
			 */
			static GnLookupLocalStream&
			Enable() throw (GnError);
			/**
			 *  Retrieves a GnLookupLocalStream SDK version string.
			 *  You can call this API at any time after successfully allocating a GnManager instance. The returned
			 *  string is a constant. Do not attempt to modify or delete.
			 *  Example: 1.2.3.123 (Major.Minor.Improvement.Build)
			 *  Major: New functionality
			 *  Minor: New or changed features
			 *  Improvement: Improvements and fixes
			 *  Build: Internal build number
			 */
			static gnsdk_cstr_t
			Version();

			/**
			 *  Retrieves the GnLookupLocalStream SDK's build date string.
			 *  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
			 *  <p><b>Remarks:</b></p>
			 *  You can call this API at any time after successfully allocating a GnManager instance. The returned
			 *  string is a constant. Do not attempt to modify or delete.
			 *  Example build date string: 2008-02-12 00:41 UTC
			 */
			static gnsdk_cstr_t
			BuildDate();

			/**
			 *  Sets a folder location for GNSDK LookupLocalStream
			 *  @param folderPath	[in] Relative path name for storage
			 * <p><b>Remarks:</b></p>
			 *  This API overrides the (default or explicit) folder location of GNSDK SQLite storage - for this database.
			 */
			void
			StorageLocation(gnsdk_cstr_t location) throw (GnError);

			/**
			 *  Sets the local fingerprint lookup engine memory type
			 *  @param engineType	[in] GnLocalStreamEngineType enum indicating which memory mode to use
			 */
			void
			EngineType(GnLocalStreamEngineType engineType) throw (GnError);

			/**
			 *  Retrieves the local fingerprint lookup engine memory type
			 */
			GnLocalStreamEngineType
			EngineType(void) throw (GnError);

			/**
			 *  Sets the current local fingerprint lookup processing method.
			 *  @param processingMethod	[in] GnLocalStreamFingerprintProcessingMethod enum indicating the local fingerprint lookup processing method.
			 */
			void
			FingerprintProcessingMethod(GnLocalStreamFingerprintProcessingMethod processingMethod) throw (GnError);

			/**
			 *  Retrieves the current local fingerprint lookup processing method.
			 */
			GnLocalStreamFingerprintProcessingMethod
			FingerprintProcessingMethod(void) throw (GnError);

			/**
			 *  Gets the Option for local fingerprint lookup processing CPU maximum thread count
			 */
			gnsdk_uint32_t
			FingerprintProcessing_CPU_MaxThreadCount(void) throw (GnError);

			/**
			 *  Sets the option for local fingerprint lookup processing CPU maximum thread count
			 *  @param option_value	[in] The maximum number of threads FP Processing may spawn for a single query.
			 */
			void
			FingerprintProcessing_CPU_MaxThreadCount(gnsdk_uint32_t option_value) throw (GnError);

			/**
			 *  Gets the Option for local fingerprint lookup processing CPU minimum thread work size
			 */
			gnsdk_uint32_t
			FingerprintProcessing_CPU_MinThreadWorkSize(void) throw (GnError);

			/**
			 *  Sets the option for local fingerprint lookup processing CPU minimum thread work size.
			 *  @param option_value	[in] The minimum amount of work (in bytes) required by the fingerprint comparison enginge needed before
			 *                           it will spawn additional CPU threads.
			 */
			void
			FingerprintProcessing_CPU_MinThreadWorkSize(gnsdk_uint32_t option_value) throw (GnError);

			/**
			 *  Gets the Option for local fingerprint lookup processing GPU minimum work size
			 */
			gnsdk_uint32_t
			FingerprintProcessing_GPU_MinWorkSize(void) throw (GnError);

			/**
			 *  Sets the Option for local fingerprint lookup processing GPU minimum work size
			 *  @param option_value	[in] The minimum amount of work (in bytes) required by the fingerprint comparison engine needed before
			 *                           it will attempt to use the GPU (if enabled).
			 */
			void
			FingerprintProcessing_GPU_MinWorkSize(gnsdk_uint32_t option_value) throw (GnError);

			/**
			 *  Gets the Option for local fingerprint lookup processing GPU maximum work size.
			 */
			gnsdk_uint32_t
			FingerprintProcessing_GPU_MaxWorkSize(void) throw (GnError);

			/**
			 *  Sets the option for local fingerprint lookup processing GPU maximum work size
			 *  @param option_value	[in] The maximum amount of work that will be sent to the GPU in a single block.
			 */
			void
			FingerprintProcessing_GPU_MaxWorkSize(gnsdk_uint32_t option_value) throw (GnError);

			/**
			 * Clear all tracks from the MusicID-Stream local database storage file.
			 */
			void
			StorageClear() throw (GnError);

			/**
			 * Remove a bundle item from the MusicID-Stream local database.
			 * @param	bundleItemId	[in] Bundle item ID
			 */
			void
			StorageRemove(gnsdk_cstr_t bundleItemId) throw (GnError);

		private:
			GnLookupLocalStream() throw (GnError) { };
		};

		enum GnLookupLocalStreamIngestStatus
		{
			kIngestStatusInvalid = 0,
			kIngestStatusItemBegin,
			kIngestStatusItemAdd,
			kIngestStatusItemDelete
		};

		class IGnLookupLocalStreamIngestEvents
		{
		public:

			virtual ~IGnLookupLocalStreamIngestEvents() {};

			virtual void
			StatusEvent( GnLookupLocalStreamIngestStatus status, gnsdk_cstr_t bundleId, IGnCancellable& canceller) = 0;
		};


		class GnLookupLocalStreamIngest : public GnObject<gnsdk_lookup_localstream_ingest_handle_t>
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 *  Constructor for creating a GnLookupLocalStreamIngest object
			 *  @param pEventDelegate           [in] Delegate to receive events.
			 *  @param callbackData             [in] Optional user data that will be sent to the delegate.
			 */
			GnLookupLocalStreamIngest(IGnLookupLocalStreamIngestEvents* pEventHandler) throw (GnError);
			GnLookupLocalStreamIngest(GnManagedPtr<IGnLookupLocalStreamIngestEvents*> eventHandler) throw (GnError);

			/**
			 * Write to the ingestion process. You can call this multiple times to ensure that data is written when it is available.
			 *  @param data             [in] data to ingest
			 *  @param dataLength       [in] size of data being written
			 */
			void
			Write(gnsdk_byte_t* bundleData, gnsdk_size_t dataSize) throw (GnError);

			/**
			 * Flushes the memory cache to the file storage and commits the changes. This call results in IO.
			 * Call this method to ensure that everything written is commited to the file system.
			 * Note: This is an optional call as, internally, data is flushed when it exceeds the cache size and when the object goes out of scope.
			 */
			void
			Flush() throw (GnError);


			/*-----------------------------------------------------------------------------
			 *  EventHandler
			 */
			IGnLookupLocalStreamIngestEvents*
			EventHandler() { return eventHandler_.native(); }


		private:
			void
			create();

			GnManagedPtr<IGnLookupLocalStreamIngestEvents*>	eventHandler_;

			DISALLOW_COPY_AND_ASSIGN(GnLookupLocalStreamIngest);
		};
	} /* namespace lookup_localstream */
}     /* namespace GracenoteSDK */

#endif /* GNSDK_LOOKUP_LOCALSTREAM */

#endif /* _GNSDK_LOOKUP_LOCALSTREAM_HPP_ */

