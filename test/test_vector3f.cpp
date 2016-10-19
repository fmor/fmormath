#include <gtest/gtest.h>

//#include <Eigen/Eigen>

#include "../src/common.h"
#include "../src/vector3f.h"
#include "../src/constants.h"
#include "../src/common.h"




using namespace fmormath;

//////////////////////////////////////////////////////////////
/// static
TEST( Vector3f, static_zero )
{
    EXPECT_EQ( 0, Vector3f::ZERO.x );
    EXPECT_EQ( 0, Vector3f::ZERO.y );
    EXPECT_EQ( 0, Vector3f::ZERO.z );
}
TEST( Vector3f, static_unit_x )
{
    EXPECT_EQ( 1, Vector3f::UNIT_X.x );
    EXPECT_EQ( 0, Vector3f::UNIT_X.y );
    EXPECT_EQ( 0, Vector3f::UNIT_X.z );
}
TEST( Vector3f, static_unit_y )
{
    EXPECT_EQ( 0, Vector3f::UNIT_Y.x );
    EXPECT_EQ( 1, Vector3f::UNIT_Y.y );
    EXPECT_EQ( 0, Vector3f::UNIT_Y.z );
}
TEST( Vector3f, static_unit_z )
{
    EXPECT_EQ( 0, Vector3f::UNIT_Z.x );
    EXPECT_EQ( 0, Vector3f::UNIT_Z.y );
    EXPECT_EQ( 1, Vector3f::UNIT_Z.z );
}
TEST( Vector3f, static_negative_unit_x )
{
    EXPECT_EQ( -1, Vector3f::NEGATIVE_UNIT_X.x );
    EXPECT_EQ(  0, Vector3f::NEGATIVE_UNIT_X.y );
    EXPECT_EQ(  0, Vector3f::NEGATIVE_UNIT_X.z );
}
TEST( Vector3f, static_negative_unit_y )
{
    EXPECT_EQ(  0, Vector3f::NEGATIVE_UNIT_Y.x );
    EXPECT_EQ( -1, Vector3f::NEGATIVE_UNIT_Y.y );
    EXPECT_EQ(  0, Vector3f::NEGATIVE_UNIT_Y.z );
}
TEST( Vector3f, static_negative_unit_z )
{
    EXPECT_EQ(  0, Vector3f::NEGATIVE_UNIT_Z.x );
    EXPECT_EQ(  0, Vector3f::NEGATIVE_UNIT_Z.y );
    EXPECT_EQ( -1, Vector3f::NEGATIVE_UNIT_Z.z );
}
TEST( Vector3f, static_unit_scale )
{
    EXPECT_EQ( 1, Vector3f::UNIT_SCALE.x );
    EXPECT_EQ( 1, Vector3f::UNIT_SCALE.y );
    EXPECT_EQ( 1, Vector3f::UNIT_SCALE.z );
}





//////////////////////////////////////////////////////////////
/// constructor
TEST( Vector3f, constructor_float3 )
{
    Vector3f  v3( 1, 3, 5);
    EXPECT_EQ( 1,  v3.x );
    EXPECT_EQ( 3,  v3.y );
    EXPECT_EQ( 5,  v3.z );
}
TEST( Vector3f, constructor_vector3 )
{
    Vector3f other( 1, 3, 5 );
    Vector3f v3( other );

    EXPECT_EQ( other.x ,  v3.x );
    EXPECT_EQ( other.y,  v3.y );
    EXPECT_EQ( other.z,  v3.z );
}

//////////////////////////////////////////////////////////////
/// operator
TEST( Vector3f, void_operator_equal_vector3f )
{
    Vector3f first(  5,4, 10 );
    Vector3f second(-5,-4, 10 );
    EXPECT_TRUE( first == first  );
    EXPECT_FALSE(first == second  );
}
TEST( Vector3f, void_operator_notequal_vector3f )
{
    Vector3f first(  5,4, 10 );
    Vector3f second(-5,-4, 10 );
    EXPECT_TRUE(first != second  );
    EXPECT_FALSE( first != first  );
}

TEST( Vector3f, void_operator_mult_float )
{
    Vector3f first(  36, 24, 11 );
    first *= 8;
    EXPECT_EQ( 288, first.x );
    EXPECT_EQ( 192, first.y );
    EXPECT_EQ(  88, first.z );
}
TEST( Vector3f, void_operator_divide_float )
{
    Vector3f first(  24, 44, 50);
    first /= 8;
    EXPECT_EQ(    3, first.x );
    EXPECT_EQ(  5.5, first.y );
    EXPECT_EQ( 6.25, first.z );
}
TEST( Vector3f, void_operator_add_vector3f )
{
    Vector3f first(  5, 4, 10);
    Vector3f second(-5,-4, 10);
    first += second;
    EXPECT_EQ(  0, first.x );
    EXPECT_EQ(  0, first.y );
    EXPECT_EQ( 20, first.z );
}
TEST( Vector3f, void_operator_sub_vector3f )
{
    Vector3f first(  5, 4, 10);
    Vector3f second(-5,-4, 10);

    first -= second;

    EXPECT_EQ( 10, first.x );
    EXPECT_EQ(  8, first.y );
    EXPECT_EQ(  0, first.z );
}
TEST( Vector3f, operator_minus )
{
    Vector3f v3( 1,2,3);
    v3 = -v3;
    EXPECT_FLOAT_EQ( -1, v3.x );
    EXPECT_FLOAT_EQ( -2, v3.y );
    EXPECT_FLOAT_EQ( -3, v3.z );
}


//////////////////////////////////////////////////////////////
/// functions
TEST( Vector3f, set )
{
    Vector3f  v3( 0,0,0);
    v3.set( 2, 3, 5 );
    EXPECT_EQ( 2,  v3.x );
    EXPECT_EQ( 3,  v3.y );
    EXPECT_EQ( 5,  v3.z );
}

TEST( Vector3f, dot )
{
    Vector3f first;
    Vector3f second;

    // not particular vectors
    first.set(  2, 2, 4 );
    second.set( 5, 8, 1 );
    EXPECT_EQ( 30, first.dot( second) );

    // colinear
    first.set(  1, 0, 0 );
    second.set( 1, 0, 0 );
    EXPECT_EQ( 1, first.dot( second)  );

    // perpendicular
    first.set(  1, 0, 0 );
    second.set( 0, 0, 0 );
    EXPECT_EQ( 0, first.dot( second) );
}



TEST( Vector3f, length )
{
    Vector3f  v3;

    v3.set( 5, 4, 2 );
    EXPECT_EQ( std::sqrt(45.f),  v3.length() );

    v3.set(5,-4, 2 );
    EXPECT_EQ( std::sqrt(45.f),  v3.length() );
}
TEST( Vector3f, lengthSquared )
{
    Vector3f  v3;
    v3.set( 5, 4, 2 );
    EXPECT_EQ( 45.f,  v3.lengthSquared() );

    v3.set(5,-4, 2 );
    EXPECT_EQ( 45.f,  v3.lengthSquared() );
}

TEST( Vector3f, scale )
{
    Vector3f  v3( 6, 2, 14 );
     v3.scale( Vector3f(3,2,1) );

     EXPECT_EQ( 18, v3.x);
     EXPECT_EQ(  4, v3.y );
     EXPECT_EQ( 14, v3.z);
}

TEST( Vector3f, normalize )
{
    Vector3f  v3( 3,6, 22 );

    Vector3f correct;
    float invl = 1.0f / std::sqrt( v3.x*v3.x + v3.y*v3.y + v3.z*v3.z );
    correct.x = v3.x * invl;
    correct.y = v3.y * invl;
    correct.z = v3.z * invl;

    v3.normalize();

    EXPECT_EQ( correct.x,  v3.x );
    EXPECT_EQ( correct.y,  v3.y );
    EXPECT_EQ( correct.z,  v3.z );
}


TEST( Vector3f, cross )
{
    Vector3f v3( 1,2,3);
    Vector3f other(8,0,2);
    Vector3f crossed = v3.cross(other);

    EXPECT_EQ(  4, crossed.x );
    EXPECT_EQ( 22, crossed.y );
    EXPECT_EQ(-16, crossed.z );

    EXPECT_EQ( Vector3f::UNIT_Y, Vector3f::UNIT_Z.cross( Vector3f::UNIT_X ) );
    EXPECT_EQ( Vector3f::UNIT_Z, Vector3f::UNIT_X.cross( Vector3f::UNIT_Y ) );
    EXPECT_EQ( Vector3f::UNIT_X, Vector3f::UNIT_Y.cross( Vector3f::UNIT_Z ) );

}

TEST( Vector3f, angle )
{
    Vector3f v1;
    Vector3f v2;
    float degree;


    v1.set( 0,0,1);
    v2.set( 0,1,0);
    degree = RadianToDegreee(v1.angle(v2) );
    EXPECT_NEAR( 90.f, degree , Constants::EPSILON );

    v1.set( 10,10,0);
    v2.set( -10,10,0);
    degree = RadianToDegreee(v1.angle(v2));
    EXPECT_NEAR( 90.f, degree , Constants::EPSILON );

    v1.set( 3,3,3);
    v2.set( -3,-3,-3);
    degree = RadianToDegreee(v1.angle(v2));
    EXPECT_NEAR( 180.f, degree , Constants::EPSILON );
}


TEST( Vector3f, rotate )
{
    Vector3f v3;




    float rad = DegreeToRadian(45.f);



    Vector3f axis = Vector3f(1,6,3);
    axis.normalize();


    v3.set( 10, 10, 10 );
    v3.rotate( rad, axis );

    EXPECT_NEAR( 10.835508, v3.x, Constants::EPSILON );
    EXPECT_NEAR( 12.976558, v3.y, Constants::EPSILON );
    EXPECT_NEAR(  3.768381, v3.z, Constants::EPSILON );



    v3 = Vector3f( 1,1,1 );
    v3.rotate( DegreeToRadian(180), Vector3f(-1,0,1) );
    EXPECT_NEAR( -1, v3.x, Constants::EPSILON );
    EXPECT_NEAR( -1, v3.y, Constants::EPSILON );
    EXPECT_NEAR( -1, v3.z, Constants::EPSILON );


    // Oposite
    v3 = Vector3f( 1,1,1 );
    v3.rotate( DegreeToRadian(90), Vector3f(-1,-1,-1) );
    EXPECT_NEAR( 1, v3.x, Constants::EPSILON );
    EXPECT_NEAR( 1, v3.y, Constants::EPSILON );
    EXPECT_NEAR( 1, v3.z, Constants::EPSILON );



    v3 =  Vector3f( 1,1,1 );
    v3.rotate( DegreeToRadian(180), Vector3f::UNIT_Y );
    EXPECT_NEAR( -1, v3.x, Constants::EPSILON );
    EXPECT_NEAR(  1, v3.y, Constants::EPSILON );
    EXPECT_NEAR( -1, v3.z, Constants::EPSILON );



    // Axis Z
    v3 =  Vector3f::UNIT_Z;
    v3.rotate( DegreeToRadian(90), Vector3f::UNIT_Y );
    EXPECT_NEAR( 1, v3.x, Constants::EPSILON );
    EXPECT_NEAR( 0, v3.y, Constants::EPSILON );
    EXPECT_NEAR( 0, v3.z, Constants::EPSILON );

    // Axis X
    v3 =  Vector3f::UNIT_X;
    v3.rotate( DegreeToRadian(90), Vector3f::UNIT_Z );
    EXPECT_NEAR( 0, v3.x, Constants::EPSILON );
    EXPECT_NEAR( 1, v3.y, Constants::EPSILON );
    EXPECT_NEAR( 0, v3.z, Constants::EPSILON );

    // Axis Y
    v3 =  Vector3f::UNIT_Y;
    v3.rotate( DegreeToRadian(90), Vector3f::UNIT_X );
    EXPECT_NEAR( 0, v3.x, Constants::EPSILON );
    EXPECT_NEAR( 0, v3.y, Constants::EPSILON );
    EXPECT_NEAR( 1, v3.z, Constants::EPSILON );
}
