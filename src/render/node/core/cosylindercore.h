#ifndef COSYLINDERCORE_H
#define COSYLINDERCORE_H

#include "coshapecore.h"

class CoSylinderCore : public CoShapeCore
{
public:
    CoSylinderCore();
    CoSylinderCore(CoNode* pNode,
                   CoCamera *pCamera,
                   CoLight *pLight);
    ~CoSylinderCore();

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

#endif // COSYLINDERCORE_H
