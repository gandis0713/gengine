LIBRARY_PATH = ../../src

INCLUDEPATH += $${LIBRARY_PATH}/ \
## common
    $${LIBRARY_PATH}/common \
    $${LIBRARY_PATH}/common/core \
    $${LIBRARY_PATH}/common/math \
## render
    $${LIBRARY_PATH}/render \
    $${LIBRARY_PATH}/render/core \
    $${LIBRARY_PATH}/render/node \
    $${LIBRARY_PATH}/render/node/core \
    $${LIBRARY_PATH}/render/object \
    $${LIBRARY_PATH}/render/camera \
    $${LIBRARY_PATH}/render/shader \
    $${LIBRARY_PATH}/render/shader/core \
## util
    $${LIBRARY_PATH}/util \
## window
    $${LIBRARY_PATH}/window \
    $${LIBRARY_PATH}/window/screen \
    $${LIBRARY_PATH}/window/screen/qt \
