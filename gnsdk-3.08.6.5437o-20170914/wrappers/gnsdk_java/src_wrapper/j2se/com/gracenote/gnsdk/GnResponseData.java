
package com.gracenote.gnsdk;

public class GnResponseData extends GnDataObject {
  private transient long swigCPtr;

  protected GnResponseData(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnResponseData_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnResponseData obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnResponseData(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public static String gnType() {
    return gnsdk_javaJNI.GnResponseData_gnType();
  }

  public static GnResponseData from(GnDataObject obj) throws com.gracenote.gnsdk.GnException {
    return new GnResponseData(gnsdk_javaJNI.GnResponseData_from(GnDataObject.getCPtr(obj), obj), true);
  }

  public GnResponseData() {
    this(gnsdk_javaJNI.new_GnResponseData(), true);
  }

}
