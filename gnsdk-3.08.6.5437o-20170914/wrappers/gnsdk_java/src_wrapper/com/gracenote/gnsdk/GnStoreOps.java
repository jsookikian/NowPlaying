/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnStoreOps {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnStoreOps(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnStoreOps obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnStoreOps(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public void location(String location) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnStoreOps_location(swigCPtr, this, location);
  }

  public void fileSize(long size_in_kb) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnStoreOps_fileSize(swigCPtr, this, size_in_kb);
  }

  public void flush(boolean bAsync) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnStoreOps_flush(swigCPtr, this, bAsync);
  }

  public void compact(boolean bAsync) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnStoreOps_compact(swigCPtr, this, bAsync);
  }

  public void cleanup(boolean bAsync) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnStoreOps_cleanup(swigCPtr, this, bAsync);
  }

}
