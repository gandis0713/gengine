#include "cotexturedpolygoncore.h"
#include "cotexturedpolygon.h"

CoTexturedPolygonCore::CoTexturedPolygonCore()
{

}

CoTexturedPolygonCore::CoTexturedPolygonCore(CoNode* pNode,
                             CoCamera *pCamera,
                             CoLight *pLight)
    : CoShapeCore(pNode, pCamera, pLight)
{
}


CoTexturedPolygonCore::~CoTexturedPolygonCore()
{

}

void CoTexturedPolygonCore::initialize()
{

    createObject();
    createShaderProgram();
    setUniformLocation();
    bindObject();

}

void CoTexturedPolygonCore::paint()
{
    CoTexturedPolygon *pPolygon = static_cast<CoTexturedPolygon*>(m_pNode);

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

//    glDrawArrays(GL_TRIANGLES, 0, pPolygon->getSize());

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}



void CoTexturedPolygonCore::createObject()
{
    CoShapeCore::createObject();

    m_pVertexNormalBufferObject = new CoVertexBufferObject();
    m_pTextureBufferObject = new CoVertexBufferObject();
    m_pIndexBufferObject = new CoVertexBufferObject();
}

void CoTexturedPolygonCore::createShaderProgram()
{
    m_pShaderProgram = new CoShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/polygon_frag.glsl");
//    m_pShaderProgram->AddShaders(EShaderType::eGeometry, ":resource/glsl/polygon_geom.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/polygon_vert.glsl");
    m_pShaderProgram->link();
}

void CoTexturedPolygonCore::bindObject()
{

    CoTexturedPolygon *pPolygon = static_cast<CoTexturedPolygon*>(m_pNode);

    m_pVertexBufferObject->gen();
    m_pVertexBufferObject->bind();
    m_pVertexBufferObject->allocate(&pPolygon->getPoints()[0], pPolygon->getSize() * 3 * sizeof(Gfloat));

    m_pVertexNormalBufferObject->gen();
    m_pVertexNormalBufferObject->bind();
    m_pVertexNormalBufferObject->allocate(&pPolygon->getNormals()[0], pPolygon->getSize() * 3 * sizeof(Gfloat));

    m_pTextureBufferObject->bind();
    m_pTextureBufferObject->allocate(&pPolygon->getTextureCoords()[0], pPolygon->getTextureCoords().size() * 2 * sizeof(Gfloat));

    m_pIndexBufferObject->setType(CoVertexBufferObject::EType::eIndexArray);
    m_pIndexBufferObject->bind();
    std::vector<Guint> vecVertexIndices;
    pPolygon->getFaceIndex().getVertexIndices(vecVertexIndices);
    m_pIndexBufferObject->allocate(&vecVertexIndices[0], vecVertexIndices.size() * sizeof(Guint));

    glGenTextures(1, &m_nTextureID);

    glBindTexture(GL_TEXTURE_2D, m_nTextureID);


//    glTexImage2D(GL_TEXTURE_2D,
//                 0,
//                 GL_RGBA,
//                 pPolygon->getWidth(),
//                 pPolygon->getHeight(),
//                 0,
//                 GL_BGRA,
//                 GL_UNSIGNED_BYTE,
//                 pTexture->getData());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);

    m_pVertexArrayObject->gen();
    m_pVertexArrayObject->bind();

    m_pVertexBufferObject->bind();
    m_pShaderProgram->enableAttributeVertexArray(VERTEX_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(VERTEX_IN_LAYOUT, 3, 0);

    m_pVertexNormalBufferObject->bind();
    m_pShaderProgram->enableAttributeVertexArray(VERTEXNORMAL_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(VERTEXNORMAL_IN_LAYOUT, 3, 0);

    m_pTextureBufferObject->bind();
    m_pShaderProgram->enableAttributeVertexArray(TEXTURE_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(TEXTURE_IN_LAYOUT, 2, 0);

    m_pVertexArrayObject->release();
}

void CoTexturedPolygonCore::setUniformLocation()
{
    CoShapeCore::setUniformLocation();
}
