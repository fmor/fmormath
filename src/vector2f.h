#pragma once

#include <cmath>
#include "fmormathvector.h"


namespace fmormath {



struct Vector2f : public fmVector<Vector2f>
{
    float x;
    float y;


    inline Vector2f()
    {}

    inline Vector2f( float _x, float _y ) :
        x( _x ),
        y( _y )
    {}
    inline Vector2f( const Vector2f& other ) :
        x( other.x ),
        y( other.y )
    {}


    virtual inline bool operator ==( const Vector2f& other ) const final override
    {
        if( x != other.x ) return false;
        if( y != other.y ) return false;
        return true;
    }
    virtual inline bool operator !=( const Vector2f& other ) const final override
    {
        return !( *this == other );
    }


    virtual inline void operator *=( float f ) final override
    {
        x *= f;
        y *= f;
    }
    virtual inline void operator /=( float f ) final override
    {
        x /= f;
        y /= f;
    }
    virtual inline Vector2f operator *( float f) const final override
    {
        Vector2f result;
        result.x *= f;
        result.y *= f;
        return result;
    }
    virtual inline Vector2f operator /( float f) const final override
    {
        Vector2f result;
        result.x /= f;
        result.y /= f;
        return result;
    }

    virtual inline void operator +=( const Vector2f& other ) final override
    {
        x += other.x;
        y += other.y;
    }
    virtual inline void operator -=( const Vector2f& other ) final override
    {
        x -= other.x;
        y -= other.y;
    }


    virtual inline Vector2f operator +( const Vector2f& other ) const final override
    {
        Vector2f result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }
    virtual inline Vector2f operator -( const Vector2f& other ) const final override
    {
        Vector2f result;
        result.x = x - other.x;
        result.y = y - other.y;
        return result;
    }
    virtual inline Vector2f operator -() const final override
    {
        Vector2f result;
        result.x = -x;
        result.y = -y;
        return result;
    }



    inline void set( float _x, float _y )
    {
        x=_x;
        y=_y;
    }

    virtual inline float dot( const Vector2f& other ) const final override
    {
        return x*other.x + y*other.y;
    }
    virtual inline float length() const final override
    {
        return std::sqrt( x*x + y*y);
    }
    virtual inline float lengthSquared() const final override
    {
        return ( x*x + y*y);
    }
    virtual inline void  scale( const Vector2f& other ) final override
    {
        x *= other.x;
        y *= other.y;
    }

    virtual inline void normalize() final override
    {
        float len = std::sqrt( x*x + y*y );
        if( len > 0.f )
        {
            float invLen = 1.0f / len;
            x *= invLen;
            y *= invLen;
        }
    }

    void rotate( float radian );





    static const Vector2f ZERO;
    static const Vector2f UNIT_X;
    static const Vector2f UNIT_Y;
    static const Vector2f NEGATIVE_UNIT_X;
    static const Vector2f NEGATIVE_UNIT_Y;
    static const Vector2f UNIT_SCALE;

};

}
