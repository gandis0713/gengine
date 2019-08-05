#include "copolygoncore.h"
#include "copolygon.h"

CoPolygonCore::CoPolygonCore()
{

}

CoPolygonCore::CoPolygonCore(CoNode* pNode, CoCamera *pCamera)
    : CoShapeCore(pNode, pCamera)
{
}


CoPolygonCore::~CoPolygonCore()
{

}

void CoPolygonCore::initialize()
{
    m_pVAO = new CoVertexArrayObject();
    m_pVBO = new CoVertexBufferObject();
    m_pCBO = new CoVertexBufferObject();

    m_pShaderProgram = new CoShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/polygon_frag.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eGeometry, ":resource/glsl/polygon_geom.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/polygon_vert.glsl");
    m_pShaderProgram->link();

    m_nMVPID = m_pShaderProgram->getUniformLocation("mvp");

    CoPolygon *pPolygon = static_cast<CoPolygon*>(m_pNode);

    m_pVBO->gen();
    m_pVBO->bind();
    m_pVBO->allocate(&pPolygon->getPoints()[0], pPolygon->getSize() * 3 * sizeof(Gfloat));

    m_pCBO->gen();
    m_pCBO->bind();
    m_pCBO->allocate(&pPolygon->getColors()[0], pPolygon->getSize() * 3 * sizeof(Gfloat));

    m_pVAO->gen();
    m_pVAO->bind();

    m_pVBO->bind();
    m_pShaderProgram->enableAttributeVertexArray(VERTEX_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(VERTEX_IN_LAYOUT, 3, 0);

    m_pCBO->bind();
    m_pShaderProgram->enableAttributeVertexArray(COLOR_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(COLOR_IN_LAYOUT, 3, 0);

    m_pVAO->release();
}

void CoPolygonCore::paint()
{
    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_nMVPID, m_pCamera->getCameraMat() * CoMat4x4());

    m_pVAO->bind();

    CoPolygon *pPolygon = static_cast<CoPolygon*>(m_pNode);
    glDrawArrays(GL_TRIANGLES, 0, pPolygon->getSize());
}
