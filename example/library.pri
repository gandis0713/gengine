include($${PWD}/../output/libgandis.pri);

win32
{

!contains( file_copies, CONFIG )
{

CONFIG += file_copies

}

COPIES += copylibrary
copylibrary.files += $$files($${PWD}/../output/lib/*.dll)
copylibrary.path = $${DESTDIR}

}
