#ifndef COLINENODECORE_H
#define COLINENODECORE_H

#include "conodecore.h"

class CoLineNodeCore : public CoNodeCore
{
public:
    CoLineNodeCore();
    CoLineNodeCore(CoNode* pNode, CoCamera *pCamera);
    ~CoLineNodeCore();

    void initialize() override;
    void paint() override;

protected:
    Guint    m_nWidthID;
};

#endif // COLINENODECORE_H
