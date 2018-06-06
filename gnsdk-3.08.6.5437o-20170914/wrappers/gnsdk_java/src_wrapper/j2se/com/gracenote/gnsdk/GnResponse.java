
package com.gracenote.gnsdk;

public class GnResponse extends GnDataObject {
  private transient long swigCPtr;

  protected GnResponse(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnResponse_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnResponse obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnResponse(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public static String gnType() {
    return gnsdk_javaJNI.GnResponse_gnType();
  }

  public static GnResponse from(GnDataObject obj) throws com.gracenote.gnsdk.GnException {
    return new GnResponse(gnsdk_javaJNI.GnResponse_from(GnDataObject.getCPtr(obj), obj), true);
  }

  public GnResponse() {
    this(gnsdk_javaJNI.new_GnResponse(), true);
  }

  public GnResponseMeta meta() {
    return new GnResponseMeta(gnsdk_javaJNI.GnResponse_meta(swigCPtr, this), true);
  }

  public GnResponseData data() {
    return new GnResponseData(gnsdk_javaJNI.GnResponse_data(swigCPtr, this), true);
  }

  public GnResponseError error() {
    return new GnResponseError(gnsdk_javaJNI.GnResponse_error(swigCPtr, this), true);
  }

}
