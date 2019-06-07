#ifndef COFRAGMENTSHADER_H
#define COFRAGMENTSHADER_H

#include "coshader.h"

class CoFragmentShader : public CoShader
{
public:
    CoFragmentShader(QOpenGLFunctions_2_1 *pGLFunctions);
    ~CoFragmentShader();

protected:
    bool setShaderType() override;
    bool setShaderSource() override;
};

#endif // COFRAGMENTSHADER_H
