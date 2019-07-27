#ifndef COCATMULLSPLINE_H
#define COCATMULLSPLINE_H

#include "coline.h"

class GANDISENGINE CoCatmullSpline : public CoLine
{
public:
    CoCatmullSpline(const std::vector<CoVec3> vecPoints);
    ~CoCatmullSpline();

    void draw() override;
    void setPoints(const std::vector<CoVec3> vecPoints);
};

#endif // COCATMULLSPLINE_H
