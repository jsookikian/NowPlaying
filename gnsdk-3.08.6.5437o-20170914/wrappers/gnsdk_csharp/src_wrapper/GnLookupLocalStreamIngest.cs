
namespace GracenoteSDK {

public class GnLookupLocalStreamIngest : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnLookupLocalStreamIngest(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnLookupLocalStreamIngest obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnLookupLocalStreamIngest() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnLookupLocalStreamIngest(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public GnLookupLocalStreamIngest(GnLookupLocalStreamIngestEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnLookupLocalStreamIngest(GnLookupLocalStreamIngestEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Write to the ingestion process. You can call this multiple times to ensure that data is written when it is available.
*  @param data             [in] data to ingest
*  @param dataLength       [in] size of data being written
*/
  public void Write(byte[] bundleData, uint dataSize) {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocalStreamIngest_Write(swigCPtr, bundleData, dataSize);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Flushes the memory cache to the file storage and commits the changes. This call results in IO.
* Call this method to ensure that everything written is commited to the file system.
* Note: This is an optional call as, internally, data is flushed when it exceeds the cache size and when the object goes out of scope.
*/
  public void Flush() {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocalStreamIngest_Flush(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnLookupLocalStreamIngestEventsDelegate EventHandler() {
    global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnLookupLocalStreamIngest_EventHandler(swigCPtr);
    GnLookupLocalStreamIngestEventsDelegate ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnLookupLocalStreamIngestEventsDelegate(cPtr, false);
    return ret;
  }

}

}
