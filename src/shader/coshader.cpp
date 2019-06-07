#include "coshader.h"

#include <QDebug>

#include "../common/util/noreader.h"

#include <GL/glew.h>

CoShader::CoShader()
{
}

CoShader::~CoShader()
{
    // do nothing.
}

bool CoShader::initialize()
{
    setShaderType();

    if(!createShader())
    {
        qDebug() << __FUNCTION__ << "Failed to initialized shader.";
        return false;
    }

    return true;
}

bool CoShader::createShader(const char* pPath)
{
    std::string strShaderPath(pPath);
    std::string strShaderSource;
    bool bState = NoReader::ReadText(pPath, strShaderSource);
    if(!bState)
    {
        qDebug() << __FUNCTION__ << "The shader source code can't be opened ";
        return false;
    }

    return createShader();
}

bool CoShader::createShader()
{
    m_nID = glCreateShader(getGLShaderType(m_eType));
    qDebug() << __FUNCTION__ << "The created shader ID : " << m_nID;
    if(m_nID <= 0)
    {
        return false;
    }

    const GLchar* cShaderSource = getShaderSource();
//    if(false == bCreateShaderSource)
//    {
//        qDebug() << __FUNCTION__ << "The shader source is not created.";
//        return false;
//    }

    GLint nResult = GL_FALSE;
    int nInfoLogLength;

    glShaderSource(m_nID, 1, &cShaderSource , NULL);
    glCompileShader(m_nID);

    glGetShaderiv(m_nID, GL_COMPILE_STATUS, &nResult);
    glGetShaderiv(m_nID, GL_INFO_LOG_LENGTH, &nInfoLogLength);
    if ( nInfoLogLength > 0 ){
        std::vector<char> strErrMsg(nInfoLogLength + 1);
        glGetShaderInfoLog(m_nID, nInfoLogLength, NULL, &strErrMsg[0]);

        qDebug() << __FUNCTION__ << "The erroe message from shader : " << &strErrMsg[0];

        return false;
    }

    return true;
}

Cbuint CoShader::getID()
{
    return m_nID;
}

Cbuint CoShader::getGLShaderType(EShaderType eShaderType)
{
    Cbuint nShaderType = GL_VERTEX_SHADER;
    switch (eShaderType)
    {
    case EShaderType::eFragment:
        nShaderType = GL_FRAGMENT_SHADER;
        break;
    case EShaderType::eVertex:
    default:
        nShaderType = GL_VERTEX_SHADER;
        break;
    }
    return nShaderType;
}
