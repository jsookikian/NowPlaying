
package com.gracenote.gnsdk;

/** 
** Configures query for {@link GnMusicIdBatch} 
*/ 
 
public class GnMusicIdBatchQuery {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnMusicIdBatchQuery(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnMusicIdBatchQuery obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnMusicIdBatchQuery(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

/** 
*  Constructs a batch music identification query object with a unique identifier 
*  @param batch		[in] {@link GnMusicIdBatch} object to use with query 
*  @param unique_id	[in] Unique identifier for batch query 
*/ 
 
  public GnMusicIdBatchQuery(GnMusicIdBatch batch, String uniqueId) throws com.gracenote.gnsdk.GnException {
    this(gnsdk_javaJNI.new_GnMusicIdBatchQuery(GnMusicIdBatch.getCPtr(batch), batch, uniqueId), true);
  }

/** 
*  Sets externally- and internally-generated Gracenote fingerprint 
*  fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint data. 
*	Use with GnMusicIdBatch::GetAlbums 
*  @param strFingerprintData	[in] Audio source to fingerprint 
*  @param fpType				[in] One of the {@link GnFingerprintType} fingerprint data types, 
*/ 
 
  public void setFingerprint(String strFingerprintData, GnFingerprintType fpType) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchQuery_setFingerprint(swigCPtr, this, strFingerprintData, fpType.swigValue());
  }

/** 
*  Sets metadata::GnDataObject, use with GnMusicIdBatch::GetAlbums 
*  @param gnObj				[in] An metadata::GnDataObject object 
*/ 
 
  public void setGDO(GnDataObject gnObj) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchQuery_setGDO(swigCPtr, this, GnDataObject.getCPtr(gnObj), gnObj);
  }

/** 
*  Sets text string, use with GnMusicIdBatch::GetAlbums and GnMusicIdBatch::GetMatches 
*  @param albumTitle			[in] Album title string 
*  @param trackTitle			[in] Track title string 
*  @param albumArtistName		[in] Album artist string 
*  @param trackArtistName		[in] Track artist string 
*  @param composerName			[in] Composer string 
*/ 
 
  public void setText(String albumTitle, String trackTitle, String albumArtistName, String trackArtistName, String composerName) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchQuery_setText(swigCPtr, this, albumTitle, trackTitle, albumArtistName, trackArtistName, composerName);
  }

/** 
*  Sets TOC Offset 
*  @param strCDTOC				[in] CD TOC string 
*/ 
 
  public void setTOCOffset(long tocOffset) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchQuery_setTOCOffset(swigCPtr, this, tocOffset);
  }

/** 
*  Sets CDTOC string, use with GnMusicIdBatch::GetAlbums 
*  @param strCDTOC				[in] CD TOC string 
*/ 
 
  public void setTOC(String strTOC) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchQuery_setTOC(swigCPtr, this, strTOC);
  }

}
