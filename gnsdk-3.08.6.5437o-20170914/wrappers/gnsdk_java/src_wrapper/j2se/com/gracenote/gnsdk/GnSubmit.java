
package com.gracenote.gnsdk;

/** 
* 
*  represents  Object's information returned by Gracenote. 
*/ 
 
public class GnSubmit {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnSubmit(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnSubmit obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnSubmit(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

	private IGnStatusEvents pEventHandler;
	private IGnStatusEventsProxyU eventHandlerProxy;

/****************************************************************************** 
* Submit Parcel Handle - for the life of the Submit parcel 
******************************************************************************//** 
* 
*  Creates a handle to a parcel. A single parcel can contain multiple types of data. 
*  @param user set User handle for the user making the submit request 
*  <p><b>Remarks:</b></p> 
*  Use this function to create an empty, editable parcel for subsequent uploading to Gracenote 
*   Service. 
*/ 
 
  public GnSubmit(GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnSubmit__SWIG_0(GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnSubmit(GnUser user) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnSubmit__SWIG_1(GnUser.getCPtr(user), user);
}

  public static String version() {
    return gnsdk_javaJNI.GnSubmit_version();
  }

  public static String buildDate() {
    return gnsdk_javaJNI.GnSubmit_buildDate();
  }

/** 
* 
*  Creates an editable {@link GnDataObject} to submit data for TYPE_ALBUM. 
*  @param numTracks - is the number of tracks 
*  <p><b>Remarks:</b></p> 
*  Use this function to create an editable {@link GnDataObject} from a {@link GnDataObject} context (TYPE_ALBUM). 
*/ 
 
  public GnAlbumEdit albumEditFromEmpty(long numTracks) throws com.gracenote.gnsdk.GnException {
    return new GnAlbumEdit(gnsdk_javaJNI.GnSubmit_albumEditFromEmpty(swigCPtr, this, numTracks), true);
  }

/** 
* 
*  Creates an editable {@link GnDataObject} with data derived from a source {@link GnDataObject}. 
*  @param {@link GnAlbum} 
*  @return {@link GnAlbumEdit} 
*  <p><b>Remarks:</b></p> 
*  Use this function to create an editable {@link GnDataObject} from a source {@link GnDataObject} (TYPE_ALBUM). The 
*   editable {@link GnDataObject} is essentially a close copy (but not a clone) of the source {@link GnDataObject}, containing the 
*   metadata that is editable. 
* <p><b>Note:</b></p> 
*  After the function has completed processing, the child's {@link GnDataObject} handle must be released 
*/ 
 
  public GnAlbumEdit albumEdit(GnAlbum album) throws com.gracenote.gnsdk.GnException {
    return new GnAlbumEdit(gnsdk_javaJNI.GnSubmit_albumEdit(swigCPtr, this, GnAlbum.getCPtr(album), album), true);
  }

/** 
* 
*  Creates an editable {@link GnDataObject} with data parsed from pre-populated, GnDataObject-formatted XML. 
*  @param album_xml set Source XML for data used to create a new editable {@link GnDataObject} 
*  @return {@link GnAlbumEdit} 
*  <p><b>Remarks:</b></p> 
*  Use this function to create an editable {@link GnDataObject} from a specified source of pre-populated and {@link GnDataObject} 
*	-formatted XML data (GNSDK_GDO_TYPE_ALBUM). The editable {@link GnDataObject} is essentially a close copy (but not 
* a clone) of the source XML, containing only editable metadata. 
*/ 
 
  public GnAlbumEdit albumEditFromXml(String albumXml) throws com.gracenote.gnsdk.GnException {
    return new GnAlbumEdit(gnsdk_javaJNI.GnSubmit_albumEditFromXml(swigCPtr, this, albumXml), true);
  }

/** 
* 
*  Creates an editable Album {@link GnDataObject} to submit data for a specific {@link GnDataObject} context. The album comes 
* pre-populated with the correct number of track children, but no metadata. 
*  @param toc set CD TOC string 
*  @return {@link GnAlbumEdit} 
*  <p><b>Remarks:</b></p> 
*  Use this function to create an editable album {@link GnDataObject} with the correct number of track children, as 
*  derived from the TOC. 
*  The children are empty, and do not have metadata. You must enter all the children's metadata. 
*/ 
 
  public GnAlbumEdit albumEditFromCdToc(String cdtoc) throws com.gracenote.gnsdk.GnException {
    return new GnAlbumEdit(gnsdk_javaJNI.GnSubmit_albumEditFromCdToc(swigCPtr, this, cdtoc), true);
  }

/****************************************************************************** 
* Submit Parcel audio Feature APIs - for the generation and submission of 
* features generated from audio streams. 
******************************************************************************//** 
* 
*  Prepares a parcel for gathering and generating features. 
*  @param dataObject set Handle to a {@link GnDataObject}; note that these are generally not editable GDOs 
*  @param flags set One of the available Submit Parcel Flags 
*  @return bool 
*  <p><b>Remarks:</b></p> 
*  Use this function to initialize the generation process for features contained in a parcel; this 
* enables Gracenote Service to determine if it requires specific feature data from the parcel, such as 
* a particular audio stream (Track). 
*  The function first checks whether the application's license has been enabled for Submit. If not, 
* the function cancels. 
*  You can submit Track feature data only for Album GDOs that are generated from a TOC lookup. For 
* an example of performing a TOC lookup, see Example: MusicID TOC Lookup. 
*  <p><b>Important:</b></p> 
*  Be sure to call DataInitFeature only once per Album. 
*/ 
 
  public boolean isAudioProcessNeeded(GnAlbum album, boolean bSubmitTestMode) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnSubmit_isAudioProcessNeeded(swigCPtr, this, GnAlbum.getCPtr(album), album, bSubmitTestMode);
  }

/** 
* 
*  Initializes the generation of features for a specific audio stream. 
*  @param track_num set Ordinal for the audio stream (for albums, this is the track number) 
*  @param audio_rate set Sample rate of audio to be provided ( for example: 44100) 
*  @param audio_format set The audio format 
*  @param audio_channels set Number of channels for audio to be provided (for example: 2) 
*  <p><b>Remarks:</b></p> 
*  Use this function to initialize the generation of a specific audio stream (track). You must 
* ensure the following successfully happens before calling this function: 
*  Calling the DataInitFeature function, so the Gracenote Service can 
* identify which audio streams require processing. 
*  Initializing the DSP library, in preparation for track fingerprint generation. 
*/ 
 
  public void audioProcessInit(GnTrack track, long audioRate, GnSubmitAudioFormat audioFormat, long audioChannels) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnSubmit_audioProcessInit(swigCPtr, this, GnTrack.getCPtr(track), track, audioRate, audioFormat.swigValue(), audioChannels);
  }

  public void audioSourceDetails(GnDataObject dataObject, GnSubmitFeatureSourceName name, GnSubmitFeatureSourceId id, GnSubmitFeatureSourceDescription desc, GnSubmitFeatureSourceBitRate bitrate, GnSubmitFeatureSourceBitRateType bitrate_type) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnSubmit_audioSourceDetails(swigCPtr, this, GnDataObject.getCPtr(dataObject), dataObject, name.swigValue(), id.swigValue(), desc.swigValue(), bitrate.swigValue(), bitrate_type.swigValue());
  }

/** 
* 
*  Processes audio stream data contained in a parcel. 
*  @param audioData set Pointer to audio data buffer that matches the audio format described 
*  @param audioData_bytes set Number of audio data bytes in this sample 
*  @param bool 
*  <p><b>Remarks:</b></p> 
*  Use this function to pass in a parcel's audio data for processing. 
*/ 
 
  public boolean audioProcessWrite(GnTrack track, byte[] audioData, long audioData_bytes) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnSubmit_audioProcessWrite(swigCPtr, this, GnTrack.getCPtr(track), track, audioData, audioData_bytes);
  }

/** 
* 
*  Finalizes the processing of the audio for the given stream. 
*  @param abort set Boolean value to indicate whether the finalization process must stop operating, 
* due to processing errors 
*  <p><b>Remarks:</b></p> 
*  Use this function to finalize write processing for a feature. This function must be called before 
* the feature can be uploaded. 
*  If your application receives an error or aborts while calling this function, be sure the 
* application calls the upload function (upload). This ensures sending important 
* information to Gracenote that is useful for error resolution. 
*/ 
 
  public void audioProcessFinalize(GnTrack track, boolean bAborted) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnSubmit_audioProcessFinalize(swigCPtr, this, GnTrack.getCPtr(track), track, bAborted);
  }

/** 
* 
*  Adds a {@link GnDataObject} containing metadata to a parcel for submission to Gracenote Service. 
*  @param dataObject set Handle to a {@link GnDataObject} of a supported context 
*  <p><b>Remarks:</b></p> 
*  Use this function to add a {@link GnDataObject} to a parcel prior to subsequently uploading the parcel to 
* Gracenote Service, such as passing in an editable Album {@link GnDataObject} with metadata to a parcel. 
*/ 
 
  public void parcelAdd(GnDataObject dataObject) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnSubmit_parcelAdd(swigCPtr, this, GnDataObject.getCPtr(dataObject), dataObject);
  }

/** 
* 
*  Uploads a parcel to Gracenote Service. 
*  @param flags set An available Submit parcel flag 
*  @return {@link GnSubmitState} 
*  <p><b>Remarks:</b></p> 
*  Use this function to submit a completed parcel to Gracenote Service. 
*  If your application receives an error or aborts while calling the finalization function, be sure the application calls the upload function. This 
* ensures sending important information to Gracenote that is useful for error resolution. 
*/ 
 
  public GnSubmitState parcelUpload(boolean bSubmitTestMode) throws com.gracenote.gnsdk.GnException {
    return GnSubmitState.swigToEnum(gnsdk_javaJNI.GnSubmit_parcelUpload(swigCPtr, this, bSubmitTestMode));
  }

  public IGnStatusEvents eventHandler() {
	return pEventHandler;
}

  public void setCancel(boolean cancel) {
    gnsdk_javaJNI.GnSubmit_setCancel(swigCPtr, this, cancel);
  }

  public boolean isCancelled() {
    return gnsdk_javaJNI.GnSubmit_isCancelled(swigCPtr, this);
  }

}
