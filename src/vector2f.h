#pragma once

#include <cmath>
#include "mathtypes.h"


namespace fmormath {



struct Vector2f
{
    union
    {
        Real data[2];
        Real xy[2];
        Real uv[2];

        struct
        {
            Real x;
            Real y;
        };


        struct
        {
            Real u;
            Real v;
        };
    };



    inline Vector2f()
    {}

    inline Vector2f( Real _x, Real _y ) :
        x( _x ),
        y( _y )
    {}




    inline Real operator[]( uint index ) const { return data[index]; }


    bool operator ==( const Vector2f& other ) const;
    bool operator !=( const Vector2f& other ) const;


    inline void operator +=( const Vector2f& other )
    {
        x += other.x;
        y += other.y;
    }
    inline void operator -=( const Vector2f& other )
    {
        x -= other.x;
        y -= other.y;
    }


    inline void operator *=( Real f )
    {
        x *= f;
        y *= f;
    }
    inline void operator /=( Real f )
    {
        x /= f;
        y /= f;
    }




    inline Vector2f operator -() const
    {
        Vector2f result;
        result.x = -x;
        result.y = -y;
        return result;
    }



    inline void set( Real _x, Real _y )
    {
        x=_x;
        y=_y;
    }

    inline Real dot( const Vector2f& other ) const
    {
        return x*other.x + y*other.y;
    }
    inline Real length() const
    {
        return std::sqrt( x*x + y*y);
    }
    inline Real lengthSquared() const
    {
        return ( x*x + y*y);
    }
    inline void  scale( const Vector2f& other )
    {
        x *= other.x;
        y *= other.y;
    }

    void normalize();

    void rotate( Real radian );





    static const Vector2f ZERO;
    static const Vector2f UNIT_X;
    static const Vector2f UNIT_Y;
    static const Vector2f NEGATIVE_UNIT_X;
    static const Vector2f NEGATIVE_UNIT_Y;
    static const Vector2f UNIT_SCALE;


    Vector2f operator +( const Vector2f& second ) const;


};


//Vector2f operator +(const Vector2f& first, const Vector2f& second );



// Vector2f operator +( const Vector2f& first, const Vector2f& second );
Vector2f operator -(  const Vector2f& first, const Vector2f& second);


inline Vector2f operator *( const Vector2f& first, Real second )
{
    Vector2f result;
    result.x = first.x * second;
    result.y = first.y * second;
    return result;
}
inline Vector2f operator*( Real first, const Vector2f& second )
{
    Vector2f result;
    result.x = first * second.x;
    result.y = first * second.y;
    return result;
}

Vector2f operator /( const Vector2f& first, Real second );


}
