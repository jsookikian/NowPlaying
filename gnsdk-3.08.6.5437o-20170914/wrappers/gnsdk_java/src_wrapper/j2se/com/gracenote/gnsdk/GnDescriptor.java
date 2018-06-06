
package com.gracenote.gnsdk;

/** 
* @enum {@link GnDescriptor} 
* <p> 
* Verbosity, or granularity, of returned Gracenote metadata. This only applies to genres. 
* If you want more, finer-grained genres, then use <code>kDescriptorDetailed</code>; 
* otherwise, if storage and bandwidth need to be minimized and/or you can live with 
* less granular genres, use <code>kDescriptorSimplified</code>. 
* <p> 
*/ 
 
public enum GnDescriptor {
 
 
  kDescriptorDefault(0),
 
 
  kDescriptorSimplified,
 
 
  kDescriptorDetailed;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnDescriptor swigToEnum(int swigValue) {
    GnDescriptor[] swigValues = GnDescriptor.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnDescriptor swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnDescriptor.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnDescriptor() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnDescriptor(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnDescriptor(GnDescriptor swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}
