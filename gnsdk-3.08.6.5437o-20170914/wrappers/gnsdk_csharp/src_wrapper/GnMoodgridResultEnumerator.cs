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

public class GnMoodgridResultEnumerator : System.Collections.Generic.IEnumerator<GnMoodgridIdentifier> {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMoodgridResultEnumerator(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMoodgridResultEnumerator obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMoodgridResultEnumerator() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMoodgridResultEnumerator(swigCPtr);
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

	public GnMoodgridIdentifier Current {
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

  public GnMoodgridIdentifier __ref__() {
    GnMoodgridIdentifier ret = new GnMoodgridIdentifier(gnsdk_csharp_marshalPINVOKE.GnMoodgridResultEnumerator___ref__(swigCPtr), false);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnMoodgridIdentifier next() {
    GnMoodgridIdentifier ret = new GnMoodgridIdentifier(gnsdk_csharp_marshalPINVOKE.GnMoodgridResultEnumerator_next(swigCPtr), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool hasNext() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnMoodgridResultEnumerator_hasNext(swigCPtr);
    return ret;
  }

  public uint distance(GnMoodgridResultEnumerator itr) {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnMoodgridResultEnumerator_distance(swigCPtr, GnMoodgridResultEnumerator.getCPtr(itr));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnMoodgridResultEnumerator(moodgrid_result_provider provider, uint pos) : this(gnsdk_csharp_marshalPINVOKE.new_GnMoodgridResultEnumerator(moodgrid_result_provider.getCPtr(provider), pos), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
