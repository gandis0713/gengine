#include "cocatmullsplinenodecore.h"
#include "cocatmullsplineshaderprogram.h"
#include "cocatmullspline.h"

CoCatmullSplineNodeCore::CoCatmullSplineNodeCore()
{

}

CoCatmullSplineNodeCore::CoCatmullSplineNodeCore(CoNode* pNode, CoCamera *pCamera)
    : CoLineNodeCore(pNode, pCamera)
{

}
CoCatmullSplineNodeCore::~CoCatmullSplineNodeCore()
{

}

void CoCatmullSplineNodeCore::initialize()
{
    m_pVAO = new CoVertexArrayObject();
    m_pVBO = new CoVertexBufferObject();
    m_pCBO = new CoVertexBufferObject();

    m_pShaderProgram = new CoCatmullSplineShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/catmull_spline_vert.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/catmull_spline_frag.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eGeometry, ":resource/glsl/catmull_spline_geom.glsl");
    m_pShaderProgram->link();

    m_nMVPID = m_pShaderProgram->getUniformLocation("mvp");
    m_nWidthID = m_pShaderProgram->getUniformLocation("width");
    m_nAlpha = m_pShaderProgram->getUniformLocation("alpha");

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

void CoCatmullSplineNodeCore::paint()
{
    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_nMVPID, m_pCamera->getMatrix() * CoMat4x4());

    CoCatmullSpline *pSpline = dynamic_cast<CoCatmullSpline*>(m_pNode);
    m_pShaderProgram->setUniform1f(m_nWidthID, pSpline->getWidth());
    m_pShaderProgram->setUniform1f(m_nAlpha, pSpline->getAlpha());

    m_pVAO->bind();

    m_pNode->draw();
}
