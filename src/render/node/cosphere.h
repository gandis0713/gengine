#ifndef COSPHERE_H
#define COSPHERE_H

#include "coshape.h"


class GANDISENGINE CoSphere : public CoShape
{
public:
    CoSphere();
    CoSphere(CoVec3 vCenter, Gfloat fRadius);
    virtual ~CoSphere();

    void setCenter(CoVec3 vPosition);
    void setRadius(Gfloat fRadius);

protected:
    void createSphere();

private:
    CoVec3 m_vCenter;
    Gfloat m_fRadius;
};

#endif // COSPHERE_H
