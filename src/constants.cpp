#include "constants.h"

#include <cmath>
#include <limits>


namespace fmormath {

const Real Constants::EPSILON = std::numeric_limits<Real>::epsilon();
const Real Constants::PI = 4.0 * atan( 1.0 );
const Real Constants::PI_HALF = 2.0 * atan( 1.0 );
const Real Constants::PI_QUARTER = atan( 1.0 );
const Real Constants::PI_DOUBLE = 8.0 * atan(1.0);


}
