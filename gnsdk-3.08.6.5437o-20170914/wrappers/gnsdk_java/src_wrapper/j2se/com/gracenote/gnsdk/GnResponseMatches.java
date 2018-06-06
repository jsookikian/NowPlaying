
package com.gracenote.gnsdk;

/** 
*  Collection of matches from a Scan & Match query 
*/ 
 
public class GnResponseMatches extends GnDataObject {
  private transient long swigCPtr;

  protected GnResponseMatches(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnResponseMatches_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnResponseMatches obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnResponseMatches(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

/** 
* Iterator for accessing response match(es) 
* @return Iterator 
*/ 
 
  public GnMatchIterable matches() {
    return new GnMatchIterable(gnsdk_javaJNI.GnResponseMatches_matches(swigCPtr, this), true);
  }

}
