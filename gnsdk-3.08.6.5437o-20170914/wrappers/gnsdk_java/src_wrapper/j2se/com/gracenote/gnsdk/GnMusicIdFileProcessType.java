
package com.gracenote.gnsdk;

/** 
*  @enum {@link GnMusicIdFileProcessType} 
*  Response and processing controls for DoTrackId, DoAlbumId and DoLibraryId 
*/ 
 
public enum GnMusicIdFileProcessType {
 
 
  kQueryReturnSingle(1),
 
 
  kQueryReturnAll;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnMusicIdFileProcessType swigToEnum(int swigValue) {
    GnMusicIdFileProcessType[] swigValues = GnMusicIdFileProcessType.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnMusicIdFileProcessType swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnMusicIdFileProcessType.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnMusicIdFileProcessType() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnMusicIdFileProcessType(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnMusicIdFileProcessType(GnMusicIdFileProcessType swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}
