#include "coglextension.h"
#include "coimagecore.h"
#include "coimage.h"

CoImageCore::CoImageCore()
{

}

CoImageCore::CoImageCore(CoNode* pNode,
                             CoCamera *pCamera,
                             CoLight *pLight)
    : CoShapeCore(pNode, pCamera, pLight)
{
}


CoImageCore::~CoImageCore()
{

}

void CoImageCore::initialize()
{

    createObject();
    createShaderProgram();
    setUniformLocation();
    bindObject();


}

void CoImageCore::paint()
{

    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_nMVPID, m_pCamera->getCameraMat() * CoMat4x4());

    m_pVertexArrayObject->bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}



void CoImageCore::createObject()
{
    CoShapeCore::createObject();

    m_pTextureBufferObject = new CoVertexBufferObject();
    m_pIndexBufferObject = new CoVertexBufferObject();
}

void CoImageCore::createShaderProgram()
{
    m_pShaderProgram = new CoShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/texture_frag.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/texture_vert.glsl");
    m_pShaderProgram->link();
}

void CoImageCore::bindObject()
{
    CoImage *pTexture = static_cast<CoImage*>(m_pNode);

    m_pVertexBufferObject->gen();
    m_pTextureBufferObject->gen();
    m_pIndexBufferObject->gen();

    m_pVertexArrayObject->gen();
    m_pVertexArrayObject->bind();

    m_pVertexBufferObject->bind();
    m_pVertexBufferObject->allocate(&pTexture->getPoints()[0], pTexture->getSize() * 3 * sizeof(Gfloat));

    m_pTextureBufferObject->bind();
    m_pTextureBufferObject->allocate(&pTexture->getTextureCoords()[0], pTexture->getTextureCoords().size() * 2 * sizeof(Gfloat));

    m_pIndexBufferObject->setType(CoVertexBufferObject::EType::eIndexArray);
    m_pIndexBufferObject->bind();
    m_pIndexBufferObject->allocate(&pTexture->getVertexIndices()[0], pTexture->getVertexIndices().size() * sizeof(Guint));

    glGenTextures(1, &m_nTextureID);

    glBindTexture(GL_TEXTURE_2D, m_nTextureID);


    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 pTexture->getWidth(),
                 pTexture->getHeight(),
                 0,
                 GL_BGRA,
                 GL_UNSIGNED_BYTE,
                 pTexture->getData());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);

    m_pVertexBufferObject->bind();
    m_pShaderProgram->enableAttributeVertexArray(VERTEX_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(VERTEX_IN_LAYOUT, 3, 0);

    m_pTextureBufferObject->bind();
    m_pShaderProgram->enableAttributeVertexArray(TEXTURE_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(TEXTURE_IN_LAYOUT, 2, 0);

    m_pVertexArrayObject->release();
}

void CoImageCore::setUniformLocation()
{
    CoShapeCore::setUniformLocation();
}
