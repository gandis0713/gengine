#include "cotexture.h"

#include <QImage>

CoTexture::CoTexture()
    : m_pImage(NULL)
{
    m_eShaderProgramType = EShaderProgramType::eTexture;
}

CoTexture::~CoTexture()
{
    delete m_pImage;
}

void CoTexture::load(const Gchar *pPath)
{
    m_pImage = new QImage();
    m_pImage->load(pPath);
}

Guchar* CoTexture::getData()
{
    return m_pImage->bits();
}

Gint CoTexture::getWidth()
{
    return m_pImage->width();
}

Gint CoTexture::getHeight()
{
    return m_pImage->height();
}
