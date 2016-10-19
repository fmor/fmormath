#include "clamp.h"

namespace fmormath {

////////////////////////////////////////
/// Clamp
///

u32 Clamp(u32 value, u32 min, u32 max)
{
    if( value < min )
        return min;
    if( value > max )
        return max;
    return value;
}

i32 Clamp(i32 value, i32 min, i32 max)
{
    if( value < min )
        return min;
    if( value > max )
        return max;
    return value;
}

float Clamp(float value, float min, float max)
{
    if( value < min )
        return min;
    if( value > max )
        return max;
    return value;
}

Vector2f Clamp(const Vector2f& value, const Vector2f& min, const Vector2f& max )
{
    Vector2f result = value;

    // X
    if( result.x < min.x )
        result.x = min.x;
    else if( result.x > max.x )
        result.x = max.x;

    // Y
    if( result.y < min.y )
        result.y = min.y;
    else if( result.y > max.y )
        result.y = max.y;

    return result;

}

Vector3f Clamp(const Vector3f& value, const Vector3f& min, const Vector3f& max )
{
    Vector3f result = value;

    // X
    if( result.x < min.x )
        result.x = min.x;
    else if( result.x > max.x )
        result.x = max.x;

    // Y
    if( result.y < min.y )
        result.y = min.y;
    else if( result.y > max.y )
        result.y = max.y;

    // Z
    if( result.z < min.z )
        result.z = min.z;
    else if( result.z > max.z )
        result.z = max.z;

    return result;
}

Vector4f Clamp( const Vector4f& value, const Vector4f& min, const Vector4f& max )
{
    Vector4f result = value;

    // X
    if( result.x < min.x )
        result.x = min.x;
    else if( result.x > max.x )
        result.x = max.x;

    // Y
    if( result.y < min.y )
        result.y = min.y;
    else if( result.y > max.y )
        result.y = max.y;

    // Z
    if( result.z < min.z )
        result.z = min.z;
    else if( result.z > max.z )
        result.z = max.z;

    // W
    if( result.w < min.w )
        result.w = min.w;
    else if( result.w > max.w )
        result.w = max.w;

    return result;
}




}

