LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES += main.cpp \
									 fftool.cpp

LOCAL_C_INCLUDES += \
    $(TOP)/frameworks/av/media/libstagefright/codecs/libffmpeg/ffmpeg/
    
LOCAL_SHARED_LIBRARIES += \
    libavformat libavcodec libavutil
    
LOCAL_CFLAGS += -DBOARD_USES_FFMPEG
LOCAL_CFLAGS += -D__STDC_CONSTANT_MACROS
    
LOCAL_MODULE := FFTOOL

LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
