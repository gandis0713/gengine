#include "copolygon.h"

CoPolygon::CoPolygon()
{    
    m_eShaderProgramType = EShaderProgramType::ePolygon;

}

CoPolygon::CoPolygon(const std::vector<CoVec3> &vecPoints)
{
    setPoints(vecPoints);
    setColor(CoVec3(0.5, 0.5, 0.5));

    m_eShaderProgramType = EShaderProgramType::ePolygon;
}

CoPolygon::~CoPolygon()
{
    // do nothing.
}

void CoPolygon::setPoints(const std::vector<CoVec3> &vecPoints)
{
    m_vecPoints.clear();
    m_vecPoints = vecPoints;

    setColor(CoVec3(0.5, 0.5, 0.5));
}

void CoPolygon::setNormals(const std::vector<CoVec3> &vecNormals)
{
    m_vecVertexNormals.clear();
    m_vecVertexNormals = vecNormals;
}

void CoPolygon::setMatModel(CoMat4x4 matModel)
{
    m_matModel = matModel;
}

CoMat4x4 CoPolygon::getMatModel()
{
    return m_matModel;
}

std::vector<CoVec3> CoPolygon::getNormals()
{
    return m_vecVertexNormals;
}
