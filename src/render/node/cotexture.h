#ifndef COTEXTURE_H
#define COTEXTURE_H

#include "conode.h"

class QImage;

class GANDISENGINE CoTexture : public CoNode
{
public:
    CoTexture();
    ~CoTexture();

    void load(const Gchar *pPath);
    Guchar* getData();
    Gint getWidth();
    Gint getHeight();

protected:
    QImage *m_pImage;
};

#endif // COTEXTURE_H
