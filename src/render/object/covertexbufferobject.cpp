#include "coglextension.h"
#include "covertexbufferobject.h"

CoVertexBufferObject::CoVertexBufferObject()
    : m_nID(0)
    , m_eUsagePattern(EUsagePattern::eStaticDraw)
    , m_eType(EType::eVertexArray)
{
}

CoVertexBufferObject::~CoVertexBufferObject()
{
    release();
}

void CoVertexBufferObject::gen()
{
    glGenBuffers(1, &m_nID);
}

void CoVertexBufferObject::bind()
{
    glBindBuffer(m_eType, m_nID);
}

void CoVertexBufferObject::release()
{
    glDeleteBuffers(1, &m_nID);
}

void CoVertexBufferObject::setUsagePattern(EUsagePattern eUsagePattern)
{
    m_eUsagePattern = eUsagePattern;
}

void CoVertexBufferObject::setType(EType eType)
{
    m_eType = eType;
}

void CoVertexBufferObject::allocate(const void *pData, Guint nSize)
{
    glBufferData(m_eType, nSize, pData, m_eUsagePattern);
}

Guint CoVertexBufferObject::getID()
{
    return m_nID;
}
