
ROOT_PATH =

unix {

ROOT_PATH = /home/gandis

}

win32 {

ROOT_PATH = C:/gandis

}

LIB_PATH = $${ROOT_PATH}/lib
INCLUDE_PATH = $${ROOT_PATH}/include



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
