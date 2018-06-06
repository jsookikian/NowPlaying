
package com.gracenote.gnsdk;

/** 
* @enum {@link GnConfigOptionAccess} 
* Config Option Access 
*/ 
 
public enum GnConfigOptionAccess {
 
 
  kConfigOptionAccessInvalid(0),
 
 
  kConfigOptionAccessLookupDatabaseReadOnly,
 
 
  kConfigOptionAccessLookupDatabaseReadWrite;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnConfigOptionAccess swigToEnum(int swigValue) {
    GnConfigOptionAccess[] swigValues = GnConfigOptionAccess.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnConfigOptionAccess swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnConfigOptionAccess.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnConfigOptionAccess() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnConfigOptionAccess(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnConfigOptionAccess(GnConfigOptionAccess swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

