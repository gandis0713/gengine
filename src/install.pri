unix {

G_INSTALL_PATH = /home/gandis/lib/gandis

}

win32 {

G_INSTALL_PATH = C:/lib/gandis

}

G_INSTALL_LIB_PATH = $${G_INSTALL_PATH}/lib
G_INSTALL_INC_PATH = $${G_INSTALL_PATH}/include

## pri
    pri.path = $${G_INSTALL_PATH}
    pri.files = libgandis.pri
    INSTALLS += pri

## lib
    lib.path = $${G_INSTALL_LIB_PATH}
    lib.files = ../output/*.*
    INSTALLS += lib

## common
    include_common_core.path = $${G_INSTALL_INC_PATH}/common/core
    include_common_core.files = common/core/*.h
    INSTALLS += include_common_core

    include_common_math.path = $${G_INSTALL_INC_PATH}/common/math
    include_common_math.files = common/math/*.h
    INSTALLS += include_common_math

## render
    include_render.path = $${G_INSTALL_INC_PATH}/render
    include_render.files = render/*.h
    INSTALLS += include_render

    include_render_core.path = $${G_INSTALL_INC_PATH}/render/core
    include_render_core.files = render/core/*.h
    INSTALLS += include_render_core

    include_render_opengl.path = $${G_INSTALL_INC_PATH}/render/opengl
    include_render_opengl.files = render/opengl/*.h
    INSTALLS += include_render_opengl

## shader
    include_shader.path = $${G_INSTALL_INC_PATH}/shader
    include_shader.files = shader/*.h
    INSTALLS += include_shader

    include_shader_core.path = $${G_INSTALL_INC_PATH}/shader/core
    include_shader_core.files = shader/core/*.h
    INSTALLS += include_shader_core

## window
    include_window.path = $${G_INSTALL_INC_PATH}/window
    include_window.files = window/*.h
    INSTALLS += include_window

    include_window_screen.path = $${G_INSTALL_INC_PATH}/window/screen
    include_window_screen.files = window/screen/*.h
    INSTALLS += include_window_screen

    include_window_screen_qt.path = $${G_INSTALL_INC_PATH}/window/screen/qt
    include_window_screen_qt.files = window/screen/qt/*.h
    INSTALLS += include_window_screen_qt
