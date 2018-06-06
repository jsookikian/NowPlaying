/*
 * Copyright (c) 2000-2016 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

/* link.cpp
 *
 * Implementation of C++ wrapper for GNSDK
 *
 */
#include "gnsdk_list.hpp"
#include "gnsdk_convert.hpp"

using namespace gracenote;
using namespace gracenote::metadata;

static void GNSDK_CALLBACK_API
_list_status_callback(void* callback_data, gnsdk_status_t status, gnsdk_uint32_t percent_complete, gnsdk_size_t bytes_total_sent, gnsdk_size_t bytes_total_received, gnsdk_bool_t* p_abort);

/*-----------------------------------------------------------------------------
 *  _convertListTypeCCpp
 */
static GnListType
_convertListTypeCCpp(gnsdk_cstr_t c_list_type)
{
	GnListType listType = kListTypeLanguages;

	if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_LANGUAGES) == 0 )
	{
		listType = kListTypeLanguages;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_SCRIPTS) == 0 )
	{
		listType = kListTypeScripts;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_GENRES) == 0 )
	{
		listType = kListTypeGenres;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_ORIGINS) == 0 )
	{
		listType = kListTypeOrigins;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_ERAS) == 0 )
	{
		listType = kListTypeEras;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_ARTISTTYPES) == 0 )
	{
		listType = kListTypeArtistTypes;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_ROLES) == 0 )
	{
		listType = kListTypeRoles;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_GENRES_VIDEO) == 0 )
	{
		listType = kListTypeGenreVideos;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_RATINGS) == 0 )
	{
		listType = kListTypeRatings;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_RATINGTYPES) == 0 )
	{
		listType = kListTypeRatingTypes;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_CONTRIBUTORS) == 0 )
	{
		listType = kListTypeContributors;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_FEATURETYPES) == 0 )
	{
		listType = kListTypeFeatureTypes;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOREGIONS) == 0 )
	{
		listType = kListTypeVideoRegions;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOTYPES) == 0 )
	{
		listType = kListTypeVideoTypes;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_MEDIATYPES) == 0 )
	{
		listType = kListTypeMediaTypes;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOSERIALTYPES) == 0 )
	{
		listType = kListTypeVideoSerialTypes;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_WORKTYPES) == 0 )
	{
		listType = kListTypeWorkTypes;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_MEDIASPACES) == 0 )
	{
		listType = kListTypeMediaSpaces;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_MOODS) == 0 )
	{
		listType = kListTypeMoods;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_TEMPOS) == 0 )
	{
		listType = kListTypeTempos;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_COMPOSITION_FORM) == 0 )
	{
		listType = kListTypeCompostionForm;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_INSTRUMENTATION) == 0 )
	{
		listType = kListTypeInstrumentation;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOSTORYTYPE) == 0 )
	{
		listType = kListTypeVideoStoryType;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOAUDIENCE) == 0 )
	{
		listType = kListTypeVideoAudience;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOMOOD) == 0 )
	{
		listType = kListTypeVideoMood;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOREPUTATION) == 0 )
	{
		listType = kListTypeVideoReputation;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOSCENARIO) == 0 )
	{
		listType = kListTypeVideoScenario;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOSETTINGENV) == 0 )
	{
		listType = kListTypeVideoSettingEnv;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOSETTINGPERIOD) == 0 )
	{
		listType = kListTypeVideoSettingPeriod;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOSOURCE) == 0 )
	{
		listType = kListTypeVideoSource;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOSTYLE) == 0 )
	{
		listType = kListTypeVideoStyle;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_VIDEOTOPIC) == 0 )
	{
		listType = kListTypeVideoTopic;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_EPGVIEWINGTYPES) == 0 )
	{
		listType = kListTypeEpgViewingTypes;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_EPGAUDIOTYPES) == 0 )
	{
		listType = kListTypeEpgAudioTypes;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_EPGVIDEOTYPES) == 0 )
	{
		listType = kListTypeEpgVideoTypes;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_EPGCAPTIONTYPES) == 0 )
	{
		listType = kListTypeEpgCaptionTypes;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_IPGCATEGORIES_L1) == 0 )
	{
		listType = kListTypeIpgCategoriesL1;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_IPGCATEGORIES_L2) == 0 )
	{
		listType = kListTypeIpgCategoriesL2;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_EPGPRODUCTIONTYPES) == 0 )
	{
		listType = kListTypeEpgProductionTypes;
	}
	else if ( gnstd::gn_strcmp(c_list_type, GNSDK_LIST_TYPE_EPGDEVICETYPES) == 0 )
	{
		listType = kListTypeEpgDeviceTypes;
	}

	return listType;
}


/*-----------------------------------------------------------------------------
 *  _convertListTypeCppC
 */
static gnsdk_cstr_t
_convertListTypeCppC(GnListType descriptor)
{
	switch ( descriptor )
	{
	case kListTypeArtistTypes:
		return GNSDK_LIST_TYPE_ARTISTTYPES;

	case kListTypeCompostionForm:
		return GNSDK_LIST_TYPE_COMPOSITION_FORM;

	case kListTypeContributors:
		return GNSDK_LIST_TYPE_CONTRIBUTORS;

	case kListTypeEpgAudioTypes:
		return GNSDK_LIST_TYPE_EPGAUDIOTYPES;

	case kListTypeEpgCaptionTypes:
		return GNSDK_LIST_TYPE_EPGCAPTIONTYPES;

	case kListTypeEpgDeviceTypes:
		return GNSDK_LIST_TYPE_EPGDEVICETYPES;

	case kListTypeEpgProductionTypes:
		return GNSDK_LIST_TYPE_EPGPRODUCTIONTYPES;

	case kListTypeEpgVideoTypes:
		return GNSDK_LIST_TYPE_EPGVIDEOTYPES;

	case kListTypeEpgViewingTypes:
		return GNSDK_LIST_TYPE_EPGVIEWINGTYPES;

	case kListTypeEras:
		return GNSDK_LIST_TYPE_ERAS;

	case kListTypeFeatureTypes:
		return GNSDK_LIST_TYPE_FEATURETYPES;

	case kListTypeGenres:
		return GNSDK_LIST_TYPE_GENRES;

	case kListTypeGenreVideos:
		return GNSDK_LIST_TYPE_GENRES_VIDEO;

	case kListTypeInstrumentation:
		return GNSDK_LIST_TYPE_INSTRUMENTATION;

	case kListTypeIpgCategoriesL1:
		return GNSDK_LIST_TYPE_IPGCATEGORIES_L1;

	case kListTypeIpgCategoriesL2:
		return GNSDK_LIST_TYPE_IPGCATEGORIES_L2;

	case kListTypeLanguages:
		return GNSDK_LIST_TYPE_LANGUAGES;

	case kListTypeScripts:
		return GNSDK_LIST_TYPE_SCRIPTS;

	case kListTypeMediaSpaces:
		return GNSDK_LIST_TYPE_MEDIASPACES;

	case kListTypeMediaTypes:
		return GNSDK_LIST_TYPE_MEDIATYPES;

	case kListTypeMoods:
		return GNSDK_LIST_TYPE_MOODS;

	case kListTypeOrigins:
		return GNSDK_LIST_TYPE_ORIGINS;

	case kListTypeRatings:
		return GNSDK_LIST_TYPE_RATINGS;

	case kListTypeRatingTypes:
		return GNSDK_LIST_TYPE_RATINGTYPES;

	case kListTypeRoles:
		return GNSDK_LIST_TYPE_ROLES;

	case kListTypeTempos:
		return GNSDK_LIST_TYPE_TEMPOS;

	case kListTypeVideoAudience:
		return GNSDK_LIST_TYPE_VIDEOAUDIENCE;

	case kListTypeVideoMood:
		return GNSDK_LIST_TYPE_VIDEOMOOD;

	case kListTypeVideoRegions:
		return GNSDK_LIST_TYPE_VIDEOREGIONS;

	case kListTypeVideoReputation:
		return GNSDK_LIST_TYPE_VIDEOREPUTATION;

	case kListTypeVideoScenario:
		return GNSDK_LIST_TYPE_VIDEOSCENARIO;

	case kListTypeVideoSerialTypes:
		return GNSDK_LIST_TYPE_VIDEOSERIALTYPES;

	case kListTypeVideoSettingEnv:
		return GNSDK_LIST_TYPE_VIDEOSETTINGENV;

	case kListTypeVideoSettingPeriod:
		return GNSDK_LIST_TYPE_VIDEOSETTINGPERIOD;

	case kListTypeVideoSource:
		return GNSDK_LIST_TYPE_VIDEOSOURCE;

	case kListTypeVideoStoryType:
		return GNSDK_LIST_TYPE_VIDEOSTORYTYPE;

	case kListTypeVideoStyle:
		return GNSDK_LIST_TYPE_VIDEOSTYLE;

	case kListTypeVideoTopic:
		return GNSDK_LIST_TYPE_VIDEOTOPIC;

	case kListTypeVideoTypes:
		return GNSDK_LIST_TYPE_VIDEOTYPES;

	case kListTypeWorkTypes:
		return GNSDK_LIST_TYPE_WORKTYPES;

	case kListTypeInvalid:
		break;
	}

	return GNSDK_NULL;
}


/**************************************************************************
 * list_element_child_provider
 **/
GnListElement
list_element_child_provider::get_data(gnsdk_uint32_t pos)
{
	gnsdk_list_element_handle_t list_element = GNSDK_NULL;

	if ( pos < GN_UINT32_MAX)
	{
		gnsdk_error_t error = gnsdk_manager_list_element_get_child(elementHandle_, pos, &list_element);
		if (GNSDKERR_IndexOutOfRange == GNSDKERR_ERROR_CODE(error)) error = GNSDK_SUCCESS; /* out of range just allow "end" returned */
		if (GNSDKERR_SEVERE(error)) { throw GnError(); }
	}
	
	return GnListElement(list_element);
}


/*-----------------------------------------------------------------------------
 *  count
 */
gnsdk_uint32_t
list_element_child_provider::count() const
{
	gnsdk_uint32_t count = 0;

	gnsdk_error_t error = gnsdk_manager_list_element_get_child_count(elementHandle_, &count);
	if (GNSDKERR_SEVERE(error)) { throw GnError(); }

	return count;
}


/**************************************************************************
 * GnListElement
 **/


gnsdk_cstr_t
GnListElement::DisplayString() const throw (GnError)
{
	gnsdk_error_t error;
	gnsdk_cstr_t  display_string = GNSDK_NULL;

	if ( this->IsNull() == false )
	{
		error = gnsdk_manager_list_element_get_display_string(native(), &display_string);
		if (GNSDKERR_SEVERE(error)) { throw GnError(); }
	}

	return display_string;
}


/*-----------------------------------------------------------------------------
 *  Id
 */
gnsdk_uint32_t
GnListElement::Id() const throw (GnError)
{
	gnsdk_error_t  error;
	gnsdk_uint32_t id = 0;

	if ( this->IsNull() == false )
	{
		error = gnsdk_manager_list_element_get_id(native(), &id);
		if (GNSDKERR_SEVERE(error)) { throw GnError(); }
	}

	return id;
}


/*-----------------------------------------------------------------------------
 *  IdForSubmit
 */
gnsdk_uint32_t
GnListElement::IdForSubmit() const throw (GnError)
{
	gnsdk_error_t  error;
	gnsdk_uint32_t submit_id = 0;

	if ( this->IsNull() == false )
	{
		error = gnsdk_manager_list_element_get_id_for_submit(native(), &submit_id);
		if (GNSDKERR_SEVERE(error)) { throw GnError(); }
	}

	return submit_id;
}


/*-----------------------------------------------------------------------------
 *  Description
 */
gnsdk_cstr_t
GnListElement::Description() const throw (GnError)
{
	gnsdk_error_t error;
	gnsdk_cstr_t  val = GNSDK_NULL;

	if ( this->IsNull() == false )
	{
		error = gnsdk_manager_list_element_get_value(native(), GNSDK_LIST_KEY_DESC, &val);
		if (GNSDKERR_SEVERE(error)) { throw GnError(); }
	}

	return val;
}


/*-----------------------------------------------------------------------------
 *  RatingTypeId
 */
gnsdk_cstr_t
GnListElement::RatingTypeId() const throw (GnError)
{
	gnsdk_error_t error;
	gnsdk_cstr_t  val = GNSDK_NULL;

	if ( this->IsNull() == false )
	{
		error = gnsdk_manager_list_element_get_value(native(), GNSDK_LIST_KEY_RATINGTYPE_ID, &val);
		if (GNSDKERR_SEVERE(error)) { throw GnError(); }
	}

	return val;
}


/*-----------------------------------------------------------------------------
 *  Parent
 */
GnListElement
GnListElement::Parent() const throw (GnError)
{
	gnsdk_error_t               error;
	gnsdk_list_element_handle_t parent_handle = GNSDK_NULL;

	if ( this->IsNull() == false )
	{
		error = gnsdk_manager_list_element_get_parent(native(), &parent_handle);
		if (GNSDKERR_SEVERE(error)) { throw GnError(); }

		if (parent_handle == GNSDK_NULL) { throw GnError(GNSDKERR_NotFound, "No parent element found"); }
	}

	GnListElement result(parent_handle);
	return result;
}


/*-----------------------------------------------------------------------------
 *  Level
 */
gnsdk_uint32_t
GnListElement::Level() const throw (GnError)
{
	gnsdk_error_t  error;
	gnsdk_uint32_t level = 0;

	if ( this->IsNull() == false )
	{
		error = gnsdk_manager_list_element_get_level(native(), &level);
		if (error) { throw GnError(); }
	}

	return level;
}


/**************************************************************************
 * list_element_provider
 **/

GnListElement
list_element_provider::get_data(gnsdk_uint32_t pos) throw (GnError)
{
	gnsdk_list_element_handle_t list_element = GNSDK_NULL;
	
	if (pos < GN_UINT32_MAX)
	{
		gnsdk_error_t error = gnsdk_manager_list_get_element(listHandle_, level_, pos, &list_element);
		if (GNSDKERR_IndexOutOfRange == GNSDKERR_ERROR_CODE(error)) error = GNSDK_SUCCESS; /* out of range just allow "end" returned */
		if (GNSDKERR_SEVERE(error)) { throw GnError(); }
	}

	return GnListElement(list_element);
}


/*-----------------------------------------------------------------------------
 *  count
 */
gnsdk_uint32_t
list_element_provider::count() const
{
	gnsdk_uint32_t count = 0;
	gnsdk_manager_list_get_element_count(listHandle_, level_, &count);
	return count;
}


/**************************************************************************
 * GnList
 **/
GnList::GnList(GnListType listType, GnLanguage language, GnRegion region, GnDescriptor descriptor, const GnUser& user, IGnStatusEvents* pEventHandler) throw (GnError)
{
	gnsdk_list_handle_t list_handle = GNSDK_NULL;

	gnsdk_error_t error = gnsdk_manager_list_retrieve(
	    _convertListTypeCppC(listType),
	    gnconvert::gn_language_to_string(language),
	    gnconvert::gn_region_to_string(region),
		gnconvert::gn_descriptor_to_string(descriptor),
	    user.native(),
	    _list_status_callback,
	    pEventHandler,
	    &list_handle);
	if (error) { throw GnError(); }
	assign(list_handle);
}


GnList::GnList(GnListType listType, const GnLocale& locale, const GnUser& user, IGnStatusEvents* pEventHandler)  throw (GnError)
{
	gnsdk_list_handle_t list_handle = GNSDK_NULL;

	gnsdk_error_t error = gnsdk_manager_list_retrieve(
	    _convertListTypeCppC(listType),
		gnconvert::gn_language_to_string(locale.LocaleInformation().Language()),
		gnconvert::gn_region_to_string(locale.LocaleInformation().Region()),
		gnconvert::gn_descriptor_to_string(locale.LocaleInformation().Descriptor()),
	    user.native(),
	    _list_status_callback,
	    pEventHandler,
	    &list_handle);
	if (error) { throw GnError(); }

	assign(list_handle);
}


GnList::GnList(gnsdk_cstr_t serializedList) throw (GnError)
{
	gnsdk_list_handle_t list_handle = GNSDK_NULL;
	gnsdk_error_t       error       = gnsdk_manager_list_deserialize(serializedList, &list_handle);
	if (error) { throw GnError(); }

	assign(list_handle);
}


/*-----------------------------------------------------------------------------
 *  Update
 */
bool
GnList::Update(const GnUser& user, IGnStatusEvents* pEventHandler) throw (GnError)
{
	gnsdk_error_t       error;
	bool                result        = false;
	gnsdk_list_handle_t update_handle = GNSDK_NULL;

	error = gnsdk_manager_list_update(native(), user.native(), _list_status_callback, pEventHandler, &update_handle);
	if (error) { throw GnError(); }

	if (GNSDK_NULL != update_handle)
	{
		assign(update_handle);
		result = true;
	}

	return result;
}


/*-----------------------------------------------------------------------------
 *  UpdateCheck
 */
bool
GnList::UpdateCheck(const GnUser& user, IGnStatusEvents* pEventHandler) throw (GnError)
{
	gnsdk_bool_t  b_new_revision_available = GNSDK_FALSE;
	gnsdk_error_t error;

	error = gnsdk_manager_list_update_check(
	    native(),
	    user.native(),
	    _list_status_callback,
	    pEventHandler,
	    &b_new_revision_available);
	if (error) { throw GnError(); }

	return ( b_new_revision_available ) ? true : false;
}


/*-----------------------------------------------------------------------------
 *  Serialize
 */
GnString
GnList::Serialize() throw (GnError)
{
	gnsdk_str_t   serializedList = GNSDK_NULL;
	gnsdk_error_t error;

	error = gnsdk_manager_list_serialize(native(), &serializedList);
	if (error) { throw GnError(); }

	return GnString::manage(serializedList);
}


/*-----------------------------------------------------------------------------
 *  RenderToXml
 */
GnString
GnList::RenderToXml(gnsdk_uint32_t levels, GnListRenderFlags render_flags) throw (GnError)
{
	gnsdk_uint32_t render_flag_uint32 = GNSDK_LIST_RENDER_XML_MINIMAL;
	gnsdk_str_t    renderedList       = GNSDK_NULL;
	gnsdk_error_t  error;

	if (kListRenderFull == render_flags)
	{
		render_flag_uint32 = GNSDK_LIST_RENDER_XML_SUBMIT;
	}

	error = gnsdk_manager_list_render(native(), levels, render_flag_uint32, &renderedList);
	if (error) { throw GnError(); }

	return GnString::manage(renderedList);
}


/*-----------------------------------------------------------------------------
 *  Render
 */
GnString
GnList::Render(gnsdk_uint32_t levels, GnListRenderFormat renderFormat, bool bIndented) throw (GnError)
{
	gnsdk_uint32_t render_format;
	gnsdk_str_t    renderedList;
	gnsdk_error_t  error;

	if (kListRenderFormat_XML == renderFormat)
		render_format = GNSDK_LIST_RENDER_XML;
	else if (kListRenderFormat_XMLv2 == renderFormat)
		render_format = GNSDK_LIST_RENDER_XML|GNSDK_LIST_RENDER_V2;
	else if (kListRenderFormat_JSONv2 == renderFormat)
		render_format = GNSDK_LIST_RENDER_JSON|GNSDK_LIST_RENDER_V2;
	else
		render_format = GNSDK_LIST_RENDER_JSON;

	if (!bIndented)
		render_format |= GNSDK_LIST_RENDER_NOINDENT;

	error = gnsdk_manager_list_render(native(), levels, render_format, &renderedList);
	if (error) { throw GnError(); }

	return GnString::manage(renderedList);
}

GnString
GnList::RenderLevel(gnsdk_uint32_t level, GnListRenderFormat renderFormat, bool bIndented) throw (GnError)
{
	gnsdk_uint32_t render_format;
	gnsdk_str_t    renderedList;
	gnsdk_error_t  error;

	if (kListRenderFormat_XML == renderFormat)
		render_format = GNSDK_LIST_RENDER_XML;
	else if (kListRenderFormat_XMLv2 == renderFormat)
		render_format = GNSDK_LIST_RENDER_XML|GNSDK_LIST_RENDER_V2;
	else if (kListRenderFormat_JSONv2 == renderFormat)
		render_format = GNSDK_LIST_RENDER_JSON|GNSDK_LIST_RENDER_V2;
	else
		render_format = GNSDK_LIST_RENDER_JSON;

	if (!bIndented)
		render_format |= GNSDK_LIST_RENDER_NOINDENT;

	error = gnsdk_manager_list_render(native(), level, render_format|GNSDK_LIST_RENDER_SINGLE_LEVEL, &renderedList);
	if (error) { throw GnError(); }

	return GnString::manage(renderedList);
}

/*-----------------------------------------------------------------------------
 *  Type
 */
GnListType
GnList::Type() throw (GnError)
{
	gnsdk_cstr_t  value = GNSDK_NULL;
	gnsdk_error_t error = gnsdk_manager_list_get_type(native(), &value);
	if (error) { throw GnError(); }
	return _convertListTypeCCpp(value);
}


/*-----------------------------------------------------------------------------
 *  Descriptor
 */
GnDescriptor
GnList::Descriptor() throw (GnError)
{
	gnsdk_cstr_t  value = GNSDK_NULL;
	gnsdk_error_t error = gnsdk_manager_list_get_descriptor(native(), &value);
	if (error) { throw GnError(); }
	return gnconvert::gn_descriptor_to_enum(value);
}


/*-----------------------------------------------------------------------------
 *  Region
 */
GnRegion
GnList::Region() throw (GnError)
{
	gnsdk_cstr_t  value = GNSDK_NULL;
	gnsdk_error_t error = gnsdk_manager_list_get_region(native(), &value);
	if (error) { throw GnError(); }
	return gnconvert::gn_region_to_enum(value);

}


/*-----------------------------------------------------------------------------
 *  Language
 */
GnLanguage
GnList::Language() throw (GnError)
{
	gnsdk_cstr_t  value = GNSDK_NULL;
	gnsdk_error_t error = gnsdk_manager_list_get_language(native(), &value);
	if (error) { throw GnError(); }
	return gnconvert::gn_language_to_enum(value);
}


/*-----------------------------------------------------------------------------
 *  Revision
 */
gnsdk_cstr_t
GnList::Revision() throw (GnError)
{
	gnsdk_error_t error;
	gnsdk_cstr_t  value = GNSDK_NULL;

	error = gnsdk_manager_list_get_revision(native(), &value);
	if (error) { throw GnError(); }

	return value;
}


/*-----------------------------------------------------------------------------
 *  LevelCount
 */
gnsdk_uint32_t
GnList::LevelCount() throw (GnError)
{
	gnsdk_error_t  error;
	gnsdk_uint32_t level_count = 0;

	error = gnsdk_manager_list_get_level_count(native(), &level_count);
	if (error) { throw GnError(); }

	return level_count;
}


/*-----------------------------------------------------------------------------
 *  ElementById
 */
GnListElement
GnList::ElementById(gnsdk_uint32_t itemId) throw (GnError)
{
	gnsdk_list_element_handle_t element_handle = GNSDK_NULL;

	gnsdk_error_t error = gnsdk_manager_list_get_element_by_id(native(), itemId, &element_handle);
	if (GNSDKERR_SEVERE(error)) { throw GnError(); }

	return GnListElement(element_handle);
}


/*-----------------------------------------------------------------------------
 *  ElementByRange
 */
GnListElement
GnList::ElementByRange(gnsdk_uint32_t range) throw (GnError)
{
	gnsdk_list_element_handle_t element_handle = GNSDK_NULL;

	gnsdk_error_t error = gnsdk_manager_list_get_element_by_range(native(), range, &element_handle);
	if (GNSDKERR_SEVERE(error)) { throw GnError(); }

	return GnListElement(element_handle);
}


/*-----------------------------------------------------------------------------
 *  ElementByString
 */
GnListElement
GnList::ElementByString(gnsdk_cstr_t strEquality) throw (GnError)
{
	gnsdk_list_element_handle_t element_handle = GNSDK_NULL;
	gnsdk_error_t               error          = GNSDK_NULL;

	error = gnsdk_manager_list_get_element_by_string(native(), strEquality, &element_handle);
	if (GNSDKERR_SEVERE(error)) { throw GnError(); }

	return GnListElement(element_handle);
}


/*-----------------------------------------------------------------------------
 *  ElementByGnDataObject
 */
GnListElement
GnList::ElementByGnDataObject(const GnDataObject& dataObject, gnsdk_uint32_t ordinal, gnsdk_uint32_t level) throw (GnError)
{
	gnsdk_list_element_handle_t element_handle = GNSDK_NULL;

	gnsdk_error_t error = gnsdk_manager_list_get_element_by_gdo(native(), dataObject.native(), ordinal, level, &element_handle);
	if (GNSDKERR_SEVERE(error)) { throw GnError(); }

	return GnListElement(element_handle);
}


/*-----------------------------------------------------------------------------
 *  _list_status_callback
 */
void GNSDK_CALLBACK_API
_list_status_callback(void* callback_data, gnsdk_status_t status, gnsdk_uint32_t percent_complete, gnsdk_size_t bytes_total_sent, gnsdk_size_t bytes_total_received, gnsdk_bool_t* p_abort)
{
	IGnStatusEvents* pEventHandler = (IGnStatusEvents*)callback_data;

	if (pEventHandler)
	{
		gn_canceller canceller;

		pEventHandler->StatusEvent((GnStatus)status, percent_complete, bytes_total_sent, bytes_total_received, canceller);
		if (canceller.IsCancelled())
		{
			*p_abort = GNSDK_TRUE;
		}
	}
}

