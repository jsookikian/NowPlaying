/** Public header file for Gracenote SDK C++ Wrapper
 * Author:
 *   Copyright (c) 2000-2015 Gracenote, Inc.
 *
 *   This software may not be used in any way or distributed without
 *   permission. All rights reserved.
 *
 *   Some code herein may be covered by US and international patents.
 */

#ifndef _GNSDK_CONVERT_HPP_
#define _GNSDK_CONVERT_HPP_

#ifndef __cplusplus
#error "C++ compiler required"
#endif

#include "gnsdk_base.hpp"

namespace gracenote
{
	/**
	 * Various methods for converting to and from native values
	 * For internal use.
	 */
	class gnconvert
	{
	public:
		/**
		 * Convert native language to enumerated language
		 * @param c_region  [in] Native language
		 * @return Enumerated language
		 */
		static GnLanguage
		gn_language_to_enum(gnsdk_cstr_t c_language)
		{
			GnLanguage language = kLanguageEnglish;

			if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_ENGLISH) == 0 )
			{
				language = kLanguageEnglish;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_CHINESE_SIMP) == 0 )
			{
				language = kLanguageChineseSimplified;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_CHINESE_TRAD) == 0 )
			{
				language = kLanguageChineseTraditional;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_DUTCH) == 0 )
			{
				language = kLanguageDutch;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_FRENCH) == 0 )
			{
				language = kLanguageFrench;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_GERMAN) == 0 )
			{
				language = kLanguageGerman;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_ITALIAN) == 0 )
			{
				language = kLanguageItalian;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_JAPANESE) == 0 )
			{
				language = kLanguageJapanese;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_KOREAN) == 0 )
			{
				language = kLanguageKorean;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_PORTUGUESE) == 0 )
			{
				language = kLanguagePortuguese;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_RUSSIAN) == 0 )
			{
				language = kLanguageRussian;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_SPANISH) == 0 )
			{
				language = kLanguageSpanish;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_SWEDISH) == 0 )
			{
				language = kLanguageSwedish;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_THAI) == 0 )
			{
				language = kLanguageThai;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_TURKISH) == 0 )
			{
				language = kLanguageTurkish;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_POLISH) == 0 )
			{
				language = kLanguagePolish;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_FARSI) == 0 )
			{
				language = kLanguageFarsi;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_VIETNAMESE) == 0 )
			{
				language = kLanguageVietnamese;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_HUNGARIAN) == 0 )
			{
				language = kLanguageHungarian;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_CZECH) == 0 )
			{
				language = kLanguageCzech;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_SLOVAK) == 0 )
			{
				language = kLanguageSlovak;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_ROMANIAN) == 0 )
			{
				language = kLanguageRomanian;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_GREEK) == 0 )
			{
				language = kLanguageGreek;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_ARABIC) == 0 )
			{
				language = kLanguageArabic;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_INDONESIAN) == 0 )
			{
				language = kLanguageIndonesian;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_FINNISH) == 0 )
			{
				language = kLanguageFinnish;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_NORWEGIAN) == 0 )
			{
				language = kLanguageNorwegian;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_CROATIAN) == 0 )
			{
				language = kLanguageCroatian;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_BULGARIAN) == 0 )
			{
				language = kLanguageBulgarian;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_SERBIAN) == 0 )
			{
				language = kLanguageSerbian;
			}
			else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_DANISH) == 0 )
			{
				language = kLanguageDanish;
			}
            else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_LITHUANIAN) == 0 )
            {
                language = kLanguageLithuanian;
            }
            else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_LATVIAN) == 0 )
            {
                language = kLanguageLatvian;
            }
            else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_ESTONIAN) == 0 )
            {
                language = kLanguageEstonian;
            }
            else if ( gnstd::gn_strcmp(c_language, GNSDK_LANG_UKRAINIAN) == 0 )
            {
                language = kLanguageUkrainian;
            }

			return language;
		}

		/**
		 * Convert enumerated language to native language
		 * @param lanaguage	[in] Enumerated langauge
		 * @return Native language value
		 */
		static gnsdk_cstr_t
		gn_language_to_string(GnLanguage language)
		{
			switch ( language )
			{
			case kLanguageArabic:
				return GNSDK_LANG_ARABIC;

			case kLanguageBulgarian:
				return GNSDK_LANG_BULGARIAN;

			case kLanguageChineseSimplified:
				return GNSDK_LANG_CHINESE_SIMP;

			case kLanguageChineseTraditional:
				return GNSDK_LANG_CHINESE_TRAD;

			case kLanguageCroatian:
				return GNSDK_LANG_CROATIAN;

			case kLanguageCzech:
				return GNSDK_LANG_CZECH;

			case kLanguageDanish:
				return GNSDK_LANG_DANISH;

			case kLanguageDutch:
				return GNSDK_LANG_DUTCH;

			case kLanguageEnglish:
				return GNSDK_LANG_ENGLISH;

			case kLanguageFarsi:
				return GNSDK_LANG_FARSI;

			case kLanguageFinnish:
				return GNSDK_LANG_FINNISH;

			case kLanguageFrench:
				return GNSDK_LANG_FRENCH;

			case kLanguageGerman:
				return GNSDK_LANG_GERMAN;

			case kLanguageGreek:
				return GNSDK_LANG_GREEK;

			case kLanguageHungarian:
				return GNSDK_LANG_HUNGARIAN;

			case kLanguageIndonesian:
				return GNSDK_LANG_INDONESIAN;

			case kLanguageItalian:
				return GNSDK_LANG_ITALIAN;

			case kLanguageJapanese:
				return GNSDK_LANG_JAPANESE;

			case kLanguageKorean:
				return GNSDK_LANG_KOREAN;

			case kLanguageNorwegian:
				return GNSDK_LANG_NORWEGIAN;

			case kLanguagePolish:
				return GNSDK_LANG_POLISH;

			case kLanguagePortuguese:
				return GNSDK_LANG_PORTUGUESE;

			case kLanguageRomanian:
				return GNSDK_LANG_ROMANIAN;

			case kLanguageRussian:
				return GNSDK_LANG_RUSSIAN;

			case kLanguageSerbian:
				return GNSDK_LANG_SERBIAN;

			case kLanguageSlovak:
				return GNSDK_LANG_SLOVAK;

			case kLanguageSpanish:
				return GNSDK_LANG_SPANISH;

			case kLanguageSwedish:
				return GNSDK_LANG_SWEDISH;

			case kLanguageThai:
				return GNSDK_LANG_THAI;

			case kLanguageTurkish:
				return GNSDK_LANG_TURKISH;

			case kLanguageVietnamese:
				return GNSDK_LANG_VIETNAMESE;

            case kLanguageLithuanian:
                return GNSDK_LANG_LITHUANIAN;

            case kLanguageLatvian:
                return GNSDK_LANG_LATVIAN;

            case kLanguageEstonian:
                return GNSDK_LANG_ESTONIAN;
                
            case kLanguageUkrainian:
                return GNSDK_LANG_UKRAINIAN;

			case kLanguageInvalid:
				break;
			}

			return GNSDK_NULL;
		}

		/**
		 * Convert native region to enumerated region
		 * @param c_region  [in] Native region
		 * @return Enumerated region
		 */
		static GnRegion
		gn_region_to_enum(gnsdk_cstr_t c_region)
		{
			GnRegion region = kRegionDefault;

			if ( gnstd::gn_strcmp(c_region, GNSDK_REGION_DEFAULT) == 0 )
			{
				region = kRegionDefault;
			}
			else if ( gnstd::gn_strcmp(c_region, GNSDK_REGION_GLOBAL) == 0 )
			{
				region = kRegionGlobal;
			}
			else if ( gnstd::gn_strcmp(c_region, GNSDK_REGION_US) == 0 )
			{
				region = kRegionUS;
			}
			else if ( gnstd::gn_strcmp(c_region, GNSDK_REGION_JAPAN) == 0 )
			{
				region = kRegionJapan;
			}
			else if ( gnstd::gn_strcmp(c_region, GNSDK_REGION_CHINA) == 0 )
			{
				region = kRegionChina;
			}
			else if ( gnstd::gn_strcmp(c_region, GNSDK_REGION_TAIWAN) == 0 )
			{
				region = kRegionTaiwan;
			}
			else if ( gnstd::gn_strcmp(c_region, GNSDK_REGION_KOREA) == 0 )
			{
				region = kRegionKorea;
			}
			else if ( gnstd::gn_strcmp(c_region, GNSDK_REGION_EUROPE) == 0 )
			{
				region = kRegionEurope;
			}
			else if ( gnstd::gn_strcmp(c_region, GNSDK_REGION_NORTH_AMERICA) == 0 )
			{
				region = kRegionNorthAmerica;
			}
			else if ( gnstd::gn_strcmp(c_region, GNSDK_REGION_LATIN_AMERICA) == 0 )
			{
				region = kRegionLatinAmerica;
			}
			else if ( gnstd::gn_strcmp(c_region, GNSDK_REGION_INDIA) == 0 )
			{
				region = kRegionIndia;
			}

			return region;
		}

		/**
		 * Convert enumerated region to native region
		 * @param lanaguage	[in] Enumerated region
		 * @return Native region value
		 */
		static gnsdk_cstr_t
		gn_region_to_string(GnRegion region)
		{
			switch ( region )
			{
			case kRegionDefault:
				return GNSDK_REGION_DEFAULT;

			case kRegionGlobal:
				return GNSDK_REGION_GLOBAL;

			case kRegionNorthAmerica:
			case kRegionUS:
				return GNSDK_REGION_US;

			case kRegionJapan:
				return GNSDK_REGION_JAPAN;

			case kRegionChina:
				return GNSDK_REGION_CHINA;

			case kRegionTaiwan:
				return GNSDK_REGION_TAIWAN;

			case kRegionKorea:
				return GNSDK_REGION_KOREA;

			case kRegionEurope:
				return GNSDK_REGION_EUROPE;

			case kRegionLatinAmerica:
				return GNSDK_REGION_LATIN_AMERICA;

			case kRegionIndia:
				return GNSDK_REGION_INDIA;
			}

			return GNSDK_REGION_DEFAULT;
		}

		/**
		 * Convert native descriptor to enumerated descriptor
		 * @param c_region  [in] Native descriptor
		 * @return Enumerated descriptor
		 */
		static GnDescriptor
		gn_descriptor_to_enum(gnsdk_cstr_t c_descriptor)
		{
			GnDescriptor desc = kDescriptorDefault;

			if ( gnstd::gn_strcmp(c_descriptor, GNSDK_DESCRIPTOR_DEFAULT) == 0 )
			{
				desc = kDescriptorDefault;
			}
			else if ( gnstd::gn_strcmp(c_descriptor, GNSDK_DESCRIPTOR_SIMPLIFIED) == 0 )
			{
				desc = kDescriptorSimplified;
			}
			else if ( gnstd::gn_strcmp(c_descriptor, GNSDK_DESCRIPTOR_DETAILED) == 0 )
			{
				desc = kDescriptorDetailed;
			}

			return desc;
		}

		/**
		 * Convert enumerated descriptor to native descriptor
		 * @param lanaguage	[in] Enumerated descriptor
		 * @return Native descriptor value
		 */
		static gnsdk_cstr_t
		gn_descriptor_to_string(GnDescriptor descriptor)
		{
			switch ( descriptor )
			{
			case kDescriptorDefault:
				return GNSDK_DESCRIPTOR_DEFAULT;

			case kDescriptorSimplified:
				return GNSDK_DESCRIPTOR_SIMPLIFIED;

			case kDescriptorDetailed:
				return GNSDK_DESCRIPTOR_DETAILED;
			}
			return GNSDK_DESCRIPTOR_DEFAULT;
		}

		/**
		 * Convert enumerated content type to native content type
		 * @param lanaguage	[in] Enumerated content type
		 * @return Native content type value
		 */
		static gnsdk_cstr_t
		gn_content_type_to_string(GnContentType contentType)
		{
			gnsdk_cstr_t key = GNSDK_NULL;

			switch (contentType)
			{
			case kContentTypeImageCover:
				key = GNSDK_GDO_CHILD_CONTENT_IMAGECOVER;
				break;

			case kContentTypeImageArtist:
				key = GNSDK_GDO_CHILD_CONTENT_IMAGEARTIST;
				break;

			case kContentTypeImageVideo:
				key = GNSDK_GDO_CHILD_CONTENT_IMAGEVIDEO;
				break;

			case kContentTypeImageLogo:
				key = GNSDK_GDO_CHILD_CONTENT_IMAGELOGO;
				break;

			case kContentTypeBiography:
				key = GNSDK_GDO_CHILD_CONTENT_BIOGRAPHY;
				break;

			case kContentTypeReview:
				key = GNSDK_GDO_CHILD_CONTENT_REVIEW;
				break;

			case kContentTypeNews:
				key = GNSDK_CONTENT_TYPE_TEXT_NEWS;
				break;

			case kContentTypeArtistNews:
				key = GNSDK_CONTENT_TYPE_TEXT_ARTISTNEWS;
				break;

			case kContentTypeListenerComments:
				key = GNSDK_CONTENT_TYPE_TEXT_LISTENERCOMMENTS;
				break;

			case kContentTypeReleaseComments:
				key = GNSDK_CONTENT_TYPE_TEXT_RELEASECOMMENTS;
				break;

			default:
				break;
			}

			return key;
		}

		/*-----------------------------------------------------------------------------
		 *  gn_image_size_to_enum
		 */
		static GnImageSize
		gn_image_size_to_enum(gnsdk_cstr_t image_size)
		{
			GnImageSize value = kImageSizeUnknown;
			if (image_size)
			{
				if (	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_75) == 0)
				    ||	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_THUMBNAIL) == 0)
				    ||	(gnstd::gn_strcmp(image_size, GNSDK_VALUE_ASSET_SIZE_THUMBNAIL) == 0))
					value = kImageSizeThumbnail;

				else 
				if (	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_110) == 0)
					||	(gnstd::gn_strcmp(image_size, GNSDK_VALUE_ASSET_SIZE_110) == 0))
					value = kImageSize110;

				else
				if (	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_170) == 0)
				    ||	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_SMALL) == 0)
				    ||	(gnstd::gn_strcmp(image_size, GNSDK_VALUE_ASSET_SIZE_SMALL) == 0))
					value = kImageSizeSmall;

				else 
				if (	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_220) == 0)
				    ||	(gnstd::gn_strcmp(image_size, GNSDK_VALUE_ASSET_SIZE_220) == 0))
					value = kImageSize220;

				else 
				if (	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_300) == 0)
					||	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_300X300) == 0)
				    ||	(gnstd::gn_strcmp(image_size, GNSDK_VALUE_ASSET_SIZE_300) == 0))
					value = kImageSize300;

				else 
				if (	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_450) == 0) 
					||	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_MEDIUM) == 0)
					||	(gnstd::gn_strcmp(image_size, GNSDK_VALUE_ASSET_SIZE_MEDIUM) == 0))
					value = kImageSizeMedium;

				else 
				if (	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_720) == 0) 
					||	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_LARGE) == 0)
					||	(gnstd::gn_strcmp(image_size, GNSDK_VALUE_ASSET_SIZE_LARGE) == 0))
					value = kImageSizeMedium;

				else 
				if (	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_1080) == 0) 
					||	(gnstd::gn_strcmp(image_size, GNSDK_CONTENT_DATA_SIZE_VALUE_XLARGE) == 0)
					||	(gnstd::gn_strcmp(image_size, GNSDK_VALUE_ASSET_SIZE_XLARGE) == 0))
					value = kImageSizeMedium;
			}
			return value;
		}

		/*-----------------------------------------------------------------------------
		 *  gn_image_size_to_string
		 */
		static gnsdk_cstr_t
		gn_image_size_to_string(GnImageSize image_size)
		{
			switch (image_size)
			{
			//case gracenote::kImageSize75:
			case gracenote::kImageSizeThumbnail:
				return GNSDK_VALUE_ASSET_SIZE_THUMBNAIL;

			case gracenote::kImageSize110:
				return GNSDK_VALUE_ASSET_SIZE_110;

			//case gracenote::kImageSize170:
			case gracenote::kImageSizeSmall:
				return GNSDK_VALUE_ASSET_SIZE_SMALL;

			case gracenote::kImageSize220:
				return GNSDK_VALUE_ASSET_SIZE_220;

			case gracenote::kImageSize300:
				return GNSDK_VALUE_ASSET_SIZE_300;

			//case gracenote::kImageSize450:
			case gracenote::kImageSizeMedium:
				return GNSDK_VALUE_ASSET_SIZE_MEDIUM;

			//case gracenote::kImageSize720:
			case gracenote::kImageSizeLarge:
				return GNSDK_VALUE_ASSET_SIZE_LARGE;

			//case gracenote::kImageSize1080:
			case gracenote::kImageSizeXLarge:
				return GNSDK_VALUE_ASSET_SIZE_XLARGE;

			case gracenote::kImageSizeUnknown:
			default:
				return GNSDK_NULL;
			}
		}


		/*-----------------------------------------------------------------------------
		 *  gn_lookup_mode_to_enum
		 */
		static GnLookupMode
		gn_lookup_mode_to_enum(gnsdk_cstr_t lookup_mode) throw (GnError)
		{
			if (gnstd::gn_strcmp(lookup_mode, GNSDK_LOOKUP_MODE_LOCAL) == 0)
				return kLookupModeLocal;

			if (gnstd::gn_strcmp(lookup_mode, GNSDK_LOOKUP_MODE_ONLINE) == 0)
				return kLookupModeOnline;

			if (gnstd::gn_strcmp(lookup_mode, GNSDK_LOOKUP_MODE_ONLINE_NOCACHE) == 0)
				return kLookupModeOnlineNoCache;

			if (gnstd::gn_strcmp(lookup_mode, GNSDK_LOOKUP_MODE_ONLINE_NOCACHEREAD) == 0)
				return kLookupModeOnlineNoCacheRead;

			if (gnstd::gn_strcmp(lookup_mode, GNSDK_LOOKUP_MODE_ONLINE_CACHEONLY) == 0)
				return kLookupModeOnlineCacheOnly;

			return kLookupModeInvalid;
		}

		/*-----------------------------------------------------------------------------
		 *  gn_lookup_mode_to_string
		 */
		static gnsdk_cstr_t
		gn_lookup_mode_to_string(GnLookupMode lookupMode) throw (GnError)
		{
			switch (lookupMode)
			{
			case kLookupModeLocal:
				return GNSDK_LOOKUP_MODE_LOCAL;

			case kLookupModeOnline:
				return GNSDK_LOOKUP_MODE_ONLINE;

			case kLookupModeOnlineNoCache:
				return GNSDK_LOOKUP_MODE_ONLINE_NOCACHE;

			case kLookupModeOnlineNoCacheRead:
				return GNSDK_LOOKUP_MODE_ONLINE_NOCACHEREAD;

			case kLookupModeOnlineCacheOnly:
				return GNSDK_LOOKUP_MODE_ONLINE_CACHEONLY;

			case kLookupModeInvalid:
				return GNSDK_NULL;
			}

			return GNSDK_NULL;
		}

	};


}

#endif // _GNSDK_CONVERT_HPP_

