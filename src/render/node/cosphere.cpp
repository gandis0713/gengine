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

/**
 * @brief This function is used to opengl coordinate opengl to create vertice of sphere.
 *        z-axis is screen.
 *        y-axis is up.
 *        x-aixs is right.
 */
void CoSphere::createSphere()
{
    // step 1 : create vertice

    Gint n2PIDegree = 360;
    Gint nStackRatio = 10;
    Gint nSectorRatio = 10;
    Gint nStack = n2PIDegree / 2 / nStackRatio;
    Gint nSector = n2PIDegree / nSectorRatio;

    CoVec3 startPosition(m_vCenter[0], m_vCenter[1] + m_fRadius, m_vCenter[2]);
    CoVec3 startNormal = startPosition - m_vCenter;

    vector<CoVec3> vecVertices;
    for(Gint i = 0; i < nStack; i++)
    {
        Gfloat fStackTheta = i * nStackRatio;

        for(Gint j = 0; j < nSector; j++)
        {
            Gfloat fSectorTheta = j * nSectorRatio;

            Gfloat x = startNormal.length() * sin(fStackTheta * DEG2RAD) * sin(fSectorTheta * DEG2RAD);
            Gfloat y = startNormal.length() * cos(fStackTheta * DEG2RAD);
            Gfloat z = startNormal.length() * sin(fStackTheta * DEG2RAD) * cos(fSectorTheta * DEG2RAD);

            CoVec3 vPos(x, y, z);

            vecVertices.push_back(vPos);
        }
    }

    // step 2 : create indices for triangle.

    vector<Gint> vecVertexIndices;
    for(Gint i = 0; i < nStack - 1; i++)
    {
        for(Gint j = 0; j < nSector; j++)
        {
            // triangle 1
            vecVertexIndices.push_back(i * nSector + j); // stack 0 + sector 0
            vecVertexIndices.push_back((i + 1) * nSector + j); // stack 1 + sector 0
            vecVertexIndices.push_back(i * nSector + j + 1); // stack 0 + sector 1

            // triangle 2
            vecVertexIndices.push_back(i * nSector + j + 1); // stack 0 + sector 1
            vecVertexIndices.push_back((i + 1) * nSector + j); // stack 1 + sector 0
            vecVertexIndices.push_back((i + 1) * nSector + j + 1); // stack 1 + sector 1
        }
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
