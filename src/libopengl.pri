unix {
INCLUDEPATH += /usr/include/GL

LIBS += -L/usr/lib/x86_64-linux-gnu/ -lGLEW
}

win32 {

INCLUDEPATH += $$(WINDOWS_SDK)/include \
    $$(GRAPHICS_DRIVER_PATH)/lib/x86_64/include

LIBS += -L$$(WINDOWS_SDK)/Lib/x64 -lOpenGL32 \
    -L$$(WINDOWS_SDK)/Lib/x64 -lGdi32 \
    -L$$(WINDOWS_SDK)/Lib/x64 -lGlU32 \
    -L$$(WINDOWS_SDK)/Lib/x64 -lUser32 \
    -L$$(GRAPHICS_DRIVER_PATH)/lib/x86_64 -lglew64  # need remove if added custom extension functions is defined.

}
