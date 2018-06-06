
namespace GracenoteSDK {

/**
* Delegate interface for receiving status updates as GNSDK operations are performed.
*/
public class GnStatusEventsDelegate : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnStatusEventsDelegate(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnStatusEventsDelegate obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnStatusEventsDelegate() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnStatusEventsDelegate(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Status change notification method. Override to receive notification.
* @param status				[in] Status type
* @param percentComplete		[in] Operation progress
* @param bytesTotalSent		[in] Total number of bytes sent
* @param bytesTotalReceived	[in] Total number of bytes received
* @param canceller				[in] Object that can be used to canel the operation
*/
  public virtual void StatusEvent(GnStatus status, uint percentComplete, uint bytesTotalSent, uint bytesTotalReceived, IGnCancellable canceller) {
    gnsdk_csharp_marshalPINVOKE.GnStatusEventsDelegate_StatusEvent(swigCPtr, (int)status, percentComplete, bytesTotalSent, bytesTotalReceived, IGnCancellable.getCPtr(canceller));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnStatusEventsDelegate() : this(gnsdk_csharp_marshalPINVOKE.new_GnStatusEventsDelegate(), true) {
    SwigDirectorConnect();
  }

  private void SwigDirectorConnect() {
    if (SwigDerivedClassHasMethod("StatusEvent", swigMethodTypes0))
      swigDelegate0 = new SwigDelegateGnStatusEventsDelegate_0(SwigDirectorStatusEvent);
    gnsdk_csharp_marshalPINVOKE.GnStatusEventsDelegate_director_connect(swigCPtr, swigDelegate0);
  }

  private bool SwigDerivedClassHasMethod(string methodName, global::System.Type[] methodTypes) {
    global::System.Reflection.MethodInfo methodInfo = this.GetType().GetMethod(methodName, global::System.Reflection.BindingFlags.Public | global::System.Reflection.BindingFlags.NonPublic | global::System.Reflection.BindingFlags.Instance, null, methodTypes, null);
    bool hasDerivedMethod = methodInfo.DeclaringType.IsSubclassOf(typeof(GnStatusEventsDelegate));
    return hasDerivedMethod;
  }

  private void SwigDirectorStatusEvent(int status, uint percentComplete, uint bytesTotalSent, uint bytesTotalReceived, global::System.IntPtr canceller) {
    StatusEvent((GnStatus)status, percentComplete, bytesTotalSent, bytesTotalReceived, new IGnCancellable(canceller, false));
  }

  public delegate void SwigDelegateGnStatusEventsDelegate_0(int status, uint percentComplete, uint bytesTotalSent, uint bytesTotalReceived, global::System.IntPtr canceller);

  private SwigDelegateGnStatusEventsDelegate_0 swigDelegate0;

  private static global::System.Type[] swigMethodTypes0 = new global::System.Type[] { typeof(GnStatus), typeof(uint), typeof(uint), typeof(uint), typeof(IGnCancellable) };
}

}
