#ifndef CODEFAULTSHADERPROGRAM_H
#define CODEFAULTSHADERPROGRAM_H

#include "coshaderprogram.h"

class CoDefaultShaderProgram : public CoShaderProgram
{
public:
    CoDefaultShaderProgram();
    ~CoDefaultShaderProgram();

    void getUniform() override;
};

#endif // CODEFAULTSHADERPROGRAM_H
