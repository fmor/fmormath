#include "common.h"
#include <cmath>

#include "constants.h"

namespace fmormath {

Real DegreeToRadian( Real degree )
{
    static const Real R_PI_DIVBY_180 = Constants::PI / Real(180);
    Real radian = degree * R_PI_DIVBY_180;
    return radian;
}

Real RadianToDegreee(Real radian)
{
    static const Real R_180_DIVBY_PI = Real(180) / Constants::PI ;
    Real degree = R_180_DIVBY_PI * radian;
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




#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
// https://fr.wikipedia.org/wiki/Racine_carr%C3%A9e_inverse_rapide
Real Q_rsqrt( Real number )
{
    long i;
    Real x2, y;
    const Real threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil Realing point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( Real * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}
#pragma GCC diagnostic pop




Real IsAlmostEqual(Real a, Real b)
{
    // http://stackoverflow.com/questions/17333/most-effective-way-for-float-and-double-comparison#77735
    const Real absA = std::abs(a);
    const Real absB = std::abs(b);
    const Real e = std::abs( a - b );
    const Real eps = Constants::EPSILON * ( (absA > absB ) ?  absA : absB );
    if( e > eps  )
        return false;
    return true;
}




}
