TEMPLATE = lib
TARGET = IsrafilBase

CONFIG += C++11 warn_off
CONFIG -= Qt
DESTDIR = $$BUILD_TREE/bin

INCLUDEPATH += \
    include \
    ../IsrafilPrefix

SOURCES += \
    source/IsrafilBase.cpp

HEADERS += \
    include/IsrafilBase/IsrafilBase.h

