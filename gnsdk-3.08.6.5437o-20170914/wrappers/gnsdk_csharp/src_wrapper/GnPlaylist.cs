
namespace GracenoteSDK {

/**
* <b>Experimental</b>: Provides access to information regarding the underlying
* GNSDK playlist library. For working with user collections to create playlists
* see GnPlaylistCollection.
*/
public class GnPlaylist : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnPlaylist(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnPlaylist obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnPlaylist() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnPlaylist(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public GnPlaylist() : this(gnsdk_csharp_marshalPINVOKE.new_GnPlaylist(), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/** @internal Version @endinternal
*  Retrieves the Playlist SDK version string.
*  @return version string if successful
*  @return GNSDK_NULL if not successful
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully getting a GnManager instance. The returned
*   string is a constant. Do not attempt to modify or delete.
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
* @ingroup Music_Playlist_InitializationFunctions
*/
  public string Version {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnPlaylist_Version_get(swigCPtr) );
	} 

  }

/** @internal BuildDate @endinternal
*  Retrieves the Playlist SDK's build date string.
*  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully getting a GnManager instance. The returned
*   string is a constant. Do not attempt to modify or delete.
*  Example build date string: 2008-02-12 00:41 UTC
* @ingroup Music_Playlist_InitializationFunctions
*/
  public string BuildDate {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnPlaylist_BuildDate_get(swigCPtr) );
	} 

  }

  public GnPlaylistAttributeEnumerable AttributesSupported {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnPlaylist_AttributesSupported_get(swigCPtr);
      GnPlaylistAttributeEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnPlaylistAttributeEnumerable(cPtr, true);
      return ret;
    } 
  }

}

}
