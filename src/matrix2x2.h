#pragma once

#include "mathtypes.h"
#include "vector2f.h"

namespace fmormath {

class Matrix2x2
{
    float m_Reals[2][2];

public:

    inline Matrix2x2()
    {}
    inline Matrix2x2(float r00, float r01, float r10, float r11 )
    {
        m_Reals[0][0] = r00;
        m_Reals[0][1] = r01;
        m_Reals[1][0] = r10;
        m_Reals[1][1] = r11;
    }

    inline void set( float r00, float r01, float r10, float r11 )
    {
        m_Reals[0][0] = r00;
        m_Reals[0][1] = r01;
        m_Reals[1][0] = r10;
        m_Reals[1][1] = r11;
    }

    inline const float* operator[]( uint index ) const { return m_Reals[index]; }
    inline float* operator[]( uint index ) { return m_Reals[index]; }

    bool operator == (const Matrix2x2& other ) const;
    inline bool operator != ( const Matrix2x2& other ) const { return !( *this == other ); }
    void operator *=( real f );
    void operator *=( const Matrix2x2& other );
    void operator +=( const Matrix2x2& other );
    void operator -=( const Matrix2x2& other );

    Matrix2x2 operator *( const Matrix2x2& other ) const;
    Matrix2x2 operator *( real r ) const;
    Matrix2x2 operator +( const Matrix2x2& other ) const;
    Matrix2x2 operator -( const Matrix2x2& other ) const;

    Vector2f operator *( const Vector2f& v2 ) const;




    float determinant() const;


    Matrix2x2 inverse() const;
    Matrix2x2 transpose() const;


    static const Matrix2x2 ZERO;
    static const Matrix2x2 IDENTITY;

};

}

