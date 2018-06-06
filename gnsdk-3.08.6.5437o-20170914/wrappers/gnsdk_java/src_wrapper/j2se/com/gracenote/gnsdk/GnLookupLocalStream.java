
package com.gracenote.gnsdk;

/** 
* <p> 
* {@link GnLookupLocalStream} is a MusicID-Stream local lookup provider, providing a local 
* database of MusicID-Stream tracks suitable for lookup via {@link GnMusicIdStream} or {@link GnMusicId}. 
* A MusicID-Stream local database can be constructed from "bundles" (raw fingerprints and metadata) that 
* Gracenote provides. 
* <p> 
* <b>SDK Documentation</b> 
* <p> 
* Topic: "Implementing Applications..." > "Using a Local Fingerprint Database" 
* <p> 
* For more information on using the {@link GnLookupLocalStream} class see the above topic which covers 
* the following: 
* <ul> 
*     <li>Using a local fingerprint database</li> 
*     <li>Downloading and ingesting bundles</li> 
*     <li>Ingesting bundles code samples</li> 
*     <li>Designating a storage provider</li> 
*     <li>Local fingerprinting options</li> 
* </ul> 
* <p> 
*/ 
 
public class GnLookupLocalStream {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnLookupLocalStream(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnLookupLocalStream obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnLookupLocalStream(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

/** 
* Enable a lookup local Stream provider. 
* @return Storage provider instance 
*/ 
 
  public static GnLookupLocalStream enable() throws com.gracenote.gnsdk.GnException {
    return new GnLookupLocalStream(gnsdk_javaJNI.GnLookupLocalStream_enable(), false);
  }

/** 
*  Retrieves a {@link GnLookupLocalStream} SDK version string. 
*  You can call this API at any time after successfully allocating a {@link GnManager} instance. The returned 
*  string is a constant. Do not attempt to modify or delete. 
*  Example: 1.2.3.123 (Major.Minor.Improvement.Build) 
*  Major: New functionality 
*  Minor: New or changed features 
*  Improvement: Improvements and fixes 
*  Build: Internal build number 
*/ 
 
  public static String version() {
    return gnsdk_javaJNI.GnLookupLocalStream_version();
  }

/** 
*  Retrieves the {@link GnLookupLocalStream} SDK's build date string. 
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC 
*  <p><b>Remarks:</b></p> 
*  You can call this API at any time after successfully allocating a {@link GnManager} instance. The returned 
*  string is a constant. Do not attempt to modify or delete. 
*  Example build date string: 2008-02-12 00:41 UTC 
*/ 
 
  public static String buildDate() {
    return gnsdk_javaJNI.GnLookupLocalStream_buildDate();
  }

/** 
*  Sets a folder location for GNSDK LookupLocalStream 
*  @param folderPath	[in] Relative path name for storage 
* <p><b>Remarks:</b></p> 
*  This API overrides the (default or explicit) folder location of GNSDK SQLite storage - for this database. 
*/ 
 
  public void storageLocation(String location) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocalStream_storageLocation(swigCPtr, this, location);
  }

/** 
*  Sets the local fingerprint lookup engine memory type 
*  @param engineType	[in] {@link GnLocalStreamEngineType} enum indicating which memory mode to use 
*/ 
 
  public void engineType(GnLocalStreamEngineType engineType) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocalStream_engineType__SWIG_0(swigCPtr, this, engineType.swigValue());
  }

  public GnLocalStreamEngineType engineType() throws com.gracenote.gnsdk.GnException {
    return GnLocalStreamEngineType.swigToEnum(gnsdk_javaJNI.GnLookupLocalStream_engineType__SWIG_1(swigCPtr, this));
  }

/** 
*  Sets the current local fingerprint lookup processing method. 
*  @param processingMethod	[in] {@link GnLocalStreamFingerprintProcessingMethod} enum indicating the local fingerprint lookup processing method. 
*/ 
 
  public void fingerprintProcessingMethod(GnLocalStreamFingerprintProcessingMethod processingMethod) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocalStream_fingerprintProcessingMethod__SWIG_0(swigCPtr, this, processingMethod.swigValue());
  }

  public GnLocalStreamFingerprintProcessingMethod fingerprintProcessingMethod() throws com.gracenote.gnsdk.GnException {
    return GnLocalStreamFingerprintProcessingMethod.swigToEnum(gnsdk_javaJNI.GnLookupLocalStream_fingerprintProcessingMethod__SWIG_1(swigCPtr, this));
  }

  public long fingerprintProcessingCPUMaxThreadCount() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLookupLocalStream_fingerprintProcessingCPUMaxThreadCount__SWIG_0(swigCPtr, this);
  }

  public void fingerprintProcessingCPUMaxThreadCount(long option_value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocalStream_fingerprintProcessingCPUMaxThreadCount__SWIG_1(swigCPtr, this, option_value);
  }

  public long fingerprintProcessingCPUMinThreadWorkSize() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLookupLocalStream_fingerprintProcessingCPUMinThreadWorkSize__SWIG_0(swigCPtr, this);
  }

  public void fingerprintProcessingCPUMinThreadWorkSize(long option_value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocalStream_fingerprintProcessingCPUMinThreadWorkSize__SWIG_1(swigCPtr, this, option_value);
  }

  public long fingerprintProcessingGPUMinWorkSize() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLookupLocalStream_fingerprintProcessingGPUMinWorkSize__SWIG_0(swigCPtr, this);
  }

  public void fingerprintProcessingGPUMinWorkSize(long option_value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocalStream_fingerprintProcessingGPUMinWorkSize__SWIG_1(swigCPtr, this, option_value);
  }

  public long fingerprintProcessingGPUMaxWorkSize() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLookupLocalStream_fingerprintProcessingGPUMaxWorkSize__SWIG_0(swigCPtr, this);
  }

  public void fingerprintProcessingGPUMaxWorkSize(long option_value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocalStream_fingerprintProcessingGPUMaxWorkSize__SWIG_1(swigCPtr, this, option_value);
  }

/** 
* Clear all tracks from the MusicID-Stream local database storage file. 
*/ 
 
  public void storageClear() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocalStream_storageClear(swigCPtr, this);
  }

/** 
* Remove a bundle item from the MusicID-Stream local database. 
* @param	bundleItemId	[in] Bundle item ID 
*/ 
 
  public void storageRemove(String bundleItemId) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocalStream_storageRemove(swigCPtr, this, bundleItemId);
  }

}
