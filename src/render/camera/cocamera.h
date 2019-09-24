#ifndef COCAMERA_H
#define COCAMERA_H

#include "comatrix4x4.h"
#include "covector4.h"
#include "covector3.h"
#include "covector2.h"
#include "deengine.h"

#include <QObject>


class GANDISENGINE CoCamera : public QObject
{
    Q_OBJECT
public:
    explicit CoCamera();
    virtual ~CoCamera();

    // initialize
    void setViewport(CoVec4 vViewport);

    void setMatrix(const CoMat4x4& mat);
    CoMat4x4 getCameraMat();

    virtual void update() = 0;
    virtual void setCamera() = 0;

    // lookup
    void setTarget(const CoVec3 &vec);
    CoVec3 getTarget();
    void setPosition(const CoVec3 &vec);
    CoVec3 getPosition();
    void setUp(const CoVec3 &vec);
    CoVec3 getUp();

    CoMat4x4 getViewMat();

    // projection
    void setLeftPosition(const Gfloat &value);
    void setRightPosition(const Gfloat &value);
    void setBottomPosition(const Gfloat &value);
    void setTopPosition(const Gfloat &value);
    void setNearPosition(const Gfloat &value);
    void setFarPosition(const Gfloat &value);
    void setClipSpace(const Gfloat &left,
                      const Gfloat &right,
                      const Gfloat &bottom,
                      const Gfloat &top,
                      const Gfloat &near,
                      const Gfloat &far);
    CoMat4x4 getProjectionMat();

    // move, zoom, rotate
    void orbit(CoVec2 vCurPos, CoVec2 vPrePos);
    void move(CoVec2 vCurPos, CoVec2 vPrePos);
    void zoom(Gfloat fRate);


signals:
    void signalCameraUpdated();

protected:
    CoMat4x4 lookAt(CoVec3 position, CoVec3 target, CoVec3 up);

protected:
    CoMat4x4 m_matCamera;
    CoMat4x4 m_matProjection;
    CoMat4x4 m_matView;

    CoVec3 m_vecTarget;
    CoVec3 m_vecPosition;
    CoVec3 m_vecUp;

    Gfloat m_fLeft;
    Gfloat m_fRight;
    Gfloat m_fBottom;
    Gfloat m_fTop;
    Gfloat m_fNear;
    Gfloat m_fFar;

    CoVec4 m_vViewport;


};

#endif // COCAMERA_H
