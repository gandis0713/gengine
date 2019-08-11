#include "cofaceindex.h"

CoFaceIndex::CoFaceIndex()
{

}

CoFaceIndex::~CoFaceIndex()
{

}

void CoFaceIndex::addVertexIndices(Guint vVertex)
{
    m_vecVertexIndices.push_back(vVertex);
}

void CoFaceIndex::addUICoordIndices(Guint vUICoord)
{
    m_vecUVCoordIndices.push_back(vUICoord);
}

void CoFaceIndex::addVertexNormalIndices(Guint vVertexNormal)
{
    m_vecVertexNormalIndices.push_back(vVertexNormal);
}


void CoFaceIndex::getVertexIndices(std::vector<Guint> &vecVertexIndices)
{
    vecVertexIndices = m_vecVertexIndices;
}

void CoFaceIndex::getVertexNormalIndices(std::vector<Guint> &vecVertexNormalIndices)
{
    vecVertexNormalIndices = m_vecVertexNormalIndices;
}
