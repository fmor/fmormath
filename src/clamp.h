#pragma once


#include "mathtypes.h"
#include "vector2f.h"
#include "vector3f.h"
#include "vector4f.h"


namespace fmormath {

u32      Clamp( u32 value, u32 min, u32 max );
i32      Clamp( i32 value, i32 min, i32 max );


float    Clamp( float f, float min, float max );
Vector2f Clamp( const Vector2f& value, const Vector2f& min, const Vector2f& max );
Vector3f Clamp( const Vector3f& value, const Vector3f& min, const Vector3f& max );
Vector4f Clamp( const Vector4f& value, const Vector4f& min, const Vector4f& max );




}

