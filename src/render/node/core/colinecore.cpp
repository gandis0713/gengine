#include "colinecore.h"
#include "coline.h"
#include "colineshaderprogram.h"


CoLineCore::CoLineCore()
{

}

CoLineCore::CoLineCore(CoNode* pNode,
                       CoCamera *pCamera,
                       CoLight *pLight)
    : CoShapeCore(pNode, pCamera, pLight)
{
}


CoLineCore::~CoLineCore()
{

}

void CoLineCore::initialize()
{
    m_pVertexArrayObject = new CoVertexArrayObject();
    m_pVertexBufferObject = new CoVertexBufferObject();
    m_pCBO = new CoVertexBufferObject();

    m_pShaderProgram = new CoLineShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/line_frag.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eGeometry, ":resource/glsl/line_geom.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/line_vert.glsl");
    m_pShaderProgram->link();

    m_nMVPID = m_pShaderProgram->getUniformLocation("mvp");
    m_nWidthID = m_pShaderProgram->getUniformLocation("width");

    CoLine *pLine = static_cast<CoLine*>(m_pNode);

    m_pVertexBufferObject->gen();
    m_pVertexBufferObject->bind();
    m_pVertexBufferObject->allocate(&pLine->getPoints()[0], pLine->getSize() * 3 * sizeof(Gfloat));

    m_pCBO->gen();
    m_pCBO->bind();
    m_pCBO->allocate(&pLine->getColor()[0], pLine->getSize() * 3 * sizeof(Gfloat));

    m_pVertexArrayObject->gen();
    m_pVertexArrayObject->bind();

    m_pVertexBufferObject->bind();
    m_pShaderProgram->enableAttributeVertexArray(VERTEX_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(VERTEX_IN_LAYOUT, 3, 0);

    m_pCBO->bind();
    m_pShaderProgram->enableAttributeVertexArray(COLOR_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(COLOR_IN_LAYOUT, 3, 0);

    m_pVertexArrayObject->release();
}

void CoLineCore::paint()
{
    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_nMVPID, m_pCamera->getCameraMat() * CoMat4x4());

    CoLine *pLine = static_cast<CoLine*>(m_pNode);
    m_pShaderProgram->setUniform1f(m_nWidthID, pLine->getWidth());

    m_pVertexArrayObject->bind();

    glDrawArrays(GL_LINE_STRIP, 0, pLine->getSize());
}
