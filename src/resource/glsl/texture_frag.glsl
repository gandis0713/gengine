#version 430 core

in vec3 outColor;
in vec2 outTexCoord;

uniform sampler2D texture2D;
uniform float textureScale;

void main()
{
    gl_FragColor = texture(texture2D, outTexCoord);
}
