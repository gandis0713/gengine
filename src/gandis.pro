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
DESTDIR = build/lib
OBJECTS_DIR = temp/obj
MOC_DIR = temp/moc
RCC_DIR = temp/rcc

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
    render/shader/coshaderprogram.cpp \
    render/node/core/conodecore.cpp \
    render/shader/colineshaderprogram.cpp \
    render/shader/cocatmullsplineshaderprogram.cpp \
    render/node/cocatmullspline.cpp \
    render/node/core/cocatmullsplinecore.cpp \
    render/node/core/colinecore.cpp \
    render/node/core/coshapecore.cpp \
    render/node/core/cocirclecore.cpp \
    render/node/cocircle.cpp \
    render/object/cotextureobject.cpp \
    render/node/core/copolygoncore.cpp \
    common/core/cofaceindex.cpp \
    render/node/coshape.cpp \
    render/light/colight.cpp \
    render/node/core/coimagecore.cpp \
    render/node/coimage.cpp

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
    render/shader/coshaderprogram.h \
    render/node/core/conodecore.h \
    render/shader/colineshaderprogram.h \
    render/shader/cocatmullsplineshaderprogram.h \
    render/node/cocatmullspline.h \
    render/node/core/cocatmullsplinecore.h \
    render/node/core/colinecore.h \
    render/node/core/coshapecore.h \
    render/node/core/cocirclecore.h \
    render/node/cocircle.h \
    render/object/cotextureobject.h \
    render/node/core/copolygoncore.h \
    common/core/cofaceindex.h \
    render/node/coshape.h \
    common/core/delog.h \
    render/light/colight.h \
    render/node/coimage.h \
    render/node/core/coimagecore.h

OTHER_FILES += \
    libgandis.pri

RESOURCES += \
    shader.qrc

DISTFILES +=
