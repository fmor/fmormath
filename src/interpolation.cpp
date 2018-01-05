#include "interpolation.h"


namespace fmormath {


Real Lerp( Real position, Real begin, Real end)
{
    if( position <= 0 )
        return begin;

    if( position >= 1.0f )
        return end;

    return begin + (end-begin) * position;
}

Vector2f Lerp(Real position, const Vector2f &begin, const Vector2f &end)
{
    if( position <= 0 )
        return begin;

    if( position >= 1.0f )
        return end;


    Vector2f result;
    result.x = begin.x + (end.x-begin.x) * position;
    result.y = begin.y + (end.y-begin.y) * position;

    return result;

}

Vector3f Lerp( Real position, const Vector3f& begin, const Vector3f& end )
{
    if( position <= 0 )
        return begin;

    if( position >= 1.0f )
        return end;


    Vector3f result;
    result.x = begin.x + (end.x-begin.x) * position;
    result.y = begin.y + (end.y-begin.y) * position;
    result.z = begin.z + (end.z-begin.z) * position;

    return result;
}

Vector4f Lerp(Real position, const Vector4f& begin, const Vector4f& end )
{
    if( position <= 0 )
        return begin;

    if( position >= 1.0f )
        return end;


    Vector4f result;
    result.x = begin.x + (end.x-begin.x) * position;
    result.y = begin.y + (end.y-begin.y) * position;
    result.z = begin.z + (end.z-begin.z) * position;
    result.w = begin.w + (end.w-begin.w) * position;

    return result;

}



}

