
namespace GracenoteSDK {

public class collection_ident_provider : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal collection_ident_provider(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(collection_ident_provider obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~collection_ident_provider() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_collection_ident_provider(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public collection_ident_provider() : this(gnsdk_csharp_marshalPINVOKE.new_collection_ident_provider(), true) {
  }

  public GnPlaylistIdentifier get_data(uint pos) {
    GnPlaylistIdentifier ret = new GnPlaylistIdentifier(gnsdk_csharp_marshalPINVOKE.collection_ident_provider_get_data(swigCPtr, pos), true);
    return ret;
  }

  public uint count() {
    uint ret = gnsdk_csharp_marshalPINVOKE.collection_ident_provider_count(swigCPtr);
    return ret;
  }

}

}
