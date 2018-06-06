
namespace GracenoteSDK {

public class GnConfig : GnConfigObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnConfig(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnConfig_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnConfig obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnConfig() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnConfig(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public GnConfig() : this(gnsdk_csharp_marshalPINVOKE.new_GnConfig__SWIG_0(), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnConfig(string config) : this(gnsdk_csharp_marshalPINVOKE.new_GnConfig__SWIG_1(config), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Set(string custom, string value) {
    gnsdk_csharp_marshalPINVOKE.GnConfig_Set__SWIG_0(swigCPtr, custom, value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Set(GnConfigOptionAccess access) {
    gnsdk_csharp_marshalPINVOKE.GnConfig_Set__SWIG_1(swigCPtr, (int)access);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Set(GnConfigOptionEnable enable, bool value) {
    gnsdk_csharp_marshalPINVOKE.GnConfig_Set__SWIG_2(swigCPtr, (int)enable, value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Set(GnConfigOptionLocation location, string value) {
    gnsdk_csharp_marshalPINVOKE.GnConfig_Set__SWIG_3(swigCPtr, (int)location, value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
