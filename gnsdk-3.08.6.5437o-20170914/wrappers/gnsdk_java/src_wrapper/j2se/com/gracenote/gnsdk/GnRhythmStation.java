
package com.gracenote.gnsdk;

/** 
** Provides services for interacting with Rhythm Stations 
*/ 
 
public class GnRhythmStation {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnRhythmStation(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnRhythmStation obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnRhythmStation(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

	private IGnStatusEvents pEventHandler;
	private IGnStatusEventsProxyU eventHandlerProxy;

/** 
*  Constructs a Rhythm Station object from a {@link GnRhythmQuery} object and event delegate 
*  @param rhythmQuery   [in] {@link GnRhythmQuery} object containing the seeds and options to generate a new Rhythm Station. 
*  @param filter		 [in] {@link GnRhythmFilter} object containing the filter to generate a new Rhythm Station. 
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed. 
*/ 
 
  public GnRhythmStation(GnRhythmQuery rhythmQuery, GnRhythmFilter filter, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnRhythmStation__SWIG_0(GnRhythmQuery.getCPtr(rhythmQuery), rhythmQuery, GnRhythmFilter.getCPtr(filter), filter, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnRhythmStation(GnRhythmQuery rhythmQuery, GnRhythmFilter filter) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnRhythmStation__SWIG_1(GnRhythmQuery.getCPtr(rhythmQuery), rhythmQuery, GnRhythmFilter.getCPtr(filter), filter);
}

  public GnRhythmStation(GnRhythmQuery rhythmQuery, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnRhythmStation__SWIG_2(GnRhythmQuery.getCPtr(rhythmQuery), rhythmQuery, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnRhythmStation(GnRhythmQuery rhythmQuery) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnRhythmStation__SWIG_3(GnRhythmQuery.getCPtr(rhythmQuery), rhythmQuery);
}

/** 
*  Constructs a Rhythm Station object from an existing Rhythm Station ID, with a Gracenote user and event delegate 
*  @param stationId    [in] An Rhythm Station ID which will be used to retrieve a pre-existing Rhythm Station. 
*  @param user          [in] Set {@link GnUser} object representing the user making the {@link GnMusicId} request. 
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed. 
*/ 
 
  public GnRhythmStation(String stationId, GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnRhythmStation__SWIG_4(stationId, GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnRhythmStation(String stationId, GnUser user) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnRhythmStation__SWIG_5(stationId, GnUser.getCPtr(user), user);
}

/** 
*  Retrieves the station ID 
*   @return A C String contaning the Rhythm Station's ID. 
*  <p><b>Remarks:</b></p> 
*  The returned string is a constant. Do not attempt to modify or delete. 
*/ 
 
  public String stationId() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnRhythmStation_stationId(swigCPtr, this);
  }

/** 
*  Generate a Rhythm Station Playlist. 
*  @return An instance of {@link GnResponseAlbums}, response contains one Album per Recommended Track. 
*  <p><b>Remarks:</b></p> 
*  The Matched Track on each Album in the {@link GnResponseAlbums} is the Recommended Track 
*/ 
 
  public GnResponseAlbums generatePlaylist() throws com.gracenote.gnsdk.GnException {
    return new GnResponseAlbums(gnsdk_javaJNI.GnRhythmStation_generatePlaylist(swigCPtr, this), true);
  }

/** 
*  Adds an event to a Rhythm station. 
*   @param event        [in] One of the predefined Rhythm event types 
*   @param gnObj        [in] A {@link GnDataObject} representing the context of the event 
*/ 
 
  public void event(GnRhythmEvent event, GnDataObject gnObj) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnRhythmStation_event(swigCPtr, this, event.swigValue(), GnDataObject.getCPtr(gnObj), gnObj);
  }

/** 
* Get the event handler provided on construction 
* @return Event handler 
*/ 
 
  public IGnStatusEvents eventHandler() {
	return pEventHandler;
}

/** 
* Get {@link GnRhythmQuery} options object. Use to configure your {@link GnRhythmQuery} instance. 
* @return Options object 
*/ 
 
  public GnRhythmQueryOptions options() {
    return new GnRhythmQueryOptions(gnsdk_javaJNI.GnRhythmStation_options(swigCPtr, this), false);
  }

/** 
* Set cancel state 
* @param bCancel   [in] Cancel state 
*/ 
 
  public void setCancel(boolean bCancel) {
    gnsdk_javaJNI.GnRhythmStation_setCancel(swigCPtr, this, bCancel);
  }

/** 
* Get cancel state. 
* @return Cancel state 
*/ 
 
  public boolean isCancelled() {
    return gnsdk_javaJNI.GnRhythmStation_isCancelled(swigCPtr, this);
  }

}
