#ifndef COSHAPE_H
#define COSHAPE_H

#include "conode.h"
#include "comatrix4x4.h"

class GANDISENGINE CoShape : public CoNode
{
public:
    CoShape();
    ~CoShape();

    Guint getSize();

    void setColor(CoVec3 vColor);

    std::vector<CoVec3> getPoints();
    std::vector<CoVec3> getColors();

    void setWidth(Gfloat fWidth);
    Gfloat getWidth();

    void setMatModel(CoMat4x4 matModel);
    CoMat4x4 getMatModel();

    void getBound(CoVec3 &vMin, CoVec3 &vMax);

protected:
    std::vector<CoVec3> m_vecPoints;
    std::vector<CoVec3> m_vecColors;

    CoMat4x4            m_matModel;

    Gfloat m_fWidth;
};

#endif // COSHAPE_H
