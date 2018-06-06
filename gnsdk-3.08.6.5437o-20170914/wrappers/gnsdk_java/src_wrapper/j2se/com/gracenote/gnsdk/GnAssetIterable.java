
package com.gracenote.gnsdk;

/** 
* Provides access to {@link GnAsset} iterator object 
*/ 
 
public class GnAssetIterable {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnAssetIterable(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnAssetIterable obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnAssetIterable(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnAssetIterable(GnAssetProvider provider, long start) {
    this(gnsdk_javaJNI.new_GnAssetIterable(GnAssetProvider.getCPtr(provider), provider, start), true);
  }

  public GnAssetIterator getIterator() {
    return new GnAssetIterator(gnsdk_javaJNI.GnAssetIterable_getIterator(swigCPtr, this), true);
  }

  public GnAssetIterator end() {
    return new GnAssetIterator(gnsdk_javaJNI.GnAssetIterable_end(swigCPtr, this), true);
  }

  public long count() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnAssetIterable_count(swigCPtr, this);
  }

  public GnAssetIterator at(long index) {
    return new GnAssetIterator(gnsdk_javaJNI.GnAssetIterable_at(swigCPtr, this, index), true);
  }

  public GnAssetIterator getByIndex(long index) {
    return new GnAssetIterator(gnsdk_javaJNI.GnAssetIterable_getByIndex(swigCPtr, this, index), true);
  }

}