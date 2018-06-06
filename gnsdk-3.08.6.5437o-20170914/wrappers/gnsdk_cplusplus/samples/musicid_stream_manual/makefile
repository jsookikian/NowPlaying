#
# Makefile:
# gnsdk_musicid_stream 'manual mode' sample app
#

sdkdepends = musicid_stream lookup_local lookup_localstream storage_sqlite dsp manager 

ifeq ($(filter static, $(MAKECMDGOALS)), static)
	extra_libs = ../../xtralibs/ipp
endif

include ../sample_vars.mk

