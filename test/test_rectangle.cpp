#include <gtest/gtest.h>

#include "../src/rectangle.h"

using namespace fmormath;


TEST( Rectangle, constructor_float4 )
{
    Rectangle r( 2, 2, 10, 20 );
    EXPECT_FLOAT_EQ( 2,  r.m_X );
    EXPECT_FLOAT_EQ( 2,  r.m_Y );
    EXPECT_FLOAT_EQ( 10, r.m_Width );
    EXPECT_FLOAT_EQ( 20, r.m_Height );
}


TEST( Rectangle, set )
{
    Rectangle r;
    r.set( 0, 0, 10, 20 );

    EXPECT_FLOAT_EQ( 0,  r.m_X );
    EXPECT_FLOAT_EQ( 0,  r.m_Y );
    EXPECT_FLOAT_EQ( 10, r.m_Width );
    EXPECT_FLOAT_EQ( 20, r.m_Height );
}

TEST( Rectangle, area )
{
    Rectangle r;
    r.set( 0, 0, 10, 20 );
    EXPECT_FLOAT_EQ( 200.f,  r.area() );
}

TEST( Rectangle, ratio )
{
    Rectangle r;
    r.set( 0, 0, 9, 3 );
    EXPECT_FLOAT_EQ( 3,  r.ratio()  );
}

TEST( Rectangle, isPointInside )
{
    Rectangle r;
    r.set( 1, 9, 16, 8 );
    // inside
    EXPECT_TRUE( r.isInside(5, 5) );

    // outside
    EXPECT_FALSE( r.isInside(-1,-1) );

    // border
    EXPECT_TRUE( r.isInside(1,1) );
}

TEST( Rectangle, operator_equal )
{
    Rectangle r1;
    Rectangle r2;

    r1.set( 10, 10, 100, 200 );
    r2.set( 10, 10, 100, 200 );
    EXPECT_TRUE( r1 == r2 );

    r1.set( 10, 10, 200, 200 );
    r2.set( 10, 10, 100, 200 );
    EXPECT_FALSE( r1 == r2 );

}
TEST( Rectangle, operator_not_equal )
{
    Rectangle r1;
    Rectangle r2;

    r1.set( 10, 10, 200, 200 );
    r2.set( 10, 10, 100, 200 );
    EXPECT_TRUE( r1 != r2 );

    r1.set( 10, 10, 100, 200 );
    r2.set( 10, 10, 100, 200 );
    EXPECT_FALSE( r1 != r2 );
}

TEST( Rectangle, operator_assign )
{
    Rectangle r1;
    Rectangle r2;

    r1.set( 1, 2, 3, 4 );
    r2.set( 4, 5, 6, 7 );

    r2 = r1;
    EXPECT_EQ( r1, r2 );

    r1.set( 8, 9, 10, 11 );
    r2.set( 12, 13, 14, 15 );
    r2 = r1;
    EXPECT_EQ( r1, r2 );
}



//TEST( Rectangle, intersect )
//{
//    Rectangle r( 0, 9, 16, 9 );

//    Rectangle inside( 1, 2, 1, 1 );
//    Rectangle cross( 15, 2, 7, 1 );
//    Rectangle outside( 100,100, 1, 1);
//    Rectangle border( 16, 9, 1, 1 );

//    // inside
//    EXPECT_TRUE( r.interset( inside ) );
//    // cross
//    EXPECT_TRUE( r.interset( cross ) );
//    // outside
//    EXPECT_FALSE( r.interset(outside));
//    // border
//    EXPECT_TRUE( r.interset(border) );
//}
