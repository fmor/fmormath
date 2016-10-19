#include <gtest/gtest.h>

#include "../src/random.h"

using namespace fmormath;



TEST( random, random_range_int )
{
    int v = RandomRange( -100, 0 );
    EXPECT_FALSE( v < -100 );
    EXPECT_FALSE( v > 0 );
}
TEST( random, random_range_float )
{
    float v = RandomRange( -100.f, 0.f );
    EXPECT_FALSE( v < -100.f );
    EXPECT_FALSE( v > 0.f );
}

TEST( random, random_range_Vector2 )
{
    Vector2f min( -10, -10 );
    Vector2f max(  10,  10 );

    Vector2f p = RandomRange( min, max );
    EXPECT_FALSE( p.x < -10.f );
    EXPECT_FALSE( p.x >  10.f );

    EXPECT_FALSE( p.y < -10.f );
    EXPECT_FALSE( p.y >  10.f );
}
TEST( random, random_range_Vector3 )
{
    Vector3f min( -10, -10, -10 );
    Vector3f max(  10,  10,  10 );

    Vector3f p = RandomRange( min, max );
    EXPECT_FALSE( p.x < -10.f );
    EXPECT_FALSE( p.x >  10.f );

    EXPECT_FALSE( p.y < -10.f );
    EXPECT_FALSE( p.y >  10.f );

    EXPECT_FALSE( p.z < -10.f );
    EXPECT_FALSE( p.z >  10.f );
}
TEST( random, random_range_Vector4 )
{
    Vector4f min( -10, -10, -10, -10 );
    Vector4f max(  10,  10,  10,  10 );

    Vector4f p = RandomRange( min, max );
    EXPECT_FALSE( p.x < -10.f );
    EXPECT_FALSE( p.x >  10.f );

    EXPECT_FALSE( p.y < -10.f );
    EXPECT_FALSE( p.y >  10.f );

    EXPECT_FALSE( p.z < -10.f );
    EXPECT_FALSE( p.z >  10.f );

    EXPECT_FALSE( p.w < -10.f );
    EXPECT_FALSE( p.w >  10.f );
}
