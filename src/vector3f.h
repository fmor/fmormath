#pragma once

#include <cmath>

#include "fmormathvector.h"
#include "mathtypes.h"

namespace fmormath {



struct Vector3f : public fmVector<Vector3f>
{
    real x;
    real y;
    real z;

    static const Vector3f ZERO;
    static const Vector3f UNIT_X;
    static const Vector3f UNIT_Y;
    static const Vector3f UNIT_Z;
    static const Vector3f NEGATIVE_UNIT_X;
    static const Vector3f NEGATIVE_UNIT_Y;
    static const Vector3f NEGATIVE_UNIT_Z;
    static const Vector3f UNIT_SCALE;


    inline Vector3f()
    {}

    inline Vector3f( real _x, real _y, real _z ) :
        x( _x ),
        y( _y ),
        z( _z )
    {}
    inline Vector3f( const Vector3f& other ) :
        x( other.x ),
        y( other.y ),
        z( other.z )
    {}

    virtual inline bool operator ==( const Vector3f& other ) const final override
    {
        if( x != other.x ) return false;
        if( y != other.y ) return false;
        if( z != other.z ) return false;
        return true;

    }
    virtual inline bool operator !=( const Vector3f& other ) const final override
    {
        return !( *this == other );
    }

    virtual inline void operator *=( real f) final override
    {
        x *= f;
        y *= f;
        z *= f;
    }
    virtual inline void operator /=( real f) final override
    {
        const real inv = 1.0 / f;
        x *= inv;
        y *= inv;
        z *= inv;
    }
    virtual inline Vector3f operator *( real f) const final override
    {
        Vector3f result;
        result.x *= f;
        result.y *= f;
        result.z *= f;
        return result;
    }
    virtual inline Vector3f operator /( real f) const final override
    {
        Vector3f result;
        result.x /= f;
        result.y /= f;
        result.z /= f;
        return result;
    }

    virtual inline void operator +=( const Vector3f& other ) final override
    {
        x = x + other.x;
        y = y + other.y;
        z = z + other.z;
    }
    virtual inline void operator -=( const Vector3f& other ) final override
    {
        x = x - other.x;
        y = y - other.y;
        z = z - other.z;
    }


    virtual inline Vector3f operator +( const Vector3f& other ) const final override
    {
        Vector3f result;
        result.x = x + other.x;
        result.y = y + other.y;
        result.z = z + other.z;
        return result;
    }
    virtual inline Vector3f operator -( const Vector3f& other ) const final override
    {
        Vector3f result;
        result.x = x - other.x;
        result.y = y - other.y;
        result.z = z - other.z;
        return result;
    }
    virtual inline Vector3f operator -() const final override
    {
        Vector3f result;
        result.x = -x;
        result.y = -y;
        result.z = -z;
        return result;
    }

    inline void set( real _x, real _y, real _z )
    {
        x = _x;
        y = _y;
        z = _z;
    }

    virtual inline real dot( const Vector3f& other ) const final override
    {
        return x*other.x + y*other.y + z*other.z;
    }
    virtual inline real length() const final override
    {
        return std::sqrt( x*x + y*y + z*z );
    }
    virtual inline real lengthSquared() const final override
    {
        return ( x*x + y*y + z*z );
    }
    virtual inline void  scale( const Vector3f& other ) final override
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
    }
    virtual inline void normalize() final override
    {
        const real len = std::sqrt( x*x + y*y + z*z);
        if( len > 0.f )
        {
            const real invLen = 1.0f / len;
            x *= invLen;
            y *= invLen;
            z *= invLen;
        }
    }
    inline Vector3f cross( const Vector3f& other ) const
    {
        return Vector3f( y*other.z-z*other.y, z*other.x-other.z*x, x*other.y-y*other.x );
    }




    real angle( const Vector3f& other );
    void rotate( real radian, const Vector3f& axis );





};



inline Vector3f operator*( real r, const Vector3f& v3 ) { return v3 * r; }


}
