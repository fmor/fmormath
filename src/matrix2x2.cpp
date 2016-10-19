#include "matrix2x2.h"


namespace fmormath {

const Matrix2x2 Matrix2x2::ZERO( 0, 0, 0,0 );
const Matrix2x2 Matrix2x2::IDENTITY( 1, 0, 0, 1 );



bool Matrix2x2::operator ==(const Matrix2x2 &other) const
{
    if( m_Reals[0][0] != other.m_Reals[0][0] ) return false;
    if( m_Reals[0][1] != other.m_Reals[0][1] ) return false;
    if( m_Reals[1][0] != other.m_Reals[1][0] ) return false;
    if( m_Reals[1][1] != other.m_Reals[1][1] ) return false;
    return true;
}

void Matrix2x2::operator *=( real f)
{
    m_Reals[0][0] *= f;
    m_Reals[0][1] *= f;
    m_Reals[1][0] *= f;
    m_Reals[1][1] *= f;
}

void Matrix2x2::operator *=(const Matrix2x2& other )
{
    Matrix2x2 result;
    result.m_Reals[0][0] = m_Reals[0][0]*other.m_Reals[0][0] + m_Reals[0][1]*other.m_Reals[1][0];
    result.m_Reals[0][1] = m_Reals[0][0]*other.m_Reals[0][1] + m_Reals[0][1]*other.m_Reals[1][1];
    result.m_Reals[1][0] = m_Reals[1][0]*other.m_Reals[0][0] + m_Reals[1][1]*other.m_Reals[1][0];
    result.m_Reals[1][1] = m_Reals[1][0]*other.m_Reals[0][1] + m_Reals[1][1]*other.m_Reals[1][1];
    *this = result;
}

void Matrix2x2::operator +=(const Matrix2x2& other )
{
    m_Reals[0][0] += other.m_Reals[0][0];
    m_Reals[0][1] += other.m_Reals[0][1];
    m_Reals[1][0] += other.m_Reals[1][0];
    m_Reals[1][1] += other.m_Reals[1][1];
}

void Matrix2x2::operator -=(const Matrix2x2& other)
{
    m_Reals[0][0] -= other.m_Reals[0][0];
    m_Reals[0][1] -= other.m_Reals[0][1];
    m_Reals[1][0] -= other.m_Reals[1][0];
    m_Reals[1][1] -= other.m_Reals[1][1];
}

Matrix2x2 Matrix2x2::operator *( const Matrix2x2& other ) const
{
    Matrix2x2 result;
    result.m_Reals[0][0] = m_Reals[0][0]*other.m_Reals[0][0] + m_Reals[0][1]*other.m_Reals[1][0];
    result.m_Reals[0][1] = m_Reals[0][0]*other.m_Reals[0][1] + m_Reals[0][1]*other.m_Reals[1][1];
    result.m_Reals[1][0] = m_Reals[1][0]*other.m_Reals[0][0] + m_Reals[1][1]*other.m_Reals[1][0];
    result.m_Reals[1][1] = m_Reals[1][0]*other.m_Reals[0][1] + m_Reals[1][1]*other.m_Reals[1][1];
    return result;
}

Matrix2x2 Matrix2x2::operator *(real r) const
{
    Matrix2x2 result;
    result[0][0] = m_Reals[0][0] * r;
    result[0][1] = m_Reals[0][1] * r;
    result[1][0] = m_Reals[1][0] * r;
    result[1][1] = m_Reals[1][1] * r;
    return result;
}

Matrix2x2 Matrix2x2::operator +(const Matrix2x2 &other) const
{
    Matrix2x2 result;
    result[0][0] = m_Reals[0][0] + other.m_Reals[0][0];
    result[0][1] = m_Reals[0][1] + other.m_Reals[0][1];
    result[1][0] = m_Reals[1][0] + other.m_Reals[1][0];
    result[1][1] = m_Reals[1][1] + other.m_Reals[1][1];
    return result;
}

Matrix2x2 Matrix2x2::operator -(const Matrix2x2 &other) const
{
    Matrix2x2 result;
    result[0][0] = m_Reals[0][0] - other.m_Reals[0][0];
    result[0][1] = m_Reals[0][1] - other.m_Reals[0][1];
    result[1][0] = m_Reals[1][0] - other.m_Reals[1][0];
    result[1][1] = m_Reals[1][1] - other.m_Reals[1][1];
    return result;
}

Vector2f Matrix2x2::operator *(const Vector2f& v2 ) const
{
    Vector2f result;
    result.x = m_Reals[0][0]*v2.x + m_Reals[0][1]*v2.y;
    result.y = m_Reals[1][0]*v2.x + m_Reals[1][1]*v2.y;
    return result;
}

float Matrix2x2::determinant() const
{
    return m_Reals[0][0]*m_Reals[1][1] - m_Reals[0][1]*m_Reals[1][0];
}

Matrix2x2 Matrix2x2::inverse() const
{
    const float det = m_Reals[0][0]*m_Reals[1][1] - m_Reals[0][1]*m_Reals[1][0];
    if( det != 0.f )
    {
        const float invDeterminant = 1.0f / det;
        Matrix2x2 result;
        result.m_Reals[0][0] =   invDeterminant * m_Reals[1][1];
        result.m_Reals[0][1] = - invDeterminant * m_Reals[0][1];
        result.m_Reals[1][0] = - invDeterminant * m_Reals[1][0];
        result.m_Reals[1][1] =   invDeterminant * m_Reals[0][0];
        return result;
    }
    return Matrix2x2::ZERO;
}

Matrix2x2 Matrix2x2::transpose() const
{
    Matrix2x2 result;
    result.m_Reals[0][0] = m_Reals[0][0];
    result.m_Reals[0][1] = m_Reals[1][0];
    result.m_Reals[1][0] = m_Reals[0][1];
    result.m_Reals[1][1] = m_Reals[1][1];
    return result;
}



}
