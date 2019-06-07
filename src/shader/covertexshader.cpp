#include "covertexshader.h"

#include "dedefaultvertexshader.h"

CoVertexShader::CoVertexShader()
    : CoShader()
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

const GLchar* CoVertexShader::getShaderSource()
{
    return const_cast<CbChar*>(pDefaultVertexShader);
}
