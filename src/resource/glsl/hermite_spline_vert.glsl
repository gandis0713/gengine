#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 color;
layout (location = 2) in int size;

out vec3 vertColor;
out int vertIndex;

void main()
{
    gl_Position = vec4(vertex, 1.0);
    vertColor = color;

    vertIndex = gl_VertexID;
    if(gl_VertexID == size - 6)
    {
        vertIndex = -1;
    }
}
