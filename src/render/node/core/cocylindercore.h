#ifndef COCYLINDERCORE_H
#define COCYLINDERCORE_H

#include "coshapecore.h"

class CoCylinderCore : public CoShapeCore
{
public:
    CoCylinderCore();
    CoCylinderCore(CoNode* pNode,
                   CoCamera *pCamera,
                   CoLight *pLight);
    ~CoCylinderCore();

    void initialize() override;
    void paint() override;

protected:

    void createObject() override;
    void createShaderProgram() override;
    void bindObject() override;
    void setUniformLocation() override;

protected:
    CoVertexBufferObject* m_pVertexNormalBufferObject;
    CoVertexBufferObject* m_pIndexBufferObject;
};

#endif // COCYLINDERCORE_H
