
namespace GracenoteSDK {

/**
** <b>Experimental</b>: GnMoodgridProvider
*/
public class GnMoodgridProvider : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMoodgridProvider(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMoodgridProvider obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMoodgridProvider() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMoodgridProvider(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Retrieves the name of the moodgrid provider.
* @return string representing the name of the provider.
*/
  public string Name {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMoodgridProvider_Name_get(swigCPtr) );
	} 

  }

/**
* Retrieves the type of Moodgrid provider.e.g. playlist collection
* @return string value denoting type of provider
*/
  public string Type {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMoodgridProvider_Type_get(swigCPtr) );
	} 

  }

/**
* Retrieves a bool value indicating whether the provider needs network access.
* @return requiresnetwork
*/
  public bool RequiresNetwork {
    get {
      bool ret = gnsdk_csharp_marshalPINVOKE.GnMoodgridProvider_RequiresNetwork_get(swigCPtr);
      return ret;
    } 
  }

}

}
