#ifndef COSHAPECORE_H
#define COSHAPECORE_H

#include "conodecore.h"
#include "covertexarrayobject.h"
#include "covertexbufferobject.h"

class CoShapeCore : public CoNodeCore
{
public:
    CoShapeCore();
    CoShapeCore(CoNode* pNode,
                CoCamera *pCamera,
                CoLight *pLight);
    ~CoShapeCore();

    void initialize() override {}
    void paint() override {}

protected:
    CoVertexArrayObject*  m_pVertexArrayObject;
    CoVertexBufferObject* m_pVertexBufferObject;
    CoVertexBufferObject* m_pCBO;

    Guint    m_nWidthID;
};

#endif // COSHAPECORE_H
