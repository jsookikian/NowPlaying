
package com.gracenote.gnsdk;

/** 
**  Provides services for audio recognition using CD TOC-based search, 
*  text-based search, fingerprint, and identifier lookup functionality. 
* <p> 
*  <p><b>SDK Documentation</b></p> 
*  <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Music Using a CD-TOC, Text, or Fingerprints (MusicID) 
* <p> 
*  For more information on using MusicID, see the above topic which covers: 
*    <ul> 
*   <li>MusicID queries</li> 
*   <li>Options for MusicID queries</li> 
*   <li>Identifying music using a CD TOC<ul> 
*   <li>Code samples for identifying music using a CD TOC</li></ul></li> 
*   <li>Identifying music using text<ul> 
*   <li>Code samples for identifying music using text</li></ul></li> 
*   <li>Identifying music using fingerprints</li> 
*   <li>MusicID fingerprinting<ul> 
*   <li>Code samples for identifying music using MusicID fingerprinting</li></ul></li> 
*   </ul> 
* <p> 
*  <p><b>Overiew</b></p> 
*  <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID Overview 
* <p> 
*  <p><b>Sample Apps</b></p> 
*  <ul> 
*     <li>.../samples/musicid_gdo_navigation</li> 
*     <li>.../samples/musicid_lookup_album_id</li> 
*     <li>.../samples/musicid_lookup_album_local_online</li> 
*     <li>.../samples/musicid_lookup_album_toc</li> 
*     <li>.../samples/musicid_lookup_matches_text</li> 
*     <li>.../samples/musicid_persist_and_manage</li> 
*     <li>.../samples/musicid_persist_results</li> 
*   </ul> 
* <p> 
*/ 
 
public class GnMusicId {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnMusicId(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnMusicId obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnMusicId(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

	private IGnStatusEvents pEventHandler;
	private IGnStatusEventsProxyU eventHandlerProxy;
	private GnLocale locale;

    private long getCancellerCPtrFromCancellable(IGnCancellable cancellable) {
    	if ( cancellable instanceof IGnCancellableProxy ){
    		IGnCancellableProxy canceller = (IGnCancellableProxy)cancellable;
    		return IGnCancellableProxy.getCPtr(canceller);
    	}
    	return 0;
    }
    
/** 
*  Provides uncompressed audio data to a query for native fingerprint generation and returns 
*  a boolean value indicating when enough data has been received. 
*  @param audioData 		[in] Native data buffer containing sample audio that matches audio format described in 
*  						fingerprintBegin(). 
*  @return True fingerprint generation process gathered enough audio data, false otherwise. 
*  <p><b>Remarks:</b></p> 
*  Call this API after fingerprintBegin() to: 
*  <ul> 
*  <li>Generate a native Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint. 
*  <li>Receive a boolean value indicating whether MusicID has 
*  received sufficient audio data to generate the fingerprint. 
*  </ul> 
*  Additionally, if fingerprints have been generated (as shown by the returned 
*  value): 
*  <ul> 
*  <li>Optimally, stop calling fingerprintWrite after it returns true 
*  to conserve application resources. 
*  <li>Call fingerprintDataGet() for cases where the application needs to retrieve the 
*  raw fingerprint value from storage. 
*  </ul> 
*/ 
 
    public boolean fingerprintWrite(byte[] audioData) throws GnException{
		return fingerprintWrite(audioData,audioData.length);
	}

/** 
*  Constructs a music identification query object with a Gracenote user and event delegate 
*  @param user          [in] Set {@link GnUser} object representing the user making the {@link GnMusicId} request 
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed. 
*/ 
 
  public GnMusicId(GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	this.locale = locale; 				// <REFERENCE_NAME_CHECK><TYPE>GnLocale</TYPE><NAME>locale</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicId__SWIG_0(GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

/** 
*  Constructs a music identification query object with a Gracenote user 
*  @param user          [in] Set {@link GnUser} object representing the user making the {@link GnMusicId} request 
*/ 
 
  public GnMusicId(GnUser user) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	this.locale = locale; 				// <REFERENCE_NAME_CHECK><TYPE>GnLocale</TYPE><NAME>locale</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicId__SWIG_1(GnUser.getCPtr(user), user);
}

/** 
*  Constructs a music identification query object with a Gracenote user, locale and event delegate 
*  @param user          [in] Set {@link GnUser} object representing the user making the {@link GnMusicId} request 
*  @param locale		 [in] {@link GnLocale} object representing region and language preferred for MusicID-Stream responses 
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed. 
*/ 
 
  public GnMusicId(GnUser user, GnLocale locale, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	this.locale = locale; 				// <REFERENCE_NAME_CHECK><TYPE>GnLocale</TYPE><NAME>locale</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicId__SWIG_2(GnUser.getCPtr(user), user, GnLocale.getCPtr(locale), locale, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

/** 
*  Constructs a music identification query object with a Gracenote user and a locale 
*  @param user          [in] Set {@link GnUser} object representing the user making the {@link GnMusicId} request 
*  @param locale		[in] Locale representing region and language preferred for MusicID-Stream responses 
*/ 
 
  public GnMusicId(GnUser user, GnLocale locale) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	this.locale = locale; 				// <REFERENCE_NAME_CHECK><TYPE>GnLocale</TYPE><NAME>locale</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicId__SWIG_3(GnUser.getCPtr(user), user, GnLocale.getCPtr(locale), locale);
}

/** 
*  Retrieves the MusicID library version string. 
*  @return gnsdk_cstr_t Version string, if successful 
*  <p><b>Remarks:</b></p> 
*  You can call this API after successfully instantiating a {@link GnManager} instance. 
*  The returned string is a constant. Do not attempt to modify or delete. 
* <p> 
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build) 
* <p> 
*  Major: New functionality 
* <p> 
*  Minor: New or changed features 
* <p> 
*  Improvement: Improvements and fixes 
* <p> 
*  Build: Internal build number 
*/ 
 
  public static String version() {
    return gnsdk_javaJNI.GnMusicId_version();
  }

/** 
*  Retrieves the MusicID SDK's build date string. 
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC 
*  <p><b>Remarks:</b></p> 
*  You can call this API after successfully instantiating a {@link GnManager} instance. 
*  The returned string is a constant. Do not attempt to modify or delete. 
* <p> 
*  Example build date string: 2008-02-12 00:41 UTC 
*/ 
 
  public static String buildDate() {
    return gnsdk_javaJNI.GnMusicId_buildDate();
  }

/** 
*  Retrieves externally- and internally-generated Gracenote 
*  fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint data. 
*  @return String fingerprint data 
*/ 
 
  public String fingerprintDataGet() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnMusicId_fingerprintDataGet(swigCPtr, this);
  }

/** 
*  Initializes native fingerprint generation for a MusicID query. 
*  @param fpType 			[in] One of the {@link GnFingerprintType} fingerprint data types, 
*  						either Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX) 
*  @param audioSampleRate 	[in] Sample rate of audio to be provided in Hz (for example,44100) 
*  @param audioSampleSize 	[in] Size of a single sample of audio to be provided: 8 for 8-bit audio 
*  						(0-255 integers), 16 for 16-bit audio , and 32 for 32-bit audio (floating point) 
*  @param audioChannels 	[in] Number of channels for audio to be provided (1 or 2) 
*/ 
 
  public void fingerprintBegin(GnFingerprintType fpType, long audioSampleRate, long audioSampleSize, long audioChannels) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicId_fingerprintBegin(swigCPtr, this, fpType.swigValue(), audioSampleRate, audioSampleSize, audioChannels);
  }

/** 
*  Provides uncompressed audio data to a query for native fingerprint generation and returns 
*  a boolean value indicating when enough data has been received. 
*  @param audioData 		[in] Pointer to audio data buffer that matches audio format described in 
*  						FingerprintBegin(). 
*  @param audioDataSize 	[in] Size of audio data buffer in bytes 
*  @return True fingerprint generation process gathered enough audio data, false otherwise. 
*  <p><b>Remarks:</b></p> 
*  Call this API after FingerprintBegin() to: 
*  <ul> 
*  <li>Generate a native Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint. 
*  <li>Receive a boolean value indicating whether MusicID has 
*  received sufficient audio data to generate the fingerprint. 
*  </ul> 
*  Additionally, if fingerprints have been generated (as shown by the returned 
*  value): 
*  <ul> 
*  <li>Optimally, stop calling FingerprintWrite after it returns true 
*  to conserve application resources. 
*  <li>Call FingerprintDataGet() for cases where the application needs to retrieve the 
*  raw fingerprint value from storage. 
*  </ul> 
*/ 
 
  public boolean fingerprintWrite(byte[] audioData, long audioDataSize) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnMusicId_fingerprintWrite__SWIG_0(swigCPtr, this, audioData, audioDataSize);
  }

/** 
*  Finalizes native fingerprint generation for a MusicID query handle. 
*  <p><b>Remarks:</b></p> 
*  Call this API when the audio stream ends - this alerts the system that it has received all the 
*  available audio for a particular stream. 
*  If FingerprintWrite() returns True before the stream ends, we recommend that you: 
*  <ul> 
*  <li>Stop providing audio at that time, since enough has been received. 
*  <li>Do not FingerprintEnd(), as this is unnecessary. 
*  </ul> 
*  Fingerprints may be generated based on the call to this API; however, this is not guaranteed. 
*/ 
 
  public void fingerprintEnd() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicId_fingerprintEnd(swigCPtr, this);
  }

/** 
*  Creates a fingerprint from the given audio stream represented by an implementation 
*  of {@link IGnAudioSource}. Once completed, call FingerprintDataGet() for cases where the application needs 
*  to retrieve the raw fingerprint value from storage. 
*  This is an alternate and often simpler method for generating a 
*  fingerprint instead of calling FingerprintBegin, FingerprintWrite and FingerprintEnd. 
*  To use this method, the audio source to be fingerprinted must be accessible via an {@link IGnAudioSource} 
*  implementation. Custom implementations of {@link IGnAudioSource} are encouraged. 
*  @param audioSource		[in] Audio source to fingerprint 
*  @param fpType			[in] One of the {@link GnFingerprintType} fingerprint data types, 
*  						either Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX) 
*/ 
 
  public void fingerprintFromSource(IGnAudioSource audioSource, GnFingerprintType fpType) throws com.gracenote.gnsdk.GnException {
IGnAudioSourceProxyU audioSourceProxy = new IGnAudioSourceProxyU(audioSource);
    {
      gnsdk_javaJNI.GnMusicId_fingerprintFromSource(swigCPtr, this, IGnAudioSourceProxyL.getCPtr(audioSourceProxy), audioSourceProxy, fpType.swigValue());
    }
  }

/** 
*  Performs a MusicID query for album results based on text input. 
*  @param albumTitle           [in] Album title 
*  @param trackTitle           [in] Track title 
*  @param albumArtistName      [in] Album Artist name 
*  @param trackArtistName      [in] Track Artist name 
*  @param composerName         [in] Album Composer ( e.g. Classical, Instrumental, Movie Score) 
*  @return An instance of {@link GnResponseAlbums} that contain Album metadata. 
* <p> 
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup) 
*/ 
 
  public GnResponseAlbums findAlbums(String albumTitle, String trackTitle, String albumArtistName, String trackArtistName, String composerName) throws com.gracenote.gnsdk.GnException {
    return new GnResponseAlbums(gnsdk_javaJNI.GnMusicId_findAlbums__SWIG_0(swigCPtr, this, albumTitle, trackTitle, albumArtistName, trackArtistName, composerName), true);
  }

/** 
*  Performs a MusicID query for album results using a CD TOC 
*  @param CDTOC             [in] Compact Disc Table Of Contents 
*  @return An instance of {@link GnResponseAlbums} that contain Album metadata. 
* <p> 
*  Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup) 
*/ 
 
  public GnResponseAlbums findAlbums(String CDTOC) throws com.gracenote.gnsdk.GnException {
    return new GnResponseAlbums(gnsdk_javaJNI.GnMusicId_findAlbums__SWIG_1(swigCPtr, this, CDTOC), true);
  }

/** 
*  Performs a MusicID query for album results using CD TOC togther with fingerprint data 
*  @param CDTOC             	[in] Compact Disc Table Of Contents 
*  @param strFingerprintData	[in] Fingerprint data 
*  @param fpType            	[in] One of the {@link GnFingerprintType} fingerprint types 
*  @return An instance of {@link GnResponseAlbums} that contain Album metadata. 
* <p> 
*  Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup) 
*/ 
 
  public GnResponseAlbums findAlbums(String CDTOC, String strFingerprintData, GnFingerprintType fpType) throws com.gracenote.gnsdk.GnException {
    return new GnResponseAlbums(gnsdk_javaJNI.GnMusicId_findAlbums__SWIG_2(swigCPtr, this, CDTOC, strFingerprintData, fpType.swigValue()), true);
  }

/** 
*  Performs a MusicID query for album results using fingerprint data and finger print type. 
*  @param fingerprintData 	[in] Fingerprint data 
*  @param fpType 			[in] One of the {@link GnFingerprintType} fingerprint types 
*  @return An instance of {@link GnResponseAlbums} that contain Album metadata. 
* <p> 
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup) 
*/ 
 
  public GnResponseAlbums findAlbums(String fingerprintData, GnFingerprintType fpType) throws com.gracenote.gnsdk.GnException {
    return new GnResponseAlbums(gnsdk_javaJNI.GnMusicId_findAlbums__SWIG_3(swigCPtr, this, fingerprintData, fpType.swigValue()), true);
  }

/** 
*  Performs a MusicID query for album results. 
*  @param gnDataObject      [in] Gracenote data object 
*  @return An instance of {@link GnResponseAlbums} that contain Album metadata. 
* <p> 
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup) 
*/ 
 
  public GnResponseAlbums findAlbums(GnDataObject gnDataObject) throws com.gracenote.gnsdk.GnException {
    return new GnResponseAlbums(gnsdk_javaJNI.GnMusicId_findAlbums__SWIG_4(swigCPtr, this, GnDataObject.getCPtr(gnDataObject), gnDataObject), true);
  }

/** 
*  Performs a MusicID query for album results. 
*  @param audioSource     	[in] A valid {@link IGnAudioSource} object. 
*  @param fpType 			[in] One of the {@link GnFingerprintType} fingerprint types 
*  @return An instance of {@link GnResponseAlbums} that contain Album metadata. 
* <p> 
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup) 
*/ 
 
  public GnResponseAlbums findAlbums(IGnAudioSource audioSource, GnFingerprintType fpType) throws com.gracenote.gnsdk.GnException {
IGnAudioSourceProxyU audioSourceProxy = new IGnAudioSourceProxyU(audioSource);
    {
      return new GnResponseAlbums(gnsdk_javaJNI.GnMusicId_findAlbums__SWIG_5(swigCPtr, this, IGnAudioSourceProxyL.getCPtr(audioSourceProxy), audioSourceProxy, fpType.swigValue()), true);
    }
  }

/** 
*  Performs a MusicID query for best Matches results, being {@link GnAlbum} and/or {@link GnContributor} matches ordered in priority. 
*  @param albumTitle             [in] Album title 
*  @param trackTitle             [in] Track title 
*  @param albumArtistName        [in] Album Artist name 
*  @param trackArtistName        [in] Track Artist name 
*  @param composerName           [in] Album Composer ( e.g. Classical, Instrumental, Movie Score) 
*  @return Response containing Album, Track and Artist metadata. 
* <p> 
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup) 
*/ 
 
  public GnResponseDataMatches findMatches(String albumTitle, String trackTitle, String albumArtistName, String trackArtistName, String composerName) throws com.gracenote.gnsdk.GnException {
    return new GnResponseDataMatches(gnsdk_javaJNI.GnMusicId_findMatches(swigCPtr, this, albumTitle, trackTitle, albumArtistName, trackArtistName, composerName), true);
  }

/** 
* Get the event handler provided on construction 
* @return Event handler 
*/ 
 
  public IGnStatusEvents eventHandler() {
	return pEventHandler;
}

/** 
* Get {@link GnMusicId} options object. Use to configure your {@link GnMusicId} instance. 
* @return Options objects 
*/ 
 
  public GnMusicIdOptions options() {
    return new GnMusicIdOptions(gnsdk_javaJNI.GnMusicId_options(swigCPtr, this), false);
  }

/** 
* Set cancel state 
* @param bCancel 	[in] Cancel state 
*/ 
 
  public void setCancel(boolean bCancel) {
    gnsdk_javaJNI.GnMusicId_setCancel(swigCPtr, this, bCancel);
  }

/** 
* Get cancel state. 
* @return Cancel state 
*/ 
 
  public boolean isCancelled() {
    return gnsdk_javaJNI.GnMusicId_isCancelled(swigCPtr, this);
  }

/** 
*  Returns information about the {@link GnMusicId} instance 
*  @param infoType		[in] Information type 
*  @return {@link GnString} containing the requested information 
*/ 
 
  public GnString infoGet(GnMusicIdInfo infoType) throws com.gracenote.gnsdk.GnException {
    return new GnString(gnsdk_javaJNI.GnMusicId_infoGet__SWIG_0(swigCPtr, this, infoType.swigValue()), true);
  }

/** 
*  Returns information about the {@link GnMusicId} instance 
*  @param key		[in] Information key 
*  @return {@link GnString} containing the requested information 
*/ 
 
  public GnString infoGet(String key) throws com.gracenote.gnsdk.GnException {
    return new GnString(gnsdk_javaJNI.GnMusicId_infoGet__SWIG_1(swigCPtr, this, key), true);
  }

/** 
*  Provides uncompressed audio data to a query for native fingerprint generation and returns 
*  a boolean value indicating when enough data has been received. 
*  @param audioData 		[in] Native data buffer containing sample audio that matches audio format described in 
*  						fingerprintBegin(). 
*  @param audioDataSize 	[in] Size of audio data buffer in bytes 
*  @return True fingerprint generation process gathered enough audio data, false otherwise. 
*  <p><b>Remarks:</b></p> 
*  Call this API after fingerprintBegin() to: 
*  <ul> 
*  <li>Generate a native Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint. 
*  <li>Receive a boolean value indicating whether MusicID has 
*  received sufficient audio data to generate the fingerprint. 
*  </ul> 
*  Additionally, if fingerprints have been generated (as shown by the returned 
*  value): 
*  <ul> 
*  <li>Optimally, stop calling fingerprintWrite after it returns true 
*  to conserve application resources. 
*  <li>Call fingerprintDataGet() for cases where the application needs to retrieve the 
*  raw fingerprint value from storage. 
*  </ul> 
*/ 
 
  public boolean fingerprintWrite(java.nio.ByteBuffer audioData, long audioDataSize) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnMusicId_fingerprintWrite__SWIG_1(swigCPtr, this, audioData, audioDataSize);
  }

}
