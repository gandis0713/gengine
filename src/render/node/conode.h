#ifndef CONODE_H
#define CONODE_H

#include "coglextension.h"
#include "deengine.h"
#include "covector3.h"
#include "deshader.h".h"

#include <vector>

class GANDISENGINE CoNode
{
public:
    CoNode();
    ~CoNode();

    virtual void draw() = 0;

    Guint getSize();

    void setColor(CoVec3 vColor);

    std::vector<CoVec3> getPoints();
    std::vector<CoVec3> getColors();
    EShaderProgramType getShaderProgramType();

protected:
    std::vector<CoVec3> m_vecPoints;
    std::vector<CoVec3> m_vecColors;
    EShaderProgramType  m_eShaderProgramType;
};

#endif // CONODE_H
