#ifndef COLINE_H
#define COLINE_H

#include "conode.h"

class GANDISENGINE CoLine : public CoNode
{
public:
    CoLine(CoVec3 vStart, CoVec3 vEnd);
    ~CoLine();

    void draw() override;

    void setPoint(CoVec3 vStart, CoVec3 vEnd);
};

#endif // COLINE_H
