#include <gtest/gtest.h>

#include "../src/vector4f.h"


using namespace fmormath;

//////////////////////////////////////////////////////////////
/// static
TEST( Vector4f, static_zero )
{
    EXPECT_EQ( 0, Vector4f::ZERO.x );
    EXPECT_EQ( 0, Vector4f::ZERO.y );
    EXPECT_EQ( 0, Vector4f::ZERO.z );
    EXPECT_EQ( 0, Vector4f::ZERO.w );
}
TEST( Vector4f, static_unit_x )
{
    EXPECT_EQ( 1, Vector4f::UNIT_X.x );
    EXPECT_EQ( 0, Vector4f::UNIT_X.y );
    EXPECT_EQ( 0, Vector4f::UNIT_X.z );
    EXPECT_EQ( 0, Vector4f::UNIT_X.w );
}
TEST( Vector4f, static_unit_y )
{
    EXPECT_EQ( 0, Vector4f::UNIT_Y.x );
    EXPECT_EQ( 1, Vector4f::UNIT_Y.y );
    EXPECT_EQ( 0, Vector4f::UNIT_Y.z );
    EXPECT_EQ( 0, Vector4f::UNIT_Y.w );
}
TEST( Vector4f, static_unit_z )
{
    EXPECT_EQ( 0, Vector4f::UNIT_Z.x );
    EXPECT_EQ( 0, Vector4f::UNIT_Z.y );
    EXPECT_EQ( 1, Vector4f::UNIT_Z.z );
    EXPECT_EQ( 0, Vector4f::UNIT_Z.w );
}
TEST( Vector4f, static_unit_w )
{
    EXPECT_EQ( 0, Vector4f::UNIT_W.x );
    EXPECT_EQ( 0, Vector4f::UNIT_W.y );
    EXPECT_EQ( 0, Vector4f::UNIT_W.z );
    EXPECT_EQ( 1, Vector4f::UNIT_W.w );
}
TEST( Vector4f, static_negative_unit_x )
{
    EXPECT_EQ( -1, Vector4f::NEGATIVE_UNIT_X.x );
    EXPECT_EQ(  0, Vector4f::NEGATIVE_UNIT_X.y );
    EXPECT_EQ(  0, Vector4f::NEGATIVE_UNIT_X.z );
    EXPECT_EQ(  0, Vector4f::NEGATIVE_UNIT_X.w );
}
TEST( Vector4f, static_negative_unit_y )
{
    EXPECT_EQ(  0, Vector4f::NEGATIVE_UNIT_Y.x );
    EXPECT_EQ( -1, Vector4f::NEGATIVE_UNIT_Y.y );
    EXPECT_EQ(  0, Vector4f::NEGATIVE_UNIT_Y.z );
    EXPECT_EQ(  0, Vector4f::NEGATIVE_UNIT_Y.w );
}
TEST( Vector4f, static_negative_unit_z )
{
    EXPECT_EQ(  0, Vector4f::NEGATIVE_UNIT_Z.x );
    EXPECT_EQ(  0, Vector4f::NEGATIVE_UNIT_Z.y );
    EXPECT_EQ( -1, Vector4f::NEGATIVE_UNIT_Z.z );
    EXPECT_EQ(  0, Vector4f::NEGATIVE_UNIT_Z.w );
}
TEST( Vector4f, static_negative_unit_w )
{
    EXPECT_EQ(  0, Vector4f::NEGATIVE_UNIT_W.x );
    EXPECT_EQ(  0, Vector4f::NEGATIVE_UNIT_W.y );
    EXPECT_EQ(  0, Vector4f::NEGATIVE_UNIT_W.z );
    EXPECT_EQ( -1, Vector4f::NEGATIVE_UNIT_W.w );
}
TEST( Vector4f, static_unit_scale )
{
    EXPECT_EQ( 1, Vector4f::UNIT_SCALE.x );
    EXPECT_EQ( 1, Vector4f::UNIT_SCALE.y );
    EXPECT_EQ( 1, Vector4f::UNIT_SCALE.z );
    EXPECT_EQ( 1, Vector4f::UNIT_SCALE.w );
}





//////////////////////////////////////////////////////////////
/// constructor
TEST( Vector4f, constructor_float4 )
{
    Vector4f  v4( 1,3,5,7);
    EXPECT_EQ( 1,  v4.x );
    EXPECT_EQ( 3,  v4.y );
    EXPECT_EQ( 5,  v4.z );
    EXPECT_EQ( 7,  v4.w );
}
TEST( Vector4f, constructor_vector4 )
{
    Vector4f other( 1,3,5,7);
    Vector4f v4( other );

    EXPECT_EQ( other.x ,  v4.x );
    EXPECT_EQ( other.y,  v4.y );
    EXPECT_EQ( other.z,  v4.z );
    EXPECT_EQ( other.w,  v4.w );
}

//////////////////////////////////////////////////////////////
/// operator
TEST( Vector4f, void_operator_equal_vector4f )
{
    Vector4f first(  5,4, 10, 11 );
    Vector4f second(-5,-4, 10, 11 );
    EXPECT_TRUE( first == first  );
    EXPECT_FALSE(first == second  );
}
TEST( Vector4f, void_operator_notequal_vector4f )
{
    Vector4f first(  5,4, 10, 11 );
    Vector4f second(-5,-4, 10, 11 );
    EXPECT_TRUE(first != second  );
    EXPECT_FALSE( first != first  );
}

TEST( Vector4f, void_operator_mult_float )
{
    Vector4f first(  36, 24, 11, 13);
    first *= 8;
    EXPECT_EQ( 288, first.x );
    EXPECT_EQ( 192, first.y );
    EXPECT_EQ(  88, first.z );
    EXPECT_EQ( 104, first.w );
}
TEST( Vector4f, void_operator_divide_float )
{
    Vector4f first(  24, 44, 50, 8 );
    first /= 8;
    EXPECT_EQ(    3, first.x );
    EXPECT_EQ(  5.5, first.y );
    EXPECT_EQ( 6.25, first.z );
    EXPECT_EQ(    1, first.w );
}
TEST( Vector4f, void_operator_add_vector4f )
{
    Vector4f first(  5,4, 10, 11 );
    Vector4f second(-5,-4, 10, 11 );
    first += second;
    EXPECT_EQ(  0, first.x );
    EXPECT_EQ(  0, first.y );
    EXPECT_EQ( 20, first.z );
    EXPECT_EQ( 22, first.w );
}
TEST( Vector4f, void_operator_sub_vector4f )
{
    Vector4f first(  5,4, 10, 11 );
    Vector4f second(-5,-4, 10, 11 );

    first -= second;

    EXPECT_EQ( 10, first.x );
    EXPECT_EQ(  8, first.y );
    EXPECT_EQ(  0, first.z );
    EXPECT_EQ(  0, first.w );
}
TEST( Vector4f, operator_minus )
{
    Vector4f v4( 1, 2, 3, 4);
    v4 = -v4;
    EXPECT_FLOAT_EQ( -1, v4.x );
    EXPECT_FLOAT_EQ( -2, v4.y );
    EXPECT_FLOAT_EQ( -3, v4.z );
    EXPECT_FLOAT_EQ( -4, v4.w );
}


//////////////////////////////////////////////////////////////
/// functions
TEST( Vector4f, set )
{
    Vector4f  v4( 0,0,0,0);
    v4.set( 2, 3, 5, 7 );
    EXPECT_EQ( 2,  v4.x );
    EXPECT_EQ( 3,  v4.y );
    EXPECT_EQ( 5,  v4.z );
    EXPECT_EQ( 7,  v4.w );
}

TEST( Vector4f, dot )
{
    Vector4f first;
    Vector4f second;

    // not particular vectors
    first.set(  2, 2, 4, 5 );
    second.set( 5, 8, 1, 5 );
    EXPECT_EQ( 55, first.dot( second) );

    // colinear
    first.set(  1, 0, 0, 0 );
    second.set( 1, 0, 0, 0 );
    EXPECT_EQ( 1, first.dot( second)  );

    // perpendicular
    first.set(  1, 0, 0, 0 );
    second.set( 0, 0, 0, 1 );
    EXPECT_EQ( 0, first.dot( second) );
}



TEST( Vector4f, length )
{
    Vector4f  v4;

    v4.set( 5, 4, 2, 4);
    EXPECT_EQ( std::sqrt( Real(61) ),  v4.length() );

    v4.set(5,-4, 2,-4);
    EXPECT_EQ( std::sqrt( Real(61) ),  v4.length() );
}
TEST( Vector4f, lengthSquared )
{
    Vector4f  v4;
    v4.set( 5, 4, 2, 4);
    EXPECT_EQ(  Real(61) ,  v4.lengthSquared() );

    v4.set(5,-4, 2,-4);
    EXPECT_EQ(  Real(61) ,  v4.lengthSquared() );
}

TEST( Vector4f, scale )
{
    Vector4f  v4( 6,2,14,7);
     v4.scale( Vector4f(3,2,1,10) );

     EXPECT_EQ( 18, v4.x);
     EXPECT_EQ(  4, v4.y );
     EXPECT_EQ( 14, v4.z);
     EXPECT_EQ( 70, v4.w );
}

TEST( Vector4f, normalize )
{
    Vector4f  v4( 3,6, 22, 4 );

    Vector4f correct;
    Real invl = Real(1.0) / std::sqrt( v4.x*v4.x + v4.y*v4.y + v4.z*v4.z + v4.w*v4.w );
    correct.x = v4.x * invl;
    correct.y = v4.y * invl;
    correct.z = v4.z * invl;
    correct.w = v4.w * invl;

    v4.normalize();

    EXPECT_EQ( correct.x,  v4.x );
    EXPECT_EQ( correct.y,  v4.y );
    EXPECT_EQ( correct.z,  v4.z );
    EXPECT_EQ( correct.w,  v4.w );
}


