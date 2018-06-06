
namespace GracenoteSDK {

public class GnResponseError : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnResponseError(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnResponseError_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnResponseError obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnResponseError() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnResponseError(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public static string GnType() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnResponseError_GnType();
    return ret;
  }

  public static GnResponseError From(GnDataObject obj) {
    GnResponseError ret = new GnResponseError(gnsdk_csharp_marshalPINVOKE.GnResponseError_From(GnDataObject.getCPtr(obj)), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnResponseError() : this(gnsdk_csharp_marshalPINVOKE.new_GnResponseError(), true) {
  }

}

}
