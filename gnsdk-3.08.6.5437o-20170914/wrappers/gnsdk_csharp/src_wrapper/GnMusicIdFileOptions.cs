
namespace GracenoteSDK {

/**
* Configures options for GnMusicIdFile
*/
public class GnMusicIdFileOptions : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMusicIdFileOptions(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMusicIdFileOptions obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMusicIdFileOptions() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMusicIdFileOptions(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
*  Indicates whether the MusicID-File query should be performed against local embedded databases or online.
*  @param lookupMode		[in] One of the GnLookupMode values
*  @ingroup MusicIdFile_Options
*/
  public void LookupMode(GnLookupMode lookupMode) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFileOptions_LookupMode(swigCPtr, (int)lookupMode);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Sets the lookup data value for the MusicID-File query.
*  @param val 				[in] Set One of the GnLookupData values
*  @param enable 			[in] True or false to enable or disable
*  @ingroup MusicIdFile_Options
*/
  public void LookupData(GnLookupData val, bool enable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFileOptions_LookupData(swigCPtr, (int)val, enable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Sets the batch size for the MusicID-File query.
*  @param size				[in] set String value or one of MusicID-File Option Values that corresponds to BATCH_SIZE
*  <p><b>Remarks:</b></p>
*  The option value provided for batch size must be greater than zero (0).
*  @ingroup MusicIdFile_Options
*/
  public void BatchSize(uint size) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFileOptions_BatchSize(swigCPtr, size);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Indicates whether MusicID-File should process the responses online, thus reducing client-used resources.
*  Your license must allow online processing.
*  @param enable			[in] True or false to enable or disable
*  @ingroup MusicIdFile_Options
*/
  public void OnlineProcessing(bool enable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFileOptions_OnlineProcessing(swigCPtr, enable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Sets the preferred language for the MusicID-File query.
*  @param preferredLangauge	[in] One of the GNSDK language values
*  @ingroup MusicIdFile_Options
*/
  public void PreferResultLanguage(GnLanguage preferredLangauge) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFileOptions_PreferResultLanguage(swigCPtr, (int)preferredLangauge);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Use this option to specify an external identifier which MusicID-File should try to include in any responses that are returned.
*  <p><b>Remarks:</b></p>
* This option is currently only supported when online processing is enabled.
*  @param preferredExternalId	[in] The name of an external identifier that should be preferred when selecting matches
*  @ingroup MusicIdFile_Options
*/
  public void PreferResultExternalId(string preferredExternalId) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFileOptions_PreferResultExternalId(swigCPtr, preferredExternalId);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Sets the thread priority for a given MusicID-File query.
*  @param threadPriority 	[in] Set one of GnThreadPriority values that corresponds to thread priority
*  <p><b>Remarks:</b></p>
*  The option value provided for thread priority must be one of the defined
*  #GnThreadPriority values.
*  @ingroup MusicIdFile_Options
*/
  public void ThreadPriority(GnThreadPriority threadPriority) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFileOptions_ThreadPriority(swigCPtr, (int)threadPriority);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
*  @param intfName [in] Local IP address or system name for the desired network interface
*  @ingroup MusicIdFile_Options
*/
  public void NetworkInterface(string intfName) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFileOptions_NetworkInterface__SWIG_0(swigCPtr, intfName);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Return network interface being used with this object's connections if one has been set.
* If no specific network interface has been set, an empty string is returned.
*  @ingroup MusicIdFile_Options
*/
  public string NetworkInterface() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnMusicIdFileOptions_NetworkInterface__SWIG_1(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  General option setting for custom options
*  @param optionKey		[in] Set one of the MusicID-File option keys
*  @param enable			[in] Set to true (enable) or false (disable)
*  @ingroup MusicIdFile_Options
*/
  public void Custom(string optionKey, bool enable) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFileOptions_Custom__SWIG_0(swigCPtr, optionKey, enable);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Set option using option name
*  @param option			[in] Option name
*  @param value			[in] Option value
*  @ingroup MusicIdFile_Options
*/
  public void Custom(string option, string value) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdFileOptions_Custom__SWIG_1(swigCPtr, option, value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
