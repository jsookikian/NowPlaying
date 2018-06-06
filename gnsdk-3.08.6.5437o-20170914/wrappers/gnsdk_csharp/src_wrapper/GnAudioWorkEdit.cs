
namespace GracenoteSDK {

/**
*  @internal GnAudioWorkEdit @endinternal
*  represents  AudioWork's information returned by Gracenote.
*/
public class GnAudioWorkEdit : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnAudioWorkEdit(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnAudioWorkEdit_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnAudioWorkEdit obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnAudioWorkEdit() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnAudioWorkEdit(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public GnCreditEdit Credit(uint ord) {
    GnCreditEdit ret = new GnCreditEdit(gnsdk_csharp_marshalPINVOKE.GnAudioWorkEdit_Credit(swigCPtr, ord), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Origin(GnListElement originElement) {
    gnsdk_csharp_marshalPINVOKE.GnAudioWorkEdit_Origin(swigCPtr, GnListElement.getCPtr(originElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Era(GnListElement eraElement) {
    gnsdk_csharp_marshalPINVOKE.GnAudioWorkEdit_Era(swigCPtr, GnListElement.getCPtr(eraElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  @internal CompositionForm @endinternal
*  Sets a list-based value by the list item Submit ID for COMPOSITION FORM. If the value does not
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the
*   value is deleted.
*  @param value set Value corresponding to the specified GnDataObject value key
*  <p><b>Remarks:</b></p>
*  Use this function to set a list-based Submit ID to COMPOSITION FORM, prior to adding the GnDataObject to a
*   parcel.
*/
  public string CompositionForm {
	/* csvarin typemap code */
	set 
	{
		System.IntPtr tempvalue = GnMarshalUTF8.NativeUtf8FromString(value);
		gnsdk_csharp_marshalPINVOKE.GnAudioWorkEdit_CompositionForm_set(swigCPtr, tempvalue);
		GnMarshalUTF8.ReleaseMarshaledUTF8String(tempvalue);
	}
 
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnAudioWorkEdit_CompositionForm_get(swigCPtr) );
	} 

  }

/**
*  @internal getTitleEdit @endinternal
*  Create an empty object of GnTitleEdit using TITLE OFFICIAL.
*  @return GnTitleEdit
*/
  public GnTitleEdit Title {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnAudioWorkEdit_Title_get(swigCPtr);
      GnTitleEdit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnTitleEdit(cPtr, true);
      return ret;
    } 
  }

  public GnCreditEdit CreditAdd {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnAudioWorkEdit_CreditAdd_get(swigCPtr);
      GnCreditEdit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnCreditEdit(cPtr, true);
      return ret;
    } 
  }

  public GnAudioWork GnAudioWork {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnAudioWorkEdit_GnAudioWork_get(swigCPtr);
      GnAudioWork ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnAudioWork(cPtr, true);
      return ret;
    } 
  }

}

}
