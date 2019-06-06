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
    return true;
}

bool CoShader::createVertexShader()
{
    return true;
}
