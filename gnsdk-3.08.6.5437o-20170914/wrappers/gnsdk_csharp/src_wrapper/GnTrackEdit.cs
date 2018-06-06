
namespace GracenoteSDK {

/**
*  @internal GnTrackEdit @endinternal
*  represents  Track's information returned by Gracenote.
*/
public class GnTrackEdit : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnTrackEdit(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnTrackEdit_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnTrackEdit obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnTrackEdit() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnTrackEdit(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public GnCreditEdit Credit(uint ord) {
    GnCreditEdit ret = new GnCreditEdit(gnsdk_csharp_marshalPINVOKE.GnTrackEdit_Credit(swigCPtr, ord), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Mood(GnListElement moodElement) {
    gnsdk_csharp_marshalPINVOKE.GnTrackEdit_Mood(swigCPtr, GnListElement.getCPtr(moodElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Tempo(GnListElement tempoElement) {
    gnsdk_csharp_marshalPINVOKE.GnTrackEdit_Tempo(swigCPtr, GnListElement.getCPtr(tempoElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Genre(GnListElement genreElement) {
    gnsdk_csharp_marshalPINVOKE.GnTrackEdit_Genre(swigCPtr, GnListElement.getCPtr(genreElement));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
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
		gnsdk_csharp_marshalPINVOKE.GnTrackEdit_Year_set(swigCPtr, tempvalue);
		GnMarshalUTF8.ReleaseMarshaledUTF8String(tempvalue);
	}
 
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnTrackEdit_Year_get(swigCPtr) );
	} 

  }

/**
*  @internal getArtistEdit @endinternal
*  Create an empty object of GnArtistEdit using ARTIST.
*  @return GnArtistEdit
*/
  public GnArtistEdit Artist {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnTrackEdit_Artist_get(swigCPtr);
      GnArtistEdit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnArtistEdit(cPtr, true);
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
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnTrackEdit_CreditAdd_get(swigCPtr);
      GnCreditEdit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnCreditEdit(cPtr, true);
      return ret;
    } 
  }

/**
*  @internal getWorkEdit @endinternal
*  Create an empty object of GnAudioWorkEdit using AUDIO WORK.
*  @return GnAudioWorkEdit
*/
  public GnAudioWorkEdit AudioWork {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnTrackEdit_AudioWork_get(swigCPtr);
      GnAudioWorkEdit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnAudioWorkEdit(cPtr, true);
      return ret;
    } 
  }

/**
*  @internal getTitleEdit @endinternal
*  Create an empty object of GnTitleEdit using TITLE OFFICIAL.
*  @return GnTitleEdit
*/
  public GnTitleEdit Title {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnTrackEdit_Title_get(swigCPtr);
      GnTitleEdit ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnTitleEdit(cPtr, true);
      return ret;
    } 
  }

  public GnTrack GnTrack {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnTrackEdit_GnTrack_get(swigCPtr);
      GnTrack ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnTrack(cPtr, true);
      return ret;
    } 
  }

}

}
