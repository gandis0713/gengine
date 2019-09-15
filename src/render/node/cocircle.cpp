#include "cocircle.h"
#include "demath.h"

CoCircle::CoCircle()
    : m_vCenter(CoVec3(0, 0, 0))
    , m_fRadius(1.f)
{
    m_eShaderProgramType = EShaderProgramType::eCircle;

    createCircle();
}

CoCircle::CoCircle(CoVec3 vPosition, Gfloat fRadius)
    : m_vCenter(vPosition)
    , m_fRadius(fRadius)
{
    m_eShaderProgramType = EShaderProgramType::eCircle;

    createCircle();
}

CoCircle::~CoCircle()
{
    // do nothing.
}

void CoCircle::createCircle()
{
    m_vecPoints.clear();

    CoVec3 startPosition(m_vCenter[0], m_vCenter[1] + m_fRadius, m_vCenter[2]);

    CoVec3 startNormal = startPosition - m_vCenter;

    Gint nRatio = 10;
    Gint nCount = 36;

    for(Gint i = 0; i < nCount; i++)
    {

        Gfloat fDegree = nRatio * i;

        CoVec3 vPosition(startNormal.length() * cos(DEG2RAD * fDegree),
                         startNormal.length() * sin(DEG2RAD * fDegree),
                         0);

        m_vecPoints.push_back(vPosition);
    }
}

void CoCircle::setCenter(CoVec3 vPosition)
{
    m_vCenter = vPosition;
}

void CoCircle::setRadius(Gfloat fRadius)
{
    m_fRadius = fRadius;
}
