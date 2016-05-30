TEMPLATE = app
TARGET = IsrafilApp

QT += qml quick
CONFIG += c++11
DESTDIR = $$BUILD_TREE/bin

SOURCES += main.cpp
RESOURCES +=

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH = C:/Users/etasr/Code/Qt/Israfil-Qt/src/quick

#IsrafilAddLibrary(IsrafilCore)
#include(../shared/shared.pri)
include(deployment.pri)

#osx {
    # TODO
#    plugins.files += $$BUILD_TREE/plugins/libexampleplugin.$$QMAKE_EXTENSION_SHLIB
#    plugins.path = Contents/PlugIns
#    QMAKE_BUNDLE_DATA += plugins
#}
