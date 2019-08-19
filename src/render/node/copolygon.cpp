#include "copolygon.h"

CoPolygon::CoPolygon()
{    
    m_eShaderProgramType = EShaderProgramType::ePolygon;

}

CoPolygon::CoPolygon(const std::vector<CoVec3> &vecPoints,
                     const std::vector<CoVec3> &vecNormals,
                     const std::vector<CoVec2> &vecUICoords,
                     const CoFaceIndex &faceIndices)
{
    setFaceIndex(faceIndices);
    setPoints(vecPoints);
    setNormals(vecNormals);
    setUICoords(vecUICoords);

    m_eShaderProgramType = EShaderProgramType::ePolygon;
}

CoPolygon::~CoPolygon()
{
    // do nothing.
}

void CoPolygon::setPoints(const std::vector<CoVec3> &vecPoints)
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

void CoPolygon::setNormals(const std::vector<CoVec3> &vecNormals)
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

void CoPolygon::setUICoords(const std::vector<CoVec2> &vecUICoords)
{
    m_vecUICoords.clear();
    m_vecUICoords = vecUICoords;
}

void CoPolygon::setFaceIndex(const CoFaceIndex &faceIndices)
{
    m_faceIndices = faceIndices;
}

std::vector<CoVec3> CoPolygon::getNormals()
{
    return m_vecVertexNormals;
}
