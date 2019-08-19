#include "colight.h"

CoLight::CoLight()
    : m_fPower(1000000000000.f)
    , m_vColor(CoVec3(1, 1, 1))
    , m_vPosition(10000, 10000, 1000000)
{

}

CoLight::~CoLight()
{

}

void CoLight::setPower(Gfloat fPower)
{
    m_fPower = fPower;
}

void CoLight::setColor(CoVec3 vColor)
{
    m_vColor = vColor;
}

void CoLight::setPosition(CoVec3 vPosition)
{
    m_vPosition = vPosition;
}

Gfloat CoLight::getPower()
{
    return m_fPower;
}

CoVec3 CoLight::getColor()
{
    return m_vColor;
}

CoVec3 CoLight::getPosition()
{
    return m_vPosition;
}
