
package com.gracenote.gnsdk;

/** 
* <b>Experimental</b> 
*/ 
 
public class GnPlaylistStorageIterator {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnPlaylistStorageIterator(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnPlaylistStorageIterator obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnPlaylistStorageIterator(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public String __ref__() {
    return gnsdk_javaJNI.GnPlaylistStorageIterator___ref__(swigCPtr, this);
  }

  public String next() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnPlaylistStorageIterator_next(swigCPtr, this);
  }

  public boolean hasNext() {
    return gnsdk_javaJNI.GnPlaylistStorageIterator_hasNext(swigCPtr, this);
  }

  public long distance(GnPlaylistStorageIterator itr) {
    return gnsdk_javaJNI.GnPlaylistStorageIterator_distance(swigCPtr, this, GnPlaylistStorageIterator.getCPtr(itr), itr);
  }

  public GnPlaylistStorageIterator(collection_storage_provider provider, long pos) {
    this(gnsdk_javaJNI.new_GnPlaylistStorageIterator__SWIG_0(collection_storage_provider.getCPtr(provider), provider, pos), true);
  }

  public GnPlaylistStorageIterator(GnPlaylistStorageIterator copy) {
    this(gnsdk_javaJNI.new_GnPlaylistStorageIterator__SWIG_1(GnPlaylistStorageIterator.getCPtr(copy), copy), true);
  }

}
