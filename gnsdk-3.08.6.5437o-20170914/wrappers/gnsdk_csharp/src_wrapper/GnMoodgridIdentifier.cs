
namespace GracenoteSDK {

/**
** <b>Experimental</b>: GnMoodgridIdentifier
*/
public class GnMoodgridIdentifier : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMoodgridIdentifier(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMoodgridIdentifier obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMoodgridIdentifier() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMoodgridIdentifier(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Retrieves a read only string that is the media identifier.
*/
  public string MediaIdentifier {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMoodgridIdentifier_MediaIdentifier_get(swigCPtr) );
	} 

  }

/**
* Retrieves a read only string that is the group the MediaIdentifier belongs to.
*  E.g. in the case of a Playlist provider , the group represents the collection name.
*/
  public string Group {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMoodgridIdentifier_Group_get(swigCPtr) );
	} 

  }

}

}
