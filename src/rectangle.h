#pragma once

#include "vector2f.h"


namespace fmormath {

struct Rectangle
{
    // Top Left point
    Real m_X;
    Real m_Y;

    Real m_Width;
    Real m_Height;


    inline Rectangle()
    {}

    inline Rectangle( Real x, Real y, Real width, Real height ) :
        m_X(x),
        m_Y(y),
        m_Width( width ),
        m_Height( height )
    {}


    inline void setPosition( Real x, Real y )
    {
        m_X = x;
        m_Y = y;
    }
    inline void setSize( Real w, Real h )
    {
        m_Width  = w;
        m_Height = h;
    }



    inline void set( Real x, Real y, Real w, Real h )
    {
        m_X = x;
        m_Y = y;
        m_Width  = w;
        m_Height = h;
    }

    inline Real ratio() const { return Real(m_Width)/Real(m_Height); }
    inline Real area() const { return m_Width * m_Height; }


    bool isInside( Real x, Real y ) const;

    Rectangle& operator =( const Rectangle& other );
    bool operator ==( const Rectangle& other ) const;
    bool operator !=( const Rectangle& other ) const;




    static const Rectangle ZERO;
    static const Rectangle UNIT;




};

}

