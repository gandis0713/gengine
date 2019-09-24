#ifndef COMATRIX3X3_H
#define COMATRIX3X3_H

#include "dedatatype.h"
#include "covector3.h"
#include "deengine.h"

class GANDISENGINE CoMat3x3
{
public:
    CoMat3x3();
    CoMat3x3(const Gfloat mat[9]);

    CoMat3x3& identity();
    void set(const Gfloat mat[9]);
    CoMat3x3 getTranspose();
    CoMat3x3& transpose();
    CoMat3x3& inverse();
    Gfloat determinant();
    CoVec3 angle();

    static Gfloat determinant(const Gfloat mat[9]);
    static Gfloat determinant(const Gfloat& mat0, const Gfloat& mat1, const Gfloat& mat2,
                       const Gfloat& mat3, const Gfloat& mat4, const Gfloat& mat5,
                       const Gfloat& mat6, const Gfloat& mat7, const Gfloat& mat8);

private:
    float mat[9];
};

#endif // COMATRIX3X3_H
