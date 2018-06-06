
package com.gracenote.gnsdk;

/** 
* <b>Experimental</b>: Fetch asset raw data. 
* The raw data is fetched during object construction 
* and may result in lengthy network access if accessing 
* from online. 
*/ 
 
public class GnAssetFetch {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected GnAssetFetch(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnAssetFetch obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnAssetFetch(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

	private IGnStatusEvents pEventHandler;
	private IGnStatusEventsProxyU eventHandlerProxy;

/** 
* Perform the fetch of the data from the provided URL. 
* This method can fetch data from any valid URL. This class must 
* be used to fetch data from a GNSDK local URL. 
* Construction may result in lengthy network access if the URL is 
* online and the target data is large. 
*/ 
 
  public GnAssetFetch(GnUser user, String url, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnAssetFetch__SWIG_0(GnUser.getCPtr(user), user, url, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnAssetFetch(GnUser user, String url) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnAssetFetch__SWIG_1(GnUser.getCPtr(user), user, url);
}

  public GnAssetFetch(GnUser user, String url, GnLookupMode lookupMode, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnAssetFetch__SWIG_2(GnUser.getCPtr(user), user, url, lookupMode.swigValue(), (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnAssetFetch(GnUser user, String url, GnLookupMode lookupMode) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
	swigCPtr = gnsdk_javaJNI.new_GnAssetFetch__SWIG_3(GnUser.getCPtr(user), user, url, lookupMode.swigValue());
}

/** 
* Raw data buffer 
*/ 
 
  public byte[] data() {
	return gnsdk_javaJNI.GnAssetFetch_data(swigCPtr, this);
}

/** 
* Raw data size in bytes 
*/ 
 
  public long size() {
    return gnsdk_javaJNI.GnAssetFetch_size(swigCPtr, this);
  }

  public String type() {
    return gnsdk_javaJNI.GnAssetFetch_type(swigCPtr, this);
  }

/** 
* Get the event handler provided on construction 
* @return Event handler 
*/ 
 
  public IGnStatusEvents eventHandler() {
	return pEventHandler;
}

}
