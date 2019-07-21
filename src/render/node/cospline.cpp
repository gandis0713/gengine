#include "cospline.h"

CoSpline::CoSpline(const std::vector<CoVec3> vecPoints)
{    
    m_vecPoints = vecPoints;
    setColor(CoVec3(1.0, 1.0, 1.0));

    m_eShaderProgramType = EShaderProgramType::eSpline;
}

CoSpline::~CoSpline()
{

}

void CoSpline::draw()
{
//    glDrawArrays(GL_LINE_STRIP, 0, getSize());
    glDrawArrays(GL_LINE_STRIP_ADJACENCY, 0, getSize());
}

void CoSpline::setPoints(const std::vector<CoVec3> vecPoints)
{
    m_vecPoints.clear();
    m_vecPoints = vecPoints;
}



