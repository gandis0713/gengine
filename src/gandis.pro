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
    util/coobjreader.cpp \
    util/costlreader.cpp \
    util/cotexturereader.cpp \
    common/util/noreader.cpp \
    window/screen/qt/coqscreen.cpp \
    render/core/coopenglstate.cpp \
    render/camera/cocamera.cpp \
    common/math/comatrix3x3.cpp \
    common/math/comatrix4x4.cpp \
    window/cowindow.cpp \
    window/cowin32window.cpp \
    window/coxwindow.cpp \
    common/math/comatrix2x2.cpp \
    common/math/covector2.cpp \
    common/math/covector3.cpp \
    common/math/covector4.cpp \
    common/core/nomath.cpp \
    render/camera/coperspectivecamera.cpp \
    render/camera/coorthographiccamera.cpp \
    common/core/coglextension.cpp \
    render/object/covertexbufferobject.cpp \
    render/object/covertexarrayobject.cpp \
    render/node/coline.cpp \
    render/node/cosylinder.cpp \
    render/node/cosphere.cpp \
    render/node/copolygon.cpp \
    render/node/copoint.cpp \
    render/node/conode.cpp \
    render/shader/codefaultshaderprogram.cpp \
    render/shader/coshaderprogram.cpp \
    render/shader/cosplineshaderprogram.cpp \
    render/node/core/conodecore.cpp \
    render/node/core/codefaultnodecore.cpp \
    render/node/core/cosplinenodecore.cpp \
    render/node/cospline.cpp

HEADERS += \
    render/coqtrenderer.h \
    render/corenderer.h \
    render/shader/coshader.h \
    util/coobjreader.h \
    util/costlreader.h \
    util/cotexturereader.h \
    common/util/noreader.h \
    common/core/dedatatype.h \
    render/shader/core/deshader.h \
    render/shader/core/dedefaultvertexshader.h \
    render/shader/core/dedefaultfragmentshader.h \
    window/screen/qt/coqscreen.h \
    common/util/delog.h \
    render/core/coopenglstate.h \
    render/camera/cocamera.h \
    common/math/comatrix3x3.h \
    common/math/comatrix4x4.h \
    window/cowindow.h \
    window/cowin32window.h \
    window/coxwindow.h \
    common/math/comatrix2x2.h \
    common/math/covector2.h \
    common/math/covector3.h \
    common/math/covector4.h \
    common/core/demath.h \
    common/core/nomath.h \
    render/camera/coperspectivecamera.h \
    common/core/deengine.h \
    render/camera/coorthographiccamera.h \
    common/core/glext.h \
    common/core/coglextension.h \
    render/object/covertexbufferobject.h \
    render/object/covertexarrayobject.h \
    render/node/coline.h \
    render/node/cosylinder.h \
    render/node/cosphere.h \
    render/node/copolygon.h \
    render/node/copoint.h \
    render/node/conode.h \
    render/shader/codefaultshaderprogram.h \
    render/shader/coshaderprogram.h \
    render/shader/cosplineshaderprogram.h \
    render/node/core/conodecore.h \
    render/node/core/codefaultnodecore.h \
    render/node/core/cosplinenodecore.h \
    render/node/cospline.h

OTHER_FILES += \
    libgandis.pri
