#ifndef COLIGHT_H
#define COLIGHT_H

#include "dedatatype.h"
#include "covector3.h"

class CoLight
{
public:
    CoLight();
    ~CoLight();

    void setPower(Gfloat fPower);
    void setColor(CoVec3 vColor);
    void setPosition(CoVec3 vPosition);
    Gfloat getPower();
    CoVec3 getColor();
    CoVec3 getPosition();

private:
    Gfloat m_fPower;
    CoVec3 m_vColor;
    CoVec3 m_vPosition;
};

#endif // COLIGHT_H
