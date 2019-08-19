#ifndef COPOLYGONCORE_H
#define COPOLYGONCORE_H

#include "coshapecore.h"

class CoPolygonCore : public CoShapeCore
{
public:
    CoPolygonCore();
    CoPolygonCore(CoNode* pNode,
                  CoCamera *pCamera,
                  CoLight *pLight);
    ~CoPolygonCore();

    void initialize() override;
    void paint() override;
protected:
    Guint m_nVID;
    Guint m_nMID;
    Guint m_nLightPosID;
    Guint m_nLightColorID;
    Guint m_nLightPowerID;

    CoVertexBufferObject* m_pNBO;
};

#endif // COPOLYGONCORE_H
