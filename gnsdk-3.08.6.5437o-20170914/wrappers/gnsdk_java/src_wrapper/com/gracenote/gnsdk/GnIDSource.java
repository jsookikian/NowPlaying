/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public enum GnIDSource {
  kIDSourceInvalid(0),
  kIDSourceTrack(1),
  kIDSourceContributor,
  kIDSourceVideoWork,
  kIDSourceVideoProduct,
  kIDSourceVideoDisc,
  kIDSourceVideoSeason,
  kIDSourceVideoSeries,
  kIDSourceVideoTvProgram,
  kIDSourceLyric,
  kIDSourceCddbId;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnIDSource swigToEnum(int swigValue) {
    GnIDSource[] swigValues = GnIDSource.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnIDSource swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnIDSource.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnIDSource() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnIDSource(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnIDSource(GnIDSource swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}
