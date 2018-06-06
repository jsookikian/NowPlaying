/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
  *
 */

/* gnsdk_manager_gdo.h: GDO interface for the GNSDK Manager.
*/

#ifndef _GNSDK_MANAGER_GDO_H_
#define _GNSDK_MANAGER_GDO_H_

#include "gnsdk_manager_locales.h"
#include "gnsdk_manager_gdo_values.h"

#ifdef __cplusplus
extern "C"{
#endif


/******************************************************************************
 * Typedefs
 ******************************************************************************/
#ifndef SWIG
/** @internal gnsdk_gdo_handle_t @endinternal
*  Gracenote Data Object handle. An application receives this handle from many GNSDK APIs that
return Gracenote data. All
*  Gracenote data is accessed through the GNSDK Manager GDO APIs.
*  This handle must be released by gnsdk_manager_gdo_release.
* @hideinitializer
* @ingroup GDO_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_gdo_handle_t );


/******************************************************************************
 * SDK Manager 'Gracenote Data Objects (GDOs)' APIs
 ******************************************************************************/


/** @internal gnsdk_manager_gdo_get_type @endinternal
*  Retrieves the type of a given GDO.
*  @param gdo_handle [in] Handle to GDO to retrieve the type for
*  @param p_gdo_type [out] Pointer to receive GDO type value for given GDO
*  <p><b>Remarks:</b></p>
*  GDO handles do not clearly define a GDO's contents. Use this API to retrieve a GDO's type, as
this enables the application to more accurately determine what data the specific GDO contains.
*  Possible type values are defined in GDO Types.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_get_type(
	gnsdk_gdo_handle_t	gdo_handle,
	gnsdk_cstr_t*		p_gdo_type
	);


/** @internal gnsdk_manager_gdo_is_type @endinternal
*  Test the type of a given GDO.
*  @param gdo_handle [in] Handle to GDO to retrieve the type for
*  @param gdo_type [in] GDO type value to expect for given GDO
*  <p><b>Remarks:</b></p>
*  Use this API to test a GDO to ensure it is of an expected type.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_is_type(
	gnsdk_gdo_handle_t	gdo_handle,
	gnsdk_cstr_t		gdo_type
	);


/** @internal gnsdk_manager_gdo_value_count @endinternal
*  Retrieves the number of occurrences of the given value key that are available in a given GDO.
*  @param gdo_handle [in] Handle to GDO
*  @param value_key [in] GDO value key to count
*  @param p_count [out] Pointer to integer that receives the count
*  <p><b>Remarks:</b></p>
*  Use this function to count values of a specific GDO; note that only those values accessible in
the current type are considered.
*
*  When this API successfully counts zero (0) occurrences of the key with no errors, the system
displays the SDKMGRERR_NoError return code to indicate processing success.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_value_count(
	gnsdk_gdo_handle_t	gdo_handle,
	gnsdk_cstr_t		value_key,
	gnsdk_uint32_t*		p_count
	);

/** @internal gnsdk_manager_gdo_value_get @endinternal
*  Retrieves a value from a given GDO for a given value key.
*  @param gdo_handle [in] Handle to GDO
*  @param value_key [in] GDO value key to retrieve
*  @param ordinal [in] Retrieve n'th instance of the value (1-based)
*  @param p_value [out] Pointer to string to receive the GDO value
*  <p><b>Remarks:</b></p>
*  When successfully completed, this function returns a value for the <code>p_value</code> parameter that should
not be freed, as this value is managed by the GDO and is guaranteed to be valid as long as the GDO
handle is valid.
* <p><b>Note:</b></p>
*  The ordinal parameter is 1-based. Set to '1' to retrieve the first (or only) instance of the
value.
*  <p><b>Retrieving Locale-dependent Values</b></p>
*  <ul>
*  <li>To obtain locale-dependent values, a GDO must first have a default or specifically-configured
locale.</li>
*  <li>To set a default locale, use <code>gnsdk_manager_locale_set_group_default</code>.</li>
*  <li>To override a default locale and have the GDO obtain locale data from another locale, use
<code>gnsdk_gdo_set_locale</code>.</li>
*  <li>To successfully retrieve list-based values, the configured locale must be successfully loaded
using <code>gnsdk_gdo_set_locale</code>. Unsuccessful loading results in a <code>LocaleNotLoaded</code> error.</li>
*  <li>To successfully retrieve non-list based values, the SDK first attempts to retrieve values
corresponding to the specified locale. If values for the specified locale are not available, the
application then retrieves values in the default (or "official") locale defined for the metadata.</li>
*  </ul>
*
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_value_get(
	gnsdk_gdo_handle_t	gdo_handle,
	gnsdk_cstr_t		value_key,
	gnsdk_uint32_t		ordinal,
	gnsdk_cstr_t*		p_value
	);

/** @internal gnsdk_manager_gdo_child_count @endinternal
*  Retrieves the number of children of a given type that are available in a given GDO.
*  @param gdo_handle [in] Handle to GDO
*  @param child_key [in] GDO child key to count
*  @param p_count [out] Pointer to integer that receives the count
*  <p><b>Remarks:</b></p>
*  Use this function to count children of a specific GDO; note that only those children accessible
in the current type are considered.
*
*  When this function successfully counts zero (0) occurrences of the child key with no errors, the
system displays the SDKMGRERR_NoError return code to indicate processing success.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_child_count(
	gnsdk_gdo_handle_t	gdo_handle,
	gnsdk_cstr_t		child_key,
	gnsdk_uint32_t*		p_count
	);

/** @internal gnsdk_manager_gdo_child_get @endinternal
*  Retrieves a child GDO from a given GDO for a given type key.
*  @param gdo_handle [in] Handle to GDO
*  @param child_key [in] GDO child key to retrieve
*  @param ordinal [in] Retrieve n'th instance of the child (1 based)
*  @param p_gdo_handle [out] Pointer to GDO handle to receive the
*  GDO child
*  <p><b>Remarks:</b></p>
*  The child GDO returned in the <code>p_gdo_handle</code> parameter upon success must be released with
<code>gnsdk_manager_gdo_release</code> when no longer needed.
* <p><b>Note:</b></p>
*  The ordinal parameter is 1-based. Set to '1' to retrieve the first (or only) child GDO instance.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_child_get(
	gnsdk_gdo_handle_t	gdo_handle,
	gnsdk_cstr_t		child_key,
	gnsdk_uint32_t		ordinal,
	gnsdk_gdo_handle_t* p_gdo_handle
	);

/** @internal gnsdk_manager_gdo_serialize @endinternal
*  Serializes a GDO into encrypted text for storage or transmission.
*  @param gdo_handle [in] Handle to a GDO
*  @param p_serialized_gdo [out] Pointer to string to receive serialized GDO
*  data
*  <p><b>Remarks:</b></p>
*  The current implementation only serializes a minimal set of data representing the GDO.
Deserialization of this value does not result in the same GDO before serialization. The deserialized
GDO can be used in a follow-up query to retrieve the original GDO data.
(
*  Use <code>gnsdk_manager_string_free</code> to free the serialized string when application is finished using
it.
* Note: This API does not currently serialize Response GDOs. The call, in this case, will succeed but no output data will be generated.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_serialize(
	gnsdk_gdo_handle_t	gdo_handle,
	gnsdk_str_t*		p_serialized_gdo
	);

/** @internal gnsdk_manager_gdo_deserialize @endinternal
*  Reconstitutes a GDO handle from serialized GDO data.
*  @param serialized_gdo [in] String of serialized GDO handle data
*  @param p_gdo_handle [out] Pointer to receive a GDO handle
*  <p><b>Remarks:</b></p>
*  The GDO returned in the <code>p_gdo_handle</code> parameter upon success must be released with
<code>gnsdk_manager_gdo_release</code> when no longer needed.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_deserialize(
	gnsdk_cstr_t		serialized_gdo,
	gnsdk_gdo_handle_t*	p_gdo_handle
	);

/** @internal gnsdk_manager_gdo_render2 @endinternal
*  Renders contents of a GDO as an XML or JSON string.
*  @param gdo_handle [in] Handle to a GDO to render
*  @param format_version [in] Version of GDO Data Model to render to. Use '1' for compatibility with gnsdk_manager_gdo_render API.
*  @param render_flags [in] One or more GDO render flags to enable optional content in rendered output
*  @param p_render_str [out] Pointer to the string that receives the rendered output
*  <p><b>Remarks:</b></p>
*  Use this function with the GDO render flags to render data in a GDO to XML or JSON.<br>
*  Use <code>gnsdk_manager_string_free</code> to free the output string when the application is finished using it.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_render2(
	gnsdk_gdo_handle_t	gdo_handle,
	gnsdk_uint32_t		format_version,
	gnsdk_uint32_t		render_flags,
	gnsdk_str_t*		p_render_str
	);

/** @internal gnsdk_manager_gdo_render @endinternal
*  Renders contents of a GDO as an XML or JSON string.
*  @param gdo_handle [in] Handle to a GDO to render
*  @param render_flags [in] One or more GDO render flags to enable optional content in rendered output
*  @param p_render_str [out] Pointer to the string that receives the rendered output
*  <p><b>Remarks:</b></p>
*  Use this function with the GDO render flags to render data in a GDO to XML or JSON.<br>
*  Use <code>gnsdk_manager_string_free</code> to free the output string when the application is finished using it.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_render(
	gnsdk_gdo_handle_t	gdo_handle,
	gnsdk_uint32_t		render_flags,
	gnsdk_str_t*		p_render_str
	);


/** @internal gnsdk_manager_gdo_render_to_xml @endinternal
*  <p><b>Remarks:</b></p>
*  This API is deprecated. Use gnsdk_manager_gdo_render2 instead.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_DEPRECATED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_render_to_xml(
	gnsdk_gdo_handle_t	gdo_handle,
	gnsdk_uint32_t		render_flags,
	gnsdk_str_t*		p_render_str
	);

#endif

/** @internal GNSDK_GDO_RENDER_XML @endinternal
*  Renders GDO metadata as XML output 
*  <p><b>Remarks:</b></p>
*  As XML is the default output format, this flag just makes explicit
*  that this API is to render the output as XML.
*  GDO render flags can be combined to output more metadata.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_XML					0x00000

/** @internal GNSDK_GDO_RENDER_JSON @endinternal
*  Renders GDO metadata as JSON output (otherwise XML is rendered format)
*  <p><b>Remarks:</b></p>
*  Use this flag to render output as JSON.
*  GDO render flags can be combined to output more metadata.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_JSON					0x10000

/** @internal GNSDK_GDO_RENDER_NONEWLINES @endinternal
*  Renders GDO without newlines (as single line of text)
*  <p><b>Remarks:</b></p>
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_NONEWLINES				0x20000

/** @internal GNSDK_GDO_RENDER_STANDARD @endinternal
*  Renders standard metadata into the output for a GDO.
*  <p><b>Remarks:</b></p>
*  Renders standard common metadata but without special identifiers: no credits and no Ids.
*  GDO render flags can be combined to output more metadata.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_STANDARD				0x0001

/** @internal GNSDK_GDO_RENDER_CREDITS @endinternal
*  Renders any credit metadata into the output for a GDO.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_CREDITS				0x0002

/** @internal GNSDK_GDO_RENDER_SORTABLE @endinternal
*  Renders values for sorting names and titles into the output for a GDO.
*  Note: this flag is going to be deprecated and sortable data will be rendered
*  based on the presence of the '*_ENABLE_SORTABLE' query option on the initial
*  query.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_SORTABLE				0x0004

/** @internal GNSDK_GDO_RENDER_SERIAL_GDOS @endinternal
*  Renders any serialized GDO values into the output for a GDO.
*  <p><b>Remarks:</b></p>
*  Serialized GDOs provide an identifier that can be used to re-retrieve the respective type from
Gracenote, or to use as input for follow-on queries on the originating type.
*  GDO render flags can be combined to output more metadata.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_SERIAL_GDOS			0x0010

/** @internal GNSDK_GDO_RENDER_PRODUCT_IDS @endinternal
*  Renders any Gracenote Product ID values into the output for a GDO.
*  <p><b>Remarks:</b></p>
*  Product IDs provide a static identifier for each type for which they are available.
*  GDO render flags can be combined to output more metadata.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_PRODUCT_IDS			0x0020

/** @internal GNSDK_GDO_RENDER_DISCOVER_SEEDS @endinternal
*  Renders any Gracenote Discover Seed values into the output for a GDO.
*  <p><b>Remarks:</b></p>
*  Discover Seeds provide for compatibility with Gracenote Discover product.
*  GDO render flags can be combined to output more metadata.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_DISCOVER_SEEDS			0x0040

/** @internal GNSDK_GDO_RENDER_RAW_TUIS @endinternal
*  Renders any Gracenote TUI values into output for a GDO.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_RAW_TUIS				0x0080

/** @internal GNSDK_GDO_RENDER_GNIDS @endinternal
  *
  * @hideinitializer
  * @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_GNIDS					0x0100

/** @internal GNSDK_GDO_RENDER_GNUIDS @endinternal
  *
  * @hideinitializer
  * @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_GNUIDS					0x0200

/** @internal GNSDK_GDO_RENDER_GENRE_LEVEL1 @endinternal
*  Renders any Gracenote genres as level-1 (coarse) values into output for a GDO.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_GENRE_LEVEL1			0x1000

/** @internal GNSDK_GDO_RENDER_GENRE_LEVEL2 @endinternal
*  Renders any Gracenote genres as level-2 (more granular) values into output for a GDO.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_GENRE_LEVEL2			0x2000

/** @internal GNSDK_GDO_RENDER_GENRE_LEVEL3 @endinternal
*  Renders any Gracenote genres as level-3 (fine grained) values into output for a GDO.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_GENRE_LEVEL3			0x4000

/** @internal GNSDK_GDO_RENDER_DESCRIPTORS @endinternal
*  Renders all Gracenote List-based descriptors (genre, era, mood, etc...) values into output for a GDO.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_DESCRIPTORS			0x8000

/** @internal GNSDK_GDO_RENDER_DEFAULT @endinternal
*  Renders the default metadata into the output for a GDO (identifiers not included).
*  <p><b>Remarks:</b></p>
*  Equivalent to the set of flags:
*  <ul>
*  <li>GNSDK_GDO_RENDER_STANDARD</li>
*  <li>GNSDK_GDO_RENDER_GENRE_LEVEL2</li>
*  </ul>
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_DEFAULT				(GNSDK_GDO_RENDER_STANDARD|GNSDK_GDO_RENDER_GENRE_LEVEL2)

/** @internal GNSDK_GDO_RENDER_FULL @endinternal
*  Renders majority of metadata into the output for a GDO (identifiers not included)
*  <p><b>Remarks:</b></p>
*  Equivalent to the set of flags:
*  <ul>
*  <li>GNSDK_GDO_RENDER_DEFAULT<li>
*  <li>GNSDK_GDO_RENDER_CREDITS<li>
*  <li>GNSDK_GDO_RENDER_SORTABLE<li>
*  <li>GNSDK_GDO_RENDER_GNIDS<li>
*  </ul>
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_FULL					(GNSDK_GDO_RENDER_STANDARD|GNSDK_GDO_RENDER_CREDITS|GNSDK_GDO_RENDER_SORTABLE|GNSDK_GDO_RENDER_GNIDS|GNSDK_GDO_RENDER_DESCRIPTORS)

/** @internal GNSDK_GDO_RENDER_SUBMIT @endinternal
*  Renders any Gracenote data supported for Submit editable GDOs into the output for a GDO. This
rendered data includes both the supported editable and non-editable data.
*  Use in conjuction with STANDARD, DEFAULT or FULL render flags.
* @hideinitializer
* @ingroup GDO_RenderFlags
*/
#define GNSDK_GDO_RENDER_SUBMIT					0x80000

#ifndef SWIG
/** @internal gnsdk_manager_gdo_set_locale @endinternal
*  Applies lists to use for retrieving and rendering locale-related values.
*  @param gdo_handle [in] Handle to a GDO
*  @param locale_handle [in] Handle to a locale
*  <p><b>Remarks:</b></p>
*  Use this function to set the locale of retrieved and rendered locale-dependent data for a
specific GDO handle. This function overrides any applicable global defaults set by
<code>gnsdk_manager_locale_set_group_default</code>.
*  <p><b>Locale Language Support</b></p>
*  This function supports all locale languages and successfully assigns a locale for the given GDO.
The locale is used for future calls to the <code>gnsdk_manager_gdo_value_get</code> function when
locale-dependent values are requested.
*
*  For list-based values, the <code>gnsdk_manager_gdo_value_get</code> function returns locale-specific values
only when <code>gnsdk_manager_gdo_set_locale</code> succeeds for the specified locale.
*
*  For non-list-based values, the <code>gnsdk_manager_gdo_value_get</code> function returns values in the
specified locale only if these values are available from Gracenote Service. If not, the application
uses the default (or "official") locale data for these values. For example, plot values
(GNSDK_GDO_VALUE_PLOT_*) are
*  non-list-based. If a plot summary value (GNSDK_GDO_VALUE_PLOT_SUMMARY) is available only in the
English language, and the specific locale is defined for the Spanish language, the application
displays the plot summary in the English language.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_set_locale(
	gnsdk_gdo_handle_t		gdo_handle,
	gnsdk_locale_handle_t	locale_handle
	);

/** @internal gnsdk_manager_gdo_addref @endinternal
*  Increments reference count for a GDO handle.
*  @param gdo_handle [in] Handle to a GDO
*  <p><b>Remarks:</b></p>
*  All calls to <code>gnsdk_manager_gdo_addref</code> must be paired with a call to <code>gnsdk_manager_gdo_release</code>.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_addref(
	gnsdk_gdo_handle_t	gdo_handle
	);

/** @internal gnsdk_manager_gdo_release @endinternal
*  Releases a GDO handle reference.
*  @param gdo_handle [in] Handle to a GDO
*  <p><b>Remarks:</b></p>
*  All GDO handles retrieved must be passed to <code>gnsdk_manager_gdo_release</code> when no longer needed.
Passing a null handle returns SDKMGRERR_NoError.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_release(
	gnsdk_gdo_handle_t	gdo_handle
	);

/** @internal gnsdk_manager_gdo_create_from_render @endinternal
*  Creates a GDO handle from XML or JSON created by gnsdk_manager_gdo_render.
*  @param render_str [in] XML or JSON string as create by gnsdk_manager_gdo_render.
*  @param p_gdo_handle [out] Pointer to receive a GDO handle
*  <p><b>Remarks:</b></p>
*  Use this function when you need to recreate a GDO handle from rendered GDO string.
*
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_create_from_render(
	gnsdk_cstr_t		render_str,
	gnsdk_gdo_handle_t*	p_gdo_handle
	);

GNSDK_DEPRECATED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_create_from_xml(
	gnsdk_cstr_t		xml_str,
	gnsdk_gdo_handle_t*	p_gdo_handle
	);

/** @internal gnsdk_manager_gdo_create_from_id @endinternal
*  Creates a GDO handle from identifier information.
*  @param id_value [in] A value determined by the id_source parameter
*  @param id_value_tag [in_opt] A value determined by the id_source parameter
*  @param id_source [in] An available ID Source value such as GNSDK_ID_SOURCE_ALBUM or one of the other GNSDK_ID_SOURCE* defines
*  @param p_gdo_handle [out] Pointer to receive a GDO handle
*  <p><b>Remarks:</b></p>
*  Use this function when you need to convert an ID source tag to a GDO, such as using a CDDB ID,
Product ID, or
*  TUI and a TUI Tag from Gracenote.
*
*  TUIs are proprietary Gracenote identifiers. Gracenote provides these values to customers only for
special circumstances. In addition to providing TUI values, Gracenote will also inform you of the correct ID Source value to use for the type parameter.
* @hideinitializer
* @ingroup GDO_Functions
*/
GNSDK_EXPORTED gnsdk_error_t GNSDK_API
gnsdk_manager_gdo_create_from_id(
	gnsdk_cstr_t		id_value,
	gnsdk_cstr_t		id_value_tag,
	gnsdk_cstr_t		id_source,
	gnsdk_gdo_handle_t*	p_gdo_handle
	);
#endif
/** @internal GNSDK_ID_SOURCE_ALBUM @endinternal
*  Album source ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes
*/
#define GNSDK_ID_SOURCE_ALBUM						"gnsdk_id_source_album"
/** @internal GNSDK_ID_SOURCE_TRACK @endinternal
*  Track source ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes
*/
#define GNSDK_ID_SOURCE_TRACK						"gnsdk_id_source_track"
/** @internal GNSDK_ID_SOURCE_CONTRIBUTOR @endinternal
*  Contributor source ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes
*/
#define GNSDK_ID_SOURCE_CONTRIBUTOR					"gnsdk_id_source_contributor"
/** @internal GNSDK_ID_SOURCE_VIDEO_WORK @endinternal
*  Video work source ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes
*/
#define GNSDK_ID_SOURCE_VIDEO_WORK					"gnsdk_id_source_videowork"
/** @internal GNSDK_ID_SOURCE_VIDEO_PRODUCT @endinternal
*  Video product source ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes
*/
#define GNSDK_ID_SOURCE_VIDEO_PRODUCT				"gnsdk_id_source_videoprod"
/** @internal GNSDK_ID_SOURCE_VIDEO_DISC @endinternal
*  Video disc source ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes
*/
#define GNSDK_ID_SOURCE_VIDEO_DISC					"gnsdk_id_source_videodisc"
/** @internal GNSDK_ID_SOURCE_VIDEO_SEASON @endinternal
*  Season source ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes
*/
#define GNSDK_ID_SOURCE_VIDEO_SEASON				"gnsdk_id_source_videoseason"
/** @internal GNSDK_ID_SOURCE_VIDEO_SERIES @endinternal
*  Series source ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes
*/
#define GNSDK_ID_SOURCE_VIDEO_SERIES				"gnsdk_id_source_videoseries"


/** @internal GNSDK_ID_SOURCE_TVPROGRAM @endinternal
  *
  *   Video TVPROGRAM source ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes_Epg
*/
#define GNSDK_ID_SOURCE_TVPROGRAM					"gnsdk_id_source_tvprogram"

/** @internal GNSDK_ID_SOURCE_TVPROVIDER @endinternal
  *
  * TV provider ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes_Epg
*/
#define GNSDK_ID_SOURCE_TVPROVIDER					"gnsdk_id_source_tvprovider"
/** @internal GNSDK_ID_SOURCE_TVCHANNEL @endinternal
  *
  * TV channel ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes_Epg
*/
#define GNSDK_ID_SOURCE_TVCHANNEL					"gnsdk_id_source_tvchannel"


/** @internal GNSDK_ID_SOURCE_LYRIC @endinternal
*  Lyric source ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes
*/
#define GNSDK_ID_SOURCE_LYRIC						"gnsdk_id_source_lyric"
/** @internal GNSDK_ID_SOURCE_CDDBID @endinternal
*  CDDB identification source ID
* @hideinitializer
* @ingroup GDO_IDSourceTypes
*/
#define GNSDK_ID_SOURCE_CDDBID						"gnsdk_id_source_cddbid"


#ifdef __cplusplus
}
#endif

#endif /** @internal _GNSDK_MANAGER_GDO_H_ @endinternal
*  GDO interface for the GNSDK Manager.
*/
