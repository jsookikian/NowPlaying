
package com.gracenote.gnsdk;

/** 
* Assets for content (cover art, biography etc) 
* <p> 
* <p><b>SDK Documentation</b></p> 
* <p> 
* Topic:  Data Models 
* <p> 
*  The above topic displays all the metadata returned from a recognition event, 
*  including objects containing a {@link GnAsset} object. 
*  It does this in an expand/collapse format, showing object hierarchy and 
*  a description of each field returned. 
* <p> 
*/ 
 
public class GnAsset extends GnDataObject {
  private transient long swigCPtr;

  protected GnAsset(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnAsset_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnAsset obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnAsset(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

/** 
*  Asset dimension 
*  @return Dimention string 
*/ 
 
  public String dimension() {
    return gnsdk_javaJNI.GnAsset_dimension(swigCPtr, this);
  }

/** 
*  Asset Type 
*  @return asset's mime type string 
*/ 
 
  public String type() {
    return gnsdk_javaJNI.GnAsset_type(swigCPtr, this);
  }

  public int bytes() {
    return gnsdk_javaJNI.GnAsset_bytes(swigCPtr, this);
  }

/** 
*  Pixel image size of asset as defined with a {@link GnImageSize} enum, such as kImageSize110 (110x110) 
*  @return Image size 
*/ 
 
  public GnImageSize size() {
    return GnImageSize.swigToEnum(gnsdk_javaJNI.GnAsset_size(swigCPtr, this));
  }

/** 
* @deprecated NB: This method has been marked as deprecated and will be removed from the next major release. 
*      Use UrlHttp() or UrlHttps() instead. 
*/ 
 
  public String url() {
    return gnsdk_javaJNI.GnAsset_url(swigCPtr, this);
  }

/** 
*  GNSDK url for retrieval of asset from Gracenote 
*  @return URL 
*/ 
 
  public String urlGnsdk() {
    return gnsdk_javaJNI.GnAsset_urlGnsdk(swigCPtr, this);
  }

/** 
*  HTTP url for retrieval of asset from Gracenote 
*  @return URL 
*/ 
 
  public String urlHttp() {
    return gnsdk_javaJNI.GnAsset_urlHttp(swigCPtr, this);
  }

/** 
*  HTTPS url for retrieval of asset from Gracenote 
*  @return URL 
*/ 
 
  public String urlHttps() {
    return gnsdk_javaJNI.GnAsset_urlHttps(swigCPtr, this);
  }

}
