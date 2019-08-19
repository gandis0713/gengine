#ifndef COSHADERPROGRAM_H
#define COSHADERPROGRAM_H

#include "coshader.h"
#include "comatrix4x4.h"

#include <map>

#define VERTEX_IN_LAYOUT          0
#define VERTEXNORMAL_IN_LAYOUT    1
#define TEXTURE_IN_LAYOUT         2

class CoShaderProgram
{
public:

    CoShaderProgram();
    ~CoShaderProgram();

    void AddShaders(EShaderType eShaderType, QString strSource);
    void bind();
    void link();

    void enableAttributeVertexArray(Guint nID);
    void setVertexAttribPointer(Guint nID, Guint nSize, Guint nOffset);

    Guint getUniformLocation(Gstring strName);
    Guint getAttribLocation(Gstring strName);
    void setUniformMatrix4fv(Guint nID, CoMat4x4 mat4);
    void setUniform1f(Guint nID, Gfloat fValue);

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
