#ifndef COPOINT_H
#define COPOINT_H

#include "conode.h"
#include "covector3.h"

class CoPoint : public CoNode
{
public:
    CoPoint();

private:
    CoVec3 vPoint;
};

#endif // COPOINT_H
