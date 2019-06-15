#include "noshaderhelper.h"

#include <GL/glew.h>

namespace NoShaderHelper
{
Cbuint getGLShaderType(EShaderType eShaderType)
{
    Cbuint nShaderType = GL_VERTEX_SHADER;
    switch (eShaderType)
    {
    case EShaderType::eFragment:
        nShaderType = GL_FRAGMENT_SHADER;
        break;
    case EShaderType::eVertex:
    default:
        nShaderType = GL_VERTEX_SHADER;
        break;
    }
    return nShaderType;
}
}

