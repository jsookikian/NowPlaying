
namespace GracenoteSDK {

public class list_element_provider : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal list_element_provider(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(list_element_provider obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~list_element_provider() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_list_element_provider(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/** 
* Constructor
*/
  public list_element_provider() : this(gnsdk_csharp_marshalPINVOKE.new_list_element_provider(), true) {
  }

/** 
* Get list element by position
*/
  public GnListElement get_data(uint pos) {
    GnListElement ret = new GnListElement(gnsdk_csharp_marshalPINVOKE.list_element_provider_get_data(swigCPtr, pos), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Get count 
*/
  public uint count() {
    uint ret = gnsdk_csharp_marshalPINVOKE.list_element_provider_count(swigCPtr);
    return ret;
  }

}

}