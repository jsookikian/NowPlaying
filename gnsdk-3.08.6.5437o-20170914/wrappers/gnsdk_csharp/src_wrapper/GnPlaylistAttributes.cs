
namespace GracenoteSDK {

/**
* <b>Experimental</b>: GnPlaylistAttributes
*/
public class GnPlaylistAttributes : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnPlaylistAttributes(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnPlaylistAttributes_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnPlaylistAttributes obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnPlaylistAttributes() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnPlaylistAttributes(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public GnPlaylistAttributes(GnPlaylistAttributes other) : this(gnsdk_csharp_marshalPINVOKE.new_GnPlaylistAttributes(GnPlaylistAttributes.getCPtr(other)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
*  Retrieves attribute value by given attribute name.
*  @return attribute string value if it exists else an empty string.
*
**/
  public string Value(string attrName) {
	System.IntPtr temp = gnsdk_csharp_marshalPINVOKE.GnPlaylistAttributes_Value(swigCPtr, attrName); 
	return GnMarshalUTF8.StringFromNativeUtf8(temp);
}

/**
*  Retrieves the AlbumName value as a string for this attribute.
*  @return album name string value if it exists else an empty string.
*
**/
  public string AlbumName {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnPlaylistAttributes_AlbumName_get(swigCPtr) );
	} 

  }

/**
*  Retrieves the ArtistName value as a string for this attribute.
*  @return artist name string value if it exists else an empty string.
*
**/
  public string ArtistName {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnPlaylistAttributes_ArtistName_get(swigCPtr) );
	} 

  }

/**
*  Retrieves the ArtistType value as a string for this attribute.
*  @return artist type string value if it exists else an empty string.
*
**/
  public string ArtistType {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnPlaylistAttributes_ArtistType_get(swigCPtr) );
	} 

  }

/**
*  Retrieves the Era value as a string for this attribute.
*  @return era string value if it exists else an empty string.
*
**/
  public string Era {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnPlaylistAttributes_Era_get(swigCPtr) );
	} 

  }

/**
*  Retrieves the Genre value as a string for this attribute.
*  @return genre string value if it exists else an empty string.
*
**/
  public string Genre {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnPlaylistAttributes_Genre_get(swigCPtr) );
	} 

  }

/**
*  Retrieves the Origin value as a string for this attribute.
*  @return origin string value if it exists else an empty string.
*
**/
  public string Origin {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnPlaylistAttributes_Origin_get(swigCPtr) );
	} 

  }

/**
*  Retrieves the Mood value as a string for this attribute.
*  @return mood string value if it exists else an empty string.
*
**/
  public string Mood {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnPlaylistAttributes_Mood_get(swigCPtr) );
	} 

  }

/**
*  Retrieves the Tempo value as a string for this attribute.
*  @return tempo string value if it exists else an empty string.
*
**/
  public string Tempo {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnPlaylistAttributes_Tempo_get(swigCPtr) );
	} 

  }

}

}
