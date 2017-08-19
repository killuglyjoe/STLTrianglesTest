QT += core
QT -= gui

CONFIG += c++11

TARGET = TrianglesTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    $$PWD/stlroutines/stlfilereader.cpp \
    $$PWD/utils/comandlineparser.cpp \
    $$PWD/stlroutines/stlfilewriter.cpp \
    $$PWD/stlroutines/vertex.cpp \
    stlroutines/triangle.cpp

HEADERS += \
    $$PWD/stlroutines/stlfilereader.h \
    $$PWD/utils/comandlineparser.h \
    $$PWD/stlroutines/stlfilewriter.h \
    $$PWD/stlroutines/stlglobals.h \
    $$PWD/stlroutines/vertex.h \
    stlroutines/triangle.h
