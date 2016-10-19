#include <gtest/gtest.h>

#include "../src/interpolation.h"

using namespace fmormath;


TEST( interpolation, lerp_float )
{
    // Min
    EXPECT_EQ(   0, Lerp( -1,  0,  100 ) );
    EXPECT_EQ(   0, Lerp(  0,  0,  100 ) );

    // Max
    EXPECT_EQ( 100, Lerp(  2, 0,  100 ) );
    EXPECT_EQ( 100, Lerp(  1,  0,  100 ) );


    EXPECT_EQ(  25, Lerp( 0.25f,  0,  100 ) );
    EXPECT_EQ(  50, Lerp( 0.50f,  0,  100 ) );
    EXPECT_EQ(  75, Lerp( 0.75f,  0,  100 ) );

}
TEST( interpolation, lerp_vector2 )
{
    Vector2f first(    0,   0 );
    Vector2f second( 100, 100 );

    // Min
    EXPECT_EQ(   first, Lerp( -1,  first,  second ) );
    EXPECT_EQ(   first, Lerp(  0,  first,  second ) );

    // Max
    EXPECT_EQ( second, Lerp(  2, first,  second ) );
    EXPECT_EQ( second, Lerp(  1,  first,  second ) );


    EXPECT_EQ(  Vector2f(25,25), Lerp( 0.25f,  first,  second ) );
    EXPECT_EQ(  Vector2f(50,50), Lerp( 0.50f,  first,  second ) );
    EXPECT_EQ(  Vector2f(75,75), Lerp( 0.75f,  first,  second ) );

}

TEST( interpolation, lerp_vector3 )
{
    Vector3f first(    0,   0, 0 );
    Vector3f second( 100, 100, 100 );

    // Min
    EXPECT_EQ(   first, Lerp( -1,  first,  second ) );
    EXPECT_EQ(   first, Lerp(  0,  first,  second ) );

    // Max
    EXPECT_EQ( second, Lerp(  2, first,  second ) );
    EXPECT_EQ( second, Lerp(  1,  first,  second ) );


    EXPECT_EQ(  Vector3f(25,25,25), Lerp( 0.25f,  first,  second ) );
    EXPECT_EQ(  Vector3f(50,50,50), Lerp( 0.50f,  first,  second ) );
    EXPECT_EQ(  Vector3f(75,75,75), Lerp( 0.75f,  first,  second ) );

}

TEST( interpolation, lerp_vector4 )
{
    Vector4f first(    0,   0, 0, 0 );
    Vector4f second( 100, 100, 100, 100 );

    // Min
    EXPECT_EQ(   first, Lerp( -1,  first,  second ) );
    EXPECT_EQ(   first, Lerp(  0,  first,  second ) );

    // Max
    EXPECT_EQ( second, Lerp(  2, first,  second ) );
    EXPECT_EQ( second, Lerp(  1,  first,  second ) );


    EXPECT_EQ(  Vector4f(25,25,25,25), Lerp( 0.25f,  first,  second ) );
    EXPECT_EQ(  Vector4f(50,50,50,50), Lerp( 0.50f,  first,  second ) );
    EXPECT_EQ(  Vector4f(75,75,75,75), Lerp( 0.75f,  first,  second ) );

}
