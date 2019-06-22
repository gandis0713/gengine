#include "nomath.h"

namespace NoMath
{
Gfloat determinant2x2(const Gfloat mat[4])
{
    return mat[0] * mat[3] - mat[1] * mat[2];
}
Gfloat determinant2x2(const Gfloat mat0, const Gfloat mat1,
                         const Gfloat mat2, const Gfloat mat3)
{
    return mat0 * mat3 - mat1 * mat2;
}
Gfloat determinant3x3(const Gfloat mat[9])
{
    return mat[0] * (mat[4] * mat[8] - mat[5] * mat[7])
         - mat[1] * (mat[3] * mat[8] - mat[5] * mat[6])
         + mat[2] * (mat[3] * mat[7] - mat[4] * mat[6]);
}

Gfloat determinant3x3(const Gfloat mat0, const Gfloat mat1, const Gfloat mat2,
                         const Gfloat mat3, const Gfloat mat4, const Gfloat mat5,
                         const Gfloat mat6, const Gfloat mat7, const Gfloat mat8)
{
    return mat0 * (mat4 * mat8 - mat5 * mat7)
         - mat1 * (mat3 * mat8 - mat5 * mat6)
         + mat2 * (mat3 * mat7 - mat4 * mat6);
}
}
