#ifndef COPOINT_H
#define COPOINT_H

#include "conode.h"
#include "covector3.h"

class CoPoint : public CoNode
{
public:
    CoPoint();
    ~CoPoint();

    void setPoint(CoVec3 vPoint);

private:
    CoVec3 m_vPoint;
};

#endif // COPOINT_H
