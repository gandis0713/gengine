#ifndef CODEFAULTNODECORE_H
#define CODEFAULTNODECORE_H

#include "conodecore.h"

class CoDefaultNodeCore : public CoNodeCore
{
public:
    CoDefaultNodeCore(CoNode* pNode, CoCamera *pCamera);
    ~CoDefaultNodeCore();

    void initialize() override;
    void paint() override;
};

#endif // CODEFAULTNODECORE_H
