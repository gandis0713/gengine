#include "coglextension.h"
#include "codefaultshaderprogram.h"
#include <QDebug>

CoDefaultShaderProgram::CoDefaultShaderProgram()
{
    // do nothing.
}

CoDefaultShaderProgram::~CoDefaultShaderProgram()
{
    // do nothing.
}

void CoDefaultShaderProgram::setUniform()
{
    m_nMatrixID = getUniformLocation("perViewModel");
}

void CoDefaultShaderProgram::setAttribute()
{
    m_nVertexID = getAttribLocation("vertex");
    m_nColorID = getAttribLocation("color");
}
