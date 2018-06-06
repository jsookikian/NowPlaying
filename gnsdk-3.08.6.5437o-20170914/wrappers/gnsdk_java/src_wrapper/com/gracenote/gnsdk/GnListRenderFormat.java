/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public enum GnListRenderFormat {
  kListRenderFormat_Invalid,
  kListRenderFormat_XML,
  kListRenderFormat_XMLv2,
  kListRenderFormat_JSON,
  kListRenderFormat_JSONv2;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnListRenderFormat swigToEnum(int swigValue) {
    GnListRenderFormat[] swigValues = GnListRenderFormat.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnListRenderFormat swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnListRenderFormat.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnListRenderFormat() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnListRenderFormat(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnListRenderFormat(GnListRenderFormat swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}
