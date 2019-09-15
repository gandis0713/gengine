#ifndef COSPHERE_H
#define COSPHERE_H

#include "coshape.h"

using namespace std;

class GANDISENGINE CoSphere : public CoShape
{
public:
    CoSphere();
    CoSphere(CoVec3 vCenter, Gfloat fRadius);
    virtual ~CoSphere();

    void setCenter(CoVec3 vPosition);
    void setRadius(Gfloat fRadius);

    std::vector<CoVec3> getNormals();

protected:
    void createSphere();
    void createIndexedSphere();

private:
    CoVec3 m_vCenter;
    Gfloat m_fRadius;

    vector<Gint> m_vecVertexIndices;
    vector<CoVec3> m_vecVertexNormal;

};

#endif // COSPHERE_H
