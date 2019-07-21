#ifndef COSPLINENODECORE_H
#define COSPLINENODECORE_H

#include "conodecore.h"

class CoSplineNodeCore : public CoNodeCore
{
public:
    CoSplineNodeCore(CoNode* pNode, CoCamera *pCamera);
    ~CoSplineNodeCore();

    void initialize() override;
    void paint() override;
};


#endif // COSPLINENODECORE_H
