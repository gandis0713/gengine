#ifndef DEDEFAULTVERTEXSHADER_H
#define DEDEFAULTVERTEXSHADER_H

const char* pDefaultVertexShader =
"#version 120                                                                                                        \n\
                                                                                                                     \n\
// Input vertex data, different for all executions of this shader.                                                   \n\
attribute vec3 vertex;                                                                                               \n\
attribute vec3 color;                                                                                                \n\
                                                                                                                     \n\
// Output data ; will be interpolated for each fragment.                                                             \n\
varying vec3 fragmentColor;                                                                                          \n\
// Values that stay constant for the whole mesh.                                                                     \n\
uniform mat4 perViewModel;                                                                                           \n\
                                                                                                                     \n\
void main(){	                                                                                                     \n\
                                                                                                                     \n\
    // Output position of the vertex, in clip space : MVP * position                                                 \n\
    gl_Position =  perViewModel * vec4(vertex,1);                                                                    \n\
                                                                                                                     \n\
    // The color of each vertex will be interpolated                                                                 \n\
    // to produce the color of each fragment                                                                         \n\
    fragmentColor = color;                                                                                           \n\
}                                                                                                                    \n\
";

#endif // DEDEFAULTVERTEXSHADER_H
