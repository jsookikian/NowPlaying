
namespace GracenoteSDK {

/**************************************************************************
** GnDspFeature
*/
public class GnDspFeature : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnDspFeature(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnDspFeature obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnDspFeature() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnDspFeature(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public string FeatureData() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnDspFeature_FeatureData(swigCPtr);
    return ret;
  }

  public GnDspFeatureQuality FeatureQuality() {
    GnDspFeatureQuality ret = (GnDspFeatureQuality)gnsdk_csharp_marshalPINVOKE.GnDspFeature_FeatureQuality(swigCPtr);
    return ret;
  }

}

}
