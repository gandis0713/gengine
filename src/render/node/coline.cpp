#include "coline.h"

CoLine::CoLine()
{
    m_eShaderProgramType = EShaderProgramType::eLine;
}

CoLine::CoLine(CoVec3 vStart, CoVec3 vEnd)
{
    setPoint(vStart, vEnd);

    m_eShaderProgramType = EShaderProgramType::eLine;
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
