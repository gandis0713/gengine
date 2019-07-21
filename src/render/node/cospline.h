#ifndef COSPLINE_H
#define COSPLINE_H

#include "conode.h"

class GANDISENGINE CoSpline : public CoNode
{
public:
    CoSpline(const std::vector<CoVec3> vecPoints);
    ~CoSpline();

    void draw() override;
    void setPoints(const std::vector<CoVec3> vecPoints);
};

#endif // COSPLINE_H
