#pragma once

#include "vector2f.h"


namespace fmormath {


class Rectangle
{

    Vector2f m_TopLeft;

    float mWidth;
    float mHeight;

public:

    inline Rectangle() :
        m_TopLeft( Vector2f(0,0) ),
        mWidth( 0 ),
        mHeight( 0 )
    {}

    inline Rectangle( float x, float y, float width, float height ) :
        m_TopLeft( Vector2f(x,y) ),
        mWidth( width ),
        mHeight( height )
    {}



    inline const Vector2f& getTopLeft() const { return m_TopLeft; }
    inline float getWidth()   const { return mWidth; }
    inline float getHeight()  const { return mHeight; }





    inline void set( float x, float y, float width, float height )
    {
        m_TopLeft.set( x, y );

        mWidth =  ( width  < 0 ) ? 0 : width;
        mHeight = ( height < 0 ) ? 0 : height;
    }

    inline float ratio() const { return float(mWidth)/float(mHeight); }
    inline float area() const { return mWidth * mHeight; }



    inline bool isPointInside( float x, float y ) const
    {
        if( x <  m_TopLeft.x )           return false;
        if( x > (m_TopLeft.x+mWidth) )   return false;

        if( y >  m_TopLeft.y )           return false;
        if( y < (m_TopLeft.y-mHeight) )   return false;

        return true;
    }

    inline void setTopLeft( float x, float y )
    {
        m_TopLeft.x = x;
        m_TopLeft.y = y;
    }
    inline void setDimensions( float width, float height )
    {
        mWidth = width;
        mHeight = height;
    }

    bool interset( const Rectangle& other ) const;


    static const Rectangle ZERO;
    static const Rectangle UNIT;




};

}

