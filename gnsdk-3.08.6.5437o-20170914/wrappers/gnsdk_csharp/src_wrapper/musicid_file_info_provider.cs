
namespace GracenoteSDK {

public class musicid_file_info_provider : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal musicid_file_info_provider(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(musicid_file_info_provider obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~musicid_file_info_provider() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_musicid_file_info_provider(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
*@internal
*  Gets the GnMusicIdFileInfo object at the requested position
*  @param pos				[in] the index of obect to retrieve
*@endinternal
*/
  public GnMusicIdFileInfo get_data(uint pos) {
    GnMusicIdFileInfo ret = new GnMusicIdFileInfo(gnsdk_csharp_marshalPINVOKE.musicid_file_info_provider_get_data(swigCPtr, pos), true);
    return ret;
  }

/**
*@internal
*  Gets the number of GnMusicIdFileInfo objects available
*@endinternal
*/
  public uint count() {
    uint ret = gnsdk_csharp_marshalPINVOKE.musicid_file_info_provider_count(swigCPtr);
    return ret;
  }

}

}
