TEMPLATE = lib
TARGET = curlcpp

CONFIG += C++11 warn_off
CONFIG -= Qt
DESTDIR = $$BUILD_TREE/bin

INCLUDEPATH += include
SOURCES += \
    src/cookie_date.cpp \
    src/cookie_datetime.cpp \
    src/cookie_time.cpp \
    src/cookie.cpp \
    src/curl_cookie.cpp \
    src/curl_easy.cpp \
    src/curl_exception.cpp \
    src/curl_form.cpp \
    src/curl_header.cpp \
    src/curl_info.cpp \
    src/curl_multi.cpp \
    src/curl_share.cpp
HEADERS += \
    include/cookie_date.h \
    include/cookie_datetime.h \
    include/cookie_time.h \
    include/cookie.h \
    include/curl_config.h \
    include/curl_cookie.h \
    include/curl_easy_info.h \
    include/curl_easy.h \
    include/curl_exception.h \
    include/curl_form.h \
    include/curl_global.h \
    include/curl_header.h \
    include/curl_info.h \
    include/curl_interface.h \
    include/curl_ios.h \
    include/curl_multi.h \
    include/curl_option.h \
    include/curl_pair.h \
    include/curl_receiver.h \
    include/curl_sender.h \
    include/curl_share.h \
    include/curl_utility.h

LIBS += -lcurl
