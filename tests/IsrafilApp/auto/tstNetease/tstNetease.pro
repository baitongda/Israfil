#-------------------------------------------------
#
# Project created by QtCreator 2016-05-14T21:23:38
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_tstneteasetest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
israfilAddLibrary(IsrafilCore)

SOURCES += tst_tstneteasetest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
