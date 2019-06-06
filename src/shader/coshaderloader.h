#ifndef COSHADERLOADER_H
#define COSHADERLOADER_H

#include "qtheader.h"

class CoShaderLoader
{
public:
    CoShaderLoader(QOpenGLFunctions_2_1 *pGLFunctions);
    ~CoShaderLoader();

    GLuint ReadCustomShader(const GLenum eType, const char* pShaderPath);
    GLboolean ShaderLinking(const GLuint nProgramID, const GLuint nShaderIDs[], const int nShaderCount);

private:
    QOpenGLFunctions_2_1 *m_pGLFunctions;
};

#endif // COSHADERLOADER_H
