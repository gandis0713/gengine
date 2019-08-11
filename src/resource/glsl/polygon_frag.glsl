#version 430 core

in vec3 vertColor;
in vec3 vertex_w;
in vec3 vertexNormal_c;
in vec3 eyeDir_c;
in vec3 lightDir_c;

out vec3 color;

uniform vec3 lightPos_w;
uniform vec3 lightColor;
uniform float lightPower;
uniform vec3 diffuseColor;
uniform vec3 ambientColor;
uniform vec3 specularColor;

void main(){

    vec3 lightPos_t = vec3(0, 0, 4000);
    // Light emission properties
    // You probably want to put them as uniforms
    vec3 lightColor_t = vec3(1,1,1);
    float lightPower_t = 50000000.0f;

    // Material properties
    vec3 diffuseColor_t = vertColor;
    vec3 ambientColor_t = vec3(0.1,0.1,0.1) * diffuseColor_t;
    vec3 specularColor_t = vec3(0.3,0.3,0.3);

    // Distance to the light
    float distance = length( lightPos_t - vertex_w );

    // Normal of the computed fragment, in camera space
    vec3 n = normalize( vertexNormal_c );
    // Direction of the light (from the fragment to the light)
    vec3 l = normalize( lightDir_c );
    // Cosine of the angle between the normal and the light direction,
    // clamped above 0
    //  - light is at the vertical of the triangle -> 1
    //  - light is perpendicular to the triangle -> 0
    //  - light is behind the triangle -> 0
    float cosTheta = clamp( dot( n,l ), 0,1 );
    //        float cosTheta = dot( n,l );

    // Eye vector (towards the camera)
    vec3 E = normalize(eyeDir_c);
    // Direction in which the triangle reflects the light
    vec3 R = reflect(-l,n);
    // Cosine of the angle between the Eye vector and the Reflect vector,
    // clamped to 0
    //  - Looking into the reflection -> 1
    //  - Looking elsewhere -> < 1
    float cosAlpha = clamp( dot( E,R ), 0,1 );

    color =
            // Ambient : simulates indirect lighting
            ambientColor_t +
            // Diffuse : "color" of the object
            diffuseColor_t * lightColor_t * lightPower_t * cosTheta / (distance*distance) +
            // Specular : reflective highlight, like a mirror
            specularColor_t * lightColor_t * lightPower_t * pow(cosAlpha,5) / (distance*distance);
}
