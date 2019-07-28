#ifndef COCIRCLE_H
#define COCIRCLE_H

#include "coshape.h".h"

class CoCircle : public CoShape
{
public:
    CoCircle();
    CoCircle(CoVec3 vPoint, Gfloat fRadius);
    ~CoCircle();

    void setPoint(CoVec3 vPoint);
    void setRadius(CoVec3 vPoint);
};

#endif // COCIRCLE_H
