QT += core
QT -= gui

CONFIG += c++11

TARGET = TrianglesTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

CONFIG(debug, debug|release) {
    DESTDIR     = $$PWD/bin
    MOC_DIR     = $$PWD/debug/build/moc
    OBJECTS_DIR = $$PWD/debug/build/obj
    UI_DIR      = $$PWD/debug/build/ui
    TARGET      = TrianglesTestD
}
CONFIG(release, debug|release) {
    DESTDIR     = $$PWD/bin
    MOC_DIR     = $$PWD/release/build/moc
    OBJECTS_DIR = $$PWD/release/build/obj
    UI_DIR      = $$PWD/release/build/ui
}

include($$PWD/utils/utils.pri)
include($$PWD/stlroutines/stlroutines.pri)

SOURCES += main.cpp \

HEADERS += \
