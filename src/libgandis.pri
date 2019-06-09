win32 {

LIBRARY_PATH = $$(LIB_PATH)/gandis
INCLUDE_PATH = $${LIBRARY_PATH}/include

INCLUDEPATH += $${INCLUDE_PATH}/ \
## common
    $${INCLUDE_PATH}/common \
    $${INCLUDE_PATH}/common/core \
    $${INCLUDE_PATH}/common/math \
## render
    $${INCLUDE_PATH}/render \
    $${INCLUDE_PATH}/render/core \
    $${INCLUDE_PATH}/render/opengl \
## shader
    $${INCLUDE_PATH}/shader \
    $${INCLUDE_PATH}/shader/core \
## window
    $${INCLUDE_PATH}/window \
    $${INCLUDE_PATH}/window/screen \
    $${INCLUDE_PATH}/window/screen/qt \
LIBS += -L$${LIBRARY_PATH}/lib -lgandis

}
