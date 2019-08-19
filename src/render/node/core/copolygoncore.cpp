#include "copolygoncore.h"
#include "copolygon.h"

CoPolygonCore::CoPolygonCore()
{

}

CoPolygonCore::CoPolygonCore(CoNode* pNode,
                             CoCamera *pCamera,
                             CoLight *pLight)
    : CoShapeCore(pNode, pCamera, pLight)
{
}


CoPolygonCore::~CoPolygonCore()
{

}

void CoPolygonCore::initialize()
{
    m_pVertexArrayObject = new CoVertexArrayObject();
    m_pVertexBufferObject = new CoVertexBufferObject();
    m_pVertexNornalBufferObject = new CoVertexBufferObject();

    m_pShaderProgram = new CoShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/polygon_frag.glsl");
//    m_pShaderProgram->AddShaders(EShaderType::eGeometry, ":resource/glsl/polygon_geom.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/polygon_vert.glsl");
    m_pShaderProgram->link();

    m_nMVPID = m_pShaderProgram->getUniformLocation("mvp");
    m_nMID = m_pShaderProgram->getUniformLocation("m");
    m_nVID = m_pShaderProgram->getUniformLocation("v");

    m_nLightPosID = m_pShaderProgram->getUniformLocation("lightPosition");
    m_nLightColorID = m_pShaderProgram->getUniformLocation("lightColor");
    m_nLightPowerID = m_pShaderProgram->getUniformLocation("lightPower");

    m_nDiffuseColorID = m_pShaderProgram->getUniformLocation("diffuseColor");
    m_nAmbientColorID = m_pShaderProgram->getUniformLocation("ambientColor");
    m_nSpecularColorID = m_pShaderProgram->getUniformLocation("specularColor");

    CoPolygon *pPolygon = static_cast<CoPolygon*>(m_pNode);

    m_pVertexBufferObject->gen();
    m_pVertexBufferObject->bind();
    m_pVertexBufferObject->allocate(&pPolygon->getPoints()[0], pPolygon->getSize() * 3 * sizeof(Gfloat));

    m_pVertexNornalBufferObject->gen();
    m_pVertexNornalBufferObject->bind();
    m_pVertexNornalBufferObject->allocate(&pPolygon->getNormals()[0], pPolygon->getSize() * 3 * sizeof(Gfloat));

    m_pVertexArrayObject->gen();
    m_pVertexArrayObject->bind();

    m_pVertexBufferObject->bind();
    m_pShaderProgram->enableAttributeVertexArray(VERTEX_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(VERTEX_IN_LAYOUT, 3, 0);

    m_pVertexNornalBufferObject->bind();
    m_pShaderProgram->enableAttributeVertexArray(2);
    m_pShaderProgram->setVertexAttribPointer(2, 3, 0);

    m_pVertexArrayObject->release();
}

void CoPolygonCore::paint()
{
    CoPolygon *pPolygon = static_cast<CoPolygon*>(m_pNode);

    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_nMVPID, m_pCamera->getCameraMat());
    m_pShaderProgram->setUniformMatrix4fv(m_nMID, pPolygon->getMatModel());
    m_pShaderProgram->setUniformMatrix4fv(m_nVID, m_pCamera->getViewMat());

    Gfloat fCameraLength = m_pCamera->getPosition().length();
    Gfloat fLightLength = m_pLight->getPosition().length();

    Gfloat fRate = fLightLength / fCameraLength;

    CoVec3 vLightPosition = m_pCamera->getPosition() * fRate;
    CoVec3 vLightColor = m_pLight->getColor();
    Gfloat fLightPower = m_pLight->getPower();

    glUniform3f(m_nLightPosID, vLightPosition[0], vLightPosition[1], vLightPosition[2]);
    glUniform3f(m_nLightColorID, vLightColor[0], vLightColor[1], vLightColor[2]);
    glUniform1f(m_nLightPowerID, fLightPower);

    CoVec3 vDiffuseColor = pPolygon->getColor();
    CoVec3 vAmbientColor = pPolygon->getAmbientColor();
    CoVec3 vSpecularColor = pPolygon->getSpecularColor();

    glUniform3f(m_nDiffuseColorID, vDiffuseColor[0], vDiffuseColor[1], vDiffuseColor[2]);
    glUniform3f(m_nAmbientColorID, vAmbientColor[0], vAmbientColor[1], vAmbientColor[2]);
    glUniform3f(m_nSpecularColorID, vSpecularColor[0], vSpecularColor[1], vSpecularColor[2]);

    m_pVertexArrayObject->bind();

    glDrawArrays(GL_TRIANGLES, 0, pPolygon->getSize());
}
