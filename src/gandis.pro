#-------------------------------------------------
#
# Project created by QtCreator 2019-06-02T17:46:50
#
#-------------------------------------------------

QT       = opengl

TARGET = gandis
TEMPLATE = lib

DEFINES += GANDISENGINE_EXPORT

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../output/lib
OBJECTS_DIR = build
MOC_DIR = build

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(include.pri);
include(install.pri);

include(library.pri);

SOURCES += \
    render/shader/coshader.cpp \
    render/coqtrenderer.cpp \
    render/corenderer.cpp \
    common/core/copoint.cpp \
    common/core/copolygon.cpp \
    util/coobjreader.cpp \
    util/costlreader.cpp \
    util/cotexturereader.cpp \
    render/shader/covertexshader.cpp \
    render/shader/cofragmentshader.cpp \
    common/util/noreader.cpp \
    render/shader/coshadermanager.cpp \
    common/core/coobject.cpp \
    window/screen/qt/coqscreen.cpp \
    render/core/coopenglstate.cpp \
    render/core/cocamera.cpp \
    common/core/comath.cpp \
    common/math/comatrix3x3.cpp \
    common/math/comatrix4x4.cpp \
    render/shader/noshaderhelper.cpp \
    render/shader/coshaderprogram.cpp

HEADERS += \
    common/core/coenginedefine.h \
    render/coqtrenderer.h \
    render/corenderer.h \
    render/shader/coshader.h \
    common/core/copoint.h \
    common/core/copolygon.h \
    util/coobjreader.h \
    util/costlreader.h \
    util/cotexturereader.h \
    render/shader/covertexshader.h \
    render/shader/cofragmentshader.h \
    common/util/noreader.h \
    render/shader/coshadermanager.h \
    common/core/dedatatype.h \
    render/shader/core/deshader.h \
    render/shader/core/dedefaultvertexshader.h \
    render/shader/core/dedefaultfragmentshader.h \
    common/core/coobject.h \
    window/screen/qt/coqscreen.h \
    common/util/delog.h \
    render/core/coopenglstate.h \
    render/core/cocamera.h \
    common/core/comath.h \
    common/math/comatrix3x3.h \
    common/math/comatrix4x4.h \
    render/shader/noshaderhelper.h \
    render/shader/coshaderprogram.h

