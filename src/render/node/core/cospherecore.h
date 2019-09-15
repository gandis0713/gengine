#ifndef COSPHERECORE_H
#define COSPHERECORE_H

#include "coshapecore.h"

class CoSphereCore : public CoShapeCore
{
public:
    CoSphereCore();
    CoSphereCore(CoNode* pNode,
                 CoCamera *pCamera,
                 CoLight *pLight);
    ~CoSphereCore();

    void initialize() override;
    void paint() override;

protected:

    void createObject() override;
    void createShaderProgram() override;
    void bindObject() override;
    void setUniformLocation() override;

protected:
    CoVertexBufferObject* m_pVertexNormalBufferObject;
};

#endif // COSPHERECORE_H
