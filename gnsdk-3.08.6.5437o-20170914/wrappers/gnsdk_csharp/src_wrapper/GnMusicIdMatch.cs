
namespace GracenoteSDK {

/**
* MusicID Match uses a combination of waveform fingerprinting technologies to match tracks
* within an end-user's collection to tracks within a cloud music provider's catalog, enabling
* instant playback from all devices without requiring upload.
*
* The <code>GnMusicId</code> and <code>GnMusicIdFile</code> classes provide methods for generating fingerprints
* from audio files and streaming music.
*/
public class GnMusicIdMatch : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMusicIdMatch(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMusicIdMatch obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMusicIdMatch() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMusicIdMatch(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Initializes the Gracenote MusicID Match SDK.
* @param user           GnUser object
* @param idDataSource   Data source ID from your user agreement with Gracenote.
* @param pEventHandler   Event handler pointer; default is Null.
* <p><b>Remarks:</b></p>
*/
  public GnMusicIdMatch(GnUser user, string idDataSource, GnStatusEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdMatch__SWIG_0(GnUser.getCPtr(user), idDataSource, GnStatusEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnMusicIdMatch(GnUser user, string idDataSource) : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdMatch__SWIG_1(GnUser.getCPtr(user), idDataSource), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Sets fingerprint data for a lookup request for a MusicID Match query.
* @param  ident             Identity string that must be unique for a query
* @param  fingerprintData   String representation of fingerprint data,
* must be a Cantametrix fingerprint.
*/
  public void LookupFingerprint(string ident, string fingerprintData) {
  System.IntPtr tempident = GnMarshalUTF8.NativeUtf8FromString(ident);
    try {
      gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_LookupFingerprint(swigCPtr, tempident, fingerprintData);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempident);
    }
  }

/**
* Sets fingerprint data and ID data for a compare request for a MusicID Match query.
* @param  ident             Identity string that must be unique for a query
* @param  fingerprintData   String representation of fingerprint data,
*					must be a Phillips macro fingerprint
*/
  public void CompareFingerprint(string ident, string fingerprintData) {
  System.IntPtr tempident = GnMarshalUTF8.NativeUtf8FromString(ident);
    try {
      gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_CompareFingerprint(swigCPtr, tempident, fingerprintData);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempident);
    }
  }

/**
* Adds an external ID for a compare request for a MusicID Match query.
* @param ident      Identity string that must be unique for a query
* @param externalId The external ID to be compared
*/
  public void AddCompareData(string ident, GnExternalId externalId) {
  System.IntPtr tempident = GnMarshalUTF8.NativeUtf8FromString(ident);
    try {
      gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_AddCompareData__SWIG_0(swigCPtr, tempident, GnExternalId.getCPtr(externalId));
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempident);
    }
  }

/**
* Add a single GnMatch from a CMX lookup for a compare request for a MusicID Match query. All external IDs in the match
* are considered for the query.
* @param ident      Identity string that must be unique for a query
* @param match      The GnMatch from a CMX Lookup to be compared
* @param includeTui Flag to denote if the Tui should be included from a CMX Lookup to be compared; default is false
*
*/
  public void AddCompareData(string ident, GnMatch match, bool includeTui) {
  System.IntPtr tempident = GnMarshalUTF8.NativeUtf8FromString(ident);
    try {
      gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_AddCompareData__SWIG_1(swigCPtr, tempident, GnMatch.getCPtr(match), includeTui);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempident);
    }
  }

  public void AddCompareData(string ident, GnMatch match) {
  System.IntPtr tempident = GnMarshalUTF8.NativeUtf8FromString(ident);
    try {
      gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_AddCompareData__SWIG_2(swigCPtr, tempident, GnMatch.getCPtr(match));
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempident);
    }
  }

  public void AddCompareData(string ident, GnMatchEnumerator from, GnMatchEnumerator end, bool includeTui) {
  System.IntPtr tempident = GnMarshalUTF8.NativeUtf8FromString(ident);
    try {
      gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_AddCompareData__SWIG_3(swigCPtr, tempident, GnMatchEnumerator.getCPtr(from), GnMatchEnumerator.getCPtr(end), includeTui);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempident);
    }
  }

  public void AddCompareData(string ident, GnMatchEnumerator from, GnMatchEnumerator end) {
  System.IntPtr tempident = GnMarshalUTF8.NativeUtf8FromString(ident);
    try {
      gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_AddCompareData__SWIG_4(swigCPtr, tempident, GnMatchEnumerator.getCPtr(from), GnMatchEnumerator.getCPtr(end));
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempident);
    }
  }

/**
* Adds a specific ID (generic) for a compare request for a MusicID Match query. This ID is relative to the context of the usage and the
* ID DataSource specified.
* @param ident     Identity string that must be unique for a query
* @param otherId   The ID data to be compared
*/
  public void AddCompareData(string ident, string otherId) {
  System.IntPtr tempident = GnMarshalUTF8.NativeUtf8FromString(ident);
    try {
      gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_AddCompareData__SWIG_5(swigCPtr, tempident, otherId);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempident);
    }
  }

/**
* Performs a MusicID Match query for the added lookup and compare requests.
*/
  public void FindMatches() {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_FindMatches(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Performs a MusicID Match query for responses.
* @param ident Identifier used for adding requests to the query
* @return GnResponseMatches
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve responses based on an input parameters.
*/
  public GnResponseMatches Response(string ident) {
  System.IntPtr tempident = GnMarshalUTF8.NativeUtf8FromString(ident);
    try {
      GnResponseMatches ret = new GnResponseMatches(gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_Response(swigCPtr, tempident), true);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempident);
    }
  }

/**
* SetCancel
* @param bool bCancel - true or false value 
*/
  public virtual void SetCancel(bool bCancel) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_SetCancel(swigCPtr, bCancel);
  }

/**
* IsCancelled
* @return bool - true or false value
*/
  public virtual bool IsCancelled() {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_IsCancelled(swigCPtr);
    return ret;
  }

/**
* Retrieves the MusicID Match SDK's version string.
* <p><b>Remarks:</b></p>
* This API can be called at any time, after successfully getting a GnManager instance.
* The returned string is a constant. Do not attempt to modify or delete.
*
* Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*
* Major: New functionality
*
* Minor: New or changed features
*
* Improvement: Improvements and fixes
*
* Build: Internal build number
*/
  public string Version {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_Version_get(swigCPtr) );
	} 

  }

/**
* Retrieves MusicID Match SDK's build date string.
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, after successfully getting a GnManager instance.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example build date string: 2008-02-12 00:41 UTC
*/
  public string BuildDate {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnMusicIdMatch_BuildDate_get(swigCPtr) );
	} 

  }

}

}
