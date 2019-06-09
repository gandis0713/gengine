#include "cofragmentshader.h"

#include "dedefaultfragmentshader.h"

CoFragmentShader::CoFragmentShader()
    : CoShader()
{
}

CoFragmentShader::~CoFragmentShader()
{

}

CbString CoFragmentShader::getDefaultSource()
{
    return strDefaultFragShader;
}
