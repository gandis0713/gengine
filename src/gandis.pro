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
DESTDIR = ../output
OBJECTS_DIR = build
MOC_DIR = build

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    shader/coshader.cpp \
    render/coqtrenderer.cpp \
    render/corenderer.cpp \
    screen/qt/coglwidget.cpp \
    screen/qt/coqtscreen.cpp \
    screen/coscreen.cpp \
    data/copoint.cpp \
    data/copolygon.cpp \
    util/coobjreader.cpp \
    util/costlreader.cpp \
    util/cotexturereader.cpp \
    shader/covertexshader.cpp \
    shader/cofragmentshader.cpp \
    common/util/noreader.cpp \
    shader/coshadermanager.cpp

HEADERS += \
    coenginedefine.h \
    render/coqtrenderer.h \
    render/corenderer.h \
    shader/coshader.h \
    screen/qt/coglwidget.h \
    screen/qt/coqtscreen.h \
    screen/coscreen.h \
    data/copoint.h \
    data/copolygon.h \
    util/coobjreader.h \
    util/costlreader.h \
    util/cotexturereader.h \
    shader/covertexshader.h \
    shader/cofragmentshader.h \
    common/util/noreader.h \
    shader/coshadermanager.h \
    common/datatype/dedatatype.h \
    shader/deshader.h \
    shader/dedefaultvertexshader.h \
    shader/dedefaultfragmentshader.h

PRECOMPILED_HEADER += ./common/pch/precompileheader.h

INCLUDEPATH += /usr/include/glm \
    common/pch

unix {
    target.path = /home/gandis/lib
    target.files = ../output/*.*
    INSTALLS += target
}
