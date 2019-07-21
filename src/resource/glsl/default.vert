#version 120

attribute vec3 vertex;
attribute vec3 color;

varying vec3 fragmentColor;
uniform mat4 perViewModel;

void main()
{
    gl_Position = perViewModel * vec4(vertex, 1);
    fragmentColor = color;
}
