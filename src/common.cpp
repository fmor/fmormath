#include "common.h"

#include "constants.h"

namespace fmormath {

float DegreeToRadian( float degree )
{
    float radian = degree * Constants::PI / 180.f;
    return radian;
}

float RadianToDegreee(float radian)
{
    float degree = 180.0f * radian / Constants::PI;
    return degree;
}





bool IsPowerOf2( int i)
{
    if ( i < 1 )
        return false;
    return (i & (i-1)) == 0;
}
u32 NextPowerOf2( u32 value )
{
    u32 result = 1;
    for( u32 i = 1; i < 32; ++i )
    {
        result = result << 1;
        if( result >= value )
        {
            return result;
        }
    }
    return 0;
}



// https://fr.wikipedia.org/wiki/Racine_carr%C3%A9e_inverse_rapide
float Q_rsqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}




}
