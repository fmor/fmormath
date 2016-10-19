#include <gtest/gtest.h>

#include "../src/aabb.h"

using namespace fmormath;


TEST( AxisAlignedBoundingBox, set_Vector3f )
{
    AxisAlignedBoundingBox bbox;
    bbox.set( Vector3f::ZERO, Vector3f::UNIT_SCALE );

    EXPECT_EQ( Vector3f::ZERO,  bbox.getMin() );
    EXPECT_EQ( Vector3f::UNIT_SCALE,  bbox.getMax() );
}

TEST( AxisAlignedBoundingBox, isInside )
{
    AxisAlignedBoundingBox bbox;
    bbox.set( Vector3f::ZERO, Vector3f(10,10,10) );

    Vector3f inside( 5,5,5 );
    Vector3f outside( -5,5,5 );
    Vector3f border( 10,10,10 );

    EXPECT_TRUE(  bbox.isInside(inside) );
    EXPECT_FALSE( bbox.isInside(outside));
    EXPECT_TRUE(  bbox.isInside(border) );
}
