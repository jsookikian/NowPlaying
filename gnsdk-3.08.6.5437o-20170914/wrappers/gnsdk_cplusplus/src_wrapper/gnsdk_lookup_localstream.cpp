/*
 * Copyright (c) 2000-2016 Gracenote.

 *
 * Some code herein may be covered by US and international patents.
 */

/* gnsdk_lookup_localstream.cpp
 *
 * Implementation of C++ wrapper for GNSDK Lookup LocalStream
 *
 */
#include "gnsdk_manager.hpp"

#if GNSDK_LOOKUP_LOCALSTREAM

#include "gnsdk_lookup_localstream.hpp"

using namespace gracenote;
using namespace gracenote::lookup_localstream;


/*-----------------------------------------------------------------------------
 *  _callback_status
 */
static gnsdk_void_t GNSDK_CALLBACK_API
_callback_status(void* callback_data, gnsdk_lookup_localstream_status_t status, gnsdk_cstr_t bundle_id, gnsdk_bool_t* p_abort)
{
	GnLookupLocalStreamIngest* ingestor = (GnLookupLocalStreamIngest*) callback_data;
	gn_canceller               canceller;
	if (ingestor->EventHandler())
	{
		ingestor->EventHandler()->StatusEvent((GnLookupLocalStreamIngestStatus) status, bundle_id, canceller);
	}
	if (canceller.IsCancelled())
	{
		*p_abort = true;
	}
}


/*-----------------------------------------------------------------------------
 *  Version
 */
gnsdk_cstr_t
GnLookupLocalStream::Version()
{
	return gnsdk_lookup_localstream_get_version();
}


/*-----------------------------------------------------------------------------
 *  BuildDate
 */
gnsdk_cstr_t
GnLookupLocalStream::BuildDate()
{
	return gnsdk_lookup_localstream_get_build_date();
}


/*-----------------------------------------------------------------------------
 *  Enable
 */
GnLookupLocalStream&
GnLookupLocalStream::Enable() throw (GnError)
{
	static GnLookupLocalStream s_lookup_localstream;

	_gnsdk_internal::module_initialize(GNSDK_MODULE_LOOKUP_LOCALSTREAM);
	return s_lookup_localstream;
}


/*-----------------------------------------------------------------------------
 *  StorageLocation
 */
void
GnLookupLocalStream::StorageLocation(gnsdk_cstr_t location) throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_lookup_localstream_storage_location_set(location);
	if (error) { throw GnError(); }
}

/*-----------------------------------------------------------------------------
 *  _get_option
 */
static gnsdk_uint32_t
_get_uint32_option(gnsdk_cstr_t key) throw (GnError)
{
	gnsdk_cstr_t  value = GNSDK_NULL;
	gnsdk_error_t error;

	error = gnsdk_lookup_localstream_option_get(key, &value);
	if (error) { throw GnError(); }

	return gnstd::gn_atoi(value);
}

/*-----------------------------------------------------------------------------
 *  _set_option
 */
static void
_set_uint32_option(gnsdk_cstr_t key, gnsdk_uint32_t value) throw (GnError)
{
	char          buffer[16];
	gnsdk_error_t error;

	if (!gracenote::gnstd::gn_itoa(buffer, 16, value)) { throw GnError(); }

	error = gnsdk_lookup_localstream_option_set(key, buffer);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  EngineType
 */
void
GnLookupLocalStream::EngineType(GnLocalStreamEngineType engineType) throw (GnError)
{
	gnsdk_cstr_t option_value = GNSDK_NULL;
	gnsdk_error_t error;

	switch (engineType)
	{
	case kLocalStreamEngineMMap:
		option_value = GNSDK_LOOKUP_LOCALSTREAM_ENGINE_MMAP;
		break;

	case kLocalStreamEngineInMemory:
		option_value = GNSDK_LOOKUP_LOCALSTREAM_ENGINE_INMEMORY;
		break;

	case kLocalStreamEngineInvalid:
		option_value = GNSDK_NULL;
		break;
	}

	error = gnsdk_lookup_localstream_option_set(GNSDK_LOOKUP_LOCALSTREAM_OPTION_ENGINE_TYPE, option_value);
	if (error) { throw GnError(); }
}

/*-----------------------------------------------------------------------------
 *  EngineType
 */
GnLocalStreamEngineType
GnLookupLocalStream::EngineType(void) throw (GnError)
{
	gnsdk_cstr_t option_value = GNSDK_NULL;
	gnsdk_error_t error;

	error = gnsdk_lookup_localstream_option_get(GNSDK_LOOKUP_LOCALSTREAM_OPTION_ENGINE_TYPE, &option_value);
	if (error) { throw GnError(); }

	if (gnstd::gn_strcmp(option_value, GNSDK_LOOKUP_LOCALSTREAM_ENGINE_INMEMORY))
		return kLocalStreamEngineInMemory;
	return kLocalStreamEngineMMap;
}


/*-----------------------------------------------------------------------------
 *  FingerprintProcessingMethod
 */
void
GnLookupLocalStream::FingerprintProcessingMethod(GnLocalStreamFingerprintProcessingMethod processingMethod) throw (GnError)
{
	gnsdk_cstr_t option_value = GNSDK_NULL;
	gnsdk_error_t error;

	switch (processingMethod)
	{
	case kLocalStreamFingeprintProcessingUseCPU:
		option_value = GNSDK_LOOKUP_LOCALSTREAM_FP_PROCESSING_USE_CPU;
		break;

	case kLocalStreamFingeprintProcessingUseGPU:
		option_value = GNSDK_LOOKUP_LOCALSTREAM_FP_PROCESSING_USE_GPU;
		break;

	case kLocalStreamFingeprintProcessingUseGPU_CUDA:
		option_value = GNSDK_LOOKUP_LOCALSTREAM_FP_PROCESSING_USE_GPU_CUDA;
		break;

	case kLocalStreamFingeprintProcessingInvalid:
		option_value = GNSDK_NULL;
		break;
	}

	error = gnsdk_lookup_localstream_option_set(GNSDK_LOOKUP_LOCALSTREAM_OPTION_FP_PROCESSING, option_value);
	if (error) { throw GnError(); }
}

/*-----------------------------------------------------------------------------
 *  FingerprintProcessingMethod
 */
GnLocalStreamFingerprintProcessingMethod
GnLookupLocalStream::FingerprintProcessingMethod(void) throw (GnError)
{
	gnsdk_cstr_t option_value = GNSDK_NULL;
	gnsdk_error_t error;

	error = gnsdk_lookup_localstream_option_get(GNSDK_LOOKUP_LOCALSTREAM_OPTION_FP_PROCESSING, &option_value);
	if (error) { throw GnError(); }

	if (!option_value || gnstd::gn_strcmp(option_value, GNSDK_LOOKUP_LOCALSTREAM_FP_PROCESSING_USE_CPU))
		return kLocalStreamFingeprintProcessingUseCPU;
	if (gnstd::gn_strcmp(option_value, GNSDK_LOOKUP_LOCALSTREAM_FP_PROCESSING_USE_GPU))
		return kLocalStreamFingeprintProcessingUseGPU;
	if (gnstd::gn_strcmp(option_value, GNSDK_LOOKUP_LOCALSTREAM_FP_PROCESSING_USE_GPU_CUDA))
		return kLocalStreamFingeprintProcessingUseGPU_CUDA;

	return kLocalStreamFingeprintProcessingInvalid;
}


/*-----------------------------------------------------------------------------
 *  FingerprintProcessing_CPU_MaxThreadCount
 */
gnsdk_uint32_t
GnLookupLocalStream::FingerprintProcessing_CPU_MaxThreadCount(void) throw (GnError)
{
	return _get_uint32_option(GNSDK_LOOKUP_LOCALSTREAM_OPTION_FP_PROCESSING_CPU_MAX_THREAD_COUNT);
}

/*-----------------------------------------------------------------------------
 *  FingerprintProcessing_CPU_MaxThreadCount
 */
void
GnLookupLocalStream::FingerprintProcessing_CPU_MaxThreadCount(gnsdk_uint32_t option_value) throw (GnError)
{
	_set_uint32_option(GNSDK_LOOKUP_LOCALSTREAM_OPTION_FP_PROCESSING_CPU_MAX_THREAD_COUNT, option_value);
}


/*-----------------------------------------------------------------------------
 *  FingerprintProcessing_CPU_MinThreadWorkSize
 */
gnsdk_uint32_t
GnLookupLocalStream::FingerprintProcessing_CPU_MinThreadWorkSize(void) throw (GnError)
{
	return _get_uint32_option(GNSDK_LOOKUP_LOCALSTREAM_OPTION_FP_PROCESSING_CPU_MIN_THREAD_WORK_SIZE);
}

/*-----------------------------------------------------------------------------
 *  FingerprintProcessing_CPU_MinThreadWorkSize
 */
void
GnLookupLocalStream::FingerprintProcessing_CPU_MinThreadWorkSize(gnsdk_uint32_t option_value) throw (GnError)
{
	_set_uint32_option(GNSDK_LOOKUP_LOCALSTREAM_OPTION_FP_PROCESSING_CPU_MIN_THREAD_WORK_SIZE, option_value);
}


/*-----------------------------------------------------------------------------
 *  FingerprintProcessing_GPU_MinWorkSize
 */
gnsdk_uint32_t
GnLookupLocalStream::FingerprintProcessing_GPU_MinWorkSize(void) throw (GnError)
{
	return _get_uint32_option(GNSDK_LOOKUP_LOCALSTREAM_OPTION_FP_PROCESSING_GPU_MIN_WORK_SIZE);
}

/*-----------------------------------------------------------------------------
 *  FingerprintProcessing_GPU_MinWorkSize
 */
void
GnLookupLocalStream::FingerprintProcessing_GPU_MinWorkSize(gnsdk_uint32_t option_value) throw (GnError)
{
	_set_uint32_option(GNSDK_LOOKUP_LOCALSTREAM_OPTION_FP_PROCESSING_GPU_MIN_WORK_SIZE, option_value);
}


/*-----------------------------------------------------------------------------
 *  FingerprintProcessing_GPU_MaxWorkSize
 */
gnsdk_uint32_t
GnLookupLocalStream::FingerprintProcessing_GPU_MaxWorkSize(void) throw (GnError)
{
	return _get_uint32_option(GNSDK_LOOKUP_LOCALSTREAM_OPTION_FP_PROCESSING_GPU_MAX_WORK_SIZE);
}

/*-----------------------------------------------------------------------------
 *  FingerprintProcessing_GPU_MaxWorkSize
 */
void
GnLookupLocalStream::FingerprintProcessing_GPU_MaxWorkSize(gnsdk_uint32_t option_value) throw (GnError)
{
	_set_uint32_option(GNSDK_LOOKUP_LOCALSTREAM_OPTION_FP_PROCESSING_GPU_MAX_WORK_SIZE, option_value);
}


/*-----------------------------------------------------------------------------
 *  StorageClear
 */
void
GnLookupLocalStream::StorageClear() throw (GnError)
{
	gnsdk_error_t error;

	error = gnsdk_lookup_localstream_storage_clear();
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  StorageRemove
 */
void
GnLookupLocalStream::StorageRemove(gnsdk_cstr_t bundleId) throw (GnError)
{
	gnsdk_error_t error = gnsdk_lookup_localstream_storage_remove(bundleId);
	if (error) { throw GnError(); }
}


/* ***************************************************************************************************************************** */
/*  GnLookupLocalStreamIngest */
/* ***************************************************************************************************************************** */
GnLookupLocalStreamIngest::GnLookupLocalStreamIngest(IGnLookupLocalStreamIngestEvents* pEventHandler) throw (GnError)
{
	eventHandler_ = GnManagedPtr<IGnLookupLocalStreamIngestEvents*>(pEventHandler, GnManagedPtr<IGnLookupLocalStreamIngestEvents*>::ptr_nomanage);
	create();
}

GnLookupLocalStreamIngest::GnLookupLocalStreamIngest(GnManagedPtr<IGnLookupLocalStreamIngestEvents*> eventHandler) throw (GnError)
{
	eventHandler_ = eventHandler;
	create();
}

void
GnLookupLocalStreamIngest::create()
{
	_gnsdk_internal::module_initialize(GNSDK_MODULE_LOOKUP_LOCALSTREAM);

	gnsdk_lookup_localstream_ingest_handle_t handle = GNSDK_NULL;

	gnsdk_error_t error = gnsdk_lookup_localstream_ingest_create(_callback_status, this, &handle);
	if (error) { throw GnError(); }

	assign(handle);
}


/*-----------------------------------------------------------------------------
 *  Write
 */
void
GnLookupLocalStreamIngest::Write(gnsdk_byte_t* bundleData, gnsdk_size_t dataLength) throw (GnError)
{
	gnsdk_error_t error = gnsdk_lookup_localstream_ingest_write( native(), (void*)bundleData, dataLength);
	if (error) { throw GnError(); }
}


/*-----------------------------------------------------------------------------
 *  Flush
 */
void
GnLookupLocalStreamIngest::Flush() throw (GnError)
{
	gnsdk_error_t error = gnsdk_lookup_localstream_ingest_flush(native());
	if (error) { throw GnError(); }
}


#endif /*GNSDK_LOOKUP_LOCALSTREAM*/

