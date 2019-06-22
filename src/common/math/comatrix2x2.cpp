#include "comatrix2x2.h"
#include "demath.h"

CoMat2x2::CoMat2x2()
{
    identity();
}

CoMat2x2::CoMat2x2(const Gfloat mat[4])
{
    set(mat);
}

CoMat2x2& CoMat2x2::identity()
{
    mat[0] = mat[3] = 1.f;
    mat[1] = mat[2] = 0.f;
    return *this;
}

void CoMat2x2::set(const Gfloat mat[4])
{
    this->mat[0] = mat[0];
    this->mat[1] = mat[1];
    this->mat[2] = mat[2];
    this->mat[3] = mat[3];
}

CoMat2x2 CoMat2x2::getTranspose()
{
    Gfloat tmat[4];

    tmat[0] = mat[0];   tmat[1] = mat[2];
    tmat[2] = mat[1];   tmat[3] = mat[3];

    return tmat;
}

CoMat2x2& CoMat2x2::transpose()
{
    std::swap(mat[1], mat[2]);
    return *this;
}

CoMat2x2& CoMat2x2::invert()
{
    Gfloat invertDeterminant = 1.0f / getDeterminant();
    Gfloat tmpMat0 = mat[0];

    mat[0] = invertDeterminant * mat[3];
    mat[1] = invertDeterminant * -mat[2];
    mat[2] = invertDeterminant * -mat[1];
    mat[3] = invertDeterminant * tmpMat0;

    return *this;
}

Gfloat CoMat2x2::getDeterminant()
{
    return mat[0] * mat[3] - mat[1] * mat[2];
}

Gfloat CoMat2x2::getAngle()
{
    return std::atan2f(mat[1], mat[0]) * RAD2DEG;
}
