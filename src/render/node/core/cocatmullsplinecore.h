#ifndef COCATMULLSPLINECORE_H
#define COCATMULLSPLINECORE_H

#include "colinecore.h"

class CoCatmullSplineCore : public CoLineCore
{
public:
    CoCatmullSplineCore();
    CoCatmullSplineCore(CoNode* pNode, CoCamera *pCamera);
    ~CoCatmullSplineCore();

    void initialize() override;
    void paint() override;
protected:
    Guint m_nAlpha;
};


#endif // COCATMULLSPLINECORE_H
