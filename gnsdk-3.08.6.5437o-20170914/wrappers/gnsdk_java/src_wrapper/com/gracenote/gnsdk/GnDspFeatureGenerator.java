/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnDspFeatureGenerator {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnDspFeatureGenerator(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnDspFeatureGenerator obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnDspFeatureGenerator(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnDspFeatureGenerator(GnUser user, GnDspFeatureType featureType, long audioSampleRate, long audioSampleSize, long audioChannels) throws com.gracenote.gnsdk.GnException {
    this(gnsdk_javaJNI.new_GnDspFeatureGenerator(GnUser.getCPtr(user), user, featureType.swigValue(), audioSampleRate, audioSampleSize, audioChannels), true);
  }

  public boolean featureAudioWrite(byte[] audioData, long audioDataBytes) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnDspFeatureGenerator_featureAudioWrite(swigCPtr, this, audioData, audioDataBytes);
  }

  public void featureEndOfAudioWrite() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnDspFeatureGenerator_featureEndOfAudioWrite(swigCPtr, this);
  }

  public GnDspFeature featureRetrieve() throws com.gracenote.gnsdk.GnException {
    return new GnDspFeature(gnsdk_javaJNI.GnDspFeatureGenerator_featureRetrieve(swigCPtr, this), true);
  }

}
