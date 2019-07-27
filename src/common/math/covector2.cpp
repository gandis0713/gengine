#include "covector2.h"

#include <qmath.h>

void CoVec2::set(Gfloat x, Gfloat y)
{
    x = x;
    y = y;
}

void CoVec2::set(const CoVec2& vec)
{
    x = vec.x;
    y = vec.y;
}

Gfloat CoVec2::dot(const CoVec2& vec)
{
    return x * vec.x + y * vec.y;
}

Gfloat CoVec2::length()
{
    return qSqrt(x * x + y * y);
}

Gfloat CoVec2::distance(const CoVec2& vec)
{
    return qSqrt((x - vec.x) * (x - vec.x) + (y - vec.y) * (y - vec.y));
}

CoVec2& CoVec2::normalize()
{
    Gfloat normalizeFactor = 1.0f / qSqrt(x * x + y * y);

    x *= normalizeFactor;
    y *= normalizeFactor;

    return *this;
}

CoVec2 CoVec2::operator-() const
{
    return CoVec2(-x, -y);
}

CoVec2 CoVec2::operator+() const
{
    return CoVec2(+x, +y);
}

CoVec2 CoVec2::operator-(const CoVec2& vec) const
{
    return CoVec2(x - vec.x, y - vec.y);
}

CoVec2 CoVec2::operator+(const CoVec2& vec) const
{
    return CoVec2(x + vec.x, y + vec.y);
}

CoVec2 CoVec2::operator*(const CoVec2& vec) const
{
    return CoVec2(x * vec.x, y * vec.y);
}

CoVec2 CoVec2::operator/(const CoVec2& vec) const
{
    return CoVec2(x / vec.x, y / vec.y);
}

CoVec2& CoVec2::operator-=(const CoVec2& vec)
{
    x -= vec.x;
    y -= vec.y;

    return *this;
}

CoVec2& CoVec2::operator+=(const CoVec2& vec)
{
    x += vec.x;
    y += vec.y;

    return *this;
}

CoVec2& CoVec2::operator*=(const Gfloat& value)
{
    x *= value;
    y *= value;

    return *this;
}

CoVec2& CoVec2::operator/=(const Gfloat& value)
{
    x /= value;
    y /= value;

    return *this;
}

Gbool CoVec2::operator==(const CoVec2& vec)
{
    return (x == vec.x) &&
           (y == vec.y);
}


Gfloat CoVec2::operator[](Gint index) const
{
    return (&x)[index];
}

Gfloat& CoVec2::operator[](Gint index)
{
    return (&x)[index];
}
