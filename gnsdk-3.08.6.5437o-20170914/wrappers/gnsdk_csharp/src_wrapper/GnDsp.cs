
namespace GracenoteSDK {

/**************************************************************************
** GnDsp
*/
public class GnDsp : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnDsp(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnDsp obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnDsp() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnDsp(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Enable a dsp provider.
* @return dsp provider instance
*/
  public static GnDsp Enable() {
    GnDsp ret = new GnDsp(gnsdk_csharp_marshalPINVOKE.GnDsp_Enable(), false);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Sets a folder location for Audio Classifier Storage
*  @param location	[in] Relative path name for storage
*/
  public void AudioClassifierStorageLocation(string location) {
  System.IntPtr templocation = GnMarshalUTF8.NativeUtf8FromString(location);
    try {
      gnsdk_csharp_marshalPINVOKE.GnDsp_AudioClassifierStorageLocation(swigCPtr, templocation);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(templocation);
    }
  }

/**
*  Retrieves GnDsp SDK version string.
*  This API can be called at any time, after getting instance of GnManager successfully. The returned
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
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnDsp_Version_get(swigCPtr) );
	} 

  }

/**
*  Retrieves the GnDsp SDK's build date string.
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, after getting instance of GnManager successfully. The returned
* string is a constant. Do not attempt to modify or delete.
*  Example build date string: 2008-02-12 00:41 UTC
*/
  public string BuildDate {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnDsp_BuildDate_get(swigCPtr) );
	} 

  }

}

}
