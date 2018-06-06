
namespace GracenoteSDK {

/**
* Person or group primarily responsible for creating the Album or Track.
*
* Part of the metadata returned from a recognition event.
*
* <p><b>SDK Documentation</b></p>
*
* Topic:  .../docs/html-oo > index.html > Data Models
*
*  The above topic displays all the metadata returned from a recognition event.
*  It does this in an expand/collapse format, showing object hierarchy and
*  a description of each field returned.
*
*/
public class GnArtist : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnArtist(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnArtist_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnArtist obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnArtist() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnArtist(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public static string GnType() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnArtist_GnType();
    return ret;
  }

  public static GnArtist From(GnDataObject obj) {
    GnArtist ret = new GnArtist(gnsdk_csharp_marshalPINVOKE.GnArtist_From(GnDataObject.getCPtr(obj)), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Artist's official name.
* @return Name
*/
  public GnName Name {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnArtist_Name_get(swigCPtr);
      GnName ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnName(cPtr, true);
      return ret;
    } 
  }

/**
* Contributor object - contributor associated with the work
* @return Contributor
*/
  public GnContributor Contributor {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnArtist_Contributor_get(swigCPtr);
      GnContributor ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnContributor(cPtr, true);
      return ret;
    } 
  }

}

}
