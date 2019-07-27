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


//void main()
//{
//    fragColor = vertColor[0];

//    int size = gl_in.length();

//    float mcXC[4];
//    float mcYC[4];
//    float mcZC[4];

//    float mcXD[4];
//    float mcYD[4];
//    float mcZD[4];

//    float unXD[4];
//    float unYD[4];
//    float unZD[4];

//    float coeXA[4];
//    float coeXB[4];
//    float coeXC[4];
//    float coeXD[4];

//    float coeYA[4];
//    float coeYB[4];
//    float coeYC[4];
//    float coeYD[4];

//    float coeZA[4];
//    float coeZB[4];
//    float coeZC[4];
//    float coeZD[4];

//    // step 1
//    if(vertIndex == 0)
//    {
//        mcXC[0] = 1.f / 2.f;
//        mcYC[0] = 1.f / 2.f;
//        mcZC[0] = 1.f / 2.f;

//        for(int i = 1; i < size; i++)
//        {
//            mcXC[i] = 1.f / ( 4.f - mcXC[ i - 1 ] );
//            mcYC[i] = 1.f / ( 4.f - mcYC[ i - 1 ] );
//            mcZC[i] = 1.f / ( 4.f - mcZC[ i - 1 ] );
//        }
//    }

//    for(int i = 0; i < size; i++)
//    {
//        mcXC[i] = 1.f / ( 4.f - mcXC[ i - 1 ] );
//        mcYC[i] = 1.f / ( 4.f - mcYC[ i - 1 ] );
//        mcZC[i] = 1.f / ( 4.f - mcZC[ i - 1 ] );
//    }

//    if(vertIndex == -1)
//    {
//        for(int i = 0; i < size - 1; i++)
//        {
//            mcXC[i] = 1.f / ( 4.f - mcXC[ i - 1 ] );
//            mcYC[i] = 1.f / ( 4.f - mcYC[ i - 1 ] );
//            mcZC[i] = 1.f / ( 4.f - mcZC[ i - 1 ] );
//        }

//        mcXC[size - 1] = 1.f / ( 2.f - mcXC[size - 2] );
//        mcYC[size - 1] = 1.f / ( 2.f - mcYC[size - 2] );
//        mcZC[size - 1] = 1.f / ( 2.f - mcZC[size - 2] );
//    }


//    // step 2
//    if(vertIndex == 0)
//    {
//        mcXD[0] = 3.f * ( gl_in[1].gl_Position.x - gl_in[0].gl_Position.x ) * mcXC[0];
//        mcYD[0] = 3.f * ( gl_in[1].gl_Position.y - gl_in[0].gl_Position.y ) * mcYC[0];
//        mcZD[0] = 3.f * ( gl_in[1].gl_Position.z - gl_in[0].gl_Position.z ) * mcZC[0];

//        for(int i = 1; i < size - 2; i++)
//        {
//            mcXD[i] = ( 3.f * ( gl_in[i + 1].gl_Position.x - gl_in[i - 1].gl_Position.x ) - mcXD[i - 1]) * mcXC[i];
//            mcYD[i] = ( 3.f * ( gl_in[i + 1].gl_Position.y - gl_in[i - 1].gl_Position.y ) - mcYD[i - 1]) * mcYC[i];
//            mcZD[i] = ( 3.f * ( gl_in[i + 1].gl_Position.z - gl_in[i - 1].gl_Position.z ) - mcZD[i - 1]) * mcZC[i];
//        }
//    }

//    for(int i = 1; i < size - 2; i++)
//    {
//        mcXD[i] = ( 3.f * ( gl_in[i + 1].gl_Position.x - gl_in[i - 1].gl_Position.x ) - mcXD[i - 1]) * mcXC[i];
//        mcYD[i] = ( 3.f * ( gl_in[i + 1].gl_Position.y - gl_in[i - 1].gl_Position.y ) - mcYD[i - 1]) * mcYC[i];
//        mcZD[i] = ( 3.f * ( gl_in[i + 1].gl_Position.z - gl_in[i - 1].gl_Position.z ) - mcZD[i - 1]) * mcZC[i];
//    }

//    if(vertIndex == -1)
//    {
//        for(int i = 1; i < size - 1; i++)
//        {
//            mcXD[i] = ( 3.f * ( gl_in[i + 1].gl_Position.x - gl_in[i - 1].gl_Position.x ) - mcXD[i - 1]) * mcXC[i];
//            mcYD[i] = ( 3.f * ( gl_in[i + 1].gl_Position.y - gl_in[i - 1].gl_Position.y ) - mcYD[i - 1]) * mcYC[i];
//            mcZD[i] = ( 3.f * ( gl_in[i + 1].gl_Position.z - gl_in[i - 1].gl_Position.z ) - mcZD[i - 1]) * mcZC[i];
//        }

//        mcXD[size - 1] = ( 3.f * ( gl_in[size - 1].gl_Position.x - gl_in[size - 2].gl_Position.x ) - mcXD[size - 2] ) * mcXC[size - 1];
//        mcYD[size - 1] = ( 3.f * ( gl_in[size - 1].gl_Position.y - gl_in[size - 2].gl_Position.y ) - mcYD[size - 2] ) * mcYC[size - 1];
//        mcZD[size - 1] = ( 3.f * ( gl_in[size - 1].gl_Position.z - gl_in[size - 2].gl_Position.z ) - mcZD[size - 2] ) * mcZC[size - 1];
//    }

//    // step 3

//    if(vertIndex == 0)
//    {
//        unXD[size - 2] = mcXD[size - 2]; // check
//        unYD[size - 2] = mcYD[size - 2]; // check
//        unZD[size - 2] = mcZD[size - 2]; // check

//        for(int i = size - 3; i >= 0; i--)
//        {
//            unXD[i] = mcXD[i] - mcXC[i] * unXD[i + 1];
//            unYD[i] = mcYD[i] - mcYC[i] * unYD[i + 1];
//            unZD[i] = mcZD[i] - mcZC[i] * unZD[i + 1];
//        }
//    }

//    unXD[size - 1] = mcXD[size - 1]; // check
//    unYD[size - 1] = mcYD[size - 1]; // check
//    unZD[size - 1] = mcZD[size - 1]; // check

//    for(int i = size - 2; i >= 1; i--)
//    {
//        unXD[i] = mcXD[i] - mcXC[i] * unXD[i + 1];
//        unYD[i] = mcYD[i] - mcYC[i] * unYD[i + 1];
//        unZD[i] = mcZD[i] - mcZC[i] * unZD[i + 1];
//    }

//    if(vertIndex == -1)
//    {
//        unXD[size - 1] = mcXD[size - 1]; // check
//        unYD[size - 1] = mcYD[size - 1]; // check
//        unZD[size - 1] = mcZD[size - 1]; // check

//        for(int i = size - 2; i >= 2; i--)
//        {
//            unXD[i] = mcXD[i] - mcXC[i] * unXD[i + 1];
//            unYD[i] = mcYD[i] - mcYC[i] * unYD[i + 1];
//            unZD[i] = mcZD[i] - mcZC[i] * unZD[i + 1];
//        }
//    }

//    // step 4

//    if(vertIndex == 0)
//    {
//        for(int i = 0; i < size - 2; i++)
//        {
//            coeXA[i] = (2 * ( gl_in[i].gl_Position.x - gl_in[i + 1].gl_Position.x ) + unXD[i] + unXD[i + 1]);
//            coeYA[i] = (2 * ( gl_in[i].gl_Position.y - gl_in[i + 1].gl_Position.y ) + unYD[i] + unYD[i + 1]);
//            coeZA[i] = (2 * ( gl_in[i].gl_Position.z - gl_in[i + 1].gl_Position.z ) + unZD[i] + unZD[i + 1]);

//            coeXB[i] = (3 * ( gl_in[i + 1].gl_Position.x - gl_in[i].gl_Position.x ) - 2 * unXD[i] - unXD[i + 1]);
//            coeYB[i] = (3 * ( gl_in[i + 1].gl_Position.y - gl_in[i].gl_Position.y ) - 2 * unYD[i] - unYD[i + 1]);
//            coeZB[i] = (3 * ( gl_in[i + 1].gl_Position.z - gl_in[i].gl_Position.z ) - 2 * unZD[i] - unZD[i + 1]);

//            coeXC[i] = unXD[i];
//            coeYC[i] = unYD[i];
//            coeZC[i] = unZD[i];

//            coeXD[i] = gl_in[i].gl_Position.x;
//            coeYD[i] = gl_in[i].gl_Position.y;
//            coeZD[i] = gl_in[i].gl_Position.z;
//        }
//    }

//    for(int i = 1; i < size - 1; i++)
//    {
//        coeXA[i] = (2 * ( gl_in[i].gl_Position.x - gl_in[i + 1].gl_Position.x ) + unXD[i] + unXD[i + 1]);
//        coeYA[i] = (2 * ( gl_in[i].gl_Position.y - gl_in[i + 1].gl_Position.y ) + unYD[i] + unYD[i + 1]);
//        coeZA[i] = (2 * ( gl_in[i].gl_Position.z - gl_in[i + 1].gl_Position.z ) + unZD[i] + unZD[i + 1]);

//        coeXB[i] = (3 * ( gl_in[i + 1].gl_Position.x - gl_in[i].gl_Position.x ) - 2 * unXD[i] - unXD[i + 1]);
//        coeYB[i] = (3 * ( gl_in[i + 1].gl_Position.y - gl_in[i].gl_Position.y ) - 2 * unYD[i] - unYD[i + 1]);
//        coeZB[i] = (3 * ( gl_in[i + 1].gl_Position.z - gl_in[i].gl_Position.z ) - 2 * unZD[i] - unZD[i + 1]);

//        coeXC[i] = unXD[i];
//        coeYC[i] = unYD[i];
//        coeZC[i] = unZD[i];

//        coeXD[i] = gl_in[i].gl_Position.x;
//        coeYD[i] = gl_in[i].gl_Position.y;
//        coeZD[i] = gl_in[i].gl_Position.z;
//    }


//    if(vertIndex == -1)
//    {
//        for(int i = 2; i < size - 1; i++)
//        {
//            coeXA[i] = (2 * ( gl_in[i].gl_Position.x - gl_in[i + 1].gl_Position.x ) + unXD[i] + unXD[i + 1]);
//            coeYA[i] = (2 * ( gl_in[i].gl_Position.y - gl_in[i + 1].gl_Position.y ) + unYD[i] + unYD[i + 1]);
//            coeZA[i] = (2 * ( gl_in[i].gl_Position.z - gl_in[i + 1].gl_Position.z ) + unZD[i] + unZD[i + 1]);

//            coeXB[i] = (3 * ( gl_in[i + 1].gl_Position.x - gl_in[i].gl_Position.x ) - 2 * unXD[i] - unXD[i + 1]);
//            coeYB[i] = (3 * ( gl_in[i + 1].gl_Position.y - gl_in[i].gl_Position.y ) - 2 * unYD[i] - unYD[i + 1]);
//            coeZB[i] = (3 * ( gl_in[i + 1].gl_Position.z - gl_in[i].gl_Position.z ) - 2 * unZD[i] - unZD[i + 1]);

//            coeXC[i] = unXD[i];
//            coeYC[i] = unYD[i];
//            coeZC[i] = unZD[i];

//            coeXD[i] = gl_in[i].gl_Position.x;
//            coeYD[i] = gl_in[i].gl_Position.y;
//            coeZD[i] = gl_in[i].gl_Position.z;
//        }

//        coeXA[size - 1] = 0;
//        coeYA[size - 1] = 0;
//        coeZA[size - 1] = 0;

//        coeXB[size - 1] = 0;
//        coeYB[size - 1] = 0;
//        coeZB[size - 1] = 0;

//        coeXC[size - 1] = unXD[size - 1];
//        coeYC[size - 1] = unYD[size - 1];
//        coeZC[size - 1] = unZD[size - 1];

//        coeXD[size - 1] = gl_in[size - 1].gl_Position.x;
//        coeYD[size - 1] = gl_in[size - 1].gl_Position.y;
//        coeZD[size - 1] = gl_in[size - 1].gl_Position.z;
//    }


//    int count = 50;
//    float fcount = count;

//    for(int i = 0; i <= count; i++)
//    {
//        float fi = i;
//        float fT = fi / count;
//        fT = fT * (size - 1);
//        highp int index = int(fT);
//        fT = fT - index;

//        float fPointX = (( coeXA[index] * fT + coeXB[index]) * fT + coeXC[index]) * fT + coeXD[index];
//        float fPointY = (( coeYA[index] * fT + coeYB[index]) * fT + coeYC[index]) * fT + coeYD[index];
//        float fPointZ = (( coeZA[index] * fT + coeZB[index]) * fT + coeZC[index]) * fT + coeZD[index];

//        gl_Position = clip(vec4(fPointX, fPointY, fPointZ, 1.0));
//        EmitVertex();
//    }

//    EndPrimitive();
//}
