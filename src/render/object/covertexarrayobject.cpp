#include "coglextension.h"
#include "covertexarrayobject.h"

CoVertexArrayObject::CoVertexArrayObject()
    : m_nID(0)
{
}

CoVertexArrayObject::~CoVertexArrayObject()
{

}

void CoVertexArrayObject::gen()
{
    glGenVertexArrays(1, &m_nID);
}
void CoVertexArrayObject::bind()
{
    glBindVertexArray(m_nID);
}

void CoVertexArrayObject::release()
{
    glBindVertexArray(0);
}
