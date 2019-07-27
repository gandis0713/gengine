#include "covector3.h"
#include "demath.h"

void CoVec3::set(Gfloat x, Gfloat y, Gfloat z)
{
    x = x;
    y = y;
    z = z;
}

void CoVec3::set(const CoVec3& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

Gfloat CoVec3::dot(const CoVec3& vec)
{
    return x * vec.x + y * vec.y + z * vec.z;
}

CoVec3 CoVec3::cross(const CoVec3& vec)
{
    return CoVec3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
}

Gfloat CoVec3::length()
{
    return sqrtf(x * x + y * y + z * z);
}

Gfloat CoVec3::distance(const CoVec3& vec)
{
    return sqrtf((x - vec.x) * (x - vec.x) + (y - vec.y) * (y - vec.y) + (z - vec.z) * (z - vec.z));
}

CoVec3& CoVec3::normalize()
{
    Gfloat normalizeFactor = 1.0f / qSqrt(x * x + y * y + z * z);

    x *= normalizeFactor;
    y *= normalizeFactor;
    z *= normalizeFactor;

    return *this;
}

CoVec3 CoVec3::operator-() const
{
    return CoVec3(-x, -y, -z);
}

CoVec3 CoVec3::operator+() const
{
    return CoVec3(+x, +y, +z);
}

CoVec3 CoVec3::operator-(const CoVec3& vec) const
{
    return CoVec3(x - vec.x, y - vec.y, z - vec.z);
}

CoVec3 CoVec3::operator+(const CoVec3& vec) const
{
    return CoVec3(x + vec.x, y + vec.y, z + vec.z);
}

CoVec3 CoVec3::operator*(const CoVec3& vec) const
{
    return CoVec3(x * vec.x, y * vec.y, z * vec.z);
}

CoVec3 CoVec3::operator/(const CoVec3& vec) const
{
    return CoVec3(x / vec.x, y / vec.y, z / vec.z);
}

CoVec3& CoVec3::operator-=(const CoVec3& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;

    return *this;
}

CoVec3& CoVec3::operator+=(const CoVec3& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;

    return *this;
}

CoVec3& CoVec3::operator*=(const Gfloat& value)
{
    x *= value;
    y *= value;
    z *= value;

    return *this;
}

CoVec3& CoVec3::operator/=(const Gfloat& value)
{
    x /= value;
    y /= value;
    z /= value;

    return *this;
}
Gbool CoVec3::operator==(const CoVec3& vec)
{
    return x == vec.x &&
            y == vec.y &&
            z == vec.z;
}

Gfloat CoVec3::operator[](Gint index) const
{
    return (&x)[index];
}

Gfloat& CoVec3::operator[](Gint index)
{
    return (&x)[index];
}

