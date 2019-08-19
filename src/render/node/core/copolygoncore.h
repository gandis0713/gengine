#ifndef COPOLYGONCORE_H
#define COPOLYGONCORE_H

#include "coshapecore.h"

class CoPolygonCore : public CoShapeCore
{
public:
    CoPolygonCore();
    CoPolygonCore(CoNode* pNode,
                  CoCamera *pCamera,
                  CoLight *pLight);
    ~CoPolygonCore();

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

#endif // COPOLYGONCORE_H
