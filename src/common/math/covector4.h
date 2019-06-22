#ifndef COVECTOR4_H
#define COVECTOR4_H

#include "dedatatype.h"

class CoVec4
{
public:
    CoVec4() : x(0.f), y(0.f), z(0.f), w(0.f) {};
    CoVec4(Gfloat x, Gfloat y, Gfloat z, Gfloat w) : x(x), y(y), z(z), w(w) {};

    void set(Gfloat x, Gfloat y, Gfloat z, Gfloat w);
    void set(const CoVec4& vec);
    Gfloat dot(const CoVec4& vec);
    Gfloat length();
    Gfloat distance(const CoVec4& vec);

    CoVec4 operator-();
    CoVec4 operator+();

    CoVec4 operator-(const CoVec4& vec);
    CoVec4 operator+(const CoVec4& vec);
    CoVec4 operator*(const CoVec4& vec);
    CoVec4 operator/(const CoVec4& vec);

    CoVec4& operator-=(const CoVec4& vec);
    CoVec4& operator+=(const CoVec4& vec);

    CoVec4& operator*=(const Gfloat& value);
    CoVec4& operator/=(const Gfloat& value);

    Gbool operator==(const CoVec4& vec);

private:
    Gfloat x;
    Gfloat y;
    Gfloat z;
    Gfloat w;
};

inline void CoVec4::set(Gfloat x, Gfloat y, Gfloat z, Gfloat w)
{
    x = x;
    y = y;
    z = z;
}

inline void CoVec4::set(const CoVec4& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

inline Gfloat CoVec4::dot(const CoVec4& vec)
{
    return x * vec.x + y * vec.y + z * vec.z;
}

inline Gfloat CoVec4::length()
{
    return sqrtf(x * x + y * y + z * z);
}

inline Gfloat CoVec4::distance(const CoVec4& vec)
{
    return sqrtf((x - vec.x) * (x - vec.x)
                 + (y - vec.y) * (y - vec.y)
                 + (z - vec.z) * (z - vec.z)
                 + (w - vec.w) * (w - vec.w));
}

inline CoVec4 CoVec4::operator-()
{
    return CoVec4(-x, -y, -z, -w);
}

inline CoVec4 CoVec4::operator+()
{
    return CoVec4(+x, +y, +z, +w);
}

inline CoVec4 CoVec4::operator-(const CoVec4& vec)
{
    return CoVec4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
}

inline CoVec4 CoVec4::operator+(const CoVec4& vec)
{
    return CoVec4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}

inline CoVec4 CoVec4::operator*(const CoVec4& vec)
{
    return CoVec4(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
}

inline CoVec4 CoVec4::operator/(const CoVec4& vec)
{
    return CoVec4(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
}

inline CoVec4& CoVec4::operator-=(const CoVec4& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    w -= vec.w;

    return *this;
}

inline CoVec4& CoVec4::operator+=(const CoVec4& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    w += vec.w;

    return *this;
}

inline CoVec4& CoVec4::operator*=(const Gfloat& value)
{
    x *= value;
    y *= value;
    z *= value;
    w *= value;

    return *this;
}

inline CoVec4& CoVec4::operator/=(const Gfloat& value)
{
    x /= value;
    y /= value;
    z /= value;
    w /= value;

    return *this;
}

inline Gbool CoVec4::operator==(const CoVec4& vec)
{
    return (x == vec.x) &&
           (y == vec.y) &&
           (z == vec.z) &&
           (w == vec.w);
}

#endif // COVECTOR4_H
