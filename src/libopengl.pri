unix {
INCLUDEPATH += /usr/include/GL

LIBS += -L/usr/lib/x86_64-linux-gnu/ -lGLEW
}

win32 {

INCLUDEPATH += 'C:/Program Files (x86)/AMD APP SDK/2.9-1/include/'

LIBS += -L'C:/Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x64/' -lOpenGL32
LIBS += -L'C:/Program Files (x86)/AMD APP SDK/2.9-1/lib/x86_64/' -lglew64

}
