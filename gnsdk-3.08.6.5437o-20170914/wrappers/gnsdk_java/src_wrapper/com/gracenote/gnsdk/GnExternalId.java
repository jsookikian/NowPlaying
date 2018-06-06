/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnExternalId extends GnDataObject {
  private transient long swigCPtr;

  protected GnExternalId(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnExternalId_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnExternalId obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnExternalId(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public static String gnType() {
    return gnsdk_javaJNI.GnExternalId_gnType();
  }

  public static GnExternalId from(GnDataObject obj) throws com.gracenote.gnsdk.GnException {
    return new GnExternalId(gnsdk_javaJNI.GnExternalId_from(GnDataObject.getCPtr(obj), obj), true);
  }

  public String source() {
    return gnsdk_javaJNI.GnExternalId_source(swigCPtr, this);
  }

  public String type() {
    return gnsdk_javaJNI.GnExternalId_type(swigCPtr, this);
  }

  public String value() {
    return gnsdk_javaJNI.GnExternalId_value(swigCPtr, this);
  }

}