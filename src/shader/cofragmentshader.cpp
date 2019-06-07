#include "cofragmentshader.h"

#include "dedefaultfragmentshader.h"

CoFragmentShader::CoFragmentShader()
    : CoShader()
{
    initialize();
}

CoFragmentShader::~CoFragmentShader()
{

}

bool CoFragmentShader::setShaderType()
{
    m_eType = EShaderType::eFragment;

    return true;
}

const GLchar* CoFragmentShader::getShaderSource()
{
    return const_cast<CbChar*>(pDefaultFragShader);
}
