
namespace GracenoteSDK {

/**
* GNSDK internal provider class
*/
public class locale_info_provider : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal locale_info_provider(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(locale_info_provider obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~locale_info_provider() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_locale_info_provider(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Constructor
*/
  public locale_info_provider() : this(gnsdk_csharp_marshalPINVOKE.new_locale_info_provider(), true) {
  }

/**
* Get locale available data at position
* @param pos - position of GnLocale info to get
* @return Locale info
*/
  public GnLocaleInfo get_data(uint pos) {
    GnLocaleInfo ret = new GnLocaleInfo(gnsdk_csharp_marshalPINVOKE.locale_info_provider_get_data(swigCPtr, pos), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Get total count of locales available
* @return Count
*/
  public uint count() {
    uint ret = gnsdk_csharp_marshalPINVOKE.locale_info_provider_count(swigCPtr);
    return ret;
  }

  public static readonly uint kOrdinalStart = gnsdk_csharp_marshalPINVOKE.locale_info_provider_kOrdinalStart_get();
  public static readonly uint kCountOffset = gnsdk_csharp_marshalPINVOKE.locale_info_provider_kCountOffset_get();
}

}
