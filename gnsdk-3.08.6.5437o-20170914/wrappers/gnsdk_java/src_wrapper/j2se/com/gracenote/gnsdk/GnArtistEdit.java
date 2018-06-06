
package com.gracenote.gnsdk;

/** 
* 
*  represents  Artist's information returned by Gracenote. 
*/ 
 
public class GnArtistEdit extends GnDataObject {
  private transient long swigCPtr;

  protected GnArtistEdit(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnArtistEdit_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnArtistEdit obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnArtistEdit(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GnArtist gnArtist() {
    return new GnArtist(gnsdk_javaJNI.GnArtistEdit_gnArtist(swigCPtr, this), true);
  }

/** 
* 
*  Create an empty object of {@link GnNameEdit} using NAME OFFICIAL. 
*  @return {@link GnNameEdit} 
*/ 
 
  public GnNameEdit name() throws com.gracenote.gnsdk.GnException {
    return new GnNameEdit(gnsdk_javaJNI.GnArtistEdit_name(swigCPtr, this), true);
  }

/** 
* 
*  Create an empty object of {@link GnContributorEdit} using CONTRIBUTOR. 
*  @return {@link GnContributorEdit} 
*/ 
 
  public GnContributorEdit contributor() throws com.gracenote.gnsdk.GnException {
    return new GnContributorEdit(gnsdk_javaJNI.GnArtistEdit_contributor(swigCPtr, this), true);
  }

}
