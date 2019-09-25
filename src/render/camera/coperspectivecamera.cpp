#include "coperspectivecamera.h"

#include "nomath.h"

CoPerspectiveCamera::CoPerspectiveCamera()
{    
    m_fLeft = -0.1f;
    m_fRight = 0.1f;
    m_fBottom = -0.1f;
    m_fTop = 0.1f;

    m_vecTarget = CoVec3(0.f, 0.f, 0.f);
    m_vecPosition = CoVec3(0.f, 0.f, 1000.f);
    m_vecUp = CoVec3(0.f, 1.f, 0.f);

    m_fNear = 0.1f;
    m_fFar = 1000.0f;

    setCamera();
}

CoPerspectiveCamera::~CoPerspectiveCamera()
{

}

void CoPerspectiveCamera::update()
{
    setCamera();

    emit signalCameraUpdated();
}


void CoPerspectiveCamera::setCamera()
{
    CoMat4x4 matPerspective = NoMath::perspective(m_fLeft, m_fRight, m_fBottom, m_fTop, m_fNear, m_fFar);
    CoMat4x4 matLookAt = lookAt(m_vecPosition,
                                m_vecTarget,
                                m_vecUp);

    m_matCamera = matPerspective * matLookAt;
}
