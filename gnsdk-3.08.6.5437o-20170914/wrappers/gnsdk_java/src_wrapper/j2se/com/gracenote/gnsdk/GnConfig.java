
package com.gracenote.gnsdk;

public class GnConfig extends GnConfigObject {
  private transient long swigCPtr;

  protected GnConfig(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnConfig_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnConfig obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnConfig(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GnConfig() throws com.gracenote.gnsdk.GnException {
    this(gnsdk_javaJNI.new_GnConfig__SWIG_0(), true);
  }

  public GnConfig(String config) throws com.gracenote.gnsdk.GnException {
    this(gnsdk_javaJNI.new_GnConfig__SWIG_1(config), true);
  }

  public void set(String custom, String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnConfig_set__SWIG_0(swigCPtr, this, custom, value);
  }

  public void set(GnConfigOptionAccess access) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnConfig_set__SWIG_1(swigCPtr, this, access.swigValue());
  }

  public void set(GnConfigOptionEnable enable, boolean value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnConfig_set__SWIG_2(swigCPtr, this, enable.swigValue(), value);
  }

  public void set(GnConfigOptionLocation location, String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnConfig_set__SWIG_3(swigCPtr, this, location.swigValue(), value);
  }

}
