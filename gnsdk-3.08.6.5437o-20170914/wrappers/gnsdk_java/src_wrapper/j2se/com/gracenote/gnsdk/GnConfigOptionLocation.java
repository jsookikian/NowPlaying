
package com.gracenote.gnsdk;

/** 
* @enum {@link GnConfigOptionLocation} 
* Config Option Location 
*/ 
 
public enum GnConfigOptionLocation {
 
 
  kConfigOptionLocationInvalid(0),
 
 
  kConfigOptionLocationLookupDatabaseAll,
 
 
  kConfigOptionLocationLookupDatabaseContent,
 
 
  kConfigOptionLocationLookupDatabaseMetadata,
 
 
  kConfigOptionLocationLookupDatabaseTocIndex,
 
 
  kConfigOptionLocationLookupDatabaseTextIndex,
 
 
  kConfigOptionLocationLookupDatabaseEpg;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnConfigOptionLocation swigToEnum(int swigValue) {
    GnConfigOptionLocation[] swigValues = GnConfigOptionLocation.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnConfigOptionLocation swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnConfigOptionLocation.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnConfigOptionLocation() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnConfigOptionLocation(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnConfigOptionLocation(GnConfigOptionLocation swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

