#ifndef COLINE_H
#define COLINE_H

#include "conode.h"

class GANDISENGINE CoLine : public CoNode
{
public:
    CoLine();
    CoLine(CoVec3 vStart, CoVec3 vEnd);
    ~CoLine();

    void setPoint(CoVec3 vStart, CoVec3 vEnd);

    void setRadius(Gfloat fWidth);
    Gfloat getRadius();

protected:
    Gfloat m_fRadius;
};

#endif // COLINE_H
