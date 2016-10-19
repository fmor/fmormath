#include <gtest/gtest.h>

#include "../src/quaternion.h"
#include "../src/constants.h"

using namespace fmormath;


TEST( Quaternion, identity )
{
    EXPECT_EQ( 0, Quaternion::IDENTITY.x );
    EXPECT_EQ( 0, Quaternion::IDENTITY.y );
    EXPECT_EQ( 0, Quaternion::IDENTITY.z );
    EXPECT_EQ( 1, Quaternion::IDENTITY.w );
}


TEST( Quaternion, constructor_float )
{
    Quaternion quat( 1, 2, 3, 4 );
    EXPECT_EQ( 1, quat.w );
    EXPECT_EQ( 2, quat.x );
    EXPECT_EQ( 3, quat.y );
    EXPECT_EQ( 4, quat.z );
}

TEST( Quaternion, constructor_quaternion )
{
    Quaternion other( 4, 3, 2, 1 );
    Quaternion quat( other );

    EXPECT_EQ( other.x, quat.x );
    EXPECT_EQ( other.y, quat.y );
    EXPECT_EQ( other.z, quat.z );
    EXPECT_EQ( other.w, quat.w );
}

TEST( Quaternion, set_float )
{
    Quaternion quat;
    quat.set( 1, 3, 5, 7 );


    EXPECT_EQ( 1, quat.w );
    EXPECT_EQ( 3, quat.x );
    EXPECT_EQ( 5, quat.y );
    EXPECT_EQ( 7, quat.z );
}

TEST( Quaternion, quaterion_operator_plus )
{
    Quaternion quat1;
    Quaternion quat2;
    Quaternion result;

    quat1.set( 1,   3,  5,  7 );
    quat2.set( 11, 13, 17, 19 );

    result = quat1 + quat2;

    EXPECT_EQ( 12, result.w );
    EXPECT_EQ( 16, result.x );
    EXPECT_EQ( 22, result.y );
    EXPECT_EQ( 26, result.z );

    result = quat2 + quat1;

    EXPECT_EQ( 12, result.w );
    EXPECT_EQ( 16, result.x );
    EXPECT_EQ( 22, result.y );
    EXPECT_EQ( 26, result.z );

}
TEST( Quaternion, quaterion_operator_minus )
{
    Quaternion quat1;
    Quaternion quat2;
    Quaternion result;

    quat1.set( 1,   3,  5,  7 );
    quat2.set( 11, 13, 17, 19 );

    result = quat1 - quat2;


    EXPECT_EQ( -10, result.w );
    EXPECT_EQ( -10, result.x );
    EXPECT_EQ( -12, result.y );
    EXPECT_EQ( -12, result.z );


    quat1.set( 1,  7,   3,  5 );
    quat2.set( 11, 19, 13, 17 );
    result = quat1 - quat2;

    EXPECT_EQ( -10, result.w );
    EXPECT_EQ( -12, result.x );
    EXPECT_EQ( -10, result.y );
    EXPECT_EQ( -12, result.z );

}

TEST( Quaternion, void_operator_plus_equal )
{
    Quaternion quaternion;
    Quaternion other;

    quaternion.set( 1,   3,  5,  7 );
    other.set( 19, 13, 17, 19 );

    quaternion += other;

    EXPECT_EQ( 20, quaternion.w );
    EXPECT_EQ( 16, quaternion.x );
    EXPECT_EQ( 22, quaternion.y );
    EXPECT_EQ( 26, quaternion.z );


}
TEST( Quaternion, void_operator_minus_equal )
{
    Quaternion q1;
    Quaternion q2;

    q1.set( 1, 3,  23,  7 );
    q2.set( 7, 6, 17, 19 );

    q1 -= q2;


    EXPECT_EQ(  -6, q1.w );
    EXPECT_EQ(  -3, q1.x );
    EXPECT_EQ(   6, q1.y );
    EXPECT_EQ( -12, q1.z );
}

TEST( Quaternion, operator_mult )
{
    Quaternion q1( 2,  3,  5,  7 );
    Quaternion q2( 11, 13, 17, 19 );

    Quaternion result = q1 * q2;

    EXPECT_EQ( -235, result.w );
    EXPECT_EQ(   35, result.x );
    EXPECT_EQ(  123, result.y );
    EXPECT_EQ(  101, result.z );


}
TEST( Quaternion, operator_mult_assign )
{
    Quaternion q1( 2,  3,  5,  7 );
    Quaternion q2( 11, 13, 17, 19 );

    q1 *= q2;

    EXPECT_EQ( -235, q1.w );
    EXPECT_EQ(   35, q1.x );
    EXPECT_EQ(  123, q1.y );
    EXPECT_EQ(  101, q1.z );


    q1.set( 2,  3,  5,  7 );
    q1 *= Quaternion::IDENTITY;
    EXPECT_EQ( 2, q1.w );
    EXPECT_EQ( 3, q1.x );
    EXPECT_EQ( 5, q1.y );
    EXPECT_EQ( 7, q1.z );
}

TEST( Quaternion, conjugate )
{
    Quaternion q1( 2,  3,  5,  7 );
    Quaternion conjugate = q1.conjugate();

    EXPECT_EQ( 2, conjugate.w );
    EXPECT_EQ(-3, conjugate.x );
    EXPECT_EQ(-5, conjugate.y );
    EXPECT_EQ(-7, conjugate.z );
}

TEST( Quaternion, inverse )
{
    Quaternion q( 2,  3,  5,  7 );
    Quaternion inverse = q.inverse();

    EXPECT_EQ(  2.f/87.f, inverse.w );
    EXPECT_EQ( -3.f/87.f, inverse.x );
    EXPECT_EQ( -5.f/87.f, inverse.y );
    EXPECT_EQ( -7.f/87.f, inverse.z );

    Quaternion q1 = q * inverse;
    EXPECT_NEAR( 1 ,  q1.w, Constants::EPSILON );
    EXPECT_NEAR( 0 ,  q1.x, Constants::EPSILON );
    EXPECT_NEAR( 0 ,  q1.y, Constants::EPSILON );
    EXPECT_NEAR( 0 ,  q1.z, Constants::EPSILON );

}
