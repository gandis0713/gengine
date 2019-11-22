SAMPLE_WINDOW_LIB_PATH = $${PWD}/lib
unix
{
    SAMPLE_WINDOW_LIB_PATH = /usr/local/lib/samplewindow/lib
}
SAMPLE_WINDOW_INC_PATH = $${PWD}/include

INCLUDEPATH += $${SAMPLE_WINDOW_INC_PATH}/ \

LIBS += -L$${SAMPLE_WINDOW_LIB_PATH} -lsamplewindow
