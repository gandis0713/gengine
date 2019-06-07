#include "covertexshader.h"

#include "dedefaultvertexshader.h"

CoVertexShader::CoVertexShader(QOpenGLFunctions_2_1 *pGLFunctions)
    : CoShader(pGLFunctions)
{
    initialize();
}

CoVertexShader::~CoVertexShader()
{
}


bool CoVertexShader::setShaderType()
{
    m_eType = EShaderType::eVertex;

    return true;
}

bool CoVertexShader::setShaderSource()
{
    m_pShaderSource = const_cast<CbChar*>(pDefaultVertexShader);

    return true;
}
