#include "CoTexturedPolygon.h"

CoTexturedPolygon::CoTexturedPolygon()
{    
    m_eShaderProgramType = EShaderProgramType::ePolygon;

}

CoTexturedPolygon::CoTexturedPolygon(const std::vector<CoVec3> &vecPoints,
                     const std::vector<CoVec3> &vecNormals,
                     const std::vector<CoVec2> &vecTextureCoords,
                     const CoFaceIndex &faceIndices)
{
    setFaceIndex(faceIndices);
    setPoints(vecPoints);
    setNormals(vecNormals);
    setTextureCoords(vecTextureCoords);

    m_eShaderProgramType = EShaderProgramType::ePolygon;
}

CoTexturedPolygon::~CoTexturedPolygon()
{
    // do nothing.
}

void CoTexturedPolygon::setPoints(const std::vector<CoVec3> &vecPoints)
{
    m_vecPoints.clear();

    std::vector<Guint> vecVertexIndices;
    m_faceIndices.getVertexIndices(vecVertexIndices);

    for(Gint nIndex = 0; nIndex < vecVertexIndices.size(); nIndex += 3)
    {
        CoVec3 vPoint[3];
        vPoint[0] = vecPoints[vecVertexIndices[nIndex] - 1];
        vPoint[1] = vecPoints[vecVertexIndices[nIndex + 1] - 1];
        vPoint[2] = vecPoints[vecVertexIndices[nIndex + 2] - 1];

        m_vecPoints.push_back(vPoint[0]);
        m_vecPoints.push_back(vPoint[1]);
        m_vecPoints.push_back(vPoint[2]);
    }
}

void CoTexturedPolygon::setNormals(const std::vector<CoVec3> &vecNormals)
{
    m_vecVertexNormals.clear();

    std::vector<Guint> vecVertexIndices;
    m_faceIndices.getVertexIndices(vecVertexIndices);

    std::vector<Guint> vecVertexNormalIndices;
    m_faceIndices.getVertexNormalIndices(vecVertexNormalIndices);

    if(vecNormals.size() <= 0)
    {
        for(Gint nIndex = 0; nIndex < m_vecPoints.size(); nIndex += 3)
        {
            CoVec3 vPoint[3];
            vPoint[0] = m_vecPoints[nIndex];
            vPoint[1] = m_vecPoints[nIndex + 1];
            vPoint[2] = m_vecPoints[nIndex + 2];

            CoVec3 vP2P1 = vPoint[1] - vPoint[0];
            CoVec3 vP3P1 = vPoint[2] - vPoint[0];
            CoVec3 vNormal = vP2P1.cross(vP3P1);
            vNormal.normalize();

            m_vecVertexNormals.push_back(vNormal);
            m_vecVertexNormals.push_back(vNormal);
            m_vecVertexNormals.push_back(vNormal);

        }
    }
    else
    {
        for(Gint nIndex = 0; nIndex < vecVertexIndices.size(); nIndex += 3)
        {
            CoVec3 vNormal[3];
            vNormal[0] = vecNormals[vecVertexNormalIndices[nIndex] - 1];
            vNormal[1] = vecNormals[vecVertexNormalIndices[nIndex + 1] - 1];
            vNormal[2] = vecNormals[vecVertexNormalIndices[nIndex + 2] - 1];

            m_vecVertexNormals.push_back(vNormal[0]);
            m_vecVertexNormals.push_back(vNormal[1]);
            m_vecVertexNormals.push_back(vNormal[2]);
        }
    }
}

void CoTexturedPolygon::setTextureCoords(const std::vector<CoVec2> &vecTextureCoords)
{
    m_vecTextureCoords.clear();
    m_vecTextureCoords = vecTextureCoords;
}

void CoTexturedPolygon::setFaceIndex(const CoFaceIndex &faceIndices)
{
    m_faceIndices = faceIndices;
}

std::vector<CoVec3> CoTexturedPolygon::getPoints()
{
    return m_vecPoints;
}

std::vector<CoVec3> CoTexturedPolygon::getNormals()
{
    return m_vecVertexNormals;
}

std::vector<CoVec2> CoTexturedPolygon::getTextureCoords()
{
    return m_vecTextureCoords;
}

CoFaceIndex CoTexturedPolygon::getFaceIndex()
{
    return m_faceIndices;
}
