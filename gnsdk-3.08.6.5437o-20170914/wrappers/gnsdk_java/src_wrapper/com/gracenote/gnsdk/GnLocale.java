/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gracenote.gnsdk;

public class GnLocale extends GnLocaleObject {
  private transient long swigCPtr;

  protected GnLocale(long cPtr, boolean cMemoryOwn) {
    super(gnsdk_javaJNI.GnLocale_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(GnLocale obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gnsdk_javaJNI.delete_GnLocale(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

	private IGnStatusEvents pEventHandler;
	private IGnStatusEventsProxyU eventHandlerProxy;

  public GnLocale(GnLocaleInfo localeInfo, GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_0(GnLocaleInfo.getCPtr(localeInfo), localeInfo, GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnLocale(GnLocaleInfo localeInfo, GnUser user) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_1(GnLocaleInfo.getCPtr(localeInfo), localeInfo, GnUser.getCPtr(user), user);
}

  public GnLocale(GnLocaleGroup group, GnLanguage language, GnRegion region, GnDescriptor descriptor, GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_2(group.swigValue(), language.swigValue(), region.swigValue(), descriptor.swigValue(), GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnLocale(GnLocaleGroup group, GnLanguage language, GnRegion region, GnDescriptor descriptor, GnUser user) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_3(group.swigValue(), language.swigValue(), region.swigValue(), descriptor.swigValue(), GnUser.getCPtr(user), user);
}

  public GnLocale(String group, String language, String region, String descriptor, GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_4(group, language, region, descriptor, GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnLocale(String group, String language, String region, String descriptor, GnUser user) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_5(group, language, region, descriptor, GnUser.getCPtr(user), user);
}

  public GnLocale(GnLocaleGroup group, String langIsoCode, GnRegion region, GnDescriptor descriptor, GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_6(group.swigValue(), langIsoCode, region.swigValue(), descriptor.swigValue(), GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

  public GnLocale(GnLocaleGroup group, String langIsoCode, GnRegion region, GnDescriptor descriptor, GnUser user) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_7(group.swigValue(), langIsoCode, region.swigValue(), descriptor.swigValue(), GnUser.getCPtr(user), user);
}

  public GnLocale(String serializedLocale) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_8(serializedLocale);
}

  public GnLocaleInfo localeInformation() {
    return new GnLocaleInfo(gnsdk_javaJNI.GnLocale_localeInformation(swigCPtr, this), false);
  }

  public String revision() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLocale_revision(swigCPtr, this);
  }

  public void setGroupDefault() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLocale_setGroupDefault(swigCPtr, this);
  }

  public static GnLocaleInfoIterable storedLocales() {
    return new GnLocaleInfoIterable(gnsdk_javaJNI.GnLocale_storedLocales(), true);
  }

  public boolean update(GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLocale_update__SWIG_0(swigCPtr, this, GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
  }

  public boolean update(GnUser user) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLocale_update__SWIG_1(swigCPtr, this, GnUser.getCPtr(user), user);
  }

  public boolean updateCheck(GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLocale_updateCheck__SWIG_0(swigCPtr, this, GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
  }

  public boolean updateCheck(GnUser user) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLocale_updateCheck__SWIG_1(swigCPtr, this, GnUser.getCPtr(user), user);
  }

  public GnString serialize() throws com.gracenote.gnsdk.GnException {
    return new GnString(gnsdk_javaJNI.GnLocale_serialize(swigCPtr, this), true);
  }

}
