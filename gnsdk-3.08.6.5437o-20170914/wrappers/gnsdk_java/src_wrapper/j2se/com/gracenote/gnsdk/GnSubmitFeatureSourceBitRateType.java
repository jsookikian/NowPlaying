
package com.gracenote.gnsdk;

/** 
* @enum {@link GnSubmitFeatureSourceBitRateType} 
*/ 
 
public enum GnSubmitFeatureSourceBitRateType {
 
 
  kSubmitFeatureSourceBitRateType_unknown(0),
 
 
  kSubmitFeatureSourceBitRateType_constant;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnSubmitFeatureSourceBitRateType swigToEnum(int swigValue) {
    GnSubmitFeatureSourceBitRateType[] swigValues = GnSubmitFeatureSourceBitRateType.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnSubmitFeatureSourceBitRateType swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnSubmitFeatureSourceBitRateType.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceBitRateType() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceBitRateType(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceBitRateType(GnSubmitFeatureSourceBitRateType swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

