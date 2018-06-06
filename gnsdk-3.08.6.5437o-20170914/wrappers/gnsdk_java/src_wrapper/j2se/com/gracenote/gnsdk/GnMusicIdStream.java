
package com.gracenote.gnsdk;

/** 
* <p> 
* {@link GnMusicIdStream} provides services for identifying music within a continuous audio stream. 
* As data is received from the audio stream, it is provided to {@link GnMusicIdStream}, when the application 
* wishes to identify the audio it initializes an identification. The results of the identification 
* are delivered asynchronously to a delegate object. 
* <p> 
* <p><b>SDK Documentation</b></p> 
* <p> 
* <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Streaming Music 
* <p> 
* For more information on using MusicID-Stream/Radio, see the above topic which covers: 
* <ul> 
*     <li>General information about identifying streaming music</li> 
*     <li>How to identify streaming audio from an audio source (IGnAudioSource implementation)</li> 
*     <li>Setting options for streaming audio queries</li> 
*     <li>Music-ID Stream/Radio code samples</li> 
* </ul> 
* <p> 
* <b>Sample App</b> 
* <p> 
*     - .../samples/musicid_stream_manual 
* <p> 
* <p><b>Overview</b></p> 
* <p> 
* <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID Radio 
* <p> 
* Note: Customers must be licensed to implement use of a MusicID product in an application. 
* Contact your Gracenote support representative with questions about product licensing and 
* entitlement. 
*/ 
 
public class GnMusicIdStream {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnMusicIdStream(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnMusicIdStream obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnMusicIdStream(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

	private IGnMusicIdStreamEvents pEventDelegate;
	private IGnMusicIdStreamEventsProxyU eventHandlerProxy;
	private IGnAudioSource audioSource;
	private IGnAudioSourceProxyU audioSourceProxyU;
	private GnLocale locale;
	
/** 
* Provides audio manually for processing by {@link GnMusicIdStream}. 
* This should not be called if 
* audio processing was started with an object implementing the audio source interface. 
* @param audioData			[in] Native data buffer containing sample audio 
*/ 
 
	public void audioProcess(byte[] audioData) throws com.gracenote.gnsdk.GnException {
		this.audioProcess(audioData,(long)audioData.length);
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
 
  public GnMusicIdStream(GnUser user, GnMusicIdStreamPreset preset, GnLocale locale, IGnMusicIdStreamEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnMusicIdStreamEventsProxyU(pEventHandler);
	}
	this.pEventDelegate = pEventHandler; // <REFERENCE_NAME_CHECK><TYPE>IGnMusicIdStreamEvents</TYPE><NAME>pEventDelegate</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	this.locale = locale; 				  // <REFERENCE_NAME_CHECK><TYPE>GnLocale</TYPE><NAME>locale</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicIdStream__SWIG_0(GnUser.getCPtr(user), user, preset.swigValue(), GnLocale.getCPtr(locale), locale, (eventHandlerProxy==null)?0:IGnMusicIdStreamEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

/** 
*  Establishes an audio stream identification object with locale. The locale is used determine 
*  the preferred language and script of stream identification results. 
*  Note: Results are only returned in preferred language and script where available. 
*  @param user 			[in] Gracenote user 
*  @param preset			[in] Gracenote musicID stream preset 
*  @param pEventDelegate 	[in] Audio processing and identification query events handler 
*/ 
 
  public GnMusicIdStream(GnUser user, GnMusicIdStreamPreset preset, IGnMusicIdStreamEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnMusicIdStreamEventsProxyU(pEventHandler);
	}
	this.pEventDelegate = pEventHandler; // <REFERENCE_NAME_CHECK><TYPE>IGnMusicIdStreamEvents</TYPE><NAME>pEventDelegate</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	this.locale = locale; 				  // <REFERENCE_NAME_CHECK><TYPE>GnLocale</TYPE><NAME>locale</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicIdStream__SWIG_1(GnUser.getCPtr(user), user, preset.swigValue(), (eventHandlerProxy==null)?0:IGnMusicIdStreamEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
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
 
  public static String version() {
    return gnsdk_javaJNI.GnMusicIdStream_version();
  }

/** 
*  Retrieves the MusicID-Stream SDK's build date string. 
*  @return Build date string of the format: YYYY-MM-DD hh:mm UTC 
*  <p><b>Remarks:</b></p> 
*  You can call this API at any time after successfully establishing a MusicID-Stream audio channel. 
*  The returned string is a constant. Do not attempt to modify or delete. 
*  Example build date string: 2008-02-12 00:41 UTC 
*/ 
 
  public static String buildDate() {
    return gnsdk_javaJNI.GnMusicIdStream_buildDate();
  }

/** 
* Get {@link GnMusicIdStream} options object. Use to configure your {@link GnMusicIdStream} instance. 
* @return Options objects 
*/ 
 
  public GnMusicIdStreamOptions options() {
    return new GnMusicIdStreamOptions(gnsdk_javaJNI.GnMusicIdStream_options(swigCPtr, this), false);
  }

/** 
* Commence retrieving and processing audio from an object implementing the audio source interface. 
* This is an alternate and often simpler method for providing audio to {@link GnMusicIdStream} 
* instead of calling AudioProcessStart (audio format overload) and AudioProcess. 
* To use this method the audio source to be identified must be accessible via an {@link IGnAudioSource} 
* implementation. Custom implementations of {@link IGnAudioSource} are encouraged. 
* Note: audio is retrieved from the audio source in a loop so some applications may wish to start 
* automatic audio processing in a background thread to avoid stalling the main thread. 
* @param audioSource	[in] Audio source to be identified 
*/ 
 
  public void audioProcessStart(IGnAudioSource audioSource) throws com.gracenote.gnsdk.GnException {
audioSourceProxyU = new IGnAudioSourceProxyU(audioSource);this.audioSource=audioSource; // <REFERENCE_NAME_CHECK><TYPE>IGnAudioSource</TYPE><NAME>audioSource</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
    {
      gnsdk_javaJNI.GnMusicIdStream_audioProcessStart__SWIG_0(swigCPtr, this, IGnAudioSourceProxyL.getCPtr(audioSourceProxyU), audioSourceProxyU);
    }
  }

/** 
* Initialize manual delivery of audio stream audio to {@link GnMusicIdStream}. {@link GnMusicIdStream} 
* establishes buffers and audio processing modules, readying itself to receive audio. 
* @param samplesPerSecond	[in] Number of samples per second 
* @param bitsPerSample		[in] Number of bits per sample 
* @param numberOfChannels	[in] Number of channels 
*/ 
 
  public void audioProcessStart(long samplesPerSecond, long bitsPerSample, long numberOfChannels) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdStream_audioProcessStart__SWIG_1(swigCPtr, this, samplesPerSecond, bitsPerSample, numberOfChannels);
  }

/** 
* Stops audio processing. If audio processing was started with an object implementing {@link IGnAudioSource} 
* the audio source is closed and data is no longer retrieved from that source. If manual audio processing 
* was used future attempts to write audio data for processing will fail. 
*/ 
 
  public void audioProcessStop() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdStream_audioProcessStop(swigCPtr, this);
  }

/** 
* Provides audio manually for processing by {@link GnMusicIdStream}. This should not be called if 
* audio processing was started with an object implementing the audio source interface. 
* @param audioData			[in] Buffer containing sample audio 
* @param audioDataLength	[in] Number of bytes of audio in pAudioBuffer 
*/ 
 
  public void audioProcess(byte[] audioData, long audioDataLength) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdStream_audioProcess__SWIG_0(swigCPtr, this, audioData, audioDataLength);
  }

/** 
* @deprecated Will be removed next release, use IdentifyAlbumAsync and WaitForIdentify instead. 
* Identifying the audio in the audio stream and blocks until identification is 
* complete. Results are delivered asynchronously via {@link IGnMusicIdStreamEvents} delegate. 
*/ 
 
  public void identifyAlbum() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdStream_identifyAlbum(swigCPtr, this);
  }

/** 
* Identifying the audio in the audio stream. Results are delivered 
* asynchronously via {@link IGnMusicIdStreamEvents} delegate. 
*/ 
 
  public void identifyAlbumAsync() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdStream_identifyAlbumAsync(swigCPtr, this);
  }

/** 
* Wait for currently running identify call to complete (up to timeout_ms milliseconds). 
* Returns true if identification completed in the timeout period, false if not 
* @param timeout_ms	[in] Timeout in milliseconds 
* @return true			True if completed, false if timed out 
*/ 
 
  public boolean waitForIdentify(long timeout_ms) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnMusicIdStream_waitForIdentify(swigCPtr, this, timeout_ms);
  }

/** 
* Cancel the current identify operation blocking until the identification has stopped. 
* Cannot be called from within a {@link GnMusicIdStream} delegate callback, use the canceller provided 
* in the callback instead.  
*/ 
 
  public void identifyCancel() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdStream_identifyCancel(swigCPtr, this);
  }

/** 
* @deprecated NB: Automatic mode will be removed in future release. Do not use. 
* Specifies automatic recognition should be enabled or disabled 
* @param bEnable 	[in] Option, default is false. True to enable, false to disable 
* <p> 
*/ 
 
  public void automaticIdentification(boolean bEnable) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdStream_automaticIdentification__SWIG_0(swigCPtr, this, bEnable);
  }

/** 
* @deprecated NB: Automatic mode will be removed in future release. Do not use. 
* Specifies automatic recognition is enabled or disabled 
* @return true			True if automatic recognition is enabled 
* <p> 
*/ 
 
  public boolean automaticIdentification() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnMusicIdStream_automaticIdentification__SWIG_1(swigCPtr, this);
  }

/** 
* @deprecated NB: Automatic mode for radio stream identification will be removed in future release. Do not use. 
* Provide text accompanying the channel stream to a query handle for improved match resolution 
* @param textKey 		[in] A input type from the available MusicIDStream Text Keys 
* @param textValue 	[in] A string value that corresponds to the defined text key 
* <p> 
*/ 
 
  public void text(GnMusicIdStreamText textKey, String textValue) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdStream_text(swigCPtr, this, textKey.swigValue(), textValue);
  }

/** 
* @deprecated NB: Automatic mode for radio stream identification will be removed in future release. Do not use. 
* Returns real clock time duration remaining before next query takes place when automatic recognition mode is turned on. 
* @param queryTimeLeft	[out[ Duration in ms left before next query. 
* <p> 
*/ 
 
  public GnString nextQueryTime() throws com.gracenote.gnsdk.GnException {
    return new GnString(gnsdk_javaJNI.GnMusicIdStream_nextQueryTime(swigCPtr, this), true);
  }

/** 
* Get the event handler provided on construction 
* @return Event handler 
*/ 
 
  public IGnMusicIdStreamEvents eventHandler() {
	return pEventDelegate;
}

/** 
*  Returns information about the {@link GnMusicIdStream} instance 
*  @param key		[in] Information key 
*  @return {@link GnString} containing the requested information 
*/ 
 
  public GnString infoGet(String key) throws com.gracenote.gnsdk.GnException {
    return new GnString(gnsdk_javaJNI.GnMusicIdStream_infoGet(swigCPtr, this, key), true);
  }

/** 
* Provides audio manually for processing by {@link GnMusicIdStream}. Data is provided via a 
* native data buffer. 
* This should not be called if 
* audio processing was started with an object implementing the audio source interface. 
* @param dataBuffer	[in] Native data buffer containing sample audio 
* @param dataSize	    [in] Number of bytes of audio in pAudioBuffer 
*/ 
 
  public void audioProcess(java.nio.ByteBuffer dataBuffer, long dataSize) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdStream_audioProcess__SWIG_1(swigCPtr, this, dataBuffer, dataSize);
  }

}
