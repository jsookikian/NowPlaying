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

public class GnLookupLocalStreamIngestEventsDelegate : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnLookupLocalStreamIngestEventsDelegate(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnLookupLocalStreamIngestEventsDelegate obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnLookupLocalStreamIngestEventsDelegate() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnLookupLocalStreamIngestEventsDelegate(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public virtual void StatusEvent(GnLookupLocalStreamIngestStatus status, string bundleId, IGnCancellable canceller) {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocalStreamIngestEventsDelegate_StatusEvent(swigCPtr, (int)status, bundleId, IGnCancellable.getCPtr(canceller));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnLookupLocalStreamIngestEventsDelegate() : this(gnsdk_csharp_marshalPINVOKE.new_GnLookupLocalStreamIngestEventsDelegate(), true) {
    SwigDirectorConnect();
  }

  private void SwigDirectorConnect() {
    if (SwigDerivedClassHasMethod("StatusEvent", swigMethodTypes0))
      swigDelegate0 = new SwigDelegateGnLookupLocalStreamIngestEventsDelegate_0(SwigDirectorStatusEvent);
    gnsdk_csharp_marshalPINVOKE.GnLookupLocalStreamIngestEventsDelegate_director_connect(swigCPtr, swigDelegate0);
  }

  private bool SwigDerivedClassHasMethod(string methodName, global::System.Type[] methodTypes) {
    global::System.Reflection.MethodInfo methodInfo = this.GetType().GetMethod(methodName, global::System.Reflection.BindingFlags.Public | global::System.Reflection.BindingFlags.NonPublic | global::System.Reflection.BindingFlags.Instance, null, methodTypes, null);
    bool hasDerivedMethod = methodInfo.DeclaringType.IsSubclassOf(typeof(GnLookupLocalStreamIngestEventsDelegate));
    return hasDerivedMethod;
  }

  private void SwigDirectorStatusEvent(int status, string bundleId, global::System.IntPtr canceller) {
    StatusEvent((GnLookupLocalStreamIngestStatus)status, bundleId, new IGnCancellable(canceller, false));
  }

  public delegate void SwigDelegateGnLookupLocalStreamIngestEventsDelegate_0(int status, string bundleId, global::System.IntPtr canceller);

  private SwigDelegateGnLookupLocalStreamIngestEventsDelegate_0 swigDelegate0;

  private static global::System.Type[] swigMethodTypes0 = new global::System.Type[] { typeof(GnLookupLocalStreamIngestStatus), typeof(string), typeof(IGnCancellable) };
}

}
