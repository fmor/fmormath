#pragma once

#include "vector3f.h"
#include "mathtypes.h"

namespace fmormath {

class Matrix3x3
{
    Real m_Reals[3][3];

public:

    inline Matrix3x3()
    {}

    Matrix3x3( Real r00, Real r01, Real r02,
               Real r10, Real r11, Real r12,
               Real r20, Real r21, Real r22 );


    void set( Real r00, Real r01, Real r02,
              Real r10, Real r11, Real r12,
              Real r20, Real r21, Real r22 );

    inline const Real* operator []( uint index ) const { return m_Reals[index]; }
    inline Real* operator []( uint index ) { return m_Reals[index]; }

    bool operator == ( const Matrix3x3& other ) const;
    inline bool operator !=( const Matrix3x3& other ) const { return !( *this == other ); }
    void operator *=( Real f );
    void operator *=( const Matrix3x3& other );
    void operator +=( const Matrix3x3& other );
    void operator -=( const Matrix3x3& other );


    Matrix3x3 operator * ( Real f ) const;
    Vector3f  operator *( const Vector3f& v3 ) const;
    Matrix3x3 operator *( const Matrix3x3& other ) const;
    Matrix3x3 operator +( const Matrix3x3& other ) const;
    Matrix3x3 operator -( const Matrix3x3& other ) const;


    Real determinant() const;
    Matrix3x3 inverse() const;
    Matrix3x3 transpose() const;


    static const Matrix3x3 ZERO;
    static const Matrix3x3 IDENTITY;

};



}

