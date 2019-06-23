#include "nomath.h"
#include "demath.h"

#include <QDebug>

namespace NoMath
{
Gfloat determinant2x2(const Gfloat mat[4])
{
    return mat[0] * mat[3] - mat[1] * mat[2];
}
Gfloat determinant2x2(const Gfloat& mat0, const Gfloat& mat1,
                      const Gfloat& mat2, const Gfloat& mat3)
{
    return mat0 * mat3 - mat1 * mat2;
}
Gfloat determinant3x3(const Gfloat mat[9])
{
    return mat[0] * (mat[4] * mat[8] - mat[5] * mat[7])
         - mat[1] * (mat[3] * mat[8] - mat[5] * mat[6])
         + mat[2] * (mat[3] * mat[7] - mat[4] * mat[6]);
}

Gfloat determinant3x3(const Gfloat& mat0, const Gfloat& mat1, const Gfloat& mat2,
                      const Gfloat& mat3, const Gfloat& mat4, const Gfloat& mat5,
                      const Gfloat& mat6, const Gfloat& mat7, const Gfloat& mat8)
{
    return mat0 * (mat4 * mat8 - mat5 * mat7)
         - mat1 * (mat3 * mat8 - mat5 * mat6)
         + mat2 * (mat3 * mat7 - mat4 * mat6);
}


CoMat4x4 perspective(Gfloat left, Gfloat right, Gfloat bottom, Gfloat top, Gfloat near, Gfloat far)
{
    CoMat4x4 mat;

    mat[0]  =  2 * near / (right - left);
    mat[5]  =  2 * near / (top - bottom);
    mat[8]  =  (right + left) / (right - left);
    mat[9]  =  (top + bottom) / (top - bottom);
    mat[10] = -(far + near) / (far - near);
    mat[11] = -1;
    mat[14] = -(2 * far * near) / (far - near);
    mat[15] =  0;

    return mat;
}

CoMat4x4 perspective(Gfloat fovVertical, Gfloat aspectRatio, Gfloat front, Gfloat back)
{
    Gfloat tangent = std::tanf(fovVertical/2 * DEG2RAD);
    Gfloat height = front * tangent;
    Gfloat width = height * aspectRatio;

    return perspective(-width, width, -height, height, front, back);
}

CoMat4x4 lookAt(CoVec3 position, CoVec3 target, CoVec3 up)
{
    up.normalize();

    CoVec3 forward = position - target;
    forward.normalize();

    CoVec3 left = up.cross(forward);
    left.normalize();

    up = forward.cross(left);
    up.normalize();

    CoMat4x4 matView;
    matView[0] = left[0];
    matView[4] = left[1];
    matView[8] = left[2];
    matView[12] = -position.dot(left);

    matView[1] = up[0];
    matView[5] = up[1];
    matView[9] = up[2];
    matView[13] = -position.dot(up);

    matView[2] = forward[0];
    matView[6] = forward[1];
    matView[10] = forward[2];
    matView[14] = -position.dot(forward);

    matView[3] = 0.f;
    matView[7] = 0.f;
    matView[11] = 0.f;
    matView[15] = 1.f;

    return matView;
}
}
