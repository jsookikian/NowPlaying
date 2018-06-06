
package com.gracenote.gnsdk;

/** 
* 
*  represents  GnTitle's information returned by Gracenote. 
*/ 
 
public class GnTitleEdit extends GnDataObject {
  private transient long swigCPtr;

  protected GnTitleEdit(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnTitleEdit_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnTitleEdit obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnTitleEdit(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GnTitle gnTitle() {
    return new GnTitle(gnsdk_javaJNI.GnTitleEdit_gnTitle(swigCPtr, this), true);
  }

/** 
* 
*  Sets a list-based value by the list item Submit ID for display value. If the value does not 
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the 
*   value is deleted. 
*  @param value set Value corresponding to the specified {@link GnDataObject} value key 
*  <p><b>Remarks:</b></p> 
*  Use this function to set a list-based Submit ID to display value, prior to adding the {@link GnDataObject} to a 
*   parcel. 
*/ 
 
  public String display() {
    return gnsdk_javaJNI.GnTitleEdit_display__SWIG_0(swigCPtr, this);
  }

  public void display(String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnTitleEdit_display__SWIG_1(swigCPtr, this, value);
  }

  public String sortable() {
    return gnsdk_javaJNI.GnTitleEdit_sortable__SWIG_0(swigCPtr, this);
  }

  public void sortable(String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnTitleEdit_sortable__SWIG_1(swigCPtr, this, value);
  }

  public void language(GnListElement langElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnTitleEdit_language(swigCPtr, this, GnListElement.getCPtr(langElement), langElement);
  }

}
