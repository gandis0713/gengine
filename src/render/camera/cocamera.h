#ifndef COCAMERA_H
#define COCAMERA_H

#include "comatrix4x4.h"
#include "covector3.h"
#include "coenginedefine.h"

#include <QObject>


class GANDISENGINE CoCamera : public QObject
{
    Q_OBJECT
public:
    explicit CoCamera();
    virtual ~CoCamera();

    void setTarget(const CoVec3 &vec);
    CoVec3 getTarget();
    void setPosition(const CoVec3 &vec);
    CoVec3 getPosition();
    void setUp(const CoVec3 &vec);
    CoVec3 getUp();
    void setMatrix(const CoMat4x4& mat);
    CoMat4x4 getMatrix();

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

    virtual void update() = 0;
signals:
    void signalUpdated();

protected:
    CoMat4x4 m_matCamera;

    CoVec3 m_vecTarget;
    CoVec3 m_vecPosition;
    CoVec3 m_vecUp;

    Gfloat m_fLeft;
    Gfloat m_fRight;
    Gfloat m_fBottom;
    Gfloat m_fTop;
    Gfloat m_fNear;
    Gfloat m_fFar;


};

#endif // COCAMERA_H
