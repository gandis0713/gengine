#include "cocamera.h"

CoCamera::CoCamera()
    : m_vecTarget(0.f, 0.f, 0.f)
    , m_vecPosition(0.f, 0.f, 1000.f)
    , m_vecUp(0.f, 1.f, 0.f)
    , m_fLeft(-0.5f)
    , m_fRight(0.5f)
    , m_fBottom(-0.5f)
    , m_fTop(0.5f)
    , m_fNear(0.1f)
    , m_fFar(10000.0f)
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

CoMat4x4 CoCamera::getCameraMat()
{
    return m_matCamera;
}

CoMat4x4 CoCamera::getProjectionMat()
{
    return m_matProjection;
}
CoMat4x4 CoCamera::getViewMat()
{
    return m_matView;
}

void CoCamera::orbit(CoVec2 vCurPos, CoVec2 vPrePos)
{
    CoVec3 vDir;
    vDir[0] = vCurPos[0] - vPrePos[0];
    vDir[1] = vCurPos[1] - vPrePos[1];
    vDir[2] = 0;

    CoVec3 vScreenNormal(0, 0, 1);
    CoVec3 vRotationNormal = vDir.cross(vScreenNormal);

    Gfloat fDegreeX = vRotationNormal.dot(CoVec3(1, 0, 0));
    Gfloat fDegreeY = vRotationNormal.dot(CoVec3(0, 1, 0));

    CoVec3 vCameraPosition = getPosition();
    CoVec3 vCameraUpNormalized = getUp().normalize();
    CoVec3 vCameraTarget = getTarget();

    CoVec3 vCameraToTarget = (vCameraPosition - vCameraTarget);
    CoVec3 vCameraToTargetNormalized = (vCameraPosition - vCameraTarget).normalize();
    CoVec3 vCameraRightNormalized = (vCameraUpNormalized.cross(vCameraToTargetNormalized)).normalize();

    CoMat4x4 matRotateYaw;
    CoMat4x4 matRotatePitch;

    matRotatePitch = matRotatePitch.rotate(fDegreeX, vCameraRightNormalized);
    vCameraToTarget = matRotatePitch * vCameraToTarget;
    vCameraToTarget += vCameraTarget;

    matRotateYaw = matRotateYaw.rotate(fDegreeY, vCameraUpNormalized);
    vCameraToTarget = matRotateYaw * vCameraToTarget;
    vCameraToTarget += vCameraTarget;

    vCameraToTargetNormalized = vCameraToTarget;
    vCameraToTargetNormalized.normalize();
    vCameraUpNormalized = (vCameraToTargetNormalized.cross(vCameraRightNormalized)).normalize();

    m_vecPosition = vCameraToTarget;
    m_vecUp = vCameraUpNormalized;
    m_vecTarget = vCameraTarget;
}

void CoCamera::move(CoVec2 vCurPos, CoVec2 vPrePos)
{
    CoVec3 vDir;
    vDir[0] = vCurPos[0] - vPrePos[0];
    vDir[1] = vCurPos[1] - vPrePos[1];

    Gfloat fHorizontal = m_fRight - m_fLeft;
    Gfloat fVertical = m_fTop - m_fBottom;

    Gfloat fViewportHorizontal = m_vViewport[2] - m_vViewport[0];
    Gfloat fViewportVertical = m_vViewport[3] - m_vViewport[1];

    Gfloat fHorizontalRate = fHorizontal / fViewportHorizontal;
    Gfloat fVerticalRate = fVertical / fViewportVertical;

    m_fLeft -= vDir[0] * fHorizontalRate;
    m_fRight -= vDir[0] * fHorizontalRate;
    m_fTop -= vDir[1] * fVerticalRate;
    m_fBottom -= vDir[1] * fVerticalRate;
}

void CoCamera::zoom(Gfloat fRate)
{
    Gfloat fHorizontal = m_fRight - m_fLeft;
    Gfloat fVertical = m_fTop - m_fBottom;

    Gfloat fViewportHorizontal = m_vViewport[2] - m_vViewport[0];
    Gfloat fViewportVertical = m_vViewport[3] - m_vViewport[1];

    Gfloat fHorizontalRate = fHorizontal / fViewportHorizontal;
    Gfloat fVerticalRate = fVertical / fViewportVertical;

    m_fLeft -= fRate * fHorizontalRate;
    m_fRight += fRate * fHorizontalRate;
    m_fTop += fRate * fVerticalRate;
    m_fBottom -= fRate * fVerticalRate;
}

void CoCamera::setViewport(CoVec4 vViewport)
{
    m_vViewport = vViewport;
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

/**
 * @brief
 * Matrix Indexing
 * [  0   1   2   3 ]
 * [  4   5   6   7 ]
 * [  8   9  10  11 ]
 * [ 12  13  14  15 ]
 *
 * Look at matrix by MT * MR
 * [      1       0       0   0 ]   [ xAxis.x  yAxis.x  zAxis.x 0 ]
 * [      0       1       0   0 ] * [ xAxis.y  yAxis.y  zAxis.y 0 ]
 * [      0       0       1   0 ]   [ xAxis.z  yAxis.z  zAxis.z 0 ]
 * [ -Eye.x  -Eye.y  -Eye.z   1 ]   [       0        0        0 1 ]
 */
CoMat4x4 CoCamera::lookAt(CoVec3 position, CoVec3 target, CoVec3 up)
{
    up.normalize();

    CoVec3 forward = position - target;
    forward.normalize();

    CoVec3 left = up.cross(forward);
    left.normalize();

    up = forward.cross(left);
    up.normalize();

    CoMat4x4 matView;
    matView[0] = left[0];
    matView[4] = left[1];
    matView[8] = left[2];
    matView[12] = -position.dot(left);

    matView[1] = up[0];
    matView[5] = up[1];
    matView[9] = up[2];
    matView[13] = -position.dot(up);

    matView[2] = forward[0];
    matView[6] = forward[1];
    matView[10] = forward[2];
    matView[14] = -position.dot(forward);

    matView[3] = 0.f;
    matView[7] = 0.f;
    matView[11] = 0.f;
    matView[15] = 1.f;

    return matView;
}
