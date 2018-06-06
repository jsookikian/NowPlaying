/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnMoodgridProviderIterable {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnMoodgridProviderIterable(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnMoodgridProviderIterable obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnMoodgridProviderIterable(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnMoodgridProviderIterable(moodgrid_provider provider, long start) {
    this(gnsdk_javaJNI.new_GnMoodgridProviderIterable(moodgrid_provider.getCPtr(provider), provider, start), true);
  }

  public GnMoodgridProviderIterator getIterator() {
    return new GnMoodgridProviderIterator(gnsdk_javaJNI.GnMoodgridProviderIterable_getIterator(swigCPtr, this), true);
  }

  public GnMoodgridProviderIterator end() {
    return new GnMoodgridProviderIterator(gnsdk_javaJNI.GnMoodgridProviderIterable_end(swigCPtr, this), true);
  }

  public long count() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnMoodgridProviderIterable_count(swigCPtr, this);
  }

  public GnMoodgridProviderIterator at(long index) {
    return new GnMoodgridProviderIterator(gnsdk_javaJNI.GnMoodgridProviderIterable_at(swigCPtr, this, index), true);
  }

  public GnMoodgridProviderIterator getByIndex(long index) {
    return new GnMoodgridProviderIterator(gnsdk_javaJNI.GnMoodgridProviderIterable_getByIndex(swigCPtr, this, index), true);
  }

}
