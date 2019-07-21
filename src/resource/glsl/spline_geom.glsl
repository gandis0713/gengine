#version 430

layout (lines) in;
layout (line_strip, max_vertices = 50) out;

in vec3 vertColor[];
out vec3 fragColor;

uniform mat4 mvp;

vec4 clip(vec4 vec)
{
    return mvp * vec;
}

void main()
{
    fragColor = vertColor[0];
    for(int i = 0; i < gl_in.length(); i++)
    {
        gl_Position = clip(gl_in[i].gl_Position);
        EmitVertex();
    }

    EndPrimitive();
}
