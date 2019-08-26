#include "cotexture.h"

CoTexture::CoTexture(Guchar* pData,
                     Gint nWidth,
                     Gint nHeight)
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

    setData(pData);
    setWidth(nWidth);
    setHeight(nHeight);
}

CoTexture::~CoTexture()
{
}

void CoTexture::setData(Guchar* pData)
{
    m_pData = pData;
}

Guchar* CoTexture::getData()
{
    return m_pData;
}

void CoTexture::setWidth(Gint nWidth)
{
    m_nWidth = nWidth;
}
void CoTexture::setHeight(Gint nHeight)
{
    m_nHeight = nHeight;
}

Gint CoTexture::getWidth()
{
    return m_nWidth;
}

Gint CoTexture::getHeight()
{
    return m_nHeight;
}

std::vector<CoVec2> CoTexture::getTextureCoords()
{
    return m_vecTextureCoord;
}

std::vector<Guint> CoTexture::getVertexIndices()
{
    return m_vecVertexIndices;
}
