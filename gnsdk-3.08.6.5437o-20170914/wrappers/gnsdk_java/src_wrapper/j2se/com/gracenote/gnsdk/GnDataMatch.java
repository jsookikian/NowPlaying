
package com.gracenote.gnsdk;

/** 
*  Represents a match to query where any type of match is desired, album or contributor. 
*/ 
 
public class GnDataMatch extends GnDataObject {
  private transient long swigCPtr;

  protected GnDataMatch(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnDataMatch_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnDataMatch obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnDataMatch(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

/** 
*  Flag indicating if match is album 
*  @return True if album is a match, false otherwise 
*/ 
 
  public boolean isAlbum() {
    return gnsdk_javaJNI.GnDataMatch_isAlbum(swigCPtr, this);
  }

/** 
*  Flag indicating if match is contributor 
*  @return True if result is a contributor, false otherwise 
*/ 
 
  public boolean isContributor() {
    return gnsdk_javaJNI.GnDataMatch_isContributor(swigCPtr, this);
  }

/** 
*  If album, get match as album object 
*  @return Album 
*/ 
 
  public GnAlbum getAsAlbum() {
    return new GnAlbum(gnsdk_javaJNI.GnDataMatch_getAsAlbum(swigCPtr, this), true);
  }

/** 
*  Flag indicating if response contains full (true) or partial (false) metadata. 
*  @return True if full result, false if partial result 
* <p><b>Note:</b></p> 
*   What constitutes a full result varies among the individual response types and results, and also 
*  depends on data availability. 
* 
*/ 
 
  public boolean isFullResult() {
    return gnsdk_javaJNI.GnDataMatch_isFullResult(swigCPtr, this);
  }

/** 
*  If contributor, get match as contributor object 
*  @return Contributor 
*/ 
 
  public GnContributor getAsContributor() {
    return new GnContributor(gnsdk_javaJNI.GnDataMatch_getAsContributor(swigCPtr, this), true);
  }

}
