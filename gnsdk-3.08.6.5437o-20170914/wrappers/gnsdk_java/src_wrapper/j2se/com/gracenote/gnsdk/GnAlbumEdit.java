
package com.gracenote.gnsdk;

/** 
* 
*  represents  Album's information returned by Gracenote. 
*/ 
 
public class GnAlbumEdit extends GnDataObject {
  private transient long swigCPtr;

  protected GnAlbumEdit(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnAlbumEdit_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnAlbumEdit obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnAlbumEdit(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GnAlbum gnAlbum() {
    return new GnAlbum(gnsdk_javaJNI.GnAlbumEdit_gnAlbum(swigCPtr, this), true);
  }

  public void genre(GnListElement genreElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnAlbumEdit_genre(swigCPtr, this, GnListElement.getCPtr(genreElement), genreElement);
  }

/** 
* 
*  Create an empty object of {@link GnTitleEdit} using TITLE OFFICIAL. 
*  @return {@link GnTitleEdit} 
*/ 
 
  public GnTitleEdit title() throws com.gracenote.gnsdk.GnException {
    return new GnTitleEdit(gnsdk_javaJNI.GnAlbumEdit_title(swigCPtr, this), true);
  }

/** 
* 
*  Create an empty object of {@link GnArtistEdit} using ARTIST. 
*  @return {@link GnArtistEdit} 
*/ 
 
  public GnArtistEdit artist() throws com.gracenote.gnsdk.GnException {
    return new GnArtistEdit(gnsdk_javaJNI.GnAlbumEdit_artist(swigCPtr, this), true);
  }

  public void language(GnListElement langElement) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnAlbumEdit_language(swigCPtr, this, GnListElement.getCPtr(langElement), langElement);
  }

/** 
* 
*  Sets a list-based value by the list item Submit ID for TOC ALBUM. If the value does not 
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the 
*   value is deleted. 
*  @param value set Value corresponding to the specified {@link GnDataObject} value key 
*  <p><b>Remarks:</b></p> 
*  Use this function to set a list-based Submit ID to TOC ALBUM, prior to adding the {@link GnDataObject} to a 
*   parcel. 
*/ 
 
  public String cdToc() {
    return gnsdk_javaJNI.GnAlbumEdit_cdToc__SWIG_0(swigCPtr, this);
  }

  public void cdToc(String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnAlbumEdit_cdToc__SWIG_1(swigCPtr, this, value);
  }

/** 
* 
*  Sets a list-based value by the list item Submit ID for album_lable . If the value does not 
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the 
*   value is deleted. 
*  @param value set Value corresponding to the specified {@link GnDataObject} value key 
*  <p><b>Remarks:</b></p> 
*  Use this function to set a list-based Submit ID to album_lable , prior to adding the {@link GnDataObject} to a 
*   parcel. 
*/ 
 
  public String label() {
    return gnsdk_javaJNI.GnAlbumEdit_label__SWIG_0(swigCPtr, this);
  }

  public void label(String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnAlbumEdit_label__SWIG_1(swigCPtr, this, value);
  }

/** 
* 
*  Sets the volume number of disc in a multi-disc set 
*  @param discNumber set to the volume number of this disc 
*  @param totalDiscs set to the total discs in volume 
*  <p><b>Remarks:</b></p> 
*  Use this function to set a list-based Submit ID to DISC_IN_SET, prior to adding the {@link GnDataObject} to a 
*   parcel. 
*/ 
 
  public long discInSet() {
    return gnsdk_javaJNI.GnAlbumEdit_discInSet__SWIG_0(swigCPtr, this);
  }

  public void discInSet(long discNumber) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnAlbumEdit_discInSet__SWIG_1(swigCPtr, this, discNumber);
  }

  public long totalInSet() {
    return gnsdk_javaJNI.GnAlbumEdit_totalInSet__SWIG_0(swigCPtr, this);
  }

  public void totalInSet(long totalDiscs) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnAlbumEdit_totalInSet__SWIG_1(swigCPtr, this, totalDiscs);
  }

/** 
* 
*  Sets a list-based value by the list item Submit ID for ALBUM_COMPILATION . If the value does not 
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the 
*   value is deleted. 
*  @param value set Value corresponding to the specified {@link GnDataObject} value key 
*  <p><b>Remarks:</b></p> 
*  Use this function to set a list-based Submit ID to ALBUM_COMPILATION, prior to adding the {@link GnDataObject} to a 
*   parcel. 
*/ 
 
  public boolean isCompilation() {
    return gnsdk_javaJNI.GnAlbumEdit_isCompilation__SWIG_0(swigCPtr, this);
  }

  public void isCompilation(boolean bIsCompilation) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnAlbumEdit_isCompilation__SWIG_1(swigCPtr, this, bIsCompilation);
  }

/** 
* 
*  Sets a list-based value by the list item Submit ID for CLASSICAL_DATA. If the value does not 
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the 
*   value is deleted. 
*  @param value set Value corresponding to the specified {@link GnDataObject} value key 
*  <p><b>Remarks:</b></p> 
*  Use this function to set a list-based Submit ID to CLASSICAL_DATA, prior to adding the {@link GnDataObject} to a 
*   parcel. 
*/ 
 
  public boolean isClassical() {
    return gnsdk_javaJNI.GnAlbumEdit_isClassical__SWIG_0(swigCPtr, this);
  }

  public void isClassical(boolean bIsClassical) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnAlbumEdit_isClassical__SWIG_1(swigCPtr, this, bIsClassical);
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
    return gnsdk_javaJNI.GnAlbumEdit_year__SWIG_0(swigCPtr, this);
  }

  public void year(String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnAlbumEdit_year__SWIG_1(swigCPtr, this, value);
  }

/** 
* 
*  Create an empty object of {@link GnTrackEdit} using TRACK. 
*  @return {@link GnTrackEdit} 
*/ 
 
  public GnTrackEdit track(long trackNum) throws com.gracenote.gnsdk.GnException {
    return new GnTrackEdit(gnsdk_javaJNI.GnAlbumEdit_track(swigCPtr, this, trackNum), true);
  }

  public GnTrackEditIterable tracks() {
    return new GnTrackEditIterable(gnsdk_javaJNI.GnAlbumEdit_tracks(swigCPtr, this), true);
  }

/** 
* 
*  Create an empty object of {@link GnCreditEdit} using CREDIT. 
*  @return {@link GnCreditEdit} 
*/ 
 
  public GnCreditEdit creditAdd() throws com.gracenote.gnsdk.GnException {
    return new GnCreditEdit(gnsdk_javaJNI.GnAlbumEdit_creditAdd(swigCPtr, this), true);
  }

  public GnCreditEdit credit(long ord) throws com.gracenote.gnsdk.GnException {
    return new GnCreditEdit(gnsdk_javaJNI.GnAlbumEdit_credit(swigCPtr, this, ord), true);
  }

}
