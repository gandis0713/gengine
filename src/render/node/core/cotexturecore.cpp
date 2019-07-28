#include "cotexturecore.h"
#include "coglextension.h"
#include "cotexture.h"

CoTextureCore::CoTextureCore()
{

}

CoTextureCore::CoTextureCore(CoNode* pNode, CoCamera *pCamera)
    : CoNodeCore(pNode, pCamera)
{
}


CoTextureCore::~CoTextureCore()
{

}

void CoTextureCore::initialize()
{
    Guint textureID;
    glGenTextures(1, &textureID);

    glBindTexture(GL_TEXTURE_2D, textureID);

    CoTexture *pTexture = static_cast<CoTexture*>(m_pNode);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, pTexture->getWidth(), pTexture->getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, pTexture->getData());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void CoTextureCore::paint()
{
}
