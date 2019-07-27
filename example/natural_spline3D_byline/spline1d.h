#ifndef SPLINE1D_H
#define SPLINE1D_H

#include "dedatatype.h"
#include <vector>

class Spline1D
{
public:
    Spline1D();
    ~Spline1D();

    void setPoints(const std::vector<Gfloat> &vecPoints);
    Gfloat getPoint(Gfloat fNormalizedPoint);

private:
    void build();

private:
    std::vector<Gfloat> m_vecPoints;
    std::vector<Gfloat> m_vecCoefA;
    std::vector<Gfloat> m_vecCoefB;
    std::vector<Gfloat> m_vecCoefC;
    std::vector<Gfloat> m_vecCoefD;
};

#endif // SPLINE1D_H
