#ifndef COSHAPECORE_H
#define COSHAPECORE_H

#include "conodecore.h"

class CoShapeCore : public CoNodeCore
{
public:
    CoShapeCore();
    CoShapeCore(CoNode* pNode, CoCamera *pCamera);
    ~CoShapeCore();

    void initialize() override {}
    void paint() override {}

protected:
    CoVertexArrayObject*  m_pVAO;
    CoVertexBufferObject* m_pVBO;
    CoVertexBufferObject* m_pCBO;
};

#endif // COSHAPECORE_H
