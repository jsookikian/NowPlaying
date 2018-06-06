
namespace GracenoteSDK {

/**
** GnMoodgridDataPoint
*/
public class GnMoodgridDataPoint : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMoodgridDataPoint(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMoodgridDataPoint obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMoodgridDataPoint() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMoodgridDataPoint(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public GnMoodgridDataPoint() : this(gnsdk_csharp_marshalPINVOKE.new_GnMoodgridDataPoint__SWIG_0(), true) {
  }

  public GnMoodgridDataPoint(uint x, uint y) : this(gnsdk_csharp_marshalPINVOKE.new_GnMoodgridDataPoint__SWIG_1(x, y), true) {
  }

  public uint X {
    set {
      gnsdk_csharp_marshalPINVOKE.GnMoodgridDataPoint_X_set(swigCPtr, value);
    } 
    get {
      uint ret = gnsdk_csharp_marshalPINVOKE.GnMoodgridDataPoint_X_get(swigCPtr);
      return ret;
    } 
  }

  public uint Y {
    set {
      gnsdk_csharp_marshalPINVOKE.GnMoodgridDataPoint_Y_set(swigCPtr, value);
    } 
    get {
      uint ret = gnsdk_csharp_marshalPINVOKE.GnMoodgridDataPoint_Y_get(swigCPtr);
      return ret;
    } 
  }

}

}
