
package com.gracenote.gnsdk;

/** 
* 
*  represents  AudioWork's information returned by Gracenote. 
*/ 
 
public class GnAudioWorkEdit extends GnDataObject {
  private transient long swigCPtr;

  protected GnAudioWorkEdit(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnAudioWorkEdit_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnAudioWorkEdit obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnAudioWorkEdit(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GnAudioWork gnAudioWork() {
    return new GnAudioWork(gnsdk_javaJNI.GnAudioWorkEdit_gnAudioWork(swigCPtr, this), true);
  }

/** 
* 
*  Create an empty object of {@link GnTitleEdit} using TITLE OFFICIAL. 
*  @return {@link GnTitleEdit} 
*/ 
 
  public GnTitleEdit title() throws com.gracenote.gnsdk.GnException {
    return new GnTitleEdit(gnsdk_javaJNI.GnAudioWorkEdit_title(swigCPtr, this), true);
  }

  public GnCreditEdit creditAdd() throws com.gracenote.gnsdk.GnException {
    return new GnCreditEdit(gnsdk_javaJNI.GnAudioWorkEdit_creditAdd(swigCPtr, this), true);
  }

  public GnCreditEdit credit(long ord) throws com.gracenote.gnsdk.GnException {
    return new GnCreditEdit(gnsdk_javaJNI.GnAudioWorkEdit_credit(swigCPtr, this, ord), true);
  }

  public void origin(GnListElement originElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnAudioWorkEdit_origin(swigCPtr, this, GnListElement.getCPtr(originElement), originElement);
  }

  public void era(GnListElement eraElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnAudioWorkEdit_era(swigCPtr, this, GnListElement.getCPtr(eraElement), eraElement);
  }

/** 
* 
*  Sets a list-based value by the list item Submit ID for COMPOSITION FORM. If the value does not 
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the 
*   value is deleted. 
*  @param value set Value corresponding to the specified {@link GnDataObject} value key 
*  <p><b>Remarks:</b></p> 
*  Use this function to set a list-based Submit ID to COMPOSITION FORM, prior to adding the {@link GnDataObject} to a 
*   parcel. 
*/ 
 
  public String compositionForm() {
    return gnsdk_javaJNI.GnAudioWorkEdit_compositionForm__SWIG_0(swigCPtr, this);
  }

  public void compositionForm(String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnAudioWorkEdit_compositionForm__SWIG_1(swigCPtr, this, value);
  }

}
