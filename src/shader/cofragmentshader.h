#ifndef COFRAGMENTSHADER_H
#define COFRAGMENTSHADER_H

#include "coshader.h"

class CoFragmentShader : public CoShader
{
public:
    CoFragmentShader();
    ~CoFragmentShader();

protected:
    CbString getDefaultSource() override;
};

#endif // COFRAGMENTSHADER_H
