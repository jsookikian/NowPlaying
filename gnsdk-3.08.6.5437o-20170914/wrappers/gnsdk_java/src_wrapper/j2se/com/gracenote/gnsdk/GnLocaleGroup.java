
package com.gracenote.gnsdk;

/** 
* @enum {@link GnLocaleGroup} 
* Locale groups used when specifying which locale to load. 
*/ 
 
public enum GnLocaleGroup {
/** 
* Invalid locale group 
*/ 
 
  kLocaleGroupInvalid(0),
/** 
* Locale group for the GNSDK music products. Set this when creating a locale used with the MusicID and MusicID -File libraries. 
*/ 
 
  kLocaleGroupMusic,
/** 
* Locale group for the GNSDK video products. Set this when creating a locale used with the VideoID or Video Explore libraries (or both). 
*/ 
 
  kLocaleGroupVideo,
/** 
* Locale group for the GNSDK Playlist product. Set this when creating a locale used with the Playlist library. 
*/ 
 
  kLocaleGroupPlaylist,
/** 
* Locale group for the GNSDK EPG product. Set this when creating a locale used with the EPG library. 
*/ 
 
  kLocaleGroupEpg,
/** 
* Locale group for the GNSDK ACR products. Set this when creating a locale used with the ACR library. 
* Additionally, this will set the locale value for the MusicID, VideoID, VideoExplore and EPG libraries 
* that ACR uses. 
* <p> 
* <p><b>Remarks:</b></p> 
* If kLocaleGroupAcr is set <i>after</i> kLocaleGroupMusic, kLocaleGroupVideo or kLocaleGroupEpg is set, then kLocaleGroupAcr 
* will override any previous locale settings used with the MusicID, VideoID/VideoExplore and EPG libraries, and set the locale 
* for all of those libraries to the same locale value. 
* <p> 
* If kLocaleGroupMusic, kLocaleGroupVideo or kLocaleGroupEpg is set <i>after</i> kLocaleGroupAcr is set, then it will override 
* the locale value previously set by kLocaleGroupAcr for the MusicID, VideoID/VideoExplore or EPG libraries, respectively. 
*/ 
 
  kLocaleGroupAcr;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnLocaleGroup swigToEnum(int swigValue) {
    GnLocaleGroup[] swigValues = GnLocaleGroup.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnLocaleGroup swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnLocaleGroup.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnLocaleGroup() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnLocaleGroup(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnLocaleGroup(GnLocaleGroup swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

