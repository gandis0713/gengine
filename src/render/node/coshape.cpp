#include "coshape.h"

CoShape::CoShape()
    : m_fWidth(0.005f)
{

}

CoShape::~CoShape()
{
}

Guint CoShape::getSize()
{
    return m_vecPoints.size();
}

void CoShape::setColor(CoVec3 vColor)
{
    m_vecColors.clear();
    for(Gint i = 0; i < m_vecPoints.size(); i++)
    {
        m_vecColors.push_back(vColor);
    }
}

std::vector<CoVec3> CoShape::getPoints()
{
    return m_vecPoints;
}

std::vector<CoVec3> CoShape::getColors()
{
    return m_vecColors;
}


void CoShape::setWidth(Gfloat fWidth)
{
    m_fWidth = fWidth;
}

Gfloat CoShape::getWidth()
{
    return m_fWidth;
}

void CoShape::setMatModel(CoMat4x4 matModel)
{
    m_matModel = matModel;
}

CoMat4x4 CoShape::getMatModel()
{
    return m_matModel;
}


void CoShape::getBound(CoVec3 &vMin, CoVec3 &vMax)
{
    CoVec3 vLowerLimit( 1, 1, 1);

    vMin = vLowerLimit;
    vMax = -vLowerLimit;
    if(m_vecPoints.size() <= 0)
    {
        return;
    }

    CoVec3 vUpLimit( 10000000,  10000000,  10000000);

    vMin = vUpLimit;
    vMax = -vUpLimit;

    for(Gint nIndex = 0; nIndex < m_vecPoints.size(); nIndex++)
    {
        CoVec3 vPoint = m_vecPoints[nIndex];

        if(vMin[0] > vPoint[0])
        {
            vMin[0] = vPoint[0];
        }
        if(vMin[1] > vPoint[1])
        {
            vMin[1] = vPoint[1];
        }
        if(vMin[2] > vPoint[2])
        {
            vMin[2] = vPoint[2];
        }

        if(vMax[0] < vPoint[0])
        {
            vMax[0] = vPoint[0];
        }
        if(vMax[1] < vPoint[1])
        {
            vMax[1] = vPoint[1];
        }
        if(vMax[2] < vPoint[2])
        {
            vMax[2] = vPoint[2];
        }
    }
}
