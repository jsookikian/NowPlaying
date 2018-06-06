
package com.gracenote.gnsdk;

/** 
* @enum {@link GnConfigOptionEnable} 
* Config Option Enable 
*/ 
 
public enum GnConfigOptionEnable {
 
 
  kConfigOptionEnableInvalid(0),
 
 
  kConfigOptionEnableLookupDatabaseMusicID,
 
 
  kConfigOptionEnableLookupDatabaseMusicIDText,
 
 
  kConfigOptionEnableLookupDatabaseMusicIDCD,
 
 
  kConfigOptionEnableLookupDatabaseMusicIDImages,
 
 
  kConfigOptionEnableLookupDatabaseEpgRadio,
 
 
  kConfigOptionEnableLookupDatabaseEpgTV;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnConfigOptionEnable swigToEnum(int swigValue) {
    GnConfigOptionEnable[] swigValues = GnConfigOptionEnable.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnConfigOptionEnable swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnConfigOptionEnable.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnConfigOptionEnable() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnConfigOptionEnable(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnConfigOptionEnable(GnConfigOptionEnable swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

