#include "cosylinder.h"
#include "demath.h"
#include "delog.h"

CoSylinder::CoSylinder()
    : m_vCenter(0, 0, 0)
    , m_fRadius(10)
    , m_fLength(10)
{
    m_eShaderProgramType = EShaderProgramType::eSylinder;

    createSylinder();
//    createIndexedSphere();
}

CoSylinder::CoSylinder(CoVec3 vCenter, Gfloat fRadius)
    : m_vCenter(vCenter)
    , m_fRadius(fRadius)
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
