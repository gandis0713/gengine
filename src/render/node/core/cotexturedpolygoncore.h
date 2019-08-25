#ifndef COTEXTUREDPOLYGONCORE_H
#define COTEXTUREDPOLYGONCORE_H

#include "coshapecore.h"

class CoTexturedPolygonCore : public CoShapeCore
{
public:
    CoTexturedPolygonCore();
    CoTexturedPolygonCore(CoNode* pNode,
                  CoCamera *pCamera,
                  CoLight *pLight);
    ~CoTexturedPolygonCore();

    void initialize() override;
    void paint() override;

protected:

    void createObject() override;
    void createShaderProgram() override;
    void bindObject() override;
    void setUniformLocation() override;

protected:
    CoVertexBufferObject* m_pVertexNormalBufferObject;
    CoVertexBufferObject* m_pTextureBufferObject;
    CoVertexBufferObject* m_pIndexBufferObject;
private:
    Guint m_nTextureID;
};

#endif // COTEXTUREDPOLYGONCORE_H
