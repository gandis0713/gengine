SAMPLE_WINDOW_INSTALL_PATH = ../../output/util
SAMPLE_WINDOW_INSTALL_INC_PATH = $${SAMPLE_WINDOW_INSTALL_PATH}/include

## pri
    s_pri.path = $${SAMPLE_WINDOW_INSTALL_PATH}
    s_pri.files = libsamplewindow.pri
    INSTALLS += s_pri

## include
    ## common
    s_include.path = $${SAMPLE_WINDOW_INSTALL_INC_PATH}
    s_include.files = ./*.h
    INSTALLS += s_include

## lib
SAMPLE_WINDOW_LIB_PATH = $${SAMPLE_WINDOW_INSTALL_PATH}
unix
{
    SAMPLE_WINDOW_LIB_PATH = /usr/local/lib/samplewindow
}
    s_library.path = $${SAMPLE_WINDOW_LIB_PATH}
    s_library.files = $${DESTDIR}
    INSTALLS += s_library
