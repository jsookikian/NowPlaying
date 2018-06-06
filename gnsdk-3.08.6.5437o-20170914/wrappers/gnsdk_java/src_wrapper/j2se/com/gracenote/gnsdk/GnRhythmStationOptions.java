
package com.gracenote.gnsdk;

/** 
* Configures options for {@link GnRhythmStation} 
*/ 
 
public class GnRhythmStationOptions extends GnRhythmQueryOptions {
  private transient long swigCPtr;

  protected GnRhythmStationOptions(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnRhythmStationOptions_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnRhythmStationOptions obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnRhythmStationOptions(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public void custom(String option, String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnRhythmStationOptions_custom(swigCPtr, this, option, value);
  }

}