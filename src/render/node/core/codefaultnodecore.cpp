#include "codefaultnodecore.h"
#include "codefaultshaderprogram.h"

#include "dedefaultvertexshader.h"
#include "dedefaultfragmentshader.h"

CoDefaultNodeCore::CoDefaultNodeCore(CoNode* pNode, CoCamera *pCamera)
    : CoNodeCore(pNode, pCamera)
{
}


CoDefaultNodeCore::~CoDefaultNodeCore()
{

}

void CoDefaultNodeCore::initialize()
{
    m_pVAO = new CoVertexArrayObject();
    m_pVBO = new CoVertexBufferObject();
    m_pCBO = new CoVertexBufferObject();

    m_pShaderProgram = new CoDefaultShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, strDefaultFragShader);
    m_pShaderProgram->AddShaders(EShaderType::eVertex, strDefaultVertexShader);
    m_pShaderProgram->link();
    m_pShaderProgram->setUniform();
    m_pShaderProgram->setAttribute();

    m_pVBO->gen();
    m_pVBO->bind();
    m_pVBO->setAllocate(&m_pNode->getPoints()[0], m_pNode->getSize() * 3 * sizeof(Gfloat));

    m_pCBO->gen();
    m_pCBO->bind();
    m_pVBO->setAllocate(&m_pNode->getColors()[0], m_pNode->getSize() * 3 * sizeof(Gfloat));

    m_pVAO->gen();
    m_pVAO->bind();

    m_pVBO->bind();
    m_pShaderProgram->enableAttributeArray(m_pShaderProgram->m_nVertexID);
    m_pShaderProgram->setAttributeBuffer(m_pShaderProgram->m_nVertexID, 3, 0);

    m_pCBO->bind();
    m_pShaderProgram->enableAttributeArray(m_pShaderProgram->m_nColorID);
    m_pShaderProgram->setAttributeBuffer(m_pShaderProgram->m_nColorID, 3, 0);

    m_pVAO->release();
}

void CoDefaultNodeCore::paint()
{
    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_pShaderProgram->m_nMatrixID, m_pCamera->getMatrix() * CoMat4x4());

    m_pVAO->bind();

    m_pNode->draw();
}
