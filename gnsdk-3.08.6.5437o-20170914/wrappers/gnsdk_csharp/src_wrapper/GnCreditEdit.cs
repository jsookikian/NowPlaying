
namespace GracenoteSDK {

/**
*  @internal GnCreditEdit @endinternal
*  represents GnCredit's information returned by Gracenote.
*/
public class GnCreditEdit : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnCreditEdit(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnCreditEdit_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnCreditEdit obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnCreditEdit() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnCreditEdit(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public void Role(GnListElement roleElement) {
    gnsdk_csharp_marshalPINVOKE.GnCreditEdit_Role(swigCPtr, GnListElement.getCPtr(roleElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  @internal getNameOfficialEdit @endinternal
*  Create an empty object of GnNameEdit using NAME OFFICIAL.
*  @return GnNameEdit
*/
  public GnNameEdit Name {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnCreditEdit_Name_get(swigCPtr);
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
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnCreditEdit_Contributor_get(swigCPtr);
      GnContributorEdit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnContributorEdit(cPtr, true);
      return ret;
    } 
  }

  public GnCredit GnCredit {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnCreditEdit_GnCredit_get(swigCPtr);
      GnCredit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnCredit(cPtr, true);
      return ret;
    } 
  }

}

}
