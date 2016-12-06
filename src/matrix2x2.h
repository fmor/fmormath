#pragma once

#include "mathtypes.h"
#include "vector2f.h"

namespace fmormath {

class Matrix2x2
{
    Real m_Reals[2][2];

public:

    inline Matrix2x2()
    {}
    inline Matrix2x2(Real r00, Real r01, Real r10, Real r11 )
    {
        m_Reals[0][0] = r00;
        m_Reals[0][1] = r01;
        m_Reals[1][0] = r10;
        m_Reals[1][1] = r11;
    }

    inline void set( Real r00, Real r01, Real r10, Real r11 )
    {
        m_Reals[0][0] = r00;
        m_Reals[0][1] = r01;
        m_Reals[1][0] = r10;
        m_Reals[1][1] = r11;
    }

    inline const Real* operator[]( uint index ) const { return m_Reals[index]; }
    inline Real* operator[]( uint index ) { return m_Reals[index]; }

    bool operator == (const Matrix2x2& other ) const;
    inline bool operator != ( const Matrix2x2& other ) const { return !( *this == other ); }
    void operator *=( Real f );
    void operator *=( const Matrix2x2& other );
    void operator +=( const Matrix2x2& other );
    void operator -=( const Matrix2x2& other );

    Matrix2x2 operator *( Real r ) const;
    Vector2f  operator *( const Vector2f& v2 ) const;
    Matrix2x2 operator *( const Matrix2x2& other ) const;

    Matrix2x2 operator +( const Matrix2x2& other ) const;
    Matrix2x2 operator -( const Matrix2x2& other ) const;





    Real determinant() const;


    Matrix2x2 inverse() const;
    Matrix2x2 transpose() const;


    static const Matrix2x2 ZERO;
    static const Matrix2x2 IDENTITY;

};

}

