#include "cofragmentshader.h"

#include "dedefaultfragmentshader.h"

CoFragmentShader::CoFragmentShader(QOpenGLFunctions_2_1 *pGLFunctions)
    : CoShader(pGLFunctions)
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

bool CoFragmentShader::setShaderSource()
{
    m_pShaderSource = const_cast<CbChar*>(pDefaultFragShader);

    return true;
}
