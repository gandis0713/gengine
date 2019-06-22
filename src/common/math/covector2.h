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
    CoVec2& normalize();

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

#endif // COVECTOR2_H
