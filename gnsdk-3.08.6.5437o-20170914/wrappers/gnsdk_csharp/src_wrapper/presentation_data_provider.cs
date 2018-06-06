
namespace GracenoteSDK {

/******
** Internal class  presentation_data_provider
*/
public class presentation_data_provider : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal presentation_data_provider(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(presentation_data_provider obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~presentation_data_provider() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_presentation_data_provider(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public presentation_data_provider() : this(gnsdk_csharp_marshalPINVOKE.new_presentation_data_provider__SWIG_0(), true) {
  }

  public presentation_data_provider(GnMoodgridPresentationType type) : this(gnsdk_csharp_marshalPINVOKE.new_presentation_data_provider__SWIG_1((int)type), true) {
  }

  public GnMoodgridDataPoint get_data(uint pos) {
    GnMoodgridDataPoint ret = new GnMoodgridDataPoint(gnsdk_csharp_marshalPINVOKE.presentation_data_provider_get_data(swigCPtr, pos), true);
    return ret;
  }

  public uint count() {
    uint ret = gnsdk_csharp_marshalPINVOKE.presentation_data_provider_count(swigCPtr);
    return ret;
  }

}

}
