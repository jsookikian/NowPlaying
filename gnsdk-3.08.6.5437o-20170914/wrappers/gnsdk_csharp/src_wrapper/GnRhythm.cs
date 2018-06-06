
namespace GracenoteSDK {

/**
* \class GnRhythm
* Gracenote Rhythm provide a suite of Adaptive Radio and Recommendation features.
*
* Key features of Gracenote Rhythm:
*    - Creates highly-relevant and personalized adaptive radio experiences and recommendations for end-users
*    - Delivers radio stations or playlists from seed artist(s) and track(s)
*    - Radio stations respond to user's likes and dislikes and includes support for DMCA (Digital Millennium Copyright Act) sequencing rulesPerforms bulk audio track recognition
*/
public class GnRhythm : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnRhythm(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnRhythm obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnRhythm() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnRhythm(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
*  Retrieves the Rhythm library's version string.
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, after getting instance of GnManager successfully.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
*/
  public static string Version() {
	System.IntPtr temp = gnsdk_csharp_marshalPINVOKE.GnRhythm_Version(); 
	return GnMarshalUTF8.StringFromNativeUtf8(temp);
}

/**
*  Retrieves the Rhythm library's build date string.
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, after getting instance of GnManager successfully.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example build date string: 2008-02-12 00:41 UTC
*/
  public static string BuildDate() {
	System.IntPtr temp = gnsdk_csharp_marshalPINVOKE.GnRhythm_BuildDate(); 
	return GnMarshalUTF8.StringFromNativeUtf8(temp);
}

  public GnRhythm() : this(gnsdk_csharp_marshalPINVOKE.new_GnRhythm(), true) {
  }

}

}
