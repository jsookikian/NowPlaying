
package com.gracenote.gnsdk;

/** 
* 
*  encapsulates the Name's meta data information returned by Gracenote 
*/ 
 
public class GnNameEdit extends GnDataObject {
  private transient long swigCPtr;

  protected GnNameEdit(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnNameEdit_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnNameEdit obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnNameEdit(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GnName gnName() {
    return new GnName(gnsdk_javaJNI.GnNameEdit_gnName(swigCPtr, this), true);
  }

/** 
* 
*  Changes a {@link GnDataObject} value for a supported key of display value. If the value does not exist, it will 
*   be added. If the value does exist, it will be changed. If NULL or an empty string is passed in, the 
*   value will be deleted. 
*  @param value set Value corresponding to the specified {@link GnDataObject} value key 
*  <p><b>Remarks:</b></p> 
*  Use this function to edit an existing value of display value. Note that the value must already 
*   exist on the editable {@link GnDataObject}. 
*/ 
 
  public String display() {
    return gnsdk_javaJNI.GnNameEdit_display__SWIG_0(swigCPtr, this);
  }

  public void display(String value) {
    gnsdk_javaJNI.GnNameEdit_display__SWIG_1(swigCPtr, this, value);
  }

  public String sortable() {
    return gnsdk_javaJNI.GnNameEdit_sortable__SWIG_0(swigCPtr, this);
  }

  public void sortable(String value) {
    gnsdk_javaJNI.GnNameEdit_sortable__SWIG_1(swigCPtr, this, value);
  }

  public void language(GnListElement langElement) {
    gnsdk_javaJNI.GnNameEdit_language(swigCPtr, this, GnListElement.getCPtr(langElement), langElement);
  }

}
