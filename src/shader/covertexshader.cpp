#include "covertexshader.h"

#include "dedefaultvertexshader.h"

CoVertexShader::CoVertexShader()
    : CoShader()
{
}

CoVertexShader::~CoVertexShader()
{
}

CbString CoVertexShader::getDefaultSource()
{
    return strDefaultVertexShader;
}
