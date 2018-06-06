
package com.gracenote.gnsdk;

/** 
** Configures options for {@link GnMusicId} 
*/ 
 
public class GnMusicIdOptions {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnMusicIdOptions(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnMusicIdOptions obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnMusicIdOptions(swigCPtr);
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
    gnsdk_javaJNI.GnMusicIdOptions_lookupMode__SWIG_0(swigCPtr, this, lookupMode.swigValue());
  }

/** 
*  Return current lookup mode for MusicID query 
* 
*/ 
 
  public GnLookupMode lookupMode() throws com.gracenote.gnsdk.GnException {
    return GnLookupMode.swigToEnum(gnsdk_javaJNI.GnMusicIdOptions_lookupMode__SWIG_1(swigCPtr, this));
  }

/** 
*  Set the lookup data value for the MusicID query. 
*  @param lookupData [in] One of the {@link GnLookupData} values 
*  @param bEnable    [in] Set lookup data 
* 
*/ 
 
  public void lookupData(GnLookupData lookupData, boolean bEnable) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdOptions_lookupData(swigCPtr, this, lookupData.swigValue(), bEnable);
  }

/** 
*  Set the preferred language for the returned results. 
*  @param preferredLanguage [in] One of the GNSDK language values 
* 
*/ 
 
  public void preferResultLanguage(GnLanguage preferredLanguage) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdOptions_preferResultLanguage(swigCPtr, this, preferredLanguage.swigValue());
  }

/** 
*  Set the preferred external ID of the returned results. 
*  Only available where single result is also requested. 
*  @param strExternalId [in] Gracenote external ID source name 
* 
*/ 
 
  public void preferResultExternalId(String strExternalId) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdOptions_preferResultExternalId(swigCPtr, this, strExternalId);
  }

/** 
*  Set that you would like cover art (if availble) in the returned results. 
*  @param bEnable [in] Set prefer cover art 
* 
*/ 
 
  public void preferResultCoverart(boolean bEnable) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdOptions_preferResultCoverart(swigCPtr, this, bEnable);
  }

/** 
*  Set that the response must return only a single best result. 
*  When enabled, a single full result is returned; when disabled, multiple partial results may be returned. 
*  @param bEnable [in] Set single result 
*  <p><b>Remarks:</b></p> 
*  If enabled, the MusicID library selects the single best result based on the query type and input. 
* 
*/ 
 
  public void resultSingle(boolean bEnable) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdOptions_resultSingle(swigCPtr, this, bEnable);
  }

/** 
*  Enable or disable revision check option. 
*  @param bEnable [in] Set revision check 
* <p> 
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup) 
* 
*/ 
 
  public void revisionCheck(boolean bEnable) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdOptions_revisionCheck(swigCPtr, this, bEnable);
  }

/** 
*  Specfies whether a response must return a range of results beginning at a specified value. 
*  @param resultStart  [in] Result range start value 
*  <p><b>Remarks:</b></p> 
*  This option is useful for paging through results. 
*  <p><b>Note:</b></p> 
*  Gracenote Service enforces that the range start value must be less than or equal to the total 
*  number of results. If you specify a range start value that is greater than the total number of 
*  results, no results are returned. 
* 
*/ 
 
  public void resultRangeStart(long resultStart) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdOptions_resultRangeStart(swigCPtr, this, resultStart);
  }

/** 
*  Set the maximum number of results to return. 
*  @param resultCount  [in] Maximum results 
*  <p><b>Note:</b></p> 
*  Gracenote Service enforces its own maximum number of results that can vary over time and query types. 
*  This setting sets a maximum that can be as high as the Service maximum  but not higher. 
* 
*/ 
 
  public void resultCount(long resultCount) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdOptions_resultCount(swigCPtr, this, resultCount);
  }

/** 
* Set a specific network interface to use with this object's connections. This can be useful for 
* systems with multiple network interfaces. Otherwise, the operating system determines the interface to use. 
*  @param intfName [in] Local IP address or system name for the desired network interface 
* 
*/ 
 
  public void networkInterface(String intfName) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdOptions_networkInterface__SWIG_0(swigCPtr, this, intfName);
  }

/** 
* Return the network interface being used with this object's connections if one has been set. 
* If no specific network interface has been set, this option returns an empty string. 
* 
*/ 
 
  public String networkInterface() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnMusicIdOptions_networkInterface__SWIG_1(swigCPtr, this);
  }

/** 
* Specifies whether {@link GnMuisicId} processes received audio for music identification 
* suitability. 
* This option is experimental and subject to change 
* 
*/ 
 
  public void audioSuitabilityProcessing(boolean bEnable) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdOptions_audioSuitabilityProcessing(swigCPtr, this, bEnable);
  }

/** 
*  Set option using option name 
*  @param option   [in] Option name 
*  @param value	[in] Option value 
* 
*/ 
 
  public void custom(String option, String value) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdOptions_custom__SWIG_0(swigCPtr, this, option, value);
  }

/** 
*  Set option using option name 
*  @param option   [in] Option name 
*  @param bEnable	[in] Option enable true/false 
* 
*/ 
 
  public void custom(String option, boolean bEnable) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnMusicIdOptions_custom__SWIG_1(swigCPtr, this, option, bEnable);
  }

}
