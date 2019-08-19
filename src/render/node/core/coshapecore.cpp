#include "coshapecore.h"

CoShapeCore::CoShapeCore()
{

}

CoShapeCore::CoShapeCore(CoNode* pNode,
                         CoCamera *pCamera,
                         CoLight *pLight)
    :CoNodeCore(pNode, pCamera, pLight)
    ,m_pVAO(NULL)
    ,m_pVBO(NULL)
    ,m_pCBO(NULL)
{
}

CoShapeCore::~CoShapeCore()
{

}
