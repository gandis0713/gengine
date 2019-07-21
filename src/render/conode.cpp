#include "conode.h"

CoNode::CoNode()
{
}

CoNode::~CoNode()
{
}

Guint CoNode::GetSize()
{
    return m_vecPoints.size();
}

std::vector<CoVec3> CoNode::GetPoints()
{
    return m_vecPoints;
}

std::vector<CoVec3> CoNode::GetColors()
{
    return m_vecColors;
}
