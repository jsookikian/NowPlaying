
namespace GracenoteSDK {

public class GnResponseMeta : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnResponseMeta(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnResponseMeta_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnResponseMeta obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnResponseMeta() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnResponseMeta(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public static string GnType() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnResponseMeta_GnType();
    return ret;
  }

  public static GnResponseMeta From(GnDataObject obj) {
    GnResponseMeta ret = new GnResponseMeta(gnsdk_csharp_marshalPINVOKE.GnResponseMeta_From(GnDataObject.getCPtr(obj)), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnResponseMeta() : this(gnsdk_csharp_marshalPINVOKE.new_GnResponseMeta(), true) {
  }

}

}
