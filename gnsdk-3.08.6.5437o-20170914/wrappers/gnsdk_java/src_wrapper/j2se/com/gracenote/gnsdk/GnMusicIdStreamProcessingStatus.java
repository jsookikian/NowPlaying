
package com.gracenote.gnsdk;

/** 
* @enum {@link GnMusicIdStreamProcessingStatus} 
* {@link GnMusicIdStreamProcessingStatus} is currently considered to be experimental. 
* An application should only use this option if your Gracenote representative advises you to do so. 
* Contact your Gracenote representative with any questions about this enhanced functionality. 
* 
*/ 
 
public enum GnMusicIdStreamProcessingStatus {
 
 
  kStatusProcessingInvalid(0),
 
 
  kStatusProcessingAudioNone,
 
 
  kStatusProcessingAudioSilence,
 
 
  kStatusProcessingAudioNoise,
 
 
  kStatusProcessingAudioSpeech,
 
 
  kStatusProcessingAudioMusic,
 
 
  kStatusProcessingTransitionNone,
 
 
  kStatusProcessingTransitionChannelChange,
 
 
  kStatusProcessingTransitionContentToContent,
 
 
  kStatusProcessingErrorNoClassifier,
 
 
  kStatusProcessingAudioStarted,
 
 
  kStatusProcessingAudioEnded,
 
 
  kStatusProcessingEqProfileChanged;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnMusicIdStreamProcessingStatus swigToEnum(int swigValue) {
    GnMusicIdStreamProcessingStatus[] swigValues = GnMusicIdStreamProcessingStatus.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnMusicIdStreamProcessingStatus swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnMusicIdStreamProcessingStatus.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnMusicIdStreamProcessingStatus() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnMusicIdStreamProcessingStatus(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnMusicIdStreamProcessingStatus(GnMusicIdStreamProcessingStatus swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

