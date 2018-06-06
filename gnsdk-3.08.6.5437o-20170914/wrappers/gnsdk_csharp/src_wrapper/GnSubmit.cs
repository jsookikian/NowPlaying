
namespace GracenoteSDK {

/**
*  @internal GnSubmit @endinternal
*  represents  Object's information returned by Gracenote.
*/
public class GnSubmit : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnSubmit(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnSubmit obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnSubmit() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnSubmit(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/******************************************************************************
* Submit Parcel Handle - for the life of the Submit parcel
******************************************************************************//**
*  @internal GnSubmit @endinternal
*  Creates a handle to a parcel. A single parcel can contain multiple types of data.
*  @param user set User handle for the user making the submit request
*  <p><b>Remarks:</b></p>
*  Use this function to create an empty, editable parcel for subsequent uploading to Gracenote
*   Service.
*/
  public GnSubmit(GnUser user, GnStatusEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnSubmit__SWIG_0(GnUser.getCPtr(user), GnStatusEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnSubmit(GnUser user) : this(gnsdk_csharp_marshalPINVOKE.new_GnSubmit__SWIG_1(GnUser.getCPtr(user)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  @internal AlbumEditNew @endinternal
*  Creates an editable GnDataObject to submit data for TYPE_ALBUM.
*  @param numTracks - is the number of tracks
*  <p><b>Remarks:</b></p>
*  Use this function to create an editable GnDataObject from a GnDataObject context (TYPE_ALBUM).
*/
  public GnAlbumEdit AlbumEditFromEmpty(uint numTracks) {
    GnAlbumEdit ret = new GnAlbumEdit(gnsdk_csharp_marshalPINVOKE.GnSubmit_AlbumEditFromEmpty(swigCPtr, numTracks), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  @internal AlbumEditFromAlbum @endinternal
*  Creates an editable GnDataObject with data derived from a source GnDataObject.
*  @param GnAlbum
*  @return GnAlbumEdit
*  <p><b>Remarks:</b></p>
*  Use this function to create an editable GnDataObject from a source GnDataObject (TYPE_ALBUM). The
*   editable GnDataObject is essentially a close copy (but not a clone) of the source GnDataObject, containing the
*   metadata that is editable.
* <p><b>Note:</b></p>
*  After the function has completed processing, the child's GnDataObject handle must be released
*/
  public GnAlbumEdit AlbumEdit(GnAlbum album) {
    GnAlbumEdit ret = new GnAlbumEdit(gnsdk_csharp_marshalPINVOKE.GnSubmit_AlbumEdit(swigCPtr, GnAlbum.getCPtr(album)), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  @internal AlbumEditFromXml @endinternal
*  Creates an editable GnDataObject with data parsed from pre-populated, GnDataObject-formatted XML.
*  @param album_xml set Source XML for data used to create a new editable GnDataObject
*  @return GnAlbumEdit
*  <p><b>Remarks:</b></p>
*  Use this function to create an editable GnDataObject from a specified source of pre-populated and GnDataObject
*	-formatted XML data (GNSDK_GDO_TYPE_ALBUM). The editable GnDataObject is essentially a close copy (but not
* a clone) of the source XML, containing only editable metadata.
*/
  public GnAlbumEdit AlbumEditFromXml(string albumXml) {
    GnAlbumEdit ret = new GnAlbumEdit(gnsdk_csharp_marshalPINVOKE.GnSubmit_AlbumEditFromXml(swigCPtr, albumXml), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  @internal AlbumEditFromCDTOC @endinternal
*  Creates an editable Album GnDataObject to submit data for a specific GnDataObject context. The album comes
* pre-populated with the correct number of track children, but no metadata.
*  @param toc set CD TOC string
*  @return GnAlbumEdit
*  <p><b>Remarks:</b></p>
*  Use this function to create an editable album GnDataObject with the correct number of track children, as
*  derived from the TOC.
*  The children are empty, and do not have metadata. You must enter all the children's metadata.
*/
  public GnAlbumEdit AlbumEditFromCdToc(string cdtoc) {
    GnAlbumEdit ret = new GnAlbumEdit(gnsdk_csharp_marshalPINVOKE.GnSubmit_AlbumEditFromCdToc(swigCPtr, cdtoc), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/******************************************************************************
* Submit Parcel audio Feature APIs - for the generation and submission of
* features generated from audio streams.
******************************************************************************//**
*  @internal DataInitFeature @endinternal
*  Prepares a parcel for gathering and generating features.
*  @param dataObject set Handle to a GnDataObject; note that these are generally not editable GDOs
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
  public bool IsAudioProcessNeeded(GnAlbum album, bool bSubmitTestMode) {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnSubmit_IsAudioProcessNeeded(swigCPtr, GnAlbum.getCPtr(album), bSubmitTestMode);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  @internal AudioProcessInit @endinternal
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
  public void AudioProcessInit(GnTrack track, uint audioRate, GnSubmitAudioFormat audioFormat, uint audioChannels) {
    gnsdk_csharp_marshalPINVOKE.GnSubmit_AudioProcessInit(swigCPtr, GnTrack.getCPtr(track), audioRate, (int)audioFormat, audioChannels);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void AudioSourceDetails(GnDataObject dataObject, GnSubmitFeatureSourceName name, GnSubmitFeatureSourceId id, GnSubmitFeatureSourceDescription desc, GnSubmitFeatureSourceBitRate bitrate, GnSubmitFeatureSourceBitRateType bitrate_type) {
    gnsdk_csharp_marshalPINVOKE.GnSubmit_AudioSourceDetails(swigCPtr, GnDataObject.getCPtr(dataObject), (int)name, (int)id, (int)desc, (int)bitrate, (int)bitrate_type);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public bool AudioProcessWrite(GnTrack track, byte[] audioData, uint audioData_bytes) {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnSubmit_AudioProcessWrite(swigCPtr, GnTrack.getCPtr(track), audioData, audioData_bytes);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  @internal FeatureFinalize @endinternal
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
  public void AudioProcessFinalize(GnTrack track, bool bAborted) {
    gnsdk_csharp_marshalPINVOKE.GnSubmit_AudioProcessFinalize(swigCPtr, GnTrack.getCPtr(track), bAborted);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  @internal ParcelAdd @endinternal
*  Adds a GnDataObject containing metadata to a parcel for submission to Gracenote Service.
*  @param dataObject set Handle to a GnDataObject of a supported context
*  <p><b>Remarks:</b></p>
*  Use this function to add a GnDataObject to a parcel prior to subsequently uploading the parcel to
* Gracenote Service, such as passing in an editable Album GnDataObject with metadata to a parcel.
*/
  public void ParcelAdd(GnDataObject dataObject) {
    gnsdk_csharp_marshalPINVOKE.GnSubmit_ParcelAdd(swigCPtr, GnDataObject.getCPtr(dataObject));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  @internal Upload @endinternal
*  Uploads a parcel to Gracenote Service.
*  @param flags set An available Submit parcel flag
*  @return GnSubmitState
*  <p><b>Remarks:</b></p>
*  Use this function to submit a completed parcel to Gracenote Service.
*  If your application receives an error or aborts while calling the finalization function, be sure the application calls the upload function. This
* ensures sending important information to Gracenote that is useful for error resolution.
*/
  public GnSubmitState ParcelUpload(bool bSubmitTestMode) {
    GnSubmitState ret = (GnSubmitState)gnsdk_csharp_marshalPINVOKE.GnSubmit_ParcelUpload(swigCPtr, bSubmitTestMode);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnStatusEventsDelegate EventHandler() {
    global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnSubmit_EventHandler(swigCPtr);
    GnStatusEventsDelegate ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnStatusEventsDelegate(cPtr, false);
    return ret;
  }

  public void SetCancel(bool cancel) {
    gnsdk_csharp_marshalPINVOKE.GnSubmit_SetCancel(swigCPtr, cancel);
  }

  public bool IsCancelled() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnSubmit_IsCancelled(swigCPtr);
    return ret;
  }

  public string Version {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnSubmit_Version_get(swigCPtr) );
	} 

  }

  public string BuildDate {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnSubmit_BuildDate_get(swigCPtr) );
	} 

  }

}

}
