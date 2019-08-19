#include "coglextension.h"
#include "cotexturecore.h"
#include "cotexture.h"

CoTextureCore::CoTextureCore()
{

}

CoTextureCore::CoTextureCore(CoNode* pNode,
                             CoCamera *pCamera,
                             CoLight *pLight)
    : CoNodeCore(pNode, pCamera, pLight)
{
}


CoTextureCore::~CoTextureCore()
{

}

void CoTextureCore::initialize()
{
    m_pVAO = new CoVertexArrayObject();
    m_pVBO = new CoVertexBufferObject();
    m_pCBO = new CoVertexBufferObject();
    m_pTBO = new CoVertexBufferObject();
    m_pIBO = new CoVertexBufferObject();

    m_pShaderProgram = new CoShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/texture_frag.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/texture_vert.glsl");
    m_pShaderProgram->link();

    m_nMVPID = m_pShaderProgram->getUniformLocation("mvp");

    Gfloat position[] = {
         1.0f,  1.0f, 0.0f, // top right
         1.0f, -1.0f, 0.0f, // bottom right
        -1.0f, -1.0f, 0.0f, // bottom left
        -1.0f,  1.0f, 0.0f, // top left
    };

    Gfloat color[] = {
         1.0f, 0.0f, 0.0f, // top right
         0.0f, 1.0f, 0.0f, // bottom right
         0.0f, 0.0f, 1.0f, // bottom left
         1.0f, 1.0f, 0.0f, // top left
    };

    Gfloat texture_coords[] = {
         1.0f, 1.0f - 1.0f, // top right
         1.0f, 1.0f - 0.0f, // bottom right
         0.0f, 1.0f - 0.0f, // bottom left
         0.0f, 1.0f - 1.0f, // top left
    };

    Guint indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    m_pVBO->gen();
    m_pCBO->gen();
    m_pTBO->gen();
    m_pIBO->gen();

    m_pVAO->gen();
    m_pVAO->bind();

    m_pVBO->bind();
    m_pVBO->allocate(&position, 12 * sizeof(Gfloat));

    m_pCBO->bind();
    m_pCBO->allocate(&color, 12 * sizeof(Gfloat));

    m_pTBO->bind();
    m_pTBO->allocate(&texture_coords, 8 * sizeof(Gfloat));

    m_pIBO->setType(CoVertexBufferObject::EType::eIndexArray);
    m_pIBO->bind();
    m_pIBO->allocate(&indices, 6 * sizeof(Guint));

    glGenTextures(1, &m_nTextureID);

    glBindTexture(GL_TEXTURE_2D, m_nTextureID);

    CoTexture *pTexture = static_cast<CoTexture*>(m_pNode);

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

    m_pVBO->bind();
    m_pShaderProgram->enableAttributeVertexArray(VERTEX_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(VERTEX_IN_LAYOUT, 3, 0);

    m_pCBO->bind();
    m_pShaderProgram->enableAttributeVertexArray(COLOR_IN_LAYOUT);
    m_pShaderProgram->setVertexAttribPointer(COLOR_IN_LAYOUT, 3, 0);

    m_pTBO->bind();
    m_pShaderProgram->enableAttributeVertexArray(2);
    m_pShaderProgram->setVertexAttribPointer(2, 2, 0);

    m_pVAO->release();
}

void CoTextureCore::paint()
{    
    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_nMVPID, m_pCamera->getCameraMat() * CoMat4x4());

    m_pVAO->bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
