
package com.gracenote.gnsdk;

/** 
* @enum {@link GnImagePreferenceType} 
*/ 
 
public enum GnImagePreferenceType {
/** 
* Retrieve exact size as specified by {@link GnImageSize} 
*/ 
 
  kImagePreferenceExact(1),
/** 
* Retrieve exact or smaller size as specified by {@link GnImageSize} 
*/ 
 
  kImagePreferenceLargest,
/** 
* Retrieve exact or larger size as specified by {@link GnImageSize} 
*/ 
 
  kImagePreferenceSmallest;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnImagePreferenceType swigToEnum(int swigValue) {
    GnImagePreferenceType[] swigValues = GnImagePreferenceType.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnImagePreferenceType swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnImagePreferenceType.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnImagePreferenceType() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnImagePreferenceType(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnImagePreferenceType(GnImagePreferenceType swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

