/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnPlaylistStorage {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnPlaylistStorage(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnPlaylistStorage obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnPlaylistStorage(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnPlaylistStorage() {
    this(gnsdk_javaJNI.new_GnPlaylistStorage(), true);
  }

  public GnError isValid() {
    return new GnError(gnsdk_javaJNI.GnPlaylistStorage_isValid(swigCPtr, this), true);
  }

  public void compact() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistStorage_compact(swigCPtr, this);
  }

  public void store(GnPlaylistCollection collection) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistStorage_store(swigCPtr, this, GnPlaylistCollection.getCPtr(collection), collection);
  }

  public GnPlaylistCollection load(GnPlaylistStorageIterator itr) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistCollection(gnsdk_javaJNI.GnPlaylistStorage_load__SWIG_0(swigCPtr, this, GnPlaylistStorageIterator.getCPtr(itr), itr), true);
  }

  public GnPlaylistCollection load(String collectionName) throws com.gracenote.gnsdk.GnException {
    return new GnPlaylistCollection(gnsdk_javaJNI.GnPlaylistStorage_load__SWIG_1(swigCPtr, this, collectionName), true);
  }

  public void remove(GnPlaylistCollection collection) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistStorage_remove__SWIG_0(swigCPtr, this, GnPlaylistCollection.getCPtr(collection), collection);
  }

  public void remove(String collectionName) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistStorage_remove__SWIG_1(swigCPtr, this, collectionName);
  }

  public void location(String location) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnPlaylistStorage_location(swigCPtr, this, location);
  }

  public GnPlaylistStorageIterable names() {
    return new GnPlaylistStorageIterable(gnsdk_javaJNI.GnPlaylistStorage_names(swigCPtr, this), true);
  }

}