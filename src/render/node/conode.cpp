#include "conode.h"

CoNode::CoNode()
    :m_eShaderProgramType(EShaderProgramType::eDefault)
{
}

CoNode::~CoNode()
{
}

EShaderProgramType CoNode::getShaderProgramType()
{
    return m_eShaderProgramType;
}
