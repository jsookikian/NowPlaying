
package com.gracenote.gnsdk;

/** 
* @enum {@link GnRegion} 
* Regions for loading locale/list 
*/ 
 
public enum GnRegion {
/** Default region. A region will be selected based on what's available. */ 
 
  kRegionDefault(0),
/** Global */ 
 
  kRegionGlobal,
/** United States */ 
 
  kRegionUS,
/** Japan */ 
 
  kRegionJapan,
/** China  */ 
 
  kRegionChina,
/** Taiwan */ 
 
  kRegionTaiwan,
/** Korea */ 
 
  kRegionKorea,
/** Europe */ 
 
  kRegionEurope,
/** Deprecated, will be removed in a future release, use kRegionUS. */ 
 
  kRegionNorthAmerica,
/** Latin America */ 
 
  kRegionLatinAmerica,
/** India */ 
 
  kRegionIndia;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnRegion swigToEnum(int swigValue) {
    GnRegion[] swigValues = GnRegion.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnRegion swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnRegion.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnRegion() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnRegion(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnRegion(GnRegion swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

