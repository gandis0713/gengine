#include "cocatmullsplinecore.h"
#include "cocatmullsplineshaderprogram.h"
#include "cocatmullspline.h"

CoCatmullSplineCore::CoCatmullSplineCore()
{

}

CoCatmullSplineCore::CoCatmullSplineCore(CoNode* pNode,
                                         CoCamera *pCamera,
                                         CoLight *pLight)
    : CoLineCore(pNode, pCamera, pLight)
{

}
CoCatmullSplineCore::~CoCatmullSplineCore()
{

}

void CoCatmullSplineCore::initialize()
{

    createObject();
    createShaderProgram();
    setUniformLocation();
    bindObject();

}

void CoCatmullSplineCore::paint()
{
    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_nMVPID, m_pCamera->getCameraMat() * CoMat4x4());

    CoCatmullSpline *pSpline = static_cast<CoCatmullSpline*>(m_pNode);
    m_pShaderProgram->setUniform1f(m_nWidthID, pSpline->getWidth());
    m_pShaderProgram->setUniform1f(m_nAlpha, pSpline->getAlpha());

    CoVec3 vDiffuseColor = pSpline->getColor();
    glUniform3f(m_nDiffuseColorID, vDiffuseColor[0], vDiffuseColor[1], vDiffuseColor[2]);

    m_pVertexArrayObject->bind();

    glDrawArrays(GL_LINE_STRIP_ADJACENCY, 0, pSpline->getSize());
}

void CoCatmullSplineCore::createObject()
{
    CoShapeCore::createObject();
}

void CoCatmullSplineCore::createShaderProgram()
{
    m_pShaderProgram = new CoShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/catmull_spline_vert.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/catmull_spline_frag.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eGeometry, ":resource/glsl/catmull_spline_geom.glsl");
    m_pShaderProgram->link();
}

void CoCatmullSplineCore::bindObject()
{

    CoCatmullSpline *pSpline = static_cast<CoCatmullSpline*>(m_pNode);
    m_pVertexBufferObject->gen();
    m_pVertexBufferObject->bind();
    m_pVertexBufferObject->allocate(&pSpline->getPoints()[0], pSpline->getSize() * 3 * sizeof(Gfloat));

    m_pVertexArrayObject->gen();
    m_pVertexArrayObject->bind();

    m_pVertexBufferObject->bind();
    m_pShaderProgram->enableAttributeVertexArray(VERTEX_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(VERTEX_IN_LAYOUT, 3, 0);

    m_pVertexArrayObject->release();
}

void CoCatmullSplineCore::setUniformLocation()
{
    CoShapeCore::setUniformLocation();

    m_nWidthID = m_pShaderProgram->getUniformLocation("width");
    m_nAlpha = m_pShaderProgram->getUniformLocation("alpha");
}

