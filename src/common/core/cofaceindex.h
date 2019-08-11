#ifndef COFACEINDEX_H
#define COFACEINDEX_H

#include "covector2.h"
#include "covector3.h"

#include "deengine.h"

#include <vector>

class GANDISENGINE CoFaceIndex
{
public:
    CoFaceIndex();
    ~CoFaceIndex();

    void addVertexIndices(Guint vVertex);
    void addUICoordIndices(Guint vUICoord);
    void addVertexNormalIndices(Guint vVertexNormal);

    void getVertexIndices(std::vector<Guint> &vecVertexIndices);

private:
    std::vector<Guint> m_vecVertexIndices;
    std::vector<Guint> m_vecUVCoordIndices;
    std::vector<Guint> m_vecVertexNormalIndices;
};

#endif // COFACEINDEX_H
