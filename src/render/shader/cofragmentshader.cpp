#include "cofragmentshader.h"

#include "dedefaultfragmentshader.h"

CoFragmentShader::CoFragmentShader()
    : CoShader()
{
    initializeShader();
}

CoFragmentShader::~CoFragmentShader()
{

}

void CoFragmentShader::initializeShader()
{
    initType();
    initSource();
    compile();
}

void CoFragmentShader::initType()
{
    m_eType = EShaderType::eFragment;
}

void CoFragmentShader::initSource()
{
    m_strSource = strDefaultFragShader;
}
