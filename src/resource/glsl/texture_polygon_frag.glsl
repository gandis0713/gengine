#version 120

in vec2 vertex_UV;
in vec3 vertex_w;
in vec3 vertexNormal_c;
in vec3 eyeDir_c;
in vec3 lightDir_c;

out vec3 color;

uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform float lightPower;

uniform vec3 diffuseColor;
uniform vec3 ambientColor;
uniform vec3 specularColor;

uniform sampler2D texture2D;

void main()
{
    color = texture( texture2D, vertex_UV ).rgb;
}
