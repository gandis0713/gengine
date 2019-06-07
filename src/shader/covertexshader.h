#ifndef COVERTEXSHADER_H
#define COVERTEXSHADER_H

#include "coshader.h"

class CoVertexShader : public CoShader
{
public:
    CoVertexShader();
    ~CoVertexShader();

protected:
    bool setShaderType() override;
    const GLchar* getShaderSource() override;
};

#endif // COVERTEXSHADER_H
