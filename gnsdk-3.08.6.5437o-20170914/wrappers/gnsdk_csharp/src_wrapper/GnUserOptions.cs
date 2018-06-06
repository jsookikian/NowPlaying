
namespace GracenoteSDK {

/**
* Configuration options for GnUser
*/
public class GnUserOptions : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnUserOptions(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnUserOptions obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnUserOptions() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnUserOptions(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Constructs empty GnUserOptions object. It is not associated with any GnUser object.
*/
  public GnUserOptions() : this(gnsdk_csharp_marshalPINVOKE.new_GnUserOptions(), true) {
  }

/**
* Get lookup mode.
* @return Lookup mode
*/
  public GnLookupMode LookupMode() {
    GnLookupMode ret = (GnLookupMode)gnsdk_csharp_marshalPINVOKE.GnUserOptions_LookupMode__SWIG_0(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Set lookup mode.
* @param lookupMode	[in] Lookup mode
*/
  public void LookupMode(GnLookupMode lookupMode) {
    gnsdk_csharp_marshalPINVOKE.GnUserOptions_LookupMode__SWIG_1(swigCPtr, (int)lookupMode);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Get network proxy hostname
* @return Network proxy hostname
*/
  public string NetworkProxy() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnUserOptions_NetworkProxy__SWIG_0(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Sets host name, username and password for proxy to route GNSDK queries through
* @param hostname	[in] Fully qualified host name with optional port number. If no port number
*                  is given, the default port number is assumed to be 80.
*                  Example values are "http://proxy.mycompany.com:8080/", "proxy.mycompany.com:8080" and
*                  "proxy.mycompany.com"
* @param username  [in] Valid user name for the proxy server. Do not set this option if a username is not required.
* @param password  [in] Valid password for the proxy server. Do not set this option if a password is not required.
*/
  public void NetworkProxy(string hostname, string username, string password) {
    gnsdk_csharp_marshalPINVOKE.GnUserOptions_NetworkProxy__SWIG_1(swigCPtr, hostname, username, password);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Gets the network time-out for all GNSDK queries
* @return Netwrk timeout
*/
  public uint NetworkTimeout() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnUserOptions_NetworkTimeout__SWIG_0(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Sets the network time-out for all GNSDK queries in milliseconds.
* This option's value is a string containing a numeric value for network time-outs in milliseconds
* For example, for a 30-second time-out, set this to 30000.
* @param timeout_ms	[in] Time-out in milliseconds
*/
  public void NetworkTimeout(uint timeout_ms) {
    gnsdk_csharp_marshalPINVOKE.GnUserOptions_NetworkTimeout__SWIG_1(swigCPtr, timeout_ms);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Get network local balance state
* @return Network load balance state
*/
  public bool NetworkLoadBalance() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnUserOptions_NetworkLoadBalance__SWIG_0(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Enable/disable distributing queries across multiple Gracenote co-location facilities
* Enable to implement load balancing; otherwise, queries generally resolve to a single co-location.
*
* You might want to enable this if you are sending a large amount of traffic through a central
* point, e.g., a proxy. In this scenario, enabling load-balancing could help to improve performance. Talk to your
* Gracenote representative on how much traffic would justify doing this.
*
* @param bEnable  [in] True to enable load balancing, false otherwise.
* <p><b>Note:</b></p>
* Ensure that any security settings (such as a firewall) in your network infrastructure do not
* affect outbound access and prevent GNSDK from transmitting queries to various hosts with unique IP
* addresses.
*/
  public void NetworkLoadBalance(bool bEnable) {
    gnsdk_csharp_marshalPINVOKE.GnUserOptions_NetworkLoadBalance__SWIG_1(swigCPtr, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
*  @param intfName [in] Local IP address or system name for the desired network interface
*/
  public void NetworkInterface(string intfName) {
    gnsdk_csharp_marshalPINVOKE.GnUserOptions_NetworkInterface__SWIG_0(swigCPtr, intfName);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* If one has been set, returns the network interface being used with this object's connections.
* Returns an empty string if no specific network interface has been set.
*/
  public string NetworkInterface() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnUserOptions_NetworkInterface__SWIG_1(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Set information about this user
* @param location_id	[in] Set an IP address or country code to represent the location of user performing requests.
*                      Value for this parameter is a string with the IP address, or a 3-character country code
*                      for the client making the request. This is generally required when setting a proxy for
*                      GNSDK queries. Example values are "192.168.1.1", "usa" and "jpn".
* @param mfg			[in] The manufacturer of the device running the SDK. Used mostly by Gracenote Service to collect
*                      runtime statistics.
* @param os			[in] The OS version of the device running the SDK. Used mostly by Gracenote Service to collect
*                      runtime statistics.
* @param uid			[in] Unique ID of the device running the SDK, such as ESN. Used mostly by Gracenote Service to
*                      collect runtime statistics.
*/
  public void UserInfo(string location_id, string mfg, string os, string uid) {
    gnsdk_csharp_marshalPINVOKE.GnUserOptions_UserInfo(swigCPtr, location_id, mfg, os, uid);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Set a developer/SDK specific user ID
* @param devUserId	[in] Set a developer specific user ID from the app using this SDK. This is used to
*                       collect runtime statistics.
*/
  public void DeveloperUserID(string devUserId) {
    gnsdk_csharp_marshalPINVOKE.GnUserOptions_DeveloperUserID(swigCPtr, devUserId);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Set the advertising ID for this device
* @param adId		[in] Set an advertising ID for this device
* @param optOut	[in] Boolean indicating if the user has opted in or out of of using
*                       the advertising ID.
*/
  public void AdID(string adId, bool optOut) {
    gnsdk_csharp_marshalPINVOKE.GnUserOptions_AdID(swigCPtr, adId, optOut);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Sets the Device model
* Used for runtime statistics
* @param model of the device
*/
  public void DeviceModel(string model) {
    gnsdk_csharp_marshalPINVOKE.GnUserOptions_DeviceModel__SWIG_0(swigCPtr, model);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Gets the Device model
* @return Device model
*/
  public string DeviceModel() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnUserOptions_DeviceModel__SWIG_1(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Gets cache expiration time in seconds
* @return Cache expiration time
*/
  public uint CacheExpiration() {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnUserOptions_CacheExpiration__SWIG_0(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Sets the maximum duration for which an item in the GNSDK query cache is valid. This duration is in
* seconds, and must exceed one day.
* The value set for this option is a string with a numeric value that indicates the number of
* seconds to set for the expiration of cached queries. The maximum duration is set by Gracenote and
* varies by requirements.
* @param durationSec		[in] Expiration duration in seconds. For example, for a one day expiration
* 							set an option value of "86400" (60 seconds * 60 minutes * 24 hours); for a
* 							seven day expiration set an option value of "604800"
* 							(60 seconds * 60 minutes * 24 hours * 7 days).
* <p><b>Note:</b></p>
* Setting this option to a zero value (0) causes the cache to start deleting records upon cache
* hit, and not write new or updated records to the cache; in short, the cache effectively flushes
* itself. The cache will start caching records again once this option is set to a value greater than
* 0. Setting this option to a value less than 0 (for example: -1) causes the cache to use default
* expiration values.
*
* For mobile platforms Android, iOS and Windows Mobile the default cache expiration is zero.
*
* Cache expiration only has an effect if the application initializes a GNSDK storage provider such as
* GnStorageSqlite. Without a storage provider no cache can be created.
*
*/
  public void CacheExpiration(uint durationSec) {
    gnsdk_csharp_marshalPINVOKE.GnUserOptions_CacheExpiration__SWIG_1(swigCPtr, durationSec);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Gets user option
* @param key	[in] Option key
* @return Option value
*/
  public string Custom(string key) {
    string ret = gnsdk_csharp_marshalPINVOKE.GnUserOptions_Custom__SWIG_0(swigCPtr, key);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Sets User option
* @param key	[in] Option key
* @param value	[in] Option value
*/
  public void Custom(string key, string value) {
    gnsdk_csharp_marshalPINVOKE.GnUserOptions_Custom__SWIG_1(swigCPtr, key, value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
