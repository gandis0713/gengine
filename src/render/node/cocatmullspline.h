#ifndef COCATMULLSPLINE_H
#define COCATMULLSPLINE_H

#include "coline.h"

class GANDISENGINE CoCatmullSpline : public CoLine
{
public:
    CoCatmullSpline();
    CoCatmullSpline(const std::vector<CoVec3> vecPoints);
    ~CoCatmullSpline();

    void setPoints(const std::vector<CoVec3> vecPoints);

    void setAlpha(Gfloat fAlpha);
    Gfloat getAlpha();

protected:
    Gfloat m_fAlpha;
};

#endif // COCATMULLSPLINE_H
