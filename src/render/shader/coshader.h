#ifndef COSHADER_H
#define COSHADER_H

#include "deshader.h"
#include "dedatatype.h"

class CoShader
{
public:
    CoShader(EShaderType eShaderType);
    ~CoShader();

    void setSource(const Gstring& strSource);
    Gstring getSource() const;
    EShaderType getType() const;
    Guint getID();

    bool compile();

private:
    Guint                   m_nID;
    EShaderType             m_eType;
    Gstring                 m_strSource;

};

#endif // COSHADER_H
