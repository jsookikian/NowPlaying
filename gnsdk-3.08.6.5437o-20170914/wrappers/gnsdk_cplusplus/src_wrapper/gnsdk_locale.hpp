/** Public header file for Gracenote SDK C++ Wrapper
 * Author:
 *   Copyright (c) 2000-2015 Gracenote, Inc.
 *
 *   This software may not be used in any way or distributed without
 *   permission. All rights reserved.
 *
 *   Some code herein may be covered by US and international patents.
 */

#ifndef _GNSDK_LOCALE_HPP_
#define _GNSDK_LOCALE_HPP_

#ifndef __cplusplus
#error "C++ compiler required"
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4290 ) /* disable "warning C4290: C++ exception specification ignored except to indicate a function is not __declspec(nothrow)" */
#endif

#include "gnsdk_base.hpp"

namespace gracenote
{
	/**
	 * @enum GnLocaleGroup
	 * Locale groups used when specifying which locale to load.
	 */
	enum GnLocaleGroup
	{
		/**
		 * Invalid locale group
		 */
		kLocaleGroupInvalid = 0,

		/**
		 * Locale group for the GNSDK music products. Set this when creating a locale used with the MusicID and MusicID -File libraries.
		 */
		kLocaleGroupMusic,

		/**
		 * Locale group for the GNSDK video products. Set this when creating a locale used with the VideoID or Video Explore libraries (or both).
		 */
		kLocaleGroupVideo,

		/**
		 * Locale group for the GNSDK Playlist product. Set this when creating a locale used with the Playlist library.
		 */
		kLocaleGroupPlaylist,

		/**
		 * Locale group for the GNSDK EPG product. Set this when creating a locale used with the EPG library.
		 */
		kLocaleGroupEpg,

		/**
		 * Locale group for the GNSDK ACR products. Set this when creating a locale used with the ACR library.
		 * Additionally, this will set the locale value for the MusicID, VideoID, VideoExplore and EPG libraries
		 * that ACR uses.
		 *
		 * <p><b>Remarks:</b></p>
		 * If kLocaleGroupAcr is set <i>after</i> kLocaleGroupMusic, kLocaleGroupVideo or kLocaleGroupEpg is set, then kLocaleGroupAcr
		 * will override any previous locale settings used with the MusicID, VideoID/VideoExplore and EPG libraries, and set the locale
		 * for all of those libraries to the same locale value.
		 *
		 * If kLocaleGroupMusic, kLocaleGroupVideo or kLocaleGroupEpg is set <i>after</i> kLocaleGroupAcr is set, then it will override
		 * the locale value previously set by kLocaleGroupAcr for the MusicID, VideoID/VideoExplore or EPG libraries, respectively.
		 */
		kLocaleGroupAcr
	};


	/**
	 * Encapsulates information about a GnLocale instance. Used where GNSDK delivers a locale description such as
	 * iterating the available locales or when querying a GnLocale instance for information.
	 */
	class GnLocaleInfo
	{
	public:
		GNWRAPPER_ANNOTATE

		/**
		 * Construct GnLocaleInfo object with default values.
		 */
		 GnLocaleInfo() :group_(kLocaleGroupInvalid), language_(kLanguageInvalid), region_(kRegionDefault), descriptor_(kDescriptorDefault) { }

		/**
		 * Construct GnLocaleInfo object with default values.
		 * @param GnLocaleGroup group - locale group
		 * @param GnLanguage language - locale language
		 * @param GnRegion region - locale region
		 * @param GnDescriptor descriptor - locale descriptor
		 */
		GnLocaleInfo(GnLocaleGroup group, GnLanguage language, GnRegion region, GnDescriptor descriptor) :
			group_(group), language_(language), region_(region), descriptor_(descriptor) { }


		/**
		 * Get locale group
		 * @return Group
		 */
		GnLocaleGroup
		Group(void) const { return group_;}

		/**
		 * Get locale language
		 * @return Language
		 */
		GnLanguage
		Language(void) const  { return language_; }

		/**
		 * Get locale region
		 * @return Region
		 */
		GnRegion
		Region(void) const { return region_;}

		/**
		 * Get locale descriptor
		 * @return Descriptor
		 */
		GnDescriptor
		Descriptor(void) const {return descriptor_;}

		/**
		*  operator ==
		*/
		bool
		operator == (const GnLocaleInfo& rhs) const
		{
			return ( group_ == rhs.group_ ) && ( language_ == rhs.language_ ) && ( region_ == rhs.region_) &&( descriptor_ == rhs.descriptor_);
		}

	private:
		GnLocaleGroup 	group_;
		GnLanguage 		language_;
		GnRegion 		region_;
		GnDescriptor	descriptor_;
	};


	/**
	 * GNSDK internal provider class
	 */
	class locale_info_provider
	{
	public:
		/**
		* Constructor
		*/
		locale_info_provider() { }

		/**
		* Destructor
		*/
		~locale_info_provider() { }

		/**
		 * Get locale available data at position
		 * @param pos - position of GnLocale info to get
		 * @return Locale info
		 */
		GnLocaleInfo
		get_data(gnsdk_uint32_t pos) const throw (GnError);

		/**
		 * Get total count of locales available
		 * @return Count
		 */
		gnsdk_uint32_t
		count() const
		{
			gnsdk_uint32_t count = 0;

			gnsdk_manager_locale_available_count(&count);
			return count;
		}

		/**
		 * Iterator ordinal start
		 */
		static const gnsdk_uint32_t kOrdinalStart = 1;

		/**
		 * Iterator ordinal offset
		 */
		static const gnsdk_uint32_t kCountOffset  = 1;
	};

	/**
	 * locale_info_iterator
	 */
	typedef gn_facade_range_iterator<GnLocaleInfo, locale_info_provider>   locale_info_iterator;

	/**
	 * locale_info_iterable
	 */
	typedef gn_iterable_container<GnLocaleInfo, locale_info_provider>   locale_info_iterable;

	/**
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
	class GnLocale : public GnObject<gnsdk_locale_handle_t>
	{
	public:
		GNWRAPPER_ANNOTATE

		/**
		 * Constructs an empty GnLocale object, no locale is loaded.
		 */
		GnLocale() :localeinfo_() { }

		/**
		* Constructs a GnLocale object
		*/
		GnLocale(const GnLocaleInfo& localeInfo, const GnUser& user, IGnStatusEvents* pEventHandler = GNSDK_NULL)  throw (GnError);

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
		GnLocale(GnLocaleGroup group, GnLanguage language, GnRegion region, GnDescriptor descriptor, const GnUser& user, IGnStatusEvents* pEventHandler = GNSDK_NULL)  throw (GnError);

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
		GnLocale(gnsdk_cstr_t group, gnsdk_cstr_t language, gnsdk_cstr_t region, gnsdk_cstr_t descriptor, const GnUser& user, IGnStatusEvents* pEventHandler = GNSDK_NULL)  throw (GnError);

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
		GnLocale(GnLocaleGroup group, gnsdk_cstr_t langIsoCode, GnRegion region, GnDescriptor descriptor, const GnUser& user, IGnStatusEvents* pEventHandler = GNSDK_NULL)  throw (GnError);

		/**
		 * Create GnLocale instance from native handle
		 * @param localeHandle		Native locale handle
		 */
		GnLocale(gnsdk_locale_handle_t localeHandle) throw (GnError);

		/**
		 * Reconstitutes locale from serialized locale data.
		 * @param serializedLocale	String of serialized locale handle data
		 */
		GnLocale(gnsdk_cstr_t serializedLocale) throw (GnError);

		virtual
		~GnLocale();

		/**
		* Get Locale information
		*/
		const GnLocaleInfo& LocaleInformation() const { return localeinfo_;}
		/**
		 * Retrieves this locale's revision string.
		 * @return Revision
		 */
		gnsdk_cstr_t
		Revision() const throw (GnError);

		/**
		 * Sets this locale as the default locale for the 'locale group' (see GnLocaleGroup).
		 */
		void
		SetGroupDefault() throw (GnError);

		/**
		 * Retrieve iterator for locales available from locale lists cache
		 * @return Locale info iterator
		 */
		static locale_info_iterable
		StoredLocales()
		{
			return locale_info_iterable(locale_info_provider(), GN_GDO_START);
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
		bool
		Update(const GnUser& user, IGnStatusEvents* pEventHandler = GNSDK_NULL) throw (GnError);

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
		bool
		UpdateCheck(const GnUser& user, IGnStatusEvents* pEventHandler = GNSDK_NULL) throw (GnError);

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
		GnString
		Serialize() const throw (GnError);

	private:
		GnLocaleInfo localeinfo_;
	};


} /* namespace gracenote */


#endif /* _GNSDK_LOCALE_HPP_ */

