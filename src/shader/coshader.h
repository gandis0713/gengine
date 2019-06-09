#ifndef COSHADER_H
#define COSHADER_H

#include "deshader.h"
#include "dedatatype.h"

#include <GL/glew.h>

class CoShader
{
public:
    CoShader();
    ~CoShader();

    void setSource(const CbString& strSource = CbString());
    CbString getSource() const;
    void setType(const EShaderType& eShaderType);
    EShaderType getType() const;

    bool compile();
    Cbuint getID();

protected:
    virtual CbString getDefaultSource() = 0;

protected:
    Cbuint                   m_nID;
    EShaderType              m_eType;
    CbString                 m_strSource;

private:
    Cbuint getGLShaderType(EShaderType eShaderType);

};

#endif // COSHADER_H
