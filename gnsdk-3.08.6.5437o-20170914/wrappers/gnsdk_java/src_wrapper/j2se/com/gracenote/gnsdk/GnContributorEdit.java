
package com.gracenote.gnsdk;

/** 
* 
*  represents  GnContributor's information returned by Gracenote. 
*/ 
 
public class GnContributorEdit extends GnDataObject {
  private transient long swigCPtr;

  protected GnContributorEdit(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnContributorEdit_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnContributorEdit obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnContributorEdit(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GnContributor gnContributor() {
    return new GnContributor(gnsdk_javaJNI.GnContributorEdit_gnContributor(swigCPtr, this), true);
  }

  public void genre(GnListElement genreElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnContributorEdit_genre(swigCPtr, this, GnListElement.getCPtr(genreElement), genreElement);
  }

  public void origin(GnListElement originElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnContributorEdit_origin(swigCPtr, this, GnListElement.getCPtr(originElement), originElement);
  }

  public void era(GnListElement eraElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnContributorEdit_era(swigCPtr, this, GnListElement.getCPtr(eraElement), eraElement);
  }

  public void artistType(GnListElement arttypeElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnContributorEdit_artistType(swigCPtr, this, GnListElement.getCPtr(arttypeElement), arttypeElement);
  }

}
