#ifndef COVERTEXSHADER_H
#define COVERTEXSHADER_H

#include "coshader.h"

class CoVertexShader : public CoShader
{
public:
    CoVertexShader();
    ~CoVertexShader() override;

protected:
    void initializeShader() override;
    void initType() override;
    void initSource() override;
};

#endif // COVERTEXSHADER_H
