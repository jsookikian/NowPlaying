
package com.gracenote.gnsdk;

public class GnResponseError extends GnDataObject {
  private transient long swigCPtr;

  protected GnResponseError(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnResponseError_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnResponseError obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnResponseError(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public static String gnType() {
    return gnsdk_javaJNI.GnResponseError_gnType();
  }

  public static GnResponseError from(GnDataObject obj) throws com.gracenote.gnsdk.GnException {
    return new GnResponseError(gnsdk_javaJNI.GnResponseError_from(GnDataObject.getCPtr(obj), obj), true);
  }

  public GnResponseError() {
    this(gnsdk_javaJNI.new_GnResponseError(), true);
  }

}
