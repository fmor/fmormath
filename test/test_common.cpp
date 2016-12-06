#include "../src/common.h"
#include "../src/constants.h"

#include <gtest/gtest.h>

using namespace fmormath;

TEST( common, DegreeToRadian )
{
    EXPECT_EQ( Constants::PI,   DegreeToRadian(180));
    EXPECT_EQ( Constants::PI_HALF, DegreeToRadian(90) );
    EXPECT_EQ( Constants::PI_QUARTER, DegreeToRadian(45) );
    EXPECT_EQ( Constants::PI_DOUBLE,    DegreeToRadian(360) );
}
TEST( common, RadianToDegreee )
{
    EXPECT_EQ( 180,   RadianToDegreee(Constants::PI) );
    EXPECT_EQ(  90,   RadianToDegreee(Constants::PI_HALF) );
    EXPECT_EQ(  45,   RadianToDegreee(Constants::PI_QUARTER) );
    EXPECT_EQ(  360,   RadianToDegreee(Constants::PI_DOUBLE) );
}

TEST( common, NextPowerOf2 )
{
    EXPECT_EQ( 2,   NextPowerOf2(0)   );
    EXPECT_EQ( 2,   NextPowerOf2(1)   );
    EXPECT_EQ( 4,   NextPowerOf2(4)   );
    EXPECT_EQ( 512, NextPowerOf2(480) );
}

TEST( common, IsPowerOf2 )
{
    EXPECT_FALSE(  IsPowerOf2(-2 ) );
    EXPECT_FALSE(  IsPowerOf2( 0 ) );
    EXPECT_TRUE(   IsPowerOf2( 1 ) );
    EXPECT_TRUE(   IsPowerOf2( 2 ) );
    EXPECT_FALSE(  IsPowerOf2( 3 ) );
    EXPECT_FALSE(  IsPowerOf2( 44 ) );
    EXPECT_TRUE(   IsPowerOf2( 512 ) );
}

TEST( common, IsAlmostEqual )
{
    Real a;
    Real b;

    a = -4;
    b =  2;
    EXPECT_FALSE( IsAlmostEqual(a,b) );

    a = -3;
    b = -3;
    EXPECT_TRUE( IsAlmostEqual(a,b) );

    a = -2;
    b = -2.0 - Constants::EPSILON *0.5f;
    EXPECT_TRUE( IsAlmostEqual(a,b) );

    a = 2.0;
    b = 2.0 + Constants::EPSILON * 1.00001;
    EXPECT_TRUE( IsAlmostEqual(a,b) );

    a = 2.0;
    b = 2.0 - Constants::EPSILON * 1.00001;
    EXPECT_TRUE( IsAlmostEqual(a,b) );

    a = -2.0;
    b = -2.0 - Constants::EPSILON * 3.0;
    EXPECT_FALSE( IsAlmostEqual(a,b) );

    a = -2.0;
    b = -2.0 + Constants::EPSILON * 3.0;
    EXPECT_FALSE( IsAlmostEqual(a,b) );
}
