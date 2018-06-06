
namespace GracenoteSDK {

/**
*  @internal GnNameEdit @endinternal
*  encapsulates the Name's meta data information returned by Gracenote
*/
public class GnNameEdit : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnNameEdit(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnNameEdit_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnNameEdit obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnNameEdit() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnNameEdit(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public void Language(GnListElement langElement) {
    gnsdk_csharp_marshalPINVOKE.GnNameEdit_Language(swigCPtr, GnListElement.getCPtr(langElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  @internal setDisplay @endinternal
*  Changes a GnDataObject value for a supported key of display value. If the value does not exist, it will
*   be added. If the value does exist, it will be changed. If NULL or an empty string is passed in, the
*   value will be deleted.
*  @param value set Value corresponding to the specified GnDataObject value key
*  <p><b>Remarks:</b></p>
*  Use this function to edit an existing value of display value. Note that the value must already
*   exist on the editable GnDataObject.
*/
  public string Display {
	/* csvarin typemap code */
	set 
	{
		System.IntPtr tempvalue = GnMarshalUTF8.NativeUtf8FromString(value);
		gnsdk_csharp_marshalPINVOKE.GnNameEdit_Display_set(swigCPtr, tempvalue);
		GnMarshalUTF8.ReleaseMarshaledUTF8String(tempvalue);
	}
 
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnNameEdit_Display_get(swigCPtr) );
	} 

  }

  public string Sortable {
	/* csvarin typemap code */
	set 
	{
		System.IntPtr tempvalue = GnMarshalUTF8.NativeUtf8FromString(value);
		gnsdk_csharp_marshalPINVOKE.GnNameEdit_Sortable_set(swigCPtr, tempvalue);
		GnMarshalUTF8.ReleaseMarshaledUTF8String(tempvalue);
	}
 
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnNameEdit_Sortable_get(swigCPtr) );
	} 

  }

  public GnName GnName {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnNameEdit_GnName_get(swigCPtr);
      GnName ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnName(cPtr, true);
      return ret;
    } 
  }

}

}
