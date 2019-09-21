#ifndef SPLINE3D_H
#define SPLINE3D_H

#include "covector3.h"
#include "spline1d.h"

class Spline3D
{
public:
    Spline3D();
    ~Spline3D();

    void setPoints(const std::vector<CoVec3> &vecPoints);
    CoVec3 getPoints(Gfloat fNormalizedPoint);

private:
    Spline1D m_XSpline;
    Spline1D m_YSpline;
    Spline1D m_ZSpline;
};

#endif // SPLINE3D_H
