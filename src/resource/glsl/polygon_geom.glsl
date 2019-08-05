#version 430

layout (lines) in;
layout (triangle_strip, max_vertices = 4) out;

in vec3 vertColor[];
in float vertWidth[];

out vec3 fragColor;

uniform mat4 mvp;
uniform float width;

vec4 clip(vec4 vec)
{
    return mvp * vec;
}

void main()
{
    vec4 p1 = mvp * vec4(gl_in[0].gl_Position.xyz, 1.0);
    vec4 p2 = mvp * vec4(gl_in[1].gl_Position.xyz, 1.0);

    vec3 v1 = p1.xyz / (p1.w);
    vec3 v2 = p2.xyz / (p2.w);

    vec3 dir = cross(vec3(0, 0, 1), normalize(v2-v1));

    fragColor = vertColor[0];
    gl_Position = vec4(v1 - dir * width, 1.0);
    EmitVertex();
    gl_Position = vec4(v1 + dir * width, 1.0);
    EmitVertex();

    fragColor = vertColor[1];
    gl_Position = vec4(v2 - dir * width, 1.0);
    EmitVertex();
    gl_Position = vec4(v2 + dir * width, 1.0);
    EmitVertex();
}
