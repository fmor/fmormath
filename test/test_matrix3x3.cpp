#include "../src/matrix3x3.h"

#include <gtest/gtest.h>

using namespace fmormath;


//static void ExpectMatrixIsIdentityMatrix( const Matrix3x3& matrix )
//{
//    EXPECT_FLOAT_EQ( 1.f, matrix[0][0] );
//    EXPECT_FLOAT_EQ( 0.f, matrix[0][1] );
//    EXPECT_FLOAT_EQ( 0.f, matrix[0][2] );

//    EXPECT_FLOAT_EQ( 0.f, matrix[1][0] );
//    EXPECT_FLOAT_EQ( 1.f, matrix[1][1] );
//    EXPECT_FLOAT_EQ( 0.f, matrix[1][2] );

//    EXPECT_FLOAT_EQ( 0.f, matrix[2][0] );
//    EXPECT_FLOAT_EQ( 0.f, matrix[2][1] );
//    EXPECT_FLOAT_EQ( 1., matrix[2][2] );
//}



TEST( Matrix3x3, identity )
{
    EXPECT_FLOAT_EQ( 1.f, Matrix3x3::IDENTITY[0][0] );
    EXPECT_FLOAT_EQ( 0.f, Matrix3x3::IDENTITY[0][1] );
    EXPECT_FLOAT_EQ( 0.f, Matrix3x3::IDENTITY[0][2] );

    EXPECT_FLOAT_EQ( 0.f, Matrix3x3::IDENTITY[1][0] );
    EXPECT_FLOAT_EQ( 1.f, Matrix3x3::IDENTITY[1][1] );
    EXPECT_FLOAT_EQ( 0.f, Matrix3x3::IDENTITY[1][2] );

    EXPECT_FLOAT_EQ( 0.f, Matrix3x3::IDENTITY[2][0] );
    EXPECT_FLOAT_EQ( 0.f, Matrix3x3::IDENTITY[2][1] );
    EXPECT_FLOAT_EQ( 1.f, Matrix3x3::IDENTITY[2][2] );
}

TEST( Matrix3x3, set )
{
    Matrix3x3 matrix;
    matrix.set( 8, 7, 6, 5, 4, 3, 2, 1,0 );

    EXPECT_FLOAT_EQ( 8, matrix[0][0] );
    EXPECT_FLOAT_EQ( 7, matrix[0][1] );
    EXPECT_FLOAT_EQ( 6, matrix[0][2] );

    EXPECT_FLOAT_EQ( 5, matrix[1][0] );
    EXPECT_FLOAT_EQ( 4, matrix[1][1] );
    EXPECT_FLOAT_EQ( 3, matrix[1][2] );

    EXPECT_FLOAT_EQ( 2, matrix[2][0] );
    EXPECT_FLOAT_EQ( 1, matrix[2][1] );
    EXPECT_FLOAT_EQ( 0, matrix[2][2] );

}


TEST( Matrix3x3, operator_equal )
{
    Matrix3x3 first(  0, 1, 2, 3, 4, 5, 6, 7, 8 );
    Matrix3x3 second( 0, 1, 2, 3, 4, 5, 6, 7, 8 );
    Matrix3x3 third(  8, 7, 6, 5, 4, 3, 2, 1, 0 );

    EXPECT_TRUE(  first == second );
    EXPECT_FALSE( first == third );
}

TEST( Matrix3x3, operator_notequal )
{
    Matrix3x3 first(  0, 1, 2, 3, 4, 5, 6, 7, 8 );
    Matrix3x3 second( 0, 1, 2, 3, 4, 5, 6, 7, 8 );
    Matrix3x3 third(  8, 7, 6, 5, 4, 3, 2, 1, 0 );

    EXPECT_FALSE( first != second );
    EXPECT_TRUE(  first != third );
}
TEST( Matrix3x3, operator_add_equal_matrix3x3 )
{
    Matrix3x3 first(  0,1,2, 3,5,7, 11,13,17 );
    Matrix3x3 second( 17,13,11, 7,5,3, 2,1,0 );
    first += second;
    EXPECT_FLOAT_EQ( 17.f, first[0][0] );
    EXPECT_FLOAT_EQ( 14.f, first[0][1] );
    EXPECT_FLOAT_EQ( 13.f, first[0][2] );

    EXPECT_FLOAT_EQ( 10.f, first[1][0] );
    EXPECT_FLOAT_EQ( 10.f, first[1][1] );
    EXPECT_FLOAT_EQ( 10.f, first[1][2] );

    EXPECT_FLOAT_EQ( 13.f, first[2][0] );
    EXPECT_FLOAT_EQ( 14.f, first[2][1] );
    EXPECT_FLOAT_EQ( 17.f, first[2][2] );
}
TEST( Matrix3x3, operator_sub_equal_matrix3x3 )
{
    Matrix3x3 first(  0,1,2,    3,5,7, 11,13,17 );
    Matrix3x3 second( 17,13,11, 7,5,3, 2,1,0 );
    first -= second;
    EXPECT_FLOAT_EQ(-17.f, first[0][0] );
    EXPECT_FLOAT_EQ(-12.f, first[0][1] );
    EXPECT_FLOAT_EQ( -9.f, first[0][2] );

    EXPECT_FLOAT_EQ(-4.f, first[1][0] );
    EXPECT_FLOAT_EQ( 0.f, first[1][1] );
    EXPECT_FLOAT_EQ( 4.f, first[1][2] );

    EXPECT_FLOAT_EQ( 9.f, first[2][0] );
    EXPECT_FLOAT_EQ( 12.f, first[2][1] );
    EXPECT_FLOAT_EQ( 17.f, first[2][2] );
}

TEST( Matrix3x3, operator_mult_equal_float )
{
    Matrix3x3 matrix(  0, 1, 2, 3, 4, 5, 6, 7, 8 );
    matrix *= 2.f;

    EXPECT_FLOAT_EQ(  0.f, matrix[0][0] );
    EXPECT_FLOAT_EQ(  2.f, matrix[0][1] );
    EXPECT_FLOAT_EQ(  4.f, matrix[0][2] );

    EXPECT_FLOAT_EQ(  6.f, matrix[1][0] );
    EXPECT_FLOAT_EQ(  8.f, matrix[1][1] );
    EXPECT_FLOAT_EQ( 10.f, matrix[1][2] );

    EXPECT_FLOAT_EQ( 12.f, matrix[2][0] );
    EXPECT_FLOAT_EQ( 14.f, matrix[2][1] );
    EXPECT_FLOAT_EQ( 16.f, matrix[2][2] );
}

TEST( Matrix3x3, operator_mult_equal_Matrix3x3 )
{

    Matrix3x3 matrix( 2,  0,  5,
                     0,  4,  0,
                     0,  0,  6 );

    Matrix3x3 other( 6,  1,  0,
                     11, 4,  0,
                     0,  3,  6 );


    matrix *= other;


    EXPECT_FLOAT_EQ( 12, matrix[0][0] );
    EXPECT_FLOAT_EQ( 17, matrix[0][1] );
    EXPECT_FLOAT_EQ( 30, matrix[0][2] );

    EXPECT_FLOAT_EQ( 44, matrix[1][0] );
    EXPECT_FLOAT_EQ( 16, matrix[1][1] );
    EXPECT_FLOAT_EQ( 0,  matrix[1][2] );

    EXPECT_FLOAT_EQ(  0, matrix[2][0] );
    EXPECT_FLOAT_EQ( 18, matrix[2][1] );
    EXPECT_FLOAT_EQ( 36, matrix[2][2] );
}


TEST( Matrix3x3, operator_mult_Vector3f )
{
    Vector3f v3( 4, 2, 1 );

    Matrix3x3 first(  2, 0, 0,
                        0, 4, 0,
                        0, 0, 6 );

    Vector3f result = first * v3;

    EXPECT_FLOAT_EQ( 8, result.x );
    EXPECT_FLOAT_EQ( 8, result.y );
    EXPECT_FLOAT_EQ( 6, result.z );
}
TEST( Matrix3x3, operator_mult_Matrix3x3 )
{

    Matrix3x3 first( 2,  0,  5,
                     0,  4,  0,
                     0,  0,  6 );

    Matrix3x3 second( 6,  1,  0,
                     11, 4,  0,
                     0,  3,  6 );

    Matrix3x3 result = first * second;

    EXPECT_FLOAT_EQ( 12, result[0][0] );
    EXPECT_FLOAT_EQ( 17, result[0][1] );
    EXPECT_FLOAT_EQ( 30, result[0][2] );

    EXPECT_FLOAT_EQ( 44, result[1][0] );
    EXPECT_FLOAT_EQ( 16, result[1][1] );
    EXPECT_FLOAT_EQ( 0,  result[1][2] );

    EXPECT_FLOAT_EQ(  0, result[2][0] );
    EXPECT_FLOAT_EQ( 18, result[2][1] );
    EXPECT_FLOAT_EQ( 36, result[2][2] );
}

TEST( Matrix3x3, determinant )
{
    EXPECT_FLOAT_EQ(   0,  Matrix3x3(  0,1,2, 3,4,5,   6,7,8).determinant() );
    EXPECT_FLOAT_EQ( -688, Matrix3x3( 4,24,2, 3,-4,5,  1,8,8).determinant() );
    EXPECT_FLOAT_EQ( -996, Matrix3x3( 4,5,7, 44,11,18, 0,1,7).determinant() );

}



TEST( Matrix3x3, inverse )
{
    Matrix3x3 matrix;;
    Matrix3x3 inverse;

    //////
    matrix.set(  4,5,7,  4,11,18,  0, 1,7 );
    inverse = matrix.inverse();
    EXPECT_FLOAT_EQ(  59.0f/124.f, inverse[0][0] );
    EXPECT_FLOAT_EQ( -28.0f/124.f, inverse[0][1] );
    EXPECT_FLOAT_EQ(  13.0f/124.f, inverse[0][2] );

    EXPECT_FLOAT_EQ( -28.0f/124.f, inverse[1][0] );
    EXPECT_FLOAT_EQ(  28.0f/124.f, inverse[1][1] );
    EXPECT_FLOAT_EQ( -44.0f/124.f, inverse[1][2] );

    EXPECT_FLOAT_EQ(  4.0f/124.0f, inverse[2][0] );
    EXPECT_FLOAT_EQ( -4.0f/124.0f, inverse[2][1] );
    EXPECT_FLOAT_EQ( 24.0f/124.0f, inverse[2][2] );

    //////
    matrix.set( 3,0,2, 2,0,-2, 0,1,1 );
    inverse = matrix.inverse();

    EXPECT_FLOAT_EQ( 0.2f,  inverse[0][0] );
    EXPECT_FLOAT_EQ( 0.2f,  inverse[0][1] );
    EXPECT_FLOAT_EQ( 0.0f,  inverse[0][2] );

    EXPECT_FLOAT_EQ( -0.2f, inverse[1][0] );
    EXPECT_FLOAT_EQ( 0.3f,  inverse[1][1] );
    EXPECT_FLOAT_EQ( 1.0f,  inverse[1][2] );

    EXPECT_FLOAT_EQ(  0.2f, inverse[2][0] );
    EXPECT_FLOAT_EQ( -0.3f, inverse[2][1] );
    EXPECT_FLOAT_EQ(  0.0f, inverse[2][2] );

    //////
    matrix.set( 3.0f,0.0f,2.0f, 2.0f,0.0f,-2.0f, 99.0f,1.f,1.f );
    inverse = matrix.inverse();

    EXPECT_FLOAT_EQ( 0.2f,  inverse[0][0] );
    EXPECT_FLOAT_EQ( 0.2f,  inverse[0][1] );
    EXPECT_FLOAT_EQ( 0.0f,  inverse[0][2] );

    EXPECT_FLOAT_EQ( -20.0f, inverse[1][0] );
    EXPECT_FLOAT_EQ( -19.5f, inverse[1][1] );
    EXPECT_FLOAT_EQ(   1.0f, inverse[1][2] );

    EXPECT_FLOAT_EQ(  0.2f, inverse[2][0] );
    EXPECT_FLOAT_EQ( -0.3f, inverse[2][1] );
    EXPECT_FLOAT_EQ(  0.0f, inverse[2][2] );

    //////
    matrix.set( 4.f,  8.f, 5.f,
                7.f, 11.f, 2.f,
               -3.f,  8.f, 9.f );
    inverse = matrix.inverse();

    EXPECT_FLOAT_EQ(  83.f/225.f, inverse[0][0] );
    EXPECT_FLOAT_EQ( -32.f/225.f, inverse[0][1] );
    EXPECT_FLOAT_EQ( -39.f/225.f, inverse[0][2] );

    EXPECT_FLOAT_EQ( -69.f/225.f, inverse[1][0] );
    EXPECT_FLOAT_EQ(  51.f/225.f, inverse[1][1] );
    EXPECT_FLOAT_EQ(  27.f/225.f, inverse[1][2] );

    EXPECT_FLOAT_EQ( 89.f/225.f,  inverse[2][0] );
    EXPECT_FLOAT_EQ(-56.f/225.f,  inverse[2][1] );
    EXPECT_FLOAT_EQ(-12.f/225.f,  inverse[2][2] );



}


TEST( Matrix3x3, transpose )
{

    Matrix3x3 matrix(  4,   5,  7,
                      44,  11, 18,
                       0,   1,  7 );


    Matrix3x3 transpose = matrix.transpose();

    EXPECT_FLOAT_EQ( 4,  transpose[0][0] );
    EXPECT_FLOAT_EQ( 44, transpose[0][1] );
    EXPECT_FLOAT_EQ( 0,  transpose[0][2] );

    EXPECT_FLOAT_EQ( 5, transpose[1][0] );
    EXPECT_FLOAT_EQ( 11, transpose[1][1] );
    EXPECT_FLOAT_EQ( 1,  transpose[1][2] );

    EXPECT_FLOAT_EQ(  7, transpose[2][0] );
    EXPECT_FLOAT_EQ( 18, transpose[2][1] );
    EXPECT_FLOAT_EQ( 7, transpose[2][2] );
}
