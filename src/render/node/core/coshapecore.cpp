#include "coshapecore.h"

CoShapeCore::CoShapeCore()
{

}

CoShapeCore::CoShapeCore(CoNode* pNode, CoCamera *pCamera)
    :CoNodeCore(pNode, pCamera)
    ,m_pVAO(NULL)
    ,m_pVBO(NULL)
    ,m_pCBO(NULL)
{
}

CoShapeCore::~CoShapeCore()
{

}
