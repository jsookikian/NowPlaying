
package com.gracenote.gnsdk;

/** 
* @enum {@link GnSubmitFeatureSourceId} 
*/ 
 
public enum GnSubmitFeatureSourceId {
 
 
  kSubmitFeatureSourceId_unknown(0),
 
 
  kSubmitFeatureSourceId_cdda;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnSubmitFeatureSourceId swigToEnum(int swigValue) {
    GnSubmitFeatureSourceId[] swigValues = GnSubmitFeatureSourceId.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnSubmitFeatureSourceId swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnSubmitFeatureSourceId.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceId() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceId(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceId(GnSubmitFeatureSourceId swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

