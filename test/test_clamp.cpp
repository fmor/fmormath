#include <gtest/gtest.h>

#include "../src/clamp.h"

using namespace fmormath;



TEST( clamp, uint )
{
    EXPECT_EQ( 0,  Clamp( (uint) 0,  (uint) 0,  (uint)  32) );
    EXPECT_EQ( 1,  Clamp( (uint) 1,  (uint) 0,  (uint)  32) );
    EXPECT_EQ( 32, Clamp( (uint) 32, (uint) 0,  (uint)  32) );
    EXPECT_EQ( 32, Clamp( (uint) 35, (uint) 0,  (uint)  32) );
}

TEST( clamp, int )
{
    EXPECT_EQ( 0,  Clamp( (int) 0,  (int) 0,  (int)  32) );
    EXPECT_EQ( 1,  Clamp( (int) 1,  (int) 0,  (int)  32) );
    EXPECT_EQ( 32, Clamp( (int) 32, (int) 0,  (int)  32) );
    EXPECT_EQ( 32, Clamp( (int) 35, (int) 0,  (int)  32) );

    EXPECT_EQ( 0,  Clamp(  0,  (int) -1,  (int)  32) );
    EXPECT_EQ( -1, Clamp( -1,  (int) -1,  (int)  32) );
}


TEST( clamp, Vector2f )
{
    Vector2f min( -10, -10);
    Vector2f max(  10,  10 );

    // min
    EXPECT_EQ( min, Clamp( Vector2f(-11,-11), min, max ) );
    // min x
    EXPECT_EQ( Vector2f(-10,  1),  Clamp( Vector2f(-20, 1), min, max ) );
    // min y
    EXPECT_EQ( Vector2f(  0,-10),  Clamp( Vector2f( 0,-30), min, max ) );

    // max
    EXPECT_EQ( max, Clamp( Vector2f( 11, 11), min, max) );
    // max x
    EXPECT_EQ( Vector2f(  10, 1),  Clamp( Vector2f( 14, 1), min, max ) );
    // max y
    EXPECT_EQ( Vector2f(  0, 10),  Clamp( Vector2f( 0, 30), min, max ) );
}
TEST( clamp, Vector3f )
{
    Vector3f min(-10, -10, -10);
    Vector3f max( 10,  10,  10);

    // min
    EXPECT_EQ( min, Clamp( Vector3f(-11,-11,-11), min, max ) );
    // min x
    EXPECT_EQ( Vector3f(-10,  1, 2),   Clamp( Vector3f(-20, 1,2), min, max ) );
    // min y
    EXPECT_EQ( Vector3f(  4,-10, 2),   Clamp( Vector3f( 4,-30, 2), min, max ) );
    // min z
    EXPECT_EQ( Vector3f(  4,  1, -10), Clamp( Vector3f( 4, 1, -11), min, max ) );

    // max
    EXPECT_EQ( max, Clamp( Vector3f( 11, 11,11), min, max) );
    // max x
    EXPECT_EQ( Vector3f(  10, 1, 2),  Clamp( Vector3f( 14, 1, 2), min, max ) );
    // max y
    EXPECT_EQ( Vector3f(  9, 10, 2 ),  Clamp( Vector3f( 9, 30, 2), min, max ) );
    // max z
    EXPECT_EQ( Vector3f(  9, 1, 10 ),  Clamp( Vector3f( 9, 1, 99), min, max ) );
}

TEST( clamp, Vector4f )
{
    Vector4f min(-10, -10, -10, -10);
    Vector4f max( 10,  10,  10,  10);

    // min
    EXPECT_EQ( min, Clamp( Vector4f(-11,-11,-11,-11), min, max ) );
    // min x
    EXPECT_EQ( Vector4f(-10,  1,   2, 3), Clamp( Vector4f(-20, 1,2,3), min, max ) );
    // min y
    EXPECT_EQ( Vector4f(  4,-10,   2, 3), Clamp( Vector4f(  4,-30, 2,3), min, max ) );
    // min z
    EXPECT_EQ( Vector4f(  4,  1, -10, 3), Clamp( Vector4f(  4, 1, -11,3), min, max ) );
    // min w
    EXPECT_EQ( Vector4f(  4,  1, 2, -10), Clamp( Vector4f( 4, 1, 2, -11), min, max ) );

    // max
    EXPECT_EQ( max, Clamp( Vector4f( 11, 11,11, 11), min, max) );
    // max x
    EXPECT_EQ( Vector4f(  10, 1, 2, 3),  Clamp( Vector4f( 14, 1, 2, 3), min, max ) );
    // max y
    EXPECT_EQ( Vector4f(  9, 10, 2, 3 ),  Clamp( Vector4f( 9, 30, 2, 3), min, max ) );
    // max z
    EXPECT_EQ( Vector4f(  9, 1, 10, 3 ),  Clamp( Vector4f( 9, 1, 99, 3), min, max ) );
    // max z
    EXPECT_EQ( Vector4f(  9, 1, 2, 10 ),  Clamp( Vector4f( 9, 1, 2, 99), min, max ) );
}
