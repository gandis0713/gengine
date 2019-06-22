#include "comatrix4x4.h"

#include "demath.h"
#include "nomath.h"

CoMat4x4::CoMat4x4()
{
    identity();
}

CoMat4x4::CoMat4x4(const Gfloat mat[16])
{
    set(mat);
}

CoMat4x4& CoMat4x4::identity()
{
    mat[0] = mat[4] = mat[8] = 1.0f;
    mat[1] = mat[2] = mat[3] = mat[5] = mat[6] = mat[7] = 0.0f;

    return *this;
}

void CoMat4x4::set(const Gfloat mat[16])
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
    this->mat[9] = mat[9];
    this->mat[10] = mat[10];
    this->mat[11] = mat[11];
    this->mat[12] = mat[12];
    this->mat[13] = mat[13];
    this->mat[14] = mat[14];
    this->mat[15] = mat[15];
}

CoMat4x4 CoMat4x4::getTranspose()
{
    Gfloat tmat[16];

    tmat[0] = mat[0];    tmat[1] = mat[4];    tmat[2] = mat[8];     tmat[3] = mat[12];
    tmat[4] = mat[1];    tmat[5] = mat[5];    tmat[6] = mat[9];     tmat[7] = mat[13];
    tmat[8] = mat[2];    tmat[9] = mat[6];    tmat[10] = mat[10];   tmat[11] = mat[14];
    tmat[12] = mat[3];   tmat[13] = mat[7];   tmat[14] = mat[11];   tmat[15] = mat[15];

    return tmat;
}

CoMat4x4& CoMat4x4::transpose()
{
    std::swap(mat[1],  mat[4]);
    std::swap(mat[2],  mat[8]);
    std::swap(mat[3],  mat[12]);
    std::swap(mat[6],  mat[9]);
    std::swap(mat[7],  mat[13]);
    std::swap(mat[11], mat[14]);

    return *this;
}

CoMat4x4& CoMat4x4::invert()
{
    Gfloat tmpMat[16];

    tmpMat[0] = NoMath::determinant3x3(mat[5],mat[6],mat[7], mat[9],mat[10],mat[11], mat[13],mat[14],mat[15]);
    tmpMat[1] = NoMath::determinant3x3(mat[4],mat[6],mat[7], mat[8],mat[10],mat[11], mat[12],mat[14],mat[15]);
    tmpMat[2] = NoMath::determinant3x3(mat[4],mat[5],mat[7], mat[8],mat[9], mat[11], mat[12],mat[13],mat[15]);
    tmpMat[3] = NoMath::determinant3x3(mat[4],mat[5],mat[6], mat[8],mat[9], mat[10], mat[12],mat[13],mat[14]);

    tmpMat[4] = NoMath::determinant3x3(mat[1],mat[2],mat[3], mat[9],mat[10],mat[11], mat[13],mat[14],mat[15]);
    tmpMat[5] = NoMath::determinant3x3(mat[0],mat[2],mat[3], mat[8],mat[10],mat[11], mat[12],mat[14],mat[15]);
    tmpMat[6] = NoMath::determinant3x3(mat[0],mat[1],mat[3], mat[8],mat[9], mat[11], mat[12],mat[13],mat[15]);
    tmpMat[7] = NoMath::determinant3x3(mat[0],mat[1],mat[2], mat[8],mat[9], mat[10], mat[12],mat[13],mat[14]);

    tmpMat[8] = NoMath::determinant3x3(mat[1],mat[2],mat[3], mat[5],mat[6], mat[7],  mat[13],mat[14],mat[15]);
    tmpMat[9] = NoMath::determinant3x3(mat[0],mat[2],mat[3], mat[4],mat[6], mat[7],  mat[12],mat[14],mat[15]);
    tmpMat[10] = NoMath::determinant3x3(mat[0],mat[1],mat[3], mat[4],mat[5], mat[7],  mat[12],mat[13],mat[15]);
    tmpMat[11] = NoMath::determinant3x3(mat[0],mat[1],mat[2], mat[4],mat[5], mat[6],  mat[12],mat[13],mat[14]);

    tmpMat[12] = NoMath::determinant3x3(mat[1],mat[2],mat[3], mat[5],mat[6], mat[7],  mat[9], mat[10],mat[11]);
    tmpMat[13] = NoMath::determinant3x3(mat[0],mat[2],mat[3], mat[4],mat[6], mat[7],  mat[8], mat[10],mat[11]);
    tmpMat[14] = NoMath::determinant3x3(mat[0],mat[1],mat[3], mat[4],mat[5], mat[7],  mat[8], mat[9], mat[11]);
    tmpMat[15] = NoMath::determinant3x3(mat[0],mat[1],mat[2], mat[4],mat[5], mat[6],  mat[8], mat[9], mat[10]);

    Gfloat invertDeterminant = 1.0f / determinant();

    mat[0] =  invertDeterminant * tmpMat[0];
    mat[1] = -invertDeterminant * tmpMat[4];
    mat[2] =  invertDeterminant * tmpMat[8];
    mat[3] = -invertDeterminant * tmpMat[12];

    mat[4] = -invertDeterminant * tmpMat[1];
    mat[5] =  invertDeterminant * tmpMat[5];
    mat[6] = -invertDeterminant * tmpMat[9];
    mat[7] =  invertDeterminant * tmpMat[13];

    mat[8] =  invertDeterminant * tmpMat[2];
    mat[9] = -invertDeterminant * tmpMat[6];
    mat[10]=  invertDeterminant * tmpMat[10];
    mat[11]= -invertDeterminant * tmpMat[14];

    mat[12]= -invertDeterminant * tmpMat[3];
    mat[13]=  invertDeterminant * tmpMat[7];
    mat[14]= -invertDeterminant * tmpMat[11];
    mat[15]=  invertDeterminant * tmpMat[15];

    return *this;
}

Gfloat CoMat4x4::determinant()
{
    return mat[0] * NoMath::determinant3x3(mat[5],mat[6],mat[7], mat[9],mat[10],mat[11], mat[13],mat[14],mat[15]) -
           mat[1] * NoMath::determinant3x3(mat[4],mat[6],mat[7], mat[8],mat[10],mat[11], mat[12],mat[14],mat[15]) +
           mat[2] * NoMath::determinant3x3(mat[4],mat[5],mat[7], mat[8],mat[9], mat[11], mat[12],mat[13],mat[15]) -
           mat[3] * NoMath::determinant3x3(mat[4],mat[5],mat[6], mat[8],mat[9], mat[10], mat[12],mat[13],mat[14]);
}

CoVec3 CoMat4x4::angle()
{
    return CoVec3(); // need implementation;
}
