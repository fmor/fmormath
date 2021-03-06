#pragma once

#include "mathtypes.h"
#include "vector3f.h"
#include "vector4f.h"


namespace fmormath {

struct Quaternion
{
    Real x;
    Real y;
    Real z;
    Real w;

    inline Quaternion()
    {}

    inline Quaternion( Real _w, Real _x, Real _y, Real _z ) :
        x( _x ),
        y( _y ),
        z( _z ),
        w( _w )
    {}

    inline Quaternion( const Vector3f& v3 ) :
        x( v3.x ),
        y( v3.y ),
        z( v3.z ),
        w( 0 )
    {

    }
    inline Quaternion( const Vector4f& v4 ) :
        x( v4.x ),
        y( v4.y ),
        z( v4.z ),
        w( v4.w )
    {}

    Quaternion( Real radian, const Vector3f& axis );
    Quaternion& fromAngleAxis( Real radian, const Vector3f& axis );


    bool operator ==( const Quaternion& other ) const;
    bool operator !=( const Quaternion& other ) const;

    Quaternion operator +( const Quaternion& other ) const;
    Quaternion operator -( const Quaternion& other ) const;


    Quaternion operator *( const Quaternion& other ) const;
    Vector3f operator *( const Vector3f& v3 ) const;

    Quaternion& operator =( const Vector4f& v4 );


    void operator +=( const Quaternion& other );
    void operator -=( const Quaternion& other );
    void operator *=( const Quaternion& other );


    inline void set( Real _w, Real _x, Real _y, Real _z )
    {
        w = _w;
        x = _x;
        y = _y;
        z = _z;
    }



    Quaternion conjugate() const;
    Quaternion inverse() const;
    Real norm() const;
    Real normSquared() const;
    void normalize();
    Real dot( const Quaternion& other ) const;






    static const Quaternion IDENTITY;
    static const Quaternion ZERO;

};





}
