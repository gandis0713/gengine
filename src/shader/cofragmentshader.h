#ifndef COFRAGMENTSHADER_H
#define COFRAGMENTSHADER_H

#include "coshader.h"

class CoFragmentShader : public CoShader
{
public:
    CoFragmentShader();
    ~CoFragmentShader();

protected:
    bool setShaderType() override;
    const GLchar* getShaderSource() override;
};

#endif // COFRAGMENTSHADER_H
