#ifndef COSHADERPROGRAM_H
#define COSHADERPROGRAM_H

#include "coshader.h"
#include "comatrix4x4.h"

#include <map>

#define VERTEX_IN_LAYOUT          0
#define COLOR_IN_LAYOUT           1

class CoShaderProgram
{
public:

    CoShaderProgram();
    ~CoShaderProgram();

    void AddShaders(EShaderType eShaderType, QString strSource);
    void bind();
    void link();
    virtual void getUniform() = 0;

    void enableAttributeArray(Guint nID);
    void setAttributeBuffer(Guint nID, Guint nSize, Guint nOffset);

    Guint getUniformLocation(Gstring strName);
    Guint getAttribLocation(Gstring strName);
    void setUniformMatrix4fv(Guint nID, CoMat4x4 mat4);

    Guint m_nMVPID;

private:
    void initialize();
    void createProgram();
    void release();
    bool check();

private:
    std::map<EShaderType, CoShader*>  m_mapShaders;
    Guint m_nProgramID;
};

#endif // COSHADERPROGRAM_H
