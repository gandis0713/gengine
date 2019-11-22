G_LIB_PATH = $${PWD}/lib
unix
{
    G_LIB_PATH = /usr/local/lib/gandis/lib
}
G_INC_PATH = $${PWD}/include

INCLUDEPATH += $${G_INC_PATH}/ \
## common
    $${G_INC_PATH}/common \
    $${G_INC_PATH}/common/core \
    $${G_INC_PATH}/common/math \
## render
    $${G_INC_PATH}/render \
    $${G_INC_PATH}/render/core \
    $${G_INC_PATH}/render/node \
    $${G_INC_PATH}/render/node/core \
    $${G_INC_PATH}/render/object \
    $${G_INC_PATH}/render/camera \
    $${G_INC_PATH}/render/light \
    $${G_INC_PATH}/render/shader \
    $${G_INC_PATH}/render/shader/core \
## util
    $${G_INC_PATH}/util \
## window
    $${G_INC_PATH}/window \
    $${G_INC_PATH}/window/screen \
    $${G_INC_PATH}/window/screen/qt \

LIBS += -L$${G_LIB_PATH} -lgandis

