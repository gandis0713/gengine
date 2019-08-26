#ifndef COTEXTURE_H
#define COTEXTURE_H

#include "coshape.h"
#include "covector2.h"

class GANDISENGINE CoTexture : public CoShape
{
public:
    CoTexture(Guchar* pData,
              Gint nWidth,
              Gint nHeight);
    ~CoTexture();

    void setData(Guchar* pData);
    Guchar* getData();
    void setWidth(Gint nWidth);
    void setHeight(Gint nHeight);
    Gint getWidth();
    Gint getHeight();
    std::vector<CoVec2> getTextureCoords();
    std::vector<Guint> getVertexIndices();

protected:
    Guchar*       m_pData;
    Gint          m_nWidth;
    Gint          m_nHeight;

    std::vector<CoVec2> m_vecTextureCoord;
    std::vector<Guint> m_vecVertexIndices;
};

#endif // COTEXTURE_H
