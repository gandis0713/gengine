#ifndef COMATRIX3X3_H
#define COMATRIX3X3_H

#include "dedatatype.h"
#include "covector3.h"

class CoMat3x3
{
public:
    CoMat3x3();
    CoMat3x3(const Gfloat mat[9]);

    CoMat3x3& identity();
    void set(const Gfloat mat[9]);
    CoMat3x3 getTranspose();
    CoMat3x3& transpose();
    CoMat3x3& invert();
    Gfloat determinant();
    CoVec3 angle();

private:
    float mat[9];
};

#endif // COMATRIX3X3_H
