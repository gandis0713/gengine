#version 430 core

layout (location = 0) in vec3 vertex;

uniform mat4 mvp;

vec4 clip(vec3 position)
{
    return mvp * vec4(position, 1.0);
}

void main()
{
    gl_Position = clip(vertex);
}
