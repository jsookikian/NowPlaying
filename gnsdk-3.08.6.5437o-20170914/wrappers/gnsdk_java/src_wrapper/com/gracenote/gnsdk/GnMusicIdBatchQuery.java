/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnMusicIdBatchQuery {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnMusicIdBatchQuery(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnMusicIdBatchQuery obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnMusicIdBatchQuery(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnMusicIdBatchQuery(GnMusicIdBatch batch, String uniqueId) throws com.gracenote.gnsdk.GnException {
    this(gnsdk_javaJNI.new_GnMusicIdBatchQuery(GnMusicIdBatch.getCPtr(batch), batch, uniqueId), true);
  }

  public void setFingerprint(String strFingerprintData, GnFingerprintType fpType) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchQuery_setFingerprint(swigCPtr, this, strFingerprintData, fpType.swigValue());
  }

  public void setGDO(GnDataObject gnObj) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchQuery_setGDO(swigCPtr, this, GnDataObject.getCPtr(gnObj), gnObj);
  }

  public void setText(String albumTitle, String trackTitle, String albumArtistName, String trackArtistName, String composerName) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchQuery_setText(swigCPtr, this, albumTitle, trackTitle, albumArtistName, trackArtistName, composerName);
  }

  public void setTOCOffset(long tocOffset) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchQuery_setTOCOffset(swigCPtr, this, tocOffset);
  }

  public void setTOC(String strTOC) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchQuery_setTOC(swigCPtr, this, strTOC);
  }

}