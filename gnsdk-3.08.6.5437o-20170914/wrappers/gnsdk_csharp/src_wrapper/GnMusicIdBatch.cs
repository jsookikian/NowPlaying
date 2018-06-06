
namespace GracenoteSDK {

/**
*  \class GnMusicIdBatch
*  Provides services for audio recognition using CD TOC-based search,
*  text-based search, fingerprint, and identifier lookup functionality.
*
*  <p><b>SDK Documentation</b></p>
*  <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Music Using a CD-TOC, Text, or Fingerprints (MusicID)
*
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
*
*  <p><b>Overiew</b></p>
*  <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID Overview
*
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
*
*/
public class GnMusicIdBatch : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMusicIdBatch(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMusicIdBatch obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMusicIdBatch() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMusicIdBatch(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
*  Defualt constructs a batch music identification query object
*/
  public GnMusicIdBatch() : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdBatch__SWIG_0(), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Constructs a batch music identification query object with a Gracenote user and event delegate
*  @param user          [in] Set GnUser object representing the user making the GnMusicId request
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed.
*/
  public GnMusicIdBatch(GnUser user, GnStatusEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdBatch__SWIG_1(GnUser.getCPtr(user), GnStatusEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnMusicIdBatch(GnUser user) : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdBatch__SWIG_2(GnUser.getCPtr(user)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Constructs a batch music identification query object with a Gracenote user, locale and event delegate
*  @param user          [in] Set GnUser object representing the user making the GnMusicIdBatch request
*  @param locale		 [in] GnLocale object representing region and language preferred for MusicID-Stream responses
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed.
*/
  public GnMusicIdBatch(GnUser user, GnLocale locale, GnStatusEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdBatch__SWIG_3(GnUser.getCPtr(user), GnLocale.getCPtr(locale), GnStatusEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnMusicIdBatch(GnUser user, GnLocale locale) : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdBatch__SWIG_4(GnUser.getCPtr(user), GnLocale.getCPtr(locale)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Clear all queries from batch music identification
*/
  public void Clear() {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatch_Clear(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Perform album find for all individual queries in the batch
*/
  public void FindAlbums() {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatch_FindAlbums(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Perform match find for all individual queries in the batch
*/
  public void FindMatches() {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatch_FindMatches(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Retrieve album query from batch music identification
*/
  public GnResponseAlbums GetAlbums(string unique_id) {
    GnResponseAlbums ret = new GnResponseAlbums(gnsdk_csharp_marshalPINVOKE.GnMusicIdBatch_GetAlbums(swigCPtr, unique_id), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Retrieve match query from batch music identification
*/
  public GnResponseDataMatches GetMatches(string unique_id) {
    GnResponseDataMatches ret = new GnResponseDataMatches(gnsdk_csharp_marshalPINVOKE.GnMusicIdBatch_GetMatches(swigCPtr, unique_id), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Retrieves the MusicID library version string.
*  @return gnsdk_cstr_t Version string, if successful
*  <p><b>Remarks:</b></p>
*  You can call this API after successfully instantiating a GnManager instance.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*
*  Major: New functionality
*
*  Minor: New or changed features
*
*  Improvement: Improvements and fixes
*
*  Build: Internal build number
*/
  public static string Version() {
	System.IntPtr temp = gnsdk_csharp_marshalPINVOKE.GnMusicIdBatch_Version(); 
	return GnMarshalUTF8.StringFromNativeUtf8(temp);
}

/**
*  Retrieves the MusicID SDK's build date string.
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  You can call this API after successfully instantiating a GnManager instance.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example build date string: 2008-02-12 00:41 UTC
*/
  public static string BuildDate() {
	System.IntPtr temp = gnsdk_csharp_marshalPINVOKE.GnMusicIdBatch_BuildDate(); 
	return GnMarshalUTF8.StringFromNativeUtf8(temp);
}

/**
* Get the event handler provided on construction
* @return Event handler
*/
  public GnStatusEventsDelegate EventHandler() {
    global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnMusicIdBatch_EventHandler(swigCPtr);
    GnStatusEventsDelegate ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnStatusEventsDelegate(cPtr, false);
    return ret;
  }

/**
* Set cancel state
* @param bCancel 	[in] Cancel state
*/
  public virtual void SetCancel(bool bCancel) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatch_SetCancel(swigCPtr, bCancel);
  }

/**
* Get cancel state.
* @return Cancel state
*/
  public virtual bool IsCancelled() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnMusicIdBatch_IsCancelled(swigCPtr);
    return ret;
  }

/**
* Get GnMusicIdBatchOption options object. Use to configure your GnMusicIdBatch instance.
* @return Options objects
*/
  public GnMusicIdBatchOptions Options() {
    GnMusicIdBatchOptions ret = new GnMusicIdBatchOptions(gnsdk_csharp_marshalPINVOKE.GnMusicIdBatch_Options(swigCPtr), false);
    return ret;
  }

}

}
