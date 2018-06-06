
namespace GracenoteSDK {

/**
* Provides access to content assets that can be retrieved from Urls.
* Content is only available is content is enabled from the original query's lookup data.
* Use the query object's options to enable content.
* The type of content that is available depends on the parent object. For example
* you can access album cover art from a GnAlbum object, but not an artist image. To
* retrieve an artist image navigate to a GnContributor object and invoke it's GnContent
* instance.
*
* <p><b>SDK Documentation</b></p>
*
* Topic:  Data Models
*
*  The above topic displays all the metadata returned from a recognition event,
*  including objects containing a GnContent object.
*  It does this in an expand/collapse format, showing object hierarchy and
*  a description of each field returned.
*
*/
public class GnContent : GnDataObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnContent(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnContent_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnContent obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnContent() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnContent(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

/**
* Asset by image size (if applicable)
* @param imageSize	[in] Image size
* @return Asset object
*/
  public GnAsset Asset(GnImageSize imageSize) {
    GnAsset ret = new GnAsset(gnsdk_csharp_marshalPINVOKE.GnContent_Asset(swigCPtr, (int)imageSize), true);
    return ret;
  }

  public string Id {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnContent_Id_get(swigCPtr) );
	} 

  }

/**
*  Content's mime type
*  @return Mime type
*/
  public string MimeType {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnContent_MimeType_get(swigCPtr) );
	} 

  }

/**
*  Content type - cover art, biography, etc.
*  @return Content type
*/
  public GnContentType ContentType {
    get {
      GnContentType ret = (GnContentType)gnsdk_csharp_marshalPINVOKE.GnContent_ContentType_get(swigCPtr);
      return ret;
    } 
  }

  public GnAssetEnumerable Assets {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnContent_Assets_get(swigCPtr);
      GnAssetEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnAssetEnumerable(cPtr, true);
      return ret;
    } 
  }

}

}
