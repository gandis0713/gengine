#include "cosylinder.h"
#include "demath.h"
#include "delog.h"

CoSylinder::CoSylinder()
    : m_vCenter(0, 0, 0)
    , m_fRadius(10)
    , m_fLength(30)
{
    m_eShaderProgramType = EShaderProgramType::eSylinder;

    createSylinder();
//    createIndexedSphere();
}

CoSylinder::CoSylinder(CoVec3 vCenter,
                       Gfloat fRadius,
                       Gfloat fLength)
    : m_vCenter(vCenter)
    , m_fRadius(fRadius)
    , m_fLength(fLength)
{
    m_eShaderProgramType = EShaderProgramType::eSylinder;

    createSylinder();
//    createIndexedSphere();
}

CoSylinder::~CoSylinder()
{

}

/**
 * @brief This function is used to opengl coordinate opengl to create vertice of sylinder.
 *        z-axis is screen.
 *        y-axis is up.
 *        x-aixs is right.
 */
void CoSylinder::createSylinder()
{
    // step 1 : creating top circle

    // step 1 - 1 : create vertex
    Gint nDividedDegree = 10;
    Gint nCount = 360 / nDividedDegree;
    CoVec3 vNormal(0, m_fRadius, 0);
    for(Gint nIndex = 0; nIndex < nCount; nIndex++)
    {
        Gfloat fZPosition = m_fLength / 2;

        CoVec3 vPosition1(vNormal.length() * sin(nDividedDegree * nIndex * DEG2RAD),
                          vNormal.length() * cos(nDividedDegree * nIndex * DEG2RAD),
                          fZPosition);

        CoVec3 vPosition2(vNormal.length() * sin(nDividedDegree * (nIndex + 1) * DEG2RAD),
                          vNormal.length() * cos(nDividedDegree * (nIndex + 1) * DEG2RAD),
                          fZPosition);

        m_vecPoints.push_back(CoVec3(0, 0, fZPosition));
        m_vecPoints.push_back(vPosition1);
        m_vecPoints.push_back(vPosition2);
    }

    // step 1 - 2 : create vertex normal

    for(Gint nIndex = 0; nIndex < nCount; nIndex++)
    {
        CoVec3 vVertexNormal(0, 0, 1);
        vVertexNormal.normalize();

        m_vecVertexNormal.push_back(vVertexNormal);
        m_vecVertexNormal.push_back(vVertexNormal);
        m_vecVertexNormal.push_back(vVertexNormal);
    }


    // step 2 : creating bottom circle

    // step 2 - 1 : create vertex
    for(Gint nIndex = 0; nIndex < nCount; nIndex++)
    {
        Gfloat fZPosition = -m_fLength / 2;

        CoVec3 vPosition1(vNormal.length() * sin(nDividedDegree * nIndex * DEG2RAD),
                          vNormal.length() * cos(nDividedDegree * nIndex * DEG2RAD),
                          fZPosition);

        CoVec3 vPosition2(vNormal.length() * sin(nDividedDegree * (nIndex + 1) * DEG2RAD),
                          vNormal.length() * cos(nDividedDegree * (nIndex + 1) * DEG2RAD),
                          fZPosition);

        m_vecPoints.push_back(CoVec3(0, 0, fZPosition));
        m_vecPoints.push_back(vPosition1);
        m_vecPoints.push_back(vPosition2);
    }

    // step 2 - 2 : create vertex normal

    for(Gint nIndex = 0; nIndex < nCount; nIndex++)
    {
        CoVec3 vVertexNormal(0, 0, -1);
        vVertexNormal.normalize();

        m_vecVertexNormal.push_back(vVertexNormal);
        m_vecVertexNormal.push_back(vVertexNormal);
        m_vecVertexNormal.push_back(vVertexNormal);
    }

    // step 3 : creating side area

    Gint nDividedCount = 36;
    Gfloat fHalfLength = m_fLength / 2;
    Gfloat fDiff = m_fLength / nDividedCount;

    for(Gint nZIndex = 0; nZIndex < nDividedCount; nZIndex++)
    {
        Gfloat fTopZPosition1 = fHalfLength - (nZIndex * fDiff);
        Gfloat fTopZPosition2 = fHalfLength - ((nZIndex + 1) * fDiff);

        for(Gint nCircleIndex = 0; nCircleIndex < nCount; nCircleIndex++)
        {
            CoVec3 vPosition1(vNormal.length() * sin(nDividedDegree * nCircleIndex * DEG2RAD),
                              vNormal.length() * cos(nDividedDegree * nCircleIndex * DEG2RAD),
                              fTopZPosition1);

            CoVec3 vPosition2(vNormal.length() * sin(nDividedDegree * (nCircleIndex + 1) * DEG2RAD),
                              vNormal.length() * cos(nDividedDegree * (nCircleIndex + 1) * DEG2RAD),
                              fTopZPosition1);

            CoVec3 vPosition3(vNormal.length() * sin(nDividedDegree * nCircleIndex * DEG2RAD),
                              vNormal.length() * cos(nDividedDegree * nCircleIndex * DEG2RAD),
                              fTopZPosition2);

            m_vecPoints.push_back(vPosition1);
            m_vecPoints.push_back(vPosition2);
            m_vecPoints.push_back(vPosition3);

            CoVec3 vNormal1(vNormal.length() * sin(nDividedDegree * nCircleIndex * DEG2RAD),
                            vNormal.length() * cos(nDividedDegree * nCircleIndex * DEG2RAD),
                            0);

            CoVec3 vNormal2(vNormal.length() * sin(nDividedDegree * (nCircleIndex + 1) * DEG2RAD),
                            vNormal.length() * cos(nDividedDegree * (nCircleIndex + 1) * DEG2RAD),
                            0);

            m_vecVertexNormal.push_back(vNormal1);
            m_vecVertexNormal.push_back(vNormal2);
            m_vecVertexNormal.push_back(vNormal1);


            vPosition1 = CoVec3(vNormal.length() * sin(nDividedDegree * nCircleIndex * DEG2RAD),
                                vNormal.length() * cos(nDividedDegree * nCircleIndex * DEG2RAD),
                                fTopZPosition2);

            vPosition2 = CoVec3(vNormal.length() * sin(nDividedDegree * (nCircleIndex + 1) * DEG2RAD),
                                vNormal.length() * cos(nDividedDegree * (nCircleIndex + 1) * DEG2RAD),
                                fTopZPosition1);

            vPosition3 = CoVec3(vNormal.length() * sin(nDividedDegree * (nCircleIndex + 1) * DEG2RAD),
                                vNormal.length() * cos(nDividedDegree * (nCircleIndex + 1) * DEG2RAD),
                                fTopZPosition2);

            m_vecPoints.push_back(vPosition1);
            m_vecPoints.push_back(vPosition2);
            m_vecPoints.push_back(vPosition3);

            m_vecVertexNormal.push_back(vNormal1);
            m_vecVertexNormal.push_back(vNormal2);
            m_vecVertexNormal.push_back(vNormal2);
        }
    }
}

/**
 * @brief This function is used to opengl coordinate opengl to create vertice of sylinder.
 *        z-axis is screen.
 *        y-axis is up.
 *        x-aixs is right.
 */
void CoSylinder::createIndexedSylinder()
{

}

void CoSylinder::setCenter(CoVec3 vPosition)
{
    m_vCenter = vPosition;
}

void CoSylinder::setRadius(Gfloat fRadius)
{
    m_fRadius = fRadius;
}

void CoSylinder::setLength(Gfloat fLength)
{
    m_fLength = fLength;
}

std::vector<CoVec3> CoSylinder::getNormals()
{
    return m_vecVertexNormal;
}

std::vector<Gint> CoSylinder::getVertexIndice()
{
    return m_vecVertexIndices;
}
