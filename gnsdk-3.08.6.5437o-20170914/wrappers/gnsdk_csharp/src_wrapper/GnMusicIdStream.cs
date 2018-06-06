
namespace GracenoteSDK {

/**
*
* GnMusicIdStream provides services for identifying music within a continuous audio stream.
* As data is received from the audio stream, it is provided to GnMusicIdStream, when the application
* wishes to identify the audio it initializes an identification. The results of the identification
* are delivered asynchronously to a delegate object.
*
* <p><b>SDK Documentation</b></p>
*
* <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Streaming Music
*
* For more information on using MusicID-Stream/Radio, see the above topic which covers:
* <ul>
*     <li>General information about identifying streaming music</li>
*     <li>How to identify streaming audio from an audio source (IGnAudioSource implementation)</li>
*     <li>Setting options for streaming audio queries</li>
*     <li>Music-ID Stream/Radio code samples</li>
* </ul>
*
* <b>Sample App</b>
*
*     - .../samples/musicid_stream_manual
*
* <p><b>Overview</b></p>
*
* <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID Radio
*
* Note: Customers must be licensed to implement use of a MusicID product in an application.
* Contact your Gracenote support representative with questions about product licensing and
* entitlement.
*/
public class GnMusicIdStream : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMusicIdStream(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMusicIdStream obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMusicIdStream() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMusicIdStream(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
*  Establishes an audio stream identification object with locale. The locale is used to determine
*  the preferred language and script of stream identification results.
*  Note: Results are only returned in preferred language and script where available.
*  @param user 			[in] Gracenote user
*  @param preset 			[in] Gracenote musicID stream preset
*  @param locale 			[in] Gracenote locale
*  @param pEventDelegate 	[in] Audio processing and identification query events handler
*/
  public GnMusicIdStream(GnUser user, GnMusicIdStreamPreset preset, GnLocale locale, GnMusicIdStreamEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdStream__SWIG_0(GnUser.getCPtr(user), (int)preset, GnLocale.getCPtr(locale), GnMusicIdStreamEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Establishes an audio stream identification object with locale. The locale is used determine
*  the preferred language and script of stream identification results.
*  Note: Results are only returned in preferred language and script where available.
*  @param user 			[in] Gracenote user
*  @param preset			[in] Gracenote musicID stream preset
*  @param pEventDelegate 	[in] Audio processing and identification query events handler
*/
  public GnMusicIdStream(GnUser user, GnMusicIdStreamPreset preset, GnMusicIdStreamEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdStream__SWIG_1(GnUser.getCPtr(user), (int)preset, GnMusicIdStreamEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Retrieves the MusicID-Stream SDK's version string.
*  @return Version string if successful
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully establishing a MusicID-Stream audio channel.
*  The returned string is a constant. Do not attempt to modify or delete.
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
*/
  public static string Version() {
	System.IntPtr temp = gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_Version(); 
	return GnMarshalUTF8.StringFromNativeUtf8(temp);
}

/**
*  Retrieves the MusicID-Stream SDK's build date string.
*  @return Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully establishing a MusicID-Stream audio channel.
*  The returned string is a constant. Do not attempt to modify or delete.
*  Example build date string: 2008-02-12 00:41 UTC
*/
  public static string BuildDate() {
	System.IntPtr temp = gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_BuildDate(); 
	return GnMarshalUTF8.StringFromNativeUtf8(temp);
}

/**
* Get GnMusicIdStream options object. Use to configure your GnMusicIdStream instance.
* @return Options objects
*/
  public GnMusicIdStreamOptions Options() {
    GnMusicIdStreamOptions ret = new GnMusicIdStreamOptions(gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_Options(swigCPtr), false);
    return ret;
  }

/**
* Commence retrieving and processing audio from an object implementing the audio source interface.
* This is an alternate and often simpler method for providing audio to GnMusicIdStream
* instead of calling AudioProcessStart (audio format overload) and AudioProcess.
* To use this method the audio source to be identified must be accessible via an IGnAudioSource
* implementation. Custom implementations of IGnAudioSource are encouraged.
* Note: audio is retrieved from the audio source in a loop so some applications may wish to start
* automatic audio processing in a background thread to avoid stalling the main thread.
* @param audioSource	[in] Audio source to be identified
*/
  public void AudioProcessStart(IGnAudioSource audioSource) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_AudioProcessStart__SWIG_0(swigCPtr, IGnAudioSource.getCPtr(audioSource));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Initialize manual delivery of audio stream audio to GnMusicIdStream. GnMusicIdStream
* establishes buffers and audio processing modules, readying itself to receive audio.
* @param samplesPerSecond	[in] Number of samples per second
* @param bitsPerSample		[in] Number of bits per sample
* @param numberOfChannels	[in] Number of channels
*/
  public void AudioProcessStart(uint samplesPerSecond, uint bitsPerSample, uint numberOfChannels) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_AudioProcessStart__SWIG_1(swigCPtr, samplesPerSecond, bitsPerSample, numberOfChannels);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Stops audio processing. If audio processing was started with an object implementing IGnAudioSource
* the audio source is closed and data is no longer retrieved from that source. If manual audio processing
* was used future attempts to write audio data for processing will fail.
*/
  public void AudioProcessStop() {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_AudioProcessStop(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void AudioProcess(byte[] audioData, uint audioDataLength) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_AudioProcess(swigCPtr, audioData, audioDataLength);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* @deprecated Will be removed next release, use IdentifyAlbumAsync and WaitForIdentify instead.
* Identifying the audio in the audio stream and blocks until identification is
* complete. Results are delivered asynchronously via IGnMusicIdStreamEvents delegate.
*/
  public void IdentifyAlbum() {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_IdentifyAlbum(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Identifying the audio in the audio stream. Results are delivered
* asynchronously via IGnMusicIdStreamEvents delegate.
*/
  public void IdentifyAlbumAsync() {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_IdentifyAlbumAsync(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Wait for currently running identify call to complete (up to timeout_ms milliseconds).
* Returns true if identification completed in the timeout period, false if not
* @param timeout_ms	[in] Timeout in milliseconds
* @return true			True if completed, false if timed out
*/
  public bool WaitForIdentify(uint timeout_ms) {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_WaitForIdentify(swigCPtr, timeout_ms);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Cancel the current identify operation blocking until the identification has stopped.
* Cannot be called from within a GnMusicIdStream delegate callback, use the canceller provided
* in the callback instead. 
*/
  public void IdentifyCancel() {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_IdentifyCancel(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* @deprecated NB: Automatic mode will be removed in future release. Do not use.
* Specifies automatic recognition should be enabled or disabled
* @param bEnable 	[in] Option, default is false. True to enable, false to disable
*
*/
  public void AutomaticIdentification(bool bEnable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_AutomaticIdentification__SWIG_0(swigCPtr, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* @deprecated NB: Automatic mode will be removed in future release. Do not use.
* Specifies automatic recognition is enabled or disabled
* @return true			True if automatic recognition is enabled
*
*/
  public bool AutomaticIdentification() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_AutomaticIdentification__SWIG_1(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* @deprecated NB: Automatic mode for radio stream identification will be removed in future release. Do not use.
* Provide text accompanying the channel stream to a query handle for improved match resolution
* @param textKey 		[in] A input type from the available MusicIDStream Text Keys
* @param textValue 	[in] A string value that corresponds to the defined text key
*
*/
  public void Text(GnMusicIdStreamText textKey, string textValue) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_Text(swigCPtr, (int)textKey, textValue);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* @deprecated NB: Automatic mode for radio stream identification will be removed in future release. Do not use.
* Returns real clock time duration remaining before next query takes place when automatic recognition mode is turned on.
* @param queryTimeLeft	[out[ Duration in ms left before next query.
*
*/
  public GnString NextQueryTime() {
    GnString ret = new GnString(gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_NextQueryTime(swigCPtr), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Get the event handler provided on construction
* @return Event handler
*/
  public GnMusicIdStreamEventsDelegate EventHandler() {
    global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_EventHandler(swigCPtr);
    GnMusicIdStreamEventsDelegate ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnMusicIdStreamEventsDelegate(cPtr, false);
    return ret;
  }

/**
*  Returns information about the GnMusicIdStream instance
*  @param key		[in] Information key
*  @return GnString containing the requested information
*/
  public GnString InfoGet(string key) {
    GnString ret = new GnString(gnsdk_csharp_marshalPINVOKE.GnMusicIdStream_InfoGet(swigCPtr, key), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
