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

protected:

    void createObject() override;
    void createShaderProgram() override;
    void bindObject() override;
    void setUniformLocation() override;

    Guint    m_nWidthID;

};

#endif // COLINECORE_H
