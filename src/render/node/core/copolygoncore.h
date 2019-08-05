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
};

#endif // COPOLYGONCORE_H
