
package com.gracenote.gnsdk;

public class musicid_file_info_provider {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected musicid_file_info_provider(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(musicid_file_info_provider obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_musicid_file_info_provider(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnMusicIdFileInfo getData(long pos) {
    return new GnMusicIdFileInfo(gnsdk_javaJNI.musicid_file_info_provider_getData(swigCPtr, this, pos), true);
  }

/** 
* 
*  Gets the number of {@link GnMusicIdFileInfo} objects available 
*@endinternal 
*/ 
 
  public long count() {
    return gnsdk_javaJNI.musicid_file_info_provider_count(swigCPtr, this);
  }

}
