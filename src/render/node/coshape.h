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

    std::vector<CoVec3> getPoints();

    void setColor(CoVec3 vColor);
    CoVec3 getColor();
    void setAmbientColor(CoVec3 vColor);
    CoVec3 getAmbientColor();
    void setSpecularColor(CoVec3 vColor);
    CoVec3 getSpecularColor();

    void setWidth(Gfloat fWidth);
    Gfloat getWidth();

    void setMatModel(CoMat4x4 matModel);
    CoMat4x4 getMatModel();

    void getBound(CoVec3 &vMin, CoVec3 &vMax);

protected:
    std::vector<CoVec3> m_vecPoints;
    CoVec3              m_vDiffuseColor;
    CoVec3              m_vAmbientColor;
    CoVec3              m_vSpecularColor;

    CoMat4x4            m_matModel;

    Gfloat m_fWidth;
};

#endif // COSHAPE_H
