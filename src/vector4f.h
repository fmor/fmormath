#pragma once

#include <cmath>
#include "mathtypes.h"

namespace fmormath {


struct Vector4f
{

    union
    {
        Real data[4];
        Real xyzw[4];
        Real rgba[4];

        struct
        {
            Real x;
            Real y;
            Real z;
            Real w;
        };

        struct
        {
            Real r;
            Real g;
            Real b;
            Real a;
        };




    };



    inline Vector4f()
    {}

    inline Vector4f( Real _x, Real _y, Real _z, Real _w ) :
        x( _x ),
        y( _y ),
        z( _z ),
        w( _w )
    {}

    inline Real operator[]( uint index ) const { return data[index]; }

    bool operator ==( const Vector4f& other ) const;
    inline bool operator !=( const Vector4f& other ) const
    {
        return !( *this == other );
    }
    inline void operator *=( Real f)
    {
        x *= f;
        y *= f;
        z *= f;
        w *= f;
    }
    inline void operator /=( Real f)
    {
        x /= f;
        y /= f;
        z /= f;
        w /= f;
    }
    inline Vector4f operator *( Real f) const
    {
        Vector4f result;
        result.x *= f;
        result.y *= f;
        result.z *= f;
        result.w *= f;
        return result;
    }
    inline Vector4f operator /( Real f) const
    {
        Vector4f result;
        result.x /= f;
        result.y /= f;
        result.z /= f;
        result.w /= f;
        return result;
    }
    inline void operator +=( const Vector4f& other )
    {
        x = x + other.x;
        y = y + other.y;
        z = z + other.z;
        w = w + other.w;
    }
    inline void operator -=( const Vector4f& other )
    {
        x = x - other.x;
        y = y - other.y;
        z = z - other.z;
        w = w - other.w;
    }

    inline Vector4f operator +( const Vector4f& other ) const
    {
        Vector4f result;
        result.x = x + other.x;
        result.y = y + other.y;
        result.z = z + other.z;
        result.w = w + other.w;
        return result;
    }
    inline Vector4f operator -( const Vector4f& other ) const
    {
        Vector4f result;
        result.x = x - other.x;
        result.y = y - other.y;
        result.z = z - other.z;
        result.w = w - other.w;
        return result;
    }
    inline Vector4f operator -() const
    {
        Vector4f result;
        result.x = -x;
        result.y = -y;
        result.z = -z;
        result.w = -w;
        return result;
    }

    inline void set( Real _x, Real _y, Real _z, Real _w )
    {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }

    inline Real dot( const Vector4f& other ) const
    {
        return x*other.x + y*other.y + z*other.z + w*other.w;
    }
    inline Real length() const
    {
        return std::sqrt( x*x + y*y + z*z + w*w );
    }
    inline Real lengthSquared() const
    {
        return ( x*x + y*y + z*z + w*w );
    }
    inline void  scale( const Vector4f& other )
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;
    }
    void normalize();



    static const Vector4f ZERO;
    static const Vector4f UNIT_X;
    static const Vector4f UNIT_Y;
    static const Vector4f UNIT_Z;
    static const Vector4f UNIT_W;

    static const Vector4f NEGATIVE_UNIT_X;
    static const Vector4f NEGATIVE_UNIT_Y;
    static const Vector4f NEGATIVE_UNIT_Z;
    static const Vector4f NEGATIVE_UNIT_W;

    static const Vector4f UNIT_SCALE;


};

inline Vector4f operator*( Real r, const Vector4f& v ) { return v * r; }



}
