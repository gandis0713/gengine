#include "coorthographiccamera.h"

#include "nomath.h"

CoOrthographicCamera::CoOrthographicCamera()
{
    m_fLeft = -5.f;
    m_fRight = 5.f;
    m_fBottom = -5.f;
    m_fTop = 5.f;

    setCamera();
}

CoOrthographicCamera::~CoOrthographicCamera()
{

}

void CoOrthographicCamera::update()
{
    setCamera();

    emit signalCameraUpdated();
}

void CoOrthographicCamera::setCamera()
{
    m_matProjection = NoMath::orthographic(m_fLeft, m_fRight, m_fBottom, m_fTop, m_fNear, m_fFar);
    m_matView = lookAt(m_vecPosition,
                       m_vecTarget,
                       m_vecUp);

    m_matCamera = m_matProjection * m_matView;
}

