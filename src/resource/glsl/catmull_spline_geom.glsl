#version 430

layout (lines_adjacency) in;
layout (triangle_strip, max_vertices = 120) out;

in vec3 vertColor[];
out vec3 fragColor;

uniform mat4 mvp;
//uniform float width;
//uniform float alpha;

float t0;
float t1;
float t2;
float t3;

vec3 p0;
vec3 p1;
vec3 p2;
vec3 p3;

float width;
float alpha;

vec4 clip(vec3 position)
{
    return mvp * vec4(position, 1.0);
}

float interpolate(float t)
{
    t = mix(t1, t2, t);

    vec3 a1 = (t1-t)/(t1-t0)*p0 + (t-t0)/(t1-t0)*p1;
    vec3 a2 = (t2-t)/(t2-t1)*p1 + (t-t1)/(t2-t1)*p2;
    vec3 a3 = (t3-t)/(t3-t2)*p2 + (t-t2)/(t3-t2)*p3;

    vec3 b1 = (t2-t)/(t2-t0)*a1 + (t-t0)/(t2-t0)*a2;
    vec3 b2 = (t3-t)/(t3-t1)*a2 + (t-t1)/(t3-t1)*a3;

    return (t2-t)/(t2-t1)*b1 + (t-t1)/(t2-t1)*b2;
}

float tnote(vec3 start, vec3 end, float t)
{
    return pow(sqrt(pow(start.x - end.x, 2),
                    pow(start.y - end.z, 2),
                    pow(start.z - end.z, 2)),
               alpha)
            + t;
}

void draw(vec3 pos1, vec3 pos2)
{    
    vec4 p1 = clip(pos1);
    vec4 p2 = clip(pos2);

    vec3 v1 = p1.xyz / (p1.w);
    vec3 v2 = p2.xyz / (p2.w);

    vec3 dir = cross(vec3(0, 0, 1), normalize(v2-v1));
    
//    fragColor = vertColor[0];
//    gl_Position = vec4(v1 - dir * width, 1.0);
//    EmitVertex();
//    gl_Position = vec4(v1 + dir * width, 1.0);
//    EmitVertex();
//    gl_Position = vec4(v2 - dir * width, 1.0);
//    EmitVertex();
//    gl_Position = vec4(v2 + dir * width, 1.0);
//    EmitVertex();
}

void main()
{
//    fragColor = vertColor[0];

//    width = 0.0005;
//    alpha = 0.5;

//    p0 = gl_in[0].gl_Position.xyz;
//    p1 = gl_in[1].gl_Position.xyz;
//    p2 = gl_in[2].gl_Position.xyz;
//    p3 = gl_in[3].gl_Position.xyz;

//    t0 = 0;
//    t1 = (p0, p1, t0);
//    t2 = (p1, p2, t1);
//    t3 = (p2, p3, t2);

//    int count = 20;

//    for(int i = 1; i < count - 1; i++)
//    {
//        float tV1 = float(i) / float(count);
//        float tV2 = float(i + 1) / float(count);
//        float pD1 = interpolate(tV1);
//        float pD2 = interpolate(tV2);

//        draw(pD1, pD2);
//    }
}
