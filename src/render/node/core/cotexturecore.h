#ifndef COTEXTURECORE_H
#define COTEXTURECORE_H

#include "conodecore.h"

class CoTextureCore : public CoNodeCore
{
public:
    CoTextureCore();
    CoTextureCore(CoNode* pNode, CoCamera *pCamera);
    ~CoTextureCore();

    void initialize() override;
    void paint() override;
};

#endif // COTEXTURECORE_H
