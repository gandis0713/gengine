#include "cosphere.h"
#include "demath.h"
#include "delog.h"

using namespace std;

CoSphere::CoSphere()
    : m_vCenter(0, 0, 0)
    , m_fRadius(1)
{
    m_eShaderProgramType = EShaderProgramType::eSphere;

    createSphere();
}

CoSphere::CoSphere(CoVec3 vCenter, Gfloat fRadius)
    : m_vCenter(vCenter)
    , m_fRadius(fRadius)
{
    m_eShaderProgramType = EShaderProgramType::eSphere;

    createSphere();
}

CoSphere::~CoSphere()
{

}

void CoSphere::createSphere()
{

    Gint n2PIDegree = 360;
    Gint nSectorRatio1 = 10;
    Gint nSectorRatio2 = 10;
    Gint nSector1 = n2PIDegree / nSectorRatio1 / 2;
    Gint nSector2 = n2PIDegree / nSectorRatio2;

    CoVec3 startPosition(m_vCenter[0], m_vCenter[1] + m_fRadius, m_vCenter[2]);
    CoVec3 startNormal = startPosition - m_vCenter;

    vector<vector<CoVec3>> vecSectors;
    for(Gint i = 0; i < nSector1; i++)
    {
        Gfloat fTheta1 = i * nSectorRatio1;

        vector<CoVec3> vecSector1;

        for(Gint j = 0; j < nSector2; j++)
        {
            Gfloat fTheta2 = j * nSectorRatio2;

            Gfloat x = startNormal.length() * sin(fTheta1 * DEG2RAD) * sin(fTheta2 * DEG2RAD);
            Gfloat y = startNormal.length() * cos(fTheta1 * DEG2RAD);
            Gfloat z = startNormal.length() * sin(fTheta1 * DEG2RAD) * cos(fTheta2 * DEG2RAD);

            CoVec3 vPos(x, y, z);

            vecSector1.push_back(vPos);
        }

        vecSectors.push_back(vecSector1);
    }

}

void CoSphere::setCenter(CoVec3 vPosition)
{
    m_vCenter = vPosition;
}

void CoSphere::setRadius(Gfloat fRadius)
{
    m_fRadius = fRadius;
}
