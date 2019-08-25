#ifndef COIMAGECORE_H
#define COIMAGECORE_H

#include "coshapecore.h"
#include "covertexarrayobject.h"
#include "covertexbufferobject.h"

class CoImageCore : public CoShapeCore
{
public:
    CoImageCore();
    CoImageCore(CoNode* pNode,
                  CoCamera *pCamera,
                  CoLight *pLight);
    ~CoImageCore();

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

#endif // COIMAGECORE_H
