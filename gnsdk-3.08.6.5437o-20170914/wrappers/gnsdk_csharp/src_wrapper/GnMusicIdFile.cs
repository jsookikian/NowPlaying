
namespace GracenoteSDK {

/**
*  Performs bulk audio track recognition
*
*  MusicID-File is intended to be used with collections of file-based media.
*  When an application provides decoded audio and text data for each file to the
*  library, the MusicID-File functionality both identifies each file and groups
*  the files into albums.
*
* <p><b>SDK Documentation</b></p>
* <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Audio Files
*
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
*
* <p><b>Sample Apps</b></p>
* <ul>
*    <li>.../samples/musicid_file_trackid</li>
*    <li>.../samples/musicid_file_albumid</li>
*    <li>.../samples/musicid_file_libraryid</li>
* </ul>
*
* <p><b>Overiew</b></p>
* <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID-File Overview
*/
public class GnMusicIdFile : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMusicIdFile(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMusicIdFile obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMusicIdFile() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMusicIdFile(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public GnMusicIdFile(GnUser user, GnMusicIdFileEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdFile__SWIG_0(GnUser.getCPtr(user), GnMusicIdFileEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnMusicIdFile(GnUser user) : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdFile__SWIG_1(GnUser.getCPtr(user)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Retrieves the GnMusicIdFileOptions object.
*/
  public GnMusicIdFileOptions Options() {
    GnMusicIdFileOptions ret = new GnMusicIdFileOptions(gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_Options(swigCPtr), false);
    return ret;
  }

/**
*  Initiates TrackId processing.
*
*  @param processType		[in] Specifies what you get back
*  @param responseType		[in] Match response or album response
*
*  <p><b>Remarks:</b></p>
*  TrackId processing performs MusicID-File recognition on each given FileInfo independently
*  and is intended to be used with a small number of tracks that do not relate to other tracks in
*  the user's collection.
*/
  public void DoTrackId(GnMusicIdFileProcessType processType, GnMusicIdFileResponseType responseType) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_DoTrackId(swigCPtr, (int)processType, (int)responseType);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Initiates TrackId processing asynchronously.
*
*  @param processType		[in] specifies what you get back
*  @param responseType		[in] match response or album response
*
*  <p><b>Remarks:</b></p>
*  TrackId processing performs MusicID-File recognition on each given FileInfo independently
*  and is intended to be used with small number of tracks that do not relate to other tracks in
*  the user's collection.
*/
  public void DoTrackIdAsync(GnMusicIdFileProcessType processType, GnMusicIdFileResponseType responseType) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_DoTrackIdAsync(swigCPtr, (int)processType, (int)responseType);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Initiates AlbumId processing.
*
*  @param processType		[in] Process type specifies what you get back
*  @param responseType		[in] match response or album response
*
*  <p><b>Remarks:</b></p>
*  AlbumId processing performs MusicID-File recognition on all of the given FileInfos as a group.
*  This type of processing can be more accurate than TrackId processing, as AlbumId processing matches
*  the files to albums. Intended to be used with a small number of related tracks.
*/
  public void DoAlbumId(GnMusicIdFileProcessType processType, GnMusicIdFileResponseType responseType) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_DoAlbumId(swigCPtr, (int)processType, (int)responseType);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Initiates AlbumId processing asynchronously .
*
*  @param processType		[in] Process type specifies what you get back
*  @param responseType		[in] match response or album response
*
*  <p><b>Remarks:</b></p>
*  AlbumId processing performs MusicID-File recognition on all of the given FileInfos as a group.
*  This type of processing can be more accurate than TrackId processing, as AlbumId processing matches
*  the files to albums. Intended to be used with a small number of related tracks.
*/
  public void DoAlbumIdAsync(GnMusicIdFileProcessType processType, GnMusicIdFileResponseType responseType) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_DoAlbumIdAsync(swigCPtr, (int)processType, (int)responseType);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Initiates LibraryId processing.
*
*  @param responseType		[in] match response or album response
*
*  <p><b>Remarks:</b></p>
*  LibraryId processing performs MusicID-File recognition on a large number of given FileInfos. This
*  processing divides the given group of FileInfos into workable batches, and then processes each batch
*  using AlbumId functionality.
*/
  public void DoLibraryId(GnMusicIdFileResponseType responseType) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_DoLibraryId(swigCPtr, (int)responseType);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Initiates LibraryId processing asyncronously
*
*  @param responseType		[in] match response or album response
*
*  <p><b>Remarks:</b></p>
*  LibraryId processing performs MusicID-File recognition on a large number of given FileInfos. This
*  processing divides the given group of FileInfos into workable batches, and then processes each batch
*  using AlbumId functionality.
*/
  public void DoLibraryIdAsync(GnMusicIdFileResponseType responseType) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_DoLibraryIdAsync(swigCPtr, (int)responseType);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public static uint kTimeValueInfinite {
    set {
      gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_kTimeValueInfinite_set(value);
    } 
    get {
      uint ret = gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_kTimeValueInfinite_get();
      return ret;
    } 
  }

/**
*  Wait for a MusicID-File operation to complete, wait for the specified number of milliseconds.
*  @param timeoutValue		[in] Length of time to wait in milliseconds
*  <p><b>Remarks:</b></p>
*  Use this function to set a wait for TrackId, AlbumId, or LibraryId processing to complete for
*  a given GnMusicIdFile instance.
*/
  public void WaitForComplete(uint timeoutValue) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_WaitForComplete__SWIG_0(swigCPtr, timeoutValue);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Wait for a MusicID-File operation to complete with infinite wait time.
*  <p><b>Remarks:</b></p>
*  Use this function to set a wait for TrackId, AlbumId, or LibraryId processing to complete for
*  a given GnMusicIdFile instance.
*/
  public void WaitForComplete() {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_WaitForComplete__SWIG_1(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnMusicIdFileEventsDelegate EventHandler() {
    global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_EventHandler(swigCPtr);
    GnMusicIdFileEventsDelegate ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnMusicIdFileEventsDelegate(cPtr, false);
    return ret;
  }

/**
* Set cancel state
*/
  public void Cancel() {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_Cancel(swigCPtr);
  }

/**
*  Retrieves the MusicID-File library's version string.
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully instantiating a GnManager instance.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
*/
  public string Version {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_Version_get(swigCPtr) );
	} 

  }

/**
*  Retrieves the MusicID-File library's build date string.
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully instantiating a GnManager instance.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example build date string: 2008-02-12 00:41 UTC
*/
  public string BuildDate {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_BuildDate_get(swigCPtr) );
	} 

  }

/**
*  Retrieves the GnMusicIdFileInfoManager object.
*/
  public GnMusicIdFileInfoManager FileInfos {
    get {
      GnMusicIdFileInfoManager ret = new GnMusicIdFileInfoManager(gnsdk_csharp_marshalPINVOKE.GnMusicIdFile_FileInfos_get(swigCPtr), false);
      return ret;
    } 
  }

}

}
