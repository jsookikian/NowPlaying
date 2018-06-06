
package com.gracenote.gnsdk;

/** 
* @enum {@link GnListRenderFormat} 
* Flags indicating rendering format for a list object. 
*/ 
 
public enum GnListRenderFormat {
/** 
* Render list to XML format 
*/ 
 
  kListRenderFormat_Invalid,
/** 
* Render list to JSON format 
*/ 
 
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

