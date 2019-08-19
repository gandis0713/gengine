#ifndef COCATMULLSPLINECORE_H
#define COCATMULLSPLINECORE_H

#include "colinecore.h"

class CoCatmullSplineCore : public CoLineCore
{
public:
    CoCatmullSplineCore();
    CoCatmullSplineCore(CoNode* pNode,
                        CoCamera *pCamera,
                        CoLight *pLight);
    ~CoCatmullSplineCore();

protected:
    void initialize() override;
    void paint() override;    

    void createObject() override;
    void createShaderProgram() override;
    void bindObject() override;
    void setUniformLocation() override;

protected:
    Guint m_nAlpha;
};


#endif // COCATMULLSPLINECORE_H
