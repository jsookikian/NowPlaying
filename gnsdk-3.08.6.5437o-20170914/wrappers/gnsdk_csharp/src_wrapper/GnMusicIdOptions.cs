
namespace GracenoteSDK {

/**
* \class GnMusicIdOptions
* Configures options for GnMusicId
*/
public class GnMusicIdOptions : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMusicIdOptions(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMusicIdOptions obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMusicIdOptions() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMusicIdOptions(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
*  Indicate whether the MusicID query should be performed against local embedded databases or online.
*  @param lookupMode  [in] One of the #GnLookupMode values
*  @ingroup MusicId_Options
*/
  public void LookupMode(GnLookupMode lookupMode) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_LookupMode__SWIG_0(swigCPtr, (int)lookupMode);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Return current lookup mode for MusicID query
*  @ingroup MusicId_Options
*/
  public GnLookupMode LookupMode() {
    GnLookupMode ret = (GnLookupMode)gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_LookupMode__SWIG_1(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Set the lookup data value for the MusicID query.
*  @param lookupData [in] One of the #GnLookupData values
*  @param bEnable    [in] Set lookup data
*  @ingroup MusicId_Options
*/
  public void LookupData(GnLookupData lookupData, bool bEnable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_LookupData(swigCPtr, (int)lookupData, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Set the preferred language for the returned results.
*  @param preferredLanguage [in] One of the GNSDK language values
*  @ingroup MusicId_Options
*/
  public void PreferResultLanguage(GnLanguage preferredLanguage) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_PreferResultLanguage(swigCPtr, (int)preferredLanguage);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Set the preferred external ID of the returned results.
*  Only available where single result is also requested.
*  @param strExternalId [in] Gracenote external ID source name
*  @ingroup MusicId_Options
*/
  public void PreferResultExternalId(string strExternalId) {
  System.IntPtr tempstrExternalId = GnMarshalUTF8.NativeUtf8FromString(strExternalId);
    try {
      gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_PreferResultExternalId(swigCPtr, tempstrExternalId);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempstrExternalId);
    }
  }

/**
*  Set that you would like cover art (if availble) in the returned results.
*  @param bEnable [in] Set prefer cover art
*  @ingroup MusicId_Options
*/
  public void PreferResultCoverart(bool bEnable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_PreferResultCoverart(swigCPtr, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Set that the response must return only a single best result.
*  When enabled, a single full result is returned; when disabled, multiple partial results may be returned.
*  @param bEnable [in] Set single result
*  <p><b>Remarks:</b></p>
*  If enabled, the MusicID library selects the single best result based on the query type and input.
*  @ingroup MusicId_Options
*/
  public void ResultSingle(bool bEnable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_ResultSingle(swigCPtr, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Enable or disable revision check option.
*  @param bEnable [in] Set revision check
*
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*  @ingroup MusicId_Options
*/
  public void RevisionCheck(bool bEnable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_RevisionCheck(swigCPtr, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Specfies whether a response must return a range of results beginning at a specified value.
*  @param resultStart  [in] Result range start value
*  <p><b>Remarks:</b></p>
*  This option is useful for paging through results.
*  <p><b>Note:</b></p>
*  Gracenote Service enforces that the range start value must be less than or equal to the total
*  number of results. If you specify a range start value that is greater than the total number of
*  results, no results are returned.
*  @ingroup MusicId_Options
*/
  public void ResultRangeStart(uint resultStart) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_ResultRangeStart(swigCPtr, resultStart);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Set the maximum number of results to return.
*  @param resultCount  [in] Maximum results
*  <p><b>Note:</b></p>
*  Gracenote Service enforces its own maximum number of results that can vary over time and query types.
*  This setting sets a maximum that can be as high as the Service maximum  but not higher.
*  @ingroup MusicId_Options
*/
  public void ResultCount(uint resultCount) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_ResultCount(swigCPtr, resultCount);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interfaces. Otherwise, the operating system determines the interface to use.
*  @param intfName [in] Local IP address or system name for the desired network interface
*  @ingroup MusicId_Options
*/
  public void NetworkInterface(string intfName) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_NetworkInterface__SWIG_0(swigCPtr, intfName);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Return the network interface being used with this object's connections if one has been set.
* If no specific network interface has been set, this option returns an empty string.
*  @ingroup MusicId_Options
*/
  public string NetworkInterface() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_NetworkInterface__SWIG_1(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Specifies whether GnMuisicId processes received audio for music identification
* suitability.
* This option is experimental and subject to change
* @ingroup MusicId_Options
*/
  public void AudioSuitabilityProcessing(bool bEnable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_AudioSuitabilityProcessing(swigCPtr, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Set option using option name
*  @param option   [in] Option name
*  @param value	[in] Option value
*  @ingroup MusicId_Options
*/
  public void Custom(string option, string value) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_Custom__SWIG_0(swigCPtr, option, value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Set option using option name
*  @param option   [in] Option name
*  @param bEnable	[in] Option enable true/false
*  @ingroup MusicId_Options
*/
  public void Custom(string option, bool bEnable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdOptions_Custom__SWIG_1(swigCPtr, option, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
