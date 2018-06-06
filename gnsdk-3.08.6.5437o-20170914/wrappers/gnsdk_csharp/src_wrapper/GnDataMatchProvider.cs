//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.8
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace GracenoteSDK {

public class GnDataMatchProvider : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnDataMatchProvider(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnDataMatchProvider obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnDataMatchProvider() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnDataMatchProvider(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public GnDataMatchProvider(GnDataObject obj, string key) : this(gnsdk_csharp_marshalPINVOKE.new_GnDataMatchProvider(GnDataObject.getCPtr(obj), key), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnDataMatch get_data(uint pos) {
    GnDataMatch ret = new GnDataMatch(gnsdk_csharp_marshalPINVOKE.GnDataMatchProvider_get_data(swigCPtr, pos), true);
    return ret;
  }

  public uint count() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnDataMatchProvider_count(swigCPtr);
    return ret;
  }

  public static readonly uint kOrdinalStart = gnsdk_csharp_marshalPINVOKE.GnDataMatchProvider_kOrdinalStart_get();
  public static readonly uint kCountOffset = gnsdk_csharp_marshalPINVOKE.GnDataMatchProvider_kCountOffset_get();
}

}