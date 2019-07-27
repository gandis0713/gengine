#ifndef COCATMULLSPLINENODECORE_H
#define COCATMULLSPLINENODECORE_H

#include "colinenodecore.h"

class CoCatmullSplineNodeCore : public CoLineNodeCore
{
public:
    CoCatmullSplineNodeCore();
    CoCatmullSplineNodeCore(CoNode* pNode, CoCamera *pCamera);
    ~CoCatmullSplineNodeCore();

    void initialize() override;
    void paint() override;
protected:
    Guint m_nAlpha;
};


#endif // COCATMULLSPLINENODECORE_H
