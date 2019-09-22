#ifndef STRUCTS_GLSL
#define STRUCTS_GLSL

struct SLight
{
    float fPower;
    vec3 vColor;
    vec3 vPosition;
};

struct SMaterial
{
    vec3 vDiffuseColor;
    vec3 vAmbientColor;
    vec3 vSpecularColor;
};

#endif
