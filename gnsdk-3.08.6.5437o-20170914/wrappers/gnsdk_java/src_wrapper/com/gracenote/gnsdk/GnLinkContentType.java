/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public enum GnLinkContentType {
  kLinkContentUnknown(0),
  kLinkContentCoverArt,
  kLinkContentGenreArt,
  kLinkContentReview,
  kLinkContentBiography,
  kLinkContentArtistNews,
  kLinkContentLyricXML,
  kLinkContentLyricText,
  kLinkContentDspData,
  kLinkContentCommentsListener,
  kLinkContentCommentsRelease,
  kLinkContentNews,
  kLinkContentImage,
  kLinkContentImageArtist;

  protected final int swigValue() {
    return swigValue;
  }

  protected static GnLinkContentType swigToEnum(int swigValue) {
    GnLinkContentType[] swigValues = GnLinkContentType.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (GnLinkContentType swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + GnLinkContentType.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private GnLinkContentType() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private GnLinkContentType(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private GnLinkContentType(GnLinkContentType swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

