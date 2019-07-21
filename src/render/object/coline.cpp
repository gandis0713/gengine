#include "coline.h"

CoLine::CoLine(CoVec3 vStart, CoVec3 vEnd)
{
    setPoint(vStart, vEnd);

    m_vecColors.clear();
    for(Gint i = 0; i < m_vecPoints.size(); i++)
    {
        m_vecColors.push_back(CoVec3(1.f, 1.f, 1.f));
    }
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
