#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 2) in vec2 texCoord;

uniform mat4 mvp;

out vec2 outTexCoord;

vec4 clip(vec3 position)
{
    return mvp * vec4(position, 1.0);
}

void main()
{
    gl_Position = clip(vertex);
    outTexCoord = texCoord;
}
