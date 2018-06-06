
package com.gracenote.gnsdk;

/** 
* Provides access to {@link GnListElement} iterator object 
*/ 
 
public class GnListElementChildIterable {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnListElementChildIterable(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnListElementChildIterable obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnListElementChildIterable(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnListElementChildIterable(list_element_child_provider provider, long start) {
    this(gnsdk_javaJNI.new_GnListElementChildIterable(list_element_child_provider.getCPtr(provider), provider, start), true);
  }

  public GnListElementChildIterator getIterator() {
    return new GnListElementChildIterator(gnsdk_javaJNI.GnListElementChildIterable_getIterator(swigCPtr, this), true);
  }

  public GnListElementChildIterator end() {
    return new GnListElementChildIterator(gnsdk_javaJNI.GnListElementChildIterable_end(swigCPtr, this), true);
  }

  public long count() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnListElementChildIterable_count(swigCPtr, this);
  }

  public GnListElementChildIterator at(long index) {
    return new GnListElementChildIterator(gnsdk_javaJNI.GnListElementChildIterable_at(swigCPtr, this, index), true);
  }

  public GnListElementChildIterator getByIndex(long index) {
    return new GnListElementChildIterator(gnsdk_javaJNI.GnListElementChildIterable_getByIndex(swigCPtr, this, index), true);
  }

}
