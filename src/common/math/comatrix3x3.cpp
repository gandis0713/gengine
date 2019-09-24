#include "comatrix3x3.h"

#include "demath.h"

CoMat3x3::CoMat3x3()
{
    identity();
}

CoMat3x3::CoMat3x3(const Gfloat mat[9])
{
    set(mat);
}

CoMat3x3& CoMat3x3::identity()
{
    mat[0] = mat[4] = mat[8] = 1.0f;
    mat[1] = mat[2] = mat[3] = mat[5] = mat[6] = mat[7] = 0.0f;

    return *this;
}

void CoMat3x3::set(const Gfloat mat[9])
{
    this->mat[0] = mat[0];
    this->mat[1] = mat[1];
    this->mat[2] = mat[2];
    this->mat[3] = mat[3];
    this->mat[4] = mat[4];
    this->mat[5] = mat[5];
    this->mat[6] = mat[6];
    this->mat[7] = mat[7];
    this->mat[8] = mat[8];
}

CoMat3x3 CoMat3x3::getTranspose()
{
    Gfloat tmat[9];

    tmat[0] = mat[0];   tmat[1] = mat[3];   tmat[2] = mat[6];
    tmat[3] = mat[1];   tmat[4] = mat[4];   tmat[5] = mat[7];
    tmat[6] = mat[2];   tmat[7] = mat[5];   tmat[8] = mat[8];

    return tmat;
}

CoMat3x3& CoMat3x3::transpose()
{
    std::swap(mat[1],  mat[3]);
    std::swap(mat[2],  mat[6]);
    std::swap(mat[5],  mat[7]);

    return *this;
}

CoMat3x3& CoMat3x3::inverse()
{

    Gfloat tmpMat[9];

    tmpMat[0] = mat[4] * mat[8] - mat[5] * mat[7];
    tmpMat[1] = mat[2] * mat[7] - mat[1] * mat[8];
    tmpMat[2] = mat[1] * mat[5] - mat[2] * mat[4];
    tmpMat[3] = mat[5] * mat[6] - mat[3] * mat[8];
    tmpMat[4] = mat[0] * mat[8] - mat[2] * mat[6];
    tmpMat[5] = mat[2] * mat[3] - mat[0] * mat[5];
    tmpMat[6] = mat[3] * mat[7] - mat[4] * mat[6];
    tmpMat[7] = mat[1] * mat[6] - mat[0] * mat[7];
    tmpMat[8] = mat[0] * mat[4] - mat[1] * mat[3];

    Gfloat invertDeterminant = 1.0f / determinant();

    mat[0] = invertDeterminant * tmpMat[0];
    mat[1] = invertDeterminant * tmpMat[1];
    mat[2] = invertDeterminant * tmpMat[2];
    mat[3] = invertDeterminant * tmpMat[3];
    mat[4] = invertDeterminant * tmpMat[4];
    mat[5] = invertDeterminant * tmpMat[5];
    mat[6] = invertDeterminant * tmpMat[6];
    mat[7] = invertDeterminant * tmpMat[7];
    mat[8] = invertDeterminant * tmpMat[8];

    return *this;
}

Gfloat CoMat3x3::determinant()
{
    return mat[0] * (mat[4] * mat[8] - mat[5] * mat[7])
         - mat[1] * (mat[3] * mat[8] - mat[5] * mat[6])
         + mat[2] * (mat[3] * mat[7] - mat[4] * mat[6]);
}

CoVec3 CoMat3x3::angle()
{
    return CoVec3(); // need implementation;
}

Gfloat CoMat3x3::determinant(const Gfloat mat[9])
{
    return mat[0] * (mat[4] * mat[8] - mat[5] * mat[7])
         - mat[1] * (mat[3] * mat[8] - mat[5] * mat[6])
         + mat[2] * (mat[3] * mat[7] - mat[4] * mat[6]);
}

Gfloat CoMat3x3::determinant(const Gfloat& mat0, const Gfloat& mat1, const Gfloat& mat2,
                             const Gfloat& mat3, const Gfloat& mat4, const Gfloat& mat5,
                             const Gfloat& mat6, const Gfloat& mat7, const Gfloat& mat8)
{
    return mat0 * (mat4 * mat8 - mat5 * mat7)
         - mat1 * (mat3 * mat8 - mat5 * mat6)
         + mat2 * (mat3 * mat7 - mat4 * mat6);
}
