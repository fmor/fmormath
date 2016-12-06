#pragma once

#include "mathtypes.h"

namespace fmormath {

Real DegreeToRadian( Real degree );
Real RadianToDegreee( Real radian );

u32 NextPowerOf2( u32 value );
bool IsPowerOf2( int i);
Real Q_rsqrt( Real number );
Real IsAlmostEqual( Real a, Real b );

}

