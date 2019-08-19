#ifndef CONODECORE_H
#define CONODECORE_H

#include "conode.h"
#include "cocamera.h"
#include "colight.h"
#include "coshaderprogram.h"

class CoNodeCore
{
public:
    CoNodeCore();
    CoNodeCore(CoNode* pNode,
               CoCamera *pCamera,
               CoLight *pLight);
    ~CoNodeCore();

    virtual void initialize() = 0;
    virtual void paint() = 0;

    void setCamera(CoCamera *pCamera);    
    void setLight(CoLight *pLight);

protected:
    Guint                 m_nMVPID;

    CoNode*               m_pNode;
    CoCamera*             m_pCamera;
    CoLight*              m_pLight;
    CoShaderProgram*      m_pShaderProgram;
    EShaderProgramType    m_eShaderProgramType;
};

#endif // CONODECORE_H
