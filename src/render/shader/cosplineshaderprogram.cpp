#include "cosplineshaderprogram.h"

CoSplineShaderProgram::CoSplineShaderProgram()
{

}

CoSplineShaderProgram::~CoSplineShaderProgram()
{

}

void CoSplineShaderProgram::getUniform()
{
    m_nMVPID = getUniformLocation("mvp");
}
