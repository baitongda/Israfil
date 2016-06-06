TEMPLATE = app
TARGET = test-network

CONFIG += C++11 warn_off
CONFIG -= Qt
DESTDIR = $$BUILD_TREE/bin

SOURCES += \
    main.cpp
INCLUDEPATH += \
    ../../../IsrafilCore/IsrafilNetwork/include \
    ../../../IsrafilCore/IsrafilPrefix \
    ../../../IsrafilCore/ext/curlcpp/include

LIBS += -L$$BUILD_TREE/bin -lcurl -lcurlcpp -lIsrafilNetwork -lIsrafilBase
