#include "cocatmullspline.h"

CoCatmullSpline::CoCatmullSpline()
    : m_fAlpha(0.0f)
{
    m_eShaderProgramType = EShaderProgramType::eSpline;
}

CoCatmullSpline::CoCatmullSpline(const std::vector<CoVec3> vecPoints)
    : m_fAlpha(0.0f)
{
    setPoints(vecPoints);
    setColor(CoVec3(1.0, 1.0, 1.0));

    m_eShaderProgramType = EShaderProgramType::eSpline;
}

CoCatmullSpline::~CoCatmullSpline()
{

}

void CoCatmullSpline::setPoints(const std::vector<CoVec3> vecPoints)
{
    m_vecPoints.clear();

    CoVec3 vFirst = vecPoints[0] - vecPoints[1];
    m_vecPoints.push_back(vFirst);

    for(CoVec3 vPoint : vecPoints)
    {
        m_vecPoints.push_back(vPoint);
    }

    CoVec3 vLast = vecPoints[vecPoints.size() - 1] - vecPoints[vecPoints.size() - 2];
    m_vecPoints.push_back(vLast);
}


void CoCatmullSpline::setAlpha(Gfloat fAlpha)
{
    m_fAlpha = fAlpha;
}
Gfloat CoCatmullSpline::getAlpha()
{
    return m_fAlpha;
}



