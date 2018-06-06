/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnPlaylistAttributes extends GnDataObject {
  private transient long swigCPtr;

  protected GnPlaylistAttributes(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnPlaylistAttributes_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnPlaylistAttributes obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnPlaylistAttributes(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GnPlaylistAttributes(GnPlaylistAttributes other) {
    this(gnsdk_javaJNI.new_GnPlaylistAttributes(GnPlaylistAttributes.getCPtr(other), other), true);
  }

  public String albumName() {
    return gnsdk_javaJNI.GnPlaylistAttributes_albumName(swigCPtr, this);
  }

  public String artistName() {
    return gnsdk_javaJNI.GnPlaylistAttributes_artistName(swigCPtr, this);
  }

  public String artistType() {
    return gnsdk_javaJNI.GnPlaylistAttributes_artistType(swigCPtr, this);
  }

  public String era() {
    return gnsdk_javaJNI.GnPlaylistAttributes_era(swigCPtr, this);
  }

  public String genre() {
    return gnsdk_javaJNI.GnPlaylistAttributes_genre(swigCPtr, this);
  }

  public String origin() {
    return gnsdk_javaJNI.GnPlaylistAttributes_origin(swigCPtr, this);
  }

  public String mood() {
    return gnsdk_javaJNI.GnPlaylistAttributes_mood(swigCPtr, this);
  }

  public String tempo() {
    return gnsdk_javaJNI.GnPlaylistAttributes_tempo(swigCPtr, this);
  }

  public String value(String attrName) {
    return gnsdk_javaJNI.GnPlaylistAttributes_value(swigCPtr, this, attrName);
  }

}
