
package com.gracenote.gnsdk;

/** 
** Gracenote Rhythm provide a suite of Adaptive Radio and Recommendation features. 
* <p> 
* Key features of Gracenote Rhythm: 
*    - Creates highly-relevant and personalized adaptive radio experiences and recommendations for end-users 
*    - Delivers radio stations or playlists from seed artist(s) and track(s) 
*    - Radio stations respond to user's likes and dislikes and includes support for DMCA (Digital Millennium Copyright Act) sequencing rulesPerforms bulk audio track recognition 
*/ 
 
public class GnRhythm {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnRhythm(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnRhythm obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnRhythm(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

/** 
*  Retrieves the Rhythm library's version string. 
*  <p><b>Remarks:</b></p> 
*  This API can be called at any time, after getting instance of {@link GnManager} successfully. 
*  The returned string is a constant. Do not attempt to modify or delete. 
* <p> 
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build) 
* <p> 
*  Major: New functionality 
*  Minor: New or changed features 
*  Improvement: Improvements and fixes 
*  Build: Internal build number 
*/ 
 
  public static String version() {
    return gnsdk_javaJNI.GnRhythm_version();
  }

/** 
*  Retrieves the Rhythm library's build date string. 
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC 
*  <p><b>Remarks:</b></p> 
*  This API can be called at any time, after getting instance of {@link GnManager} successfully. 
*  The returned string is a constant. Do not attempt to modify or delete. 
* <p> 
*  Example build date string: 2008-02-12 00:41 UTC 
*/ 
 
  public static String buildDate() {
    return gnsdk_javaJNI.GnRhythm_buildDate();
  }

  public GnRhythm() {
    this(gnsdk_javaJNI.new_GnRhythm(), true);
  }

}
