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

    void setSource(const GString& strSource);
    GString getSource() const;
    void setType(const EShaderType& eShaderType);
    EShaderType getType() const;
    Guint getID();

    bool compile();

protected:
    virtual void initializeShader() = 0;
    virtual void initType() = 0;
    virtual void initSource() = 0;

protected:
    Guint                   m_nID;
    EShaderType              m_eType;
    GString                 m_strSource;

};

#endif // COSHADER_H
