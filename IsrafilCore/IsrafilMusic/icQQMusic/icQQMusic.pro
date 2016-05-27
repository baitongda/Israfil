TEMPLATE = lib
TARGET = icQQMusic

CONFIG += C++11 warn_off
CONFIG -= Qt
DESTDIR = $$BUILD_TREE/bin

HEADERS += \
    qqmusic.h \
    base.h

SOURCES += \
    qqmusic.cpp

INCLUDEPATH += \
    ../../IsrafilPrefix \
    ../../IsrafilNetwork/include \
    ../../ext/curlcpp/include

LIBS += -L$$BUILD_TREE/bin -lcurl -lcurlcpp -lIsrafilNetwork
