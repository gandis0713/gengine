include(libglm.pri);
include(libopengl.pri);
include($$(LIB_PATH)/gandis/libgandis.pri);

win32
{

!contains( file_copies, CONFIG )
{

CONFIG += file_copies

}

COPIES += copylibrary
copylibrary.files += $$files($$(LIB_PATH)/gandis/lib/*.dll)
copylibrary.path = $${DESTDIR}

}
