
namespace GracenoteSDK {

/**
* Represents the role that a contributor played in a music or video production;
* for example, singing, playing an instrument, acting, directing, and so on.
* <p><b>Note:</b></p>
* For music credits, the absence of a role for a person indicates that person is the primary
* artist, who may have performed multiple roles.
*
* <p><b>SDK Documentation</b></p>
*
* Topic:  Data Models
*
*  The above topic displays all the metadata returned from a recognition event,
*  including objects containing a GnRole object.
*  It does this in an expand/collapse format, showing object hierarchy and
*  a description of each field returned.
*
*/
public class GnRole : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnRole(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnRole_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnRole obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnRole() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnRole(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

/**
* Role category, such as string instruments or brass instruments.
* @return Category
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/
  public string Category {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnRole_Category_get(swigCPtr) );
	} 

  }

/**
* Role's display string.
* @return Role
*/
  public string Role {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnRole_Role_get(swigCPtr) );
	} 

  }

}

}
