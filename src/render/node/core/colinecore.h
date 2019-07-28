#ifndef COLINECORE_H
#define COLINECORE_H

#include "coshapecore.h".h"

class CoLineCore : public CoShapeCore
{
public:
    CoLineCore();
    CoLineCore(CoNode* pNode, CoCamera *pCamera);
    ~CoLineCore();

    void initialize() override;
    void paint() override;

protected:
    Guint    m_nWidthID;
};

#endif // COLINECORE_H
