
package com.gracenote.gnsdk;

/** 
* @enum {@link GnMusicIdStreamText} 
* @deprecated NB: Automatic mode will be removed in future release. Do not use. 
* 
*/ 
 
public enum GnMusicIdStreamText {
/** No text 
* @deprecated NB: Automatic mode will be removed in future release. Do not use. 
* 
*/ 
 
  kTextNone(0),
/** Accompanying text from shoutcast stream 
* @deprecated NB: Automatic mode will be removed in future release. Do not use. 
* 
*/ 
 
  kTextShoutcast,
/** Accompanying RDS RT Text 
* @deprecated NB: Automatic mode will be removed in future release. Do not use. 
* 
*/ 
 
  kTextRdsRt,
/** Accompanying RDS PTY Text 
* @deprecated NB: Automatic mode will be removed in future release. Do not use. 
* 
*/ 
 
  kTextRdsPty,
/** Accompanying RDS PI Text 
* @deprecated NB: Automatic mode will be removed in future release. Do not use. 
* 
*/ 
 
  kTextRdsPi,
/** Accompanying Artist Text 
* @deprecated NB: Automatic mode will be removed in future release. Do not use. 
* 
*/ 
 
  kTextArtist,
/** Accompanying Track Title Text 
* @deprecated NB: Automatic mode will be removed in future release. Do not use. 
* 
*/ 
 
  kTextTrackTitle,
/** Accompanying Album Title Text 
* @deprecated NB: Automatic mode will be removed in future release. Do not use. 
* 
*/ 
 
  kTextAlbumTitle;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnMusicIdStreamText swigToEnum(int swigValue) {
    GnMusicIdStreamText[] swigValues = GnMusicIdStreamText.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnMusicIdStreamText swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnMusicIdStreamText.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnMusicIdStreamText() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnMusicIdStreamText(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnMusicIdStreamText(GnMusicIdStreamText swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

