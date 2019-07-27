#include "cocatmullspline.h"

CoCatmullSpline::CoCatmullSpline(const std::vector<CoVec3> vecPoints)
{    
    m_vecPoints = vecPoints;
    setColor(CoVec3(1.0, 1.0, 1.0));

    m_eShaderProgramType = EShaderProgramType::eSpline;
}

CoCatmullSpline::~CoCatmullSpline()
{

}

void CoCatmullSpline::draw()
{
    glDrawArrays(GL_LINES_ADJACENCY, 0, getSize());
}

void CoCatmullSpline::setPoints(const std::vector<CoVec3> vecPoints)
{
    m_vecPoints.clear();
    m_vecPoints = vecPoints;
}



