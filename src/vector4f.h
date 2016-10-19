#pragma once

#include <cmath>
#include "fmormathvector.h"

namespace fmormath {


struct Vector4f : public fmVector<Vector4f>
{
    float x;
    float y;
    float z;
    float w;


    inline Vector4f(){}
    inline Vector4f( float _x, float _y, float _z, float _w ) :
        x( _x ),
        y( _y ),
        z( _z ),
        w( _w )
    {}
    inline Vector4f( const Vector4f& other ) :
        x( other.x ),
        y( other.y ),
        z( other.z ),
        w( other.w )
    {}

    virtual inline bool operator ==( const Vector4f& other ) const final override
    {
        if( x != other.x ) return false;
        if( y != other.y ) return false;
        if( z != other.z ) return false;
        if( w != other.w ) return false;
        return true;
    }
    virtual inline bool operator !=( const Vector4f& other ) const final override
    {
        return !( *this == other );
    }
    virtual inline void operator *=( float f) final override
    {
        x *= f;
        y *= f;
        z *= f;
        w *= f;
    }
    virtual inline void operator /=( float f) final override
    {
        x /= f;
        y /= f;
        z /= f;
        w /= f;
    }
    virtual inline Vector4f operator *( float f) const final override
    {
        Vector4f result;
        result.x *= f;
        result.y *= f;
        result.z *= f;
        result.w *= f;
        return result;
    }
    virtual inline Vector4f operator /( float f) const final override
    {
        Vector4f result;
        result.x /= f;
        result.y /= f;
        result.z /= f;
        result.w /= f;
        return result;
    }
    virtual inline void operator +=( const Vector4f& other ) final override
    {
        x = x + other.x;
        y = y + other.y;
        z = z + other.z;
        w = w + other.w;
    }
    virtual inline void operator -=( const Vector4f& other ) final override
    {
        x = x - other.x;
        y = y - other.y;
        z = z - other.z;
        w = w - other.w;
    }

    virtual inline Vector4f operator +( const Vector4f& other ) const final override
    {
        Vector4f result;
        result.x = x + other.x;
        result.y = y + other.y;
        result.z = z + other.z;
        result.w = w + other.w;
        return result;
    }
    virtual inline Vector4f operator -( const Vector4f& other ) const final override
    {
        Vector4f result;
        result.x = x - other.x;
        result.y = y - other.y;
        result.z = z - other.z;
        result.w = w - other.w;
        return result;
    }
    virtual inline Vector4f operator -() const final override
    {
        Vector4f result;
        result.x = -x;
        result.y = -y;
        result.z = -z;
        result.w = -w;
        return result;
    }

    inline void set( float _x, float _y, float _z, float _w )
    {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }

    virtual inline float dot( const Vector4f& other ) const final override
    {
        return x*other.x + y*other.y + z*other.z + w*other.w;
    }
    virtual inline float length() const final override
    {
        return std::sqrt( x*x + y*y + z*z + w*w );
    }
    virtual inline float lengthSquared() const final override
    {
        return ( x*x + y*y + z*z + w*w );
    }
    virtual inline void  scale( const Vector4f& other ) final override
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;
    }
    virtual inline void normalize() final override
    {
        float len = std::sqrt( x*x + y*y + z*z + w*w );
        if( len > 0.f )
        {
            float invLen = 1.0f / len;
            x *= invLen;
            y *= invLen;
            z *= invLen;
            w *= invLen;
        }
    }



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



}
