#ifndef COCIRCLE_H
#define COCIRCLE_H

#include "coshape.h"

class GANDISENGINE CoCircle : public CoShape
{
public:
    CoCircle();
    CoCircle(CoVec3 vPosition, Gfloat fRadius);
    virtual ~CoCircle();

    void setCenter(CoVec3 vPosition);
    void setRadius(Gfloat fRadius);

protected:
    void createCircle();

private:
    CoVec3 m_vCenter;
    Gfloat m_fRadius;
};

#endif // COCIRCLE_H
