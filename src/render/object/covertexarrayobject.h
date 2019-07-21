#ifndef COVERTEXARRYAOBJECT_H
#define COVERTEXARRYAOBJECT_H

#include "dedatatype.h"

class CoVertexArrayObject
{
public:
    CoVertexArrayObject();
    ~CoVertexArrayObject();

    void gen();
    void bind();
    void release();

private:
    Guint m_nID;
};

#endif // COVERTEXARRYAOBJECT_H
