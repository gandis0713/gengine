#include "cosphere.h"
#include "demath.h"
#include "delog.h"

CoSphere::CoSphere()
    : m_vCenter(0, 0, 0)
    , m_fRadius(10)
{
    m_eShaderProgramType = EShaderProgramType::eSphere;

//    createSphereFlat();
    createSphere();
//    createIndexedSphere();
}

CoSphere::CoSphere(CoVec3 vCenter, Gfloat fRadius)
    : m_vCenter(vCenter)
    , m_fRadius(fRadius)
{
    m_eShaderProgramType = EShaderProgramType::eSphere;

//    createSphereFlat();
    createSphere();
//    createIndexedSphere();
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
    vector<CoVec3> vecVertexNormals;
    for(Gint i = 0; i <= nStack; i++)
    {
        Gfloat fStackTheta = i * nStackRatio;

        // the condition as below that to avoid zero normal vector is need to be confirmed.
        if(i == 0)
        {
            fStackTheta = 0.01 * nStackRatio;
        }
        else if(i == nStack)
        {
            fStackTheta = (nStack - 0.01) * nStackRatio;
        }

        for(Gint j = 0; j < nSector; j++)
        {
            Gfloat fSectorTheta = j * nSectorRatio;

            Gfloat x = startNormal.length() * sin(fStackTheta * DEG2RAD) * sin(fSectorTheta * DEG2RAD);
            Gfloat y = startNormal.length() * cos(fStackTheta * DEG2RAD);
            Gfloat z = startNormal.length() * sin(fStackTheta * DEG2RAD) * cos(fSectorTheta * DEG2RAD);

            CoVec3 vPos(x, y, z);

            vecVertices.push_back(vPos);
            vecVertexNormals.push_back(vPos.normalize());
        }
    }

    for(Gint i = 0; i < nStack; i++)
    {
        for(Gint j = 0; j < nSector; j++)
        {
            // triangle 1
            m_vecPoints.push_back(vecVertices[i * nSector + j]); // stack 0 + sector 0
            m_vecPoints.push_back(vecVertices[(i + 1) * nSector + j]); // stack 1 + sector 0
            m_vecPoints.push_back(vecVertices[i * nSector + j + 1]); // stack 0 + sector 1

            // triangle 2
            m_vecPoints.push_back(vecVertices[i * nSector + j + 1]); // stack 0 + sector 1
            m_vecPoints.push_back(vecVertices[(i + 1) * nSector + j]); // stack 1 + sector 0
            m_vecPoints.push_back(vecVertices[(i + 1) * nSector + j + 1]); // stack 1 + sector 1
        }
    }

    // step 2 : triangle normal

    for(Gint i = 0; i < nStack; i++)
    {
        for(Gint j = 0; j < nSector; j++)
        {
            // triangle 1 normal
            CoVec3 vNormal1 = vecVertexNormals[i * nSector + j];
            CoVec3 vNormal2 = vecVertexNormals[(i + 1) * nSector + j];
            CoVec3 vNormal3 = vecVertexNormals[i * nSector + j + 1];

            m_vecVertexNormal.push_back(vNormal1);
            m_vecVertexNormal.push_back(vNormal2);
            m_vecVertexNormal.push_back(vNormal3);

            // triangle 2 normal
            vNormal1 = vecVertexNormals[i * nSector + j + 1];
            vNormal2 = vecVertexNormals[(i + 1) * nSector + j];
            vNormal3 = vecVertexNormals[(i + 1) * nSector + j + 1];

            m_vecVertexNormal.push_back(vNormal1);
            m_vecVertexNormal.push_back(vNormal2);
            m_vecVertexNormal.push_back(vNormal3);
        }
    }
}

void CoSphere::createSphereFlat()
{
    // step 1 : create vertice

    Gint n2PIDegree = 360;
    Gint nStackRatio = 3;
    Gint nSectorRatio = 3;
    Gint nStack = n2PIDegree / 2 / nStackRatio;
    Gint nSector = n2PIDegree / nSectorRatio;

    CoVec3 startPosition(m_vCenter[0], m_vCenter[1] + m_fRadius, m_vCenter[2]);
    CoVec3 startNormal = startPosition - m_vCenter;

    vector<CoVec3> vecVertices;
    for(Gint i = 0; i <= nStack; i++)
    {
        Gfloat fStackTheta = i * nStackRatio;

        // the condition as below that to avoid zero normal vector is need to be confirmed.
        if(i == 0)
        {
            fStackTheta = 0.01 * nStackRatio;
        }
        else if(i == nStack)
        {
            fStackTheta = (nStack - 0.01) * nStackRatio;
        }

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

    for(Gint i = 0; i < nStack; i++)
    {
        for(Gint j = 0; j < nSector; j++)
        {
            // triangle 1
            m_vecPoints.push_back(vecVertices[i * nSector + j]); // stack 0 + sector 0
            m_vecPoints.push_back(vecVertices[(i + 1) * nSector + j]); // stack 1 + sector 0
            m_vecPoints.push_back(vecVertices[i * nSector + j + 1]); // stack 0 + sector 1

            // triangle 2
            m_vecPoints.push_back(vecVertices[i * nSector + j + 1]); // stack 0 + sector 1
            m_vecPoints.push_back(vecVertices[(i + 1) * nSector + j]); // stack 1 + sector 0
            m_vecPoints.push_back(vecVertices[(i + 1) * nSector + j + 1]); // stack 1 + sector 1
        }
    }

    // step 2 : triangle normal

    for(Gint i = 0; i < nStack; i++)
    {
        for(Gint j = 0; j < nSector; j++)
        {
            // triangle 1 normal
            CoVec3 vPos1 = vecVertices[i * nSector + j];
            CoVec3 vPos2 = vecVertices[(i + 1) * nSector + j];
            CoVec3 vPos3 = vecVertices[i * nSector + j + 1];

            CoVec3 vNor32 = vPos3 - vPos2;
            CoVec3 vNor12 = vPos1 - vPos2;

            CoVec3 vNormal = vNor32.cross(vNor12);
            vNormal.normalize();  // It need to be confirmed.

            m_vecVertexNormal.push_back(vNormal);
            m_vecVertexNormal.push_back(vNormal);
            m_vecVertexNormal.push_back(vNormal);

            // triangle 2 normal
            vPos1 = vecVertices[i * nSector + j + 1];
            vPos2 = vecVertices[(i + 1) * nSector + j];
            vPos3 = vecVertices[(i + 1) * nSector + j + 1];

            vNor32 = vPos3 - vPos2;
            vNor12 = vPos1 - vPos2;

            vNormal = vNor32.cross(vNor12);
            vNormal.normalize(); // It need to be confirmed.

            m_vecVertexNormal.push_back(vNormal);
            m_vecVertexNormal.push_back(vNormal);
            m_vecVertexNormal.push_back(vNormal);
        }
    }
}

/**
 * @brief This function is used to opengl coordinate opengl to create vertice of sphere.
 *        z-axis is screen.
 *        y-axis is up.
 *        x-aixs is right.
 */
void CoSphere::createIndexedSphere()
{
    // step 1 : creating vertice

    Gint n2PIDegree = 360;
    Gint nStackRatio = 5;
    Gint nSectorRatio = 5;
    Gint nStack = n2PIDegree / 2 / nStackRatio;
    Gint nSector = n2PIDegree / nSectorRatio;

    CoVec3 startPosition(m_vCenter[0], m_vCenter[1] + m_fRadius, m_vCenter[2]);
    CoVec3 startNormal = startPosition - m_vCenter;

    for(Gint i = 0; i <= nStack; i++)
    {
        Gfloat fStackTheta = i * nStackRatio;

        // the condition as below that to avoid zero normal vector is need to be confirmed.
        if(i == 0)
        {
            fStackTheta = 0.01 * nStackRatio;
        }
        else if(i == nStack)
        {
            fStackTheta = (nStack - 0.01) * nStackRatio;
        }

        for(Gint j = 0; j < nSector; j++)
        {
            Gfloat fSectorTheta = j * nSectorRatio;

            Gfloat x = startNormal.length() * sin(fStackTheta * DEG2RAD) * sin(fSectorTheta * DEG2RAD);
            Gfloat y = startNormal.length() * cos(fStackTheta * DEG2RAD);
            Gfloat z = startNormal.length() * sin(fStackTheta * DEG2RAD) * cos(fSectorTheta * DEG2RAD);

            CoVec3 vPos(x, y, z);

            m_vecPoints.push_back(vPos);
        }
    }

    // step 2 : creating vertice index

    for(Gint i = 0; i < nStack; i++)
    {
        for(Gint j = 0; j < nSector; j++)
        {
            // triangle 1
            m_vecVertexIndices.push_back(i * nSector + j); // stack 0 + sector 0
            m_vecVertexIndices.push_back((i + 1) * nSector + j); // stack 1 + sector 0
            m_vecVertexIndices.push_back(i * nSector + j + 1); // stack 0 + sector 1

            // triangle 2
            m_vecVertexIndices.push_back(i * nSector + j + 1); // stack 0 + sector 1
            m_vecVertexIndices.push_back((i + 1) * nSector + j); // stack 1 + sector 0
            m_vecVertexIndices.push_back((i + 1) * nSector + j + 1); // stack 1 + sector 1
        }
    }

    // step 2 : creating vertex normal

    for(Gint i = 0; i < m_vecPoints.size(); i++)
    {
        CoVec3 vNormal = m_vecPoints[i];
        vNormal.normalize();
        m_vecVertexNormal.push_back(vNormal);
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

std::vector<CoVec3> CoSphere::getNormals()
{
    return m_vecVertexNormal;
}

std::vector<Gint> CoSphere::getVertexIndice()
{
    return m_vecVertexIndices;
}
