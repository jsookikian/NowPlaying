
package com.gracenote.gnsdk;

/** 
*  Performs bulk audio track recognition 
* <p> 
*  MusicID-File is intended to be used with collections of file-based media. 
*  When an application provides decoded audio and text data for each file to the 
*  library, the MusicID-File functionality both identifies each file and groups 
*  the files into albums. 
* <p> 
* <p><b>SDK Documentation</b></p> 
* <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Audio Files 
* <p> 
* For more information on using MusicID-File, see the above topic which covers: 
* <ul> 
*     <li>MusicID file identification mechanisms (TrackID, AlbumID, and LibraryID)</li> 
*     <li>How to identify audio from a file</li> 
*     <li>Implementing an events delegate<ul> 
*     <li>Events delegate code samples</li></ul></li> 
*     <li>Adding audio files for identification<ul> 
*     <li>Adding audio files code samples</li></ul></li> 
*     <li>Setting audio file identification<ul> 
*     <li>Audio file identification code samples</li></ul></li> 
*     <li>MusicID-File fingerprinting<ul> 
*     <li>Fingerprinting code samples</li></ul></li> 
*     <li>Setting options for MusicID-File queries</li> 
*     <li>Making a MusicID-File query<ul> 
*     <li>MusicID-file query options</li> 
*     <li>Setting options code samples</li></ul></li> 
* </ul> 
* <p> 
* <p><b>Sample Apps</b></p> 
* <ul> 
*    <li>.../samples/musicid_file_trackid</li> 
*    <li>.../samples/musicid_file_albumid</li> 
*    <li>.../samples/musicid_file_libraryid</li> 
* </ul> 
* <p> 
* <p><b>Overiew</b></p> 
* <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID-File Overview 
*/ 
 
public class GnMusicIdFile {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnMusicIdFile(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnMusicIdFile obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnMusicIdFile(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

	private IGnMusicIdFileEvents pEventHandler;
	private IGnMusicIdFileEventsProxyU eventHandlerProxy;

/** 
*  Constructs an audio track identification object 
*  @param user 			[in] Gracenote user object representing the user making the {@link GnMusicIdFile} request 
*  @param pEventHandler	[in] Delegate object for receiving processing events 
*/ 
 
  public GnMusicIdFile(GnUser user, IGnMusicIdFileEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnMusicIdFileEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnMusicIdFileEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicIdFile__SWIG_0(GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnMusicIdFileEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

/** 
*  Constructs an audio track identification object 
*  @param user 			[in] Gracenote user object representing the user making the {@link GnMusicIdFile} request 
*/ 
 
  public GnMusicIdFile(GnUser user) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnMusicIdFileEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnMusicIdFileEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnMusicIdFile__SWIG_1(GnUser.getCPtr(user), user);
}

/** 
*  Retrieves the MusicID-File library's version string. 
*  <p><b>Remarks:</b></p> 
*  You can call this API at any time after successfully instantiating a {@link GnManager} instance. 
*  The returned string is a constant. Do not attempt to modify or delete. 
* <p> 
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build) 
* <p> 
*  Major: New functionality 
*  Minor: New or changed features 
*  Improvement: Improvements and fixes 
*  Build: Internal build number 
*/ 
 
  public static String version() {
    return gnsdk_javaJNI.GnMusicIdFile_version();
  }

/** 
*  Retrieves the MusicID-File library's build date string. 
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC 
*  <p><b>Remarks:</b></p> 
*  You can call this API at any time after successfully instantiating a {@link GnManager} instance. 
*  The returned string is a constant. Do not attempt to modify or delete. 
* <p> 
*  Example build date string: 2008-02-12 00:41 UTC 
*/ 
 
  public static String buildDate() {
    return gnsdk_javaJNI.GnMusicIdFile_buildDate();
  }

/** 
*  Retrieves the {@link GnMusicIdFileOptions} object. 
*/ 
 
  public GnMusicIdFileOptions options() {
    return new GnMusicIdFileOptions(gnsdk_javaJNI.GnMusicIdFile_options(swigCPtr, this), false);
  }

/** 
*  Retrieves the {@link GnMusicIdFileInfoManager} object. 
*/ 
 
  public GnMusicIdFileInfoManager fileInfos() {
    return new GnMusicIdFileInfoManager(gnsdk_javaJNI.GnMusicIdFile_fileInfos(swigCPtr, this), false);
  }

/** 
*  Initiates TrackId processing. 
* <p> 
*  @param processType		[in] Specifies what you get back 
*  @param responseType		[in] Match response or album response 
* <p> 
*  <p><b>Remarks:</b></p> 
*  TrackId processing performs MusicID-File recognition on each given FileInfo independently 
*  and is intended to be used with a small number of tracks that do not relate to other tracks in 
*  the user's collection. 
*/ 
 
  public void doTrackId(GnMusicIdFileProcessType processType, GnMusicIdFileResponseType responseType) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdFile_doTrackId(swigCPtr, this, processType.swigValue(), responseType.swigValue());
  }

/** 
*  Initiates TrackId processing asynchronously. 
* <p> 
*  @param processType		[in] specifies what you get back 
*  @param responseType		[in] match response or album response 
* <p> 
*  <p><b>Remarks:</b></p> 
*  TrackId processing performs MusicID-File recognition on each given FileInfo independently 
*  and is intended to be used with small number of tracks that do not relate to other tracks in 
*  the user's collection. 
*/ 
 
  public void doTrackIdAsync(GnMusicIdFileProcessType processType, GnMusicIdFileResponseType responseType) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdFile_doTrackIdAsync(swigCPtr, this, processType.swigValue(), responseType.swigValue());
  }

/** 
*  Initiates AlbumId processing. 
* <p> 
*  @param processType		[in] Process type specifies what you get back 
*  @param responseType		[in] match response or album response 
* <p> 
*  <p><b>Remarks:</b></p> 
*  AlbumId processing performs MusicID-File recognition on all of the given FileInfos as a group. 
*  This type of processing can be more accurate than TrackId processing, as AlbumId processing matches 
*  the files to albums. Intended to be used with a small number of related tracks. 
*/ 
 
  public void doAlbumId(GnMusicIdFileProcessType processType, GnMusicIdFileResponseType responseType) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdFile_doAlbumId(swigCPtr, this, processType.swigValue(), responseType.swigValue());
  }

/** 
*  Initiates AlbumId processing asynchronously . 
* <p> 
*  @param processType		[in] Process type specifies what you get back 
*  @param responseType		[in] match response or album response 
* <p> 
*  <p><b>Remarks:</b></p> 
*  AlbumId processing performs MusicID-File recognition on all of the given FileInfos as a group. 
*  This type of processing can be more accurate than TrackId processing, as AlbumId processing matches 
*  the files to albums. Intended to be used with a small number of related tracks. 
*/ 
 
  public void doAlbumIdAsync(GnMusicIdFileProcessType processType, GnMusicIdFileResponseType responseType) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdFile_doAlbumIdAsync(swigCPtr, this, processType.swigValue(), responseType.swigValue());
  }

/** 
*  Initiates LibraryId processing. 
* <p> 
*  @param responseType		[in] match response or album response 
* <p> 
*  <p><b>Remarks:</b></p> 
*  LibraryId processing performs MusicID-File recognition on a large number of given FileInfos. This 
*  processing divides the given group of FileInfos into workable batches, and then processes each batch 
*  using AlbumId functionality. 
*/ 
 
  public void doLibraryId(GnMusicIdFileResponseType responseType) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdFile_doLibraryId(swigCPtr, this, responseType.swigValue());
  }

/** 
*  Initiates LibraryId processing asyncronously 
* <p> 
*  @param responseType		[in] match response or album response 
* <p> 
*  <p><b>Remarks:</b></p> 
*  LibraryId processing performs MusicID-File recognition on a large number of given FileInfos. This 
*  processing divides the given group of FileInfos into workable batches, and then processes each batch 
*  using AlbumId functionality. 
*/ 
 
  public void doLibraryIdAsync(GnMusicIdFileResponseType responseType) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdFile_doLibraryIdAsync(swigCPtr, this, responseType.swigValue());
  }

/** 
*  Wait for a MusicID-File operation to complete, wait for the specified number of milliseconds. 
*  @param timeoutValue		[in] Length of time to wait in milliseconds 
*  <p><b>Remarks:</b></p> 
*  Use this function to set a wait for TrackId, AlbumId, or LibraryId processing to complete for 
*  a given {@link GnMusicIdFile} instance. 
*/ 
 
  public void waitForComplete(long timeoutValue) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdFile_waitForComplete__SWIG_0(swigCPtr, this, timeoutValue);
  }

/** 
*  Wait for a MusicID-File operation to complete with infinite wait time. 
*  <p><b>Remarks:</b></p> 
*  Use this function to set a wait for TrackId, AlbumId, or LibraryId processing to complete for 
*  a given {@link GnMusicIdFile} instance. 
*/ 
 
  public void waitForComplete() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdFile_waitForComplete__SWIG_1(swigCPtr, this);
  }

/** 
* Get the event handler provided on construction 
* @return Event handler 
*/ 
 
  public IGnMusicIdFileEvents eventHandler() {
	return pEventHandler;
}

/** 
* Set cancel state 
*/ 
 
  public void cancel() {
    gnsdk_javaJNI.GnMusicIdFile_cancel(swigCPtr, this);
  }

}
