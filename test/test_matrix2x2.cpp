#include "../src/matrix2x2.h"

#include <limits.h>
#include <gtest/gtest.h>


using namespace fmormath;

TEST( Matrix2x2, identity )
{
    ASSERT_EQ( 1, Matrix2x2::IDENTITY[0][0] );
    ASSERT_EQ( 0, Matrix2x2::IDENTITY[0][1] );
    ASSERT_EQ( 0, Matrix2x2::IDENTITY[1][0] );
    ASSERT_EQ( 1, Matrix2x2::IDENTITY[1][1] );
}

TEST( Matrix2x2, set )
{
    Matrix2x2 matrix;
    matrix.set( 0, 1, 2, 3 );

    EXPECT_EQ( 0, matrix[0][0] );
    EXPECT_EQ( 1, matrix[0][1] );
    EXPECT_EQ( 2, matrix[1][0] );
    EXPECT_EQ( 3, matrix[1][1] );
}
//TEST( Matrix2x2, operator_assign )
//{
//    Matrix2x2 first(  0, 1, 2, 3 );
//    Matrix2x2 third(  3, 1, 1, 0 );

//    first = third;
//    EXPECT_EQ( 3, first[0][0] );
//    EXPECT_EQ( 1, first[0][1] );
//    EXPECT_EQ( 1, first[1][0] );
//    EXPECT_EQ( 0, first[1][1] );

//}


TEST( Matrix2x2, operator_equal )
{
    Matrix2x2 first(  0, 1, 2, 3 );
    Matrix2x2 second( 0, 1, 2, 3 );
    Matrix2x2 third(  3, 1, 1, 0 );

    EXPECT_TRUE( first == second );
    EXPECT_FALSE( first == third );
}

TEST( Matrix2x2, operator_notequal )
{
    Matrix2x2 first(  0, 1, 2, 3 );
    Matrix2x2 second( 0, 1, 2, 3 );
    Matrix2x2 third(  3, 1, 1, 0 );

    EXPECT_TRUE(  first != third );
    EXPECT_FALSE( first != second );
}
TEST( Matrix2x2, operator_mult_equal_float )
{
    Matrix2x2 matrix( 3, 2, 4, 5 );
    matrix *= 3.f;
    EXPECT_FLOAT_EQ( 9.f, matrix[0][0]);
    EXPECT_FLOAT_EQ( 6.f, matrix[0][1] );
    EXPECT_FLOAT_EQ( 12.f, matrix[1][0] );
    EXPECT_FLOAT_EQ( 15.f, matrix[1][1] );
}
TEST( Matrix2x2, operator_add_equal_matrix2x2 )
{
    Matrix2x2 first(  0, 1, 2, 3 );
    Matrix2x2 second( 5, 7, 11, 13 );
    first += second;
    EXPECT_FLOAT_EQ( 5.f,  first[0][0]);
    EXPECT_FLOAT_EQ( 8.f,  first[0][1] );
    EXPECT_FLOAT_EQ( 13.f, first[1][0] );
    EXPECT_FLOAT_EQ( 16.f,  first[1][1] );
}
TEST( Matrix2x2, operator_sub_equal_matrix2x2 )
{
    Matrix2x2 first(  0, 1, 2, 3 );
    Matrix2x2 second( 5, 7, 11, 13 );
    first -= second;
    EXPECT_FLOAT_EQ( -5.f,  first[0][0]);
    EXPECT_FLOAT_EQ( -6.f,  first[0][1] );
    EXPECT_FLOAT_EQ( -9.f, first[1][0] );
    EXPECT_FLOAT_EQ( -10.f,  first[1][1] );
}
TEST( Matrix2x2, operator_mult_equal_matrix2x2 )
{
    Matrix2x2 matrix ( 1, 2, 4, 3 );
    Matrix2x2 other( 5, 1, 2, 3 );
    matrix *= other;

    EXPECT_EQ( 9,  matrix[0][0] );
    EXPECT_EQ( 7,  matrix[0][1] );
    EXPECT_EQ( 26, matrix[1][0] );
    EXPECT_EQ( 13, matrix[1][1] );
}



TEST( Matrix2x2, operator_mult_vector2 )
{
    Matrix2x2 matrix( 3, 2, 4, 5 );
    Vector2f result = matrix * Vector2f( 2, 3 );

    EXPECT_EQ( 12, result.x );
    EXPECT_EQ( 23, result.y );
}
TEST( Matrix2x2, operator_mult_matrix2x2 )
{
    Matrix2x2 first ( 1, 2, 4, 3 );
    Matrix2x2 second( 5, 1, 2, 3 );
    Matrix2x2 result = first * second;

    EXPECT_EQ( 9,  result[0][0] );
    EXPECT_EQ( 7,  result[0][1] );
    EXPECT_EQ( 26, result[1][0] );
    EXPECT_EQ( 13, result[1][1] );
}


TEST( Matrix2x2, determinant )
{
    Matrix2x2 matrix;
    matrix.set( 0, 1, 2, 3 );
    EXPECT_EQ( 0*3-1*2, matrix.determinant() );
}

TEST( Matrix2x2, inverse )
{
    Matrix2x2 matrix( 4, 3, 5, 11 );
    Matrix2x2 inverse = matrix.inverse();

    EXPECT_EQ( Matrix2x2::IDENTITY, matrix * inverse );
    EXPECT_EQ( Matrix2x2::IDENTITY, inverse * matrix );
}

TEST( Matrix2x2, transpose )
{
    Matrix2x2 matrix( 4, 3, 5, 11 );
    Matrix2x2 transpose = matrix.transpose();
    EXPECT_EQ( 4,  transpose[0][0] );
    EXPECT_EQ( 5,  transpose[0][1] );
    EXPECT_EQ( 3,  transpose[1][0] );
    EXPECT_EQ( 11, transpose[1][1] );
}
