#ifndef COSPLINESHADERPROGRAM_H
#define COSPLINESHADERPROGRAM_H

#include "coshaderprogram.h"

class CoSplineShaderProgram : public CoShaderProgram
{
public:
    CoSplineShaderProgram();
    ~CoSplineShaderProgram();

    void setUniform() override;
    void setAttribute() override;
};

#endif // COSPLINESHADERPROGRAM_H
