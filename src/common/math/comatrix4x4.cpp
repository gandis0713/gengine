#include "comatrix4x4.h"
#include "comatrix3x3.h"

#include "demath.h"
#include "nomath.h"

CoMat4x4::CoMat4x4()
{
    identity();
}

CoMat4x4::CoMat4x4(const Gfloat mat[16])
{
    set(mat);
}

CoMat4x4::CoMat4x4(Gfloat mat00, Gfloat mat01, Gfloat mat02, Gfloat mat03,
                   Gfloat mat04, Gfloat mat05, Gfloat mat06, Gfloat mat07,
                   Gfloat mat08, Gfloat mat09, Gfloat mat10, Gfloat mat11,
                   Gfloat mat12, Gfloat mat13, Gfloat mat14, Gfloat mat15)
{
    set(mat00, mat01, mat02, mat03,  mat04, mat05, mat06, mat07,  mat08, mat09, mat10, mat11,  mat12, mat13, mat14, mat15);
}


CoMat4x4& CoMat4x4::identity()
{
    mat[0] = mat[5] = mat[10] = mat[15] = 1.0f;
    mat[1] = mat[2] = mat[3] = mat[4] = mat[6] = mat[7] = mat[8] = mat[9] = mat[11] = mat[12] = mat[13] = mat[14] = 0.0f;

    return *this;
}

void CoMat4x4::set(const Gfloat mat[16])
{
    this->mat[0] = mat[0];  this->mat[1] = mat[1];  this->mat[2] = mat[2];  this->mat[3] = mat[3];
    this->mat[4] = mat[4];  this->mat[5] = mat[5];  this->mat[6] = mat[6];  this->mat[7] = mat[7];
    this->mat[8] = mat[8];  this->mat[9] = mat[9];  this->mat[10]= mat[10]; this->mat[11]= mat[11];
    this->mat[12]= mat[12]; this->mat[13]= mat[13]; this->mat[14]= mat[14]; this->mat[15]= mat[15];
}

inline void CoMat4x4::set(Gfloat m00, Gfloat m01, Gfloat m02, Gfloat m03,
                         Gfloat m04, Gfloat m05, Gfloat m06, Gfloat m07,
                         Gfloat m08, Gfloat m09, Gfloat m10, Gfloat m11,
                         Gfloat m12, Gfloat m13, Gfloat m14, Gfloat m15)
{
    this->mat[0] = m00;  this->mat[1] = m01;  this->mat[2] = m02;  this->mat[3] = m03;
    this->mat[4] = m04;  this->mat[5] = m05;  this->mat[6] = m06;  this->mat[7] = m07;
    this->mat[8] = m08;  this->mat[9] = m09;  this->mat[10]= m10;  this->mat[11]= m11;
    this->mat[12]= m12;  this->mat[13]= m13;  this->mat[14]= m14;  this->mat[15]= m15;
}

CoMat4x4 CoMat4x4::getTranspose()
{
    Gfloat tmat[16];

    tmat[0] = mat[0];    tmat[1] = mat[4];    tmat[2] = mat[8];     tmat[3] = mat[12];
    tmat[4] = mat[1];    tmat[5] = mat[5];    tmat[6] = mat[9];     tmat[7] = mat[13];
    tmat[8] = mat[2];    tmat[9] = mat[6];    tmat[10] = mat[10];   tmat[11] = mat[14];
    tmat[12] = mat[3];   tmat[13] = mat[7];   tmat[14] = mat[11];   tmat[15] = mat[15];

    return tmat;
}

CoMat4x4& CoMat4x4::transpose()
{
    std::swap(mat[1],  mat[4]);
    std::swap(mat[2],  mat[8]);
    std::swap(mat[3],  mat[12]);
    std::swap(mat[6],  mat[9]);
    std::swap(mat[7],  mat[13]);
    std::swap(mat[11], mat[14]);

    return *this;
}

CoMat4x4& CoMat4x4::inverse()
{
    Gfloat tmpMat[16];

    tmpMat[0] = CoMat3x3::determinant(mat[5],mat[6],mat[7], mat[9],mat[10],mat[11], mat[13],mat[14],mat[15]);
    tmpMat[1] = CoMat3x3::determinant(mat[4],mat[6],mat[7], mat[8],mat[10],mat[11], mat[12],mat[14],mat[15]);
    tmpMat[2] = CoMat3x3::determinant(mat[4],mat[5],mat[7], mat[8],mat[9], mat[11], mat[12],mat[13],mat[15]);
    tmpMat[3] = CoMat3x3::determinant(mat[4],mat[5],mat[6], mat[8],mat[9], mat[10], mat[12],mat[13],mat[14]);

    tmpMat[4] = CoMat3x3::determinant(mat[1],mat[2],mat[3], mat[9],mat[10],mat[11], mat[13],mat[14],mat[15]);
    tmpMat[5] = CoMat3x3::determinant(mat[0],mat[2],mat[3], mat[8],mat[10],mat[11], mat[12],mat[14],mat[15]);
    tmpMat[6] = CoMat3x3::determinant(mat[0],mat[1],mat[3], mat[8],mat[9], mat[11], mat[12],mat[13],mat[15]);
    tmpMat[7] = CoMat3x3::determinant(mat[0],mat[1],mat[2], mat[8],mat[9], mat[10], mat[12],mat[13],mat[14]);

    tmpMat[8] = CoMat3x3::determinant(mat[1],mat[2],mat[3], mat[5],mat[6], mat[7],  mat[13],mat[14],mat[15]);
    tmpMat[9] = CoMat3x3::determinant(mat[0],mat[2],mat[3], mat[4],mat[6], mat[7],  mat[12],mat[14],mat[15]);
    tmpMat[10] = CoMat3x3::determinant(mat[0],mat[1],mat[3], mat[4],mat[5], mat[7],  mat[12],mat[13],mat[15]);
    tmpMat[11] = CoMat3x3::determinant(mat[0],mat[1],mat[2], mat[4],mat[5], mat[6],  mat[12],mat[13],mat[14]);

    tmpMat[12] = CoMat3x3::determinant(mat[1],mat[2],mat[3], mat[5],mat[6], mat[7],  mat[9], mat[10],mat[11]);
    tmpMat[13] = CoMat3x3::determinant(mat[0],mat[2],mat[3], mat[4],mat[6], mat[7],  mat[8], mat[10],mat[11]);
    tmpMat[14] = CoMat3x3::determinant(mat[0],mat[1],mat[3], mat[4],mat[5], mat[7],  mat[8], mat[9], mat[11]);
    tmpMat[15] = CoMat3x3::determinant(mat[0],mat[1],mat[2], mat[4],mat[5], mat[6],  mat[8], mat[9], mat[10]);

    Gfloat invertDeterminant = 1.0f / determinant();

    mat[0] =  invertDeterminant * tmpMat[0];
    mat[1] = -invertDeterminant * tmpMat[4];
    mat[2] =  invertDeterminant * tmpMat[8];
    mat[3] = -invertDeterminant * tmpMat[12];

    mat[4] = -invertDeterminant * tmpMat[1];
    mat[5] =  invertDeterminant * tmpMat[5];
    mat[6] = -invertDeterminant * tmpMat[9];
    mat[7] =  invertDeterminant * tmpMat[13];

    mat[8] =  invertDeterminant * tmpMat[2];
    mat[9] = -invertDeterminant * tmpMat[6];
    mat[10]=  invertDeterminant * tmpMat[10];
    mat[11]= -invertDeterminant * tmpMat[14];

    mat[12]= -invertDeterminant * tmpMat[3];
    mat[13]=  invertDeterminant * tmpMat[7];
    mat[14]= -invertDeterminant * tmpMat[11];
    mat[15]=  invertDeterminant * tmpMat[15];

    return *this;
}

Gfloat CoMat4x4::determinant()
{
    return mat[0] * CoMat3x3::determinant(mat[5],mat[6],mat[7], mat[9],mat[10],mat[11], mat[13],mat[14],mat[15]) -
           mat[1] * CoMat3x3::determinant(mat[4],mat[6],mat[7], mat[8],mat[10],mat[11], mat[12],mat[14],mat[15]) +
           mat[2] * CoMat3x3::determinant(mat[4],mat[5],mat[7], mat[8],mat[9], mat[11], mat[12],mat[13],mat[15]) -
           mat[3] * CoMat3x3::determinant(mat[4],mat[5],mat[6], mat[8],mat[9], mat[10], mat[12],mat[13],mat[14]);
}

CoVec3 CoMat4x4::angle()
{
//    Gfloat pitch, yaw, roll;         // 3 angles

//    // find yaw (around y-axis) first
//    // NOTE: asin() returns -90~+90, so correct the angle range -180~+180
//    // using z value of forward vector
//    yaw = RAD2DEG * asinf(m[8]);
//    if(m[10] < 0)
//    {
//        if(yaw >= 0) yaw = 180.0f - yaw;
//        else         yaw =-180.0f - yaw;
//    }

//    // find roll (around z-axis) and pitch (around x-axis)
//    // if forward vector is (1,0,0) or (-1,0,0), then m[0]=m[4]=m[9]=m[10]=0
//    if(m[0] > -EPSILON_F && m[0] < EPSILON_F)
//    {
//        roll  = 0;  //@@ assume roll=0
//        pitch = RAD2DEG * atan2f(m[1], m[5]);
//    }
//    else
//    {
//        roll = RAD2DEG * atan2f(-m[4], m[0]);
//        pitch = RAD2DEG * atan2f(-m[9], m[10]);
//    }

//    return CoVec3(pitch, yaw, roll);
    return CoVec3();
}

CoMat4x4& CoMat4x4::rotate(Gfloat angle, const CoVec3& axis)
{
    return rotate(angle, axis[0], axis[1], axis[2]);
}

CoMat4x4& CoMat4x4::rotate(Gfloat angle, Gfloat x, Gfloat y, Gfloat z)
{
    Gfloat c = cosf(angle * DEG2RAD);    // cosine
    Gfloat s = sinf(angle * DEG2RAD);    // sine
    Gfloat c1 = 1.0f - c;                // 1 - c
    Gfloat m0 = mat[0],  m4 = mat[4],  m8 = mat[8],  m12= mat[12],
           m1 = mat[1],  m5 = mat[5],  m9 = mat[9],  m13= mat[13],
           m2 = mat[2],  m6 = mat[6],  m10= mat[10], m14= mat[14];

    Gfloat r0 = x * x * c1 + c;
    Gfloat r1 = x * y * c1 + z * s;
    Gfloat r2 = x * z * c1 - y * s;
    Gfloat r4 = x * y * c1 - z * s;
    Gfloat r5 = y * y * c1 + c;
    Gfloat r6 = y * z * c1 + x * s;
    Gfloat r8 = x * z * c1 + y * s;
    Gfloat r9 = y * z * c1 - x * s;
    Gfloat r10= z * z * c1 + c;

    mat[0] = r0 * m0 + r4 * m1 + r8 * m2;
    mat[1] = r1 * m0 + r5 * m1 + r9 * m2;
    mat[2] = r2 * m0 + r6 * m1 + r10* m2;
    mat[4] = r0 * m4 + r4 * m5 + r8 * m6;
    mat[5] = r1 * m4 + r5 * m5 + r9 * m6;
    mat[6] = r2 * m4 + r6 * m5 + r10* m6;
    mat[8] = r0 * m8 + r4 * m9 + r8 * m10;
    mat[9] = r1 * m8 + r5 * m9 + r9 * m10;
    mat[10]= r2 * m8 + r6 * m9 + r10* m10;
    mat[12]= r0 * m12+ r4 * m13+ r8 * m14;
    mat[13]= r1 * m12+ r5 * m13+ r9 * m14;
    mat[14]= r2 * m12+ r6 * m13+ r10* m14;

    return *this;
}

CoMat4x4& CoMat4x4::rotateX(Gfloat angle)
{
    Gfloat c = cosf(angle * DEG2RAD);
    Gfloat s = sinf(angle * DEG2RAD);
    Gfloat m1 = mat[1],  m2 = mat[2],
          m5 = mat[5],  m6 = mat[6],
          m9 = mat[9],  m10= mat[10],
          m13= mat[13], m14= mat[14];

    mat[1] = m1 * c + m2 *-s;
    mat[2] = m1 * s + m2 * c;
    mat[5] = m5 * c + m6 *-s;
    mat[6] = m5 * s + m6 * c;
    mat[9] = m9 * c + m10*-s;
    mat[10]= m9 * s + m10* c;
    mat[13]= m13* c + m14*-s;
    mat[14]= m13* s + m14* c;

    return *this;
}

CoMat4x4& CoMat4x4::rotateY(Gfloat angle)
{
    Gfloat c = cosf(angle * DEG2RAD);
    Gfloat s = sinf(angle * DEG2RAD);
    Gfloat m0 = mat[0],  m2 = mat[2],
          m4 = mat[4],  m6 = mat[6],
          m8 = mat[8],  m10= mat[10],
          m12= mat[12], m14= mat[14];

    mat[0] = m0 * c + m2 * s;
    mat[2] = m0 *-s + m2 * c;
    mat[4] = m4 * c + m6 * s;
    mat[6] = m4 *-s + m6 * c;
    mat[8] = m8 * c + m10* s;
    mat[10]= m8 *-s + m10* c;
    mat[12]= m12* c + m14* s;
    mat[14]= m12*-s + m14* c;

    return *this;
}

CoMat4x4& CoMat4x4::rotateZ(Gfloat angle)
{
    Gfloat c = cosf(angle * DEG2RAD);
    Gfloat s = sinf(angle * DEG2RAD);
    Gfloat m0 = mat[0],  m1 = mat[1],
          m4 = mat[4],  m5 = mat[5],
          m8 = mat[8],  m9 = mat[9],
          m12= mat[12], m13= mat[13];

    mat[0] = m0 * c + m1 *-s;
    mat[1] = m0 * s + m1 * c;
    mat[4] = m4 * c + m5 *-s;
    mat[5] = m4 * s + m5 * c;
    mat[8] = m8 * c + m9 *-s;
    mat[9] = m8 * s + m9 * c;
    mat[12]= m12* c + m13*-s;
    mat[13]= m12* s + m13* c;

    return *this;
}

CoMat4x4 CoMat4x4::operator+(const CoMat4x4& mat)
{
    return CoMat4x4(this->mat[0]+mat[0],   this->mat[1]+mat[1],   this->mat[2]+mat[2],   this->mat[3]+mat[3],
                    this->mat[4]+mat[4],   this->mat[5]+mat[5],   this->mat[6]+mat[6],   this->mat[7]+mat[7],
                    this->mat[8]+mat[8],   this->mat[9]+mat[9],   this->mat[10]+mat[10], this->mat[11]+mat[11],
                    this->mat[12]+mat[12], this->mat[13]+mat[13], this->mat[14]+mat[14], this->mat[15]+mat[15]);
}


CoVec3 CoMat4x4::operator*(const CoVec3& vec) const
{
    return CoVec3(mat[0]*vec[0] + mat[4]*vec[1] + mat[8]*vec[2] + mat[12],
                   mat[1]*vec[0] + mat[5]*vec[1] + mat[9]*vec[2] + mat[13],
                   mat[2]*vec[0] + mat[6]*vec[1] + mat[10]*vec[2]+ mat[14]);
}

CoMat4x4 CoMat4x4::operator-(const CoMat4x4& mat)
{
    return CoMat4x4(this->mat[0]-mat[0],   this->mat[1]-mat[1],   this->mat[2]-mat[2],   this->mat[3]-mat[3],
                    this->mat[4]-mat[4],   this->mat[5]-mat[5],   this->mat[6]-mat[6],   this->mat[7]-mat[7],
                    this->mat[8]-mat[8],   this->mat[9]-mat[9],   this->mat[10]-mat[10], this->mat[11]-mat[11],
                    this->mat[12]-mat[12], this->mat[13]-mat[13], this->mat[14]-mat[14], this->mat[15]-mat[15]);
}

CoMat4x4& CoMat4x4::operator+=(const CoMat4x4& mat)
{
    this->mat[0] += mat[0];   this->mat[1] += mat[1];   this->mat[2] += mat[2];   this->mat[3] += mat[3];
    this->mat[4] += mat[4];   this->mat[5] += mat[5];   this->mat[6] += mat[6];   this->mat[7] += mat[7];
    this->mat[8] += mat[8];   this->mat[9] += mat[9];   this->mat[10]+= mat[10];  this->mat[11]+= mat[11];
    this->mat[12]+= mat[12];  this->mat[13]+= mat[13];  this->mat[14]+= mat[14];  this->mat[15]+= mat[15];
    return *this;
}



CoMat4x4& CoMat4x4::operator-=(const CoMat4x4& mat)
{
    this->mat[0] -= mat[0];   this->mat[1] -= mat[1];   this->mat[2] -= mat[2];   this->mat[3] -= mat[3];
    this->mat[4] -= mat[4];   this->mat[5] -= mat[5];   this->mat[6] -= mat[6];   this->mat[7] -= mat[7];
    this->mat[8] -= mat[8];   this->mat[9] -= mat[9];   this->mat[10]-= mat[10];  this->mat[11]-= mat[11];
    this->mat[12]-= mat[12];  this->mat[13]-= mat[13];  this->mat[14]-= mat[14];  this->mat[15]-= mat[15];

    return *this;
}

CoMat4x4 CoMat4x4::operator*(const CoMat4x4& mat)
{
    return CoMat4x4(this->mat[0]*mat[0]  + this->mat[4]*mat[1]  + this->mat[8]*mat[2]  + this->mat[12]*mat[3],   this->mat[1]*mat[0]  + this->mat[5]*mat[1]  + this->mat[9]*mat[2]  + this->mat[13]*mat[3],   this->mat[2]*mat[0]  + this->mat[6]*mat[1]  + this->mat[10]*mat[2]  + this->mat[14]*mat[3],   this->mat[3]*mat[0]  + this->mat[7]*mat[1]  + this->mat[11]*mat[2]  + this->mat[15]*mat[3],
                    this->mat[0]*mat[4]  + this->mat[4]*mat[5]  + this->mat[8]*mat[6]  + this->mat[12]*mat[7],   this->mat[1]*mat[4]  + this->mat[5]*mat[5]  + this->mat[9]*mat[6]  + this->mat[13]*mat[7],   this->mat[2]*mat[4]  + this->mat[6]*mat[5]  + this->mat[10]*mat[6]  + this->mat[14]*mat[7],   this->mat[3]*mat[4]  + this->mat[7]*mat[5]  + this->mat[11]*mat[6]  + this->mat[15]*mat[7],
                    this->mat[0]*mat[8]  + this->mat[4]*mat[9]  + this->mat[8]*mat[10] + this->mat[12]*mat[11],  this->mat[1]*mat[8]  + this->mat[5]*mat[9]  + this->mat[9]*mat[10] + this->mat[13]*mat[11],  this->mat[2]*mat[8]  + this->mat[6]*mat[9]  + this->mat[10]*mat[10] + this->mat[14]*mat[11],  this->mat[3]*mat[8]  + this->mat[7]*mat[9]  + this->mat[11]*mat[10] + this->mat[15]*mat[11],
                    this->mat[0]*mat[12] + this->mat[4]*mat[13] + this->mat[8]*mat[14] + this->mat[12]*mat[15],  this->mat[1]*mat[12] + this->mat[5]*mat[13] + this->mat[9]*mat[14] + this->mat[13]*mat[15],  this->mat[2]*mat[12] + this->mat[6]*mat[13] + this->mat[10]*mat[14] + this->mat[14]*mat[15],  this->mat[3]*mat[12] + this->mat[7]*mat[13] + this->mat[11]*mat[14] + this->mat[15]*mat[15]);
}

CoMat4x4& CoMat4x4::operator*=(const CoMat4x4& mat)
{
    *this = *this * mat;
    return *this;
}

Gfloat CoMat4x4::operator[](Gint index) const
{
    return mat[index];
}

Gfloat& CoMat4x4::operator[](Gint index)
{
    return mat[index];
}
