#ifndef COSHADERPROGRAM_H
#define COSHADERPROGRAM_H

#include "covertexshader.h"
#include "cofragmentshader.h"

#include <map>

class CoShaderProgram
{
public:
    CoShaderProgram();
    ~CoShaderProgram();

    Guint getUniformLocation(GString strName);
    Guint getAttribLocation(GString strName);
    void setUniformMatrix4fv(Guint nID, Gmat4 mat4);
    void bind();

private:
    void initializeShaders();
    void createShaders();
    void createProgram();
    void link();
    void Release();
    bool checkShaderProgram();

private:
    std::map<EShaderType, CoShader*>         m_mapShaders;
    Guint m_nProgramID;
};

#endif // COSHADERPROGRAM_H
