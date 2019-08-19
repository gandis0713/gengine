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

    void setCamera(CoCamera *pCamera);    
    void setLight(CoLight *pLight);

    virtual void initialize() = 0;
    virtual void paint() = 0;
protected:

    virtual void createObject() = 0;
    virtual void createShaderProgram() = 0;
    virtual void bindObject() = 0;
    virtual void setUniformLocation() = 0;

protected:
    Guint                 m_nMVPID;
    Guint                 m_nVID;
    Guint                 m_nMID;
    Guint                 m_nLightPosID;
    Guint                 m_nLightColorID;
    Guint                 m_nLightPowerID;
    Guint                 m_nDiffuseColorID;
    Guint                 m_nAmbientColorID;
    Guint                 m_nSpecularColorID;

    CoNode*               m_pNode;
    CoCamera*             m_pCamera;
    CoLight*              m_pLight;
    CoShaderProgram*      m_pShaderProgram;
    EShaderProgramType    m_eShaderProgramType;
};

#endif // CONODECORE_H
