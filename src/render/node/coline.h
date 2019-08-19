#ifndef COLINE_H
#define COLINE_H

#include "coshape.h"

class GANDISENGINE CoLine : public CoShape
{
public:
    CoLine();
    CoLine(CoVec3 vStart, CoVec3 vEnd);
    ~CoLine();

    void setPoint(CoVec3 vStart, CoVec3 vEnd);    

    void setWidth(Gfloat fWidth);
    Gfloat getWidth();

protected:
    Gfloat m_fWidth;
};

#endif // COLINE_H
