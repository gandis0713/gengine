#ifndef STRUCTS_GLSL
#define STRUCTS_GLSL

layout(std140) uniform Light
{
    float fPower;
    vec3 vColor;
    vec3 vPosition;
};

layout(std140) uniform Material
{
    vec3 vDiffuseColor;
    vec3 vAmbientColor;
    vec3 vSpecularColor;
};

layout(std140) uniform Camera
{
    mat4 mWorldToView;
    mat4 mWorldToClip;
    mat4 mViewToClip;
};

#endif
