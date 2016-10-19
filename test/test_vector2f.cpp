#include <gtest/gtest.h>

#include "float.h"
#include "../src/vector2f.h"
#include "../src/constants.h"

using namespace fmormath;

//////////////////////////////////////////////////////////////
/// static
TEST( Vector2f, static_zero )
{
    EXPECT_EQ( 0, Vector2f::ZERO.x );
    EXPECT_EQ( 0, Vector2f::ZERO.y );
}
TEST( Vector2f, static_unit_x )
{
    EXPECT_EQ( 1, Vector2f::UNIT_X.x );
    EXPECT_EQ( 0, Vector2f::UNIT_X.y );
}
TEST( Vector2f, static_unit_y )
{
    EXPECT_EQ( 0, Vector2f::UNIT_Y.x );
    EXPECT_EQ( 1, Vector2f::UNIT_Y.y );
}
TEST( Vector2f, static_negative_unit_x )
{
    EXPECT_EQ( -1, Vector2f::NEGATIVE_UNIT_X.x );
    EXPECT_EQ(  0, Vector2f::NEGATIVE_UNIT_X.y );
}
TEST( Vector2f, static_negative_unit_y )
{
    EXPECT_EQ(  0, Vector2f::NEGATIVE_UNIT_Y.x );
    EXPECT_EQ( -1, Vector2f::NEGATIVE_UNIT_Y.y );
}
TEST( Vector2f, static_unit_scale )
{
    EXPECT_EQ( 1, Vector2f::UNIT_SCALE.x );
    EXPECT_EQ( 1, Vector2f::UNIT_SCALE.y );
}





//////////////////////////////////////////////////////////////
/// constructor
TEST( Vector2f, constructor_float2 )
{
    Vector2f  v2( 1,3 );
    EXPECT_EQ( 1,  v2.x );
    EXPECT_EQ( 3,  v2.y );
}
TEST( Vector2f, constructor_vector4 )
{
    Vector2f other( 1,3 );
    Vector2f v2( other );

    EXPECT_EQ( other.x,  v2.x );
    EXPECT_EQ( other.y,  v2.y );
}

//////////////////////////////////////////////////////////////
/// operator
TEST( Vector2f, void_operator_equal_vector2f )
{
    Vector2f first(  5,  4 );
    Vector2f second(-5, -4 );
    EXPECT_TRUE( first == first  );
    EXPECT_FALSE(first == second  );
}
TEST( Vector2f, void_operator_notequal_vector2f )
{
    Vector2f first(  5, 4 );
    Vector2f second(-5,-4 );
    EXPECT_TRUE(first != second  );
    EXPECT_FALSE( first != first  );
}

TEST( Vector2f, void_operator_mult_float )
{
    Vector2f first(  36, 24 );
    first *= 8;
    EXPECT_EQ( 288, first.x );
    EXPECT_EQ( 192, first.y );
}
TEST( Vector2f, void_operator_divide_float )
{
    Vector2f first(  24, 44 );
    first /= 8;
    EXPECT_EQ(    3, first.x );
    EXPECT_EQ(  5.5, first.y );
}
TEST( Vector2f, void_operator_add_vector2f )
{
    Vector2f first(  5, 4);
    Vector2f second(-5,-4);
    first += second;
    EXPECT_EQ(  0, first.x );
    EXPECT_EQ(  0, first.y );
}
TEST( Vector2f, void_operator_sub_vector2f )
{
    Vector2f first(  5, 4);
    Vector2f second(-5,-4);

    first -= second;

    EXPECT_EQ( 10, first.x );
    EXPECT_EQ(  8, first.y );
}
TEST( Vector2f, operator_minus )
{
    Vector2f v2( 1,2 );
    v2 = -v2;
    EXPECT_FLOAT_EQ( -1, v2.x );
    EXPECT_FLOAT_EQ( -2, v2.y );
}

//////////////////////////////////////////////////////////////
/// functions
TEST( Vector2f, set )
{
    Vector2f  v2( 0, 0);
    v2.set( 2, 3 );
    EXPECT_EQ( 2,  v2.x );
    EXPECT_EQ( 3,  v2.y );
}

TEST( Vector2f, dot )
{
    Vector2f first;
    Vector2f second;

    // not particular vectors
    first.set(  2, 2 );
    second.set( 5, 8 );
    EXPECT_EQ( 26, first.dot( second) );

    // colinear
    first.set(  1, 0 );
    second.set( 1, 0 );
    EXPECT_EQ( 1, first.dot( second)  );

    // perpendicular
    first.set(  1, 0 );
    second.set( 0, 1 );
    EXPECT_EQ( 0, first.dot( second) );
}



TEST( Vector2f, length )
{
    Vector2f  v2;

    v2.set( 5, 4 );
    EXPECT_EQ( std::sqrt(41.f),  v2.length() );

    v2.set( 5,-4);
    EXPECT_EQ( std::sqrt(41.f),  v2.length() );
}

TEST( Vector2f, lengthSquared )
{
    Vector2f  v2;
    v2.set( 5, 4 );
    EXPECT_EQ( 41.f,  v2.lengthSquared() );

    v2.set( 5,-4 );
    EXPECT_EQ( 41.f,  v2.lengthSquared() );
}

TEST( Vector2f, scale )
{
    Vector2f  v2( 6,2 );
     v2.scale( Vector2f(3,2) );

     EXPECT_EQ( 18, v2.x);
     EXPECT_EQ(  4, v2.y );
}

TEST( Vector2f, normalize )
{
    Vector2f  v2( 3, 6 );

    Vector2f correct;
    float invl = 1.0f / std::sqrt( v2.x*v2.x + v2.y*v2.y );
    correct.x = v2.x * invl;
    correct.y = v2.y * invl;

    v2.normalize();

    EXPECT_EQ( correct.x,  v2.x );
    EXPECT_EQ( correct.y,  v2.y );
}

// https://en.wikipedia.org/wiki/Machine_epsilon
TEST( Vector2f, rotate )
{
    Vector2f v2;
    v2.set( 1, 0 );
    v2.rotate( 90.0f * Constants::PI / 180.0f );
    if( v2.x < FLT_EPSILON )
        v2.x = 0;
    EXPECT_EQ( 0.0f, v2.x );
    EXPECT_EQ( 1, v2.y );


    v2.set(  0, 1 );
    v2.rotate( 90.0f * Constants::PI / 180.0f );
    if( v2.y < FLT_EPSILON )
        v2.y = 0;
    EXPECT_EQ( -1.0f, v2.x );
    EXPECT_EQ( 0, v2.y );

}

