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

