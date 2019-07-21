#include "coglextension.h"
#include "codefaultshaderprogram.h"

CoDefaultShaderProgram::CoDefaultShaderProgram()
{
    // do nothing.
}

CoDefaultShaderProgram::~CoDefaultShaderProgram()
{
    // do nothing.
}

void CoDefaultShaderProgram::getUniform()
{
    m_nMVPID = getUniformLocation("mvp");
}
