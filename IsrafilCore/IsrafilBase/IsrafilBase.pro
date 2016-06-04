TEMPLATE = lib
TARGET = IsrafilBase

CONFIG += C++11 warn_off
CONFIG -= Qt
DESTDIR = $$BUILD_TREE/bin

INCLUDEPATH += \
    include \
    $$SOURCE_TREE/IsrafilCore/IsrafilPrefix \
    $$SOURCE_TREE/IsrafilCore/ext/rapidjson/include

SOURCES += \
    source/IsrafilBase.cpp \
    source/utils.cpp \
    source/songbase.cpp

HEADERS += \
    include/IsrafilBase/IsrafilBase.h \
    include/IsrafilBase/songbase.h \
    include/IsrafilBase/strfmt.h \
    include/IsrafilBase/utils.h

