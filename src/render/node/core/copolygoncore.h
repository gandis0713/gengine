#ifndef COPOLYGONCORE_H
#define COPOLYGONCORE_H

#include "coshapecore.h"

class CoPolygonCore : public CoShapeCore
{
public:
    CoPolygonCore();
    CoPolygonCore(CoNode* pNode, CoCamera *pCamera);
    ~CoPolygonCore();

    void initialize() override;
    void paint() override;
protected:
    Guint m_nVID;
    Guint m_nMID;
    Guint m_nCameraID;

    CoVertexBufferObject* m_pNBO;
};

#endif // COPOLYGONCORE_H
