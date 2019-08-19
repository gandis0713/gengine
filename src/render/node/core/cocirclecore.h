#ifndef COCIRCLECORE_H
#define COCIRCLECORE_H

#include "colinecore.h"

class CoCircleCore : public CoLineCore
{
public:
    CoCircleCore();
    CoCircleCore(CoNode* pNode,
                 CoCamera *pCamera,
                 CoLight *pLight);
    ~CoCircleCore();

    void initialize() override;
    void paint() override;
};

#endif // COCIRCLECORE_H
