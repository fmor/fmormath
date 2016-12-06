#include "vector3f.h"


#include "matrix4x4.h"
#include "matrix3x3.h"
#include "clamp.h"
#include "quaternion.h"

#include "constants.h"

#include <cmath>


namespace fmormath {

const Vector3f Vector3f::ZERO( 0.0f, 0.0f, 0.0f );
const Vector3f Vector3f::UNIT_X( 1, 0.0f, 0.0f );
const Vector3f Vector3f::UNIT_Y( 0.0f, 1, 0.0f);
const Vector3f Vector3f::UNIT_Z( 0.0f, 0.0f, 1);
const Vector3f Vector3f::NEGATIVE_UNIT_X( -1,  0.0f,  0.0f );
const Vector3f Vector3f::NEGATIVE_UNIT_Y(  0.0f, -1,  0.0f );
const Vector3f Vector3f::NEGATIVE_UNIT_Z(  0.0f,  0.0f, -1 );
const Vector3f Vector3f::UNIT_SCALE( 1, 1, 1 );

Real Vector3f::angle( const Vector3f& other )
{
    Real l = length() * other.length();
    Real dot = x*other.x + y*other.y + z*other.z;
    Real _cos = Clamp( dot / l, -1.f, 1.f );
    return std::acos( _cos );
}


bool Vector3f::operator ==( const Vector3f& other ) const
{
    if( std::abs(x - other.x) > Constants::EPSILON )
        return false;
    if( std::abs(y - other.y) > Constants::EPSILON )
        return false;
    if( std::abs(z - other.z) > Constants::EPSILON )
        return false;
    return true;

//    Real d = std::abs(y - other.y);
//    Real e = Constants::EPSILON;

}

void Vector3f::normalize()
{
    const Real lenSquared = x*x + y*y + z*z;

    if( lenSquared > Real(0) )
    {
        const Real invLen = Real(1.0) / std::sqrt(lenSquared);
        x *= invLen;
        y *= invLen;
        z *= invLen;
    }
}
void Vector3f::rotate( Real radian, const Vector3f& _axis )
{
    Vector3f axis = _axis;
    axis.normalize();


    Quaternion q( radian, axis );



    Vector3f result = q * *this;

    *this = result;
}

}
