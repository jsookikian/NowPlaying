
package com.gracenote.gnsdk;

/** 
* @enum {@link GnMusicIdInfo} 
* Represents the different information types that can be retrieved from 
* a {@link GnMusicId} object. 
* 
*/ 
 
public enum GnMusicIdInfo {
/** If Audio Suitability Processing enabled this information type 
* indicates if the received audio is suitable for music identification 
* query. If not the query is less likely to return a match. 
* This info type is experimental and subject to change. 
*/ 
 
  kInfoInvalid(0),
 
 
  kInfoSuitableForQuery;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnMusicIdInfo swigToEnum(int swigValue) {
    GnMusicIdInfo[] swigValues = GnMusicIdInfo.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnMusicIdInfo swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnMusicIdInfo.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnMusicIdInfo() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnMusicIdInfo(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnMusicIdInfo(GnMusicIdInfo swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

