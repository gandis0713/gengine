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

    void AddShaders(EShaderType eShaderType, QString strSource);
    void bind();
    void link();
    virtual void setUniform() = 0;
    virtual void setAttribute() = 0;

    void enableAttributeArray(Guint nID);
    void setAttributeBuffer(Guint nID, Guint nSize, Guint nOffset);

    Guint getUniformLocation(Gstring strName);
    Guint getAttribLocation(Gstring strName);
    void setUniformMatrix4fv(Guint nID, CoMat4x4 mat4);

    Guint m_nMatrixID;
    Guint m_nVertexID;
    Guint m_nColorID;

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
