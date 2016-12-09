#include <gtest/gtest.h>


#include "../src/matrix4x4.h"
#include "../src/common.h"




using namespace fmormath;

TEST( Matrix4x4, identity )
{
    EXPECT_FLOAT_EQ( 1, Matrix4x4::IDENTITY[0][0] );
    EXPECT_FLOAT_EQ( 0, Matrix4x4::IDENTITY[0][1] );
    EXPECT_FLOAT_EQ( 0, Matrix4x4::IDENTITY[0][2] );
    EXPECT_FLOAT_EQ( 0, Matrix4x4::IDENTITY[0][3] );

    EXPECT_FLOAT_EQ( 0, Matrix4x4::IDENTITY[1][0] );
    EXPECT_FLOAT_EQ( 1, Matrix4x4::IDENTITY[1][1] );
    EXPECT_FLOAT_EQ( 0, Matrix4x4::IDENTITY[1][2] );
    EXPECT_FLOAT_EQ( 0, Matrix4x4::IDENTITY[1][3] );

    EXPECT_FLOAT_EQ( 0, Matrix4x4::IDENTITY[2][0] );
    EXPECT_FLOAT_EQ( 0, Matrix4x4::IDENTITY[2][1] );
    EXPECT_FLOAT_EQ( 1, Matrix4x4::IDENTITY[2][2] );
    EXPECT_FLOAT_EQ( 0, Matrix4x4::IDENTITY[2][3] );

    EXPECT_FLOAT_EQ( 0, Matrix4x4::IDENTITY[3][0] );
    EXPECT_FLOAT_EQ( 0, Matrix4x4::IDENTITY[3][1] );
    EXPECT_FLOAT_EQ( 0, Matrix4x4::IDENTITY[3][2] );
    EXPECT_FLOAT_EQ( 1, Matrix4x4::IDENTITY[3][3] );
}

TEST( Matrix4x4, set )
{
    Matrix4x4 matrix;

    matrix.set( 0,  1,   2,  3,
                10, 11, 12, 13,
                20, 21, 22, 23,
                30, 31, 32, 33 );

    EXPECT_FLOAT_EQ( 0, matrix[0][0] );
    EXPECT_FLOAT_EQ( 1, matrix[0][1] );
    EXPECT_FLOAT_EQ( 2, matrix[0][2] );
    EXPECT_FLOAT_EQ( 3, matrix[0][3] );

    EXPECT_FLOAT_EQ( 10, matrix[1][0] );
    EXPECT_FLOAT_EQ( 11, matrix[1][1] );
    EXPECT_FLOAT_EQ( 12, matrix[1][2] );
    EXPECT_FLOAT_EQ( 13, matrix[1][3] );

    EXPECT_FLOAT_EQ( 20, matrix[2][0] );
    EXPECT_FLOAT_EQ( 21, matrix[2][1] );
    EXPECT_FLOAT_EQ( 22, matrix[2][2] );
    EXPECT_FLOAT_EQ( 23, matrix[2][3] );

    EXPECT_FLOAT_EQ( 30, matrix[3][0] );
    EXPECT_FLOAT_EQ( 31, matrix[3][1] );
    EXPECT_FLOAT_EQ( 32, matrix[3][2] );
    EXPECT_FLOAT_EQ( 33, matrix[3][3] );
}


TEST( Matrix4x4, operator_equal )
{
    Matrix4x4 first(  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 );
    Matrix4x4 second( 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 );

    EXPECT_TRUE( first == first );
    EXPECT_FALSE( first == second );
}
TEST( Matrix4x4, operator_notequal )
{
    Matrix4x4 first(  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 );
    Matrix4x4 second( 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 );

    EXPECT_FALSE( first != first );
    EXPECT_TRUE(  first != second );
}
TEST( Matrix4x4, operator_mult_equal_float )
{
    Matrix4x4 matrix(  0, 1, 2, 3,  4,5,6,7, 8,9,10,11, 12,13,14,15 );
    matrix *= 2.f;

    EXPECT_FLOAT_EQ( 0, matrix[0][0] );
    EXPECT_FLOAT_EQ( 2.f, matrix[0][1] );
    EXPECT_FLOAT_EQ( 4.f, matrix[0][2] );
    EXPECT_FLOAT_EQ( 6.f, matrix[0][3] );

    EXPECT_FLOAT_EQ( 8.f, matrix[1][0] );
    EXPECT_FLOAT_EQ( 10.f, matrix[1][1] );
    EXPECT_FLOAT_EQ( 12.f, matrix[1][2] );
    EXPECT_FLOAT_EQ( 14.f, matrix[1][3] );

    EXPECT_FLOAT_EQ( 16.f, matrix[2][0] );
    EXPECT_FLOAT_EQ( 18.f, matrix[2][1] );
    EXPECT_FLOAT_EQ( 20.f, matrix[2][2] );
    EXPECT_FLOAT_EQ( 22.f, matrix[2][3] );

    EXPECT_FLOAT_EQ( 24.f, matrix[3][0] );
    EXPECT_FLOAT_EQ( 26.f, matrix[3][1] );
    EXPECT_FLOAT_EQ( 28, matrix[3][2] );
    EXPECT_FLOAT_EQ( 30, matrix[3][3] );
}
TEST( Matrix4x4, operator_add_equal_matrix4x4 )
{
    Matrix4x4 first(  0,1,2,8,   3,5,7,4, 11,13,17,1, 6,4,6,7 );
    Matrix4x4 second( 17,13,1,1, 7,5,3,9, 6,4,6,7,    5,2,1,0 );

    first += second;

    EXPECT_FLOAT_EQ( 17.f, first[0][0] );
    EXPECT_FLOAT_EQ( 14.f, first[0][1] );
    EXPECT_FLOAT_EQ(  3.f, first[0][2] );
    EXPECT_FLOAT_EQ(  9.f, first[0][3] );

    EXPECT_FLOAT_EQ( 10.f, first[1][0] );
    EXPECT_FLOAT_EQ( 10.f, first[1][1] );
    EXPECT_FLOAT_EQ( 10.f, first[1][2] );
    EXPECT_FLOAT_EQ( 13.f, first[1][3] );

    EXPECT_FLOAT_EQ( 17.f, first[2][0] );
    EXPECT_FLOAT_EQ( 17.f, first[2][1] );
    EXPECT_FLOAT_EQ( 23.f, first[2][2] );
    EXPECT_FLOAT_EQ(  8.f, first[2][3] );

    EXPECT_FLOAT_EQ( 11.f, first[3][0] );
    EXPECT_FLOAT_EQ(  6.f, first[3][1] );
    EXPECT_FLOAT_EQ(  7.f, first[3][2] );
    EXPECT_FLOAT_EQ(  7.f, first[3][3] );
}
TEST( Matrix4x4, operator_sub_equal_matrix4x4 )
{
    Matrix4x4 first(  0,1,2,8,   3,5,7,4, 11,13,17,1, 6,4,6,7 );
    Matrix4x4 second( 17,13,1,1, 7,5,3,9, 6,4,6,7,    5,2,1,0 );
    first -= second;

    EXPECT_FLOAT_EQ(-17.f, first[0][0] );
    EXPECT_FLOAT_EQ(-12.f, first[0][1] );
    EXPECT_FLOAT_EQ(  1.f, first[0][2] );
    EXPECT_FLOAT_EQ(  7.f, first[0][3] );

    EXPECT_FLOAT_EQ( -4.f, first[1][0] );
    EXPECT_FLOAT_EQ(  0.f, first[1][1] );
    EXPECT_FLOAT_EQ(  4.f, first[1][2] );
    EXPECT_FLOAT_EQ( -5.f, first[1][3] );

    EXPECT_FLOAT_EQ(  5.f, first[2][0] );
    EXPECT_FLOAT_EQ(  9.f, first[2][1] );
    EXPECT_FLOAT_EQ( 11.f, first[2][2] );
    EXPECT_FLOAT_EQ( -6.f, first[2][3] );

    EXPECT_FLOAT_EQ(  1.f, first[3][0] );
    EXPECT_FLOAT_EQ(  2.f, first[3][1] );
    EXPECT_FLOAT_EQ(  5.f, first[3][2] );
    EXPECT_FLOAT_EQ(  7.f, first[3][3] );
}
TEST( Matrix4x4, operator_mult_equal_matrix4x4 )
{
    Matrix4x4 matrix(  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 );
    Matrix4x4 other( 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 );
    Matrix4x4 correct( 34,   28,  22,  16,
                         178, 156, 134, 112,
                         322, 284, 246, 208,
                         466, 412, 358, 304 );

    matrix *= other;

    EXPECT_TRUE( matrix == correct );
}


TEST( Matrix4x4, operator_mult_V2 )
{
}

TEST( Matrix4x4, operator_mult_V3 )
{
    Vector3f v3( 1,2,3 );


    Matrix4x4 mat4 = Matrix4x4::IDENTITY;

    Vector3f result = mat4 * v3;
    EXPECT_TRUE( result == v3 );
}

TEST( Matrix4x4, operator_mult_V3_translation )
{
    Vector3f position( 1,2,3 );
    Vector3f translation( -4, 5, 10 );
    Vector3f correct(-3, 7, 13);

    Matrix4x4 matrix;
    matrix.makeTranslationMatrix( translation );

    EXPECT_EQ( correct, matrix * position );
}

TEST( Matrix4x4, operator_mult_V3_scale )
{
    Vector3f position( 1,2,3 );
    Vector3f scale( 6, 3, -8 );
    Vector3f correct( 6, 6, -24 );

    Matrix4x4 matrix;
    matrix.makeScaleMatrix( scale );

    EXPECT_EQ( correct, matrix * position );
}



TEST( Matrix4x4, operator_mult_V4 )
{
    Vector4f v4( 1,2,3,4 );


    Matrix4x4 mat4 = Matrix4x4::IDENTITY;

    Vector4f result = mat4 * v4;

    EXPECT_TRUE( result == v4 );
}
TEST( Matrix4x4, operator_mult_matrix4x4 )
{
    Matrix4x4 result;

    ///
    Matrix4x4 first(  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 );
    Matrix4x4 second( 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 );
    Matrix4x4 correct( 34,   28,  22,  16,
                         178, 156, 134, 112,
                         322, 284, 246, 208,
                         466, 412, 358, 304 );

    result = first * second;
    EXPECT_TRUE( result == correct );


    ///
    first.set(   1,  2,  3, 4,  5,  6,  7, 8,  9, 10, 11, 12, 13, 14, 15, 16 );
    second.set( 16, 15, 14, 13, 0, 12, 11, 10, 9,  8,  7,  2,  6,  5,  4,  3 );
    correct.set( 67,  83,  73,  51,
                 191, 243, 217, 163,
                 315, 403, 361, 275,
                 439, 563, 505, 387  );
    result = first * second;

    EXPECT_TRUE( result == correct );
}



TEST( Matrix4x4, determinant )
{
    Matrix4x4 mat4;


    ///
    mat4.set( 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 );
    EXPECT_FLOAT_EQ( 0, mat4.determinant() );

    ///
    mat4.set( 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0  );
    EXPECT_FLOAT_EQ( 0, mat4.determinant() );

    ///
    mat4.set( 1,    0,   0,   0,
              0,    1,   4,   2,
              2,    4,   8,   16,
              16,   8,   4,   2);
    EXPECT_FLOAT_EQ( 336, mat4.determinant() );


    ///
    mat4.set( -1,  0,  1,  1,
               1, -2,  1, -1,
               1,  0, -1,  1,
               1,  0,  1, -1 );
    EXPECT_FLOAT_EQ( -8, mat4.determinant() );


    ///
    mat4.set( 3,  0,  2, -1,
              1,  2,  0, -2,
              4,  0,  6, -3,
              5,  0,  2,  0 );
    EXPECT_FLOAT_EQ( 20, mat4.determinant() );

    ///
    mat4.set( 4,  5,  3, 0,
              2,  1,  4, 5,
              8,  9, 10, 1,
              3,  0,  1, 4 );
    EXPECT_FLOAT_EQ( 224.f, mat4.determinant() );

}

TEST( Matrix4x4, inverse )
{
    Matrix4x4 matrix;

    matrix.set( 1,   3,  5,  7,
                11, 13, 17, 19,
                23, 29,  1,  3,
                5,   7, 11, 13 );

    Matrix4x4 inverse = matrix.inverse();

    EXPECT_FLOAT_EQ( 4,           inverse[0][0] );
    EXPECT_FLOAT_EQ( 43.f/12.f,   inverse[0][1] );
    EXPECT_FLOAT_EQ( -0.25f,      inverse[0][2] );
    EXPECT_FLOAT_EQ( -22.f/3.f,   inverse[0][3] );

    EXPECT_FLOAT_EQ( -7.f/2.f,    inverse[1][0] );
    EXPECT_FLOAT_EQ( -37.f/12.f,  inverse[1][1] );
    EXPECT_FLOAT_EQ( 0.25f,       inverse[1][2] );
    EXPECT_FLOAT_EQ( 19.f/3.f,    inverse[1][3] );

    EXPECT_FLOAT_EQ( -11.f/2.f,   inverse[2][0] );
    EXPECT_FLOAT_EQ( -4.f,        inverse[2][1] );
    EXPECT_FLOAT_EQ( 0.25f,       inverse[2][2] );
    EXPECT_FLOAT_EQ( 35.f/4.f,    inverse[2][3] );

    EXPECT_FLOAT_EQ( 5.f,         inverse[3][0] );
    EXPECT_FLOAT_EQ( 11.f/3.f,    inverse[3][1] );
    EXPECT_FLOAT_EQ( -0.25f,      inverse[3][2] );
    EXPECT_FLOAT_EQ( -95.f/12.f,  inverse[3][3] );




//    assert( 4 ==           inverse[0][0] );
//    assert( 43.f/12.f ==   inverse[0][1] );
//    assert( -0.25f ==      inverse[0][2] );
//    assert( -22.f/3.f ==   inverse[0][3] );

//    assert( -7.f/2.f ==    inverse[1][0] );
//    assert( -37.f/12.f ==  inverse[1][1] );
//    assert( 0.25f ==       inverse[1][2] );
//    assert( 19.f/3.f ==    inverse[1][3] );

//    assert( -11.f/2.f ==   inverse[2][0] );
//    assert( -4.f ==        inverse[2][1] );
//    assert( 0.25f ==       inverse[2][2] );
//    assert( 35.f/4.f ==    inverse[2][3] );

//    assert( 5.f ==         inverse[3][0] );
//    assert( 11.f/3.f ==    inverse[3][1] );
//    assert( -0.25f ==      inverse[3][2] );
//    assert( -95.f/12.f ==  inverse[3][3] );
}




TEST( Matrix4x4, transpose )
{
    Matrix4x4 matrix;

    matrix.set( 1,   3,  5,  7,
                11, 13, 17, 19,
                23, 29,  1,  3,
                5,   7, 11, 13 );

    Matrix4x4 transpose = matrix.tranpose();

    EXPECT_FLOAT_EQ( 1,  transpose[0][0] );
    EXPECT_FLOAT_EQ( 11, transpose[0][1] );
    EXPECT_FLOAT_EQ( 23, transpose[0][2] );
    EXPECT_FLOAT_EQ( 5,  transpose[0][3] );

    EXPECT_FLOAT_EQ( 3,  transpose[1][0] );
    EXPECT_FLOAT_EQ( 13, transpose[1][1] );
    EXPECT_FLOAT_EQ( 29, transpose[1][2] );
    EXPECT_FLOAT_EQ( 7,  transpose[1][3] );

    EXPECT_FLOAT_EQ( 5,  transpose[2][0] );
    EXPECT_FLOAT_EQ( 17, transpose[2][1] );
    EXPECT_FLOAT_EQ( 1,  transpose[2][2] );
    EXPECT_FLOAT_EQ( 11, transpose[2][3] );

    EXPECT_FLOAT_EQ( 7,  transpose[3][0] );
    EXPECT_FLOAT_EQ( 19, transpose[3][1] );
    EXPECT_FLOAT_EQ( 3,  transpose[3][2] );
    EXPECT_FLOAT_EQ( 13, transpose[3][3] );
}


TEST( Matrix4x4, makeTranslationMatrix )
{
    Vector3f translation( -4, 5, 10 );
    Matrix4x4 matrix;
    matrix.makeTranslationMatrix( translation );

    EXPECT_FLOAT_EQ( 1, matrix[0][0] );
    EXPECT_FLOAT_EQ( 0, matrix[0][1] );
    EXPECT_FLOAT_EQ( 0, matrix[0][2] );
    EXPECT_FLOAT_EQ( translation.x, matrix[0][3] );

    EXPECT_FLOAT_EQ( 0, matrix[1][0] );
    EXPECT_FLOAT_EQ( 1, matrix[1][1] );
    EXPECT_FLOAT_EQ( 0, matrix[0][2] );
    EXPECT_FLOAT_EQ( translation.y, matrix[1][3] );

    EXPECT_FLOAT_EQ( 0, matrix[2][0] );
    EXPECT_FLOAT_EQ( 0, matrix[2][1] );
    EXPECT_FLOAT_EQ( 1, matrix[2][2] );
    EXPECT_FLOAT_EQ( translation.z, matrix[2][3] );

    EXPECT_FLOAT_EQ( 0, matrix[3][0] );
    EXPECT_FLOAT_EQ( 0, matrix[3][1] );
    EXPECT_FLOAT_EQ( 0, matrix[3][2] );
    EXPECT_FLOAT_EQ( 1, matrix[3][3] );
}


TEST( Matrix4x4, makeRotationMatrix )
{
    Quaternion q;
    Vector3f r;
    Matrix4x4 m;

    q.fromAngleAxis(DegreeToRadian(90), Vector3f::UNIT_Y );
    r = m.makeRotationMatrix( q ) * Vector3f::UNIT_Z;
    EXPECT_EQ( r, Vector3f::UNIT_X );

    q.fromAngleAxis(DegreeToRadian(90), Vector3f::UNIT_Z );
    r = m.makeRotationMatrix( q ) * Vector3f::UNIT_X;
    EXPECT_EQ( r, Vector3f::UNIT_Y );

    q.fromAngleAxis(DegreeToRadian(180), Vector3f(-1,0,0) );
    r = m.makeRotationMatrix( q ) * Vector3f::UNIT_SCALE;
    EXPECT_EQ( r, Vector3f( 1,-1,-1)  );

}

TEST( Matrix4x4, makeScaleMatrix )
{
    Vector3f scale( 6, 3, -8 );
    Matrix4x4 matrix;
    matrix.makeScaleMatrix( scale );

    EXPECT_FLOAT_EQ( scale.x, matrix[0][0] );
    EXPECT_FLOAT_EQ( 0,       matrix[0][1] );
    EXPECT_FLOAT_EQ( 0,       matrix[0][2] );
    EXPECT_FLOAT_EQ( 0,       matrix[0][3] );

    EXPECT_FLOAT_EQ( 0,       matrix[1][0] );
    EXPECT_FLOAT_EQ( scale.y, matrix[1][1] );
    EXPECT_FLOAT_EQ( 0,       matrix[1][2] );
    EXPECT_FLOAT_EQ( 0,       matrix[1][3] );

    EXPECT_FLOAT_EQ( 0,       matrix[2][0] );
    EXPECT_FLOAT_EQ( 0,       matrix[2][1] );
    EXPECT_FLOAT_EQ( scale.z, matrix[2][2] );
    EXPECT_FLOAT_EQ( 0,       matrix[2][3] );

    EXPECT_FLOAT_EQ( 0,       matrix[3][0] );
    EXPECT_FLOAT_EQ( 0,       matrix[3][1] );
    EXPECT_FLOAT_EQ( 0,       matrix[3][2] );
    EXPECT_FLOAT_EQ( 1,       matrix[3][3] );


}

TEST( Matrix4x4, makeProjOrthoMatrix  )
{
    Matrix4x4 matrix;
    matrix.makeProjOrthoMatrix( -256, 256, -128, 128, 1, 100 );


    Vector3f p;

    p = Vector3f( -128, 64, 1 );
    p = matrix * p;
    EXPECT_FLOAT_EQ( p.x , -0.5 );
    EXPECT_FLOAT_EQ( p.y, 0.5);
    EXPECT_FLOAT_EQ( p.z, Real(1.04040404) );


    p = Vector3f( 256, -128, -100 );
    p = matrix * p;
    EXPECT_FLOAT_EQ( p.x, Real( 1) );
    EXPECT_FLOAT_EQ( p.y, Real(-1) );
    EXPECT_FLOAT_EQ( p.z, Real(-1) );


    EXPECT_FLOAT_EQ( matrix[0][0], Real(2)/Real(256.-(-256.) ));
    EXPECT_FLOAT_EQ( matrix[0][1], 0 );
    EXPECT_FLOAT_EQ( matrix[0][2], 0 );
    EXPECT_FLOAT_EQ( matrix[0][3], -1. * ( 256.+(-256.)) / (256.-(-256.)) );

    EXPECT_FLOAT_EQ( matrix[1][0], 0 );
    EXPECT_FLOAT_EQ( matrix[1][1], Real(2)/Real(128.-(-128.)) );
    EXPECT_FLOAT_EQ( matrix[1][2], 0 );
    EXPECT_FLOAT_EQ( matrix[1][3], -1. * (128.+(-128.)) / (128.-(-128.)) );

    EXPECT_FLOAT_EQ( matrix[2][0], 0 );
    EXPECT_FLOAT_EQ( matrix[2][1], 0 );
    EXPECT_FLOAT_EQ( matrix[2][2], Real(2)/Real(100.-1.) );
    EXPECT_FLOAT_EQ( matrix[2][3], (100.+1.)/(100.-1.) );

    EXPECT_FLOAT_EQ( matrix[3][0], 0 );
    EXPECT_FLOAT_EQ( matrix[3][1], 0 );
    EXPECT_FLOAT_EQ( matrix[3][2], 0 );
    EXPECT_FLOAT_EQ( matrix[3][3], 1 );


}


TEST( Matrix4x4, translation )
{
    Vector3f translation( -4, 5, 10 );
    Matrix4x4 matrix;
    matrix.makeTranslationMatrix( translation );

    EXPECT_EQ( translation, matrix.getTranslation() );
}

TEST( Matrix4x4, setTranslation )
{
    Matrix4x4 m = Matrix4x4::IDENTITY;
    m.setTranslation( Vector3f( -4, 5, 10 ) );

    EXPECT_EQ( m * Vector3f::ZERO,  Vector3f( -4, 5, 10 ) );
    EXPECT_EQ( m * Vector3f::UNIT_SCALE,  Vector3f( -3, 6, 11 ) );
    EXPECT_EQ( m * Vector3f(4,-5,-10),  Vector3f::ZERO );
}

TEST( Matrix4x4, setScale )
{
    Matrix4x4 m = Matrix4x4::IDENTITY;
    m.setScale( Vector3f( 2, 3, 5 ) );

    EXPECT_EQ( m * Vector3f::ZERO,  Vector3f::ZERO );
    EXPECT_EQ( m * Vector3f::UNIT_SCALE,  Vector3f(2,3,5) );
    EXPECT_EQ( m * Vector3f(4,5,6) , Vector3f(8,15,30) );
}



