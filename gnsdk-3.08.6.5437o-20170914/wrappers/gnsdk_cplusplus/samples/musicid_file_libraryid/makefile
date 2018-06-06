#
# Makefile:
# gnsdk_musicid sample app
#

sdkdepends = musicid_file lookup_local storage_sqlite dsp manager

ifeq ($(filter static, $(MAKECMDGOALS)), static)
	extra_libs = ../../xtralibs/ipp
endif

include ../sample_vars.mk
