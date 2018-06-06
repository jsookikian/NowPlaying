
namespace GracenoteSDK {

/**
* <b>Experimental</b>: Fetch asset raw data.
* The raw data is fetched during object construction
* and may result in lengthy network access if accessing
* from online.
*/
public class GnAssetFetch : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnAssetFetch(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnAssetFetch obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnAssetFetch() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnAssetFetch(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

      public byte[] DataBuffer
      {
        get
        {
          byte[] dataBytes = new byte[Size];
          System.Runtime.InteropServices.Marshal.Copy((System.IntPtr)Data, dataBytes, 0, (int)Size);
          return dataBytes;
        }
      }
    
/**
* Perform the fetch of the data from the provided URL.
* This method can fetch data from any valid URL. This class must
* be used to fetch data from a GNSDK local URL.
* Construction may result in lengthy network access if the URL is
* online and the target data is large.
*/
  public GnAssetFetch(GnUser user, string url, GnStatusEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnAssetFetch__SWIG_0(GnUser.getCPtr(user), url, GnStatusEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnAssetFetch(GnUser user, string url) : this(gnsdk_csharp_marshalPINVOKE.new_GnAssetFetch__SWIG_1(GnUser.getCPtr(user), url), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnAssetFetch(GnUser user, string url, GnLookupMode lookupMode, GnStatusEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnAssetFetch__SWIG_2(GnUser.getCPtr(user), url, (int)lookupMode, GnStatusEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnAssetFetch(GnUser user, string url, GnLookupMode lookupMode) : this(gnsdk_csharp_marshalPINVOKE.new_GnAssetFetch__SWIG_3(GnUser.getCPtr(user), url, (int)lookupMode), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public string Type() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnAssetFetch_Type(swigCPtr);
    return ret;
  }

/**
* Get the event handler provided on construction
* @return Event handler
*/
  public GnStatusEventsDelegate EventHandler() {
    global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnAssetFetch_EventHandler(swigCPtr);
    GnStatusEventsDelegate ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnStatusEventsDelegate(cPtr, false);
    return ret;
  }

/**
* Raw data size in bytes
*/
  public uint Size {
    get {
      uint ret = gnsdk_csharp_marshalPINVOKE.GnAssetFetch_Size_get(swigCPtr);
      return ret;
    } 
  }

  public System.IntPtr Data {get{System.IntPtr res = gnsdk_csharp_marshalPINVOKE.GnAssetFetch_Data_get(swigCPtr); ; return res;}
  }

}

}
