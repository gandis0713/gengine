#ifndef CODEFAULTSHADERPROGRAM_H
#define CODEFAULTSHADERPROGRAM_H

#include "coshaderprogram.h"

class CoDefaultShaderProgram : public CoShaderProgram
{
public:
    CoDefaultShaderProgram();
    ~CoDefaultShaderProgram();

    void setUniform() override;
    void setAttribute() override;
};

#endif // CODEFAULTSHADERPROGRAM_H
