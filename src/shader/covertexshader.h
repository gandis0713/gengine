#ifndef COVERTEXSHADER_H
#define COVERTEXSHADER_H

#include "coshader.h"

class CoVertexShader : public CoShader
{
public:
    CoVertexShader(QOpenGLFunctions_2_1 *pGLFunctions);
    ~CoVertexShader();

protected:
    bool setShaderType() override;
    bool setShaderSource() override;
};

#endif // COVERTEXSHADER_H
