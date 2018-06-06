/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnDataMatchProvider {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnDataMatchProvider(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnDataMatchProvider obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnDataMatchProvider(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnDataMatchProvider(GnDataObject obj, String key) {
    this(gnsdk_javaJNI.new_GnDataMatchProvider(GnDataObject.getCPtr(obj), obj, key), true);
  }

  public GnDataMatch getData(long pos) {
    return new GnDataMatch(gnsdk_javaJNI.GnDataMatchProvider_getData(swigCPtr, this, pos), true);
  }

  public long count() {
    return gnsdk_javaJNI.GnDataMatchProvider_count(swigCPtr, this);
  }

}