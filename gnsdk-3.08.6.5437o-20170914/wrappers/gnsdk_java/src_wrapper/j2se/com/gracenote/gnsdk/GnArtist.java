
package com.gracenote.gnsdk;

/** 
* Person or group primarily responsible for creating the Album or Track. 
* <p> 
* Part of the metadata returned from a recognition event. 
* <p> 
* <p><b>SDK Documentation</b></p> 
* <p> 
* Topic:  .../docs/html-oo > index.html > Data Models 
* <p> 
*  The above topic displays all the metadata returned from a recognition event. 
*  It does this in an expand/collapse format, showing object hierarchy and 
*  a description of each field returned. 
* <p> 
*/ 
 
public class GnArtist extends GnDataObject {
  private transient long swigCPtr;

  protected GnArtist(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnArtist_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnArtist obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnArtist(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public static String gnType() {
    return gnsdk_javaJNI.GnArtist_gnType();
  }

  public static GnArtist from(GnDataObject obj) throws com.gracenote.gnsdk.GnException {
    return new GnArtist(gnsdk_javaJNI.GnArtist_from(GnDataObject.getCPtr(obj), obj), true);
  }

/** 
* Artist's official name. 
* @return Name 
*/ 
 
  public GnName name() {
    return new GnName(gnsdk_javaJNI.GnArtist_name(swigCPtr, this), true);
  }

/** 
* Contributor object - contributor associated with the work 
* @return Contributor 
*/ 
 
  public GnContributor contributor() {
    return new GnContributor(gnsdk_javaJNI.GnArtist_contributor(swigCPtr, this), true);
  }

}
