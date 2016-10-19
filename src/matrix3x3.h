#pragma once

#include "vector3f.h"
#include "mathtypes.h"

namespace fmormath {

class Matrix3x3
{
    float m_Reals[3][3];

public:

    inline Matrix3x3()
    {}

    Matrix3x3( float r00, float r01, float r02,
                 float r10, float r11, float r12,
                 float r20, float r21, float r22 );


    void set( float r00, float r01, float r02,
              float r10, float r11, float r12,
              float r20, float r21, float r22 );

    inline const float* operator []( uint index ) const { return m_Reals[index]; }
    inline float* operator []( uint index ) { return m_Reals[index]; }

    bool operator == ( const Matrix3x3& other ) const;
    inline bool operator !=( const Matrix3x3& other ) const { return !( *this == other ); }
    void operator *=( float f );
    void operator *=( const Matrix3x3& other );
    void operator +=( const Matrix3x3& other );
    void operator -=( const Matrix3x3& other );


    Matrix3x3 operator * ( float f ) const;
    Vector3f  operator *( const Vector3f& v3 ) const;
    Matrix3x3 operator *( const Matrix3x3& other ) const;


    real determinant() const;
    Matrix3x3 inverse() const;
    Matrix3x3 transpose() const;


    static const Matrix3x3 ZERO;
    static const Matrix3x3 IDENTITY;

};



}

