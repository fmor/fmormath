#include <gtest/gtest.h>

#include "../src/rectangle.h"

using namespace fmormath;

TEST( Rectangle, constructor )
{
    Rectangle r;
    EXPECT_EQ( 0, r.getTopLeft().x );
    EXPECT_EQ( 0, r.getTopLeft().y );
    EXPECT_EQ( 0, r.getWidth() );
    EXPECT_EQ( 0, r.getHeight() );
}
TEST( Rectangle, constructor_float4 )
{
    Rectangle r( 2, 2, 10, 20 );
    EXPECT_EQ( 2,  r.getTopLeft().x );
    EXPECT_EQ( 2,  r.getTopLeft().y );
    EXPECT_EQ( 10, r.getWidth() );
    EXPECT_EQ( 20, r.getHeight() );
}


TEST( Rectangle, set )
{
    Rectangle r;
    r.set( 0, 0, 10, 20 );

    EXPECT_EQ( 0,  r.getTopLeft().x );
    EXPECT_EQ( 0,  r.getTopLeft().y );
    EXPECT_EQ( 10, r.getWidth() );
    EXPECT_EQ( 20, r.getHeight() );
}

TEST( Rectangle, area )
{
    Rectangle r;
    r.set( 0, 0, 10, 20 );
    EXPECT_EQ( 10.f*20.f,  r.area() );
}

TEST( Rectangle, ratio )
{
    Rectangle r;
    r.set( 0, 0, 16, 9 );
    EXPECT_EQ( 16.f/9.f,  r.ratio()  );
}

TEST( Rectangle, isPointInside )
{
    Rectangle r;
    r.set( 0, 9, 16, 9 );
    // inside
    EXPECT_TRUE( r.isPointInside( 5, 5 ) );
    // outside
    EXPECT_FALSE( r.isPointInside(-1,-1) );
    // border
    EXPECT_TRUE( r.isPointInside(0,0) );
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
