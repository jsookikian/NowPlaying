
namespace GracenoteSDK {

/**
* Configures options for GnMusicIdStream
*/
public class GnMusicIdStreamOptions : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMusicIdStreamOptions(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMusicIdStreamOptions obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMusicIdStreamOptions() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMusicIdStreamOptions(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
*  Specifies whether identification should be performed against local embedded databases or online.
*  @param lookupMode  [in] One of the GnLookupMode values
*  @ingroup MusicIdStream_Options
*/
  public void LookupMode(GnLookupMode lookupMode) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_LookupMode(swigCPtr, (int)lookupMode);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Specifies which data should be included in the response
*  @param val 		[in] Set One of the #GnLookupData values
*  @param enable 	[in] True (enable) or false (disable)
*  @ingroup MusicIdStream_Options
*/
  public void LookupData(GnLookupData val, bool enable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_LookupData(swigCPtr, (int)val, enable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*   @deprecated To set language provide appropriate GnLocale object with GnMusicIdStream constructor
*   @param preferredLanguage		[in] Preferred language for result
*  @ingroup MusicIdStream_Options
*/
  public void PreferResultLanguage(GnLanguage preferredLanguage) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_PreferResultLanguage(swigCPtr, (int)preferredLanguage);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Specifies preference for results that contain the provided external identifier
* <p><b>Remarks:</b></p>
* This option is currently only supported when online processing is enabled and single
* result is specified.
*  @param preferredExternalId 	[in] The name of an external identifier that should be preferred when selecting matches
*  @ingroup MusicIdStream_Options
*/
  public void PreferResultExternalId(string preferredExternalId) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_PreferResultExternalId(swigCPtr, preferredExternalId);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Specifies preference for results that have cover art associated
*  @param bEnable 	[in] Set prefer cover art.
*  @ingroup MusicIdStream_Options
*/
  public void PreferResultCoverart(bool bEnable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_PreferResultCoverart(swigCPtr, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Specifies whether a response must return only the single best result.
*  When enabled, a single full result is returned; when disabled, multiple partial results could be returned.
*  @param bEnable 	[in] Option, default is true. True to enable, false to disable.
*  @ingroup MusicIdStream_Options
*/
  public void ResultSingle(bool bEnable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_ResultSingle(swigCPtr, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Specifies whether a response must return a range of results that begin at a specified value
*  @param resultStart  [in] Result range start value
*  <p><b>Remarks:</b></p>
*  This Option is useful for paging through results.
*  <p><b>Note:</b></p>
*  Gracenote Service enforces that the range start value must be less than or equal to the total
*  number of results. If you specify a range start value that is greater than the total number of
*  results, no results are returned.
*  @ingroup MusicIdStream_Options
*/
  public void ResultRangeStart(uint resultStart) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_ResultRangeStart(swigCPtr, resultStart);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Specifies the number of results to return in the response
*  @param resultCount 	[in] Number of results
*  @ingroup MusicIdStream_Options
*/
  public void ResultCount(uint resultCount) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_ResultCount(swigCPtr, resultCount);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
*  @param intfName [in] Local IP address or system name for the desired network interface
*  @ingroup MusicIdStream_Options
*/
  public void NetworkInterface(string intfName) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_NetworkInterface__SWIG_0(swigCPtr, intfName);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Returns the network interface being used with this object's connections if one has been set.
* If no specific network interface has been set, this option will return an empty string.
*  @ingroup MusicIdStream_Options
*/
  public string NetworkInterface() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_NetworkInterface__SWIG_1(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Specifies whether GnMuisicIdStream processes received audio and prevents performing
* identification queries if the audio is deemed unsuitable for music identification.
* If audio is deemed unsuitable a request to identify terminates in
* IGnMusicIdStreamEvents::MusicIdStreamIdentifyCompletedWithError being invoked with
* MIDSWARN_UnsuitableAudio.
* This option is experimental and subject to change
* @ingroup MusicIdStream_Options
*/
  public void AudioSuitabilityProcessing(bool bEnable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_AudioSuitabilityProcessing(swigCPtr, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  General option setting for custom string options
*  @param optionKey   [in] Option name
*  @param value	   [in] Option value
*  @ingroup MusicIdStream_Options
*/
  public void Custom(string optionKey, string value) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_Custom__SWIG_0(swigCPtr, optionKey, value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Return set value for custom options.
*  @param optionKey   [in] Option name
*  @ingroup MusicIdStream_Options
*/
  public string Custom(string optionKey) {
    string ret = gnsdk_csharp_marshalPINVOKE.GnMusicIdStreamOptions_Custom__SWIG_1(swigCPtr, optionKey);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
