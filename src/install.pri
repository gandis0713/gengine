unix {
    lib.path = /home/gandis/lib
    lib.files = ../output/*.*
    INSTALLS += lib

    include.path = /home/gandis/include
    include.files = common/core/*.*
    INSTALLS += include
}

win32 {
    bin.path = C:/gandis/bin
    bin.files = ../output/*.*
    INSTALLS += bin

    include.path = C:/gandis/include
    include.files = common/core/*.*
    INSTALLS += include
}
