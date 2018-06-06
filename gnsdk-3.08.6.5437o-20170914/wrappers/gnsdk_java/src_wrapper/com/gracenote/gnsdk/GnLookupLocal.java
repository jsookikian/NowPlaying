/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

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

  public static GnLookupLocal enable() throws com.gracenote.gnsdk.GnException {
    return new GnLookupLocal(gnsdk_javaJNI.GnLookupLocal_enable(), false);
  }

  public static String version() {
    return gnsdk_javaJNI.GnLookupLocal_version();
  }

  public static String buildDate() {
    return gnsdk_javaJNI.GnLookupLocal_buildDate();
  }

  public void storageLocation(GnLocalStorageName storageName, String storageLocation) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocal_storageLocation(swigCPtr, this, storageName.swigValue(), storageLocation);
  }

  public void storageValidate(GnLocalStorageName storageName) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLookupLocal_storageValidate(swigCPtr, this, storageName.swigValue());
  }

  public String storageInfo(GnLocalStorageName storageName, GnLocalStorageInfo storageInfo, long ordinal) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLookupLocal_storageInfo(swigCPtr, this, storageName.swigValue(), storageInfo.swigValue(), ordinal);
  }

  public long storageInfoCount(GnLocalStorageName storageName, GnLocalStorageInfo storageInfo) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLookupLocal_storageInfoCount(swigCPtr, this, storageName.swigValue(), storageInfo.swigValue());
  }

}
