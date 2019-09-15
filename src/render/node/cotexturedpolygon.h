#ifndef COTEXTUREDPOLYGON_H
#define COTEXTUREDPOLYGON_H

#include "coshape.h"
#include "cofaceindex.h"

class GANDISENGINE CoTexturedPolygon : public CoShape
{
public:
    CoTexturedPolygon();
    CoTexturedPolygon(const std::vector<CoVec3> &vecPoints,
                      const std::vector<CoVec3> &vecNormals,
                      const std::vector<CoVec2> &vecTextureCoords,
                      const CoFaceIndex &faceIndices,
                      Guchar* pTextureData,
                      Gint nTextureWidth,
                      Gint nTextureHeight);
    virtual ~CoTexturedPolygon();

    void setPoints(const std::vector<CoVec3> &vecPoints);
    void setNormals(const std::vector<CoVec3> &vecNormals);
    void setTextureCoords(const std::vector<CoVec2> &vecUICoords);
    void setFaceIndex(const CoFaceIndex &faceIndices);
    void setTextureData(Guchar* pTextureData);
    void setTextureWidth(Gint nTextureWidth);
    void setTextureHeight(Gint nTextureHeight);

    std::vector<CoVec3> getNormals();
    std::vector<CoVec2> getTextureCoords();
    CoFaceIndex getFaceIndex();
    Guchar* getTextureData();
    Gint getTextureWidth();
    Gint getTextureHeight();

private:
    std::vector<CoVec2> m_vecTextureCoords;
    std::vector<CoVec3> m_vecVertexNormals;
    CoFaceIndex         m_faceIndices;
    Guchar* m_pTextureData;
    Gint m_nTextureWidth;
    Gint m_nTextureHeight;
};

#endif // COTEXTUREDPOLYGON_H
