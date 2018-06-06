
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

/** 
* Initializes the DSP library. 
* @param user set user 
* @param featureType The kind of DSP feature, for example a fingerprint. 
* @param audioSampleRate The source audio sample rate. 
* @param audioSampleSize The source audio sample size. 
* @param audioChannels	The source audio channels 
*/ 
 
  public GnDspFeatureGenerator(GnUser user, GnDspFeatureType featureType, long audioSampleRate, long audioSampleSize, long audioChannels) throws com.gracenote.gnsdk.GnException {
    this(gnsdk_javaJNI.new_GnDspFeatureGenerator(GnUser.getCPtr(user), user, featureType.swigValue(), audioSampleRate, audioSampleSize, audioChannels), true);
  }

/** 
* Use this method to feed audio in to {@link GnDsp} until it returns true 
* @param audioData The source audio 
* @param audioDataBytes The source audio size in bytes 
* @return false : {@link GnDsp} needs more audio, true : {@link GnDsp} received enough audio to generate required feature 
*/ 
 
  public boolean featureAudioWrite(byte[] audioData, long audioDataBytes) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnDspFeatureGenerator_featureAudioWrite(swigCPtr, this, audioData, audioDataBytes);
  }

/** 
* Indicates the the DSP feature has reached the end of the write operation. 
*/ 
 
  public void featureEndOfAudioWrite() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnDspFeatureGenerator_featureEndOfAudioWrite(swigCPtr, this);
  }

/** 
* Retrieve {@link GnDspFeature} 
* @return {@link GnDspFeature} 
*/ 
 
  public GnDspFeature featureRetrieve() throws com.gracenote.gnsdk.GnException {
    return new GnDspFeature(gnsdk_javaJNI.GnDspFeatureGenerator_featureRetrieve(swigCPtr, this), true);
  }

}
