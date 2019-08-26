#ifndef COTEXTUREREADER_H
#define COTEXTUREREADER_H

#include "dedatatype.h"
#include "deengine.h"

class QImage;

class GANDISENGINE CoTextureReader
{
public:
    explicit CoTextureReader();
    ~CoTextureReader();

    void load(const Gchar *pPath);
    Guchar* getData();
    Gint getWidth();
    Gint getHeight();

private:

    QImage *m_pImage;
};

#endif // COTEXTUREREADER_H
