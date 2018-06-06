
package com.gracenote.gnsdk;

/** 
* <b>Experimental</b>: Provides access to information regarding the underlying 
* GNSDK playlist library. For working with user collections to create playlists 
* see {@link GnPlaylistCollection}. 
*/ 
 
public class GnPlaylist {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnPlaylist(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnPlaylist obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnPlaylist(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public GnPlaylist() throws com.gracenote.gnsdk.GnException {
    this(gnsdk_javaJNI.new_GnPlaylist(), true);
  }

/** 
*  Retrieves the Playlist SDK version string. 
*  @return version string if successful 
*  @return GNSDK_NULL if not successful 
*  <p><b>Remarks:</b></p> 
*  You can call this API at any time after successfully getting a {@link GnManager} instance. The returned 
*   string is a constant. Do not attempt to modify or delete. 
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build) 
*  Major: New functionality 
*  Minor: New or changed features 
*  Improvement: Improvements and fixes 
*  Build: Internal build number 
* 
*/ 
 
  public static String version() {
    return gnsdk_javaJNI.GnPlaylist_version();
  }

/** 
*  Retrieves the Playlist SDK's build date string. 
*  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC 
*  <p><b>Remarks:</b></p> 
*  You can call this API at any time after successfully getting a {@link GnManager} instance. The returned 
*   string is a constant. Do not attempt to modify or delete. 
*  Example build date string: 2008-02-12 00:41 UTC 
* 
*/ 
 
  public static String buildDate() {
    return gnsdk_javaJNI.GnPlaylist_buildDate();
  }

/** 
*  Media attributes support for playlist generation such as album title, 
*  artist name, and artist type. 
*  @return Playlist attribute iterator 
*/ 
 
  public GnPlaylistAttributeIterable attributesSupported() {
    return new GnPlaylistAttributeIterable(gnsdk_javaJNI.GnPlaylist_attributesSupported(swigCPtr, this), true);
  }

}
