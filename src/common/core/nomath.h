#ifndef NOMATHHELPER_H
#define NOMATHHELPER_H

#include "dedatatype.h"
#include "comatrix4x4.h"

namespace NoMath
{

CoMat4x4 perspective(Gfloat left, Gfloat right, Gfloat bottom, Gfloat top, Gfloat near, Gfloat far);
CoMat4x4 perspective(Gfloat fovVertical, Gfloat aspectRatio, Gfloat front, Gfloat back);
CoMat4x4 orthographic(Gfloat left, Gfloat right, Gfloat bottom, Gfloat top, Gfloat near, Gfloat far);
}


#endif // NOMATHHELPER_H
