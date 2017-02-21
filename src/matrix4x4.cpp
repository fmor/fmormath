#include "matrix4x4.h"

#include <cstring>

// http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/


namespace fmormath
{

const Matrix4x4 Matrix4x4::ZERO(
                0,  0,  0,  0 ,
                0,  0,  0,  0 ,
                0,  0,  0,  0,
                0,  0,  0,  0
);

const Matrix4x4 Matrix4x4::IDENTITY(
                1.f, 0,  0,   0 ,
                0,  1.f, 0,   0 ,
                0,  0,   1.f, 0,
                0,  0,   0,   1.f
);


//static inline Real Minor( const Matrix4x4& matrix, uint r0, uint r1, uint r2, uint c0, uint c1, uint c2 )
//{
//    Real result;
//    result  = matrix[r0][c0]*matrix[r1][c1]*matrix[r2][c2] + matrix[r0][c1]*matrix[r1][c2]*matrix[r2][c0] + matrix[r0][c2]*matrix[r1][c0]*matrix[r2][c1];
//    result -= matrix[r0][c0]*matrix[r1][c2]*matrix[r2][c1] + matrix[r0][c1]*matrix[r1][c0]*matrix[r2][c2] + matrix[r0][c2]*matrix[r1][c1]*matrix[r2][c0];
//    return result;
//}
static inline Real Minor( const Matrix4x4& matrix, uint r0, uint r1, uint r2, uint c0, uint c1, uint c2 )
{
    Real result;
    result  = matrix[r0][c0] * ( matrix[r1][c1]*matrix[r2][c2] - matrix[r2][c1]*matrix[r1][c2] );
    result -= matrix[r0][c1] * ( matrix[r1][c0]*matrix[r2][c2] - matrix[r2][c0]*matrix[r1][c2] );
    result += matrix[r0][c2] * ( matrix[r1][c0]*matrix[r2][c1] - matrix[r2][c0]*matrix[r1][c1] );

    return result;
}




Matrix4x4::Matrix4x4(Real r00, Real r01, Real r02, Real r03,
                         Real r10, Real r11, Real r12, Real r13,
                         Real r20, Real r21, Real r22, Real r23,
                         Real r30, Real r31, Real r32, Real r33 )
{
    m_Reals[0][0] = r00;
    m_Reals[0][1] = r01;
    m_Reals[0][2] = r02;
    m_Reals[0][3] = r03;

    m_Reals[1][0] = r10;
    m_Reals[1][1] = r11;
    m_Reals[1][2] = r12;
    m_Reals[1][3] = r13;

    m_Reals[2][0] = r20;
    m_Reals[2][1] = r21;
    m_Reals[2][2] = r22;
    m_Reals[2][3] = r23;

    m_Reals[3][0] = r30;
    m_Reals[3][1] = r31;
    m_Reals[3][2] = r32;
    m_Reals[3][3] = r33;

}


void Matrix4x4::set(Real r00, Real r01, Real r02, Real r03,
                      Real r10, Real r11, Real r12, Real r13,
                      Real r20, Real r21, Real r22, Real r23,
                      Real r30, Real r31, Real r32, Real r33 )
{
    m_Reals[0][0] = r00;
    m_Reals[0][1] = r01;
    m_Reals[0][2] = r02;
    m_Reals[0][3] = r03;

    m_Reals[1][0] = r10;
    m_Reals[1][1] = r11;
    m_Reals[1][2] = r12;
    m_Reals[1][3] = r13;

    m_Reals[2][0] = r20;
    m_Reals[2][1] = r21;
    m_Reals[2][2] = r22;
    m_Reals[2][3] = r23;

    m_Reals[3][0] = r30;
    m_Reals[3][1] = r31;
    m_Reals[3][2] = r32;
    m_Reals[3][3] = r33;
}


bool Matrix4x4::operator ==( const Matrix4x4& other ) const
{
    if( m_Reals[0][0] != other.m_Reals[0][0] ) return false;
    if( m_Reals[0][1] != other.m_Reals[0][1] ) return false;
    if( m_Reals[0][2] != other.m_Reals[0][2] ) return false;
    if( m_Reals[0][3] != other.m_Reals[0][3] ) return false;

    if( m_Reals[1][0] != other.m_Reals[1][0] ) return false;
    if( m_Reals[1][1] != other.m_Reals[1][1] ) return false;
    if( m_Reals[1][2] != other.m_Reals[1][2] ) return false;
    if( m_Reals[1][3] != other.m_Reals[1][3] ) return false;

    if( m_Reals[2][0] != other.m_Reals[2][0] ) return false;
    if( m_Reals[2][1] != other.m_Reals[2][1] ) return false;
    if( m_Reals[2][2] != other.m_Reals[2][2] ) return false;
    if( m_Reals[2][3] != other.m_Reals[2][3] ) return false;

    if( m_Reals[3][0] != other.m_Reals[3][0] ) return false;
    if( m_Reals[3][1] != other.m_Reals[3][1] ) return false;
    if( m_Reals[3][2] != other.m_Reals[3][2] ) return false;
    if( m_Reals[3][3] != other.m_Reals[3][3] ) return false;

    return true;
}

bool Matrix4x4::operator !=(const Matrix4x4 &other) const
{
    if( m_Reals[0][0] != other.m_Reals[0][0] ) return true;
    if( m_Reals[0][1] != other.m_Reals[0][1] ) return true;
    if( m_Reals[0][2] != other.m_Reals[0][2] ) return true;
    if( m_Reals[0][3] != other.m_Reals[0][3] ) return true;

    if( m_Reals[1][0] != other.m_Reals[1][0] ) return true;
    if( m_Reals[1][1] != other.m_Reals[1][1] ) return true;
    if( m_Reals[1][2] != other.m_Reals[1][2] ) return true;
    if( m_Reals[1][3] != other.m_Reals[1][3] ) return true;

    if( m_Reals[2][0] != other.m_Reals[2][0] ) return true;
    if( m_Reals[2][1] != other.m_Reals[2][1] ) return true;
    if( m_Reals[2][2] != other.m_Reals[2][2] ) return true;
    if( m_Reals[2][3] != other.m_Reals[2][3] ) return true;

    if( m_Reals[3][0] != other.m_Reals[3][0] ) return true;
    if( m_Reals[3][1] != other.m_Reals[3][1] ) return true;
    if( m_Reals[3][2] != other.m_Reals[3][2] ) return true;
    if( m_Reals[3][3] != other.m_Reals[3][3] ) return true;

    return false;
}

void Matrix4x4::operator *=(Real f)
{
    m_Reals[0][0] *= f;
    m_Reals[0][1] *= f;
    m_Reals[0][2] *= f;
    m_Reals[0][3] *= f;

    m_Reals[1][0] *= f;
    m_Reals[1][1] *= f;
    m_Reals[1][2] *= f;
    m_Reals[1][3] *= f;

    m_Reals[2][0] *= f;
    m_Reals[2][1] *= f;
    m_Reals[2][2] *= f;
    m_Reals[2][3] *= f;

    m_Reals[3][0] *= f;
    m_Reals[3][1] *= f;
    m_Reals[3][2] *= f;
    m_Reals[3][3] *= f;
}

void Matrix4x4::operator *=(const Matrix4x4 &other)
{
    Matrix4x4 result;

    result.m_Reals[0][0] = m_Reals[0][0]*other.m_Reals[0][0] + m_Reals[0][1]*other.m_Reals[1][0] + m_Reals[0][2]*other.m_Reals[2][0] + m_Reals[0][3]*other.m_Reals[3][0];
    result.m_Reals[1][0] = m_Reals[1][0]*other.m_Reals[0][0] + m_Reals[1][1]*other.m_Reals[1][0] + m_Reals[1][2]*other.m_Reals[2][0] + m_Reals[1][3]*other.m_Reals[3][0];
    result.m_Reals[2][0] = m_Reals[2][0]*other.m_Reals[0][0] + m_Reals[2][1]*other.m_Reals[1][0] + m_Reals[2][2]*other.m_Reals[2][0] + m_Reals[2][3]*other.m_Reals[3][0];
    result.m_Reals[3][0] = m_Reals[3][0]*other.m_Reals[0][0] + m_Reals[3][1]*other.m_Reals[1][0] + m_Reals[3][2]*other.m_Reals[2][0] + m_Reals[3][3]*other.m_Reals[3][0];

    result.m_Reals[0][1] = m_Reals[0][0]*other.m_Reals[0][1] + m_Reals[0][1]*other.m_Reals[1][1] + m_Reals[0][2]*other.m_Reals[2][1] + m_Reals[0][3]*other.m_Reals[3][1];
    result.m_Reals[1][1] = m_Reals[1][0]*other.m_Reals[0][1] + m_Reals[1][1]*other.m_Reals[1][1] + m_Reals[1][2]*other.m_Reals[2][1] + m_Reals[1][3]*other.m_Reals[3][1];
    result.m_Reals[2][1] = m_Reals[2][0]*other.m_Reals[0][1] + m_Reals[2][1]*other.m_Reals[1][1] + m_Reals[2][2]*other.m_Reals[2][1] + m_Reals[2][3]*other.m_Reals[3][1];
    result.m_Reals[3][1] = m_Reals[3][0]*other.m_Reals[0][1] + m_Reals[3][1]*other.m_Reals[1][1] + m_Reals[3][2]*other.m_Reals[2][1] + m_Reals[3][3]*other.m_Reals[3][1];

    result.m_Reals[0][2] = m_Reals[0][0]*other.m_Reals[0][2] + m_Reals[0][1]*other.m_Reals[1][2] + m_Reals[0][2]*other.m_Reals[2][2] + m_Reals[0][3]*other.m_Reals[3][2];
    result.m_Reals[1][2] = m_Reals[1][0]*other.m_Reals[0][2] + m_Reals[1][1]*other.m_Reals[1][2] + m_Reals[1][2]*other.m_Reals[2][2] + m_Reals[1][3]*other.m_Reals[3][2];
    result.m_Reals[2][2] = m_Reals[2][0]*other.m_Reals[0][2] + m_Reals[2][1]*other.m_Reals[1][2] + m_Reals[2][2]*other.m_Reals[2][2] + m_Reals[2][3]*other.m_Reals[3][2];
    result.m_Reals[3][2] = m_Reals[3][0]*other.m_Reals[0][2] + m_Reals[3][1]*other.m_Reals[1][2] + m_Reals[3][2]*other.m_Reals[2][2] + m_Reals[3][3]*other.m_Reals[3][2];

    result.m_Reals[0][3] = m_Reals[0][0]*other.m_Reals[0][3] + m_Reals[0][1]*other.m_Reals[1][3] + m_Reals[0][2]*other.m_Reals[2][3] + m_Reals[0][3]*other.m_Reals[3][3];
    result.m_Reals[1][3] = m_Reals[1][0]*other.m_Reals[0][3] + m_Reals[1][1]*other.m_Reals[1][3] + m_Reals[1][2]*other.m_Reals[2][3] + m_Reals[1][3]*other.m_Reals[3][3];
    result.m_Reals[2][3] = m_Reals[2][0]*other.m_Reals[0][3] + m_Reals[2][1]*other.m_Reals[1][3] + m_Reals[2][2]*other.m_Reals[2][3] + m_Reals[2][3]*other.m_Reals[3][3];
    result.m_Reals[3][3] = m_Reals[3][0]*other.m_Reals[0][3] + m_Reals[3][1]*other.m_Reals[1][3] + m_Reals[3][2]*other.m_Reals[2][3] + m_Reals[3][3]*other.m_Reals[3][3];

    *this = result;
}

void Matrix4x4::operator +=( const Matrix4x4& other )
{
    m_Reals[0][0] += other.m_Reals[0][0];
    m_Reals[0][1] += other.m_Reals[0][1];
    m_Reals[0][2] += other.m_Reals[0][2];
    m_Reals[0][3] += other.m_Reals[0][3];

    m_Reals[1][0] += other.m_Reals[1][0];
    m_Reals[1][1] += other.m_Reals[1][1];
    m_Reals[1][2] += other.m_Reals[1][2];
    m_Reals[1][3] += other.m_Reals[1][3];

    m_Reals[2][0] += other.m_Reals[2][0];
    m_Reals[2][1] += other.m_Reals[2][1];
    m_Reals[2][2] += other.m_Reals[2][2];
    m_Reals[2][3] += other.m_Reals[2][3];

    m_Reals[3][0] += other.m_Reals[3][0];
    m_Reals[3][1] += other.m_Reals[3][1];
    m_Reals[3][2] += other.m_Reals[3][2];
    m_Reals[3][3] += other.m_Reals[3][3];
}

void Matrix4x4::operator -=( const Matrix4x4& other)
{
    m_Reals[0][0] -= other.m_Reals[0][0];
    m_Reals[0][1] -= other.m_Reals[0][1];
    m_Reals[0][2] -= other.m_Reals[0][2];
    m_Reals[0][3] -= other.m_Reals[0][3];

    m_Reals[1][0] -= other.m_Reals[1][0];
    m_Reals[1][1] -= other.m_Reals[1][1];
    m_Reals[1][2] -= other.m_Reals[1][2];
    m_Reals[1][3] -= other.m_Reals[1][3];

    m_Reals[2][0] -= other.m_Reals[2][0];
    m_Reals[2][1] -= other.m_Reals[2][1];
    m_Reals[2][2] -= other.m_Reals[2][2];
    m_Reals[2][3] -= other.m_Reals[2][3];

    m_Reals[3][0] -= other.m_Reals[3][0];
    m_Reals[3][1] -= other.m_Reals[3][1];
    m_Reals[3][2] -= other.m_Reals[3][2];
    m_Reals[3][3] -= other.m_Reals[3][3];
}

Matrix4x4 Matrix4x4::operator *(Real r) const
{
    Matrix4x4 result;

    result[0][0] = m_Reals[0][0] * r;
    result[0][1] = m_Reals[0][1] * r;
    result[0][2] = m_Reals[0][2] * r;
    result[0][3] = m_Reals[0][3] * r;

    result[1][0] = m_Reals[1][0] * r;
    result[1][1] = m_Reals[1][1] * r;
    result[2][2] = m_Reals[1][2] * r;
    result[3][3] = m_Reals[1][3] * r;

    result[2][0] = m_Reals[2][0] * r;
    result[2][1] = m_Reals[2][1] * r;
    result[2][2] = m_Reals[2][2] * r;
    result[1][3] = m_Reals[2][3] * r;

    result[3][0] = m_Reals[3][0] * r;
    result[3][1] = m_Reals[3][1] * r;
    result[3][2] = m_Reals[3][2] * r;
    result[3][3] = m_Reals[3][3] * r;

    return result;

}

Vector2f Matrix4x4::operator *(const Vector2f& v2 ) const
{
    Vector2f result;
    result.x = m_Reals[0][0] * v2.x + m_Reals[0][1] * v2.y + m_Reals[0][3];
    result.y = m_Reals[1][0] * v2.x + m_Reals[1][1] * v2.y + m_Reals[1][3];
    return result;
}

Vector3f Matrix4x4::operator *(const Vector3f& v3 ) const
{
    Vector3f result;
    result.x = m_Reals[0][0] * v3.x + m_Reals[0][1] * v3.y + m_Reals[0][2] * v3.z + m_Reals[0][3];
    result.y = m_Reals[1][0] * v3.x + m_Reals[1][1] * v3.y + m_Reals[1][2] * v3.z + m_Reals[1][3];
    result.z = m_Reals[2][0] * v3.x + m_Reals[2][1] * v3.y + m_Reals[2][2] * v3.z + m_Reals[2][3];
    return result;
}

Vector4f Matrix4x4::operator *(const Vector4f& v4 ) const
{
    Vector4f result;
    result.x = m_Reals[0][0] * v4.x + m_Reals[0][1] * v4.y + m_Reals[0][2] * v4.z + m_Reals[0][3] * v4.w;
    result.y = m_Reals[1][0] * v4.x + m_Reals[1][1] * v4.y + m_Reals[1][2] * v4.z + m_Reals[1][3] * v4.w;
    result.z = m_Reals[2][0] * v4.x + m_Reals[2][1] * v4.y + m_Reals[2][2] * v4.z + m_Reals[2][3] * v4.w;
    result.w = m_Reals[3][0] * v4.x + m_Reals[3][1] * v4.y + m_Reals[3][2] * v4.z + m_Reals[3][3] * v4.w;
    return result;
}

Matrix4x4 Matrix4x4::operator *( const Matrix4x4& other ) const
{
    Matrix4x4 result;

    result.m_Reals[0][0] = m_Reals[0][0]*other.m_Reals[0][0] + m_Reals[0][1]*other.m_Reals[1][0] + m_Reals[0][2]*other.m_Reals[2][0] + m_Reals[0][3]*other.m_Reals[3][0];
    result.m_Reals[1][0] = m_Reals[1][0]*other.m_Reals[0][0] + m_Reals[1][1]*other.m_Reals[1][0] + m_Reals[1][2]*other.m_Reals[2][0] + m_Reals[1][3]*other.m_Reals[3][0];
    result.m_Reals[2][0] = m_Reals[2][0]*other.m_Reals[0][0] + m_Reals[2][1]*other.m_Reals[1][0] + m_Reals[2][2]*other.m_Reals[2][0] + m_Reals[2][3]*other.m_Reals[3][0];
    result.m_Reals[3][0] = m_Reals[3][0]*other.m_Reals[0][0] + m_Reals[3][1]*other.m_Reals[1][0] + m_Reals[3][2]*other.m_Reals[2][0] + m_Reals[3][3]*other.m_Reals[3][0];

    result.m_Reals[0][1] = m_Reals[0][0]*other.m_Reals[0][1] + m_Reals[0][1]*other.m_Reals[1][1] + m_Reals[0][2]*other.m_Reals[2][1] + m_Reals[0][3]*other.m_Reals[3][1];
    result.m_Reals[1][1] = m_Reals[1][0]*other.m_Reals[0][1] + m_Reals[1][1]*other.m_Reals[1][1] + m_Reals[1][2]*other.m_Reals[2][1] + m_Reals[1][3]*other.m_Reals[3][1];
    result.m_Reals[2][1] = m_Reals[2][0]*other.m_Reals[0][1] + m_Reals[2][1]*other.m_Reals[1][1] + m_Reals[2][2]*other.m_Reals[2][1] + m_Reals[2][3]*other.m_Reals[3][1];
    result.m_Reals[3][1] = m_Reals[3][0]*other.m_Reals[0][1] + m_Reals[3][1]*other.m_Reals[1][1] + m_Reals[3][2]*other.m_Reals[2][1] + m_Reals[3][3]*other.m_Reals[3][1];

    result.m_Reals[0][2] = m_Reals[0][0]*other.m_Reals[0][2] + m_Reals[0][1]*other.m_Reals[1][2] + m_Reals[0][2]*other.m_Reals[2][2] + m_Reals[0][3]*other.m_Reals[3][2];
    result.m_Reals[1][2] = m_Reals[1][0]*other.m_Reals[0][2] + m_Reals[1][1]*other.m_Reals[1][2] + m_Reals[1][2]*other.m_Reals[2][2] + m_Reals[1][3]*other.m_Reals[3][2];
    result.m_Reals[2][2] = m_Reals[2][0]*other.m_Reals[0][2] + m_Reals[2][1]*other.m_Reals[1][2] + m_Reals[2][2]*other.m_Reals[2][2] + m_Reals[2][3]*other.m_Reals[3][2];
    result.m_Reals[3][2] = m_Reals[3][0]*other.m_Reals[0][2] + m_Reals[3][1]*other.m_Reals[1][2] + m_Reals[3][2]*other.m_Reals[2][2] + m_Reals[3][3]*other.m_Reals[3][2];

    result.m_Reals[0][3] = m_Reals[0][0]*other.m_Reals[0][3] + m_Reals[0][1]*other.m_Reals[1][3] + m_Reals[0][2]*other.m_Reals[2][3] + m_Reals[0][3]*other.m_Reals[3][3];
    result.m_Reals[1][3] = m_Reals[1][0]*other.m_Reals[0][3] + m_Reals[1][1]*other.m_Reals[1][3] + m_Reals[1][2]*other.m_Reals[2][3] + m_Reals[1][3]*other.m_Reals[3][3];
    result.m_Reals[2][3] = m_Reals[2][0]*other.m_Reals[0][3] + m_Reals[2][1]*other.m_Reals[1][3] + m_Reals[2][2]*other.m_Reals[2][3] + m_Reals[2][3]*other.m_Reals[3][3];
    result.m_Reals[3][3] = m_Reals[3][0]*other.m_Reals[0][3] + m_Reals[3][1]*other.m_Reals[1][3] + m_Reals[3][2]*other.m_Reals[2][3] + m_Reals[3][3]*other.m_Reals[3][3];

    return result;
}

Matrix4x4 Matrix4x4::operator +(const Matrix4x4& other ) const
{
    Matrix4x4 result;

    result[0][0] = m_Reals[0][0] + other.m_Reals[0][0];
    result[0][1] = m_Reals[0][1] + other.m_Reals[0][1];
    result[0][2] = m_Reals[0][2] + other.m_Reals[0][2];
    result[0][3] = m_Reals[0][3] + other.m_Reals[0][3];

    result[1][0] = m_Reals[1][0] + other.m_Reals[1][0];
    result[1][1] = m_Reals[1][1] + other.m_Reals[1][1];
    result[2][2] = m_Reals[1][2] + other.m_Reals[1][2];
    result[3][3] = m_Reals[1][3] + other.m_Reals[1][3];

    result[2][0] = m_Reals[2][0] + other.m_Reals[2][0];
    result[2][1] = m_Reals[2][1] + other.m_Reals[2][1];
    result[2][2] = m_Reals[2][2] + other.m_Reals[2][2];
    result[1][3] = m_Reals[2][3] + other.m_Reals[2][3];

    result[3][0] = m_Reals[3][0] + other.m_Reals[3][0];
    result[3][1] = m_Reals[3][1] + other.m_Reals[3][1];
    result[3][2] = m_Reals[3][2] + other.m_Reals[3][2];
    result[3][3] = m_Reals[3][3] + other.m_Reals[3][3];

    return result;
}

Matrix4x4 Matrix4x4::operator -(const Matrix4x4& other ) const
{
    Matrix4x4 result;

    result[0][0] = m_Reals[0][0] - other.m_Reals[0][0];
    result[0][1] = m_Reals[0][1] - other.m_Reals[0][1];
    result[0][2] = m_Reals[0][2] - other.m_Reals[0][2];
    result[0][3] = m_Reals[0][3] - other.m_Reals[0][3];

    result[1][0] = m_Reals[1][0] - other.m_Reals[1][0];
    result[1][1] = m_Reals[1][1] - other.m_Reals[1][1];
    result[2][2] = m_Reals[1][2] - other.m_Reals[1][2];
    result[3][3] = m_Reals[1][3] - other.m_Reals[1][3];

    result[2][0] = m_Reals[2][0] - other.m_Reals[2][0];
    result[2][1] = m_Reals[2][1] - other.m_Reals[2][1];
    result[2][2] = m_Reals[2][2] - other.m_Reals[2][2];
    result[1][3] = m_Reals[2][3] - other.m_Reals[2][3];

    result[3][0] = m_Reals[3][0] - other.m_Reals[3][0];
    result[3][1] = m_Reals[3][1] - other.m_Reals[3][1];
    result[3][2] = m_Reals[3][2] - other.m_Reals[3][2];
    result[3][3] = m_Reals[3][3] - other.m_Reals[3][3];

    return result;
}

void Matrix4x4::setTranslation( const Vector3f& v )
{
    m_Reals[0][3] = v.x;
    m_Reals[1][3] = v.y;
    m_Reals[2][3] = v.z;
}


void Matrix4x4::setScale( const Vector3f& v )
{
    m_Reals[0][0] = v.x;
    m_Reals[1][1] = v.y;
    m_Reals[2][2] = v.z;
}


Vector3f Matrix4x4::getTranslation() const
{
    return Vector3f( m_Reals[0][3], m_Reals[1][3], m_Reals[2][3] );
}


Vector3f Matrix4x4::getScale() const
{
    Vector3f scale;

    scale.x = m_Reals[0][0];
    scale.y = m_Reals[1][1];
    scale.z = m_Reals[2][2];

    return scale;
}




Real Matrix4x4::determinant() const
{
    Real det = 0;

    det += m_Reals[0][0] * Minor( *this, 1,2,3, 1,2,3 );
    det -= m_Reals[0][1] * Minor( *this, 1,2,3, 0,2,3 );
    det += m_Reals[0][2] * Minor( *this, 1,2,3, 0,1,3 );
    det -= m_Reals[0][3] * Minor( *this, 1,2,3, 0,1,2 );

    return det;
}

Matrix4x4 Matrix4x4::inverse() const
{
    Matrix4x4 result;

    // Calcul des facteurs
    result.m_Reals[0][0] =  Minor( *this, 1,2,3, 1,2,3 );
    result.m_Reals[0][1] = -Minor( *this, 1,2,3, 0,2,3 );
    result.m_Reals[0][2] =  Minor( *this, 1,2,3, 0,1,3 );
    result.m_Reals[0][3] = -Minor( *this, 1,2,3, 0,1,2 );

    result.m_Reals[1][0] = -Minor( *this, 0,2,3, 1,2,3 );
    result.m_Reals[1][1] =  Minor( *this, 0,2,3, 0,2,3 );
    result.m_Reals[1][2] = -Minor( *this, 0,2,3, 0,1,3 );
    result.m_Reals[1][3] =  Minor( *this, 0,2,3, 0,1,2 );

    result.m_Reals[2][0] =  Minor( *this, 0,1,3, 1,2,3 );
    result.m_Reals[2][1] = -Minor( *this, 0,1,3, 0,2,3 );
    result.m_Reals[2][2] =  Minor( *this, 0,1,3, 0,1,3 );
    result.m_Reals[2][3] = -Minor( *this, 0,1,3, 0,1,2 );

    result.m_Reals[3][0] = -Minor( *this, 0,1,2, 1,2,3 );
    result.m_Reals[3][1] =  Minor( *this, 0,1,2, 0,2,3 );
    result.m_Reals[3][2] = -Minor( *this, 0,1,2, 0,1,3 );
    result.m_Reals[3][3] =  Minor( *this, 0,1,2, 0,1,2 );

    // Calcul du déterminant
    Real det = determinant();
    if( det == 0.f )
    {
        return Matrix4x4::ZERO;
    }
    Real invDet = 1.f / det;

    // Multiplier 1/det
    result *= invDet;

    // Transpose
    result = result.tranpose();



    return result;
}

Matrix4x4 Matrix4x4::tranpose() const
{
    Matrix4x4 result;

    result.m_Reals[0][0] = m_Reals[0][0];
    result.m_Reals[1][0] = m_Reals[0][1];
    result.m_Reals[2][0] = m_Reals[0][2];
    result.m_Reals[3][0] = m_Reals[0][3];

    result.m_Reals[0][1] = m_Reals[1][0];
    result.m_Reals[1][1] = m_Reals[1][1];
    result.m_Reals[2][1] = m_Reals[1][2];
    result.m_Reals[3][1] = m_Reals[1][3];

    result.m_Reals[0][2] = m_Reals[2][0];
    result.m_Reals[1][2] = m_Reals[2][1];
    result.m_Reals[2][2] = m_Reals[2][2];
    result.m_Reals[3][2] = m_Reals[2][3];

    result.m_Reals[0][3] = m_Reals[3][0];
    result.m_Reals[1][3] = m_Reals[3][1];
    result.m_Reals[2][3] = m_Reals[3][2];
    result.m_Reals[3][3] = m_Reals[3][3];

    return result;
}

Matrix4x4 Matrix4x4::inverseTranspose() const
{
    return inverse().tranpose();
}

Matrix4x4& Matrix4x4::makeRotationMatrix( const Quaternion& q )
{
    m_Reals[0][0] = 1.f - 2.f*q.y*q.y -2.f*q.z*q.z;
    m_Reals[0][1] = 2.f* q.x*q.y - 2.f*q.z*q.w;
    m_Reals[0][2] = 2.f*q.x*q.z  + 2.f*q.y*q.w;
    m_Reals[0][3] = 0;

    m_Reals[1][0] = 2.f*q.x*q.y + 2.f*q.z*q.w;
    m_Reals[1][1] = 1 - 2.f*q.x*q.x - 2.f*q.z*q.z;
    m_Reals[1][2] = 2.f*q.y*q.z - 2.f*q.x*q.w;
    m_Reals[1][3] = 0;

    m_Reals[2][0] = 2.f*q.x*q.z - 2.f*q.y*q.w;
    m_Reals[2][1] = 2.f*q.y*q.z + 2.f*q.x*q.w;
    m_Reals[2][2] = 1 - 2.f*q.x*q.x -2.f*q.y*q.y;
    m_Reals[2][3] = 0;

    m_Reals[3][0] = 0;
    m_Reals[3][1] = 0;
    m_Reals[3][2] = 0;
    m_Reals[3][3] = 1;

    return *this;
}

Matrix4x4& Matrix4x4::makeScaleMatrix( const Vector3f& scale )
{
    m_Reals[0][0] = scale.x;
    m_Reals[0][1] = 0;
    m_Reals[0][2] = 0;
    m_Reals[0][3] = 0;

    m_Reals[1][0] = 0;
    m_Reals[1][1] = scale.y;
    m_Reals[1][2] = 0;
    m_Reals[1][3] = 0;

    m_Reals[2][0] = 0;
    m_Reals[2][1] = 0;
    m_Reals[2][2] = scale.z;
    m_Reals[2][3] = 0;

    m_Reals[3][0] = 0;
    m_Reals[3][1] = 0;
    m_Reals[3][2] = 0;
    m_Reals[3][3] = 1;

    return *this;
}

Matrix4x4& Matrix4x4::makeTranslationMatrix(const Vector3f& translation )
{
    m_Reals[0][0] = 1;
    m_Reals[0][1] = 0;
    m_Reals[0][2] = 0;
    m_Reals[0][3] = translation.x;

    m_Reals[1][0] = 0;
    m_Reals[1][1] = 1;
    m_Reals[1][2] = 0;
    m_Reals[1][3] = translation.y;

    m_Reals[2][0] = 0;
    m_Reals[2][1] = 0;
    m_Reals[2][2] = 1;
    m_Reals[2][3] = translation.z;

    m_Reals[3][0] = 0;
    m_Reals[3][1] = 0;
    m_Reals[3][2] = 0;
    m_Reals[3][3] = 1;

    return *this;
}

Matrix4x4& Matrix4x4::makeProjOrthoMatrix( uint width, uint height, uint deep )
{
    Real rigth  =  Real(width) * Real(0.5);
    Real left   =  -rigth;

    Real top    = Real(height) * Real(0.5);
    Real bottom = -top;

    Real far    = deep + 1.f;
    Real near   = 1.f;

    return makeProjOrthoMatrix( left, rigth, bottom, top, near, far );
}

Matrix4x4& Matrix4x4::makeProjOrthoMatrix(Real left, Real right, Real bottom, Real top, Real near, Real far)
{

    m_Reals[0][0] = 2.f / ( right - left);
    m_Reals[0][1] = 0;
    m_Reals[0][2] = 0;
    m_Reals[0][3] = -1.f * ( (right + left) / ( right-left) );

    m_Reals[1][0] = 0;
    m_Reals[1][1] = 2.f / ( top - bottom );
    m_Reals[1][2] = 0;
    m_Reals[1][3] = -1.f * ( (top + bottom) / (top - bottom) );

    m_Reals[2][0] = 0;
    m_Reals[2][1] = 0;
    m_Reals[2][2] = -2.f / (far -near);
    m_Reals[2][3] = -1.f * (far+near) / (far-near);

    m_Reals[3][0] = 0;
    m_Reals[3][1] = 0;
    m_Reals[3][2] = 0;
    m_Reals[3][3] = 1;

    return *this;
}

void Matrix4x4::translate( const Vector3f& v )
{
    m_Reals[0][3] += v.x;
    m_Reals[1][3] += v.y;
    m_Reals[2][3] += v.z;
}

void Matrix4x4::rotate( const Quaternion& quaternion )
{
    Matrix4x4 R;
    R.makeRotationMatrix( quaternion );
    *this = R * *this;
}






}
