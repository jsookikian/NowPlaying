
package com.gracenote.gnsdk;

/** 
* {@link GnUser} 
* To make queries, every application is required to instantiate a {@link GnUser} object for each app user. 
* <p> 
* <p><b>SDK Documentation</b></p> 
* <p> 
* <b>Topic:</b>  Implementing Applications (All Platforms) > Setup and Initialization 
* <p> 
* For more information on basic setup, see the above topic, which covers the following: 
*    <ul> 
*        <li>Authorizing a GNSDK application</li> 
*        <li>Including header files</li> 
*        <li>Instantiating a GNSDK Manager object</li> 
*        <li>Instantiating a User object</li> 
*    </ul> 
* <p> 
*/ 
 
public class GnUser {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnUser(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnUser obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnUser(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  private IGnUserStore userStore;
  private IGnUserStoreProxyU userStoreProxy;

/** 
* Reconstitutes user from serialized user handle data. 
* Use this constructor to reconstitute a previously serialized {@link GnUser}. Reconstitution does not 
* count towards the user count for your client in Gracenote Service. 
* User's registered via Gracenote's Web API can also be used, this prevents an application 
* that uses both GNSDK and Web API from having to register two users. To use a user from 
* Web API construct it according to the following format and provide: 
* 		<clientid>-<clienttag>:<userid>-<usertag> 
* @param serializedUser		[in] String of serialized user handle data 
* @param clientIdTest			[in_opt] Serialized user's expected Client ID 
*/ 
 
  public GnUser(String serializedUser, String clientIdTest) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( userStore != null ) {
		userStoreProxy = new IGnUserStoreProxyU(userStore);
		this.userStore = userStore;		// <REFERENCE_NAME_CHECK><TYPE>IGnUserStore</TYPE><NAME>userStore</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	}
	
    swigCPtr = gnsdk_javaJNI.new_GnUser__SWIG_0(serializedUser, clientIdTest);
}

  public GnUser(String serializedUser) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( userStore != null ) {
		userStoreProxy = new IGnUserStoreProxyU(userStore);
		this.userStore = userStore;		// <REFERENCE_NAME_CHECK><TYPE>IGnUserStore</TYPE><NAME>userStore</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	}
	
    swigCPtr = gnsdk_javaJNI.new_GnUser__SWIG_1(serializedUser);
}

/** 
* @deprecated 
* This will be removed in a future release 
* This constructor may not be safe if the lifetime of the userStore is not carefully managed 
*/ 
 
  public GnUser(IGnUserStore userStore, String clientId, String clientTag, String appVersion) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( userStore != null ) {
		userStoreProxy = new IGnUserStoreProxyU(userStore);
		this.userStore = userStore;		// <REFERENCE_NAME_CHECK><TYPE>IGnUserStore</TYPE><NAME>userStore</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	}
	
    swigCPtr = gnsdk_javaJNI.new_GnUser__SWIG_2((userStoreProxy==null)?0:IGnUserStoreProxyL.getCPtr(userStoreProxy), userStoreProxy, clientId, clientTag, appVersion);
}

/** 
* Create a {@link GnUser} with the provided Client ID and Client Tag. Check user storage for an 
* existing user and if found reconstitutes the user. Reconstitution does not 
* count towards the user count for your client in Gracenote Service. If not found in 
* user storage a new user is created. 
* @param clientId		[in] Client Identifer 
* @param clientTag		[in] Client Tag 
* @param appVersion	[in] Application version 
* @param userStore		[in] User store delegate 
*/ 
 
  public GnUser(String clientId, String clientTag, String appVersion, IGnUserStore userStore) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( userStore != null ) {
		userStoreProxy = new IGnUserStoreProxyU(userStore);
		this.userStore = userStore;		// <REFERENCE_NAME_CHECK><TYPE>IGnUserStore</TYPE><NAME>userStore</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	}
	
    swigCPtr = gnsdk_javaJNI.new_GnUser__SWIG_3(clientId, clientTag, appVersion, (userStoreProxy==null)?0:IGnUserStoreProxyL.getCPtr(userStoreProxy), userStoreProxy);
}

/** 
* Gets flag indicating if the current user is only registered for local queries 
* @return True if local only user, false otherwise 
*/ 
 
  public boolean isLocalOnly() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnUser_isLocalOnly(swigCPtr, this);
  }

/** 
* Receive user options object. Use to set user options. 
* @return User options object 
*/ 
 
  public GnUserOptions options() {
    return new GnUserOptions(gnsdk_javaJNI.GnUser_options(swigCPtr, this), false);
  }

}
