#pragma once

#include "vector2f.h"
#include "vector3f.h"
#include "vector4f.h"

namespace fmormath {

int      RandomRange( int min, int max );
Real     RandomRange( Real min, Real max );
Vector2f RandomRange( const Vector2f& min, const Vector2f& max );
Vector3f RandomRange( const Vector3f& min, const Vector3f& max );
Vector4f RandomRange( const Vector4f& min, const Vector4f& max );



}
