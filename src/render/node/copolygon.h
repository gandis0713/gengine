#ifndef COPOLYGON_H
#define COPOLYGON_H

#include "coshape.h"
#include "cofaceindex.h"
#include "comatrix4x4.h"

class GANDISENGINE CoPolygon : public CoShape
{
public:
    CoPolygon();
    CoPolygon(const std::vector<CoVec3> &vecPoints);
    ~CoPolygon();

    void setPoints(const std::vector<CoVec3> &vecPoints);
    void setNormals(const std::vector<CoVec3> &vecNormals);
    void setMatModel(CoMat4x4 matModel);
    CoMat4x4 getMatModel();
    std::vector<CoVec3> getNormals();

private:
    CoMat4x4            m_matModel;
    std::vector<CoVec2> m_vecUICoords;
    std::vector<CoVec3> m_vecVertexNormals;
    CoFaceIndex         m_faceIndices;
};

#endif // COPOLYGON_H
