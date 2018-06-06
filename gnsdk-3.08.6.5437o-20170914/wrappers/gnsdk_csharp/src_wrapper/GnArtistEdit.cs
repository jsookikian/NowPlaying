
namespace GracenoteSDK {

/**
*  @internal GnArtistEdit @endinternal
*  represents  Artist's information returned by Gracenote.
*/
public class GnArtistEdit : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnArtistEdit(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnArtistEdit_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnArtistEdit obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnArtistEdit() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnArtistEdit(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

/**
*  @internal getNameOfficialEdit @endinternal
*  Create an empty object of GnNameEdit using NAME OFFICIAL.
*  @return GnNameEdit
*/
  public GnNameEdit Name {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnArtistEdit_Name_get(swigCPtr);
      GnNameEdit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnNameEdit(cPtr, true);
      return ret;
    } 
  }

/**
*  @internal getContributorEdit @endinternal
*  Create an empty object of GnContributorEdit using CONTRIBUTOR.
*  @return GnContributorEdit
*/
  public GnContributorEdit Contributor {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnArtistEdit_Contributor_get(swigCPtr);
      GnContributorEdit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnContributorEdit(cPtr, true);
      return ret;
    } 
  }

  public GnArtist GnArtist {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnArtistEdit_GnArtist_get(swigCPtr);
      GnArtist ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnArtist(cPtr, true);
      return ret;
    } 
  }

}

}
