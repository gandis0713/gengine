#include "covertexshader.h"

#include "dedefaultvertexshader.h"

CoVertexShader::CoVertexShader()
    : CoShader()
{
    initializeShader();
}

CoVertexShader::~CoVertexShader()
{

}

void CoVertexShader::initializeShader()
{
    initType();
    initSource();
    compile();
}

void CoVertexShader::initType()
{
    m_eType = EShaderType::eVertex;
}

void CoVertexShader::initSource()
{
    m_strSource = strDefaultVertexShader;
}
