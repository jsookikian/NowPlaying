
package com.gracenote.gnsdk;

public class GnLinkOptions {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnLinkOptions(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnLinkOptions obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnLinkOptions(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

/** Set this link query lookup mode. 
* @param lookupMode		Lookup mode 
* 
*/ 
 
  public void lookupMode(GnLookupMode lookupMode) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLinkOptions_lookupMode(swigCPtr, this, lookupMode.swigValue());
  }

/** 
*  Explicitly identifies the track of interest by its ordinal number. This option takes precedence 
*   over any provided by track indicator. 
* 
*/ 
 
  public void trackOrdinal(long number) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLinkOptions_trackOrdinal(swigCPtr, this, number);
  }

/** 
*  This option sets the source provider of the content (for example, "Acme"). 
* 
*/ 
 
  public void dataSource(String datasource) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLinkOptions_dataSource(swigCPtr, this, datasource);
  }

/** 
*  This option sets the type of the provider content (for example, "cover"). 
* 
*/ 
 
  public void dataType(String datatype) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLinkOptions_dataType(swigCPtr, this, datatype);
  }

/** 
* Set a specific network interface to use with this object's connections. This can be useful for 
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use. 
*  @param intfName [in] Local IP address or system name for the desired network interface 
* 
*/ 
 
  public void networkInterface(String intfName) throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLinkOptions_networkInterface__SWIG_0(swigCPtr, this, intfName);
  }

/** 
* Return network interface being use with this object's connections if one has been set.  
* If no specific network interface has been set this option will return an empty string. 
* 
*/ 
 
  public String networkInterface() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLinkOptions_networkInterface__SWIG_1(swigCPtr, this);
  }

/** 
*  Clears all options currently set for a given Link query. 
*  <p><b>Remarks:</b></p> 
*  As Link query handles can be used to retrieve multiple enhanced data items, it may be appropriate 
*   to specify different options between data retrievals. You can use this function to clear all options 
*   before setting new ones. 
* 
*/ 
 
  public void clear() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLinkOptions_clear(swigCPtr, this);
  }

}
