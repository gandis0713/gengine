#ifndef COCONECORE_H
#define COCONECORE_H

#include "coshapecore.h"

class CoConeCore : public CoShapeCore
{
public:
    CoConeCore();
    CoConeCore(CoNode* pNode,
               CoCamera *pCamera,
               CoLight *pLight);
    ~CoConeCore();

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

#endif // COCONECORE_H
