#ifndef COLINE_H
#define COLINE_H

#include "coshape.h".h"

class GANDISENGINE CoLine : public CoShape
{
public:
    CoLine();
    CoLine(CoVec3 vStart, CoVec3 vEnd);
    ~CoLine();

    void setPoint(CoVec3 vStart, CoVec3 vEnd);

    void setRadius(Gfloat fRadius);
    Gfloat getRadius();

protected:
    Gfloat m_fRadius;
};

#endif // COLINE_H
