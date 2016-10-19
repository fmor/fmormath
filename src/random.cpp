#include "random.h"

#define RANDOM_PRECISION    100


#include <cstdlib>

namespace fmormath {

int RandomRange(int min, int max)
{
    if( min > max )
    {
        int tmp = min;
        min = max;
        max = tmp;
    }
    int delta = max - min;
    return std::rand() % delta + min;
}

float RandomRange(float min, float max)
{
    if( min == max )
        return min;
    if( min > max )
        return min;

    float p = RANDOM_PRECISION;
    float r = float(std::rand() % RANDOM_PRECISION) / p ;
    r = min + r * (max-min);
    return r;
}

Vector2f RandomRange(const Vector2f& min, const Vector2f& max )
{
    Vector2f result;
    result.x = RandomRange( min.x, max.x );
    result.y = RandomRange( min.y, max.y );
    return result;
}


Vector3f RandomRange(const Vector3f& min, const Vector3f& max )
{
    Vector3f result;
    result.x = RandomRange( min.x, max.x );
    result.y = RandomRange( min.y, max.y );
    result.z = RandomRange( min.z, max.z );
    return result;
}

Vector4f RandomRange(const Vector4f& min, const Vector4f& max)
{
    Vector4f result;
    result.x = RandomRange( min.x, max.x );
    result.y = RandomRange( min.y, max.y );
    result.z = RandomRange( min.z, max.z );
    result.w = RandomRange( min.w, max.w );
    return result;
}





}

