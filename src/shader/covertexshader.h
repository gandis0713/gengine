#ifndef COVERTEXSHADER_H
#define COVERTEXSHADER_H

#include "coshader.h"

class CoVertexShader : public CoShader
{
public:
    CoVertexShader();
    ~CoVertexShader();

protected:
    CbString getDefaultSource() override;
};

#endif // COVERTEXSHADER_H
