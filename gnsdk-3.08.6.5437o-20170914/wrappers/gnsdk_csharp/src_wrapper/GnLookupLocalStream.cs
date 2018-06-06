
namespace GracenoteSDK {

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
public class GnLookupLocalStream : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnLookupLocalStream(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnLookupLocalStream obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnLookupLocalStream() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnLookupLocalStream(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Enable a lookup local Stream provider.
* @return Storage provider instance
*/
  public static GnLookupLocalStream Enable() {
    GnLookupLocalStream ret = new GnLookupLocalStream(gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_Enable(), false);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Sets a folder location for GNSDK LookupLocalStream
*  @param folderPath	[in] Relative path name for storage
* <p><b>Remarks:</b></p>
*  This API overrides the (default or explicit) folder location of GNSDK SQLite storage - for this database.
*/
  public void StorageLocation(string location) {
  System.IntPtr templocation = GnMarshalUTF8.NativeUtf8FromString(location);
    try {
      gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_StorageLocation(swigCPtr, templocation);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(templocation);
    }
  }

/**
*  Sets the local fingerprint lookup engine memory type
*  @param engineType	[in] GnLocalStreamEngineType enum indicating which memory mode to use
*/
  public void EngineType(GnLocalStreamEngineType engineType) {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_EngineType__SWIG_0(swigCPtr, (int)engineType);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnLocalStreamEngineType EngineType() {
    GnLocalStreamEngineType ret = (GnLocalStreamEngineType)gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_EngineType__SWIG_1(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Sets the current local fingerprint lookup processing method.
*  @param processingMethod	[in] GnLocalStreamFingerprintProcessingMethod enum indicating the local fingerprint lookup processing method.
*/
  public void FingerprintProcessingMethod(GnLocalStreamFingerprintProcessingMethod processingMethod) {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_FingerprintProcessingMethod__SWIG_0(swigCPtr, (int)processingMethod);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnLocalStreamFingerprintProcessingMethod FingerprintProcessingMethod() {
    GnLocalStreamFingerprintProcessingMethod ret = (GnLocalStreamFingerprintProcessingMethod)gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_FingerprintProcessingMethod__SWIG_1(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public uint FingerprintProcessing_CPU_MaxThreadCount() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_FingerprintProcessing_CPU_MaxThreadCount__SWIG_0(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Sets the option for local fingerprint lookup processing CPU maximum thread count
*  @param option_value	[in] The maximum number of threads FP Processing may spawn for a single query.
*/
  public void FingerprintProcessing_CPU_MaxThreadCount(uint option_value) {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_FingerprintProcessing_CPU_MaxThreadCount__SWIG_1(swigCPtr, option_value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public uint FingerprintProcessing_CPU_MinThreadWorkSize() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_FingerprintProcessing_CPU_MinThreadWorkSize__SWIG_0(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Sets the option for local fingerprint lookup processing CPU minimum thread work size.
*  @param option_value	[in] The minimum amount of work (in bytes) required by the fingerprint comparison enginge needed before
*                           it will spawn additional CPU threads.
*/
  public void FingerprintProcessing_CPU_MinThreadWorkSize(uint option_value) {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_FingerprintProcessing_CPU_MinThreadWorkSize__SWIG_1(swigCPtr, option_value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public uint FingerprintProcessing_GPU_MinWorkSize() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_FingerprintProcessing_GPU_MinWorkSize__SWIG_0(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Sets the Option for local fingerprint lookup processing GPU minimum work size
*  @param option_value	[in] The minimum amount of work (in bytes) required by the fingerprint comparison engine needed before
*                           it will attempt to use the GPU (if enabled).
*/
  public void FingerprintProcessing_GPU_MinWorkSize(uint option_value) {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_FingerprintProcessing_GPU_MinWorkSize__SWIG_1(swigCPtr, option_value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public uint FingerprintProcessing_GPU_MaxWorkSize() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_FingerprintProcessing_GPU_MaxWorkSize__SWIG_0(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Sets the option for local fingerprint lookup processing GPU maximum work size
*  @param option_value	[in] The maximum amount of work that will be sent to the GPU in a single block.
*/
  public void FingerprintProcessing_GPU_MaxWorkSize(uint option_value) {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_FingerprintProcessing_GPU_MaxWorkSize__SWIG_1(swigCPtr, option_value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Clear all tracks from the MusicID-Stream local database storage file.
*/
  public void StorageClear() {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_StorageClear(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Remove a bundle item from the MusicID-Stream local database.
* @param	bundleItemId	[in] Bundle item ID
*/
  public void StorageRemove(string bundleItemId) {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_StorageRemove(swigCPtr, bundleItemId);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

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
  public string Version {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_Version_get(swigCPtr) );
	} 

  }

/**
*  Retrieves the GnLookupLocalStream SDK's build date string.
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully allocating a GnManager instance. The returned
*  string is a constant. Do not attempt to modify or delete.
*  Example build date string: 2008-02-12 00:41 UTC
*/
  public string BuildDate {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnLookupLocalStream_BuildDate_get(swigCPtr) );
	} 

  }

}

}
