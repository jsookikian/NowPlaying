
namespace GracenoteSDK {

public class GnDspFeatureGenerator : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnDspFeatureGenerator(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnDspFeatureGenerator obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnDspFeatureGenerator() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnDspFeatureGenerator(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Initializes the DSP library.
* @param user set user
* @param featureType The kind of DSP feature, for example a fingerprint.
* @param audioSampleRate The source audio sample rate.
* @param audioSampleSize The source audio sample size.
* @param audioChannels	The source audio channels
*/
  public GnDspFeatureGenerator(GnUser user, GnDspFeatureType featureType, uint audioSampleRate, uint audioSampleSize, uint audioChannels) : this(gnsdk_csharp_marshalPINVOKE.new_GnDspFeatureGenerator(GnUser.getCPtr(user), (int)featureType, audioSampleRate, audioSampleSize, audioChannels), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public bool FeatureAudioWrite(byte[] audioData, uint audioDataBytes) {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnDspFeatureGenerator_FeatureAudioWrite(swigCPtr, audioData, audioDataBytes);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Indicates the the DSP feature has reached the end of the write operation.
*/
  public void FeatureEndOfAudioWrite() {
    gnsdk_csharp_marshalPINVOKE.GnDspFeatureGenerator_FeatureEndOfAudioWrite(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Retrieve GnDspFeature
* @return GnDspFeature
*/
  public GnDspFeature FeatureRetrieve() {
    GnDspFeature ret = new GnDspFeature(gnsdk_csharp_marshalPINVOKE.GnDspFeatureGenerator_FeatureRetrieve(swigCPtr), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
