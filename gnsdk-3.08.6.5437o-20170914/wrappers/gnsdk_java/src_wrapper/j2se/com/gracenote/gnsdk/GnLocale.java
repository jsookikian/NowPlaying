
package com.gracenote.gnsdk;

/** 
* locale_info_iterable 
*//** 
* Loads Gracenote data for a specified locale. 
* <p> 
* The GNSDK provides locales as a convenient way to group locale-dependent metadata specific to a region 
* (such as Europe) and language that should be returned from the Gracenote Service. A locale is defined by a group 
* (such as Music), a language, a region and a descriptor (indicating level of metadata detail), which are identifiers 
* to a specific set of lists in the Gracenote Service. 
* <p> 
* The GNSDK uses locales for various reasons and it is a best practice to have an appropriate locale 
* loaded. Work with your Gracenote representative to determine what locale group and descriptor to load. 
* <p> 
* <p><b>SDK Documentation</b></p> 
* <p> 
* <b>Topic:</b>  Implementing Applications (All Platforms) > Loading a Locale 
* <p> 
* For more information on locales, see the above topic, which covers the following: 
*    <ul> 
*        <li>General information about locales</li> 
*        <li>Code samples, in multiple programming languages, showing how to load a locale</li> 
*        <li>Locale dependent data</li> 
*        <li>Default regions and descriptors</li> 
*        <li>Locale groups 
*            <ul> 
*        <li>Multi-threaded access</li> 
*        <li>Updating locales and lists</li> 
*        <li>Update notification</li></ul></li> 
*    <li>Locale Behavior</li> 
*    <li>Best practicles for using locales</li> 
*    </ul> 
* <p> 
* <p><b>Overview</b></p> 
* <p> 
* <b>Topic:</b> Concepts > Genre and Other List-Dependent Values 
* <p> 
*/ 
 
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

/** 
* Constructs a {@link GnLocale} object 
*/ 
 
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

/** 
* Loads the specified locale 
* @param group				Locale group 
* @param language			Locale data language 
* @param region			Locale region (where applicable) 
* @param descriptor		Descriptor, or granularity, of the locale data where applicable 
* @param user				User object 
* @param pEventHandler     Status events delegate 
* <p><b>Note</b><p> This method blocks the current thread until the load is complete; 
* set an {@link IGnStatusEvents} delegate to receive progress updates. 
* <p> 
* Long Running Potential: Network I/O, File system I/O 
*/ 
 
  public GnLocale(GnLocaleGroup group, GnLanguage language, GnRegion region, GnDescriptor descriptor, GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_2(group.swigValue(), language.swigValue(), region.swigValue(), descriptor.swigValue(), GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

/** 
* Loads the specified locale 
* @param group				Locale group specifies which locale data is loaded 
* @param language			Language of locale data 
* @param region			Region of the locale data where applicable 
* @param descriptor		Descriptor, or verbosity, of the locale data where applicable 
* @param user				User object 
* <p><b>Note</b><p> This method blocks the current thread until the load is complete. 
* <p> 
* Long Running Potential: Network I/O, File system I/O 
*/ 
 
  public GnLocale(GnLocaleGroup group, GnLanguage language, GnRegion region, GnDescriptor descriptor, GnUser user) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_3(group.swigValue(), language.swigValue(), region.swigValue(), descriptor.swigValue(), GnUser.getCPtr(user), user);
}

/** 
* Loads the specified locale with native strings 
* @param group				Locale group 
* @param language			Locale data language 
* @param region			Locale region (where applicable) 
* @param descriptor		Descriptor, or granularity, of the locale data where applicable 
* @param user				User object 
* @param pEventHandler     Status events delegate 
* <p><b>Note</b><p> This method blocks the current thread until the load is complete; 
* set an {@link IGnStatusEvents} delegate to receive progress updates. 
* <p> 
* Long Running Potential: Network I/O, File system I/O 
*/ 
 
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

/** 
* Loads the specified locale 
* @param group				Locale group 
* @param langIsoCode		ISO code for locale data language 
* @param region			Locale region (where applicable) 
* @param descriptor		Descriptor, or granularity, of the locale data where applicable 
* @param user				User object 
* @param pEventHandler     Status events delegate 
* <p><b>Note</b><p> This method blocks the current thread until the load is complete; 
* set an {@link IGnStatusEvents} delegate to receive progress messages. 
* <p> 
* Long Running Potential: Network I/O, File system I/O 
*/ 
 
  public GnLocale(GnLocaleGroup group, String langIsoCode, GnRegion region, GnDescriptor descriptor, GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_6(group.swigValue(), langIsoCode, region.swigValue(), descriptor.swigValue(), GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
}

/** 
* Loads the specified locale 
* @param group				Locale group specifies which locale data is loaded 
* @param langIsoCode		Language of locale data as an ISO code 
* @param region			Region of the locale data where applicable 
* @param descriptor		Descriptor, or verbosity, of the locale data where applicable 
* @param user				User object 
* <p><b>Note</b><p> This method blocks the current thread until the load is complete. 
* <p> 
* Long Running Potential: Network I/O, File system I/O 
*/ 
 
  public GnLocale(GnLocaleGroup group, String langIsoCode, GnRegion region, GnDescriptor descriptor, GnUser user) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_7(group.swigValue(), langIsoCode, region.swigValue(), descriptor.swigValue(), GnUser.getCPtr(user), user);
}

/** 
* Reconstitutes locale from serialized locale data. 
* @param serializedLocale	String of serialized locale handle data 
*/ 
 
  public GnLocale(String serializedLocale) throws com.gracenote.gnsdk.GnException {
	this(0, true);
	
	if ( pEventHandler != null )
	{
		eventHandlerProxy = new IGnStatusEventsProxyU(pEventHandler);
	}
	this.pEventHandler=pEventHandler;	// <REFERENCE_NAME_CHECK><TYPE>IGnStatusEvents</TYPE><NAME>pEventHandler</NAME></REFERENCE_NAME_CHECK> leave for scripted verification of names
	
    swigCPtr = gnsdk_javaJNI.new_GnLocale__SWIG_8(serializedLocale);
}

/** 
* Get Locale information 
*/ 
 
  public GnLocaleInfo localeInformation() {
    return new GnLocaleInfo(gnsdk_javaJNI.GnLocale_localeInformation(swigCPtr, this), false);
  }

/** 
* Retrieves this locale's revision string. 
* @return Revision 
*/ 
 
  public String revision() throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLocale_revision(swigCPtr, this);
  }

/** 
* Sets this locale as the default locale for the 'locale group' (see {@link GnLocaleGroup}). 
*/ 
 
  public void setGroupDefault() throws com.gracenote.gnsdk.GnException {
    gnsdk_javaJNI.GnLocale_setGroupDefault(swigCPtr, this);
  }

  public static GnLocaleInfoIterable storedLocales() {
    return new GnLocaleInfoIterable(gnsdk_javaJNI.GnLocale_storedLocales(), true);
  }

/** 
* Updates a locale with newer locale data, if available. 
* To ensure the Gracenote Service can be contacted to test for a new list version, 
* your application needs to configure the user's lookup mode to allow online access. 
* <p> 
* To cancel the update procedure, set the "canceller" in any method 
* called in the status event delegate. 
* <p> 
* @param user				User requesting the locale update 
* @param pEventHandler		Status events delegate 
* @return True indicates updates were applied, false indicates no updates are available 
* <p> 
* <p><b>Note</b></p> 
* This methods blocks the current thread until the update procedure is complete; 
* set a status events delegate to receive progress messages. 
* <p> 
* Long Running Potential: Network I/O, File system I/O 
*/ 
 
  public boolean update(GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLocale_update__SWIG_0(swigCPtr, this, GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
  }

/** 
* Updates a locale with new versions of the locale data, if available. 
* The application must ensure Gracenote Service can be contacted to test for a new list version 
* by appropriately configuring the user's lookup mode to allow online access. 
* <p> 
* @param user				User requesting the locale update 
* @return True indicates updates were applied, false indicates no updates are available 
* <p> 
* <p><b>Note</b></p> 
* This methods blocks the current thread until the update procedure is complete; 
* set a status events delegate to receive progress messages. 
* <p> 
* Long Running Potential: Network I/O, File system I/O 
*/ 
 
  public boolean update(GnUser user) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLocale_update__SWIG_1(swigCPtr, this, GnUser.getCPtr(user), user);
  }

/** 
* Tests a locale to determine if newer locale data is available. If it is, your application 
* should call Update()to download it. 
* To ensure the Gracenote Service can be contacted to test for a new list version, 
* your application needs to configure the user's lookup mode to allow online access. 
* <p> 
* To cancel the update check procedure, set the "canceller" in any method called in the 
* status event delegate. 
* <p> 
* @param user				User requesting the locale update check 
* @param pEventHandler		Status event delegate 
* @return True indicates updates are available, false otherwise. 
* <p> 
* <p><b>Remarks:</b></p> 
* You can invoke this method periodically to check the Gracenote Service for locale data updates. 
* <p> 
* <p><b>Note:</b></p> 
* You should immediately check for updates after constructing a locale object from a saved serialized locale 
* string as it may be out of date. 
* <p> 
* This methods blocks the current thread until the update procedure is complete; 
* set a status events delegate to receive progress notification updates. 
* <p> 
* Long Running Potential: Network I/O 
*/ 
 
  public boolean updateCheck(GnUser user, IGnStatusEvents pEventHandler) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLocale_updateCheck__SWIG_0(swigCPtr, this, GnUser.getCPtr(user), user, (eventHandlerProxy==null)?0:IGnStatusEventsProxyL.getCPtr(eventHandlerProxy), eventHandlerProxy);
  }

/** 
* Tests a locale to determine if a newer revision of any locale data is available. If available the new data 
* is not downloaded. To download the application must invoke update. 
* The application must ensure Gracenote Service can be contacted to test for a new list version 
* by appropriately configuring the user's lookup mode to allow online access. 
* <p> 
* @param user				User requesting the locale update check 
* @return True indicates updates are available, false otherwise. 
* <p> 
* <p><b>Remarks:</b></p> 
* This method can be invoked periodically to check Gracenote Service for updates to locale data. 
* <p> 
* <p><b>Note:</b></p> 
* You should immediately check for updates after constructing a locale object from a saved serialized locale 
* string as it may be out of date. 
* <p> 
* This methods blocks the current thread until the update procedure is complete; 
* set a status events delegate to receive progress messages. 
* <p> 
* Long Running Potential: Network I/O 
*/ 
 
  public boolean updateCheck(GnUser user) throws com.gracenote.gnsdk.GnException {
    return gnsdk_javaJNI.GnLocale_updateCheck__SWIG_1(swigCPtr, this, GnUser.getCPtr(user), user);
  }

/** 
* Serializes locale data into an encrypted text string that you can store locally for later use. 
* <p><b>Note:</b></p> 
* If your application is using a GNSDK local storage solution, locale data is automatically stored 
* and retrieved from a local store according to the user lookup option configuration. 
* If you are implementing your own local storage functionality, you can use this method to 
* render a locale into a format that can be stored persistently and restored at a later time using 
* the appropriate constructor. 
* @return Serialize locale data 
*/ 
 
  public GnString serialize() throws com.gracenote.gnsdk.GnException {
    return new GnString(gnsdk_javaJNI.GnLocale_serialize(swigCPtr, this), true);
  }

}
