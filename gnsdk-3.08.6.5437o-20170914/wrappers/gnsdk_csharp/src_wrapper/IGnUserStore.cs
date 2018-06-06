
namespace GracenoteSDK {

/**
* Delegate interface for providing persistent serialized Gracenote user object storage and retrieval
*/
public class IGnUserStore : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal IGnUserStore(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(IGnUserStore obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~IGnUserStore() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_IGnUserStore(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public virtual GnString LoadSerializedUser(string clientId) {
    GnString ret = new GnString(gnsdk_csharp_marshalPINVOKE.IGnUserStore_LoadSerializedUser(swigCPtr, clientId), true);
    return ret;
  }

  public virtual bool StoreSerializedUser(string clientId, string userData) {
    bool ret = gnsdk_csharp_marshalPINVOKE.IGnUserStore_StoreSerializedUser(swigCPtr, clientId, userData);
    return ret;
  }

  public IGnUserStore() : this(gnsdk_csharp_marshalPINVOKE.new_IGnUserStore(), true) {
    SwigDirectorConnect();
  }

  private void SwigDirectorConnect() {
    if (SwigDerivedClassHasMethod("LoadSerializedUser", swigMethodTypes0))
      swigDelegate0 = new SwigDelegateIGnUserStore_0(SwigDirectorLoadSerializedUser);
    if (SwigDerivedClassHasMethod("StoreSerializedUser", swigMethodTypes1))
      swigDelegate1 = new SwigDelegateIGnUserStore_1(SwigDirectorStoreSerializedUser);
    gnsdk_csharp_marshalPINVOKE.IGnUserStore_director_connect(swigCPtr, swigDelegate0, swigDelegate1);
  }

  private bool SwigDerivedClassHasMethod(string methodName, global::System.Type[] methodTypes) {
    global::System.Reflection.MethodInfo methodInfo = this.GetType().GetMethod(methodName, global::System.Reflection.BindingFlags.Public | global::System.Reflection.BindingFlags.NonPublic | global::System.Reflection.BindingFlags.Instance, null, methodTypes, null);
    bool hasDerivedMethod = methodInfo.DeclaringType.IsSubclassOf(typeof(IGnUserStore));
    return hasDerivedMethod;
  }

  private global::System.IntPtr SwigDirectorLoadSerializedUser(string clientId) {
    return GnString.getCPtr(LoadSerializedUser(clientId)).Handle;
  }

  private bool SwigDirectorStoreSerializedUser(string clientId, string userData) {
    return StoreSerializedUser(clientId, userData);
  }

  public delegate global::System.IntPtr SwigDelegateIGnUserStore_0(string clientId);
  public delegate bool SwigDelegateIGnUserStore_1(string clientId, string userData);

  private SwigDelegateIGnUserStore_0 swigDelegate0;
  private SwigDelegateIGnUserStore_1 swigDelegate1;

  private static global::System.Type[] swigMethodTypes0 = new global::System.Type[] { typeof(string) };
  private static global::System.Type[] swigMethodTypes1 = new global::System.Type[] { typeof(string), typeof(string) };
}

}
