#ifndef COTEXTURE_H
#define COTEXTURE_H

#include "coshape.h"
#include "covector2.h"

class QImage;

class GANDISENGINE CoTexture : public CoShape
{
public:
    CoTexture();
    ~CoTexture();

    void load(const Gchar *pPath);
    Guchar* getData();
    Gint getWidth();
    Gint getHeight();
    std::vector<CoVec2> getTextureCoords();
    std::vector<Guint> getVertexIndices();

protected:
    QImage *m_pImage;

    std::vector<CoVec2> m_vecTextureCoord;
    std::vector<Guint> m_vecVertexIndices;
};

#endif // COTEXTURE_H
