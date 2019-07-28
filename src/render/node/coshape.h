#ifndef COSHAPE_H
#define COSHAPE_H

#include "conode.h"

class CoShape : public CoNode
{
public:
    CoShape();
    ~CoShape();

    Guint getSize();

    void setColor(CoVec3 vColor);

    std::vector<CoVec3> getPoints();
    std::vector<CoVec3> getColors();

protected:
    std::vector<CoVec3> m_vecPoints;
    std::vector<CoVec3> m_vecColors;
};

#endif // COSHAPE_H
