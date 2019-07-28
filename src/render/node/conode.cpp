#include "conode.h"

CoNode::CoNode()
    :m_eShaderProgramType(EShaderProgramType::ePoint)
{
}

CoNode::~CoNode()
{
}

EShaderProgramType CoNode::getShaderProgramType()
{
    return m_eShaderProgramType;
}
