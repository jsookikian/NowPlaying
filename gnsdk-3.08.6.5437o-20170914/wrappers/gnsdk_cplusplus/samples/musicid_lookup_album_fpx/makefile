#
# Makefile:
# gnsdk_musicid sample app
#

sdkdepends = dsp musicid lookup_local storage_sqlite manager

ifeq ($(filter static, $(MAKECMDGOALS)), static)
	extra_libs = ../../xtralibs/ipp
endif

include ../sample_vars.mk
