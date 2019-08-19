#ifndef COLINECORE_H
#define COLINECORE_H

#include "coshapecore.h"

class CoLineCore : public CoShapeCore
{
public:
    CoLineCore();
    CoLineCore(CoNode* pNode,
               CoCamera *pCamera,
               CoLight *pLight);
    ~CoLineCore();

    void initialize() override;
    void paint() override;
};

#endif // COLINECORE_H
