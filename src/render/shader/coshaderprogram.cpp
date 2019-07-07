#include "coglextension.h"
#include "coshaderprogram.h"

#include "delog.h"

#include <vector>

CoShaderProgram::CoShaderProgram()
{
    initializeShaders();
}

CoShaderProgram::~CoShaderProgram()
{
    // do nothing.
}

Guint CoShaderProgram::getUniformLocation(Gstring strName)
{
    return glGetUniformLocation(m_nProgramID, strName.c_str());
}

Guint CoShaderProgram::getAttribLocation(Gstring strName)
{
    return glGetAttribLocation(m_nProgramID, strName.c_str());
}


void CoShaderProgram::setUniformMatrix4fv(Guint nID, CoMat4x4 mat4)
{
    glUniformMatrix4fv(nID, 1, GL_FALSE, &mat4[0]);
}

void CoShaderProgram::bind()
{
    glUseProgram(m_nProgramID);
}

void CoShaderProgram::initializeShaders()
{
    createProgram();
    link();
    check();
}

void CoShaderProgram::AddShaders(EShaderType eShaderType, const Gchar *pSource)
{
    auto ret = m_mapShaders.insert( { eShaderType , nullptr } );
    if (ret.second)
    {
        CoShader *pShader = new CoShader(eShaderType);
        ret.first->second = pShader;
    }
}

void CoShaderProgram::AddShaders(EShaderType eShaderType, Gstring strFileName)
{
    auto ret = m_mapShaders.insert( { eShaderType , nullptr } );
    if (ret.second)
    {
        CoShader *pShader = new CoShader(eShaderType);
        ret.first->second = pShader;
    }
}

void CoShaderProgram::createProgram()
{
    m_nProgramID = glCreateProgram();
    if(m_nProgramID <= 0)
    {
        tlog("Invalid ID for program.");
    }
}

void CoShaderProgram::link()
{
    std::map<EShaderType, CoShader*>::iterator iter;
    for(iter = m_mapShaders.begin(); iter != m_mapShaders.end(); ++iter)
    {
        CoShader *pShader = iter->second;
        if(pShader)
        {
            glAttachShader(m_nProgramID, pShader->getID());
        }
    }

    if(m_nProgramID <= 0)
    {
        tlog("Invalid Program ID.");
        return;
    }

    glLinkProgram(m_nProgramID);
}

void CoShaderProgram::Release()
{
    std::map<EShaderType, CoShader*>::iterator iter;
    for(iter = m_mapShaders.begin(); iter != m_mapShaders.end(); ++iter)
    {
        CoShader *pShader = iter->second;
        if(pShader)
        {
            glDetachShader(m_nProgramID, pShader->getID());
            glDeleteShader(pShader->getID());
        }
    }
}

bool CoShaderProgram::check()
{
    GLint nResult = GL_FALSE;
    int nInfoLogLength;

    glGetProgramiv(m_nProgramID, GL_LINK_STATUS, &nResult);
    glGetProgramiv(m_nProgramID, GL_INFO_LOG_LENGTH, &nInfoLogLength);
    if(nInfoLogLength > 0)
    {
        std::vector<char> strProgramErrorMessage(nInfoLogLength + 1);
        glGetProgramInfoLog(m_nProgramID, nInfoLogLength, NULL, &strProgramErrorMessage[0]);
        return false;
    }

    return true;
}
