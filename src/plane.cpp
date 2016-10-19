#include "plane.h"


namespace fmormath {


Plane::Plane() :
    m_Normal( Vector3f::UNIT_Y ),
    m_Point( Vector3f::ZERO  )
{}

Plane::Plane(const Vector3f& normal, float distance) :
    m_Normal( normal ),
    m_Point( normal * distance )
{
}

Plane::Plane(const Vector3f &normal, const Vector3f &position) :
    m_Normal( normal ),
    m_Point( position )
{}

Plane::~Plane()
{
    m_Normal = Vector3f::ZERO;
    m_Point = Vector3f::ZERO;
}

float Plane::getDistance(const Vector3f &point) const
{
    throw;
//    Vector3f tmp = point - m_Point;
//    float angle = acos( m_Normal.dot(tmp.getNormalized()) );
//    float distance = cos(angle) * tmp.length();
//    return distance;
}

Vector3f Plane::getMirrorPoint(const Vector3f& point ) const
{
    throw;
//    float distance = getDistance( point );
//    Vector3f mirrored = point - 2.0f * distance *  m_Normal;

//#ifdef _DEBUG_
//    if( point.y != distance )
//    {
//        LOG_ERROR( "point.y == " << point.y << ", distance == "  << distance );
//    }
//#endif
//    ASSERT_DEBUG( point.y == distance );

//    return mirrored;
}


}
