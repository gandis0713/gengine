#ifndef COTEXTURECORE_H
#define COTEXTURECORE_H

#include "conodecore.h"
#include "covertexarrayobject.h"
#include "covertexbufferobject.h"

class CoTextureCore : public CoNodeCore
{
public:
    CoTextureCore();
    CoTextureCore(CoNode* pNode,
                  CoCamera *pCamera,
                  CoLight *pLight);
    ~CoTextureCore();

    void initialize() override;
    void paint() override;

protected:
    CoVertexArrayObject*  m_pVAO;
    CoVertexBufferObject* m_pVBO;
    CoVertexBufferObject* m_pCBO;
    CoVertexBufferObject* m_pTBO;
    CoVertexBufferObject* m_pIBO;

private:
    Guint m_nTextureID;
};

#endif // COTEXTURECORE_H
