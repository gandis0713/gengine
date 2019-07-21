#ifndef CONODECORE_H
#define CONODECORE_H

#include "conode.h"
#include "cocamera.h"
#include "covertexarrayobject.h"
#include "covertexbufferobject.h"
#include "coshaderprogram.h"

class CoNodeCore
{
public:
    CoNodeCore(CoNode* pNode, CoCamera *pCamera);
    ~CoNodeCore();

    virtual void initialize() = 0;
    virtual void paint() = 0;

    void setCamera(CoCamera *pCamera);

protected:
    CoNode*               m_pNode;
    CoCamera*             m_pCamera;

    CoVertexArrayObject*  m_pVAO;
    CoVertexBufferObject* m_pVBO;
    CoVertexBufferObject* m_pCBO;
    CoShaderProgram*      m_pShaderProgram;
    EShaderProgramType    m_eShaderProgramType;
};

#endif // CONODECORE_H
