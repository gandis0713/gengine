#ifndef COMATRIX2X2_H
#define COMATRIX2X2_H

#include "dedatatype.h"

class CoMat2x2
{
public:
    CoMat2x2();
    CoMat2x2(const Gfloat mat[4]);

    CoMat2x2& identity();
    void set(const Gfloat mat[4]);
    CoMat2x2 getTranspose();
    CoMat2x2& transpose();
    CoMat2x2& invert();
    Gfloat getDeterminant();
    Gfloat getAngle();

private:
    Gfloat mat[4];
};


#endif // COMATRIX2X2_H
