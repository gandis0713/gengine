#ifndef CONODECORE_H
#define CONODECORE_H

#include "conode.h"
#include "cocamera.h"
#include "coshaderprogram.h"

class CoNodeCore
{
public:
    CoNodeCore();
    CoNodeCore(CoNode* pNode, CoCamera *pCamera);
    ~CoNodeCore();

    virtual void initialize() = 0;
    virtual void paint() = 0;

    void setCamera(CoCamera *pCamera);

protected:
    Guint                 m_nMVPID;

    CoNode*               m_pNode;
    CoCamera*             m_pCamera;
    CoShaderProgram*      m_pShaderProgram;
    EShaderProgramType    m_eShaderProgramType;
};

#endif // CONODECORE_H
