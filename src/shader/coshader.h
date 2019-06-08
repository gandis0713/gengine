#ifndef COSHADER_H
#define COSHADER_H

#include <QString>

#include "deshader.h"
#include "dedatatype.h"

#include <GL/glew.h>

class CoShader
{
public:
    CoShader();
    ~CoShader();

    bool createShader(const char* pPath);
    bool createShader();

    Cbuint getID();

protected:
    virtual bool setShaderType() = 0;
    virtual const GLchar* getShaderSource() = 0;
    bool initialize();

protected:
    Cbuint                   m_nID;
    EShaderType              m_eType;

private:
    Cbuint getGLShaderType(EShaderType eShaderType);

};

#endif // COSHADER_H
