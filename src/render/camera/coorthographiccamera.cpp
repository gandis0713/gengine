#include "coorthographiccamera.h"

#include "nomath.h"

CoOrthographicCamera::CoOrthographicCamera()
{
    m_fLeft = -5.f;
    m_fRight = 5.f;
    m_fBottom = -5.f;
    m_fTop = 5.f;

    CoMat4x4 matPerspective = NoMath::orthographic(m_fLeft, m_fRight, m_fBottom, m_fTop, m_fNear, m_fFar);
    CoMat4x4 matLookAt = NoMath::lookAt(m_vecPosition,
                                        m_vecTarget,
                                        m_vecUp);

    m_matCamera = matPerspective * matLookAt;
}

CoOrthographicCamera::~CoOrthographicCamera()
{

}

void CoOrthographicCamera::update()
{
    CoMat4x4 matPerspective = NoMath::orthographic(m_fLeft, m_fRight, m_fBottom, m_fTop, m_fNear, m_fFar);
    CoMat4x4 matLookAt = NoMath::lookAt(m_vecPosition,
                                        m_vecTarget,
                                        m_vecUp);

    m_matCamera = matPerspective * matLookAt;

    emit signalCameraUpdated();
}
