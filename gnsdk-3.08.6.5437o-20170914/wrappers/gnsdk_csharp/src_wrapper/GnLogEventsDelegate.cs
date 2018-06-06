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

public class GnLogEventsDelegate : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnLogEventsDelegate(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnLogEventsDelegate obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnLogEventsDelegate() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnLogEventsDelegate(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public virtual bool LogMessage(ushort packageId, GnLogMessageType messageType, uint errorCode, string message) {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnLogEventsDelegate_LogMessage(swigCPtr, packageId, (int)messageType, errorCode, message);
    return ret;
  }

  public GnLogEventsDelegate() : this(gnsdk_csharp_marshalPINVOKE.new_GnLogEventsDelegate(), true) {
    SwigDirectorConnect();
  }

  private void SwigDirectorConnect() {
    if (SwigDerivedClassHasMethod("LogMessage", swigMethodTypes0))
      swigDelegate0 = new SwigDelegateGnLogEventsDelegate_0(SwigDirectorLogMessage);
    gnsdk_csharp_marshalPINVOKE.GnLogEventsDelegate_director_connect(swigCPtr, swigDelegate0);
  }

  private bool SwigDerivedClassHasMethod(string methodName, global::System.Type[] methodTypes) {
    global::System.Reflection.MethodInfo methodInfo = this.GetType().GetMethod(methodName, global::System.Reflection.BindingFlags.Public | global::System.Reflection.BindingFlags.NonPublic | global::System.Reflection.BindingFlags.Instance, null, methodTypes, null);
    bool hasDerivedMethod = methodInfo.DeclaringType.IsSubclassOf(typeof(GnLogEventsDelegate));
    return hasDerivedMethod;
  }

  private bool SwigDirectorLogMessage(ushort packageId, int messageType, uint errorCode, string message) {
    return LogMessage(packageId, (GnLogMessageType)messageType, errorCode, message);
  }

  public delegate bool SwigDelegateGnLogEventsDelegate_0(ushort packageId, int messageType, uint errorCode, string message);

  private SwigDelegateGnLogEventsDelegate_0 swigDelegate0;

  private static global::System.Type[] swigMethodTypes0 = new global::System.Type[] { typeof(ushort), typeof(GnLogMessageType), typeof(uint), typeof(string) };
}

}
