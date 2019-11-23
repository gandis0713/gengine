#version 120

in vec3 vertex_w;
in vec3 vertexNormal_c;
in vec3 eyeDir_c;
in vec3 lightDir_c;

out vec3 color;

uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform float lightPower;

uniform vec3 diffuseColor;
uniform vec3 ambientColor;
uniform vec3 specularColor;

void main()
{
    // Material properties
    vec3 ambient_diffuse_Color = ambientColor * diffuseColor;

    // Distance to the light
    float distance = length( lightPosition - vertex_w );

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
            ambient_diffuse_Color +
            // Diffuse : "color" of the object
            diffuseColor * lightColor * lightPower * cosTheta / (distance*distance) +
            // Specular : reflective highlight, like a mirror
            specularColor * lightColor * lightPower * pow(cosAlpha,5) / (distance*distance);
}
