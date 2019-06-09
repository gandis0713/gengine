
ROOT_PATH =

unix {

ROOT_PATH = /home/gandis/lib/gandis

}

win32 {

ROOT_PATH = C:/lib/gandis

}

LIB_PATH = $${ROOT_PATH}/lib
INCLUDE_PATH = $${ROOT_PATH}/include

## pri
    pri.path = $${ROOT_PATH}
    pri.files = libgandis.pri
    INSTALLS += pri

## lib
    lib.path = $${LIB_PATH}
    lib.files = ../output/*.*
    INSTALLS += lib

## common
    include_common_core.path = $${INCLUDE_PATH}/common/core
    include_common_core.files = common/core/*.h
    INSTALLS += include_common_core

    include_common_math.path = $${INCLUDE_PATH}/common/math
    include_common_math.files = common/math/*.h
    INSTALLS += include_common_math

## common
    include_common_core.path = $${INCLUDE_PATH}/common/core
    include_common_core.files = common/core/*.h
    INSTALLS += include_common_core

## render
    include_render.path = $${INCLUDE_PATH}/render
    include_render.files = render/*.h
    INSTALLS += include_render

    include_render_core.path = $${INCLUDE_PATH}/render/core
    include_render_core.files = render/core/*.h
    INSTALLS += include_render_core

    include_render_opengl.path = $${INCLUDE_PATH}/render/opengl
    include_render_opengl.files = render/opengl/*.h
    INSTALLS += include_render_opengl

## window
    include_window.path = $${INCLUDE_PATH}/window
    include_window.files = window/*.h
    INSTALLS += include_window

    include_window_screen.path = $${INCLUDE_PATH}/window/screen
    include_window_screen.files = window/screen/*.h
    INSTALLS += include_window_screen

    include_window_screen_qt.path = $${INCLUDE_PATH}/window/screen/qt
    include_window_screen_qt.files = window/screen/qt/*.h
    INSTALLS += include_window_screen_qt
