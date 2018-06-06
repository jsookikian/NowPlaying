
package com.gracenote.gnsdk;

/** 
* @enum {@link GnSubmitFeatureSourceDescription} 
*/ 
 
public enum GnSubmitFeatureSourceDescription {
 
 
  kSubmitFeatureSourceDescription_unknown(0),
 
 
  kSubmitFeatureSourceDescription_cdda;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnSubmitFeatureSourceDescription swigToEnum(int swigValue) {
    GnSubmitFeatureSourceDescription[] swigValues = GnSubmitFeatureSourceDescription.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnSubmitFeatureSourceDescription swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnSubmitFeatureSourceDescription.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceDescription() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceDescription(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnSubmitFeatureSourceDescription(GnSubmitFeatureSourceDescription swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

