
namespace GracenoteSDK {

/**
*
* GnLookupLocal
*
* Provides services for local lookup of various identification queries such as
* text and CD TOC search and provides services for local retreival of content
* such as cover art.
*
* <b>SDK Documentation</b>
*
* Topic: .../docs/html-oo > index.html > Implementing Applications (All Platforms) > Enabling and Using GNSDK Storage
*
* For more information on GNSDK storage, see the above topic which covers:
* <ul>
*     <li>How to enable and manage GNSDK storage</li>
*     <li>Enabling a provider for GNSDK storage</li>
*     <li>Enabling storage code samples</li>
*     <li>GNSDK stores</li>
*     <li>GNSDK databases</li>
*     <li>Setting GNSDK storage folder locations</li>
*     <li>Setting a storage folder location code samples</li>
*     <li>Storing query results in local storage</li>
*     <li>Storing query results in local storage code samples</li>
*     <li>Getting local lookup database information</li>
*     <li>Setting online cache expiration</li>
*     <li>Managing online cache size and memory</li>
* </ul>
*
* <b>Sample App</b>
*
*     - .../samples/musicid_lookup_album_local_online
*/
public class GnLookupLocal : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnLookupLocal(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnLookupLocal obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnLookupLocal() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnLookupLocal(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
* Enable local lookup for various identification queries such as
* text and CD TOC search; plus enable services for local retreival of
* content such as cover art.
* @ingroup Music_LookupLocal_InitializationFunctions
*/
  public static GnLookupLocal Enable() {
    GnLookupLocal ret = new GnLookupLocal(gnsdk_csharp_marshalPINVOKE.GnLookupLocal_Enable(), false);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Sets location where GNSDK can find a specific local lookup database
*	@param storageName 		[in] local storage name
*	@param storageLocation 	[in] local storage location
*/
  public void StorageLocation(GnLocalStorageName storageName, string storageLocation) {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocal_StorageLocation(swigCPtr, (int)storageName, storageLocation);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Validate named local storage.
*	@param storageName [in] local storage name
*/
  public void StorageValidate(GnLocalStorageName storageName) {
    gnsdk_csharp_marshalPINVOKE.GnLookupLocal_StorageValidate(swigCPtr, (int)storageName);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Retrieves the Local Storage information for named storage
*  @param storageName 		[in] local storage name
*  @param storageInfo 		[in] local storage info type
*  @param ordinal 			[in] ordinal
*  @return info string if successful, GNSDK_NULL if not successful
*/
  public string StorageInfo(GnLocalStorageName storageName, GnLocalStorageInfo storageInfo, uint ordinal) {
    string ret = gnsdk_csharp_marshalPINVOKE.GnLookupLocal_StorageInfo(swigCPtr, (int)storageName, (int)storageInfo, ordinal);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Retrieves the Local Storage information count for named storage
*  @param storageName 		[in] local storage name
*  @param storageInfo 		[in] local storage info type
*  @return count if successful, 0 if not successful
*/
  public uint StorageInfoCount(GnLocalStorageName storageName, GnLocalStorageInfo storageInfo) {
    uint ret = gnsdk_csharp_marshalPINVOKE.GnLookupLocal_StorageInfoCount(swigCPtr, (int)storageName, (int)storageInfo);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  Version
*  Retrieves the Lookup Local SDK version string.
*  @return version string if successful
*  @return GNSDK_NULL if not successful
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after you have instantiated a GnManager instance. The returned
*  string is a constant. Do not attempt to modify or delete.
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
*/
  public string Version {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnLookupLocal_Version_get(swigCPtr) );
	} 

  }

/**
*  BuildDate
*  Retrieves the Lookup Local SDK's build date string.
*  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after you have instantiated a GnManager instance. The returned
*   string is a constant. Do not attempt to modify or delete.
*  Example build date string: 2008-02-12 00:41 UTC
*/
  public string BuildDate {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnLookupLocal_BuildDate_get(swigCPtr) );
	} 

  }

}

}
