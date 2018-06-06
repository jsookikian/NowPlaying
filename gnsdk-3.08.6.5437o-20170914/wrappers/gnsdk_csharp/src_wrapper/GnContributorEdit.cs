
namespace GracenoteSDK {

/**
*  @internal GnContributorEdit @endinternal
*  represents  GnContributor's information returned by Gracenote.
*/
public class GnContributorEdit : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnContributorEdit(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnContributorEdit_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnContributorEdit obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnContributorEdit() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnContributorEdit(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public void Genre(GnListElement genreElement) {
    gnsdk_csharp_marshalPINVOKE.GnContributorEdit_Genre(swigCPtr, GnListElement.getCPtr(genreElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Origin(GnListElement originElement) {
    gnsdk_csharp_marshalPINVOKE.GnContributorEdit_Origin(swigCPtr, GnListElement.getCPtr(originElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Era(GnListElement eraElement) {
    gnsdk_csharp_marshalPINVOKE.GnContributorEdit_Era(swigCPtr, GnListElement.getCPtr(eraElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void ArtistType(GnListElement arttypeElement) {
    gnsdk_csharp_marshalPINVOKE.GnContributorEdit_ArtistType(swigCPtr, GnListElement.getCPtr(arttypeElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnContributor GnContributor {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnContributorEdit_GnContributor_get(swigCPtr);
      GnContributor ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnContributor(cPtr, true);
      return ret;
    } 
  }

}

}
