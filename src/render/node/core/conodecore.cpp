#include "conodecore.h"

CoNodeCore::CoNodeCore(CoNode* pNode, CoCamera *pCamera)
    : m_pNode(pNode)
    , m_pCamera(pCamera)
    ,m_pVAO(NULL)
    ,m_pVBO(NULL)
    ,m_pCBO(NULL)
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
