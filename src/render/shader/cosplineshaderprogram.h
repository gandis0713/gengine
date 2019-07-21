#ifndef COSPLINESHADERPROGRAM_H
#define COSPLINESHADERPROGRAM_H

#include "coshaderprogram.h"

class CoSplineShaderProgram : public CoShaderProgram
{
public:
    CoSplineShaderProgram();
    ~CoSplineShaderProgram();

    void getUniform() override;
};

#endif // COSPLINESHADERPROGRAM_H
