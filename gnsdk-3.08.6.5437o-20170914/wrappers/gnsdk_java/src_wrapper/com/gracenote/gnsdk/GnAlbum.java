/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnAlbum extends GnDataObject {
  private transient long swigCPtr;

  protected GnAlbum(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnAlbum_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnAlbum obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnAlbum(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public static String gnType() {
    return gnsdk_javaJNI.GnAlbum_gnType();
  }

  public static GnAlbum from(GnDataObject obj) throws com.gracenote.gnsdk.GnException {
    return new GnAlbum(gnsdk_javaJNI.GnAlbum_from(GnDataObject.getCPtr(obj), obj), true);
  }

  public GnAlbum(String id, String idTag) throws com.gracenote.gnsdk.GnException {
    this(gnsdk_javaJNI.new_GnAlbum(id, idTag), true);
  }

  public boolean isFullResult() {
    return gnsdk_javaJNI.GnAlbum_isFullResult(swigCPtr, this);
  }

  public GnTitle title() {
    return new GnTitle(gnsdk_javaJNI.GnAlbum_title(swigCPtr, this), true);
  }

  public GnArtist artist() {
    return new GnArtist(gnsdk_javaJNI.GnAlbum_artist(swigCPtr, this), true);
  }

  public String genre(GnDataLevel level) {
    return gnsdk_javaJNI.GnAlbum_genre(swigCPtr, this, level.swigValue());
  }

  public String label() {
    return gnsdk_javaJNI.GnAlbum_label(swigCPtr, this);
  }

  public String language() {
    return gnsdk_javaJNI.GnAlbum_language(swigCPtr, this);
  }

  public String languageCode() {
    return gnsdk_javaJNI.GnAlbum_languageCode(swigCPtr, this);
  }

  public String tui() {
    return gnsdk_javaJNI.GnAlbum_tui(swigCPtr, this);
  }

  public String tuiTag() {
    return gnsdk_javaJNI.GnAlbum_tuiTag(swigCPtr, this);
  }

  public String tagId() {
    return gnsdk_javaJNI.GnAlbum_tagId(swigCPtr, this);
  }

  public String gnId() {
    return gnsdk_javaJNI.GnAlbum_gnId(swigCPtr, this);
  }

  public String gnUId() {
    return gnsdk_javaJNI.GnAlbum_gnUId(swigCPtr, this);
  }

  public String globalId() {
    return gnsdk_javaJNI.GnAlbum_globalId(swigCPtr, this);
  }

  public long discInSet() {
    return gnsdk_javaJNI.GnAlbum_discInSet(swigCPtr, this);
  }

  public long totalInSet() {
    return gnsdk_javaJNI.GnAlbum_totalInSet(swigCPtr, this);
  }

  public String year() {
    return gnsdk_javaJNI.GnAlbum_year(swigCPtr, this);
  }

  public boolean isClassical() {
    return gnsdk_javaJNI.GnAlbum_isClassical(swigCPtr, this);
  }

  public long trackCount() {
    return gnsdk_javaJNI.GnAlbum_trackCount(swigCPtr, this);
  }

  public String compilation() {
    return gnsdk_javaJNI.GnAlbum_compilation(swigCPtr, this);
  }

  public long matchScore() {
    return gnsdk_javaJNI.GnAlbum_matchScore(swigCPtr, this);
  }

  public GnTrack track(long trackNumber) {
    return new GnTrack(gnsdk_javaJNI.GnAlbum_track(swigCPtr, this, trackNumber), true);
  }

  public GnTrack trackMatched(long ordinal) {
    return new GnTrack(gnsdk_javaJNI.GnAlbum_trackMatched__SWIG_0(swigCPtr, this, ordinal), true);
  }

  public GnTrack trackMatched() {
    return new GnTrack(gnsdk_javaJNI.GnAlbum_trackMatched__SWIG_1(swigCPtr, this), true);
  }

  public long trackMatchNumber(long ordinal) {
    return gnsdk_javaJNI.GnAlbum_trackMatchNumber__SWIG_0(swigCPtr, this, ordinal);
  }

  public long trackMatchNumber() {
    return gnsdk_javaJNI.GnAlbum_trackMatchNumber__SWIG_1(swigCPtr, this);
  }

  public GnContent content(GnContentType contentType) {
    return new GnContent(gnsdk_javaJNI.GnAlbum_content(swigCPtr, this, contentType.swigValue()), true);
  }

  public GnContent coverArt() {
    return new GnContent(gnsdk_javaJNI.GnAlbum_coverArt(swigCPtr, this), true);
  }

  public GnContent review() {
    return new GnContent(gnsdk_javaJNI.GnAlbum_review(swigCPtr, this), true);
  }

  public GnTrackIterable tracks() {
    return new GnTrackIterable(gnsdk_javaJNI.GnAlbum_tracks(swigCPtr, this), true);
  }

  public GnTrackIterable tracksMatched() {
    return new GnTrackIterable(gnsdk_javaJNI.GnAlbum_tracksMatched(swigCPtr, this), true);
  }

  public GnCreditIterable credits() {
    return new GnCreditIterable(gnsdk_javaJNI.GnAlbum_credits(swigCPtr, this), true);
  }

  public GnAudioWorkIterable audioWorks() {
    return new GnAudioWorkIterable(gnsdk_javaJNI.GnAlbum_audioWorks(swigCPtr, this), true);
  }

  public GnContentIterable contents() {
    return new GnContentIterable(gnsdk_javaJNI.GnAlbum_contents(swigCPtr, this), true);
  }

  public GnExternalIdIterable externalIds() {
    return new GnExternalIdIterable(gnsdk_javaJNI.GnAlbum_externalIds(swigCPtr, this), true);
  }

  public GnTitle titleClassical() {
    return new GnTitle(gnsdk_javaJNI.GnAlbum_titleClassical(swigCPtr, this), true);
  }

  public GnTitle titleRegional() {
    return new GnTitle(gnsdk_javaJNI.GnAlbum_titleRegional(swigCPtr, this), true);
  }

  public GnTitle titleRegionalLocale() {
    return new GnTitle(gnsdk_javaJNI.GnAlbum_titleRegionalLocale(swigCPtr, this), true);
  }

  public String script() {
    return gnsdk_javaJNI.GnAlbum_script(swigCPtr, this);
  }

}
