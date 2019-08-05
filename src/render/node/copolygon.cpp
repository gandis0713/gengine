#include "copolygon.h"

CoPolygon::CoPolygon()
{    
    m_eShaderProgramType = EShaderProgramType::ePolygon;
}

CoPolygon::CoPolygon(const std::vector<CoVec3> vecPoints)
{
    setPoints(vecPoints);

    m_eShaderProgramType = EShaderProgramType::ePolygon;
}

CoPolygon::~CoPolygon()
{
    // do nothing.
}

void CoPolygon::setPoints(const std::vector<CoVec3> vecPoints)
{
    m_vecPoints.clear();
    m_vecPoints = vecPoints;
}
