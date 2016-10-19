#include "vector3f.h"


#include "matrix4x4.h"
#include "matrix3x3.h"
#include "clamp.h"
#include "quaternion.h"

namespace fmormath {

const Vector3f Vector3f::ZERO( 0.0f, 0.0f, 0.0f );
const Vector3f Vector3f::UNIT_X( 1, 0.0f, 0.0f );
const Vector3f Vector3f::UNIT_Y( 0.0f, 1, 0.0f);
const Vector3f Vector3f::UNIT_Z( 0.0f, 0.0f, 1);
const Vector3f Vector3f::NEGATIVE_UNIT_X( -1,  0.0f,  0.0f );
const Vector3f Vector3f::NEGATIVE_UNIT_Y(  0.0f, -1,  0.0f );
const Vector3f Vector3f::NEGATIVE_UNIT_Z(  0.0f,  0.0f, -1 );
const Vector3f Vector3f::UNIT_SCALE( 1, 1, 1 );

real Vector3f::angle( const Vector3f& other )
{
    real l = length() * other.length();
    real dot = x*other.x + y*other.y + z*other.z;
    real _cos = Clamp( dot / l, -1.f, 1.f );
    return std::acos( _cos );
}


void Vector3f::rotate( real radian, const Vector3f& _axis )
{
    Vector3f axis = _axis;
    axis.normalize();


    Quaternion q( radian, axis );



//    const real half_radian = radian * 0.5;
//    const real _cos = std::cos( half_radian );
//    const real _sin = std::sin( half_radian );


//    q.w = _cos;
//    q.x = _sin * axis.x;
//    q.y = _sin * axis.y;
//    q.z = _sin * axis.z;


    Vector3f result = q * *this;

    *this = result;
}

}
