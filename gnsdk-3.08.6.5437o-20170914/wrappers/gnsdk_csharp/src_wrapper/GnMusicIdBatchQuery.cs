
namespace GracenoteSDK {

/**
* \class GnMusicIdBatchQuery
* Configures query for GnMusicIdBatch
*/
public class GnMusicIdBatchQuery : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GnMusicIdBatchQuery(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnMusicIdBatchQuery obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnMusicIdBatchQuery() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnMusicIdBatchQuery(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

/**
*  Constructs a batch music identification query object with a unique identifier
*  @param batch		[in] GnMusicIdBatch object to use with query
*  @param unique_id	[in] Unique identifier for batch query
*/
  public GnMusicIdBatchQuery(GnMusicIdBatch batch, string uniqueId) : this(gnsdk_csharp_marshalPINVOKE.new_GnMusicIdBatchQuery(GnMusicIdBatch.getCPtr(batch), uniqueId), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Sets externally- and internally-generated Gracenote fingerprint
*  fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint data.
*	Use with GnMusicIdBatch::GetAlbums
*  @param strFingerprintData	[in] Audio source to fingerprint
*  @param fpType				[in] One of the GnFingerprintType fingerprint data types,
*/
  public void SetFingerprint(string strFingerprintData, GnFingerprintType fpType) {
  System.IntPtr tempstrFingerprintData = GnMarshalUTF8.NativeUtf8FromString(strFingerprintData);
    try {
      gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchQuery_SetFingerprint(swigCPtr, tempstrFingerprintData, (int)fpType);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempstrFingerprintData);
    }
  }

/**
*  Sets metadata::GnDataObject, use with GnMusicIdBatch::GetAlbums
*  @param gnObj				[in] An metadata::GnDataObject object
*/
  public void SetGDO(GnDataObject gnObj) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchQuery_SetGDO(swigCPtr, GnDataObject.getCPtr(gnObj));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Sets text string, use with GnMusicIdBatch::GetAlbums and GnMusicIdBatch::GetMatches
*  @param albumTitle			[in] Album title string
*  @param trackTitle			[in] Track title string
*  @param albumArtistName		[in] Album artist string
*  @param trackArtistName		[in] Track artist string
*  @param composerName			[in] Composer string
*/
  public void SetText(string albumTitle, string trackTitle, string albumArtistName, string trackArtistName, string composerName) {
  System.IntPtr tempalbumTitle = GnMarshalUTF8.NativeUtf8FromString(albumTitle);
  System.IntPtr temptrackTitle = GnMarshalUTF8.NativeUtf8FromString(trackTitle);
  System.IntPtr tempalbumArtistName = GnMarshalUTF8.NativeUtf8FromString(albumArtistName);
  System.IntPtr temptrackArtistName = GnMarshalUTF8.NativeUtf8FromString(trackArtistName);
  System.IntPtr tempcomposerName = GnMarshalUTF8.NativeUtf8FromString(composerName);
    try {
      gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchQuery_SetText(swigCPtr, tempalbumTitle, temptrackTitle, tempalbumArtistName, temptrackArtistName, tempcomposerName);
      if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempalbumTitle);
 GnMarshalUTF8.ReleaseMarshaledUTF8String(temptrackTitle);
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempalbumArtistName);
 GnMarshalUTF8.ReleaseMarshaledUTF8String(temptrackArtistName);
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempcomposerName);
    }
  }

/**
*  Sets TOC Offset
*  @param strCDTOC				[in] CD TOC string
*/
  public void SetTOCOffset(uint tocOffset) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchQuery_SetTOCOffset(swigCPtr, tocOffset);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Sets CDTOC string, use with GnMusicIdBatch::GetAlbums
*  @param strCDTOC				[in] CD TOC string
*/
  public void SetTOC(string strTOC) {
    gnsdk_csharp_marshalPINVOKE.GnMusicIdBatchQuery_SetTOC(swigCPtr, strTOC);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
