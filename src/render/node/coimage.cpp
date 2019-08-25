#include "cotexture.h"

#include <QImage>

CoTexture::CoTexture()
    : m_pImage(NULL)
{
    m_eShaderProgramType = EShaderProgramType::eTexture;

    m_vecPoints.push_back(CoVec3( 1.0f,   1.0f, 0.0f));
    m_vecPoints.push_back(CoVec3( 1.0f,  -1.0f, 0.0f));
    m_vecPoints.push_back(CoVec3(-1.0f,  -1.0f, 0.0f));
    m_vecPoints.push_back(CoVec3(-1.0f,   1.0f, 0.0f));

    m_vecTextureCoord.push_back(CoVec2(1.0f, 1.0f - 1.0f));
    m_vecTextureCoord.push_back(CoVec2(1.0f, 1.0f - 0.0f));
    m_vecTextureCoord.push_back(CoVec2(0.0f, 1.0f - 0.0f));
    m_vecTextureCoord.push_back(CoVec2(0.0f, 1.0f - 1.0f));

    m_vecVertexIndices.push_back(0);
    m_vecVertexIndices.push_back(1);
    m_vecVertexIndices.push_back(3);

    m_vecVertexIndices.push_back(1);
    m_vecVertexIndices.push_back(2);
    m_vecVertexIndices.push_back(3);
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

std::vector<CoVec2> CoTexture::getTextureCoords()
{
    return m_vecTextureCoord;
}


std::vector<Guint> CoTexture::getVertexIndices()
{
    return m_vecVertexIndices;
}
