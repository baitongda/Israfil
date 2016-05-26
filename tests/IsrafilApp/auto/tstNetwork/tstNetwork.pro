#-------------------------------------------------
#
# Project created by QtCreator 2016-03-28T11:06:42
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_tstnetworktest
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app
israfilAddLibrary(IsrafilCore)

SOURCES += tst_tstnetworktest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
