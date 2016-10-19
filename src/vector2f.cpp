#include "vector2f.h"

#include <cmath>

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
    const float sinR= std::sin( radian );
    float _x = x*cosR - y*sinR;
    float _y = x*sinR + y*cosR;
    x = _x;
    y = _y;
}







}
