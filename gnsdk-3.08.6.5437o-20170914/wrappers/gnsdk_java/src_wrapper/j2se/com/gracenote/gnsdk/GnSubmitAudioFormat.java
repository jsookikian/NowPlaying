
package com.gracenote.gnsdk;

/** 
* @enum {@link GnSubmitAudioFormat} 
*/ 
 
public enum GnSubmitAudioFormat {
 
 
  kSubmitAudioFormat_unknown(0),
 
 
  kSubmitAudioFormat_pcm16;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnSubmitAudioFormat swigToEnum(int swigValue) {
    GnSubmitAudioFormat[] swigValues = GnSubmitAudioFormat.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnSubmitAudioFormat swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnSubmitAudioFormat.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnSubmitAudioFormat() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnSubmitAudioFormat(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnSubmitAudioFormat(GnSubmitAudioFormat swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

