
package com.gracenote.gnsdk;

/** 
* Possible values for <code>EngineType</code> 
*/ 
 
public enum GnLocalStreamEngineType {
/** 
* Sets lookup local stream library to operate in memory-mapped mode. 
* Memory-mapped mode uses a memory-mapped file - the OS loads a portion of this file 
* into memory as it is accessed by an  application, which leads to overall lower peak memory 
* usage than in-memory mode. 
*/ 
 
  kLocalStreamEngineInvalid(0),
/** 
* Sets lookup local stream library to operate in in-memory mode. This is faster, but 
* for mobile devices the amount of memory needed may be prohibitive. 
*/ 
 
  kLocalStreamEngineMMap,
 
 
  kLocalStreamEngineInMemory;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnLocalStreamEngineType swigToEnum(int swigValue) {
    GnLocalStreamEngineType[] swigValues = GnLocalStreamEngineType.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnLocalStreamEngineType swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnLocalStreamEngineType.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnLocalStreamEngineType() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnLocalStreamEngineType(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnLocalStreamEngineType(GnLocalStreamEngineType swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

