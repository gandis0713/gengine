#include "cocirclecore.h"

CoCircleCore::CoCircleCore()
{

}

CoCircleCore::CoCircleCore(CoNode* pNode,
                           CoCamera *pCamera,
                           CoLight *pLight)
    : CoLineCore(pNode, pCamera, pLight)
{

}
CoCircleCore::~CoCircleCore()
{

}

void CoCircleCore::initialize()
{
}

void CoCircleCore::paint()
{
}
