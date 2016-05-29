TEMPLATE = lib
TARGET = IsrafilBase

CONFIG += C++11 warn_off
CONFIG -= Qt
DESTDIR = $$BUILD_TREE/bin

INCLUDEPATH += \
    include \
    ../IsrafilPrefix \
    ../ext/rapidjson/include

SOURCES += \
    source/IsrafilBase.cpp

HEADERS += \
    include/IsrafilBase/IsrafilBase.h \
    include/IsrafilBase/songbase.h

