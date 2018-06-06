
namespace GracenoteSDK {

/**
*  @internal GnAlbumEdit @endinternal
*  represents  Album's information returned by Gracenote.
*/
public class GnAlbumEdit : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnAlbumEdit(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnAlbumEdit obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnAlbumEdit() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnAlbumEdit(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public void Genre(GnListElement genreElement) {
    gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_Genre(swigCPtr, GnListElement.getCPtr(genreElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Language(GnListElement langElement) {
    gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_Language(swigCPtr, GnListElement.getCPtr(langElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  @internal TOCSet @endinternal
*  Sets a list-based value by the list item Submit ID for TOC ALBUM. If the value does not
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the
*   value is deleted.
*  @param value set Value corresponding to the specified GnDataObject value key
*  <p><b>Remarks:</b></p>
*  Use this function to set a list-based Submit ID to TOC ALBUM, prior to adding the GnDataObject to a
*   parcel.
*/
  public string CdToc() {
	System.IntPtr temp = gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_CdToc__SWIG_0(swigCPtr); 
	return GnMarshalUTF8.StringFromNativeUtf8(temp);
}

  public void CdToc(string value) {
    gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_CdToc__SWIG_1(swigCPtr, value);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  @internal TrackEdit @endinternal
*  Create an empty object of GnTrackEdit using TRACK.
*  @return GnTrackEdit
*/
  public GnTrackEdit Track(uint trackNum) {
    GnTrackEdit ret = new GnTrackEdit(gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_Track(swigCPtr, trackNum), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public GnCreditEdit Credit(uint ord) {
    GnCreditEdit ret = new GnCreditEdit(gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_Credit(swigCPtr, ord), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
*  @internal Year @endinternal
*  Sets a list-based value by the list item Submit ID for YEAR. If the value does not
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the
*   value is deleted.
*  @param value set Value corresponding to the specified GnDataObject value key
*  <p><b>Remarks:</b></p>
*  Use this function to set a list-based Submit ID to YEAR, prior to adding the GnDataObject to a
*   parcel.
*/
  public string Year {
	/* csvarin typemap code */
	set 
	{
		System.IntPtr tempvalue = GnMarshalUTF8.NativeUtf8FromString(value);
		gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_Year_set(swigCPtr, tempvalue);
		GnMarshalUTF8.ReleaseMarshaledUTF8String(tempvalue);
	}
 
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_Year_get(swigCPtr) );
	} 

  }

/**
*  @internal LabelSet @endinternal
*  Sets a list-based value by the list item Submit ID for album_lable . If the value does not
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the
*   value is deleted.
*  @param value set Value corresponding to the specified GnDataObject value key
*  <p><b>Remarks:</b></p>
*  Use this function to set a list-based Submit ID to album_lable , prior to adding the GnDataObject to a
*   parcel.
*/
  public string Label {
	/* csvarin typemap code */
	set 
	{
		System.IntPtr tempvalue = GnMarshalUTF8.NativeUtf8FromString(value);
		gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_Label_set(swigCPtr, tempvalue);
		GnMarshalUTF8.ReleaseMarshaledUTF8String(tempvalue);
	}
 
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_Label_get(swigCPtr) );
	} 

  }

/**
*  @internal DiscInSet @endinternal
*  Sets the volume number of disc in a multi-disc set
*  @param discNumber set to the volume number of this disc
*  @param totalDiscs set to the total discs in volume
*  <p><b>Remarks:</b></p>
*  Use this function to set a list-based Submit ID to DISC_IN_SET, prior to adding the GnDataObject to a
*   parcel.
*/
  public uint DiscInSet {
    set {
      gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_DiscInSet_set(swigCPtr, value);
    } 
    get {
      uint ret = gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_DiscInSet_get(swigCPtr);
      return ret;
    } 
  }

  public uint TotalInSet {
    set {
      gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_TotalInSet_set(swigCPtr, value);
    } 
    get {
      uint ret = gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_TotalInSet_get(swigCPtr);
      return ret;
    } 
  }

/**
*  @internal IsCompilation @endinternal
*  Sets a list-based value by the list item Submit ID for ALBUM_COMPILATION . If the value does not
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the
*   value is deleted.
*  @param value set Value corresponding to the specified GnDataObject value key
*  <p><b>Remarks:</b></p>
*  Use this function to set a list-based Submit ID to ALBUM_COMPILATION, prior to adding the GnDataObject to a
*   parcel.
*/
  public bool IsCompilation {
    set {
      gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_IsCompilation_set(swigCPtr, value);
    } 
    get {
      bool ret = gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_IsCompilation_get(swigCPtr);
      return ret;
    } 
  }

/**
*  @internal setClassical @endinternal
*  Sets a list-based value by the list item Submit ID for CLASSICAL_DATA. If the value does not
*   exist, it is added. If the value does exist, it is changed. If the role_submit_id is 0, the
*   value is deleted.
*  @param value set Value corresponding to the specified GnDataObject value key
*  <p><b>Remarks:</b></p>
*  Use this function to set a list-based Submit ID to CLASSICAL_DATA, prior to adding the GnDataObject to a
*   parcel.
*/
  public bool IsClassical {
    set {
      gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_IsClassical_set(swigCPtr, value);
    } 
    get {
      bool ret = gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_IsClassical_get(swigCPtr);
      return ret;
    } 
  }

/**
*  @internal ArtistEdit @endinternal
*  Create an empty object of GnArtistEdit using ARTIST.
*  @return GnArtistEdit
*/
  public GnArtistEdit Artist {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_Artist_get(swigCPtr);
      GnArtistEdit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnArtistEdit(cPtr, true);
      return ret;
    } 
  }

/**
*  @internal TitleEdit @endinternal
*  Create an empty object of GnTitleEdit using TITLE OFFICIAL.
*  @return GnTitleEdit
*/
  public GnTitleEdit Title {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_Title_get(swigCPtr);
      GnTitleEdit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnTitleEdit(cPtr, true);
      return ret;
    } 
  }

/**
*  @internal CreditAdd @endinternal
*  Create an empty object of GnCreditEdit using CREDIT.
*  @return GnCreditEdit
*/
  public GnCreditEdit CreditAdd {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_CreditAdd_get(swigCPtr);
      GnCreditEdit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnCreditEdit(cPtr, true);
      return ret;
    } 
  }

  public GnAlbum GnAlbum {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_GnAlbum_get(swigCPtr);
      GnAlbum ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnAlbum(cPtr, true);
      return ret;
    } 
  }

  public GnTrackEditEnumerable Tracks {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnAlbumEdit_Tracks_get(swigCPtr);
      GnTrackEditEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnTrackEditEnumerable(cPtr, true);
      return ret;
    } 
  }

}

}
