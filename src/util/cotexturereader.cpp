#include "cotexturereader.h"

#include <QImage>

CoTextureReader::CoTextureReader()
{

}

CoTextureReader::~CoTextureReader()
{
    delete m_pImage;
}

void CoTextureReader::load(const Gchar *pPath)
{
    m_pImage = new QImage();
    m_pImage->load(pPath);
}


Guchar* CoTextureReader::getData()
{
    return m_pImage->bits();
}
