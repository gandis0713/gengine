#ifndef COVECTOR3_H
#define COVECTOR3_H

#include "dedatatype.h"
#include <cmath>


class CoVec3
{
public:
    CoVec3() : x(0.f), y(0.f), z(0.f) {};
    CoVec3(Gfloat x, Gfloat y, Gfloat z) : x(x), y(y), z(z) {};

    void set(Gfloat x, Gfloat y, Gfloat z);
    void set(const CoVec3& vec);
    Gfloat dot(const CoVec3& vec);
    CoVec3 cross(const CoVec3& vec);
    Gfloat length();
    Gfloat distance(const CoVec3& vec);

    CoVec3 operator-();
    CoVec3 operator+();

    CoVec3 operator-(const CoVec3& vec);
    CoVec3 operator+(const CoVec3& vec);
    CoVec3 operator*(const CoVec3& vec);
    CoVec3 operator/(const CoVec3& vec);

    CoVec3& operator-=(const CoVec3& vec);
    CoVec3& operator+=(const CoVec3& vec);

    CoVec3& operator*=(const Gfloat& value);
    CoVec3& operator/=(const Gfloat& value);

    Gbool operator==(const CoVec3& vec);

private:
    Gfloat x;
    Gfloat y;
    Gfloat z;
};

inline void CoVec3::set(Gfloat x, Gfloat y, Gfloat z)
{
    x = x;
    y = y;
    z = z;
}

inline void CoVec3::set(const CoVec3& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

inline Gfloat CoVec3::dot(const CoVec3& vec)
{
    return x * vec.x + y * vec.y + z * vec.z;
}

inline CoVec3 CoVec3::cross(const CoVec3& vec)
{
    return CoVec3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
}

inline Gfloat CoVec3::length()
{
    return sqrtf(x * x + y * y + z * z);
}

inline Gfloat CoVec3::distance(const CoVec3& vec)
{
    return sqrtf((x - vec.x) * (x - vec.x) + (y - vec.y) * (y - vec.y) + (z - vec.z) * (z - vec.z));
}

inline CoVec3 CoVec3::operator-()
{
    return CoVec3(-x, -y, -z);
}

inline CoVec3 CoVec3::operator+()
{
    return CoVec3(+x, +y, +z);
}

inline CoVec3 CoVec3::operator-(const CoVec3& vec)
{
    return CoVec3(x - vec.x, y - vec.y, z - vec.z);
}

inline CoVec3 CoVec3::operator+(const CoVec3& vec)
{
    return CoVec3(x + vec.x, y + vec.y, z + vec.z);
}

inline CoVec3 CoVec3::operator*(const CoVec3& vec)
{
    return CoVec3(x * vec.x, y * vec.y, z * vec.z);
}

inline CoVec3 CoVec3::operator/(const CoVec3& vec)
{
    return CoVec3(x / vec.x, y / vec.y, z / vec.z);
}

inline CoVec3& CoVec3::operator-=(const CoVec3& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;

    return *this;
}

inline CoVec3& CoVec3::operator+=(const CoVec3& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;

    return *this;
}

inline CoVec3& CoVec3::operator*=(const Gfloat& value)
{
    x *= value;
    y *= value;
    z *= value;

    return *this;
}

inline CoVec3& CoVec3::operator/=(const Gfloat& value)
{
    x /= value;
    y /= value;
    z /= value;

    return *this;
}
inline Gbool CoVec3::operator==(const CoVec3& vec)
{
    return x == vec.x &&
            y == vec.y &&
            z == vec.z;
}

#endif // COVECTOR3_H
