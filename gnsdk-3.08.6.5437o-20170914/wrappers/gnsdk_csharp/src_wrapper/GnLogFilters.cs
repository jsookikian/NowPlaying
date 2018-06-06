
namespace GracenoteSDK {

/**
* Logging Filters
*/
public class GnLogFilters : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnLogFilters(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnLogFilters obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnLogFilters() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnLogFilters(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public GnLogFilters() : this(gnsdk_csharp_marshalPINVOKE.new_GnLogFilters(), true) {
  }

/** Include error logging messages */
  public GnLogFilters Clear() {
    GnLogFilters ret = new GnLogFilters(gnsdk_csharp_marshalPINVOKE.GnLogFilters_Clear(swigCPtr), false);
    return ret;
  }

/** Include error logging messages */
  public GnLogFilters Error() {
    GnLogFilters ret = new GnLogFilters(gnsdk_csharp_marshalPINVOKE.GnLogFilters_Error(swigCPtr), false);
    return ret;
  }

/** Include warning logging messages */
  public GnLogFilters Warning() {
    GnLogFilters ret = new GnLogFilters(gnsdk_csharp_marshalPINVOKE.GnLogFilters_Warning(swigCPtr), false);
    return ret;
  }

/** Include informative logging messages */
  public GnLogFilters Info() {
    GnLogFilters ret = new GnLogFilters(gnsdk_csharp_marshalPINVOKE.GnLogFilters_Info(swigCPtr), false);
    return ret;
  }

/** Include debugging logging messages */
  public GnLogFilters Debug() {
    GnLogFilters ret = new GnLogFilters(gnsdk_csharp_marshalPINVOKE.GnLogFilters_Debug(swigCPtr), false);
    return ret;
  }

/** Include all logging messages */
  public GnLogFilters All() {
    GnLogFilters ret = new GnLogFilters(gnsdk_csharp_marshalPINVOKE.GnLogFilters_All(swigCPtr), false);
    return ret;
  }

}

}
