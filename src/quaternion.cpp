#include "quaternion.h"

#include "constants.h"


#include <cmath>

namespace fmormath {


const Quaternion Quaternion::IDENTITY( 1, 0, 0, 0 );
const Quaternion Quaternion::ZERO( 0, 0, 0, 0 );

Quaternion::Quaternion( Real radian, const Vector3f& axis )
{
//#ifdef _DEBUG_
//    const Real d =  1.0 - axis.length();
//    if( d > Constants::EPSILON  )
//        throw;
//#endif

    const Real half_radian = radian * 0.5;
    const Real _cos = std::cos( half_radian );
    const Real _sin = std::sin( half_radian );

    w = _cos;
    x = _sin * axis.x;
    y = _sin * axis.y;
    z = _sin * axis.z;
}

Quaternion& Quaternion::fromAngleAxis(Real radian, const Vector3f &axis)
 {
//    Quaternion* q = new(this) Quaternion(radian,axis);
    const Real half_radian = radian * 0.5;
    const Real _cos = std::cos( half_radian );
    const Real _sin = std::sin( half_radian );

    w = _cos;
    x = _sin * axis.x;
    y = _sin * axis.y;
    z = _sin * axis.z;

    return *this;
 }

bool Quaternion::operator ==(const Quaternion &other) const
{
    if( w != other.w )  return false;
    if( x != other.x )  return false;
    if( y != other.y )  return false;
    if( z != other.z )  return false;
    return true;
}

bool Quaternion::operator !=(const Quaternion &other) const
{
    if( w == other.w )  return false;
    if( x == other.x )  return false;
    if( y == other.y )  return false;
    if( z == other.z )  return false;
    return true;
}

Quaternion Quaternion::operator +(const Quaternion &other) const
{
    Quaternion result;
    result.w = w + other.w;
    result.x = x + other.x;
    result.y = y + other.y;
    result.z = z + other.z;
    return result;
}

Quaternion Quaternion::operator -(const Quaternion &other) const
{
    Quaternion result;
    result.w = w - other.w;
    result.x = x - other.x;
    result.y = y - other.y;
    result.z = z - other.z;
    return result;
}

Quaternion Quaternion::operator *(const Quaternion& other ) const
{
    Quaternion result;
    result.w = w*other.w - x*other.x - y*other.y - z*other.z;
    result.x = w*other.x + x*other.w + y*other.z - z*other.y;
    result.y = w*other.y - x*other.z + y*other.w + z*other.x;
    result.z = w*other.z + x*other.y - y*other.x + z*other.w;

    return result;
}

Vector3f Quaternion::operator *(const Vector3f& v3 ) const
{
    Vector3f result;
    Quaternion other( v3 );

    Quaternion q = (*this) * other * inverse();

    result.set( q.x, q.y, q.z );

    return result;
}

Quaternion& Quaternion::operator =(const Vector4f& v4 )
{
    w = v4.w;
    x = v4.x;
    y = v4.y;
    z = v4.z;
    return *this;
}

void Quaternion::operator +=(const Quaternion &other)
{
    w += other.w;
    x += other.x;
    y += other.y;
    z += other.z;
}

void Quaternion::operator -=(const Quaternion &other)
{
    w -= other.w;
    x -= other.x;
    y -= other.y;
    z -= other.z;
}

void Quaternion::operator *=(const Quaternion &other)
{
    Quaternion result;
    result.w = w*other.w - x*other.x - y*other.y - z*other.z;
    result.x = w*other.x + x*other.w + y*other.z - z*other.y;
    result.y = w*other.y - x*other.z + y*other.w + z*other.x;
    result.z = w*other.z + x*other.y - y*other.x + z*other.w;

    *this = result;
}

Quaternion Quaternion::conjugate() const
{
    Quaternion q;

    q.w =  w;
    q.x = -x;
    q.y = -y;
    q.z = -z;

    return q;
}

Quaternion Quaternion::inverse() const
{
    Quaternion q = conjugate();
    Real ns = normSquared();
    if( ns != Real(1.0) )
    {
          ns = Real(1.0) /  ns;
          q.w *= ns;
          q.x *= ns;
          q.y *= ns;
          q.z *= ns;
    }


    return q;
}

Real Quaternion::norm() const
{
    Real l = std::sqrt( w*w + x*x + y*y + z*z );
    return l;
}

Real Quaternion::normSquared() const
{
    Real l =  w*w + x*x + y*y + z*z;
    return l;
}

void Quaternion::normalize()
{
    Real f = 1.0 / std::sqrt( w*w + x*x + y*y + z*z );
    w *= f;
    x *= f;
    y *= f;
    z *= f;
}

Real Quaternion::dot( const Quaternion& other ) const
{
    Real d = w*other.w + x*other.x + y*other.y + z*other.z;
    return d;
}



}
