#include "conodecore.h"

CoNodeCore::CoNodeCore()
{

}

CoNodeCore::CoNodeCore(CoNode* pNode,
                       CoCamera *pCamera,
                       CoLight *pLight)
    : m_pNode(pNode)
    , m_pCamera(pCamera)
    , m_pLight(pLight)
    ,m_pShaderProgram(NULL)
{
    m_eShaderProgramType = m_pNode->getShaderProgramType();
}

CoNodeCore::~CoNodeCore()
{

}

void CoNodeCore::setCamera(CoCamera *pCamera)
{
    m_pCamera = pCamera;
}

void CoNodeCore::setLight(CoLight *pLight)
{
    m_pLight = pLight;
}

