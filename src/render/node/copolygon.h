#ifndef COPOLYGON_H
#define COPOLYGON_H

#include "coshape.h"

class GANDISENGINE CoPolygon : public CoShape
{
public:
    CoPolygon();
    CoPolygon(const std::vector<CoVec3> vecPoints);
    ~CoPolygon();

    void setPoints(const std::vector<CoVec3> vecPoints);
};

#endif // COPOLYGON_H
