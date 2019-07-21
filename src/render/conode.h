#ifndef CONODE_H
#define CONODE_H

#include "deengine.h"
#include "covector3.h"

#include <vector>

class GANDISENGINE CoNode
{
public:
    CoNode();
    ~CoNode();

    Guint GetSize();

    std::vector<CoVec3> GetPoints();
    std::vector<CoVec3> GetColors();

protected:
    std::vector<CoVec3> m_vecPoints;
    std::vector<CoVec3> m_vecColors;

};

#endif // CONODE_H
