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

    Cbuint getUniformLocation(CbString strName);
    Cbuint getAttribLocation(CbString strName);
    void setUniformMatrix4fv(Cbuint nID, Cbmat4 mat4);
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
    Cbuint m_nProgramID;
};

#endif // COSHADERPROGRAM_H
