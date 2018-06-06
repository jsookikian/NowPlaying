/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnStringValueIterable {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnStringValueIterable(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnStringValueIterable obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnStringValueIterable(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnStringValueIterable(gn_gdo_string_provider provider, long start) {
    this(gnsdk_javaJNI.new_GnStringValueIterable(gn_gdo_string_provider.getCPtr(provider), provider, start), true);
  }

  public GnStringValueIterator getIterator() {
    return new GnStringValueIterator(gnsdk_javaJNI.GnStringValueIterable_getIterator(swigCPtr, this), true);
  }

  public GnStringValueIterator end() {
    return new GnStringValueIterator(gnsdk_javaJNI.GnStringValueIterable_end(swigCPtr, this), true);
  }

  public long count() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnStringValueIterable_count(swigCPtr, this);
  }

  public GnStringValueIterator at(long index) {
    return new GnStringValueIterator(gnsdk_javaJNI.GnStringValueIterable_at(swigCPtr, this, index), true);
  }

  public GnStringValueIterator getByIndex(long index) {
    return new GnStringValueIterator(gnsdk_javaJNI.GnStringValueIterable_getByIndex(swigCPtr, this, index), true);
  }

}
