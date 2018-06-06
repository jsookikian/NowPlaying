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

public class GnContentEnumerable : System.Collections.Generic.IEnumerable<GnContent>, System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnContentEnumerable(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnContentEnumerable obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnContentEnumerable() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnContentEnumerable(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

			System.Collections.Generic.IEnumerator<GnContent> System.Collections.Generic.IEnumerable<GnContent> .GetEnumerator( )
			{
				return GetEnumerator( );
			}
			System.Collections.IEnumerator System.Collections.IEnumerable.
			    GetEnumerator( )
			{
				return GetEnumerator( );
			}

		
  public GnContentEnumerable(GnContentProvider provider, uint start) : this(gnsdk_csharp_marshalPINVOKE.new_GnContentEnumerable(GnContentProvider.getCPtr(provider), start), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnContentEnumerator GetEnumerator() {
    GnContentEnumerator ret = new GnContentEnumerator(gnsdk_csharp_marshalPINVOKE.GnContentEnumerable_GetEnumerator(swigCPtr), true);
    return ret;
  }

  public GnContentEnumerator end() {
    GnContentEnumerator ret = new GnContentEnumerator(gnsdk_csharp_marshalPINVOKE.GnContentEnumerable_end(swigCPtr), true);
    return ret;
  }

  public uint count() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnContentEnumerable_count(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnContentEnumerator at(uint index) {
    GnContentEnumerator ret = new GnContentEnumerator(gnsdk_csharp_marshalPINVOKE.GnContentEnumerable_at(swigCPtr, index), true);
    return ret;
  }

  public GnContentEnumerator getByIndex(uint index) {
    GnContentEnumerator ret = new GnContentEnumerator(gnsdk_csharp_marshalPINVOKE.GnContentEnumerable_getByIndex(swigCPtr, index), true);
    return ret;
  }

}

}
