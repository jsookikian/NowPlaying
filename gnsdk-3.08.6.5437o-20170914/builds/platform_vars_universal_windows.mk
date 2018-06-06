#
# GNSDK Build System: Platform Variable Setup
#

#
# TARGET PLATFORM: Universal Windows 32/64-bit
#


ifneq ($(GNSDK_BUILD_PLATFORM),windows)
$(error Building MSWindows target is currently only supported on Windows clients)
endif

ifeq ($(SHARED_LIB_EXT),)
SHARED_LIB_EXT = dll
endif

STATIC_LIB_EXT = lib
SHARED_LINK_EXT = $(STATIC_LIB_EXT)
STATIC_LINK_EXT = $(STATIC_LIB_EXT)

APP_EXE_PATTERN := %.exe
SHARED_LIB_PATTERN := group_library.$(SHARED_LIB_EXT)
STATIC_LIB_PATTERN := group_library.$(STATIC_LIB_EXT)
SHARED_LINK_PATTERN := group_library.$(STATIC_LIB_EXT)
STATIC_LINK_PATTERN := group_library.$(STATIC_LIB_EXT)

ifneq ($(library_name),)
	SHARED_LIB_TARGET = $(subst group,$(group_name),$(subst library,$(library_name),$(SHARED_LIB_PATTERN)))
	STATIC_LIB_TARGET = $(subst group,$(group_name),$(subst library,$(library_name),$(STATIC_LIB_PATTERN)))
	SHARED_LINK_TARGET = $(subst group,$(group_name),$(subst library,$(library_name),$(SHARED_LINK_PATTERN)))
	STATIC_LINK_TARGET = $(subst group,$(group_name),$(subst library,$(library_name),$(STATIC_LINK_PATTERN)))
else
	SHARED_LIB_TARGET = $(subst group_library,$(group_name),$(SHARED_LIB_PATTERN))
	STATIC_LIB_TARGET = $(subst group_library,$(group_name),$(STATIC_LIB_PATTERN))
	SHARED_LINK_TARGET = $(subst group_library,$(group_name),$(SHARED_LINK_PATTERN))
	STATIC_LINK_TARGET = $(subst group_library,$(group_name),$(STATIC_LINK_PATTERN))
endif

#
# Tool Chain variables
#

TOOLDIR=

# Compilation
CC=$(TOOLDIR)/cl.exe
CCPP=$(CC)
COUTFLAG=-Fo
CWARNERR=-WX
PDB_NAME=$(group_library_name)
CDEFS = -DUNICODE -D_UNICODE -D_CRT_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE -DWINAPI_FAMILY=WINAPI_FAMILY_APP

ifneq ($(filter thread time mmap process socket random crypt fs socket,$(library_name)),)
	CFLAGS_DEBUG=-Od -MDd -J -W4 -GS -GF -RTC1 -nologo -Z7 -ZW -TP -EHsc /fp:precise -Fd$(PDB_NAME) -D_DEBUG /AI"$(VCINSTALLDIR)\lib\store\references" /FU"platform.winmd"
	CFLAGS_RELEASE=-O2 -MD -J -W4 -GS -GF -Z7 -ZW -TP -EHsc /fp:precise -Fd$(PDB_NAME) -DNDEBUG /AI"$(VCINSTALLDIR)\lib\store\references" /FU"platform.winmd"
else
	CFLAGS_DEBUG=-Od -MDd -J -W4 -GS -GF -RTC1 -nologo -Z7 -EHsc /fp:precise -Fd$(PDB_NAME) -D_DEBUG /AI"$(VCINSTALLDIR)\lib\store\references" /FU"platform.winmd"
	CFLAGS_RELEASE=-O2 -MD -J -W4 -GS -GF -Z7 -EHsc /fp:precise -Fd$(PDB_NAME) -DNDEBUG /AI"$(VCINSTALLDIR)\lib\store\references" /FU"platform.winmd"
endif

# dynamic library building
ifdef NMCL
	ifdef no_nmcl
		LD=$(TOOLDIR)/link.exe
	else
		LD=nmlink.exe $(NMCL)
	endif
else
	LD=$(TOOLDIR)/link.exe
endif

LDOUTFLAG=-OUT:
LDFLAGS_DEBUG=-NOLOGO -DEBUG -DLL -DEF:$(group_name)_exports.def -INCREMENTAL:NO -OPT:REF -OPT:ICF -NXCOMPAT -NODEFAULTLIB:libcmtd.lib
LDFLAGS_RELEASE=-NOLOGO -DLL -DEF:$(group_name)_exports.def -INCREMENTAL:NO -OPT:REF -OPT:ICF -NXCOMPAT -NODEFAULTLIB:libcmt.lib
LDLIBS_PLATFORM=ws2_32.lib advapi32.lib iphlpapi.lib kernel32.lib
LDLIBS_PLATFORM+=/DYNAMICBASE "WindowsApp.lib" 

# static library building
LDS=$(TOOLDIR)/lib.exe
LDSOUTFLAG=-OUT:
LDSFLAGS_DEBUG=-NOLOGO
LDSFLAGS_RELEASE=-NOLOGO

# application linking
LINK=$(TOOLDIR)/link.exe
LINKOUTFLAG=-OUT:
LINKFLAGS_DEBUG=-NOLOGO -DEBUG /WINMD /INCREMENTAL -NODEFAULTLIB:libcmtd.lib
LINKFLAGS_RELEASE=-NOLOGO -RELEASE /WINMD  -NODEFAULTLIB:LIBCMT

# resource compiling
RC=rc.exe
RCOUTFLAG=-fo
RCFLAGS_DEBUG=-d_DEBUG
RCFLAGS_RELEASE=

# Java
JDK_DIR=
JAVAC=javac
JAR=jar

# CSharp
CSHARP_CC=csc.exe
CSHARP_OUTFLAG=-OUT:
CSHARP_FLAGS=/noconfig /nowarn:1701,1702 /nostdlib+ /errorreport:prompt /warn:4 /define:TRACE
CSHARP_REFERENCES=/r:mscorlib.dll /r:System.Core.dll /r:System.Data.DataSetExtensions.dll /r:System.Data.dll /r:System.dll /r:System.Xml.dll /r:System.Xml.Linq.dll

# Other Tools
AR=
STRIP=
CP=cp -fp
SED=sed
MV=mv -f

ifeq ($(ARCH),uwp)
	# detect 32/64-bit compiler (since arch is driven by compiler, not flags)
	ccver := $(shell cl.exe 2>&1)
	ifneq ($(findstring x86,$(ccver)),)
		IMPLDIR = uwp
		IMPLARCH = x86-32
		TOOLDIR := "$(shell cygpath -u $$VCINSTALLDIR)/bin"
		TOOLDIR := $(TOOLDIR:%/=%)
		ifneq ($(ARCH),)
			ifeq ($(filter i386 x86_32 x86-32 x86,$(ARCH)),)
				IMPLARCH = x86-32
			endif
		endif
	else ifneq ($(findstring x64,$(ccver)),)
		IMPLDIR = uwp
		IMPLARCH = x86-64
		TOOLDIR := "$(shell cygpath -u $$VCINSTALLDIR)/bin/amd64"
		TOOLDIR := $(TOOLDIR:%/=%)
		ifneq ($(ARCH),)
			ifeq ($(filter x86_64 x86-64 x64,$(ARCH)),)
				IMPLARCH = x86-64
			endif
		endif	
	else ifneq ($(findstring ARM,$(ccver)),)
		IMPLDIR = uwp
		IMPLARCH = arm-32
		TOOLDIR := "$(shell cygpath -u $$VCINSTALLDIR)/bin/x86_arm"
		TOOLDIR := $(TOOLDIR:%/=%)
		ifneq ($(ARCH),)
			ifeq ($(filter arm_32 arm-32 arm,$(ARCH)),)
				IMPLARCH = arm-32
			endif
		endif
	endif	
endif

ifeq ($(IMPLARCH),)
$(error ARCH="$(IMPLARCH)" is unsupported. Windows can't cross compile (use different vcvars.bat setting))
endif


ifeq ($(IMPLARCH),x86-32)
LDFLAGS_DEBUG+= -MACHINE:X86 
LDFLAGS_RELEASE+= -MACHINE:X86
LINKFLAGS_DEBUG+=/MACHINE:X86
LINKFLAGS_RELEASE+=/MACHINE:X86
endif

ifeq ($(IMPLARCH),x86-64)
LDFLAGS_DEBUG+= -MACHINE:X64 
LDFLAGS_RELEASE+= -MACHINE:X64
LINKFLAGS_DEBUG+=/MACHINE:X64
LINKFLAGS_RELEASE+=/MACHINE:X64
endif

ifeq ($(IMPLARCH), arm-32)
LDFLAGS_DEBUG+= -MACHINE:ARM 
LDFLAGS_RELEASE+= -MACHINE:ARM
LINKFLAGS_DEBUG+=/MACHINE:ARM
LINKFLAGS_RELEASE+=/MACHINE:ARM
LDLIBS_PLATFORM+="Kernel32.lib"
endif

# set compiler version (needed for Windows static lib linking)
ifneq ($(findstring Version 19,$(ccver)),)
	COMPILER_VER=vs14
else
	$(error unsupported compiler version - install windows10 and visual studio 2015)
endif

