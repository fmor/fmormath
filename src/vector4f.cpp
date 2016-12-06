#include "vector4f.h"

#include <cmath>
#include "constants.h"

namespace fmormath {

const Vector4f Vector4f::ZERO( 0, 0, 0, 0);
const Vector4f Vector4f::UNIT_X( 1, 0, 0, 0);
const Vector4f Vector4f::UNIT_Y( 0, 1, 0, 0);
const Vector4f Vector4f::UNIT_Z( 0, 0, 1, 0);
const Vector4f Vector4f::UNIT_W( 0, 0, 0, 1);

const Vector4f Vector4f::NEGATIVE_UNIT_X( -1, 0, 0, 0);
const Vector4f Vector4f::NEGATIVE_UNIT_Y( 0, -1, 0, 0);
const Vector4f Vector4f::NEGATIVE_UNIT_Z( 0, 0, -1, 0);
const Vector4f Vector4f::NEGATIVE_UNIT_W( 0, 0, 0, -1);

const Vector4f Vector4f::UNIT_SCALE( 1, 1, 1, 1);


bool Vector4f::operator ==( const Vector4f& other ) const
{
    if( std::abs(x - other.x) > Constants::EPSILON )
        return false;
    if( std::abs(y - other.y) > Constants::EPSILON )
        return false;
    if( std::abs(z - other.z) > Constants::EPSILON )
        return false;
    if( std::abs(w - other.w) > Constants::EPSILON )
        return false;

    return true;
}

void Vector4f::normalize()
{
    Real lenSquared = x*x + y*y + z*z + w*w;
    if( lenSquared > 0 )
    {
        Real invLen = Real(1.0) / std::sqrt(lenSquared);
        x *= invLen;
        y *= invLen;
        z *= invLen;
        w *= invLen;
    }
}


}
