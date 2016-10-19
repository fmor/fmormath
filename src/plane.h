#pragma once

#include "vector3f.h"

namespace fmormath {

class Plane
{
    Vector3f m_Normal;
    Vector3f m_Point;

public:

    Plane();
    Plane( const Vector3f& normal, float distance );
    Plane( const Vector3f& normal, const Vector3f& position );
    virtual ~Plane();

    inline const Vector3f& getNormal() const { return m_Normal; }
    inline const Vector3f& getPoint() const  { return m_Point; }

    float getDistance( const Vector3f& point ) const;
    Vector3f getMirrorPoint( const Vector3f& point ) const;




};

}
