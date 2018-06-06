
namespace GracenoteSDK {

/**
* GnUser
* To make queries, every application is required to instantiate a GnUser object for each app user.
*
* <p><b>SDK Documentation</b></p>
*
* <b>Topic:</b>  Implementing Applications (All Platforms) > Setup and Initialization
*
* For more information on basic setup, see the above topic, which covers the following:
*    <ul>
*        <li>Authorizing a GNSDK application</li>
*        <li>Including header files</li>
*        <li>Instantiating a GNSDK Manager object</li>
*        <li>Instantiating a User object</li>
*    </ul>
*
*/
public class GnUser : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnUser(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnUser obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnUser() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnUser(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Reconstitutes user from serialized user handle data.
* Use this constructor to reconstitute a previously serialized GnUser. Reconstitution does not
* count towards the user count for your client in Gracenote Service.
* User's registered via Gracenote's Web API can also be used, this prevents an application
* that uses both GNSDK and Web API from having to register two users. To use a user from
* Web API construct it according to the following format and provide:
* 		<clientid>-<clienttag>:<userid>-<usertag>
* @param serializedUser		[in] String of serialized user handle data
* @param clientIdTest			[in_opt] Serialized user's expected Client ID
*/
  public GnUser(string serializedUser, string clientIdTest) : this(gnsdk_csharp_marshalPINVOKE.new_GnUser__SWIG_0(serializedUser, clientIdTest), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnUser(string serializedUser) : this(gnsdk_csharp_marshalPINVOKE.new_GnUser__SWIG_1(serializedUser), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* @deprecated
* This will be removed in a future release
* This constructor may not be safe if the lifetime of the userStore is not carefully managed
*/
  public GnUser(IGnUserStore userStore, string clientId, string clientTag, string appVersion) : this(gnsdk_csharp_marshalPINVOKE.new_GnUser__SWIG_2(IGnUserStore.getCPtr(userStore), clientId, clientTag, appVersion), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Create a GnUser with the provided Client ID and Client Tag. Check user storage for an
* existing user and if found reconstitutes the user. Reconstitution does not
* count towards the user count for your client in Gracenote Service. If not found in
* user storage a new user is created.
* @param clientId		[in] Client Identifer
* @param clientTag		[in] Client Tag
* @param appVersion	[in] Application version
* @param userStore		[in] User store delegate
*/
  public GnUser(string clientId, string clientTag, string appVersion, IGnUserStore userStore) : this(gnsdk_csharp_marshalPINVOKE.new_GnUser__SWIG_3(clientId, clientTag, appVersion, IGnUserStore.getCPtr(userStore)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Gets flag indicating if the current user is only registered for local queries
* @return True if local only user, false otherwise
*/
  public bool IsLocalOnly() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnUser_IsLocalOnly(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Receive user options object. Use to set user options.
* @return User options object
*/
  public GnUserOptions Options() {
    GnUserOptions ret = new GnUserOptions(gnsdk_csharp_marshalPINVOKE.GnUser_Options(swigCPtr), false);
    return ret;
  }

}

}
