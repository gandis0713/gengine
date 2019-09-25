#include "coorthographiccamera.h"

#include "nomath.h"

CoOrthographicCamera::CoOrthographicCamera()
{
    m_fLeft = -100.f;
    m_fRight = 100.f;
    m_fBottom = -100.f;
    m_fTop = 100.f;

    m_vecTarget = CoVec3(0.f, 0.f, 0.f);
    m_vecPosition = CoVec3(0.f, 0.f, 100.f);
    m_vecUp = CoVec3(0.f, 1.f, 0.f);

    m_fNear = 0.f;
    m_fFar = 1000.0f;

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

