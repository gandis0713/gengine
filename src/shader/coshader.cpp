#include "coshader.h"

CoShader::CoShader()
{
    initializeShader();
}

CoShader::~CoShader()
{

}

bool createFragmentShader(const char* pPath)
{
    return true;
}

bool createVertexShader(const char* pPath)
{
    return true;
}

bool CoShader::initializeShader()
{
    createVertexShader();
    createFragmentShader();

    return true;
}

bool CoShader::createFragmentShader()
{
    return true;
}

bool CoShader::createVertexShader()
{
    return true;
}
