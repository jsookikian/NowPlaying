
namespace GracenoteSDK {

/**
* Delegate interface for receiving GnMusicIdStream events
*/
public class GnMusicIdStreamEventsDelegate : GnStatusEventsDelegate {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnMusicIdStreamEventsDelegate(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamEventsDelegate_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMusicIdStreamEventsDelegate obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMusicIdStreamEventsDelegate() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMusicIdStreamEventsDelegate(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

/**
* MusicIdStreamProcessingStatusEvent is currently considered to be experimental.
* An application should only use this option if it is advised by Gracenote representative.
* Contact your Gracenote representative with any questions about this enhanced functionality.
* @param status		Status
* @param canceller		Cancellable that can be used to cancel this processing operation
*/
  public virtual void MusicIdStreamProcessingStatusEvent(GnMusicIdStreamProcessingStatus status, IGnCancellable canceller) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamEventsDelegate_MusicIdStreamProcessingStatusEvent(swigCPtr, (int)status, IGnCancellable.getCPtr(canceller));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Provides GnMusicIdStream identifying status notification
* @param status		Status
* @param canceller		Cancellable that can be used to cancel this identification operation
*/
  public virtual void MusicIdStreamIdentifyingStatusEvent(GnMusicIdStreamIdentifyingStatus status, IGnCancellable canceller) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamEventsDelegate_MusicIdStreamIdentifyingStatusEvent(swigCPtr, (int)status, IGnCancellable.getCPtr(canceller));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* A result is available for a GnMusicIdStream identification request
* @param result		Result
* @param canceller		Cancellable that can be used to cancel this identification operation
*/
  public virtual void MusicIdStreamAlbumResult(GnResponseAlbums result, IGnCancellable canceller) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamEventsDelegate_MusicIdStreamAlbumResult(swigCPtr, GnResponseAlbums.getCPtr(result), IGnCancellable.getCPtr(canceller));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Identifying request could not be completed due to the reported error condition
* @param completeError	Error condition information
*/
  public virtual void MusicIdStreamIdentifyCompletedWithError(GnError completeError) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamEventsDelegate_MusicIdStreamIdentifyCompletedWithError(swigCPtr, GnError.getCPtr(completeError));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnMusicIdStreamEventsDelegate() : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdStreamEventsDelegate(), true) {
    SwigDirectorConnect();
  }

  private void SwigDirectorConnect() {
    if (SwigDerivedClassHasMethod("StatusEvent", swigMethodTypes0))
      swigDelegate0 = new SwigDelegateGnMusicIdStreamEventsDelegate_0(SwigDirectorStatusEvent);
    if (SwigDerivedClassHasMethod("MusicIdStreamProcessingStatusEvent", swigMethodTypes1))
      swigDelegate1 = new SwigDelegateGnMusicIdStreamEventsDelegate_1(SwigDirectorMusicIdStreamProcessingStatusEvent);
    if (SwigDerivedClassHasMethod("MusicIdStreamIdentifyingStatusEvent", swigMethodTypes2))
      swigDelegate2 = new SwigDelegateGnMusicIdStreamEventsDelegate_2(SwigDirectorMusicIdStreamIdentifyingStatusEvent);
    if (SwigDerivedClassHasMethod("MusicIdStreamAlbumResult", swigMethodTypes3))
      swigDelegate3 = new SwigDelegateGnMusicIdStreamEventsDelegate_3(SwigDirectorMusicIdStreamAlbumResult);
    if (SwigDerivedClassHasMethod("MusicIdStreamIdentifyCompletedWithError", swigMethodTypes4))
      swigDelegate4 = new SwigDelegateGnMusicIdStreamEventsDelegate_4(SwigDirectorMusicIdStreamIdentifyCompletedWithError);
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamEventsDelegate_director_connect(swigCPtr, swigDelegate0, swigDelegate1, swigDelegate2, swigDelegate3, swigDelegate4);
  }

  private bool SwigDerivedClassHasMethod(string methodName, global::System.Type[] methodTypes) {
    global::System.Reflection.MethodInfo methodInfo = this.GetType().GetMethod(methodName, global::System.Reflection.BindingFlags.Public | global::System.Reflection.BindingFlags.NonPublic | global::System.Reflection.BindingFlags.Instance, null, methodTypes, null);
    bool hasDerivedMethod = methodInfo.DeclaringType.IsSubclassOf(typeof(GnMusicIdStreamEventsDelegate));
    return hasDerivedMethod;
  }

  private void SwigDirectorStatusEvent(int status, uint percentComplete, uint bytesTotalSent, uint bytesTotalReceived, global::System.IntPtr canceller) {
    StatusEvent((GnStatus)status, percentComplete, bytesTotalSent, bytesTotalReceived, new IGnCancellable(canceller, false));
  }

  private void SwigDirectorMusicIdStreamProcessingStatusEvent(int status, global::System.IntPtr canceller) {
    MusicIdStreamProcessingStatusEvent((GnMusicIdStreamProcessingStatus)status, new IGnCancellable(canceller, false));
  }

  private void SwigDirectorMusicIdStreamIdentifyingStatusEvent(int status, global::System.IntPtr canceller) {
    MusicIdStreamIdentifyingStatusEvent((GnMusicIdStreamIdentifyingStatus)status, new IGnCancellable(canceller, false));
  }

  private void SwigDirectorMusicIdStreamAlbumResult(global::System.IntPtr result, global::System.IntPtr canceller) {
    MusicIdStreamAlbumResult(new GnResponseAlbums(result, false), new IGnCancellable(canceller, false));
  }

  private void SwigDirectorMusicIdStreamIdentifyCompletedWithError(global::System.IntPtr completeError) {
    MusicIdStreamIdentifyCompletedWithError(new GnError(completeError, false));
  }

  public delegate void SwigDelegateGnMusicIdStreamEventsDelegate_0(int status, uint percentComplete, uint bytesTotalSent, uint bytesTotalReceived, global::System.IntPtr canceller);
  public delegate void SwigDelegateGnMusicIdStreamEventsDelegate_1(int status, global::System.IntPtr canceller);
  public delegate void SwigDelegateGnMusicIdStreamEventsDelegate_2(int status, global::System.IntPtr canceller);
  public delegate void SwigDelegateGnMusicIdStreamEventsDelegate_3(global::System.IntPtr result, global::System.IntPtr canceller);
  public delegate void SwigDelegateGnMusicIdStreamEventsDelegate_4(global::System.IntPtr completeError);

  private SwigDelegateGnMusicIdStreamEventsDelegate_0 swigDelegate0;
  private SwigDelegateGnMusicIdStreamEventsDelegate_1 swigDelegate1;
  private SwigDelegateGnMusicIdStreamEventsDelegate_2 swigDelegate2;
  private SwigDelegateGnMusicIdStreamEventsDelegate_3 swigDelegate3;
  private SwigDelegateGnMusicIdStreamEventsDelegate_4 swigDelegate4;

  private static global::System.Type[] swigMethodTypes0 = new global::System.Type[] { typeof(GnStatus), typeof(uint), typeof(uint), typeof(uint), typeof(IGnCancellable) };
  private static global::System.Type[] swigMethodTypes1 = new global::System.Type[] { typeof(GnMusicIdStreamProcessingStatus), typeof(IGnCancellable) };
  private static global::System.Type[] swigMethodTypes2 = new global::System.Type[] { typeof(GnMusicIdStreamIdentifyingStatus), typeof(IGnCancellable) };
  private static global::System.Type[] swigMethodTypes3 = new global::System.Type[] { typeof(GnResponseAlbums), typeof(IGnCancellable) };
  private static global::System.Type[] swigMethodTypes4 = new global::System.Type[] { typeof(GnError) };
}

}
