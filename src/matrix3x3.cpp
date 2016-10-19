#include "matrix3x3.h"

namespace fmormath {

const Matrix3x3 Matrix3x3::ZERO( 0, 0, 0,
                                 0, 0, 0,
                                 0, 0, 0 );

const Matrix3x3 Matrix3x3::IDENTITY( 1,0,0,
                                     0,1,0,
                                     0,0,1 );

static inline float Minor( const Matrix3x3& matrix, uint r0, uint r1, uint c0, uint c1 )
{
    return ( matrix[r0][c0]*matrix[r1][c1] - matrix[r1][c0]*matrix[r0][c1] );
}

Matrix3x3::Matrix3x3( float r00, float r01, float r02,
                          float r10, float r11, float r12,
                          float r20, float r21, float r22)
{
    m_Reals[0][0] = r00;
    m_Reals[0][1] = r01;
    m_Reals[0][2] = r02;

    m_Reals[1][0] = r10;
    m_Reals[1][1] = r11;
    m_Reals[1][2] = r12;

    m_Reals[2][0] = r20;
    m_Reals[2][1] = r21;
    m_Reals[2][2] = r22;

}

void Matrix3x3::set( float r00, float r01, float r02,
                       float r10, float r11, float r12,
                       float r20, float r21, float r22)
{
 m_Reals[0][0] = r00;
 m_Reals[0][1] = r01;
 m_Reals[0][2] = r02;

 m_Reals[1][0] = r10;
 m_Reals[1][1] = r11;
 m_Reals[1][2] = r12;

 m_Reals[2][0] = r20;
 m_Reals[2][1] = r21;
 m_Reals[2][2] = r22;

}


bool Matrix3x3::operator ==(const Matrix3x3& other ) const
{
    if( m_Reals[0][0] != other.m_Reals[0][0] ) return false;
    if( m_Reals[0][1] != other.m_Reals[0][1] ) return false;
    if( m_Reals[0][2] != other.m_Reals[0][2] ) return false;

    if( m_Reals[1][0] != other.m_Reals[1][0] ) return false;
    if( m_Reals[1][1] != other.m_Reals[1][1] ) return false;
    if( m_Reals[1][2] != other.m_Reals[1][2] ) return false;

    if( m_Reals[2][0] != other.m_Reals[2][0] ) return false;
    if( m_Reals[2][1] != other.m_Reals[2][1] ) return false;
    if( m_Reals[2][2] != other.m_Reals[2][2] ) return false;

    return true;
}

void Matrix3x3::operator *=( float f )
{
    m_Reals[0][0] *= f;
    m_Reals[0][1] *= f;
    m_Reals[0][2] *= f;

    m_Reals[1][0] *= f;
    m_Reals[1][1] *= f;
    m_Reals[1][2] *= f;

    m_Reals[2][0] *= f;;
    m_Reals[2][1] *= f;;
    m_Reals[2][2] *= f;;
}

void Matrix3x3::operator *=(const Matrix3x3& other)
{
    Matrix3x3 result;

    result.m_Reals[0][0] = m_Reals[0][0]*other.m_Reals[0][0] + m_Reals[0][1]*other.m_Reals[1][0] + m_Reals[0][2]*other.m_Reals[2][0];
    result.m_Reals[0][1] = m_Reals[0][0]*other.m_Reals[0][1] + m_Reals[0][1]*other.m_Reals[1][1] + m_Reals[0][2]*other.m_Reals[2][1];
    result.m_Reals[0][2] = m_Reals[0][0]*other.m_Reals[0][2] + m_Reals[0][1]*other.m_Reals[1][2] + m_Reals[0][2]*other.m_Reals[2][2];

    result.m_Reals[1][0] = m_Reals[1][0]*other.m_Reals[0][0] + m_Reals[1][1]*other.m_Reals[1][0] + m_Reals[1][2]*other.m_Reals[2][0];
    result.m_Reals[1][1] = m_Reals[1][0]*other.m_Reals[0][1] + m_Reals[1][1]*other.m_Reals[1][1] + m_Reals[1][2]*other.m_Reals[2][1];
    result.m_Reals[1][2] = m_Reals[1][0]*other.m_Reals[0][2] + m_Reals[1][1]*other.m_Reals[1][2] + m_Reals[1][2]*other.m_Reals[2][2];

    result.m_Reals[2][0] = m_Reals[2][0]*other.m_Reals[0][0] + m_Reals[2][1]*other.m_Reals[1][0] + m_Reals[2][2]*other.m_Reals[2][0];
    result.m_Reals[2][1] = m_Reals[2][0]*other.m_Reals[0][1] + m_Reals[2][1]*other.m_Reals[1][1] + m_Reals[2][2]*other.m_Reals[2][1];
    result.m_Reals[2][2] = m_Reals[2][0]*other.m_Reals[0][2] + m_Reals[2][1]*other.m_Reals[1][2] + m_Reals[2][2]*other.m_Reals[2][2];

    *this = result;

}

void Matrix3x3::operator +=(const Matrix3x3 &other)
{
    m_Reals[0][0] += other.m_Reals[0][0];
    m_Reals[0][1] += other.m_Reals[0][1];
    m_Reals[0][2] += other.m_Reals[0][2];

    m_Reals[1][0] += other.m_Reals[1][0];
    m_Reals[1][1] += other.m_Reals[1][1];
    m_Reals[1][2] += other.m_Reals[1][2];

    m_Reals[2][0] += other.m_Reals[2][0];
    m_Reals[2][1] += other.m_Reals[2][1];
    m_Reals[2][2] += other.m_Reals[2][2];
}

void Matrix3x3::operator -=(const Matrix3x3 &other)
{
    m_Reals[0][0] -= other.m_Reals[0][0];
    m_Reals[0][1] -= other.m_Reals[0][1];
    m_Reals[0][2] -= other.m_Reals[0][2];

    m_Reals[1][0] -= other.m_Reals[1][0];
    m_Reals[1][1] -= other.m_Reals[1][1];
    m_Reals[1][2] -= other.m_Reals[1][2];

    m_Reals[2][0] -= other.m_Reals[2][0];
    m_Reals[2][1] -= other.m_Reals[2][1];
    m_Reals[2][2] -= other.m_Reals[2][2];
}

Matrix3x3 Matrix3x3::operator *(float f) const
{
    Matrix3x3 result;
    result.m_Reals[0][0] = m_Reals[0][0]*f;
    result.m_Reals[0][1] = m_Reals[0][1]*f;
    result.m_Reals[0][2] = m_Reals[0][2]*f;

    result.m_Reals[1][0] = m_Reals[1][0]*f;
    result.m_Reals[1][1] = m_Reals[1][1]*f;
    result.m_Reals[1][2] = m_Reals[1][2]*f;

    result.m_Reals[2][0] = m_Reals[2][0]*f;
    result.m_Reals[2][1] = m_Reals[2][1]*f;
    result.m_Reals[2][2] = m_Reals[2][2]*f;

    return result;
}

Vector3f Matrix3x3::operator *(const Vector3f& v3 ) const
{
    Vector3f result;
    result.x = m_Reals[0][0]*v3.x + m_Reals[0][1]*v3.y + m_Reals[0][2]*v3.z;
    result.y = m_Reals[1][0]*v3.x + m_Reals[1][1]*v3.y + m_Reals[1][2]*v3.z;
    result.z = m_Reals[2][0]*v3.x + m_Reals[2][1]*v3.y + m_Reals[2][2]*v3.z;
    return result;
}

Matrix3x3 Matrix3x3::operator *(const Matrix3x3& other ) const
{
    Matrix3x3 result;

    result.m_Reals[0][0] = m_Reals[0][0]*other.m_Reals[0][0] + m_Reals[0][1]*other.m_Reals[1][0] + m_Reals[0][2]*other.m_Reals[2][0];
    result.m_Reals[0][1] = m_Reals[0][0]*other.m_Reals[0][1] + m_Reals[0][1]*other.m_Reals[1][1] + m_Reals[0][2]*other.m_Reals[2][1];
    result.m_Reals[0][2] = m_Reals[0][0]*other.m_Reals[0][2] + m_Reals[0][1]*other.m_Reals[1][2] + m_Reals[0][2]*other.m_Reals[2][2];

    result.m_Reals[1][0] = m_Reals[1][0]*other.m_Reals[0][0] + m_Reals[1][1]*other.m_Reals[1][0] + m_Reals[1][2]*other.m_Reals[2][0];
    result.m_Reals[1][1] = m_Reals[1][0]*other.m_Reals[0][1] + m_Reals[1][1]*other.m_Reals[1][1] + m_Reals[1][2]*other.m_Reals[2][1];
    result.m_Reals[1][2] = m_Reals[1][0]*other.m_Reals[0][2] + m_Reals[1][1]*other.m_Reals[1][2] + m_Reals[1][2]*other.m_Reals[2][2];

    result.m_Reals[2][0] = m_Reals[2][0]*other.m_Reals[0][0] + m_Reals[2][1]*other.m_Reals[1][0] + m_Reals[2][2]*other.m_Reals[2][0];
    result.m_Reals[2][1] = m_Reals[2][0]*other.m_Reals[0][1] + m_Reals[2][1]*other.m_Reals[1][1] + m_Reals[2][2]*other.m_Reals[2][1];
    result.m_Reals[2][2] = m_Reals[2][0]*other.m_Reals[0][2] + m_Reals[2][1]*other.m_Reals[1][2] + m_Reals[2][2]*other.m_Reals[2][2];

    return result;
}



float Matrix3x3::determinant() const
{
//    float d = 0;
//    d += m_Reals[0][0]*m_Reals[1][1]*m_Reals[2][2] + m_Reals[0][1]*m_Reals[1][2]*m_Reals[2][0] + m_Reals[0][2]*m_Reals[1][0]*m_Reals[2][1];
//    d -= m_Reals[0][0]*m_Reals[1][2]*m_Reals[2][1] + m_Reals[0][1]*m_Reals[1][0]*m_Reals[2][2] + m_Reals[0][2]*m_Reals[1][1]*m_Reals[2][0];
//    return d;

    float det = 0;
    det += m_Reals[0][0] * Minor( *this, 1, 2, 1, 2 );
    det -= m_Reals[0][1] * Minor( *this, 1, 2, 0, 2 );
    det += m_Reals[0][2] * Minor( *this, 1, 2, 0, 1 );
    return det;
}

Matrix3x3 Matrix3x3::inverse() const
{
    float det = determinant();
    if( det != 0.f )
    {
        Matrix3x3 result;
        const float detInverse = 1.0f / det;

        result.m_Reals[0][0] = Minor( *this, 1, 2, 1, 2 );
        result.m_Reals[0][1] = Minor( *this, 0, 2, 1, 2 ) * -1.0f;;
        result.m_Reals[0][2] = Minor( *this, 0, 1, 1, 2 );
        result.m_Reals[1][0] = Minor( *this, 1, 2, 0, 2 ) * -1.0f;
        result.m_Reals[1][1] = Minor( *this, 0, 2, 0, 2 );
        result.m_Reals[1][2] = Minor( *this, 0, 1, 0, 2 ) * -1.0f;
        result.m_Reals[2][0] = Minor( *this, 1, 2, 0, 1 );
        result.m_Reals[2][1] = Minor( *this, 0, 2, 0, 1 ) * -1.0f;
        result.m_Reals[2][2] = Minor( *this, 0, 1, 0, 1 );

        result = result * detInverse;

        return result;
    }
    return Matrix3x3::ZERO;
}

Matrix3x3 Matrix3x3::transpose() const
{
    Matrix3x3 result;

    result.m_Reals[0][0] = m_Reals[0][0];
    result.m_Reals[0][1] = m_Reals[1][0];
    result.m_Reals[0][2] = m_Reals[2][0];

    result.m_Reals[1][0] = m_Reals[0][1];
    result.m_Reals[1][1] = m_Reals[1][1];
    result.m_Reals[1][2] = m_Reals[2][1];

    result.m_Reals[2][0] = m_Reals[0][2];
    result.m_Reals[2][1] = m_Reals[1][2];
    result.m_Reals[2][2] = m_Reals[2][2];

    return result;

}

}

