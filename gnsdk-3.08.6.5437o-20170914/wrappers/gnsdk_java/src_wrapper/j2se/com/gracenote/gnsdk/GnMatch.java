
package com.gracenote.gnsdk;

/** 
* {@link GnMatch} 
*/ 
 
public class GnMatch extends GnDataObject {
  private transient long swigCPtr;

  protected GnMatch(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnMatch_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnMatch obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnMatch(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

/** 
* Match's Gracenote Tui (title-unique identifier) 
* @return Tui 
*/ 
 
  public String tui() {
    return gnsdk_javaJNI.GnMatch_tui(swigCPtr, this);
  }

/** 
* Match's Gracenote Tui Tag. 
* @return Tui Tag 
*/ 
 
  public String tuiTag() {
    return gnsdk_javaJNI.GnMatch_tuiTag(swigCPtr, this);
  }

/** 
*  Match info type - album or contributor 
*  @return Match information 
*/ 
 
  public String matchInfo() {
    return gnsdk_javaJNI.GnMatch_matchInfo(swigCPtr, this);
  }

/** 
* Iterator for match's external identifiers (e.g., Amazon's). 
* @return Iterator 
*/ 
 
  public GnExternalIdIterable externalIds() {
    return new GnExternalIdIterable(gnsdk_javaJNI.GnMatch_externalIds(swigCPtr, this), true);
  }

}
