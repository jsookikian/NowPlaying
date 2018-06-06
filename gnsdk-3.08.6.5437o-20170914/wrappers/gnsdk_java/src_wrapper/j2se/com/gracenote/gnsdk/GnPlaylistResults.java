
package com.gracenote.gnsdk;

/** 
* <b>Experimental</b>: {@link GnPlaylistResults} 
*/ 
 
public class GnPlaylistResults {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnPlaylistResults(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnPlaylistResults obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnPlaylistResults(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnPlaylistResults() {
    this(gnsdk_javaJNI.new_GnPlaylistResults(), true);
  }

  public GnPlaylistResultIdentIterable identifiers() {
    return new GnPlaylistResultIdentIterable(gnsdk_javaJNI.GnPlaylistResults_identifiers(swigCPtr, this), true);
  }

}
