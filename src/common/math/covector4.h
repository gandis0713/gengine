#ifndef COVECTOR4_H
#define COVECTOR4_H

#include "dedatatype.h"
#include "covector3.h"
#include "deengine.h"

class GANDISENGINE CoVec4
{
public:
    CoVec4() : x(0.f), y(0.f), z(0.f), w(0.f) {};
    CoVec4(Gfloat x, Gfloat y, Gfloat z, Gfloat w) : x(x), y(y), z(z), w(w) {};

    void set(Gfloat x, Gfloat y, Gfloat z, Gfloat w);
    void set(const CoVec4& vec);
    Gfloat dot(const CoVec4& vec);
    CoVec3 cross(const CoVec4& vec);

    Gfloat length();
    Gfloat distance(const CoVec4& vec);
    CoVec4& normalize();

    CoVec4 operator-() const;
    CoVec4 operator+() const;

    CoVec4 operator-(const CoVec4& vec) const;
    CoVec4 operator+(const CoVec4& vec) const;
    CoVec4 operator*(const CoVec4& vec) const;
    CoVec4 operator/(const CoVec4& vec) const;

    CoVec4& operator-=(const CoVec4& vec);
    CoVec4& operator+=(const CoVec4& vec);

    CoVec4& operator*=(const Gfloat& value);
    CoVec4& operator/=(const Gfloat& value);

    Gbool operator==(const CoVec4& vec);
    Gfloat operator[](Gint index) const;
    Gfloat& operator[](Gint index);

private:
    Gfloat x;
    Gfloat y;
    Gfloat z;
    Gfloat w;
};

#endif // COVECTOR4_H
