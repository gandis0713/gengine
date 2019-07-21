#include "conode.h"

CoNode::CoNode()
    :m_eShaderProgramType(EShaderProgramType::eDefault)
{
}

CoNode::~CoNode()
{
}

Guint CoNode::getSize()
{
    return m_vecPoints.size();
}

void CoNode::setColor(CoVec3 vColor)
{
    m_vecColors.clear();
    for(Gint i = 0; i < m_vecPoints.size(); i++)
    {
        m_vecColors.push_back(vColor);
    }
}

std::vector<CoVec3> CoNode::getPoints()
{
    return m_vecPoints;
}

std::vector<CoVec3> CoNode::getColors()
{
    return m_vecColors;
}

EShaderProgramType CoNode::getShaderProgramType()
{
    return m_eShaderProgramType;
}
