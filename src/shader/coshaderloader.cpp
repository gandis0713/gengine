#include "coshaderloader.h"

#include "../common/util/noreader.h"
#include <iostream>

using namespace std;

CoShaderLoader::CoShaderLoader(QOpenGLFunctions_2_1 *pGLFunctions)
    : m_pGLFunctions(pGLFunctions)
{

}

CoShaderLoader::~CoShaderLoader()
{

}

GLuint CoShaderLoader::ReadCustomShader(const GLenum eType, const char* pShaderPath)
{
    // 버텍스 쉐이더 코드를 파일에서 읽기
    std::string strShaderPath(pShaderPath);
    std::string strShaderSource;
    bool bState = NoReader::ReadText(pShaderPath, strShaderSource);
    if(!bState)
    {
        cout << "The shader source code can't be opened "<< endl;
        return 0;
    }

    if(!m_pGLFunctions)
    {
        cout << "The OpenGL Functions is null" << endl;
        return 0;
    }
    // 쉐이더들 생성
    GLuint nShaderID = m_pGLFunctions->glCreateShader(eType);
    cout << " nShaderID : " << nShaderID << endl;

    GLint nResult = GL_FALSE;
    int nInfoLogLength;

    // 버텍스 쉐이더를 컴파일
    const char* pShaderSource = strShaderSource.c_str();
    m_pGLFunctions->glShaderSource(nShaderID, 1, &pShaderSource , NULL);
    m_pGLFunctions->glCompileShader(nShaderID);

    // 버텍스 쉐이더를 검사
    m_pGLFunctions->glGetShaderiv(nShaderID, GL_COMPILE_STATUS, &nResult);
    m_pGLFunctions->glGetShaderiv(nShaderID, GL_INFO_LOG_LENGTH, &nInfoLogLength);

    if ( nInfoLogLength > 0 ){
        std::vector<char> strShaderErrorMessage(nInfoLogLength + 1);
        m_pGLFunctions->glGetShaderInfoLog(nShaderID, nInfoLogLength, NULL, &strShaderErrorMessage[0]);
        cout << "shader : " << &strShaderErrorMessage[0] << endl;
        return 0;
    }

    return nShaderID;
}


GLboolean CoShaderLoader::ShaderLinking(const GLuint nProgramID, const GLuint nShaderIDs[], const int nShaderCount)
{
    for(int nIndex = 0; nIndex < nShaderCount; nIndex++)
    {
        m_pGLFunctions->glAttachShader(nProgramID, nShaderIDs[nIndex]);
    }

    m_pGLFunctions->glLinkProgram(nProgramID);

    GLint nResult = GL_FALSE;
    int nInfoLogLength;
    // 프로그램 검사
    m_pGLFunctions->glGetProgramiv(nProgramID, GL_LINK_STATUS, &nResult);
    m_pGLFunctions->glGetProgramiv(nProgramID, GL_INFO_LOG_LENGTH, &nInfoLogLength);
    if ( nInfoLogLength > 0 ){
        std::vector<char> strProgramErrorMessage(nInfoLogLength + 1);
        m_pGLFunctions->glGetProgramInfoLog(nProgramID, nInfoLogLength, NULL, &strProgramErrorMessage[0]);
        cout << "The error message from progream : " << &strProgramErrorMessage[0] << endl;
        return 0;
    }

    for(int nIndex = 0; nIndex < nShaderCount; nIndex++)
    {
        m_pGLFunctions->glDetachShader(nProgramID, nShaderIDs[nIndex]);
        m_pGLFunctions->glDeleteShader(nShaderIDs[nIndex]);
    }

    return 1;
}
