/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnPlaylistStorageIterable {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnPlaylistStorageIterable(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnPlaylistStorageIterable obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnPlaylistStorageIterable(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnPlaylistStorageIterable(collection_storage_provider provider, long start) {
    this(gnsdk_javaJNI.new_GnPlaylistStorageIterable(collection_storage_provider.getCPtr(provider), provider, start), true);
  }

  public GnPlaylistStorageIterator getIterator() {
    return new GnPlaylistStorageIterator(gnsdk_javaJNI.GnPlaylistStorageIterable_getIterator(swigCPtr, this), true);
  }

  public GnPlaylistStorageIterator end() {
    return new GnPlaylistStorageIterator(gnsdk_javaJNI.GnPlaylistStorageIterable_end(swigCPtr, this), true);
  }

  public long count() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistStorageIterable_count(swigCPtr, this);
  }

  public GnPlaylistStorageIterator at(long index) {
    return new GnPlaylistStorageIterator(gnsdk_javaJNI.GnPlaylistStorageIterable_at(swigCPtr, this, index), true);
  }

  public GnPlaylistStorageIterator getByIndex(long index) {
    return new GnPlaylistStorageIterator(gnsdk_javaJNI.GnPlaylistStorageIterable_getByIndex(swigCPtr, this, index), true);
  }

}
