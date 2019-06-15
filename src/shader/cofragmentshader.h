#ifndef COFRAGMENTSHADER_H
#define COFRAGMENTSHADER_H

#include "coshader.h"

class CoFragmentShader : public CoShader
{
public:
    CoFragmentShader();
    ~CoFragmentShader() override;

protected:
    void initializeShader() override;
    void initType() override;
    void initSource() override;
};

#endif // COFRAGMENTSHADER_H
