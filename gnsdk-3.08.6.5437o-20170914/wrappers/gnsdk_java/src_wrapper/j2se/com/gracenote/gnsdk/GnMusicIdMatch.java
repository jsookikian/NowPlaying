
package com.gracenote.gnsdk;

/** 
* MusicID Match uses a combination of waveform fingerprinting technologies to match tracks 
* within an end-user's collection to tracks within a cloud music provider's catalog, enabling 
* instant playback from all devices without requiring upload. 
* <p> 
* The <code>GnMusicId</code> and <code>GnMusicIdFile</code> classes provide methods for generating fingerprints 
* from audio files and streaming music. 
*/ 
 
public class GnMusicIdMatch {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnMusicIdMatch(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnMusicIdMatch obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnMusicIdMatch(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

	private IGnStatusEvents pEventHandler;
	private IGnStatusEventsProxyU eventHandlerProxy;

/** 
* Initializes the Gracenote MusicID Match SDK. 
* @param user           {@link GnUser} object 
* @param idDataSource   Data source ID from your user agreement with Gracenote. 
* @param pEventHandler   Event handler pointer; default is Null. 
* <p><b>Remarks:</b></p> 
*/ 
 
  public GnMusicIdMatch(GnUser user, String idDataSource, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicIdMatch__SWIG_0(GnUser.getCPtr(user), user, idDataSource, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnMusicIdMatch(GnUser user, String idDataSource) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicIdMatch__SWIG_1(GnUser.getCPtr(user), user, idDataSource);
}

/** 
* Retrieves the MusicID Match SDK's version string. 
* <p><b>Remarks:</b></p> 
* This API can be called at any time, after successfully getting a {@link GnManager} instance. 
* The returned string is a constant. Do not attempt to modify or delete. 
* <p> 
* Example version string: 1.2.3.123 (Major.Minor.Improvement.Build) 
* <p> 
* Major: New functionality 
* <p> 
* Minor: New or changed features 
* <p> 
* Improvement: Improvements and fixes 
* <p> 
* Build: Internal build number 
*/ 
 
  public static String version() {
    return gnsdk_javaJNI.GnMusicIdMatch_version();
  }

/** 
* Retrieves MusicID Match SDK's build date string. 
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC 
*  <p><b>Remarks:</b></p> 
*  This API can be called at any time, after successfully getting a {@link GnManager} instance. 
*  The returned string is a constant. Do not attempt to modify or delete. 
* <p> 
*  Example build date string: 2008-02-12 00:41 UTC 
*/ 
 
  public static String buildDate() {
    return gnsdk_javaJNI.GnMusicIdMatch_buildDate();
  }

/** 
* Sets fingerprint data for a lookup request for a MusicID Match query. 
* @param  ident             Identity string that must be unique for a query 
* @param  fingerprintData   String representation of fingerprint data, 
* must be a Cantametrix fingerprint. 
*/ 
 
  public void lookupFingerprint(String ident, String fingerprintData) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdMatch_lookupFingerprint(swigCPtr, this, ident, fingerprintData);
  }

/** 
* Sets fingerprint data and ID data for a compare request for a MusicID Match query. 
* @param  ident             Identity string that must be unique for a query 
* @param  fingerprintData   String representation of fingerprint data, 
*					must be a Phillips macro fingerprint 
*/ 
 
  public void compareFingerprint(String ident, String fingerprintData) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdMatch_compareFingerprint(swigCPtr, this, ident, fingerprintData);
  }

/** 
* Adds an external ID for a compare request for a MusicID Match query. 
* @param ident      Identity string that must be unique for a query 
* @param externalId The external ID to be compared 
*/ 
 
  public void addCompareData(String ident, GnExternalId externalId) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdMatch_addCompareData__SWIG_0(swigCPtr, this, ident, GnExternalId.getCPtr(externalId), externalId);
  }

/** 
* Add a single {@link GnMatch} from a CMX lookup for a compare request for a MusicID Match query. All external IDs in the match 
* are considered for the query. 
* @param ident      Identity string that must be unique for a query 
* @param match      The {@link GnMatch} from a CMX Lookup to be compared 
* @param includeTui Flag to denote if the Tui should be included from a CMX Lookup to be compared; default is false 
* <p> 
*/ 
 
  public void addCompareData(String ident, GnMatch match, boolean includeTui) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdMatch_addCompareData__SWIG_1(swigCPtr, this, ident, GnMatch.getCPtr(match), match, includeTui);
  }

  public void addCompareData(String ident, GnMatch match) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdMatch_addCompareData__SWIG_2(swigCPtr, this, ident, GnMatch.getCPtr(match), match);
  }

  public void addCompareData(String ident, GnMatchIterator from, GnMatchIterator end, boolean includeTui) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdMatch_addCompareData__SWIG_3(swigCPtr, this, ident, GnMatchIterator.getCPtr(from), from, GnMatchIterator.getCPtr(end), end, includeTui);
  }

  public void addCompareData(String ident, GnMatchIterator from, GnMatchIterator end) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdMatch_addCompareData__SWIG_4(swigCPtr, this, ident, GnMatchIterator.getCPtr(from), from, GnMatchIterator.getCPtr(end), end);
  }

/** 
* Adds a specific ID (generic) for a compare request for a MusicID Match query. This ID is relative to the context of the usage and the 
* ID DataSource specified. 
* @param ident     Identity string that must be unique for a query 
* @param otherId   The ID data to be compared 
*/ 
 
  public void addCompareData(String ident, String otherId) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdMatch_addCompareData__SWIG_5(swigCPtr, this, ident, otherId);
  }

/** 
* Performs a MusicID Match query for the added lookup and compare requests. 
*/ 
 
  public void findMatches() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdMatch_findMatches(swigCPtr, this);
  }

/** 
* Performs a MusicID Match query for responses. 
* @param ident Identifier used for adding requests to the query 
* @return {@link GnResponseMatches} 
*  <p><b>Remarks:</b></p> 
*  Use this function to retrieve responses based on an input parameters. 
*/ 
 
  public GnResponseMatches response(String ident) throws com.gracenote.gnsdk.GnException {
    return new GnResponseMatches(gnsdk_javaJNI.GnMusicIdMatch_response(swigCPtr, this, ident), true);
  }

/** 
* SetCancel 
* @param bool bCancel - true or false value  
*/ 
 
  public void setCancel(boolean bCancel) {
    gnsdk_javaJNI.GnMusicIdMatch_setCancel(swigCPtr, this, bCancel);
  }

/** 
* IsCancelled 
* @return bool - true or false value 
*/ 
 
  public boolean isCancelled() {
    return gnsdk_javaJNI.GnMusicIdMatch_isCancelled(swigCPtr, this);
  }

}
