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

public class GnPlaylistCollectionIdentEnumerable : System.Collections.Generic.IEnumerable<GnPlaylistIdentifier>, System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnPlaylistCollectionIdentEnumerable(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnPlaylistCollectionIdentEnumerable obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnPlaylistCollectionIdentEnumerable() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnPlaylistCollectionIdentEnumerable(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

System.Collections.Generic.IEnumerator<GnPlaylistIdentifier> System.Collections.Generic.IEnumerable<GnPlaylistIdentifier>.GetEnumerator( )
{
return GetEnumerator( );
}
System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator( )
{
return GetEnumerator( );
}

  public GnPlaylistCollectionIdentEnumerable(collection_ident_provider provider, uint start) : this(gnsdk_csharp_marshalPINVOKE.new_GnPlaylistCollectionIdentEnumerable(collection_ident_provider.getCPtr(provider), start), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnPlaylistCollectionIdentEnumerator GetEnumerator() {
    GnPlaylistCollectionIdentEnumerator ret = new GnPlaylistCollectionIdentEnumerator(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollectionIdentEnumerable_GetEnumerator(swigCPtr), true);
    return ret;
  }

  public GnPlaylistCollectionIdentEnumerator end() {
    GnPlaylistCollectionIdentEnumerator ret = new GnPlaylistCollectionIdentEnumerator(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollectionIdentEnumerable_end(swigCPtr), true);
    return ret;
  }

  public uint count() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnPlaylistCollectionIdentEnumerable_count(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnPlaylistCollectionIdentEnumerator at(uint index) {
    GnPlaylistCollectionIdentEnumerator ret = new GnPlaylistCollectionIdentEnumerator(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollectionIdentEnumerable_at(swigCPtr, index), true);
    return ret;
  }

  public GnPlaylistCollectionIdentEnumerator getByIndex(uint index) {
    GnPlaylistCollectionIdentEnumerator ret = new GnPlaylistCollectionIdentEnumerator(gnsdk_csharp_marshalPINVOKE.GnPlaylistCollectionIdentEnumerable_getByIndex(swigCPtr, index), true);
    return ret;
  }

}

}
