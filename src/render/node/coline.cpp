#include "coline.h"

CoLine::CoLine()
    : m_fRadius(0.005f)
{

}

CoLine::CoLine(CoVec3 vStart, CoVec3 vEnd)
    : m_fRadius(0.005f)
{
    setPoint(vStart, vEnd);
    setColor(CoVec3(1.0, 1.0, 1.0));
}

CoLine::~CoLine()
{

}

void CoLine::setPoint(CoVec3 vStart, CoVec3 vEnd)
{
    m_vecPoints.clear();
    m_vecPoints.push_back(vStart);
    m_vecPoints.push_back(vEnd);
}

void CoLine::setRadius(Gfloat fRadius)
{
    m_fRadius = fRadius;
}

Gfloat CoLine::getRadius()
{
    return m_fRadius;
}
