#include <GL/glew.h>
#include "coshader.h"
#include "noshaderhelper.h"

#include "noreader.h"
#include "delog.h"


#include <vector>

CoShader::CoShader()
{
}

CoShader::~CoShader()
{
    // do nothing.
}

void CoShader::setSource(const GString& strSource)
{
    if(strSource.empty())
    {
        return;
    }

    m_strSource = strSource;
//    std::string strShaderPath(pPath);
//    std::string strShaderSource;
//    bool bState = NoReader::ReadText(pPath, strShaderSource);
//    if(!bState)
//    {
//        tlog("The shader source code can't be opened.");
//        return false;
//    }

//    return SetSource();
}

GString CoShader::getSource() const
{
    return m_strSource;
}


void CoShader::setType(const EShaderType& eShaderType)
{
    m_eType = eShaderType;
}

EShaderType CoShader::getType() const
{
    return m_eType;
}

Guint CoShader::getID()
{
    return m_nID;
}

bool CoShader::compile()
{
    m_nID = glCreateShader(NoShaderHelper::getGLShaderType(m_eType));
    if(m_nID <= 0)
    {
        tlog("Failed to create shader.");
        return false;
    }

    GLint nResult = GL_FALSE;
    GLint nLogLength;

    const GLchar *source = static_cast<const GLchar *>(m_strSource.c_str());
    glShaderSource(m_nID, 1, &source, NULL);
    glCompileShader(m_nID);

    glGetShaderiv(m_nID, GL_COMPILE_STATUS, &nResult);
    glGetShaderiv(m_nID, GL_INFO_LOG_LENGTH, &nLogLength);

    if ( nLogLength > 0 )
    {
        std::vector<char> strErrMsg(nLogLength + 1);
        glGetShaderInfoLog(m_nID, nLogLength, NULL, &strErrMsg[0]);

        tlog("The erroe message from shader : ");
        tlog(&strErrMsg[0]);

        return false;
    }

    return true;
}


