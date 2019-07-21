
G_INSTALL_PATH = $$(LIB_PATH)/gandis
G_INSTALL_INC_PATH = $${G_INSTALL_PATH}/include

## pri
    pri.path = $${G_INSTALL_PATH}
    pri.files = libgandis.pri
    INSTALLS += pri

## include
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

    include_render_object.path = $${G_INSTALL_INC_PATH}/render/object
    include_render_object.files = render/object/*.h
    INSTALLS += include_render_object

    include_render_camera.path = $${G_INSTALL_INC_PATH}/render/camera
    include_render_camera.files = render/camera/*.h
    INSTALLS += include_render_camera

    include_render_shader.path = $${G_INSTALL_INC_PATH}/render/shader
    include_render_shader.files = render/shader/*.h
    INSTALLS += include_render_shader

    include_render_shader_core.path = $${G_INSTALL_INC_PATH}/render/shader/core
    include_render_shader_core.files = render/shader/core/*.h
    INSTALLS += include_render_shader_core

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


## lib
    library.path = $${G_INSTALL_PATH}
    library.files = $${DESTDIR}
    INSTALLS += library
