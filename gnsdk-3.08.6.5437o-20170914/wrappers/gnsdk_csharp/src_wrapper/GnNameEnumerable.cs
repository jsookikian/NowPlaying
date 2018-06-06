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

public class GnNameEnumerable : System.Collections.Generic.IEnumerable<GnName>, System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnNameEnumerable(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnNameEnumerable obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnNameEnumerable() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnNameEnumerable(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

			System.Collections.Generic.IEnumerator<GnName> System.Collections.Generic.IEnumerable<GnName> .GetEnumerator( )
			{
				return GetEnumerator( );
			}
			System.Collections.IEnumerator System.Collections.IEnumerable.
			    GetEnumerator( )
			{
				return GetEnumerator( );
			}

		
  public GnNameEnumerable(GnNameProvider provider, uint start) : this(gnsdk_csharp_marshalPINVOKE.new_GnNameEnumerable(GnNameProvider.getCPtr(provider), start), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnNameEnumerator GetEnumerator() {
    GnNameEnumerator ret = new GnNameEnumerator(gnsdk_csharp_marshalPINVOKE.GnNameEnumerable_GetEnumerator(swigCPtr), true);
    return ret;
  }

  public GnNameEnumerator end() {
    GnNameEnumerator ret = new GnNameEnumerator(gnsdk_csharp_marshalPINVOKE.GnNameEnumerable_end(swigCPtr), true);
    return ret;
  }

  public uint count() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnNameEnumerable_count(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnNameEnumerator at(uint index) {
    GnNameEnumerator ret = new GnNameEnumerator(gnsdk_csharp_marshalPINVOKE.GnNameEnumerable_at(swigCPtr, index), true);
    return ret;
  }

  public GnNameEnumerator getByIndex(uint index) {
    GnNameEnumerator ret = new GnNameEnumerator(gnsdk_csharp_marshalPINVOKE.GnNameEnumerable_getByIndex(swigCPtr, index), true);
    return ret;
  }

}

}