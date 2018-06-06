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

public class GnMoodgridPresentationDataEnumerator : System.Collections.Generic.IEnumerator<GnMoodgridDataPoint> {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMoodgridPresentationDataEnumerator(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMoodgridPresentationDataEnumerator obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMoodgridPresentationDataEnumerator() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMoodgridPresentationDataEnumerator(swigCPtr);
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

	public GnMoodgridDataPoint Current {
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

  public GnMoodgridDataPoint __ref__() {
    GnMoodgridDataPoint ret = new GnMoodgridDataPoint(gnsdk_csharp_marshalPINVOKE.GnMoodgridPresentationDataEnumerator___ref__(swigCPtr), false);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnMoodgridDataPoint next() {
    GnMoodgridDataPoint ret = new GnMoodgridDataPoint(gnsdk_csharp_marshalPINVOKE.GnMoodgridPresentationDataEnumerator_next(swigCPtr), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool hasNext() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnMoodgridPresentationDataEnumerator_hasNext(swigCPtr);
    return ret;
  }

  public uint distance(GnMoodgridPresentationDataEnumerator itr) {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnMoodgridPresentationDataEnumerator_distance(swigCPtr, GnMoodgridPresentationDataEnumerator.getCPtr(itr));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnMoodgridPresentationDataEnumerator(presentation_data_provider provider, uint pos) : this(gnsdk_csharp_marshalPINVOKE.new_GnMoodgridPresentationDataEnumerator(presentation_data_provider.getCPtr(provider), pos), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

}

}