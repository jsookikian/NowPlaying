/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

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