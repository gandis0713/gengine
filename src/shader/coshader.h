#ifndef COSHADER_H
#define COSHADER_H

#include <QString>
#include <QOpenGLFunctions_2_1>

#include "deshader.h"
#include "../common/datatype/dedatatype.h"

class CoShader
{
public:
    CoShader(QOpenGLFunctions_2_1 *pGLFunctions);
    ~CoShader();

    bool createShader(const char* pPath);
    bool createShader();

    Cbuint getID();

protected:
    virtual bool setShaderType() = 0;
    virtual bool setShaderSource() = 0;
    bool initialize();

protected:
    CbChar*                  m_pShaderSource;
    Cbuint                   m_nID;
    EShaderType              m_eType;

private:
    Cbuint getGLShaderType(EShaderType eShaderType);

private:
    QOpenGLFunctions_2_1 *m_pGLFunctions;

};

#endif // COSHADER_H
