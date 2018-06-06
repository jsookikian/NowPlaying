
namespace GracenoteSDK {

/**
* Assets for content (cover art, biography etc)
*
* <p><b>SDK Documentation</b></p>
*
* Topic:  Data Models
*
*  The above topic displays all the metadata returned from a recognition event,
*  including objects containing a GnAsset object.
*  It does this in an expand/collapse format, showing object hierarchy and
*  a description of each field returned.
*
*/
public class GnAsset : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnAsset(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnAsset_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnAsset obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnAsset() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnAsset(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

/**
*  Asset Type
*  @return asset's mime type string
*/
  public string Type() {
	System.IntPtr temp = gnsdk_csharp_marshalPINVOKE.GnAsset_Type(swigCPtr); 
	return GnMarshalUTF8.StringFromNativeUtf8(temp);
}

/**
*  GNSDK url for retrieval of asset from Gracenote
*  @return URL
*/
  public string UrlGnsdk() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnAsset_UrlGnsdk(swigCPtr);
    return ret;
  }

/**
*  HTTP url for retrieval of asset from Gracenote
*  @return URL
*/
  public string UrlHttp() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnAsset_UrlHttp(swigCPtr);
    return ret;
  }

/**
*  HTTPS url for retrieval of asset from Gracenote
*  @return URL
*/
  public string UrlHttps() {
    string ret = gnsdk_csharp_marshalPINVOKE.GnAsset_UrlHttps(swigCPtr);
    return ret;
  }

/**
*  Pixel image size of asset as defined with a GnImageSize enum, such as kImageSize110 (110x110)
*  @return Image size
*/
  public GnImageSize Size {
    get {
      GnImageSize ret = (GnImageSize)gnsdk_csharp_marshalPINVOKE.GnAsset_Size_get(swigCPtr);
      return ret;
    } 
  }

  public uint Bytes {
    get {
      uint ret = gnsdk_csharp_marshalPINVOKE.GnAsset_Bytes_get(swigCPtr);
      return ret;
    } 
  }

/**
*  Asset dimension
*  @return Dimention string
*/
  public string Dimension {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnAsset_Dimension_get(swigCPtr) );
	} 

  }

/**
* @deprecated NB: This method has been marked as deprecated and will be removed from the next major release.
*      Use UrlHttp() or UrlHttps() instead.
*/
  public string Url {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnAsset_Url_get(swigCPtr) );
	} 

  }

}

}
