
namespace GracenoteSDK {

/**
* GNSDK internal gdo string provider class
*/
public class gn_gdo_string_provider : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal gn_gdo_string_provider(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(gn_gdo_string_provider obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~gn_gdo_string_provider() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_gn_gdo_string_provider(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public gn_gdo_string_provider(GnDataObject obj, string key) : this(gnsdk_csharp_marshalPINVOKE.new_gn_gdo_string_provider(GnDataObject.getCPtr(obj), key), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public string get_data(uint pos) {
    string ret = gnsdk_csharp_marshalPINVOKE.gn_gdo_string_provider_get_data(swigCPtr, pos);
    return ret;
  }

  public uint count() {
    uint ret = gnsdk_csharp_marshalPINVOKE.gn_gdo_string_provider_count(swigCPtr);
    return ret;
  }

  public static readonly uint kOrdinalStart = gnsdk_csharp_marshalPINVOKE.gn_gdo_string_provider_kOrdinalStart_get();
  public static readonly uint kCountOffset = gnsdk_csharp_marshalPINVOKE.gn_gdo_string_provider_kCountOffset_get();
}

}
