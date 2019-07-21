#ifndef COVERTEXBUFFEROBJECT_H
#define COVERTEXBUFFEROBJECT_H

#include "dedatatype.h"

class CoVertexBufferObject
{
public:
    enum EUsagePattern
    {
        eStreamDraw = 0x88E0,
        eStreamRead = 0x88E1,
        eStreamCopy = 0x88E2,

        eStaticDraw = 0x88E4,
        eStaticRead = 0x88E5,
        eStaticCopy = 0x88E6,

        eDynamicDraw = 0x88E8,
        eDynamicRead = 0x88E9,
        eDynamicCopy = 0x88EA
    };

    enum EType
    {
        eVertexArray = 0x8892,
        eIndexArray = 0x8893,
        ePixelPack = 0x88EB,
        ePixelUnpack = 0x88EC
    };

public:
    CoVertexBufferObject();
    ~CoVertexBufferObject();

    void gen();
    void bind();
    void release();
    void setUsagePattern(EUsagePattern eUsagePattern);
    void setType(EType eType);
    void setAllocate(const void *pData, Guint nSize);

private:
    Guint m_nID;
    EUsagePattern m_eUsagePattern;
    EType         m_eType;
};

#endif // COVERTEXBUFFEROBJECT_H
