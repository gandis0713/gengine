#include "coline.h"

CoLine::CoLine()
{

}

CoLine::CoLine(CoVec3 vStart, CoVec3 vEnd)
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
