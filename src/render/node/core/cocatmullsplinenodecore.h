#ifndef COCATMULLSPLINENODECORE_H
#define COCATMULLSPLINENODECORE_H

#include "conodecore.h"

class CoCatmullSplineNodeCore : public CoNodeCore
{
public:
    CoCatmullSplineNodeCore(CoNode* pNode, CoCamera *pCamera);
    ~CoCatmullSplineNodeCore();

    void initialize() override;
    void paint() override;

    CoVertexBufferObject * m_pVSO;
};


#endif // COCATMULLSPLINENODECORE_H
