
namespace GracenoteSDK {

/**
*  Collection of matches from a Scan & Match query
*/
public class GnResponseMatches : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnResponseMatches(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnResponseMatches_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnResponseMatches obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnResponseMatches() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnResponseMatches(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public GnMatchEnumerable Matches {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnResponseMatches_Matches_get(swigCPtr);
      GnMatchEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnMatchEnumerable(cPtr, true);
      return ret;
    } 
  }

}

}
