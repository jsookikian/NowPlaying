group_name = sample
appname = sample

ifneq "$(wildcard ../../../../builds )" ""
    # Packaged samples
    build_dir = ../../../../builds
    install_dir = $(build_dir)
else ifneq "$(wildcard ../../../../../builds )" ""
    # Dev samples
    build_dir = ../../../../../builds
    install_dir = $(build_dir)/../install/common
else
    $(info pwd = $(shell pwd))
    $(error Can't find builds dir, Where am I?)
endif

include $(build_dir)/platform_vars.mk

# C++ sources and Loader
extra_srcs += ../../src_wrapper ../../src_marshal ../../src_helpers

# Platform dependencies
ifeq ($(IMPLDIR),win)
	platformlibs += winmm.lib
else ifeq ($(IMPLDIR), mac)
	platformlibs += -framework AudioToolbox
endif
