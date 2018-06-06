
namespace GracenoteSDK {

/**
* \class GnMusicIdBatchOptions
* Configures options for GnMusicIdBatch
*/
public class GnMusicIdBatchOptions : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMusicIdBatchOptions(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMusicIdBatchOptions obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMusicIdBatchOptions() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMusicIdBatchOptions(swigCPtr);
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
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchOptions_LookupMode__SWIG_0(swigCPtr, (int)lookupMode);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Return current lookup mode for MusicID query
*  @ingroup MusicId_Options
*/
  public GnLookupMode LookupMode() {
    GnLookupMode ret = (GnLookupMode)gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchOptions_LookupMode__SWIG_1(swigCPtr);
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
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchOptions_LookupData(swigCPtr, (int)lookupData, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Set the preferred language for the returned results.
*  @param preferredLanguage [in] One of the GNSDK language values
*  @ingroup MusicId_Options
*/
  public void PreferResultLanguage(GnLanguage preferredLanguage) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchOptions_PreferResultLanguage(swigCPtr, (int)preferredLanguage);
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
      gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchOptions_PreferResultExternalId(swigCPtr, tempstrExternalId);
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
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchOptions_PreferResultCoverart(swigCPtr, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Indicates whether the query should attempt to lookup & include the requested image size in the response.
*  @param GnImageSize  [in] One of the #GnImageSize values
*  @ingroup MusicId_Options
*/
  public void InlineImage(GnImageSize imageSize) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchOptions_InlineImage(swigCPtr, (int)imageSize);
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
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchOptions_RevisionCheck(swigCPtr, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
*  @param intfName [in] Local IP address or system name for the desired network interface
*  @ingroup MusicId_Options
*/
  public void NetworkInterface(string intfName) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchOptions_NetworkInterface__SWIG_0(swigCPtr, intfName);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Return the network interface being used with this object's connections if one has been set.
* If no specific network interface has been set, this option returns an empty string.
*  @ingroup MusicId_Options
*/
  public string NetworkInterface() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchOptions_NetworkInterface__SWIG_1(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Set option using option name
*  @param option   [in] Option name
*  @param value	[in] Option value
*  @ingroup MusicId_Options
*/
  public void Custom(string option, string value) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchOptions_Custom__SWIG_0(swigCPtr, option, value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Set option using option name
*  @param option   [in] Option name
*  @param bEnable	[in] Option enable true/false
*  @ingroup MusicId_Options
*/
  public void Custom(string option, bool bEnable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchOptions_Custom__SWIG_1(swigCPtr, option, bEnable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
