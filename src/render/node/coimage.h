#ifndef COIMAGE_H
#define COIMAGE_H

#include "coshape.h"
#include "covector2.h"

class QImage;

class GANDISENGINE CoImage : public CoShape
{
public:
    CoImage();
    ~CoImage();

    void load(const Gchar *pPath);
    void setData(const Guchar* pData);
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

#endif // COIMAGE_H
