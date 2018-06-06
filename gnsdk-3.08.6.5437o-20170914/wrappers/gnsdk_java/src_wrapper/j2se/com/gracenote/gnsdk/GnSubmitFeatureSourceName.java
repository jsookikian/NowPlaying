
package com.gracenote.gnsdk;

/** 
* @enum {@link GnSubmitFeatureSourceName} 
*/ 
 
public enum GnSubmitFeatureSourceName {
 
 
  kSubmitFeatureSourceName_unknown(0),
 
 
  kSubmitFeatureSourceName_cdda;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnSubmitFeatureSourceName swigToEnum(int swigValue) {
    GnSubmitFeatureSourceName[] swigValues = GnSubmitFeatureSourceName.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnSubmitFeatureSourceName swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnSubmitFeatureSourceName.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceName() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceName(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceName(GnSubmitFeatureSourceName swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

