
package com.gracenote.gnsdk;

/** 
* @enum {@link GnSubmitFeatureSourceBitRate} 
*/ 
 
public enum GnSubmitFeatureSourceBitRate {
 
 
  kSubmitFeatureSourceBitRate_unknown(0),
 
 
  kSubmitFeatureSourceBitRate_1411200;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnSubmitFeatureSourceBitRate swigToEnum(int swigValue) {
    GnSubmitFeatureSourceBitRate[] swigValues = GnSubmitFeatureSourceBitRate.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnSubmitFeatureSourceBitRate swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnSubmitFeatureSourceBitRate.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceBitRate() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceBitRate(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceBitRate(GnSubmitFeatureSourceBitRate swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

