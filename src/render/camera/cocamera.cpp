#include "cocamera.h"

CoCamera::CoCamera()
    : m_vecTarget(0.f, 0.f, 0.f)
    , m_vecPosition(0.f, 0.f, 5.f)
    , m_vecUp(0.f, 1.f, 0.f)
    , m_fLeft(-0.5f)
    , m_fRight(0.5f)
    , m_fBottom(-0.5f)
    , m_fTop(0.5f)
    , m_fNear(1.0f)
    , m_fFar(10.0f)
{
}

CoCamera::~CoCamera()
{

}

void CoCamera::update()
{
}

void CoCamera::setTarget(const CoVec3 &vec)
{
    m_vecTarget = vec;
}

CoVec3 CoCamera::getTarget()
{
    return m_vecTarget;
}

void CoCamera::setPosition(const CoVec3 &vec)
{
    m_vecPosition = vec;
}

CoVec3 CoCamera::getPosition()
{
    return m_vecPosition;
}

void CoCamera::setUp(const CoVec3 &vec)
{
    m_vecUp = vec;
}

CoVec3 CoCamera::getUp()
{
    return m_vecUp;
}

void CoCamera::setMatrix(const CoMat4x4& mat)
{
    m_matCamera = mat;
}

CoMat4x4 CoCamera::getMatrix()
{
    return m_matCamera;
}

void CoCamera::setLeftPosition(const Gfloat &value)
{
    m_fLeft = value;
}
void CoCamera::setRightPosition(const Gfloat &value)
{
    m_fRight = value;
}

void CoCamera::setBottomPosition(const Gfloat &value)
{
    m_fBottom = value;
}

void CoCamera::setTopPosition(const Gfloat &value)
{
    m_fTop = value;
}

void CoCamera::setNearPosition(const Gfloat &value)
{
    m_fNear = value;
}
void CoCamera::setFarPosition(const Gfloat &value)
{
    m_fFar = value;
}

void CoCamera::setClipSpace(const Gfloat &left,
                            const Gfloat &right,
                            const Gfloat &bottom,
                            const Gfloat &top,
                            const Gfloat &near,
                            const Gfloat &far)
{
    m_fLeft = left;
    m_fRight = right;
    m_fBottom = bottom;
    m_fTop = top;
    m_fNear = near;
    m_fFar = far;
}
