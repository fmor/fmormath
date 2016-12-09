#pragma once


#include "mathtypes.h"
#include "vector2f.h"
#include "vector3f.h"
#include "vector4f.h"


namespace fmormath {

u32      Clamp( u32 value, u32 min, u32 max );
s32      Clamp( s32 value, s32 min, s32 max );


Real     Clamp( Real f, Real min, Real max );
Vector2f Clamp( const Vector2f& value, const Vector2f& min, const Vector2f& max );
Vector3f Clamp( const Vector3f& value, const Vector3f& min, const Vector3f& max );
Vector4f Clamp( const Vector4f& value, const Vector4f& min, const Vector4f& max );




}

