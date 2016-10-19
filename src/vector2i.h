#pragma once

#include <cmath>

namespace fmormath {

struct Vector2i
{
    int x;
    int y;


    inline Vector2i() {}
    inline Vector2i( int _x,  int _y ) :
        x( _x ),
        y( _y )
    {

    }

    ~Vector2i();

    inline bool operator ==( const Vector2i& other ) const
    {
        return (x==other.x) && (y==other.y);
    }
    inline bool operator !=( const Vector2i& other ) const
    {
        return (x!=other.x) || (y!=other.y);
    }

    inline Vector2i operator+( const Vector2i& other ) const { return Vector2i(x+other.x, y+other.y); }
    inline Vector2i operator -(const Vector2i& other ) const { return Vector2i(x-other.x, y-other.y); }


    inline void operator +=( const Vector2i& other ) { x += other.x; y += other.y; }
    inline void operator -=( const Vector2i& other ) { x -= other.x; y -= other.y; }

    inline void set( int _x, int _y )
    {
        x = _x; y = _y;
    }
    inline void zero()
    {
        x = 0;
        y = 0;
    }

    inline int lengthSquared() const { return ( x*x +y*y); }
    inline float length() const { return std::sqrt( x*x + y*y ); }
    inline float dot( const Vector2i& other ) const { return x*other.x + y*other.y; }



    static const Vector2i ZERO;
    static const Vector2i UNIT_X;
    static const Vector2i UNIT_Y;
    static const Vector2i UNIT_SCALE;
    static const Vector2i NEGATIVE_UNIT_X;
    static const Vector2i NEGATIVE_UNIT_Y;

};

}

