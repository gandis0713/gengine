unix {
INCLUDEPATH += /usr/include/GL

LIBS += -L/usr/lib/x86_64-linux-gnu/ -lGLEW
}


win32 {

WINDOWS_SDK = 'C:/Program Files (x86)/Microsoft SDKs/Windows/v7.1A'

INCLUDEPATH += $${WINDOWS_SDK}/include

LIBS += -L$${WINDOWS_SDK}/Lib/x64 -lOpenGL32 \
    -L$${WINDOWS_SDK}/Lib/x64 -lGdi32 \
    -L$${WINDOWS_SDK}/Lib/x64 -lGlU32 \
    -L$${WINDOWS_SDK}/Lib/x64 -lUser32
}
