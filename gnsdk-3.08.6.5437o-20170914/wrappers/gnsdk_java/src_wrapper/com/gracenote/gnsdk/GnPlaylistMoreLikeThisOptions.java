/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnPlaylistMoreLikeThisOptions {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnPlaylistMoreLikeThisOptions(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnPlaylistMoreLikeThisOptions obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnPlaylistMoreLikeThisOptions(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public long maxTracks() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistMoreLikeThisOptions_maxTracks__SWIG_0(swigCPtr, this);
  }

  public void maxTracks(long value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistMoreLikeThisOptions_maxTracks__SWIG_1(swigCPtr, this, value);
  }

  public long maxPerArtist() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistMoreLikeThisOptions_maxPerArtist__SWIG_0(swigCPtr, this);
  }

  public void maxPerArtist(long value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistMoreLikeThisOptions_maxPerArtist__SWIG_1(swigCPtr, this, value);
  }

  public long maxPerAlbum() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistMoreLikeThisOptions_maxPerAlbum__SWIG_0(swigCPtr, this);
  }

  public void maxPerAlbum(long value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistMoreLikeThisOptions_maxPerAlbum__SWIG_1(swigCPtr, this, value);
  }

  public long randomSeed() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistMoreLikeThisOptions_randomSeed__SWIG_0(swigCPtr, this);
  }

  public void randomSeed(long value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistMoreLikeThisOptions_randomSeed__SWIG_1(swigCPtr, this, value);
  }

}
