#include "cosplineshaderprogram.h"

CoSplineShaderProgram::CoSplineShaderProgram()
{

}

CoSplineShaderProgram::~CoSplineShaderProgram()
{

}

void CoSplineShaderProgram::setUniform()
{
    m_nMatrixID = getUniformLocation("perViewModel");
}
void CoSplineShaderProgram::setAttribute()
{
    m_nVertexID = getAttribLocation("vertex");
    m_nColorID = getAttribLocation("color");
}
