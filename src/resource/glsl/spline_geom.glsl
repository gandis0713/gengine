#version 430

//layout (lines) in;
layout (lines_adjacency) in;
layout (line_strip, max_vertices = 100) out;

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

    int size = gl_in.length();

    float mcXC[100];
    float mcYC[100];
    float mcZC[100];

    float mcXD[100];
    float mcYD[100];
    float mcZD[100];

    float unXD[100];
    float unYD[100];
    float unZD[100];

    float coeXA[100];
    float coeXB[100];
    float coeXC[100];
    float coeXD[100];

    float coeYA[100];
    float coeYB[100];
    float coeYC[100];
    float coeYD[100];

    float coeZA[100];
    float coeZB[100];
    float coeZC[100];
    float coeZD[100];

    mcXC[0] = 1.f / 2.f;
    mcYC[0] = 1.f / 2.f;
    mcZC[0] = 1.f / 2.f;

    for(int i = 1; i < size - 1; i++)
    {
        mcXC[i] = 1.f / ( 4.f - mcXC[ i - 1 ] );
        mcYC[i] = 1.f / ( 4.f - mcYC[ i - 1 ] );
        mcZC[i] = 1.f / ( 4.f - mcZC[ i - 1 ] );
    }

    mcXC[size - 1] = 1.f / ( 2.f - mcXC[size - 2] );
    mcYC[size - 1] = 1.f / ( 2.f - mcYC[size - 2] );
    mcZC[size - 1] = 1.f / ( 2.f - mcZC[size - 2] );

    mcXD[0] = 3.f * ( gl_in[1].gl_Position.x - gl_in[0].gl_Position.x ) * mcXC[0];
    mcYD[0] = 3.f * ( gl_in[1].gl_Position.y - gl_in[0].gl_Position.y ) * mcYC[0];
    mcZD[0] = 3.f * ( gl_in[1].gl_Position.z - gl_in[0].gl_Position.z ) * mcZC[0];

    for(int i = 1; i < size - 1; i++)
    {
        mcXD[i] = ( 3.f * ( gl_in[i + 1].gl_Position.x - gl_in[i - 1].gl_Position.x ) - mcXD[i - 1]) * mcXC[i];
        mcYD[i] = ( 3.f * ( gl_in[i + 1].gl_Position.y - gl_in[i - 1].gl_Position.y ) - mcYD[i - 1]) * mcYC[i];
        mcZD[i] = ( 3.f * ( gl_in[i + 1].gl_Position.z - gl_in[i - 1].gl_Position.z ) - mcZD[i - 1]) * mcZC[i];
    }

    mcXD[size - 1] = ( 3.f * ( gl_in[size - 1].gl_Position.x - gl_in[size - 2].gl_Position.x ) - mcXD[size - 2] ) * mcXC[size - 1];
    mcYD[size - 1] = ( 3.f * ( gl_in[size - 1].gl_Position.y - gl_in[size - 2].gl_Position.y ) - mcYD[size - 2] ) * mcYC[size - 1];
    mcZD[size - 1] = ( 3.f * ( gl_in[size - 1].gl_Position.z - gl_in[size - 2].gl_Position.z ) - mcZD[size - 2] ) * mcZC[size - 1];

    unXD[size - 1] = mcXD[size - 1];
    unYD[size - 1] = mcYD[size - 1];
    unZD[size - 1] = mcZD[size - 1];

    for(int i = size - 2; i >= 0; i--)
    {
        unXD[i] = mcXD[i] - mcXC[i] * unXD[i + 1];
        unYD[i] = mcYD[i] - mcYC[i] * unYD[i + 1];
        unZD[i] = mcZD[i] - mcZC[i] * unZD[i + 1];
    }

    for(int i = 0; i < size - 1; i++)
    {
        coeXA[i] = (2 * ( gl_in[i].gl_Position.x - gl_in[i + 1].gl_Position.x ) + unXD[i] + unXD[i + 1]);
        coeYA[i] = (2 * ( gl_in[i].gl_Position.y - gl_in[i + 1].gl_Position.y ) + unYD[i] + unYD[i + 1]);
        coeZA[i] = (2 * ( gl_in[i].gl_Position.z - gl_in[i + 1].gl_Position.z ) + unZD[i] + unZD[i + 1]);

        coeXB[i] = (3 * ( gl_in[i + 1].gl_Position.x - gl_in[i].gl_Position.x ) - 2 * unXD[i] - unXD[i + 1]);
        coeYB[i] = (3 * ( gl_in[i + 1].gl_Position.y - gl_in[i].gl_Position.y ) - 2 * unYD[i] - unYD[i + 1]);
        coeZB[i] = (3 * ( gl_in[i + 1].gl_Position.z - gl_in[i].gl_Position.z ) - 2 * unZD[i] - unZD[i + 1]);

        coeXC[i] = unXD[i];
        coeYC[i] = unYD[i];
        coeZC[i] = unZD[i];

        coeXD[i] = gl_in[i].gl_Position.x;
        coeYD[i] = gl_in[i].gl_Position.y;
        coeZD[i] = gl_in[i].gl_Position.z;
    }

    coeXA[size - 1] = 0;
    coeYA[size - 1] = 0;
    coeZA[size - 1] = 0;

    coeXB[size - 1] = 0;
    coeYB[size - 1] = 0;
    coeZB[size - 1] = 0;

    coeXC[size - 1] = unXD[size - 1];
    coeYC[size - 1] = unYD[size - 1];
    coeZC[size - 1] = unZD[size - 1];

    coeXD[size - 1] = gl_in[size - 1].gl_Position.x;
    coeYD[size - 1] = gl_in[size - 1].gl_Position.y;
    coeZD[size - 1] = gl_in[size - 1].gl_Position.z;

    int count = 50;
    float fcount = count;

    for(int i = 0; i <= count; i++)
    {
        float fi = i;
        float fT = fi / count;
        fT = fT * (size - 1);
        highp int index = int(fT);
        fT = fT - index;

        float fPointX = (( coeXA[index] * fT + coeXB[index]) * fT + coeXC[index]) * fT + coeXD[index];
        float fPointY = (( coeYA[index] * fT + coeYB[index]) * fT + coeYC[index]) * fT + coeYD[index];
        float fPointZ = (( coeZA[index] * fT + coeZB[index]) * fT + coeZC[index]) * fT + coeZD[index];

        gl_Position = clip(vec4(fPointX, fPointY, fPointZ, 1.0));
        EmitVertex();
    }

    EndPrimitive();
}
