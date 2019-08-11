#version 430 core

layout(location = 0) in vec3 vertex_m;
layout(location = 1) in vec3 color;
layout(location = 2) in vec3 vertexNormal_m;

out vec3 vertColor;

uniform mat4 mvp;
uniform mat4 v;
uniform mat4 m;

out vec3 vertex_w;
out vec3 vertexNormal_c;
out vec3 eyeDir_c;
out vec3 lightDir_c;

uniform vec3 lightPos_w;

void main()
{
    vec3 lightPos_t = vec3(0, 0, 4000);
    // Output position of the vertex, in clip space : MVP * position
    gl_Position =  mvp * vec4(vertex_m,1);

    // Position of the vertex, in worldspace : M * position
    vertex_w = (m * vec4(vertex_m,1)).xyz;

    // Vector that goes from the vertex to the camera, in camera space.
    // In camera space, the camera is at the origin (0,0,0).
    vec3 vertex_c = ( v * m * vec4(vertex_m,1)).xyz;
    eyeDir_c = vec3(0,0,0) - vertex_c;

    // Vector that goes from the vertex to the light, in camera space. M is ommited because it's identity.
    vec3 lightPos_c = ( v * vec4(lightPos_t, 1)).xyz;
    lightDir_c = lightPos_c + eyeDir_c;

    // Normal of the the vertex, in camera space
    vertexNormal_c = ( v * m * vec4(vertexNormal_m, 0)).xyz; // Only correct if ModelMatrix does not scale the model ! Use its inverse transpose if not.

    vertColor = color;
}
