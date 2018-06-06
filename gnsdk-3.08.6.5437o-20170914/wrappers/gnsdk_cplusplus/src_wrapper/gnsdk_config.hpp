/** Public header file for Gracenote SDK C++ Wrapper
 * Author:
 *   Copyright (c) 2000-2015 Gracenote, Inc.
 *
 *   This software may not be used in any way or distributed without
 *   permission. All rights reserved.
 *
 *   Some code herein may be covered by US and international patents.
 */

#ifndef _GNSDK_CONFIG_HPP_
#define _GNSDK_CONFIG_HPP_

#ifndef __cplusplus
#error "C++ compiler required"
#endif

#include "gnsdk_base.hpp"

/**
 * Provides functionality necessary to configure lookup database and etc.
 */
namespace gracenote
{
	class GnConfig : public GnObject<gnsdk_config_handle_t>
	{
	public:
		GNWRAPPER_ANNOTATE

		GnConfig() throw (GnError);
		GnConfig(gnsdk_cstr_t config) throw (GnError);

		void
		Set(gnsdk_cstr_t custom, gnsdk_cstr_t value) throw (GnError);

		void
		Set(GnConfigOptionAccess access) throw (GnError);

		void
		Set(GnConfigOptionEnable enable, bool value) throw (GnError);

		void
		Set(GnConfigOptionLocation location, gnsdk_cstr_t value) throw (GnError);

	private:
		DISALLOW_COPY_AND_ASSIGN(GnConfig);
	};


}

#endif // _GNSDK_CONFIG_HPP_

