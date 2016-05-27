TEMPLATE = lib
TARGET = IsrafilCore

CONFIG += C++11 warn_off
CONFIG -= Qt
DESTDIR = $$BUILD_TREE/bin

INCLUDEPATH += \
    include \
    ../IsrafilPrefix

SOURCES += \
    source/Fibonacci.cpp

HEADERS += \
    include/IsrafilCore/Fibonacci.h

