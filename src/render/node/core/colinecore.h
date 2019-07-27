#ifndef COLINECORE_H
#define COLINECORE_H

#include "conodecore.h"

class CoLineCore : public CoNodeCore
{
public:
    CoLineCore();
    CoLineCore(CoNode* pNode, CoCamera *pCamera);
    ~CoLineCore();

    void initialize() override;
    void paint() override;

protected:
    Guint    m_nRadiusID;
};

#endif // COLINECORE_H
