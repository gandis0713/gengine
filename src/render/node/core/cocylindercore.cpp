#include "cocylindercore.h"
#include "cocylinder.h"

CoCylinderCore::CoCylinderCore()
{

}

CoCylinderCore::CoCylinderCore(CoNode* pNode,
                               CoCamera *pCamera,
                               CoLight *pLight)
    : CoShapeCore(pNode, pCamera, pLight)
{
}


CoCylinderCore::~CoCylinderCore()
{

}

void CoCylinderCore::initialize()
{

    createObject();
    createShaderProgram();
    setUniformLocation();
    bindObject();

}

void CoCylinderCore::paint()
{
    CoCylinder *pCylinder = static_cast<CoCylinder*>(m_pNode);

    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_nMVPID, m_pCamera->getCameraMat());
    m_pShaderProgram->setUniformMatrix4fv(m_nMID, pCylinder->getMatModel());
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

    CoVec3 vDiffuseColor = pCylinder->getColor();
    CoVec3 vAmbientColor = pCylinder->getAmbientColor();
    CoVec3 vSpecularColor = pCylinder->getSpecularColor();

    glUniform3f(m_nDiffuseColorID, vDiffuseColor[0], vDiffuseColor[1], vDiffuseColor[2]);
    glUniform3f(m_nAmbientColorID, vAmbientColor[0], vAmbientColor[1], vAmbientColor[2]);
    glUniform3f(m_nSpecularColorID, vSpecularColor[0], vSpecularColor[1], vSpecularColor[2]);

    m_pVertexArrayObject->bind();

    glDrawArrays(GL_TRIANGLES, 0, pCylinder->getSize());
}



void CoCylinderCore::createObject()
{
    CoShapeCore::createObject();

    m_pVertexNormalBufferObject = new CoVertexBufferObject();
    m_pIndexBufferObject = new CoVertexBufferObject();
}

void CoCylinderCore::createShaderProgram()
{
    m_pShaderProgram = new CoShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/cylinder_frag.glsl");
//    m_pShaderProgram->AddShaders(EShaderType::eGeometry, ":resource/glsl/cylinder_geom.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/cylinder_vert.glsl");
    m_pShaderProgram->link();
}

void CoCylinderCore::bindObject()
{

    CoCylinder *pCylinder = static_cast<CoCylinder*>(m_pNode);

    m_pVertexBufferObject->gen();
    m_pVertexNormalBufferObject->gen();
    m_pIndexBufferObject->gen();

    m_pVertexArrayObject->gen();
    m_pVertexArrayObject->bind();

    m_pVertexBufferObject->bind();
    m_pVertexBufferObject->allocate(&pCylinder->getPoints()[0], pCylinder->getSize() * 3 * sizeof(Gfloat));

    m_pVertexNormalBufferObject->bind();
    m_pVertexNormalBufferObject->allocate(&pCylinder->getNormals()[0], pCylinder->getSize() * 3 * sizeof(Gfloat));

//    m_pIndexBufferObject->setType(CoVertexBufferObject::EType::eIndexArray);
//    m_pIndexBufferObject->bind();
//    m_pIndexBufferObject->allocate(&pCylinder->getVertexIndice()[0], pCylinder->getVertexIndice().size() * sizeof(Guint));

    m_pVertexBufferObject->bind();
    m_pShaderProgram->enableAttributeVertexArray(VERTEX_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(VERTEX_IN_LAYOUT, 3, 0);

    m_pVertexNormalBufferObject->bind();
    m_pShaderProgram->enableAttributeVertexArray(VERTEXNORMAL_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(VERTEXNORMAL_IN_LAYOUT, 3, 0);

    m_pVertexArrayObject->release();
}

void CoCylinderCore::setUniformLocation()
{
    CoShapeCore::setUniformLocation();
}
