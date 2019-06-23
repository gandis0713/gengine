#include "coperspectivecamera.h"

#include "nomath.h"
#include <QDebug>

CoPerspectiveCamera::CoPerspectiveCamera()
{
    CoMat4x4 matPerspective = NoMath::perspective(m_fLeft, m_fRight, m_fBottom, m_fTop, m_fNear, m_fFar);
    CoMat4x4 matLookAt = NoMath::lookAt(m_vecPosition,
                                        m_vecTarget,
                                        m_vecUp);

    m_matCamera = matPerspective * matLookAt;
}

CoPerspectiveCamera::~CoPerspectiveCamera()
{

}

void CoPerspectiveCamera::update()
{
    CoMat4x4 matPerspective = NoMath::perspective(m_fLeft, m_fRight, m_fBottom, m_fTop, m_fNear, m_fFar);
    CoMat4x4 matLookAt = NoMath::lookAt(m_vecPosition,
                                        m_vecTarget,
                                        m_vecUp);

    m_matCamera = matPerspective * matLookAt;

    emit signalUpdated();
}
