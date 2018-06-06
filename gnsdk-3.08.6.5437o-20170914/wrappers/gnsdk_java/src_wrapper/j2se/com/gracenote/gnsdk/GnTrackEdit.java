
package com.gracenote.gnsdk;

/** 
* 
*  represents  Track's information returned by Gracenote. 
*/ 
 
public class GnTrackEdit extends GnDataObject {
  private transient long swigCPtr;

  protected GnTrackEdit(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnTrackEdit_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnTrackEdit obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnTrackEdit(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GnTrack gnTrack() {
    return new GnTrack(gnsdk_javaJNI.GnTrackEdit_gnTrack(swigCPtr, this), true);
  }

/** 
* 
*  Create an empty object of {@link GnTitleEdit} using TITLE OFFICIAL. 
*  @return {@link GnTitleEdit} 
*/ 
 
  public GnTitleEdit title() throws com.gracenote.gnsdk.GnException {
    return new GnTitleEdit(gnsdk_javaJNI.GnTrackEdit_title(swigCPtr, this), true);
  }

/** 
* 
*  Create an empty object of {@link GnArtistEdit} using ARTIST. 
*  @return {@link GnArtistEdit} 
*/ 
 
  public GnArtistEdit artist() throws com.gracenote.gnsdk.GnException {
    return new GnArtistEdit(gnsdk_javaJNI.GnTrackEdit_artist(swigCPtr, this), true);
  }

/** 
* 
*  Create an empty object of {@link GnCreditEdit} using CREDIT. 
*  @return {@link GnCreditEdit} 
*/ 
 
  public GnCreditEdit creditAdd() throws com.gracenote.gnsdk.GnException {
    return new GnCreditEdit(gnsdk_javaJNI.GnTrackEdit_creditAdd(swigCPtr, this), true);
  }

  public GnCreditEdit credit(long ord) throws com.gracenote.gnsdk.GnException {
    return new GnCreditEdit(gnsdk_javaJNI.GnTrackEdit_credit(swigCPtr, this, ord), true);
  }

/** 
* 
*  Create an empty object of {@link GnAudioWorkEdit} using AUDIO WORK. 
*  @return {@link GnAudioWorkEdit} 
*/ 
 
  public GnAudioWorkEdit audioWork() throws com.gracenote.gnsdk.GnException {
    return new GnAudioWorkEdit(gnsdk_javaJNI.GnTrackEdit_audioWork(swigCPtr, this), true);
  }

  public void mood(GnListElement moodElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnTrackEdit_mood(swigCPtr, this, GnListElement.getCPtr(moodElement), moodElement);
  }

  public void tempo(GnListElement tempoElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnTrackEdit_tempo(swigCPtr, this, GnListElement.getCPtr(tempoElement), tempoElement);
  }

  public void genre(GnListElement genreElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnTrackEdit_genre(swigCPtr, this, GnListElement.getCPtr(genreElement), genreElement);
  }

/** 
* 
*  Sets a list-based value by the list item Submit ID for YEAR. If the value does not 
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the 
*   value is deleted. 
*  @param value set Value corresponding to the specified {@link GnDataObject} value key 
*  <p><b>Remarks:</b></p> 
*  Use this function to set a list-based Submit ID to YEAR, prior to adding the {@link GnDataObject} to a 
*   parcel. 
*/ 
 
  public String year() {
    return gnsdk_javaJNI.GnTrackEdit_year__SWIG_0(swigCPtr, this);
  }

  public void year(String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnTrackEdit_year__SWIG_1(swigCPtr, this, value);
  }

}
