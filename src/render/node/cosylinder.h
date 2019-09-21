#ifndef COSYLINDER_H
#define COSYLINDER_H

#include "coshape.h"

using namespace std;

class GANDISENGINE CoSylinder : public CoShape
{
public:
    CoSylinder();
    CoSylinder(CoVec3 vCenter,
               Gfloat fRadius,
               Gfloat fLength);
    virtual ~CoSylinder();

    void setCenter(CoVec3 vPosition);
    void setRadius(Gfloat fRadius);
    void setLength(Gfloat fLength);

    std::vector<CoVec3> getNormals();
    std::vector<Gint> getVertexIndice();

protected:
    void createSylinder();
    void createIndexedSylinder();

private:
    CoVec3 m_vCenter;
    Gfloat m_fRadius;
    Gfloat m_fLength;

    vector<Gint> m_vecVertexIndices;
    vector<CoVec3> m_vecVertexNormal;

};

#endif // COSYLINDER_H
