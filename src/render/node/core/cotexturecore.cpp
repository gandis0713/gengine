#include "coglextension.h"
#include "cotexturecore.h"
#include "cotexture.h"

CoTextureCore::CoTextureCore()
{

}

CoTextureCore::CoTextureCore(CoNode* pNode,
                             CoCamera *pCamera,
                             CoLight *pLight)
    : CoShapeCore(pNode, pCamera, pLight)
{
}


CoTextureCore::~CoTextureCore()
{

}

void CoTextureCore::initialize()
{

    createObject();
    createShaderProgram();
    setUniformLocation();
    bindObject();


}

void CoTextureCore::paint()
{

    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_nMVPID, m_pCamera->getCameraMat() * CoMat4x4());

    m_pVertexArrayObject->bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}



void CoTextureCore::createObject()
{
    CoShapeCore::createObject();

    m_pTextureBufferObject = new CoVertexBufferObject();
    m_pIndexBufferObject = new CoVertexBufferObject();
}

void CoTextureCore::createShaderProgram()
{
    m_pShaderProgram = new CoShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/texture_frag.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/texture_vert.glsl");
    m_pShaderProgram->link();
}

void CoTextureCore::bindObject()
{
    CoTexture *pTexture = static_cast<CoTexture*>(m_pNode);

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

void CoTextureCore::setUniformLocation()
{
    CoShapeCore::setUniformLocation();
}
