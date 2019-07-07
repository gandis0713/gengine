#ifndef COSHADERPROGRAM_H
#define COSHADERPROGRAM_H

#include "coshader.h"
#include "comatrix4x4.h"

#include <map>

class CoShaderProgram
{
public:
    CoShaderProgram();
    ~CoShaderProgram();

    Guint getUniformLocation(Gstring strName);
    Guint getAttribLocation(Gstring strName);
    void setUniformMatrix4fv(Guint nID, CoMat4x4 mat4);
    void bind();

private:
    void initializeShaders();
    void AddShaders(EShaderType eShaderType, const Gchar *pSource);
    void AddShaders(EShaderType eShaderType, Gstring strFileName);
    void createProgram();
    void link();
    void Release();
    bool check();

private:
    std::map<EShaderType, CoShader*>         m_mapShaders;
    Guint m_nProgramID;
};

#endif // COSHADERPROGRAM_H
