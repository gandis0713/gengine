#ifndef COMATRIX4X4_H
#define COMATRIX4X4_H

#include "dedatatype.h"
#include "covector3.h"

class CoMat4x4
{
public:
    CoMat4x4();
    CoMat4x4(const Gfloat mat[16]);

    CoMat4x4& identity();
    void set(const Gfloat mat[16]);
    CoMat4x4 getTranspose();
    CoMat4x4& transpose();
    CoMat4x4& invert();
    Gfloat determinant();
    CoVec3 angle();

private:
    float mat[16];
};

#endif // COMATRIX4X4_H
