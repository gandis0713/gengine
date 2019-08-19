#include "coshapecore.h"

CoShapeCore::CoShapeCore()
{

}

CoShapeCore::CoShapeCore(CoNode* pNode,
                         CoCamera *pCamera,
                         CoLight *pLight)
    :CoNodeCore(pNode, pCamera, pLight)
    ,m_pVertexArrayObject(NULL)
    ,m_pVertexBufferObject(NULL)
    ,m_pCBO(NULL)
{
}

CoShapeCore::~CoShapeCore()
{

}
