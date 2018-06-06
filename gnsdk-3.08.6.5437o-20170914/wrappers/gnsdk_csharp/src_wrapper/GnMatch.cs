
namespace GracenoteSDK {

/**
* GnMatch
*/
public class GnMatch : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnMatch(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnMatch_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMatch obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMatch() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMatch(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

/**
* Match's Gracenote Tui (title-unique identifier)
* @return Tui
*/
  public string Tui {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMatch_Tui_get(swigCPtr) );
	} 

  }

/**
* Match's Gracenote Tui Tag.
* @return Tui Tag
*/
  public string TuiTag {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMatch_TuiTag_get(swigCPtr) );
	} 

  }

/**
*  Match info type - album or contributor
*  @return Match information
*/
  public string MatchInfo {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMatch_MatchInfo_get(swigCPtr) );
	} 

  }

  public GnExternalIdEnumerable ExternalIds {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnMatch_ExternalIds_get(swigCPtr);
      GnExternalIdEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnExternalIdEnumerable(cPtr, true);
      return ret;
    } 
  }

}

}
