
namespace GracenoteSDK {

/**
* Third-party identifier used to match identified media to merchandise IDs in online stores and other services
*
*/
public class GnExternalId : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnExternalId(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnExternalId_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnExternalId obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnExternalId() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnExternalId(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public static string GnType() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnExternalId_GnType();
    return ret;
  }

  public static GnExternalId From(GnDataObject obj) {
    GnExternalId ret = new GnExternalId(gnsdk_csharp_marshalPINVOKE.GnExternalId_From(GnDataObject.getCPtr(obj)), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  External ID source (e.g., Amazon)
*  @return External ID source
*/
  public string Source {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnExternalId_Source_get(swigCPtr) );
	} 

  }

/**
*  External ID type
*  @return External ID type
*/
  public string Type {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnExternalId_Type_get(swigCPtr) );
	} 

  }

/**
*  External ID value
*  @return External ID value
*/
  public string Value {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnExternalId_Value_get(swigCPtr) );
	} 

  }

}

}
