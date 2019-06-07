#include "coshader.h"

#include <QDebug>

#include "../common/util/noreader.h"

CoShader::CoShader(QOpenGLFunctions_2_1 *pGLFunctions)
    : m_pGLFunctions(pGLFunctions)
{
}

CoShader::~CoShader()
{
    // do nothing.
}

bool CoShader::initialize()
{
    setShaderType();
    setShaderSource();

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
    if(!m_pGLFunctions)
    {
        qDebug() << __FUNCTION__ << "The OpenGL Functions is null";
        return false;
    }

    m_nID = m_pGLFunctions->glCreateShader(getGLShaderType(m_eType));
    qDebug() << __FUNCTION__ << "The created shader ID : " << m_nID;
    if(m_nID <= 0)
    {
        return false;
    }

    bool bCreateShaderSource = setShaderSource();
    if(false == bCreateShaderSource)
    {
        qDebug() << __FUNCTION__ << "The shader source is not created.";
        return false;
    }

    GLint nResult = GL_FALSE;
    int nInfoLogLength;

    m_pGLFunctions->glShaderSource(m_nID, 1, &m_pShaderSource , NULL);
    m_pGLFunctions->glCompileShader(m_nID);

    m_pGLFunctions->glGetShaderiv(m_nID, GL_COMPILE_STATUS, &nResult);
    m_pGLFunctions->glGetShaderiv(m_nID, GL_INFO_LOG_LENGTH, &nInfoLogLength);
    if ( nInfoLogLength > 0 ){
        std::vector<char> strErrMsg(nInfoLogLength + 1);
        m_pGLFunctions->glGetShaderInfoLog(m_nID, nInfoLogLength, NULL, &strErrMsg[0]);

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
