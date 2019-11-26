#version 130

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 color;

out vec3 fragColor;
uniform mat4 mvp;

vec4 clip(vec3 position)
{
    return mvp * vec4(position, 1.0);
}

void main()
{
    gl_Position = clip(vertex);
    fragColor = color;
}
