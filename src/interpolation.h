#pragma once

#include "vector2f.h"
#include "vector3f.h"
#include "vector4f.h"

#include "quaternion.h"

namespace fmormath {

Real        Lerp( Real position, Real begin, Real end );
Vector2f    Lerp( Real position, const Vector2f& begin, const Vector2f& end );
Vector3f    Lerp( Real position, const Vector3f& begin, const Vector3f& end );
Vector4f    Lerp( Real position, const Vector4f& begin, const Vector4f& end );


}
