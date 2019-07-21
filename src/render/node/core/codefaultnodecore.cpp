#include "codefaultnodecore.h"
#include "codefaultshaderprogram.h"

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
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/default_frag.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/default_vert.glsl");
    m_pShaderProgram->link();
    m_pShaderProgram->getUniform();

    m_pVBO->gen();
    m_pVBO->bind();
    m_pVBO->allocate(&m_pNode->getPoints()[0], m_pNode->getSize() * 3 * sizeof(Gfloat));

    m_pCBO->gen();
    m_pCBO->bind();
    m_pCBO->allocate(&m_pNode->getColors()[0], m_pNode->getSize() * 3 * sizeof(Gfloat));

    m_pVAO->gen();
    m_pVAO->bind();

    m_pVBO->bind();
    m_pShaderProgram->enableAttributeArray(VERTEX_IN_LAYOUT);
    m_pShaderProgram->setAttributeBuffer(VERTEX_IN_LAYOUT, 3, 0);

    m_pCBO->bind();
    m_pShaderProgram->enableAttributeArray(COLOR_IN_LAYOUT);
    m_pShaderProgram->setAttributeBuffer(COLOR_IN_LAYOUT, 3, 0);

    m_pVAO->release();
}

void CoDefaultNodeCore::paint()
{
    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_pShaderProgram->m_nMVPID, m_pCamera->getMatrix() * CoMat4x4());

    m_pVAO->bind();

    m_pNode->draw();
}
