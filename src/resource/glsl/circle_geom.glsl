#version 430

layout (lines) in;
layout(line_strip, max_vertices = 200)out;

uniform mat4 mvp;

in vec3 vertColor[];
in float vertWidth[];

out vec3 fragColor;

void main()
{
    //float PI = 3.14159265358979323846264;  //unused

    vec4 pos = vec4(0,0,0,1);  //introduce a single vertex at the origin
    pos = mvp * pos;  //translate it to where our model is
    //ideally do this step outside the shader

    for(float i = 0; i < 6.4 ; i+=0.1)  //generate vertices at positions on the circumference from 0 to 2*pi
    {
        fragColor = vertColor[0];
        gl_Position = vec4(pos.x+0.5*cos(i), pos.y+0.5*sin(i), pos.z,1.0);   //circle parametric equation
        EmitVertex();
    }
}
