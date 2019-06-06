#ifndef CODEFAULTSHADER_H
#define CODEFAULTSHADER_H

const char* pDefaultVertexShader =
"#version 120                                                                        \
                                                                                     \
// Input vertex data, different for all executions of this shader.                   \
attribute vec3 vertex;                                                               \
attribute vec3 color;                                                                \
                                                                                     \
// Output data ; will be interpolated for each fragment.                             \
varying vec3 fragmentColor;                                                          \
// Values that stay constant for the whole mesh.                                     \
uniform mat4 perViewModel;                                                           \
                                                                                     \
void main(){	                                                                     \
                                                                                     \
    // Output position of the vertex, in clip space : MVP * position                 \
    gl_Position =  perViewModel * vec4(vertex,1);                                    \
                                                                                     \
    // The color of each vertex will be interpolated                                 \
    // to produce the color of each fragment                                         \
    fragmentColor = color;                                                           \
}                                                                                    \
";

const char* pDefaultFragShader =
"#version 120                                                                        \
                                                                                     \
// Input vertex data, different for all executions of this shader.                   \
attribute vec3 vertex;                                                               \
attribute vec3 color;                                                                \
                                                                                     \
// Output data ; will be interpolated for each fragment.                             \
varying vec3 fragmentColor;                                                          \
// Values that stay constant for the whole mesh.                                     \
uniform mat4 perViewModel;                                                           \
                                                                                     \
void main(){	                                                                     \
                                                                                     \
    // Output position of the vertex, in clip space : MVP * position                 \
    gl_Position =  perViewModel * vec4(vertex,1);                                    \
                                                                                     \
    // The color of each vertex will be interpolated                                 \
    // to produce the color of each fragment                                         \
    fragmentColor = color;                                                           \
}                                                                                    \
";

#endif // CODEFAULTSHADER_H
