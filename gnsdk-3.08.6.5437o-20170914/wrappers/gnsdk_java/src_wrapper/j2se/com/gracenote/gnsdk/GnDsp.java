
package com.gracenote.gnsdk;

/************************************************************************** 
** {@link GnDsp} 
*/ 
 
public class GnDsp {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnDsp(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnDsp obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnDsp(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

/** 
* Enable a dsp provider. 
* @return dsp provider instance 
*/ 
 
  public static GnDsp enable() throws com.gracenote.gnsdk.GnException {
    return new GnDsp(gnsdk_javaJNI.GnDsp_enable(), false);
  }

/** 
*  Retrieves {@link GnDsp} SDK version string. 
*  This API can be called at any time, after getting instance of {@link GnManager} successfully. The returned 
*  string is a constant. Do not attempt to modify or delete. 
*  Example: 1.2.3.123 (Major.Minor.Improvement.Build) 
*  Major: New functionality 
*  Minor: New or changed features 
*  Improvement: Improvements and fixes 
*  Build: Internal build number 
*/ 
 
  public static String version() {
    return gnsdk_javaJNI.GnDsp_version();
  }

/** 
*  Retrieves the {@link GnDsp} SDK's build date string. 
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC 
*  <p><b>Remarks:</b></p> 
*  This API can be called at any time, after getting instance of {@link GnManager} successfully. The returned 
* string is a constant. Do not attempt to modify or delete. 
*  Example build date string: 2008-02-12 00:41 UTC 
*/ 
 
  public static String buildDate() {
    return gnsdk_javaJNI.GnDsp_buildDate();
  }

/** 
*  Sets a folder location for Audio Classifier Storage 
*  @param location	[in] Relative path name for storage 
*/ 
 
  public void audioClassifierStorageLocation(String location) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnDsp_audioClassifierStorageLocation(swigCPtr, this, location);
  }

}
