#include "cocirclecore.h"
#include "cocircle.h"
#include "coshaderprogram.h"
#include <QDebug>

CoCircleCore::CoCircleCore()
{

}

CoCircleCore::CoCircleCore(CoNode* pNode,
                           CoCamera *pCamera,
                           CoLight *pLight)
    : CoLineCore(pNode, pCamera, pLight)
{

}
CoCircleCore::~CoCircleCore()
{

}

void CoCircleCore::initialize()
{

    createObject();
    createShaderProgram();
    setUniformLocation();
    bindObject();

}

void CoCircleCore::paint()
{
    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_nMVPID, m_pCamera->getCameraMat() * CoMat4x4());

    CoCircle *pCircle = static_cast<CoCircle*>(m_pNode);

    CoVec3 vDiffuseColor = pCircle->getColor();
    glUniform3f(m_nDiffuseColorID, vDiffuseColor[0], vDiffuseColor[1], vDiffuseColor[2]);

    m_pVertexArrayObject->bind();

    glDrawArrays(GL_LINE_LOOP, 0, pCircle->getSize());
}


void CoCircleCore::createObject()
{
    CoShapeCore::createObject();
}

void CoCircleCore::createShaderProgram()
{
    m_pShaderProgram = new CoShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/circle_frag.glsl");
//    m_pShaderProgram->AddShaders(EShaderType::eGeometry, ":resource/glsl/circle_geom.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/circle_vert.glsl");
    m_pShaderProgram->link();
}

void CoCircleCore::bindObject()
{
    CoCircle *pCircle = static_cast<CoCircle*>(m_pNode);

    m_pVertexBufferObject->gen();
    m_pVertexBufferObject->bind();
    m_pVertexBufferObject->allocate(&pCircle->getPoints()[0], pCircle->getSize() * 3 * sizeof(Gfloat));

    m_pVertexArrayObject->gen();
    m_pVertexArrayObject->bind();

    m_pVertexBufferObject->bind();
    m_pShaderProgram->enableAttributeVertexArray(VERTEX_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(VERTEX_IN_LAYOUT, 3, 0);

    m_pVertexArrayObject->release();
}

void CoCircleCore::setUniformLocation()
{    
    CoShapeCore::setUniformLocation();
}
