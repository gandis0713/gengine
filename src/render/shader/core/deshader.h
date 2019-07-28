#ifndef CODEFAULTSHADER_H
#define CODEFAULTSHADER_H

enum EShaderType
{
    eVertex           = 0x8B31, //GL_VERTEX_SHADER
    eFragment         = 0x8B30, //GL_FRAGMENT_SHADER
    eGeometry         = 0x8DD9  //GL_GEOMETRY_SHADER
};

enum EShaderProgramType
{
    ePoint,
    eLine,
    eSpline,
    eCircle,
    eTexture,
};

#endif // CODEFAULTSHADER_H
