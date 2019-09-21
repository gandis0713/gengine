#include "cotexturereader.h"

#include <QImage>

CoTextureReader::CoTextureReader()
    : m_pImage(new QImage())
{
    // do nothing.
}

CoTextureReader::~CoTextureReader()
{
    delete m_pImage;
}

Gbool CoTextureReader::load(const Gchar *pPath)
{
    return m_pImage->load(pPath);
}

Guchar* CoTextureReader::getData()
{
    return m_pImage->bits();
}

Gint CoTextureReader::getWidth()
{
    return m_pImage->width();
}

Gint CoTextureReader::getHeight()
{
    return m_pImage->height();
}
