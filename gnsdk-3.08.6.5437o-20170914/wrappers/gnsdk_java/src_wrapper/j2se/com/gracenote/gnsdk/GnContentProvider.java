/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnContentProvider {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnContentProvider(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnContentProvider obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnContentProvider(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnContentProvider(GnDataObject obj, String key) {
    this(gnsdk_javaJNI.new_GnContentProvider(GnDataObject.getCPtr(obj), obj, key), true);
  }

  public GnContent getData(long pos) {
    return new GnContent(gnsdk_javaJNI.GnContentProvider_getData(swigCPtr, this, pos), true);
  }

  public long count() {
    return gnsdk_javaJNI.GnContentProvider_count(swigCPtr, this);
  }

}
