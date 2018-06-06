
namespace GracenoteSDK {

/**
* locale_info_iterable
*//**
* Loads Gracenote data for a specified locale.
*
* The GNSDK provides locales as a convenient way to group locale-dependent metadata specific to a region
* (such as Europe) and language that should be returned from the Gracenote Service. A locale is defined by a group
* (such as Music), a language, a region and a descriptor (indicating level of metadata detail), which are identifiers
* to a specific set of lists in the Gracenote Service.
*
* The GNSDK uses locales for various reasons and it is a best practice to have an appropriate locale
* loaded. Work with your Gracenote representative to determine what locale group and descriptor to load.
*
* <p><b>SDK Documentation</b></p>
*
* <b>Topic:</b>  Implementing Applications (All Platforms) > Loading a Locale
*
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
*
* <p><b>Overview</b></p>
*
* <b>Topic:</b> Concepts > Genre and Other List-Dependent Values
*
*/
public class GnLocale : GnLocaleObject {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal GnLocale(global::System.IntPtr cPtr, bool cMemoryOwn) : base(gnsdk_csharp_marshalPINVOKE.GnLocale_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(GnLocale obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~GnLocale() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          gnsdk_csharp_marshalPINVOKE.delete_GnLocale(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

/**
* Constructs a GnLocale object
*/
  public GnLocale(GnLocaleInfo localeInfo, GnUser user, GnStatusEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnLocale__SWIG_0(GnLocaleInfo.getCPtr(localeInfo), GnUser.getCPtr(user), GnStatusEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  public GnLocale(GnLocaleInfo localeInfo, GnUser user) : this(gnsdk_csharp_marshalPINVOKE.new_GnLocale__SWIG_1(GnLocaleInfo.getCPtr(localeInfo), GnUser.getCPtr(user)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
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
* set an IGnStatusEvents delegate to receive progress updates.
*
* Long Running Potential: Network I/O, File system I/O
*/
  public GnLocale(GnLocaleGroup group, GnLanguage language, GnRegion region, GnDescriptor descriptor, GnUser user, GnStatusEventsDelegate pEventHandler) : this(gnsdk_csharp_marshalPINVOKE.new_GnLocale__SWIG_2((int)group, (int)language, (int)region, (int)descriptor, GnUser.getCPtr(user), GnStatusEventsDelegate.getCPtr(pEventHandler)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Loads the specified locale
* @param group			Locale group specifies which locale data is loaded
* @param language		Language of locale data
* @param region			Region of the locale data where applicable
* @param descriptor		Descriptor, or verbosity, of the locale data where applicable
* @param user			User object
* <p><b>Note</b><p> This method blocks the current thread until the load is complete;
* set an IGnStatusEvents delegate to receive progress messages.
*
* Long Running Potential: Network I/O, File system I/O
*/
  public GnLocale(GnLocaleGroup group, GnLanguage language, GnRegion region, GnDescriptor descriptor, GnUser user) : this(gnsdk_csharp_marshalPINVOKE.new_GnLocale__SWIG_3((int)group, (int)language, (int)region, (int)descriptor, GnUser.getCPtr(user)), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  static private global::System.IntPtr SwigConstructGnLocale(string group, string language, string region, string descriptor, GnUser user, GnStatusEventsDelegate pEventHandler) {
  System.IntPtr tempgroup = GnMarshalUTF8.NativeUtf8FromString(group);
  System.IntPtr templanguage = GnMarshalUTF8.NativeUtf8FromString(language);
  System.IntPtr tempregion = GnMarshalUTF8.NativeUtf8FromString(region);
  System.IntPtr tempdescriptor = GnMarshalUTF8.NativeUtf8FromString(descriptor);
    try {
      return gnsdk_csharp_marshalPINVOKE.new_GnLocale__SWIG_4(tempgroup, templanguage, tempregion, tempdescriptor, GnUser.getCPtr(user), GnStatusEventsDelegate.getCPtr(pEventHandler));
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempgroup);
 GnMarshalUTF8.ReleaseMarshaledUTF8String(templanguage);
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempregion);
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempdescriptor);
    }
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
* set an IGnStatusEvents delegate to receive progress updates.
*
* Long Running Potential: Network I/O, File system I/O
*/
  public GnLocale(string group, string language, string region, string descriptor, GnUser user, GnStatusEventsDelegate pEventHandler) : this(GnLocale.SwigConstructGnLocale(group, language, region, descriptor, user, pEventHandler), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  static private global::System.IntPtr SwigConstructGnLocale(string group, string language, string region, string descriptor, GnUser user) {
  System.IntPtr tempgroup = GnMarshalUTF8.NativeUtf8FromString(group);
  System.IntPtr templanguage = GnMarshalUTF8.NativeUtf8FromString(language);
  System.IntPtr tempregion = GnMarshalUTF8.NativeUtf8FromString(region);
  System.IntPtr tempdescriptor = GnMarshalUTF8.NativeUtf8FromString(descriptor);
    try {
      return gnsdk_csharp_marshalPINVOKE.new_GnLocale__SWIG_5(tempgroup, templanguage, tempregion, tempdescriptor, GnUser.getCPtr(user));
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempgroup);
 GnMarshalUTF8.ReleaseMarshaledUTF8String(templanguage);
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempregion);
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempdescriptor);
    }
  }

  public GnLocale(string group, string language, string region, string descriptor, GnUser user) : this(GnLocale.SwigConstructGnLocale(group, language, region, descriptor, user), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  static private global::System.IntPtr SwigConstructGnLocale(GnLocaleGroup group, string langIsoCode, GnRegion region, GnDescriptor descriptor, GnUser user, GnStatusEventsDelegate pEventHandler) {
  System.IntPtr templangIsoCode = GnMarshalUTF8.NativeUtf8FromString(langIsoCode);
    try {
      return gnsdk_csharp_marshalPINVOKE.new_GnLocale__SWIG_6((int)group, templangIsoCode, (int)region, (int)descriptor, GnUser.getCPtr(user), GnStatusEventsDelegate.getCPtr(pEventHandler));
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(templangIsoCode);
    }
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
* set an IGnStatusEvents delegate to receive progress messages.
*
* Long Running Potential: Network I/O, File system I/O
*/
  public GnLocale(GnLocaleGroup group, string langIsoCode, GnRegion region, GnDescriptor descriptor, GnUser user, GnStatusEventsDelegate pEventHandler) : this(GnLocale.SwigConstructGnLocale(group, langIsoCode, region, descriptor, user, pEventHandler), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  static private global::System.IntPtr SwigConstructGnLocale(GnLocaleGroup group, string langIsoCode, GnRegion region, GnDescriptor descriptor, GnUser user) {
  System.IntPtr templangIsoCode = GnMarshalUTF8.NativeUtf8FromString(langIsoCode);
    try {
      return gnsdk_csharp_marshalPINVOKE.new_GnLocale__SWIG_7((int)group, templangIsoCode, (int)region, (int)descriptor, GnUser.getCPtr(user));
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(templangIsoCode);
    }
  }

/**
* Loads the specified locale
* @param group				Locale group specifies which locale data is loaded
* @param langIsoCode		Language of locale data as an ISO code
* @param region				Region of the locale data where applicable
* @param descriptor			Descriptor, or verbosity, of the locale data where applicable
* @param user				User object
* <p><b>Note</b><p> This method blocks the current thread until the load is complete;
* set an IGnStatusEvents delegate to receive progress messages.
*
* Long Running Potential: Network I/O, File system I/O
*/
  public GnLocale(GnLocaleGroup group, string langIsoCode, GnRegion region, GnDescriptor descriptor, GnUser user) : this(GnLocale.SwigConstructGnLocale(group, langIsoCode, region, descriptor, user), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

  static private global::System.IntPtr SwigConstructGnLocale(string serializedLocale) {
  System.IntPtr tempserializedLocale = GnMarshalUTF8.NativeUtf8FromString(serializedLocale);
    try {
      return gnsdk_csharp_marshalPINVOKE.new_GnLocale__SWIG_8(tempserializedLocale);
    } finally {
 GnMarshalUTF8.ReleaseMarshaledUTF8String(tempserializedLocale);
    }
  }

/**
* Reconstitutes locale from serialized locale data.
* @param serializedLocale	String of serialized locale handle data
*/
  public GnLocale(string serializedLocale) : this(GnLocale.SwigConstructGnLocale(serializedLocale), true) {
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Sets this locale as the default locale for the 'locale group' (see GnLocaleGroup).
*/
  public void SetGroupDefault() {
    gnsdk_csharp_marshalPINVOKE.GnLocale_SetGroupDefault(swigCPtr);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
  }

/**
* Updates a locale with newer locale data, if available.
* To ensure the Gracenote Service can be contacted to test for a new list version,
* your application needs to configure the user's lookup mode to allow online access.
*
* To cancel the update procedure, set the "canceller" in any method
* called in the status event delegate.
*
* @param user				User requesting the locale update
* @param pEventHandler		Status events delegate
* @return True indicates updates were applied, false indicates no updates are available
*
* <p><b>Note</b></p>
* This methods blocks the current thread until the update procedure is complete;
* set a status events delegate to receive progress messages.
*
* Long Running Potential: Network I/O, File system I/O
*/
  public bool Update(GnUser user, GnStatusEventsDelegate pEventHandler) {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnLocale_Update__SWIG_0(swigCPtr, GnUser.getCPtr(user), GnStatusEventsDelegate.getCPtr(pEventHandler));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Updates a locale with new versions of the locale data, if available.
* The application must ensure Gracenote Service can be contacted to test for a new list version
* by appropriately configuring the user's lookup mode to allow online access.
*
* The application can cancel the update procedure by setting the "canceller" in any method
* called in the status event delegate.
*
* @param user				User requesting the locale update
* @return True indicates updates were applied, false indicates no updates are available
*
* <p><b>Note</b></p>
* This methods blocks the current thread until the update procedure is complete;
* set a status events delegate to receive progress messages.
*
* Long Running Potential: Network I/O, File system I/O
*/
  public bool Update(GnUser user) {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnLocale_Update__SWIG_1(swigCPtr, GnUser.getCPtr(user));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Tests a locale to determine if newer locale data is available. If it is, your application
* should call Update()to download it.
* To ensure the Gracenote Service can be contacted to test for a new list version,
* your application needs to configure the user's lookup mode to allow online access.
*
* To cancel the update check procedure, set the "canceller" in any method called in the
* status event delegate.
*
* @param user				User requesting the locale update check
* @param pEventHandler		Status event delegate
* @return True indicates updates are available, false otherwise.
*
* <p><b>Remarks:</b></p>
* You can invoke this method periodically to check the Gracenote Service for locale data updates.
*
* <p><b>Note:</b></p>
* You should immediately check for updates after constructing a locale object from a saved serialized locale
* string as it may be out of date.
*
* This methods blocks the current thread until the update procedure is complete;
* set a status events delegate to receive progress notification updates.
*
* Long Running Potential: Network I/O
*/
  public bool UpdateCheck(GnUser user, GnStatusEventsDelegate pEventHandler) {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnLocale_UpdateCheck__SWIG_0(swigCPtr, GnUser.getCPtr(user), GnStatusEventsDelegate.getCPtr(pEventHandler));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Tests a locale to determine if a newer revision of any locale data is available. If available the new data
* is not downloaded. To download the application must invoke update.
* The application must ensure Gracenote Service can be contacted to test for a new list version
* by appropriately configuring the user's lookup mode to allow online access.
*
* The application can cancel the update check procedure by setting the "canceller" in any method
* called in the status event delegate.
*
* @param user				User requesting the locale update check
* @return True indicates updates are available, false otherwise.
*
* <p><b>Remarks:</b></p>
* This method can be invoked periodically to check Gracenote Service for updates to locale data.
*
* <p><b>Note:</b></p>
* You should immediately check for updates after constructing a locale object from a saved serialized locale
* string as it may be out of date.
*
* This methods blocks the current thread until the update procedure is complete;
* set a status events delegate to receive progress messages.
*
* Long Running Potential: Network I/O
*/
  public bool UpdateCheck(GnUser user) {
    bool ret = gnsdk_csharp_marshalPINVOKE.GnLocale_UpdateCheck__SWIG_1(swigCPtr, GnUser.getCPtr(user));
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
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
  public GnString Serialize() {
    GnString ret = new GnString(gnsdk_csharp_marshalPINVOKE.GnLocale_Serialize(swigCPtr), true);
    if (gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Pending) throw gnsdk_csharp_marshalPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

/**
* Retrieves this locale's revision string.
* @return Revision
*/
  public string Revision {
	get
	{   
		/* csvarout typemap code */
		return GnMarshalUTF8.StringFromNativeUtf8(gnsdk_csharp_marshalPINVOKE.GnLocale_Revision_get(swigCPtr) );
	} 

  }

/**
* Get Locale information
*/
  public GnLocaleInfo LocaleInformation {
    get {
      GnLocaleInfo ret = new GnLocaleInfo(gnsdk_csharp_marshalPINVOKE.GnLocale_LocaleInformation_get(swigCPtr), false);
      return ret;
    } 
  }

  public GnLocaleInfoEnumerable StoredLocales {
    get {
      global::System.IntPtr cPtr = gnsdk_csharp_marshalPINVOKE.GnLocale_StoredLocales_get(swigCPtr);
      GnLocaleInfoEnumerable ret = (cPtr == global::System.IntPtr.Zero) ? null : new GnLocaleInfoEnumerable(cPtr, true);
      return ret;
    } 
  }

}

}
