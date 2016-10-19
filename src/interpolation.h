#pragma once

#include "vector2f.h"
#include "vector3f.h"
#include "vector4f.h"

#include "quaternion.h"

namespace fmormath {

float       Lerp( float position, float begin, float end );
Vector2f    Lerp( float position, const Vector2f& begin, const Vector2f& end );
Vector3f    Lerp( float position, const Vector3f& begin, const Vector3f& end );
Vector4f    Lerp( float position, const Vector4f& begin, const Vector4f& end );


}
