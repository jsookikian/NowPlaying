
package com.gracenote.gnsdk;

public class GnResponseMeta extends GnDataObject {
  private transient long swigCPtr;

  protected GnResponseMeta(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnResponseMeta_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnResponseMeta obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnResponseMeta(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public static String gnType() {
    return gnsdk_javaJNI.GnResponseMeta_gnType();
  }

  public static GnResponseMeta from(GnDataObject obj) throws com.gracenote.gnsdk.GnException {
    return new GnResponseMeta(gnsdk_javaJNI.GnResponseMeta_from(GnDataObject.getCPtr(obj), obj), true);
  }

  public GnResponseMeta() {
    this(gnsdk_javaJNI.new_GnResponseMeta(), true);
  }

}
