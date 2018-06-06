
package com.gracenote.gnsdk;

/** 
* <p> 
* {@link GnLookupLocal} 
* <p> 
* Provides services for local lookup of various identification queries such as 
* text and CD TOC search and provides services for local retreival of content 
* such as cover art. 
* <p> 
* <b>SDK Documentation</b> 
* <p> 
* Topic: .../docs/html-oo > index.html > Implementing Applications (All Platforms) > Enabling and Using GNSDK Storage 
* <p> 
* For more information on GNSDK storage, see the above topic which covers: 
* <ul> 
*     <li>How to enable and manage GNSDK storage</li> 
*     <li>Enabling a provider for GNSDK storage</li> 
*     <li>Enabling storage code samples</li> 
*     <li>GNSDK stores</li> 
*     <li>GNSDK databases</li> 
*     <li>Setting GNSDK storage folder locations</li> 
*     <li>Setting a storage folder location code samples</li> 
*     <li>Storing query results in local storage</li> 
*     <li>Storing query results in local storage code samples</li> 
*     <li>Getting local lookup database information</li> 
*     <li>Setting online cache expiration</li> 
*     <li>Managing online cache size and memory</li> 
* </ul> 
* <p> 
* <b>Sample App</b> 
* <p> 
*     - .../samples/musicid_lookup_album_local_online 
*/ 
 
public class GnLookupLocal {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnLookupLocal(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnLookupLocal obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnLookupLocal(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

/** 
* Enable local lookup for various identification queries such as 
* text and CD TOC search; plus enable services for local retreival of 
* content such as cover art. 
* 
*/ 
 
  public static GnLookupLocal enable() throws com.gracenote.gnsdk.GnException {
    return new GnLookupLocal(gnsdk_javaJNI.GnLookupLocal_enable(), false);
  }

/** 
*  Version 
*  Retrieves the Lookup Local SDK version string. 
*  @return version string if successful 
*  @return GNSDK_NULL if not successful 
*  <p><b>Remarks:</b></p> 
*  You can call this API at any time after you have instantiated a {@link GnManager} instance. The returned 
*  string is a constant. Do not attempt to modify or delete. 
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build) 
*  Major: New functionality 
*  Minor: New or changed features 
*  Improvement: Improvements and fixes 
*  Build: Internal build number 
*/ 
 
  public static String version() {
    return gnsdk_javaJNI.GnLookupLocal_version();
  }

/** 
*  BuildDate 
*  Retrieves the Lookup Local SDK's build date string. 
*  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC 
*  <p><b>Remarks:</b></p> 
*  You can call this API at any time after you have instantiated a {@link GnManager} instance. The returned 
*   string is a constant. Do not attempt to modify or delete. 
*  Example build date string: 2008-02-12 00:41 UTC 
*/ 
 
  public static String buildDate() {
    return gnsdk_javaJNI.GnLookupLocal_buildDate();
  }

/** 
*  Sets location where GNSDK can find a specific local lookup database 
*	@param storageName 		[in] local storage name 
*	@param storageLocation 	[in] local storage location 
*/ 
 
  public void storageLocation(GnLocalStorageName storageName, String storageLocation) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocal_storageLocation(swigCPtr, this, storageName.swigValue(), storageLocation);
  }

/** 
*  Validate named local storage. 
*	@param storageName [in] local storage name 
*/ 
 
  public void storageValidate(GnLocalStorageName storageName) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocal_storageValidate(swigCPtr, this, storageName.swigValue());
  }

/** 
*  Retrieves the Local Storage information for named storage 
*  @param storageName 		[in] local storage name 
*  @param storageInfo 		[in] local storage info type 
*  @param ordinal 			[in] ordinal 
*  @return info string if successful, GNSDK_NULL if not successful 
*/ 
 
  public String storageInfo(GnLocalStorageName storageName, GnLocalStorageInfo storageInfo, long ordinal) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLookupLocal_storageInfo(swigCPtr, this, storageName.swigValue(), storageInfo.swigValue(), ordinal);
  }

/** 
*  Retrieves the Local Storage information count for named storage 
*  @param storageName 		[in] local storage name 
*  @param storageInfo 		[in] local storage info type 
*  @return count if successful, 0 if not successful 
*/ 
 
  public long storageInfoCount(GnLocalStorageName storageName, GnLocalStorageInfo storageInfo) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLookupLocal_storageInfoCount(swigCPtr, this, storageName.swigValue(), storageInfo.swigValue());
  }

}
