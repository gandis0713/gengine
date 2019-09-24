#include "nomath.h"
#include "demath.h"

namespace NoMath
{

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
    Gfloat tangent = qAtan(fovVertical/2 * DEG2RAD);
    Gfloat height = front * tangent;
    Gfloat width = height * aspectRatio;

    return perspective(-width, width, -height, height, front, back);
}

CoMat4x4 orthographic(Gfloat left, Gfloat right, Gfloat bottom, Gfloat top, Gfloat near, Gfloat far)
{
    CoMat4x4 mat;

    mat[0]  =  2 / (right - left);
    mat[5]  =  2 / (top - bottom);
    mat[10] = -2 / (far - near);
    mat[12] = -(right + left) / (right - left);
    mat[13] = -(top + bottom) / (top - bottom);
    mat[14] = -(far + near) / (far - near);

    return mat;
}
}
