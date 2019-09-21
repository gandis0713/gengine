#include "cocone.h"
#include "demath.h"
#include "delog.h"

CoCone::CoCone()
    : m_vCenter(0, 0, 0)
    , m_fRadius(10)
    , m_fLength(30)
{
    m_eShaderProgramType = EShaderProgramType::eCone;

    createCone();
//    createIndexedSphere();
}

CoCone::CoCone(CoVec3 vCenter,
                       Gfloat fRadius,
                       Gfloat fLength)
    : m_vCenter(vCenter)
    , m_fRadius(fRadius)
    , m_fLength(fLength)
{
    m_eShaderProgramType = EShaderProgramType::eCone;

    createCone();
//    createIndexedSphere();
}

CoCone::~CoCone()
{

}

/**
 * @brief This function is used to opengl coordinate to create vertice of cone.
 *        z-axis is screen.
 *        y-axis is up.
 *        x-aixs is right.
 */
void CoCone::createCone()
{
    // step 1 : creating bottom circle

    Gint nDividedDegree = 10;
    Gint nCount = 360 / nDividedDegree;
    CoVec3 vNormal(0, m_fRadius, 0);

    for(Gint nIndex = 0; nIndex < nCount; nIndex++)
    {
        CoVec3 vPosition1(0, 0, 0);
        CoVec3 vPosition2(vNormal.length() * cos(nIndex * nDividedDegree * DEG2RAD),
                          vNormal.length() * sin(nIndex * nDividedDegree * DEG2RAD),
                          0);

        CoVec3 vPosition3(vNormal.length() * cos((nIndex + 1) * nDividedDegree * DEG2RAD),
                          vNormal.length() * sin((nIndex + 1) * nDividedDegree * DEG2RAD),
                          0);

        m_vecPoints.push_back(vPosition1);
        m_vecPoints.push_back(vPosition2);
        m_vecPoints.push_back(vPosition3);

        CoVec3 vVertexNormal(0, 0, -1);

        m_vecVertexNormal.push_back(vVertexNormal);
        m_vecVertexNormal.push_back(vVertexNormal);
        m_vecVertexNormal.push_back(vVertexNormal);
    }

    // step 2 : triangle of inside on cone

    for(Gint nIndex = 0; nIndex < nCount; nIndex++)
    {
        CoVec3 vPosition1(0, 0, m_fLength);
        CoVec3 vPosition2(vNormal.length() * cos(nIndex * nDividedDegree * DEG2RAD),
                          vNormal.length() * sin(nIndex * nDividedDegree * DEG2RAD),
                          0);

        CoVec3 vPosition3(vNormal.length() * cos((nIndex + 1) * nDividedDegree * DEG2RAD),
                          vNormal.length() * sin((nIndex + 1) * nDividedDegree * DEG2RAD),
                          0);

        m_vecPoints.push_back(vPosition1);
        m_vecPoints.push_back(vPosition2);
        m_vecPoints.push_back(vPosition3);

        CoVec3 vVertexNormal1(0, 0, 1);
        CoVec3 vVertexNormal2 = vPosition2;
        vVertexNormal2.normalize();
        CoVec3 vVertexNormal3 = vPosition3;
        vVertexNormal3.normalize();

        m_vecVertexNormal.push_back(vVertexNormal1);
        m_vecVertexNormal.push_back(vVertexNormal2);
        m_vecVertexNormal.push_back(vVertexNormal3);
    }
}

/**
 * @brief This function is used to opengl coordinate to create vertice of cone.
 *        z-axis is screen.
 *        y-axis is up.
 *        x-aixs is right.
 */
void CoCone::createIndexedCone()
{

}

void CoCone::setCenter(CoVec3 vPosition)
{
    m_vCenter = vPosition;
}

void CoCone::setRadius(Gfloat fRadius)
{
    m_fRadius = fRadius;
}

void CoCone::setLength(Gfloat fLength)
{
    m_fLength = fLength;
}

std::vector<CoVec3> CoCone::getNormals()
{
    return m_vecVertexNormal;
}

std::vector<Gint> CoCone::getVertexIndice()
{
    return m_vecVertexIndices;
}
