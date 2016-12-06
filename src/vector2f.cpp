#include "vector2f.h"

#include <cmath>


#include "constants.h"

namespace fmormath {

const Vector2f Vector2f::ZERO(0,0);
const Vector2f Vector2f::UNIT_X(1,0);
const Vector2f Vector2f::UNIT_Y(0,1);
const Vector2f Vector2f::NEGATIVE_UNIT_X(-1,0);
const Vector2f Vector2f::NEGATIVE_UNIT_Y(0,-1);
const Vector2f Vector2f::UNIT_SCALE(1,1);


void Vector2f::rotate( float radian )
{
    const float cosR = std::cos( radian );
    const float sinR = std::sin( radian );

    float _x = x*cosR - y*sinR;
    float _y = x*sinR + y*cosR;

    x = _x;
    y = _y;
}


//Vector2f& Vector2f::operator =(const Vector2f& other)
//{
//    x = other.x;
//    y = other.y;
//    return *this;
//}



bool Vector2f::operator ==(const Vector2f& other) const
{
    if( std::abs(x - other.x) > Constants::EPSILON )
        return false;
    if( std::abs(y - other.y) > Constants::EPSILON )
        return false;
    return true;
}

bool Vector2f::operator !=(const Vector2f& other) const
{
    if( x == other.x )
        return false;
    if( y == other.y )
        return false;
    return true;
}

void Vector2f::normalize()
{
    const Real lenSquared = x*x + y*y;
    if( lenSquared > 0 )
    {
        Real invLen = 1.0f / std::sqrt(lenSquared);
        x *= invLen;
        y *= invLen;
    }
}


Vector2f Vector2f::operator +(  const Vector2f& second ) const
{
    Vector2f result;
    result.x = x + second.x;
    result.y = y + second.y;
    return result;
}

Vector2f operator -(const Vector2f& first, const Vector2f& second )
{
    Vector2f result;
    result.x = first.x - second.x;
    result.y = first.y - second.y;
    return result;
}

Vector2f operator /(const Vector2f& first, Real second )
{
    Vector2f result;
    const  Real invFirst = 1.0 / second;
    result.x = first.x * invFirst;
    result.y = first.y * invFirst;
    return result;
}








}
