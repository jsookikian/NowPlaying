
namespace GracenoteSDK {

public class GnResponse : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnResponse(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnResponse_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnResponse obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnResponse() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnResponse(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public static string GnType() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnResponse_GnType();
    return ret;
  }

  public static GnResponse From(GnDataObject obj) {
    GnResponse ret = new GnResponse(gnsdk_csharp_marshalPINVOKE.GnResponse_From(GnDataObject.getCPtr(obj)), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnResponse() : this(gnsdk_csharp_marshalPINVOKE.new_GnResponse(), true) {
  }

  public GnResponseMeta meta() {
    GnResponseMeta ret = new GnResponseMeta(gnsdk_csharp_marshalPINVOKE.GnResponse_meta(swigCPtr), true);
    return ret;
  }

  public GnResponseData data() {
    GnResponseData ret = new GnResponseData(gnsdk_csharp_marshalPINVOKE.GnResponse_data(swigCPtr), true);
    return ret;
  }

  public GnResponseError error() {
    GnResponseError ret = new GnResponseError(gnsdk_csharp_marshalPINVOKE.GnResponse_error(swigCPtr), true);
    return ret;
  }

}

}
