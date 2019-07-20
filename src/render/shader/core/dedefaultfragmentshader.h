#ifndef DESHADERSOURCE_H
#define DESHADERSOURCE_H

#include "dedatatype.h"

Gstring strDefaultFragShader =
"                                                                                                                    \n\
#version 120                                                                                                         \n\
                                                                                                                     \n\
// Interpolated values from the vertex shaders                                                                       \n\
varying vec3 fragmentColor;                                                                                          \n\
                                                                                                                     \n\
void main()                                                                                                          \n\
{                                                                                                                    \n\
    // Output color = color specified in the vertex shader,                                                          \n\
    // interpolated between all 3 surrounding vertices                                                               \n\
    gl_FragColor = vec4(fragmentColor, 1);                                                                           \n\
}                                                                                                                    \n\
";

#endif // DESHADERSOURCE_H
