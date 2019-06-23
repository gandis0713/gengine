#ifndef COMATRIX4X4_H
#define COMATRIX4X4_H

#include "dedatatype.h"
#include "covector3.h"

class CoMat4x4
{
public:
    CoMat4x4();
    CoMat4x4(const Gfloat mat[16]);
    CoMat4x4(Gfloat mat00, Gfloat mat01, Gfloat mat02, Gfloat mat03,
             Gfloat mat04, Gfloat mat05, Gfloat mat06, Gfloat mat07,
             Gfloat mat08, Gfloat mat09, Gfloat mat10, Gfloat mat11,
             Gfloat mat12, Gfloat mat13, Gfloat mat14, Gfloat mat15);

    CoMat4x4& identity();
    void set(const Gfloat mat[16]);
    void set(Gfloat m00, Gfloat m01, Gfloat m02, Gfloat m03,
             Gfloat m04, Gfloat m05, Gfloat m06, Gfloat m07,
             Gfloat m08, Gfloat m09, Gfloat m10, Gfloat m11,
             Gfloat m12, Gfloat m13, Gfloat m14, Gfloat m15);
    CoMat4x4 getTranspose();
    CoMat4x4& transpose();
    CoMat4x4& invert();
    Gfloat determinant();
    CoVec3 angle();

    CoMat4x4 operator+(const CoMat4x4& mat);
    CoMat4x4 operator-(const CoMat4x4& mat);
    CoMat4x4& operator+=(const CoMat4x4& mat);
    CoMat4x4& operator-=(const CoMat4x4& mat);
    CoMat4x4 operator*(const CoMat4x4& mat);
    CoMat4x4& operator*=(const CoMat4x4& mat);

    Gfloat operator[](Gint index) const;
    Gfloat& operator[](Gint index);

private:
    Gfloat mat[16];
};

#endif // COMATRIX4X4_H
