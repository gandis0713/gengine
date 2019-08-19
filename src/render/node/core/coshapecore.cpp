#include "coshapecore.h"

CoShapeCore::CoShapeCore()
{

}

CoShapeCore::CoShapeCore(CoNode* pNode,
                         CoCamera *pCamera,
                         CoLight *pLight)
    :CoNodeCore(pNode, pCamera, pLight)
    ,m_pVertexArrayObject(NULL)
    ,m_pVertexBufferObject(NULL)
{
}

CoShapeCore::~CoShapeCore()
{

}

void CoShapeCore::createObject()
{
    m_pVertexArrayObject = new CoVertexArrayObject();
    m_pVertexBufferObject = new CoVertexBufferObject();
}

void CoShapeCore::createShaderProgram()
{

}

void CoShapeCore::bindObject()
{

}

void CoShapeCore::setUniformLocation()
{
    m_nMVPID = m_pShaderProgram->getUniformLocation("mvp");
    m_nMID = m_pShaderProgram->getUniformLocation("m");
    m_nVID = m_pShaderProgram->getUniformLocation("v");

    m_nLightPosID = m_pShaderProgram->getUniformLocation("lightPosition");
    m_nLightColorID = m_pShaderProgram->getUniformLocation("lightColor");
    m_nLightPowerID = m_pShaderProgram->getUniformLocation("lightPower");

    m_nDiffuseColorID = m_pShaderProgram->getUniformLocation("diffuseColor");
    m_nAmbientColorID = m_pShaderProgram->getUniformLocation("ambientColor");
    m_nSpecularColorID = m_pShaderProgram->getUniformLocation("specularColor");
}
