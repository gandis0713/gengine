#version 430 core

in vec2 outTexCoord;

uniform sampler2D texture2D;

void main()
{
    gl_FragColor = texture(texture2D, outTexCoord);
}
