#ifndef COSHADER_H
#define COSHADER_H

#include "deshader.h"
#include "dedatatype.h"

#include <GL/glew.h>

class CoShader
{
public:
    CoShader();
    virtual ~CoShader() =0;

    void setSource(const CbString& strSource);
    CbString getSource() const;
    void setType(const EShaderType& eShaderType);
    EShaderType getType() const;
    Cbuint getID();

    bool compile();

protected:
    virtual void initializeShader() = 0;
    virtual void initType() = 0;
    virtual void initSource() = 0;

protected:
    Cbuint                   m_nID;
    EShaderType              m_eType;
    CbString                 m_strSource;

};

#endif // COSHADER_H
