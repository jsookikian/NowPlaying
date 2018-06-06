
namespace GracenoteSDK {

public class GnLookupDatabaseInfo : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnLookupDatabaseInfo(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnLookupDatabaseInfo_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnLookupDatabaseInfo obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnLookupDatabaseInfo() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnLookupDatabaseInfo(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public GnLookupDatabaseInfo() : this(gnsdk_csharp_marshalPINVOKE.new_GnLookupDatabaseInfo(), true) {
  }

}

}
