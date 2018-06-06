
namespace GracenoteSDK {

/*****
** Internal class  moodgrid_provider
*/
public class moodgrid_provider : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal moodgrid_provider(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(moodgrid_provider obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~moodgrid_provider() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_moodgrid_provider(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public GnMoodgridProvider get_data(uint pos) {
    GnMoodgridProvider ret = new GnMoodgridProvider(gnsdk_csharp_marshalPINVOKE.moodgrid_provider_get_data(swigCPtr, pos), true);
    return ret;
  }

  public uint count() {
    uint ret = gnsdk_csharp_marshalPINVOKE.moodgrid_provider_count(swigCPtr);
    return ret;
  }

  public moodgrid_provider() : this(gnsdk_csharp_marshalPINVOKE.new_moodgrid_provider(), true) {
  }

}

}
