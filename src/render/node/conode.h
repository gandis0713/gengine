#ifndef CONODE_H
#define CONODE_H

#include "coglextension.h"
#include "deengine.h"
#include "covector3.h"
#include "deshader.h"

#include <vector>

class GANDISENGINE CoNode
{
public:
    CoNode();
    ~CoNode();
    EShaderProgramType getShaderProgramType();

protected:
    EShaderProgramType  m_eShaderProgramType;
};

#endif // CONODE_H
