#ifndef COSHADER_H
#define COSHADER_H

#include <QString>

#include "deshader.h"
#include "../common/datatype/dedatatype.h"

class CoShader
{
public:
    CoShader();
    ~CoShader();

protected:
    bool createFragmentShader(const char* pPath);
    bool createVertexShader(const char* pPath);

protected:
    CbString m_strShaderSource;
    Cbuint   m_nID;


private:
    bool initializeShader();
    bool createFragmentShader();
    bool createVertexShader();

private:

};

#endif // COSHADER_H
