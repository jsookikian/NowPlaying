
package com.gracenote.gnsdk;

/** 
** Provides services for generating Rhythm Recommendations 
*/ 
 
public class GnRhythmQuery {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnRhythmQuery(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnRhythmQuery obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnRhythmQuery(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

	private IGnStatusEvents pEventHandler;
	private IGnStatusEventsProxyU eventHandlerProxy;

/** 
*  Constructs a Rhythm query object with a Gracenote user and event delegate 
*  @param user          [in] Set {@link GnUser} object representing the user making the {@link GnMusicId} request 
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed. 
*/ 
 
  public GnRhythmQuery(GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnRhythmQuery__SWIG_0(GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnRhythmQuery(GnUser user) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnRhythmQuery__SWIG_1(GnUser.getCPtr(user), user);
}

/** 
*  Adds a Seed to the {@link GnRhythmQuery} object. 
*  @param seed			[in] {@link GnDataObject} to be used as seed, can be a {@link GnTrack}, {@link GnAlbum}, or {@link GnArtist} object 
*/ 
 
  public void addSeed(GnDataObject seed) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnRhythmQuery_addSeed(swigCPtr, this, GnDataObject.getCPtr(seed), seed);
  }

/** 
*  Generates a set of recommendations based on seeds set into the query handle. 
*  @return An instance of {@link GnResponseAlbums}, response contains one Album per Recommended Track. 
*  <p><b>Remarks:</b></p> 
*  The Matched Track on each Album in the {@link GnResponseAlbums} is the Recommended Track 
*/ 
 
  public GnResponseAlbums generateRecommendations(GnRhythmFilter filter) throws com.gracenote.gnsdk.GnException {
    return new GnResponseAlbums(gnsdk_javaJNI.GnRhythmQuery_generateRecommendations__SWIG_0(swigCPtr, this, GnRhythmFilter.getCPtr(filter), filter), true);
  }

/** 
*  Generates a set of recommendations based on seeds set into the query handle. 
*  @return An instance of {@link GnResponseAlbums}, response contains one Album per Recommended Track. 
*  <p><b>Remarks:</b></p> 
*  The Matched Track on each Album in the {@link GnResponseAlbums} is the Recommended Track 
*/ 
 
  public GnResponseAlbums generateRecommendations() throws com.gracenote.gnsdk.GnException {
    return new GnResponseAlbums(gnsdk_javaJNI.GnRhythmQuery_generateRecommendations__SWIG_1(swigCPtr, this), true);
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
    return new GnRhythmQueryOptions(gnsdk_javaJNI.GnRhythmQuery_options(swigCPtr, this), false);
  }

/** 
* Set cancel state 
* @param bCancel   [in] Cancel state 
*/ 
 
  public void setCancel(boolean bCancel) {
    gnsdk_javaJNI.GnRhythmQuery_setCancel(swigCPtr, this, bCancel);
  }

/** 
* Get cancel state. 
* @return Cancel state 
*/ 
 
  public boolean isCancelled() {
    return gnsdk_javaJNI.GnRhythmQuery_isCancelled(swigCPtr, this);
  }

}
