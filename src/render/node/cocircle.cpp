#include "cocircle.h"

CoCircle::CoCircle()
{
    m_eShaderProgramType = EShaderProgramType::eCircle;
}

CoCircle::CoCircle(CoVec3 vPoint, Gfloat fRadius)
{
    setPoint(vPoint);
    setColor(CoVec3(0.5, 0.5, 0.5));

    m_eShaderProgramType = EShaderProgramType::eCircle;
}

CoCircle::~CoCircle()
{

}

void CoCircle::setPoint(CoVec3 vPoint)
{

}

void CoCircle::setRadius(CoVec3 vPoint)
{

}
