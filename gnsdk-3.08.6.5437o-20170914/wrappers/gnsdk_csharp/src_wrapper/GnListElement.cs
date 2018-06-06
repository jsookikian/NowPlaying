
namespace GracenoteSDK {

/**
* list_element_child_iterable
*//**
* Element of a Gracenote list.
*/
public class GnListElement : GnListElementObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnListElement(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnListElement_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnListElement obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnListElement() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnListElement(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

/**
* Retrieves a display string for a given list element.
* <p><b>Remarks:</b></p>
* Use this function to directly retrieve the display string from a list element.
*/
  public string DisplayString {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnListElement_DisplayString_get(swigCPtr) );
	} 

  }

/**
* Retrieves a specified list element ID for a given list element.
* <p><b>Remarks:</b></p>
* Use this function to retrieve the ID of a list element.
*/
  public uint Id {
    get {
      uint ret = gnsdk_csharp_marshalPINVOKE.GnListElement_Id_get(swigCPtr);
      return ret;
    } 
  }

/**
* Retrieves a list element ID for use in submitting parcels.
*/
  public uint IdForSubmit {
    get {
      uint ret = gnsdk_csharp_marshalPINVOKE.GnListElement_IdForSubmit_get(swigCPtr);
      return ret;
    } 
  }

/**
* Retrieves the list element's description.
*/
  public string Description {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnListElement_Description_get(swigCPtr) );
	} 

  }

/**
* The list element's Rating Type ID (available in content ratings list).
*/
  public string RatingTypeId {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnListElement_RatingTypeId_get(swigCPtr) );
	} 

  }

/**
* Retrieves the parent element of the given list element.
* <p><b>Remarks:</b></p>
* When GNSDK Manager throws an error exception with error code SDKMGRERR_NotFound,
* then the given element is the top-most parent element.
*/
  public GnListElement Parent {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnListElement_Parent_get(swigCPtr);
      GnListElement ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnListElement(cPtr, true);
      return ret;
    } 
  }

/**
* Retrieves the hierarchy level for a given list element.
*/
  public uint Level {
    get {
      uint ret = gnsdk_csharp_marshalPINVOKE.GnListElement_Level_get(swigCPtr);
      return ret;
    } 
  }

  public GnListElementChildEnumerable Children {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnListElement_Children_get(swigCPtr);
      GnListElementChildEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnListElementChildEnumerable(cPtr, true);
      return ret;
    } 
  }

}

}
