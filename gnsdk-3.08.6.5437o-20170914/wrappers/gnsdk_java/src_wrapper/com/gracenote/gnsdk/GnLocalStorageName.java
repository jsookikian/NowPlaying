/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public enum GnLocalStorageName {
  kLocalStorageInvalid(0),
  kLocalStorageContent,
  kLocalStorageMetadata,
  kLocalStorageTOCIndex,
  kLocalStorageTextIndex,
  kLocalStorageAll;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnLocalStorageName swigToEnum(int swigValue) {
    GnLocalStorageName[] swigValues = GnLocalStorageName.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnLocalStorageName swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnLocalStorageName.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnLocalStorageName() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnLocalStorageName(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnLocalStorageName(GnLocalStorageName swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

