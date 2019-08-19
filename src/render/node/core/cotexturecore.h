#ifndef COTEXTURECORE_H
#define COTEXTURECORE_H

#include "coshapecore.h"
#include "covertexarrayobject.h"
#include "covertexbufferobject.h"

class CoTextureCore : public CoShapeCore
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

    void createObject() override;
    void createShaderProgram() override;
    void bindObject() override;
    void setUniformLocation() override;

protected:
    CoVertexBufferObject* m_pTextureBufferObject;
    CoVertexBufferObject* m_pIndexBufferObject;

private:
    Guint m_nTextureID;
};

#endif // COTEXTURECORE_H
