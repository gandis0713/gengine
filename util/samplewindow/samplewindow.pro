#-------------------------------------------------
#
# Project created by QtCreator 2019-08-17T23:45:01
#
#-------------------------------------------------

QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = samplewindow
TEMPLATE = lib

DEFINES += GANDIS_SAMPLE_WINDOW_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS

DESTDIR = ../output/lib
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build

include(../library.pri);
include(install.pri);

SOURCES += \
    samplewindow.cpp \

HEADERS += \
    samplewindow.h \
    samplewindowglobal.h

FORMS += \
    samplewindow.ui

OTHER_FILES += \
    libsamplewindow.pri
