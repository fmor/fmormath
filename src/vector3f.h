#pragma once

#include <cmath>

#include "mathtypes.h"

namespace fmormath {



struct Vector3f
{

    union
    {
        Real data[3];
        Real xyz[3];
        Real rgb[3];

        struct
        {
            Real x;
            Real y;
            Real z;
        };

        struct
        {
            Real r;
            Real g;
            Real b;
        };

    };



    inline Vector3f()
    {}

    inline Vector3f( Real _x, Real _y, Real _z ) :
        x( _x ),
        y( _y ),
        z( _z )
    {}

    inline Real operator[]( uint index ) const { return data[index]; }


    bool operator ==( const Vector3f& other ) const;

    inline bool operator !=( const Vector3f& other ) const
    {
        return !( *this == other );
    }

    inline void operator *=( Real f)
    {
        x *= f;
        y *= f;
        z *= f;
    }
    inline void operator /=( Real f)
    {
        if( f )
        {
            const Real inv = Real(1.0) / f;
            x *= inv;
            y *= inv;
            z *= inv;
        }
    }
    inline Vector3f operator *( Real f) const
    {
        Vector3f result;
        result.x = x * f;
        result.y = y * f;
        result.z = z * f;
        return result;
    }
    inline Vector3f operator /( Real f) const
    {
        Vector3f result;
        result.x = x / f;
        result.y = y / f;
        result.z = z / f;
        return result;
    }

    inline void operator +=( const Vector3f& other )
    {
        x = x + other.x;
        y = y + other.y;
        z = z + other.z;
    }
    inline void operator -=( const Vector3f& other )
    {
        x = x - other.x;
        y = y - other.y;
        z = z - other.z;
    }


    inline Vector3f operator +( const Vector3f& other ) const
    {
        Vector3f result;
        result.x = x + other.x;
        result.y = y + other.y;
        result.z = z + other.z;
        return result;
    }
    inline Vector3f operator -( const Vector3f& other ) const
    {
        Vector3f result;
        result.x = x - other.x;
        result.y = y - other.y;
        result.z = z - other.z;
        return result;
    }
    inline Vector3f operator -() const
    {
        Vector3f result;
        result.x = -x;
        result.y = -y;
        result.z = -z;
        return result;
    }

    inline void set( Real _x, Real _y, Real _z )
    {
        x = _x;
        y = _y;
        z = _z;
    }

    inline Real dot( const Vector3f& other ) const
    {
        return x*other.x + y*other.y + z*other.z;
    }
    inline Real length() const
    {
        return std::sqrt( x*x + y*y + z*z );
    }
    inline Real lengthSquared() const
    {
        return ( x*x + y*y + z*z );
    }
    inline void  scale( const Vector3f& other )
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
    }
    void normalize();
    inline Vector3f cross( const Vector3f& other ) const
    {
        return Vector3f( y*other.z-z*other.y, z*other.x-other.z*x, x*other.y-y*other.x );
    }




    Real angle( const Vector3f& other );
    void rotate( Real radian, const Vector3f& axis );




    static const Vector3f ZERO;
    static const Vector3f UNIT_X;
    static const Vector3f UNIT_Y;
    static const Vector3f UNIT_Z;
    static const Vector3f NEGATIVE_UNIT_X;
    static const Vector3f NEGATIVE_UNIT_Y;
    static const Vector3f NEGATIVE_UNIT_Z;
    static const Vector3f UNIT_SCALE;

};



inline Vector3f operator*( Real r, const Vector3f& v3 ) { return v3 * r; }


}
