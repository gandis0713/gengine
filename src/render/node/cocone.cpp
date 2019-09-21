#include "cocone.h"
#include "demath.h"
#include "delog.h"

CoCone::CoCone()
    : m_vCenter(0, 0, 0)
    , m_fRadius(10)
    , m_fLength(30)
{
    m_eShaderProgramType = EShaderProgramType::eCone;

    createSylinder();
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

    createSylinder();
//    createIndexedSphere();
}

CoCone::~CoCone()
{

}

/**
 * @brief This function is used to opengl coordinate opengl to create vertice of sylinder.
 *        z-axis is screen.
 *        y-axis is up.
 *        x-aixs is right.
 */
void CoCone::createSylinder()
{

}

/**
 * @brief This function is used to opengl coordinate opengl to create vertice of sylinder.
 *        z-axis is screen.
 *        y-axis is up.
 *        x-aixs is right.
 */
void CoCone::createIndexedSylinder()
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
