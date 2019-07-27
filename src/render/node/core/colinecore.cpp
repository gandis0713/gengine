#include "colinecore.h"
#include "coline.h"
#include "colineshaderprogram.h"


CoLineCore::CoLineCore()
{

}

CoLineCore::CoLineCore(CoNode* pNode, CoCamera *pCamera)
    : CoNodeCore(pNode, pCamera)
{
}


CoLineCore::~CoLineCore()
{

}

void CoLineCore::initialize()
{
    m_pVAO = new CoVertexArrayObject();
    m_pVBO = new CoVertexBufferObject();
    m_pCBO = new CoVertexBufferObject();

    m_pShaderProgram = new CoLineShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/line_frag.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eGeometry, ":resource/glsl/line_geom.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/line_vert.glsl");
    m_pShaderProgram->link();

    m_nMVPID = m_pShaderProgram->getUniformLocation("mvp");
    m_nRadiusID = m_pShaderProgram->getUniformLocation("radius");

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

void CoLineCore::paint()
{
    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_nMVPID, m_pCamera->getMatrix() * CoMat4x4());

    CoLine *pLine = static_cast<CoLine*>(m_pNode);
    m_pShaderProgram->setUniform1f(m_nRadiusID, pLine->getRadius());

    m_pVAO->bind();

    glDrawArrays(GL_LINE_STRIP, 0, pLine->getSize());
}
