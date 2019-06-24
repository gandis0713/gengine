#include <GL/glew.h>
#include "noshaderhelper.h"


namespace NoShaderHelper
{
Guint getGLShaderType(EShaderType eShaderType)
{
    Guint nShaderType = GL_VERTEX_SHADER;
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

