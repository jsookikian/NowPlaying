
namespace GracenoteSDK {

/**
* <b>Experimental</b>: GnPlaylistResults
*/
public class GnPlaylistResults : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnPlaylistResults(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnPlaylistResults obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnPlaylistResults() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnPlaylistResults(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public GnPlaylistResults() : this(gnsdk_csharp_marshalPINVOKE.new_GnPlaylistResults(), true) {
  }

  public GnPlaylistResultIdentEnumerable Identifiers() {
    GnPlaylistResultIdentEnumerable ret = new GnPlaylistResultIdentEnumerable(gnsdk_csharp_marshalPINVOKE.GnPlaylistResults_Identifiers(swigCPtr), true);
    return ret;
  }

}

}
