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

public class GnMusicIdFileInfoEnumerator : System.Collections.Generic.IEnumerator<GnMusicIdFileInfo>, System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMusicIdFileInfoEnumerator(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMusicIdFileInfoEnumerator obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMusicIdFileInfoEnumerator() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMusicIdFileInfoEnumerator(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

	public bool
	MoveNext( )
	{
		return hasNext( );
	}

	public GnMusicIdFileInfo Current {
		get {
			return next( );
		}
	}
	object System.Collections.IEnumerator.Current {
		get {
			return Current;
		}
	}
	public void
	Reset( )
	{
	}


  public GnMusicIdFileInfo __ref__() {
    GnMusicIdFileInfo ret = new GnMusicIdFileInfo(gnsdk_csharp_marshalPINVOKE.GnMusicIdFileInfoEnumerator___ref__(swigCPtr), false);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnMusicIdFileInfo next() {
    GnMusicIdFileInfo ret = new GnMusicIdFileInfo(gnsdk_csharp_marshalPINVOKE.GnMusicIdFileInfoEnumerator_next(swigCPtr), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool hasNext() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnMusicIdFileInfoEnumerator_hasNext(swigCPtr);
    return ret;
  }

  public uint distance(GnMusicIdFileInfoEnumerator itr) {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnMusicIdFileInfoEnumerator_distance(swigCPtr, GnMusicIdFileInfoEnumerator.getCPtr(itr));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnMusicIdFileInfoEnumerator(musicid_file_info_provider provider, uint pos) : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdFileInfoEnumerator(musicid_file_info_provider.getCPtr(provider), pos), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

}

}