/** Public header file for Gracenote SDK C++ Wrapper
 * Author:
 *   Copyright (c) 2000-2015 Gracenote, Inc.
 *
 *   This software may not be used in any way or distributed without
 *   permission. All rights reserved.
 *
 *   Some code herein may be covered by US and international patents.
 */

/**
 * @file metadata.hpp
 */

#ifndef _GNSDK_METADATA_HPP_
#define _GNSDK_METADATA_HPP_

#ifndef __cplusplus
#error "C++ compiler required"
#endif

#include "gnsdk_locale.hpp"
#include "gnsdk_convert.hpp"

/**
 * \namespace gracenote
 */

namespace gracenote
{
	/**
	 * \namespace metadata
	 */

	namespace metadata
	{
		/* Forward class declaration */
		class gn_gdo_string_provider;

		typedef gn_facade_range_iterator<gnsdk_cstr_t, gn_gdo_string_provider>          string_iterator;
		typedef gn_iterable_container<gnsdk_cstr_t, gn_gdo_string_provider>             string_iterable;

		/**
		 * @enum GnDataLevel
		 * Metadata level enums
		 * Level of granularity of the metadata
		 * For example, Genre 'Rock' (level 1) is less granular than 'Soft Rock' (level 2)
		 * Not all 4 levels are supported for all applicable metadata.
		 */
		enum GnDataLevel
		{
			kDataLevelInvalid = 0,

			kDataLevel_1      = 1,  /* least granular */
			kDataLevel_2,
			kDataLevel_3,
			kDataLevel_4            /* most granular */

		};

		/**
		 * ID Source enums
		 */
		enum GnIDSource
		{
			kIDSourceInvalid 	= 0,

			kIDSourceTrack      = 1,
			kIDSourceContributor,
			kIDSourceVideoWork,
			kIDSourceVideoProduct,
			kIDSourceVideoDisc,
			kIDSourceVideoSeason,
			kIDSourceVideoSeries,
			kIDSourceVideoTvProgram,
			kIDSourceLyric,
			kIDSourceCddbId
		};

		/**
		 * \class GnRenderOptions
		 * Rendering options (e.g., JSON, XML)
		 */
		class GnRenderOptions
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 * Construct GnRenderOptions object
			 */
			GnRenderOptions() : m_formatVersion(1), m_renderFlags(0) { }

			/**
			 * Specify render format of XML
			 * @return Render options object
			 */
			GnRenderOptions&
			Xml() { m_renderFlags &= ~GNSDK_GDO_RENDER_JSON; return *this; }

			/**
			 * Specify render format of JSON
			 * @return Render options object
			 */
			GnRenderOptions&
			Json() { m_renderFlags |= GNSDK_GDO_RENDER_JSON; return *this; }

			/*-----------------------------------------------------------------------------
			 *  Standard
			 */
			GnRenderOptions&
			Standard() { m_renderFlags |= GNSDK_GDO_RENDER_STANDARD; return *this; }

			/**
			 * Specify rendered output include Credits
			 * @return Render options object
			 */
			GnRenderOptions&
			Credits() { m_renderFlags |= GNSDK_GDO_RENDER_CREDITS; return *this; }

			/**
			 * Specify rendered output include Sortable information
			 * @return Render options object
			 */
			GnRenderOptions&
			Sortable() { m_renderFlags |= GNSDK_GDO_RENDER_SORTABLE; return *this; }

			/*-----------------------------------------------------------------------------
			 *  SerialGdos
			 */
			GnRenderOptions&
			SerialGdos() { m_renderFlags |= GNSDK_GDO_RENDER_SERIAL_GDOS; return *this; }

			/**
			 * Specify rendered output include Product IDs
			 * @return Render options object
			 */
			GnRenderOptions&
			ProductIds() { m_renderFlags |= GNSDK_GDO_RENDER_PRODUCT_IDS; return *this; }

			/**
			 * Specify rendered output include raw TUIs
			 * @return Render options object
			 */
			GnRenderOptions&
			RawTuis() { m_renderFlags |= GNSDK_GDO_RENDER_RAW_TUIS; return *this; }

			/**
			 * Specify rendered output include Gracenote IDs
			 * @return Render options object
			 */
			GnRenderOptions&
			GnIds() { m_renderFlags |= GNSDK_GDO_RENDER_GNIDS; return *this; }

			/*-----------------------------------------------------------------------------
			 *  GnUIds
			 */
			GnRenderOptions&
			GnUIds() { m_renderFlags |= GNSDK_GDO_RENDER_GNUIDS; return *this; }

			/**
			 * Specify rendered output include Genre descriptors for specified level
			 * @param level	[in] Data level
			 * @return Render options object
			 */
			GnRenderOptions&
			Genres(GnDataLevel level)
			{
				switch (level)
				{
				case kDataLevel_1:
					m_renderFlags |= GNSDK_GDO_RENDER_GENRE_LEVEL1;
					break;

				case kDataLevel_2:
					m_renderFlags |= GNSDK_GDO_RENDER_GENRE_LEVEL2;
					break;

				case kDataLevel_3:
				case kDataLevel_4:
					m_renderFlags |= GNSDK_GDO_RENDER_GENRE_LEVEL3;
					break;

				case kDataLevelInvalid:
					break;
				}

				return *this;
			}

			/*-----------------------------------------------------------------------------
			 *  Default
			 */
			GnRenderOptions&
			Default() { m_renderFlags |= GNSDK_GDO_RENDER_DEFAULT; return *this; }

			/*-----------------------------------------------------------------------------
			 *  Full
			 */
			GnRenderOptions&
			Full() { m_renderFlags |= GNSDK_GDO_RENDER_FULL; return *this; }

			/*-----------------------------------------------------------------------------
			 *  Descriptors
			 */
			GnRenderOptions&
			Descriptors() { m_renderFlags |= GNSDK_GDO_RENDER_DESCRIPTORS; return *this; }

			/**
			 * Clear render options
			 * @return Render options object
			 */
			GnRenderOptions&
			Clear() { m_renderFlags = 0; return *this; }

			/**
			 * Specify format version of output to render
			 * @return Render options object
			 */
			GnRenderOptions&
			Version(gnsdk_uint32_t ver) { m_formatVersion = ver; return *this; }

			/**
			 * Get the format version  
			 * @return format version setting
			 */
			gnsdk_uint32_t
			Version() const 
			{
				return m_formatVersion; 
			}

			/**
			 * Returns the native value for the data object.
			 * @return Native handle
			 */
			gnsdk_uint32_t
			native() const
			{
				return m_renderFlags;
			}


		private:
			gnsdk_uint32_t m_formatVersion;
			gnsdk_uint32_t m_renderFlags;

			friend class GnDataObject;
		};


		/**
		 * Gracenote Data Object - encapsulation of GNSDK delivered media elements and metadata.
		 */
		class GnDataObject : public GnObject<gnsdk_gdo_handle_t>
		{
		protected:
			explicit GnDataObject(gnsdk_gdo_handle_t gdoHandle) : GnObject<gnsdk_gdo_handle_t>(gdoHandle) { }

		public:
			GNWRAPPER_ANNOTATE

			GnDataObject() : GnObject<gnsdk_gdo_handle_t>(GNSDK_NULL_GDO) { }
			GnDataObject(const GnDataObject& obj) : GnObject<gnsdk_gdo_handle_t>(obj) { }
			/* Remove this initializer as it takes string as input.  An initializer which is taking Enum as
			 * input is now available and all code should be updated to use it instead
			 */
			GnDataObject(gnsdk_cstr_t id, gnsdk_cstr_t idTag, gnsdk_cstr_t idSrc) throw (GnError)
			{
				gnsdk_gdo_handle_t handle = GNSDK_NULL;

				gnsdk_error_t error = gnsdk_manager_gdo_create_from_id(id, idTag, idSrc, &handle);
				if (error) { throw GnError(); }

				assign(handle);
			}

			GnDataObject(gnsdk_cstr_t id, gnsdk_cstr_t idTag, GnIDSource idSrcEnum) throw (GnError)
			{
				gnsdk_gdo_handle_t handle = GNSDK_NULL;

				gnsdk_error_t error = gnsdk_manager_gdo_create_from_id(id, idTag, IDSource(idSrcEnum), &handle);
				if (error) { throw GnError(); }

				assign(handle);
			}

			/**
			 * Mapping SOURCE_ID to string in the constructor
			 */
			gnsdk_cstr_t
			IDSource(GnIDSource IDSourceEnum) const
			{
				gnsdk_cstr_t key = GNSDK_NULL;
				switch (IDSourceEnum)
				{
				case kIDSourceTrack:
					key = GNSDK_ID_SOURCE_TRACK;
					break;

				case kIDSourceContributor:
					key = GNSDK_ID_SOURCE_CONTRIBUTOR;
					break;

				case kIDSourceVideoWork:
					key = GNSDK_ID_SOURCE_VIDEO_WORK;
					break;

				case kIDSourceVideoProduct:
					key = GNSDK_ID_SOURCE_VIDEO_PRODUCT;
					break;

				case kIDSourceVideoDisc:
					key = GNSDK_ID_SOURCE_VIDEO_DISC;
					break;

				case kIDSourceVideoSeason:
					key = GNSDK_ID_SOURCE_VIDEO_SEASON;
					break;

				case kIDSourceVideoSeries:
					key = GNSDK_ID_SOURCE_VIDEO_SERIES;
					break;

				case kIDSourceVideoTvProgram:
					key = GNSDK_ID_SOURCE_TVPROGRAM;
					break;

				case kIDSourceLyric:
					key = GNSDK_ID_SOURCE_LYRIC;
					break;

				case kIDSourceCddbId:
					key = GNSDK_ID_SOURCE_CDDBID;
					break;

				default:
					break;
				}
				return key;
			}

			/**
			 *  Deserialize GNSDK data object
			 *  @param serializedGdo	[in] Serialized Gracenote data object string
			 *  @return Gracenote data object
			 */
			static GnDataObject
			Deserialize(gnsdk_cstr_t serializedGdo) throw (GnError)
			{
				gnsdk_gdo_handle_t handle = GNSDK_NULL;
				gnsdk_error_t      error;

				error = gnsdk_manager_gdo_deserialize(serializedGdo, &handle);
				if (error) { throw GnError(); }

				return GnDataObject(handle);
			}

			/**
			 *  Create Gracenote Data Object from XML
			 *  @param xml	[in] XML string
			 *  @return Gracenote data object
			 */
			static GnDataObject
			CreateFromXml(gnsdk_cstr_t xml) throw (GnError)
			{
				gnsdk_gdo_handle_t handle = GNSDK_NULL;
				gnsdk_error_t      error;

				error = gnsdk_manager_gdo_create_from_render(xml, &handle);
				if (error) { throw GnError(); }

				return GnDataObject(handle);
			}

			/**
			 *  Reflect
			 */
			template<typename gdoType>
			gdoType
			Reflect() const
			{
				gnsdk_manager_gdo_addref(native());
				return gdoType(native());
			}

			/**
			 *  Serialize this object
			 *  @return Serialize Gracenote data object string
			 */
			GnString
			Serialize() const throw (GnError)
			{
				gnsdk_str_t   serialized = GNSDK_NULL;
				gnsdk_error_t error;

				error = gnsdk_manager_gdo_serialize(native(), &serialized);
				if (GNSDKERR_SEVERE(error) ) { throw GnError(); }

				return GnString::manage(serialized);
			}

			/**
			 * Returns count of the metadata values available for the key.
			 * @param valueKey      [in] Key of the value count to return
			 * @return count
			 */
			gnsdk_uint32_t
			StringValueCount(gnsdk_cstr_t valueKey) const
			{
				gnsdk_uint32_t count = 0;

				if (native())
				{
					gnsdk_manager_gdo_value_count(native(), valueKey, &count);
				}
				return count;
			}

			/**
			 * Returns media or metadata value as a string based on the provided key and ordinal.
			 * @param valueKey      [in] Key of the value to return
			 * @param ordinal		[in] 1-based specifier of a value where multiple values for a key exist
			 * @return Value
			 */
			gnsdk_cstr_t
			StringValue(gnsdk_cstr_t valueKey, gnsdk_uint32_t ordinal = 1) const
			{
				gnsdk_cstr_t sz_value = gnstd::kEmptyString;

				if (native())
				{
					gnsdk_manager_gdo_value_get(native(), valueKey, ordinal, &sz_value);
				}
				return sz_value;
			}

			/**
			 * Returns media or metadata value as an integer based on the provided key and ordinal.
			 * @param valueKey      [in] Key of the value to return
			 * @param ordinal		[in] 1-based specifier of a value where multiple values for a key exist
			 * @return Value
			 */
			gnsdk_int32_t
			IntValue(gnsdk_cstr_t valueKey, gnsdk_uint32_t ordinal = 1) const
			{
				gnsdk_cstr_t return_value = gnstd::kEmptyString;

				if (native())
				{
					gnsdk_manager_gdo_value_get(native(), valueKey, ordinal, &return_value);
				}
				return gnstd::gn_atoi(return_value);
			}

			/**
			 * Number of children available for a given key.
			 * @param childKey [in] Child key to count
			 * @return Count
			 *
			 * <p><b>Remarks:</b></p>
			 * Use this function to count children of a specific data instance; note that only those children
			 * accessible in the current type are considered.
			 *
			 * When this function successfully counts zero (0) occurrences of the child key with no errors, the
			 * method returns successfully.
			 */
			gnsdk_uint32_t
			ChildCount(gnsdk_cstr_t childKey) const
			{
				gnsdk_uint32_t count = 0;

				if (native())
				{
					gnsdk_manager_gdo_child_count(native(), childKey, &count);
				}
				return count;
			}

			/**
			 * Child data object specified by the key and ordinal
			 * @param childKey      [in] Child key to return
			 * @param childOrdinal	[in] 1-based specifier of a child where multiple values for a key exist
			 *
			 * <p><b>Remarks:</b></p>
			 * Use this function to count children of a specific data instance; note that only those children
			 * accessible in the current type are considered.
			 */
			template<typename gdoType>
			gdoType
			ChildGet(gnsdk_cstr_t childKey, gnsdk_uint32_t childOrdinal = 1) const
			{
				gnsdk_gdo_handle_t h_gdo_child = GNSDK_NULL;

				if (native())
				{
					gnsdk_manager_gdo_child_get(native(), childKey, childOrdinal, &h_gdo_child);
				}

				return gdoType(h_gdo_child);
			}

			/**
			 * Child data object specified by the key and ordinal
			 * @param childKey      [in] Child key to return
			 * @param childOrdinal	[in] 1-based specifier of a child where multiple values for a key exist
			 *
			 * <p><b>Remarks:</b></p>
			 * Use this function to count children of a specific data instance; note that only those children
			 * accessible in the current type are considered.
			 */
			GnDataObject
			Child(gnsdk_cstr_t childKey, gnsdk_uint32_t childOrdinal = 1) const
			{
				gnsdk_gdo_handle_t h_gdo_child = GNSDK_NULL;

				if (native())
				{
					gnsdk_manager_gdo_child_get(native(), childKey, childOrdinal, &h_gdo_child);
				}

				GnDataObject tmp(h_gdo_child);
				return tmp;
			}

			/**
			 * Renders contents of the data object as an XML string.
			 * @param options	[in] Render options object
			 * @return Rendered output string
			 */
			GnString
			Render(const GnRenderOptions& options) const throw (GnError)
			{
				gnsdk_str_t   sz_render = GNSDK_NULL;
				gnsdk_error_t error;

				if (native())
				{
					error = gnsdk_manager_gdo_render2(native(), options.m_formatVersion, options.m_renderFlags, &sz_render);
					if (GNSDKERR_ERROR_CODE(error) == GNSDKERR_LibraryNotLoaded)
						error = gnsdk_manager_gdo_render(native(), options.m_renderFlags, &sz_render);

					if (error) { throw GnError(); }
				}

				return GnString::manage(sz_render);
			}

			/**
			 * Applies lists to use for retrieving and rendering locale-related values.
			 * @param	locale Locale to apply to this data object
			 * <p><b>Remarks:</b></p>
			 * Use this function to set the locale of retrieved and rendered locale-dependent data for this
			 * data object. This function overrides any applicable global locale defaults set elsewhere.
			 * <p><b>Locale Language Support</b></p>
			 * This function supports all locale languages and successfully assigns a locale for this data object.
			 * The locale is used for future calls to get data values when locale-dependent values are requested.
			 *
			 * When list-based locale-specific values are requested from this data object they are returned
			 * only if an applicable locale has been successfully set by this method or a default locale has been
			 * successfully set elsehwere.
			 *
			 * When a non-list-based locale-specific values are requested from this data object they are returned
			 * only if these values are available from Gracenote Service or the locale database (where online queries
			 * are not accessible or permitted). If not, the application uses the default (or "official") locale data for
			 * these values. For example, plot values are non-list-based. If a plot summary value is available only in the
			 * English language, and the specific locale is defined for the Spanish language, the application
			 * displays the plot summary in the English language.
			 */
			void
			Locale(const GnLocale& locale) const throw (GnError)
			{
				gnsdk_error_t error;

				error = gnsdk_manager_gdo_set_locale(native(), locale.native() );
				if (error) { throw GnError(); }
			}

			/**
			 * Data object's type.
			 * @return Type string
			 * <p><b>Remarks:</b></p>
			 * The data object's contents are not clearly defined. Use this API to retrieve a data object's type,
			 * as this enables the application to more accurately determine what data the specific data it contains.
			 * Typically an application will use data objects subclassed from the data object, which do specifically
			 * define a type.
			 */
			gnsdk_cstr_t
			GetType() const throw (GnError)
			{
				gnsdk_cstr_t response_context = gnstd::kEmptyString;

				if (native())
				{
					gnsdk_error_t error = gnsdk_manager_gdo_get_type(native(), &response_context);
					if (error) { throw GnError(); }
				}

				return response_context;
			}

			/**
			 *  Flag indicating if object is specified type
			 *  @param strType	[in] Type string
			 *  @return True if object is if provided type, false otherwise
			 */
			bool
			IsType(gnsdk_cstr_t strType) const throw (GnError)
			{
				gnsdk_error_t error = gnsdk_manager_gdo_is_type(native(), strType);
				if (error)
				{
					if (error != SDKMGRWARN_TypeMismatch)
					{
						throw GnError();
					}
					return false;
				}

				return true;
			}

		};


		/**
		 * GNSDK internal provider class
		 */
		template<typename _GdoType>
		class gn_gdo_provider
		{
		public:
			gn_gdo_provider(const GnDataObject& obj, gnsdk_cstr_t key) : obj_(obj), key_(key) { }
			~gn_gdo_provider() { }

			/* required */
			_GdoType
			get_data(gnsdk_uint32_t pos) const
			{
				if (pos < GN_UINT32_MAX)
				{
					return obj_.template ChildGet<_GdoType>(key_, pos);
				}

				return _GdoType();
			}

			/* optional */
			gnsdk_uint32_t
			count() const { return obj_.ChildCount(key_); }
			static const gnsdk_uint32_t kOrdinalStart = 1;
			static const gnsdk_uint32_t kCountOffset  = 1;


		private:
			GnDataObject obj_;
			gnsdk_cstr_t key_;
		};


		/**
		 * GNSDK internal gdo string provider class
		 */
		class gn_gdo_string_provider
		{
		public:
			gn_gdo_string_provider(const GnDataObject& obj, gnsdk_cstr_t key) : obj_(obj), key_(key) { }
			/* required */
			gnsdk_cstr_t
			get_data(gnsdk_uint32_t pos)
			{
				return obj_.StringValue(key_, pos);
			}

			/*-----------------------------------------------------------------------------
			 *  count
			 */
			gnsdk_uint32_t
			count() const { return obj_.StringValueCount(key_); }
			static const gnsdk_uint32_t kOrdinalStart = 1;
			static const gnsdk_uint32_t kCountOffset  = 1;


		private:
			GnDataObject obj_;
			gnsdk_cstr_t key_;
		};


		class GnName;
		class GnAsset;
		class GnContent;
		class GnExternalId;
		class GnContributor;

		typedef gn_facade_range_iterator<GnName, gn_gdo_provider<GnName> >                name_iterator;
		typedef gn_facade_range_iterator<GnContent, gn_gdo_provider<GnContent> >          content_iterator;
		typedef gn_facade_range_iterator<GnAsset, gn_gdo_provider<GnAsset> >              asset_iterator;
		typedef gn_facade_range_iterator<GnExternalId, gn_gdo_provider<GnExternalId> >    externalid_iterator;
		typedef gn_facade_range_iterator<GnContributor, gn_gdo_provider<GnContributor> >  contributor_iterator;

		typedef gn_iterable_container<GnName, gn_gdo_provider<GnName> >                   name_iterable;
		typedef gn_iterable_container<GnContent, gn_gdo_provider<GnContent> >             content_iterable;
		typedef gn_iterable_container<GnAsset, gn_gdo_provider<GnAsset> >                 asset_iterable;
		typedef gn_iterable_container<GnExternalId, gn_gdo_provider<GnExternalId> >	      externalid_iterable;
		typedef gn_iterable_container<GnContributor, gn_gdo_provider<GnContributor> >     contributor_iterable;


		class GnResponseMeta : public GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE
			GNSDK_CHECKED_CAST(GnResponseMeta, GNSDK_GDO_TYPE_GN_RESPONSE_META);

			GnResponseMeta() { }
			GnResponseMeta(gnsdk_gdo_handle_t gdoHandle) : GnDataObject(gdoHandle) { }

			virtual ~GnResponseMeta() { }
		};

		class GnResponseData : public GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE
			GNSDK_CHECKED_CAST(GnResponseData, GNSDK_GDO_TYPE_GN_RESPONSE_DATA);

			GnResponseData() { }
			GnResponseData(gnsdk_gdo_handle_t gdoHandle) : GnDataObject(gdoHandle) { }

			virtual ~GnResponseData() { }
		};

		class GnResponseError : public GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE
			GNSDK_CHECKED_CAST(GnResponseError, GNSDK_GDO_TYPE_GN_RESPONSE_ERROR);

			GnResponseError() { }
			GnResponseError(gnsdk_gdo_handle_t gdoHandle) : GnDataObject(gdoHandle) { }

			virtual ~GnResponseError() { }
		};

		class GnResponse : public GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE
			GNSDK_CHECKED_CAST(GnResponse, GNSDK_GDO_TYPE_GN_RESPONSE);

			GnResponse() { }
			GnResponse(gnsdk_gdo_handle_t gdoHandle) : GnDataObject(gdoHandle) { }

			virtual ~GnResponse() { }

			GnResponseMeta meta() 
			{
				return ChildGet<GnResponseMeta>(GNSDK_GDO_CHILD_RESPONSE_META); 
			}

			GnResponseData data() 
			{ 
				return ChildGet<GnResponseData>(GNSDK_GDO_CHILD_RESPONSE_DATA); 
			}

			GnResponseError error() 
			{ 
				return ChildGet<GnResponseError>(GNSDK_GDO_CHILD_RESPONSE_ERROR); 
			}
		};

		/**
		 * Assets for content (cover art, biography etc)
		 *
		 * <p><b>SDK Documentation</b></p>
		 *
		 * Topic:  Data Models
		 *
		 *  The above topic displays all the metadata returned from a recognition event,
		 *  including objects containing a GnAsset object.
		 *  It does this in an expand/collapse format, showing object hierarchy and
		 *  a description of each field returned.
		 *
		 */
		class GnAsset : public GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 * Constructs empty GnAsset object
			 */
			GnAsset() { }

			/**
			 * Constructs GnAsset object from native Gracenote data object handle
			 * @param gdoHandle	[in] Native handle
			 */
			GnAsset(gnsdk_gdo_handle_t gdoHandle) : GnDataObject(gdoHandle) { }

			virtual
			~GnAsset() { }

			/**
			 *  Asset dimension
			 *  @return Dimention string
			 */
			gnsdk_cstr_t
			Dimension() const
			{
				return StringValue(GNSDK_GDO_VALUE_ASSET_DIMENSION);
			}

			/**
			 *  Asset Type
			 *  @return asset's mime type string
			 */
			gnsdk_cstr_t
			Type() const
			{
				return StringValue(GNSDK_GDO_VALUE_CONTENT_MIMETYPE);
			}

			/**
			 *  Size of content asset in bytes
			 *  @return Size in bytes
			 */
			gnsdk_int32_t
			Bytes() const
			{
				return IntValue(GNSDK_GDO_VALUE_ASSET_BYTES);
			}

			/**
			 *  Pixel image size of asset as defined with a GnImageSize enum, such as kImageSize110 (110x110)
			 *  @return Image size
			 */
			GnImageSize
			Size() const
			{
				return gnconvert::gn_image_size_to_enum(StringValue(GNSDK_GDO_VALUE_ASSET_SIZE));
			}

			/**
			 * @deprecated NB: This method has been marked as deprecated and will be removed from the next major release.
			 *      Use UrlHttp() or UrlHttps() instead.
			 */
			gnsdk_cstr_t
			Url() const
			{
				return StringValue(GNSDK_GDO_VALUE_ASSET_URL);
			}

			/**
			 *  GNSDK url for retrieval of asset from Gracenote
			 *  @return URL
			 */
			gnsdk_cstr_t
			UrlGnsdk() const
			{
				return StringValue(GNSDK_GDO_VALUE_ASSET_URL_GNSDK);
			}

			/**
			 *  HTTP url for retrieval of asset from Gracenote
			 *  @return URL
			 */
			gnsdk_cstr_t
			UrlHttp() const
			{
				return StringValue(GNSDK_GDO_VALUE_ASSET_URL_HTTP);
			}

			/**
			 *  HTTPS url for retrieval of asset from Gracenote
			 *  @return URL
			 */
			gnsdk_cstr_t
			UrlHttps() const
			{
				return StringValue(GNSDK_GDO_VALUE_ASSET_URL_HTTPS);
			}
		};


		/**
		 * Provides access to content assets that can be retrieved from Urls.
		 * Content is only available is content is enabled from the original query's lookup data.
		 * Use the query object's options to enable content.
		 * The type of content that is available depends on the parent object. For example
		 * you can access album cover art from a GnAlbum object, but not an artist image. To
		 * retrieve an artist image navigate to a GnContributor object and invoke it's GnContent
		 * instance.
		 *
		 * <p><b>SDK Documentation</b></p>
		 *
		 * Topic:  Data Models
		 *
		 *  The above topic displays all the metadata returned from a recognition event,
		 *  including objects containing a GnContent object.
		 *  It does this in an expand/collapse format, showing object hierarchy and
		 *  a description of each field returned.
		 *
		 */
		class GnContent : public GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 * Constructs empty GnContent object
			 */
			GnContent() { }

			/**
			 * Constructs a GnContent object from a native handle
			 * @param gdoHandle	[in] Native handle
			 */
			GnContent(gnsdk_gdo_handle_t gdoHandle) : GnDataObject(gdoHandle) { }

			/*-----------------------------------------------------------------------------
			 *  Id
			 */
			gnsdk_cstr_t
			Id() const
			{
				return StringValue(GNSDK_GDO_VALUE_CONTENT_VALUE);
			}

			/**
			 *  Content type - cover art, biography, etc.
			 *  @return Content type
			 */
			GnContentType
			ContentType() const
			{
				if (IsNull())
					return kContentTypeNull;

				gnsdk_cstr_t content_type = StringValue(GNSDK_GDO_VALUE_CONTENT_TYPE);
				if (content_type)
				{
					if (gnstd::gn_strcmp(content_type, GNSDK_CONTENT_TYPE_IMAGE_COVER) == 0)
						return kContentTypeImageCover;

					if (gnstd::gn_strcmp(content_type, GNSDK_CONTENT_TYPE_IMAGE_ARTIST) == 0)
						return kContentTypeImageArtist;

					if (gnstd::gn_strcmp(content_type, GNSDK_CONTENT_TYPE_IMAGE_VIDEO) == 0)
						return kContentTypeImageVideo;

					if (gnstd::gn_strcmp(content_type, GNSDK_CONTENT_TYPE_IMAGE_LOGO) == 0)
						return kContentTypeImageLogo;

					if (gnstd::gn_strcmp(content_type, GNSDK_CONTENT_TYPE_TEXT_BIOGRAPHY) == 0)
						return kContentTypeBiography;

					if (gnstd::gn_strcmp(content_type, GNSDK_CONTENT_TYPE_TEXT_REVIEW) == 0)
						return kContentTypeReview;

					if (gnstd::gn_strcmp(content_type, GNSDK_CONTENT_TYPE_TEXT_NEWS) == 0)
						return kContentTypeNews;

					if (gnstd::gn_strcmp(content_type, GNSDK_CONTENT_TYPE_TEXT_ARTISTNEWS) == 0)
						return kContentTypeArtistNews;

					if (gnstd::gn_strcmp(content_type, GNSDK_CONTENT_TYPE_TEXT_LISTENERCOMMENTS) == 0)
						return kContentTypeListenerComments;

					if (gnstd::gn_strcmp(content_type, GNSDK_CONTENT_TYPE_TEXT_RELEASECOMMENTS) == 0)
						return kContentTypeReleaseComments;
				}

				return kContentTypeUnknown;
			}

			/**
			 *  Content's mime type
			 *  @return Mime type
			 */
			gnsdk_cstr_t
			MimeType() const
			{
				return StringValue(GNSDK_GDO_VALUE_CONTENT_MIMETYPE);
			}

			/**
			 * Asset by image size (if applicable)
			 * @param imageSize	[in] Image size
			 * @return Asset object
			 */
			GnAsset
			Asset(GnImageSize imageSize) const
			{
				gnsdk_cstr_t key = GNSDK_NULL;

				switch (imageSize)
				{
				case kImageSizeThumbnail:
					key = GNSDK_GDO_CHILD_ASSET_SIZE_THUMB;
					break;

				case kImageSize110:
					key = GNSDK_GDO_CHILD_ASSET_SIZE_110;
					break;

				case kImageSizeSmall:
					key = GNSDK_GDO_CHILD_ASSET_SIZE_SMALL;
					break;

				case kImageSize220:
					key = GNSDK_GDO_CHILD_ASSET_SIZE_220;
					break;

				case kImageSize300:
					key = GNSDK_GDO_CHILD_ASSET_SIZE_300;
					break;

				case kImageSizeMedium:
					key = GNSDK_GDO_CHILD_ASSET_SIZE_MEDIUM;
					break;

				case kImageSizeLarge:
					key = GNSDK_GDO_CHILD_ASSET_SIZE_LARGE;
					break;

				case kImageSizeXLarge:
					key = GNSDK_GDO_CHILD_ASSET_SIZE_XLARGE;
					break;

				case kImageSizeUnknown:
					break;
				}

				return ChildGet<GnAsset>(key);

			}  /* GnAsset */

			/**
			 * Iterator for the external third-party IDs (e.g., Amazon's)  associated with this contributor.
			 * @return Iterator
			 */
			asset_iterable
			Assets() const
			{
				return asset_iterable(gn_gdo_provider<GnAsset>(*this, GNSDK_GDO_CHILD_ASSET), GN_GDO_START);
			}

		};


		/**
		 * Third-party identifier used to match identified media to merchandise IDs in online stores and other services
		 *
		 */
		class GnExternalId : public GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE
									GNSDK_CHECKED_CAST(GnExternalId, GNSDK_GDO_TYPE_EXTERNAL_ID);

			/**
			 * Constructs empty GnExternalId object
			 */
			GnExternalId() { }

			/**
			 * Construct a GnExternalId object with a native handle
			 * @param gdoHandle	[in] Native handle
			 */
			GnExternalId(gnsdk_gdo_handle_t gdoHandle) : GnDataObject(gdoHandle) { }

			virtual
			~GnExternalId()  { }

			/**
			 *  External ID source (e.g., Amazon)
			 *  @return External ID source
			 */
			gnsdk_cstr_t
			Source() const
			{
				return StringValue(GNSDK_GDO_VALUE_EXTERNALID_SOURCE);
			}

			/**
			 *  External ID type
			 *  @return External ID type
			 */
			gnsdk_cstr_t
			Type() const
			{
				return StringValue(GNSDK_GDO_VALUE_EXTERNALID_TYPE);
			}

			/**
			 *  External ID value
			 *  @return External ID value
			 */
			gnsdk_cstr_t
			Value() const
			{
				return StringValue(GNSDK_GDO_VALUE_EXTERNALID_VALUE);
			}

		};  /* GnExternalId */


		/**
		 * Represents the role that a contributor played in a music or video production;
		 * for example, singing, playing an instrument, acting, directing, and so on.
		 * <p><b>Note:</b></p>
		 * For music credits, the absence of a role for a person indicates that person is the primary
		 * artist, who may have performed multiple roles.
		 *
		 * <p><b>SDK Documentation</b></p>
		 *
		 * Topic:  Data Models
		 *
		 *  The above topic displays all the metadata returned from a recognition event,
		 *  including objects containing a GnRole object.
		 *  It does this in an expand/collapse format, showing object hierarchy and
		 *  a description of each field returned.
		 *
		 */
		class GnRole : public GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE

			/**
			 * Constructs empty GnRole object
			 */
			GnRole() { }

			/**
			 * Contructs a GnRole object from a native handle
			 * @param gdoHandle	[in] Native handle
			 */
			GnRole(gnsdk_gdo_handle_t gdoHandle) : GnDataObject(gdoHandle)   { }

			virtual
			~GnRole() { }

			/**
			 * Role category, such as string instruments or brass instruments.
			 * @return Category
			 * <p><b>Remarks:</b></p>
			 * This is a list-based value requiring that a corresponding locale or list be loaded.
			 */
			gnsdk_cstr_t
			Category() const
			{
				return StringValue(GNSDK_GDO_VALUE_ROLE_CATEGORY);
			}

			/**
			 * Role's display string.
			 * @return Role
			 */
			gnsdk_cstr_t
			Role() const
			{
				return StringValue(GNSDK_GDO_VALUE_ROLE);
			}

		}; /* GnRole */


		/**
		 * GnName
		 *
		 * <p><b>SDK Documentation</b></p>
		 *
		 * Topic:  Data Models
		 *
		 *  The above topic displays all the metadata returned from a recognition event,
		 *  including objects containing a GnName object.
		 *  It does this in an expand/collapse format, showing object hierarchy and
		 *  a description of each field returned.
		 *
		 */
		class GnName : public GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE
							  GNSDK_CHECKED_CAST(GnName, GNSDK_GDO_TYPE_NAME);

			/**
			 * Constructs empty GnName object
			 */
			GnName() { }

			/**
			 * Constructs a GnName object form a native handle
			 * @param gdoHandle	[in] Native handle
			 */
			GnName(gnsdk_gdo_handle_t gdoHandle) : GnDataObject(gdoHandle)    { }

			virtual
			~GnName()  { }

			/**
			 *  Name display language
			 *  @return Langauge string
			 */
			gnsdk_cstr_t
			Language() const
			{
				return StringValue(GNSDK_GDO_VALUE_DISPLAY_LANGUAGE_DISPLAY);
			}

			/**
			 *  3-letter ISO code for display langauge
			 *  @return Language code
			 */
			gnsdk_cstr_t
			LanguageCode() const
			{
				return StringValue(GNSDK_GDO_VALUE_DISPLAY_LANGUAGE);
			}

			/**
			 *  Display name string
			 *  @return Name suitable for displaying to the end user
			 */
			gnsdk_cstr_t
			Display() const
			{
				return StringValue(GNSDK_GDO_VALUE_DISPLAY);
			}

			/**
			 *  Sortable name
			 *  @return Sortable string
			 */
			gnsdk_cstr_t
			Sortable() const
			{
				return StringValue(GNSDK_GDO_VALUE_SORTABLE);
			}

			/**
			 *  Sortable scheme
			 *  @return Sortable Scheme
			 */
			gnsdk_cstr_t
			SortableScheme() const
			{
				return StringValue(GNSDK_GDO_VALUE_SORTABLE_SCHEME);
			}

			/**
			 *  Name prefix, e.g., "The"
			 *  @return Prefix
			 */
			gnsdk_cstr_t
			Prefix() const
			{
				return StringValue(GNSDK_GDO_VALUE_PREFIX);
			}

			/**
			 *  Family name
			 *  @return Name
			 */
			gnsdk_cstr_t
			Family() const
			{
				return StringValue(GNSDK_GDO_VALUE_FAMILY);
			}

			/**
			 *  Given name
			 *  @return name
			 */
			gnsdk_cstr_t
			Given() const
			{
				return StringValue(GNSDK_GDO_VALUE_GIVEN);
			}

			/**
			 *  Name global ID - used for transcriptions
			 *  @return Gracenote Global ID
			 */
			gnsdk_cstr_t
			GlobalId() const
			{
				return StringValue(GNSDK_GDO_VALUE_GLOBALID);
			}

		};  /* GnName */


		/**
		 * Title of a work or product
		 *
		 * <p><b>SDK Documentation</b></p>
		 *
		 * Topic:  Data Models
		 *
		 *  The above topic displays all the metadata returned from a recognition event,
		 *  including objects containing a GnTitle object.
		 *  It does this in an expand/collapse format, showing object hierarchy and
		 *  a description of each field returned.
		 *
		 */
		class GnTitle : public GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE
							   GNSDK_CHECKED_CAST(GnTitle, GNSDK_GDO_TYPE_TITLE);

			/**
			 * Constructs empty GnTitle object
			 */
			GnTitle() { }

			/**
			 * Constructs a GnTitle object from a native handle
			 * @param gdoHandle	[in] Native handle
			 */
			GnTitle(gnsdk_gdo_handle_t gdoHandle) : GnDataObject(gdoHandle) { }

			virtual
			~GnTitle() { }


			/**
			 *  Title display language
			 *  @return Language string
			 */
			gnsdk_cstr_t
			Language() const
			{
				return StringValue(GNSDK_GDO_VALUE_DISPLAY_LANGUAGE_DISPLAY);
			}

			/**
			 *  3 letter ISO code for display language
			 *  @return Language code
			 */
			gnsdk_cstr_t
			LanguageCode() const
			{
				return StringValue(GNSDK_GDO_VALUE_DISPLAY_LANGUAGE);
			}

			/**
			 *  Title display string
			 *  @return Strng suitable for displaying to end user
			 */
			gnsdk_cstr_t
			Display() const
			{
				return StringValue(GNSDK_GDO_VALUE_DISPLAY);
			}

			/**
			 *  Title prefix, e.g., The
			 *  @return Prefix
			 */
			gnsdk_cstr_t
			Prefix() const
			{
				return StringValue(GNSDK_GDO_VALUE_PREFIX);
			}

			/**
			 *  Sortable title
			 *  @return Sortable string
			 */
			gnsdk_cstr_t
			Sortable() const
			{
				return StringValue(GNSDK_GDO_VALUE_SORTABLE);
			}

			/**
			 *  Sortable title scheme
			 *  @return Sortable scheme
			 */
			gnsdk_cstr_t
			SortableScheme() const
			{
				return StringValue(GNSDK_GDO_VALUE_SORTABLE_SCHEME);
			}

			/**
			 * Main title
			 * @return Title
			 */
			gnsdk_cstr_t
			MainTitle() const
			{
				return StringValue(GNSDK_GDO_VALUE_MAIN_TITLE);
			}

			/**
			 * Title edition
			 * @return Edition
			 */
			gnsdk_cstr_t
			Edition() const
			{
				return StringValue(GNSDK_GDO_VALUE_EDITION);
			}

		};


		/**
		 * A person participating an Album or Track creation.
		 * Provides access to artist image when received from a query object
		 * with content enabled in lookup data.
		 *
		 * <p><b>SDK Documentation</b></p>
		 *
		 * Topic:  Data Models
		 *
		 *  The above topic displays all the metadata returned from a recognition event,
		 *  including objects containing a GnContributor object.
		 *  It does this in an expand/collapse format, showing object hierarchy and
		 *  a description of each field returned.
		 *
		 */
		class GnContributor : public GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE
									 GNSDK_CHECKED_CAST(GnContributor, GNSDK_GDO_TYPE_CONTRIBUTOR);

			/**
			 * Constructs empty GnContributor object
			 */
			GnContributor() { }

			/**
			 * Constructs a GnContributor from a native handle
			 * @param gdohandle	[in] Native handle
			 */
			GnContributor(gnsdk_gdo_handle_t gdoHandle) : GnDataObject(gdoHandle) { }

			/**
			 * Constructs a GnContributor from a Gracenote identifier and identifier tag
			 * @param id	[in] Identifier
			 * @param idTag [in] Identifier tag
			 */
			GnContributor(gnsdk_cstr_t id, gnsdk_cstr_t idTag) throw (GnError) : GnDataObject(id, idTag, GNSDK_ID_SOURCE_CONTRIBUTOR) { }

			virtual
			~GnContributor() { }

			/**
			 *  Flag indicating if data object response contains full (true) or partial metadata.
			 *  Returns true if full, false if partial.
			 * <p><b>Note:</b></p>
			 *   What constitutes a full result varies among the individual response types and results, and also
			 *  depends on data availability.
			 * @ingroup GDO_ValueKeys_Misc
			 */
			bool
			IsFullResult() const
			{
				gnsdk_cstr_t return_value = StringValue(GNSDK_GDO_VALUE_FULL_RESULT);
				return gnstd::gn_strtobool(return_value);
			}

			/**
			 * Contributor's Gracenote identifier
			 * @return Gracenote ID
			 */
			gnsdk_cstr_t
			GnId() const
			{
				return StringValue(GNSDK_GDO_VALUE_GNID);
			}

			/**
			 * Contributor's Gracenote unique identifier.
			 * @return Gracenote Unique ID
			 */
			gnsdk_cstr_t
			GnUId() const
			{
				return StringValue(GNSDK_GDO_VALUE_GNUID);
			}

			/**
			 * Retrieves the contributor's product identifier.
			 * @return Gracenote Product ID
			 * <p><b>Remarks:</b></p>
			 * Available for most types, this retrieves a value which can be stored or transmitted. This
			 * value can be used as a static identifier for the current content as it will not change over time.
			 */
			gnsdk_cstr_t
			ProductId() const
			{
				return StringValue(GNSDK_GDO_VALUE_PRODUCTID);
			}

			/**
			 * Contributor's Gracenote Tui (title-unique identifier)
			 * @return Tui
			 */
			gnsdk_cstr_t
			Tui() const
			{
				return StringValue(GNSDK_GDO_VALUE_TUI);
			}

			/**
			 * Contributor's Gracenote Tui Tag
			 * @return Tui Tag
			 */
			gnsdk_cstr_t
			TuiTag() const
			{
				return StringValue(GNSDK_GDO_VALUE_TUI_TAG);
			}

			/**
			 * Contributor's birth date.
			 * @return Date of birth
			 */
			gnsdk_cstr_t
			BirthDate() const
			{
				return StringValue(GNSDK_GDO_VALUE_BIRTH_DATE);
			}

			/**
			 * Contributor's place of birth.
			 * @return Place of birth
			 */
			gnsdk_cstr_t
			BirthPlace() const
			{
				return StringValue(GNSDK_GDO_VALUE_BIRTH_PLACE);
			}

			/**
			 * Date contributor died
			 * @return Date of death
			 */
			gnsdk_cstr_t
			DeathDate() const
			{
				return StringValue(GNSDK_GDO_VALUE_DEATH_DATE);
			}

			/**
			 * Contributor's place of death.
			 * @return Place of death
			 */
			gnsdk_cstr_t
			DeathPlace() const
			{
				return StringValue(GNSDK_GDO_VALUE_DEATH_PLACE);
			}

			/**
			 * Contributor's media space, e.g., music, film, stage. List/locale dependent field.
			 * @return Media space
			 * <p><b>Remarks:</b></p>
			 * This is a list-based value requiring that a corresponding locale or list be loaded.
			 */
			gnsdk_cstr_t
			MediaSpace() const
			{
				return StringValue(GNSDK_GDO_VALUE_MEDIA_SPACE);
			}

			/**
			 *  Content (cover art, review, etc) object
			 *  @param GnContentType object
			 *  @return Content object
			 */
			GnContent
			Content(GnContentType contentType) const
			{
				return ChildGet<GnContent>( gnconvert::gn_content_type_to_string(contentType));
			}

			/**
			 *  Fetch the contributor's image content object
			 *  @return Content object
			 */
			GnContent
			Image() const
			{
				return ChildGet<GnContent>(GNSDK_GDO_CHILD_CONTENT_IMAGEARTIST);
			}

/* #ifdef GNSDK_VIDEO */
			/**
			 * Contributor's biography when received from a video response.
			 * When the contributor object was derived from a video response use this
			 * method to btain the biography.
			 * @return Biography
			 */
			gnsdk_cstr_t
			BiographyVideo() const
			{
				return StringValue(GNSDK_GDO_VALUE_BIOGRAPHY);
			}

/* #endif / * GNSDK_VIDEO * / */

			/**
			 * Fetch the contributor's biography content object.
			 * @return Content object
			 */
			GnContent
			Biography() const
			{
				return ChildGet<GnContent>(GNSDK_GDO_CHILD_CONTENT_BIOGRAPHY);
			}

			/**
			 * Contributor name object
			 * @return Name
			 */
			GnName
			Name() const
			{
				return ChildGet<GnName>(GNSDK_GDO_CHILD_NAME_OFFICIAL);
			}

			/**
			 * Iterator for accessing the contributor's official name(s).
			 * @return Iterator
			 */
			name_iterable
			NamesOfficial() const
			{
				return name_iterable(gn_gdo_provider<GnName>(*this, GNSDK_GDO_CHILD_NAME_OFFICIAL), GN_GDO_START);
			}

			/**
			 * Iterator for accessing the contributor's regional name(s).
			 * @return Iterator
			 */
			name_iterable
			NamesRegional() const
			{
				return name_iterable(gn_gdo_provider<GnName>(*this, GNSDK_GDO_CHILD_NAME_REGIONAL), GN_GDO_START);
			}

			/**
			 * Iterator for contirbutor associated content.
			 * @return Iterator
			 */
			content_iterable
			Contents() const
			{
				return content_iterable(gn_gdo_provider<GnContent>(*this, GNSDK_GDO_CHILD_CONTENT), GN_GDO_START);
			}

			/**
			 * Iterator for contributor associated external IDs (3rd party IDs, e.g., Amazon's)
			 * @return Iterator
			 */
			externalid_iterable
			ExternalIds() const
			{
				return externalid_iterable(gn_gdo_provider<GnExternalId>(*this, GNSDK_GDO_CHILD_EXTERNAL_ID), GN_GDO_START);
			}

			/**
			 * Contributor that collaborated with this contributor in the context of the returned result.
			 * @return Contributor
			 */
			GnContributor
			Collaborator() const
			{
				return ChildGet<GnContributor>(GNSDK_GDO_CHILD_CONTRIBUTOR);
			}

			/**
			 * Contributor's genre. List/locale, multi-level field.
			 * @param level	[in] Data level
			 * @return Genre
			 * <p><b>Remarks:</b></p>
			 * This is a list-based value requiring that a corresponding locale or list be loaded.
			 */
			gnsdk_cstr_t
			Genre(GnDataLevel level) const
			{
				gnsdk_cstr_t key = GNSDK_NULL;
				switch (level)
				{
				case kDataLevel_1:
					key = GNSDK_GDO_VALUE_GENRE_LEVEL1;
					break;

				case kDataLevel_2:
					key = GNSDK_GDO_VALUE_GENRE_LEVEL2;
					break;

				case kDataLevel_3:
					key = GNSDK_GDO_VALUE_GENRE_LEVEL3;
					break;

				default:
					break;
				}
				return StringValue(key);
			}

			/**
			 * Contributor's origin, e.g., New York City
			 * @param level     [in] Data level
			 * @return Origin
			 * <p><b>Remarks:</b></p>
			 * This is a list-based value requiring that a corresponding locale or list be loaded.
			 */
			gnsdk_cstr_t
			Origin(GnDataLevel level) const
			{
				gnsdk_cstr_t key = GNSDK_NULL;
				switch (level)
				{
				case kDataLevel_1:
					key = GNSDK_GDO_VALUE_ORIGIN_LEVEL1;
					break;

				case kDataLevel_2:
					key = GNSDK_GDO_VALUE_ORIGIN_LEVEL2;
					break;

				case kDataLevel_3:
					key = GNSDK_GDO_VALUE_ORIGIN_LEVEL3;
					break;

				case kDataLevel_4:
					key = GNSDK_GDO_VALUE_ORIGIN_LEVEL4;
					break;

				default:
					break;
				}
				return StringValue(key);
			}

			/**
			 * Contributor's era. List/locale dependent, multi-level field.
			 * @param level	[in] Data level
			 * @return Era
			 * <p><b>Remarks:</b></p>
			 * This is a list-based value requiring that a corresponding locale or list be loaded.
			 */
			gnsdk_cstr_t
			Era(GnDataLevel level) const
			{
				gnsdk_cstr_t key = GNSDK_NULL;
				switch (level)
				{
				case kDataLevel_1:
					key = GNSDK_GDO_VALUE_ERA_LEVEL1;
					break;

				case kDataLevel_2:
					key = GNSDK_GDO_VALUE_ERA_LEVEL2;
					break;

				case kDataLevel_3:
					key = GNSDK_GDO_VALUE_ERA_LEVEL3;
					break;

				default:
					break;
				}
				return StringValue(key);
			}

			/**
			 * Contributor's artist type. List/locale dependent, multi-level field.
			 * @param level	[in] Data level
			 * @return Artist type
			 * <p><b>Remarks:</b></p>
			 * This is a list-based value requiring that a corresponding locale or list be loaded.
			 */
			gnsdk_cstr_t
			ArtistType(GnDataLevel level) const
			{
				gnsdk_cstr_t key = GNSDK_NULL;
				switch (level)
				{
				case kDataLevel_1:
					key = GNSDK_GDO_VALUE_ARTISTTYPE_LEVEL1;
					break;

				case kDataLevel_2:
					key = GNSDK_GDO_VALUE_ARTISTTYPE_LEVEL2;
					break;

				default:
					break;
				}
				return StringValue(key);
			}

			/**
			 *  Get flag indicating if this is a collaborator result
			 *  @return True if a collaborator result, false otherwise
			 */
			bool
			CollaboratorResult() const
			{
				gnsdk_cstr_t return_value = StringValue(GNSDK_GDO_VALUE_COLLABORATOR_RESULT);
				return gnstd::gn_strtobool(return_value);
			}

		};  /* GnContributor */


		/**
		 * Lists the contribution of a person (or occasionally a company, such as a record label)
		 * to a recording.
		 *
		 * <p><b>SDK Documentation</b></p>
		 *
		 * Topic:  Data Models
		 *
		 *  The above topic displays all the metadata returned from a recognition event,
		 *  including objects containing a GnCredit object.
		 *  It does this in an expand/collapse format, showing object hierarchy and
		 *  a description of each field returned.
		 *
		 */
		class GnCredit : public GnDataObject
		{
		public:
			GNWRAPPER_ANNOTATE
								GNSDK_CHECKED_CAST(GnCredit, GNSDK_GDO_TYPE_CREDIT);

			/**
			 * Constructs empty GnCredit object
			 */
			GnCredit() { }

			/**
			 * Constructs a GnCredit object from a native handle
			 * @param gdoHandle	[in] Native handle
			 */
			GnCredit(gnsdk_gdo_handle_t gdoHandle) : GnDataObject(gdoHandle) { }

			virtual
			~GnCredit() { }

			/**
			 * Credit's name, such as the name of the person or company.
			 * @return Name
			 */
			GnName
			Name() const
			{
				return ChildGet<GnName>(GNSDK_GDO_CHILD_NAME_OFFICIAL);
			}

			/**
			 * Credit's role
			 * @return Role
			 * <p><b>Remarks:</b></p>
			 * This is a list-based value requiring that a corresponding locale or list be loaded.
			 */
			GnRole
			Role() const
			{
				return Reflect<GnRole>();
			}

			/**
			 * Credit's contributor.
			 * @return Contributor
			 */
			GnContributor
			Contributor() const
			{
				return ChildGet<GnContributor>(GNSDK_GDO_CHILD_CONTRIBUTOR);
			}

		};  /* GnCredit */


	} /* namespace metadata */
}     /* namespace gracenote */
#endif /* _GNSDK_METADATA_HPP_ */

