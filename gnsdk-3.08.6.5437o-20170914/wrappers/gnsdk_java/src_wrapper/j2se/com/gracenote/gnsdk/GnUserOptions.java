
package com.gracenote.gnsdk;

/** 
* Configuration options for {@link GnUser} 
*/ 
 
public class GnUserOptions {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnUserOptions(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnUserOptions obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnUserOptions(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

/** 
* Constructs empty {@link GnUserOptions} object. It is not associated with any {@link GnUser} object. 
*/ 
 
  public GnUserOptions() {
    this(gnsdk_javaJNI.new_GnUserOptions(), true);
  }

/** 
* Get lookup mode. 
* @return Lookup mode 
*/ 
 
  public GnLookupMode lookupMode() throws com.gracenote.gnsdk.GnException {
    return GnLookupMode.swigToEnum(gnsdk_javaJNI.GnUserOptions_lookupMode__SWIG_0(swigCPtr, this));
  }

/** 
* Set lookup mode. 
* @param lookupMode	[in] Lookup mode 
*/ 
 
  public void lookupMode(GnLookupMode lookupMode) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnUserOptions_lookupMode__SWIG_1(swigCPtr, this, lookupMode.swigValue());
  }

/** 
* Get network proxy hostname 
* @return Network proxy hostname 
*/ 
 
  public String networkProxy() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnUserOptions_networkProxy__SWIG_0(swigCPtr, this);
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
 
  public void networkProxy(String hostname, String username, String password) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnUserOptions_networkProxy__SWIG_1(swigCPtr, this, hostname, username, password);
  }

/** 
* Gets the network time-out for all GNSDK queries 
* @return Netwrk timeout 
*/ 
 
  public long networkTimeout() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnUserOptions_networkTimeout__SWIG_0(swigCPtr, this);
  }

/** 
* Sets the network time-out for all GNSDK queries in milliseconds. 
* This option's value is a string containing a numeric value for network time-outs in milliseconds 
* For example, for a 30-second time-out, set this to 30000. 
* @param timeout_ms	[in] Time-out in milliseconds 
*/ 
 
  public void networkTimeout(long timeout_ms) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnUserOptions_networkTimeout__SWIG_1(swigCPtr, this, timeout_ms);
  }

/** 
* Get network local balance state 
* @return Network load balance state 
*/ 
 
  public boolean networkLoadBalance() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnUserOptions_networkLoadBalance__SWIG_0(swigCPtr, this);
  }

/** 
* Enable/disable distributing queries across multiple Gracenote co-location facilities 
* Enable to implement load balancing; otherwise, queries generally resolve to a single co-location. 
* <p> 
* You might want to enable this if you are sending a large amount of traffic through a central 
* point, e.g., a proxy. In this scenario, enabling load-balancing could help to improve performance. Talk to your 
* Gracenote representative on how much traffic would justify doing this. 
* <p> 
* @param bEnable  [in] True to enable load balancing, false otherwise. 
* <p><b>Note:</b></p> 
* Ensure that any security settings (such as a firewall) in your network infrastructure do not 
* affect outbound access and prevent GNSDK from transmitting queries to various hosts with unique IP 
* addresses. 
*/ 
 
  public void networkLoadBalance(boolean bEnable) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnUserOptions_networkLoadBalance__SWIG_1(swigCPtr, this, bEnable);
  }

/** 
* Set a specific network interface to use with this object's connections. This can be useful for 
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use. 
*  @param intfName [in] Local IP address or system name for the desired network interface 
*/ 
 
  public void networkInterface(String intfName) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnUserOptions_networkInterface__SWIG_0(swigCPtr, this, intfName);
  }

/** 
* If one has been set, returns the network interface being used with this object's connections. 
* Returns an empty string if no specific network interface has been set. 
*/ 
 
  public String networkInterface() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnUserOptions_networkInterface__SWIG_1(swigCPtr, this);
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
 
  public void userInfo(String location_id, String mfg, String os, String uid) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnUserOptions_userInfo(swigCPtr, this, location_id, mfg, os, uid);
  }

/** 
* Set a developer/SDK specific user ID 
* @param devUserId	[in] Set a developer specific user ID from the app using this SDK. This is used to 
*                       collect runtime statistics. 
*/ 
 
  public void developerUserID(String devUserId) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnUserOptions_developerUserID(swigCPtr, this, devUserId);
  }

/** 
* Set the advertising ID for this device 
* @param adId		[in] Set an advertising ID for this device 
* @param optOut	[in] Boolean indicating if the user has opted in or out of of using 
*                       the advertising ID. 
*/ 
 
  public void adID(String adId, boolean optOut) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnUserOptions_adID(swigCPtr, this, adId, optOut);
  }

/** 
* Sets the Device model 
* Used for runtime statistics 
* @param model of the device 
*/ 
 
  public void deviceModel(String model) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnUserOptions_deviceModel__SWIG_0(swigCPtr, this, model);
  }

/** 
* Gets the Device model 
* @return Device model 
*/ 
 
  public String deviceModel() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnUserOptions_deviceModel__SWIG_1(swigCPtr, this);
  }

/** 
* Gets cache expiration time in seconds 
* @return Cache expiration time 
*/ 
 
  public long cacheExpiration() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnUserOptions_cacheExpiration__SWIG_0(swigCPtr, this);
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
* <p> 
* For mobile platforms Android, iOS and Windows Mobile the default cache expiration is zero. 
* <p> 
* Cache expiration only has an effect if the application initializes a GNSDK storage provider such as 
* {@link GnStorageSqlite}. Without a storage provider no cache can be created. 
* <p> 
*/ 
 
  public void cacheExpiration(long durationSec) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnUserOptions_cacheExpiration__SWIG_1(swigCPtr, this, durationSec);
  }

/** 
* Gets user option 
* @param key	[in] Option key 
* @return Option value 
*/ 
 
  public String custom(String key) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnUserOptions_custom__SWIG_0(swigCPtr, this, key);
  }

/** 
* Sets User option 
* @param key	[in] Option key 
* @param value	[in] Option value 
*/ 
 
  public void custom(String key, String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnUserOptions_custom__SWIG_1(swigCPtr, this, key, value);
  }

}
