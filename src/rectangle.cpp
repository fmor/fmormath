#include "rectangle.h"

namespace fmormath {

//const RealColor RealColor::GRAY60( 0.6f, 0.6f, 0.6f );
const Rectangle Rectangle::ZERO(0,0,0,0);
const Rectangle Rectangle::UNIT(1,1,1,1);

bool Rectangle::isInside(Real x, Real y) const
{
    if( x < m_X )
        return false;
    if( x > (m_X + m_Width) )
        return false;
    if( y < (m_Y - m_Height) )
        return false;
    if( y > m_Y )
        return false;

    return true;
}

Rectangle& Rectangle::operator =(const Rectangle& other )
{
    m_X = other.m_X;
    m_Y = other.m_Y;
    m_Width = other.m_Width;
    m_Height = other.m_Height;

    return *this;
}

bool Rectangle::operator ==( const Rectangle& other ) const
{
    if( m_X != other.m_X )
        return false;
    if( m_Y != other.m_Y )
        return false;
    if( m_Width != other.m_Width )
        return false;
    if( m_Height != other.m_Height )
        return false;
    return true;
}

bool Rectangle::operator !=( const Rectangle& other ) const
{
    return ! ( *this == other );
}


}

