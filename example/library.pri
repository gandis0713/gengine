
include($${PWD}/../output/util/libsamplewindow.pri);
include($${PWD}/../output/gandis/libgandis.pri);

win32
{

!contains( file_copies, CONFIG )
{

CONFIG += file_copies

}

COPIES += copylibrary
copylibrary.files += $$files($${PWD}/../output/gandis/lib/*.dll)
copylibrary.files += $$files($${PWD}/../output/util/lib/*.dll)
copylibrary.path = $${DESTDIR}

}
