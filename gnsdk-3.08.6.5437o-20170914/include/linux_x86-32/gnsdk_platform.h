/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

/*
 * gnsdk_platform.h - Contains platform-specific definitions.
 * USE THIS FILE TO OVERRIDE THE DEFINITIONS IN gnsdk_defines.h
 */

 #ifndef _GNSDK_DEFINES_H_
 #error gnsdk_platforms.h should not be included directly. Use #include "gnsdk_defines.h"
 #endif

/*
 * Linux Flavor
 */

#ifndef _GNSDK_PLATFORM_H_
#define _GNSDK_PLATFORM_H_


#define GNSDK_LINUX
#define GNSDK_LINUX_X86
#define GNSDK_LINUX_X86_32
#define GNSDK_PLATFORM_STR		"Linux (x86)"


#define GNSDK_API
#define	GNSDK_CALLBACK_API
#if __GNUC__ >= 4
	#define GNSDK_EXPORTED			GNSDK_EXTERN_C __attribute__ ((visibility ("default")))
#else
	#define GNSDK_EXPORTED
#endif
#ifdef __GNUC__
	#define GNSDK_DEPRECATED		GNSDK_EXTERN_C __attribute__ ((deprecated, visibility ("default")))
#else
	#pragma message("WARNING: Need to implement DEPRECATED for this compiler")
	#define GNSDK_DEPRECATED
#endif

/* our own non-aborting assert by default */
#if defined (_DEBUG) && !defined(NDEBUG)
  #ifdef GNSDK_ASSERT_ABORT
    #include <assert.h>
    #define GNSDK_ASSERT(e)  assert(e)
  #else
    #include <signal.h>
    int  printf(const char * __restrict, ...); /* pre-decl */

    #define gnsdk_debug_break()      (raise(SIGTRAP))
    #define _gnsdk_assert(e, file, line) ((void)printf ("\033[1;31m%s:%u: failed assertion `%s'\033[0m\n", file, line, e), gnsdk_debug_break())
    #define GNSDK_ASSERT(e)        ((void) ((e) ? (void)0 : _gnsdk_assert (#e, __FILE__, __LINE__)))
  #endif
#else
  #include <assert.h>
  #define GNSDK_ASSERT(exp)        assert(exp)
#endif

#include <stddef.h> /* for size_t */

#define GNSDK_INTPTR_T
typedef long int 			gnsdk_intptr_t;

#define GNSDK_UINTPTR_T
typedef unsigned long int 	gnsdk_uintptr_t;

#define GNSDK_SIZE_T
typedef unsigned int        gnsdk_size_t;

/* byte swapping from native to LE/BE */
#define GNSDK_BSWAP32_TO_LE(x)				(x)
#define GNSDK_BSWAP16_TO_LE(x)				(x)
#define GNSDK_BSWAP32_TO_BE(x)				GNSDK_BSWAP_32(x)
#define GNSDK_BSWAP16_TO_BE(x)				GNSDK_BSWAP_16(x)

#define GNSDK_BSWAP32_FROM_LE(x)			(x)
#define GNSDK_BSWAP16_FROM_LE(x)			(x)
#define GNSDK_BSWAP32_FROM_BE(x)			GNSDK_BSWAP_32(x)
#define GNSDK_BSWAP16_FROM_BE(x)			GNSDK_BSWAP_16(x)


#endif /* _GNSDK_PLATFORM_H_ */