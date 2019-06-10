G_LIB_PATH = $$(LIB_PATH)/gandis
G_INC_PATH = $${G_LIB_PATH}/include

INCLUDEPATH += $${G_INC_PATH}/ \
## common
    $${G_INC_PATH}/common \
    $${G_INC_PATH}/common/core \
    $${G_INC_PATH}/common/math \
## render
    $${G_INC_PATH}/render \
    $${G_INC_PATH}/render/core \
    $${G_INC_PATH}/render/opengl \
## shader
    $${G_INC_PATH}/shader \
    $${G_INC_PATH}/shader/core \
## window
    $${G_INC_PATH}/window \
    $${G_INC_PATH}/window/screen \
    $${G_INC_PATH}/window/screen/qt \

LIBS += -L$${G_LIB_PATH}/lib -lgandis
