
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
 
public class GnMusicIdBatch {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnMusicIdBatch(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnMusicIdBatch obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnMusicIdBatch(swigCPtr);
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
*  Defualt constructs a batch music identification query object 
*/ 
 
  public GnMusicIdBatch() throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	this.locale = locale; 				// <REFERENCE_NAME_CHECK><TYPE>GnLocale</TYPE><NAME>locale</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicIdBatch__SWIG_0();
}

/** 
*  Constructs a batch music identification query object with a Gracenote user and event delegate 
*  @param user          [in] Set {@link GnUser} object representing the user making the {@link GnMusicId} request 
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed. 
*/ 
 
  public GnMusicIdBatch(GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	this.locale = locale; 				// <REFERENCE_NAME_CHECK><TYPE>GnLocale</TYPE><NAME>locale</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicIdBatch__SWIG_1(GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnMusicIdBatch(GnUser user) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	this.locale = locale; 				// <REFERENCE_NAME_CHECK><TYPE>GnLocale</TYPE><NAME>locale</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicIdBatch__SWIG_2(GnUser.getCPtr(user), user);
}

/** 
*  Constructs a batch music identification query object with a Gracenote user, locale and event delegate 
*  @param user          [in] Set {@link GnUser} object representing the user making the {@link GnMusicIdBatch} request 
*  @param locale		 [in] {@link GnLocale} object representing region and language preferred for MusicID-Stream responses 
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed. 
*/ 
 
  public GnMusicIdBatch(GnUser user, GnLocale locale, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	this.locale = locale; 				// <REFERENCE_NAME_CHECK><TYPE>GnLocale</TYPE><NAME>locale</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicIdBatch__SWIG_3(GnUser.getCPtr(user), user, GnLocale.getCPtr(locale), locale, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnMusicIdBatch(GnUser user, GnLocale locale) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	this.locale = locale; 				// <REFERENCE_NAME_CHECK><TYPE>GnLocale</TYPE><NAME>locale</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicIdBatch__SWIG_4(GnUser.getCPtr(user), user, GnLocale.getCPtr(locale), locale);
}

/** 
*  Clear all queries from batch music identification 
*/ 
 
  public void clear() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatch_clear(swigCPtr, this);
  }

/** 
*  Perform album find for all individual queries in the batch 
*/ 
 
  public void findAlbums() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatch_findAlbums(swigCPtr, this);
  }

/** 
*  Perform match find for all individual queries in the batch 
*/ 
 
  public void findMatches() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatch_findMatches(swigCPtr, this);
  }

/** 
*  Retrieve album query from batch music identification 
*/ 
 
  public GnResponseAlbums getAlbums(String unique_id) throws com.gracenote.gnsdk.GnException {
    return new GnResponseAlbums(gnsdk_javaJNI.GnMusicIdBatch_getAlbums(swigCPtr, this, unique_id), true);
  }

/** 
*  Retrieve match query from batch music identification 
*/ 
 
  public GnResponseDataMatches getMatches(String unique_id) throws com.gracenote.gnsdk.GnException {
    return new GnResponseDataMatches(gnsdk_javaJNI.GnMusicIdBatch_getMatches(swigCPtr, this, unique_id), true);
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
    return gnsdk_javaJNI.GnMusicIdBatch_version();
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
    return gnsdk_javaJNI.GnMusicIdBatch_buildDate();
  }

/** 
* Get the event handler provided on construction 
* @return Event handler 
*/ 
 
  public IGnStatusEvents eventHandler() {
	return pEventHandler;
}

/** 
* Set cancel state 
* @param bCancel 	[in] Cancel state 
*/ 
 
  public void setCancel(boolean bCancel) {
    gnsdk_javaJNI.GnMusicIdBatch_setCancel(swigCPtr, this, bCancel);
  }

/** 
* Get cancel state. 
* @return Cancel state 
*/ 
 
  public boolean isCancelled() {
    return gnsdk_javaJNI.GnMusicIdBatch_isCancelled(swigCPtr, this);
  }

/** 
* Get {@link GnMusicIdBatchOption} options object. Use to configure your {@link GnMusicIdBatch} instance. 
* @return Options objects 
*/ 
 
  public GnMusicIdBatchOptions options() {
    return new GnMusicIdBatchOptions(gnsdk_javaJNI.GnMusicIdBatch_options(swigCPtr, this), false);
  }

}
