#pragma once

#include "vector3f.h"
#include "mathtypes.h"

namespace fmormath {

class euler
{
public:

    static Vector3f RotateAroundAxis( const Vector3f& v3, Real radian, const Vector3f& axis );

};


}
