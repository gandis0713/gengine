#ifndef COVECTOR2_H
#define COVECTOR2_H

#include "dedatatype.h"

class CoVec2
{
public:
    CoVec2() : x(0.f), y(0.f) {};
    CoVec2(Gfloat x, Gfloat y) : x(x), y(y) {};

    void set(Gfloat x, Gfloat y);
    void set(const CoVec2& vec);
    Gfloat dot(const CoVec2& vec);
    Gfloat length();
    Gfloat distance(const CoVec2& vec);

    CoVec2 operator-();
    CoVec2 operator+();

    CoVec2 operator-(const CoVec2& vec);
    CoVec2 operator+(const CoVec2& vec);
    CoVec2 operator*(const CoVec2& vec);
    CoVec2 operator/(const CoVec2& vec);

    CoVec2& operator-=(const CoVec2& vec);
    CoVec2& operator+=(const CoVec2& vec);

    CoVec2& operator*=(const Gfloat& value);
    CoVec2& operator/=(const Gfloat& value);

    Gbool operator==(const CoVec2& vec);

private:
    Gfloat x;
    Gfloat y;
};

inline void CoVec2::set(Gfloat x, Gfloat y)
{
    x = x;
    y = y;
}

inline void CoVec2::set(const CoVec2& vec)
{
    x = vec.x;
    y = vec.y;
}

inline Gfloat CoVec2::dot(const CoVec2& vec)
{
    return x * vec.x + y * vec.y;
}

inline Gfloat CoVec2::length()
{
    return sqrtf(x * x + y * y);
}

inline Gfloat CoVec2::distance(const CoVec2& vec)
{
    return sqrtf((x - vec.x) * (x - vec.x) + (y - vec.y) * (y - vec.y));
}

inline CoVec2 CoVec2::operator-()
{
    return CoVec2(-x, -y);
}

inline CoVec2 CoVec2::operator+()
{
    return CoVec2(+x, +y);
}

inline CoVec2 CoVec2::operator-(const CoVec2& vec)
{
    return CoVec2(x - vec.x, y - vec.y);
}

inline CoVec2 CoVec2::operator+(const CoVec2& vec)
{
    return CoVec2(x + vec.x, y + vec.y);
}

inline CoVec2 CoVec2::operator*(const CoVec2& vec)
{
    return CoVec2(x * vec.x, y * vec.y);
}

inline CoVec2 CoVec2::operator/(const CoVec2& vec)
{
    return CoVec2(x / vec.x, y / vec.y);
}

inline CoVec2& CoVec2::operator-=(const CoVec2& vec)
{
    x -= vec.x;
    y -= vec.y;

    return *this;
}

inline CoVec2& CoVec2::operator+=(const CoVec2& vec)
{
    x += vec.x;
    y += vec.y;

    return *this;
}

inline CoVec2& CoVec2::operator*=(const Gfloat& value)
{
    x *= value;
    y *= value;

    return *this;
}

inline CoVec2& CoVec2::operator/=(const Gfloat& value)
{
    x /= value;
    y /= value;

    return *this;
}

inline Gbool CoVec2::operator==(const CoVec2& vec)
{
    return (x == vec.x) &&
           (y == vec.y);
}
#endif // COVECTOR2_H
