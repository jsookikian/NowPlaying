/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnLogColumns {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnLogColumns(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnLogColumns obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnLogColumns(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnLogColumns() {
    this(gnsdk_javaJNI.new_GnLogColumns(), true);
  }

  public void none() {
    gnsdk_javaJNI.GnLogColumns_none(swigCPtr, this);
  }

  public GnLogColumns timeStamp() {
    return new GnLogColumns(gnsdk_javaJNI.GnLogColumns_timeStamp(swigCPtr, this), false);
  }

  public GnLogColumns category() {
    return new GnLogColumns(gnsdk_javaJNI.GnLogColumns_category(swigCPtr, this), false);
  }

  public GnLogColumns packageName() {
    return new GnLogColumns(gnsdk_javaJNI.GnLogColumns_packageName(swigCPtr, this), false);
  }

  public GnLogColumns thread() {
    return new GnLogColumns(gnsdk_javaJNI.GnLogColumns_thread(swigCPtr, this), false);
  }

  public GnLogColumns sourceInfo() {
    return new GnLogColumns(gnsdk_javaJNI.GnLogColumns_sourceInfo(swigCPtr, this), false);
  }

  public GnLogColumns newLine() {
    return new GnLogColumns(gnsdk_javaJNI.GnLogColumns_newLine(swigCPtr, this), false);
  }

  public GnLogColumns all() {
    return new GnLogColumns(gnsdk_javaJNI.GnLogColumns_all(swigCPtr, this), false);
  }

}