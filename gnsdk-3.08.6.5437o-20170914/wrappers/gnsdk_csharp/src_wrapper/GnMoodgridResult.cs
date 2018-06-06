
namespace GracenoteSDK {

/**
** <b>Experimental</b>: GnMoodgridResult
*/
public class GnMoodgridResult : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMoodgridResult(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMoodgridResult obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMoodgridResult() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMoodgridResult(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
*  Returns the count of the GnMoodgridIdentifier instances in this result.
* @return count
*/
  public uint Count() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnMoodgridResult_Count(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnMoodgridResultEnumerable Identifiers {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnMoodgridResult_Identifiers_get(swigCPtr);
      GnMoodgridResultEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnMoodgridResultEnumerable(cPtr, true);
      return ret;
    } 
  }

}

}
