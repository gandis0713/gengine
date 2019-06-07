#include "coshadermanager.h"

#include "covertexshader.h"
#include "cofragmentshader.h"

CoShaderManager::CoShaderManager(QOpenGLFunctions_2_1 *pGLFunctions)
    : m_pGLFunctions(pGLFunctions)
{
    createShaders();
}

CoShaderManager::~CoShaderManager()
{
    qDeleteAll(m_mapShaders);
}

bool CoShaderManager::createShaders()
{
    m_mapShaders.clear();

    CoShader *pVertexShader = new CoVertexShader(m_pGLFunctions);
    m_mapShaders.insert(EShaderType::eVertex, pVertexShader);

    CoShader *pFragmentShader = new CoFragmentShader(m_pGLFunctions);
    m_mapShaders.insert(EShaderType::eFragment, pFragmentShader);

    return true;
}
