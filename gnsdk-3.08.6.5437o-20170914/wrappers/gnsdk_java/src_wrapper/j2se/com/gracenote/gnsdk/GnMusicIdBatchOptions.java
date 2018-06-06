
package com.gracenote.gnsdk;

/** 
** Configures options for {@link GnMusicIdBatch} 
*/ 
 
public class GnMusicIdBatchOptions {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnMusicIdBatchOptions(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnMusicIdBatchOptions obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnMusicIdBatchOptions(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

/** 
*  Indicate whether the MusicID query should be performed against local embedded databases or online. 
*  @param lookupMode  [in] One of the {@link GnLookupMode} values 
* 
*/ 
 
  public void lookupMode(GnLookupMode lookupMode) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchOptions_lookupMode__SWIG_0(swigCPtr, this, lookupMode.swigValue());
  }

/** 
*  Return current lookup mode for MusicID query 
* 
*/ 
 
  public GnLookupMode lookupMode() throws com.gracenote.gnsdk.GnException {
    return GnLookupMode.swigToEnum(gnsdk_javaJNI.GnMusicIdBatchOptions_lookupMode__SWIG_1(swigCPtr, this));
  }

/** 
*  Set the lookup data value for the MusicID query. 
*  @param lookupData [in] One of the {@link GnLookupData} values 
*  @param bEnable    [in] Set lookup data 
* 
*/ 
 
  public void lookupData(GnLookupData lookupData, boolean bEnable) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchOptions_lookupData(swigCPtr, this, lookupData.swigValue(), bEnable);
  }

/** 
*  Set the preferred language for the returned results. 
*  @param preferredLanguage [in] One of the GNSDK language values 
* 
*/ 
 
  public void preferResultLanguage(GnLanguage preferredLanguage) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchOptions_preferResultLanguage(swigCPtr, this, preferredLanguage.swigValue());
  }

/** 
*  Set the preferred external ID of the returned results. 
*  Only available where single result is also requested. 
*  @param strExternalId [in] Gracenote external ID source name 
* 
*/ 
 
  public void preferResultExternalId(String strExternalId) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchOptions_preferResultExternalId(swigCPtr, this, strExternalId);
  }

/** 
*  Set that you would like cover art (if availble) in the returned results. 
*  @param bEnable [in] Set prefer cover art 
* 
*/ 
 
  public void preferResultCoverart(boolean bEnable) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchOptions_preferResultCoverart(swigCPtr, this, bEnable);
  }

/** 
*  Indicates whether the query should attempt to lookup & include the requested image size in the response. 
*  @param {@link GnImageSize}  [in] One of the {@link GnImageSize} values 
* 
*/ 
 
  public void inlineImage(GnImageSize imageSize) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchOptions_inlineImage(swigCPtr, this, imageSize.swigValue());
  }

/** 
*  Enable or disable revision check option. 
*  @param bEnable [in] Set revision check 
* <p> 
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup) 
* 
*/ 
 
  public void revisionCheck(boolean bEnable) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchOptions_revisionCheck(swigCPtr, this, bEnable);
  }

/** 
* Set a specific network interface to use with this object's connections. This can be useful for 
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use. 
*  @param intfName [in] Local IP address or system name for the desired network interface 
* 
*/ 
 
  public void networkInterface(String intfName) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchOptions_networkInterface__SWIG_0(swigCPtr, this, intfName);
  }

/** 
* Return the network interface being used with this object's connections if one has been set. 
* If no specific network interface has been set, this option returns an empty string. 
* 
*/ 
 
  public String networkInterface() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnMusicIdBatchOptions_networkInterface__SWIG_1(swigCPtr, this);
  }

/** 
*  Set option using option name 
*  @param option   [in] Option name 
*  @param value	[in] Option value 
* 
*/ 
 
  public void custom(String option, String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchOptions_custom__SWIG_0(swigCPtr, this, option, value);
  }

/** 
*  Set option using option name 
*  @param option   [in] Option name 
*  @param bEnable	[in] Option enable true/false 
* 
*/ 
 
  public void custom(String option, boolean bEnable) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdBatchOptions_custom__SWIG_1(swigCPtr, this, option, bEnable);
  }

}
