#version 430

layout (lines_adjacency) in;
layout (triangle_strip, max_vertices = 42) out;

in vec3 vertColor[];
out vec3 fragColor;

uniform mat4 mvp;
uniform float width;
uniform float alpha;

float t0;
float t1;
float t2;
float t3;

vec3 p0;
vec3 p1;
vec3 p2;
vec3 p3;

vec4 clip(vec3 position)
{
    return mvp * vec4(position, 1.0);
}

vec3 interpolate(float t)
{
    t = mix(t1, t2, t);

    vec3 a1 = ((t1-t)*p0 + (t-t0)*p1)/(t1-t0);
    vec3 a2 = ((t2-t)*p1 + (t-t1)*p2)/(t2-t1);
    vec3 a3 = ((t3-t)*p2 + (t-t2)*p3)/(t3-t2);

    vec3 b1 = ((t2-t)*a1 + (t-t0)*a2)/(t2-t0);
    vec3 b2 = ((t3-t)*a2 + (t-t1)*a3)/(t3-t1);

    return ((t2-t)*b1 + (t-t1)*b2)/(t2-t1);
}

float tnote(vec3 start, vec3 end, float t)
{
    float x = end.x - start.x;
    float y = end.y - start.y;
    float z = end.z - start.z;

    float x2 = pow(x, 2);
    float y2 = pow(y, 2);
    float z2 = pow(z, 2);

    return pow(sqrt(x2 + y2 + z2), alpha) + t;
}

void draw(vec3 pos1, vec3 pos2)
{    
    vec4 p1 = clip(pos1);
    vec4 p2 = clip(pos2);

    vec3 v1 = p1.xyz / (p1.w);
    vec3 v2 = p2.xyz / (p2.w);

    vec3 dir = cross(vec3(0, 0, 1), normalize(v2-v1));

    gl_Position = vec4(v1 - dir * width, 1.0);
    EmitVertex();
    gl_Position = vec4(v1 + dir * width, 1.0);
    EmitVertex();
}

void main()
{
    fragColor = vertColor[0];

    p0 = gl_in[0].gl_Position.xyz;
    p1 = gl_in[1].gl_Position.xyz;
    p2 = gl_in[2].gl_Position.xyz;
    p3 = gl_in[3].gl_Position.xyz;

    t0 = 0.0;
    t1 = tnote(p0, p1, t0);
    t2 = tnote(p1, p2, t1);
    t3 = tnote(p2, p3, t2);

    int count = 20;

    for(int i = 0; i <= count; i++)
    {
        float tV1 = float(i) / float(count);
        float tV2 = float(i + 1) / float(count);
        vec3 pD1 = interpolate(tV1);
        vec3 pD2 = interpolate(tV2);

        draw(pD1, pD2);
    }

}
